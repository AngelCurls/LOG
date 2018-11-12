//
// Created by edmobe on 11/11/18.
//

#include "Controller.h"

bool Controller::running = true;

bool Controller::isValid(char buffer) {
    return buffer == '0' || buffer == '1' || buffer == '2' ||
           buffer == '3' || buffer == '4' || buffer == '5' || buffer == '6' ||
           buffer == '7' || buffer == '8' || buffer == ',';
}

std::list<std::string> Controller::readUSB(int USB) {
    /* READ */
    int n = 0,
            spot = 0;
    char buf = '\0';

    /* Whole response*/
    char response[1024];
    memset(response, '\0', sizeof response);

    do {
        n = read(USB, &buf, 1);
        sprintf(&response[spot], "%c", buf);
        spot += n;
    } while(buf != '\r' && n > 0);

    if (n < 0) {
        std::cout << "Error reading: " << strerror(errno) << std::endl;
    }
    else if (n == 0) {
        std::cout << "Read nothing!" << std::endl;
    } /*
    else {
        std::cout << "Response: " << response << std::endl;
    }
    */

    std::list<std::string> outputList;
    std::string number = "";
    for (const char &character : response) {
        if (isValid(character)){
            if (character == '\000')
                break;
            else if(character != ',')
                number += character;
            else {
                outputList.push_back(number);
                number = "";
            }
        }
    }
    outputList.push_back(number);
    return outputList;

}

std::list<int> Controller::stringToInt(std::list<std::string> stringList) {
    std::list<int> intList;
    for(const std::string &number : stringList) {
        int num = std::stoi(number);
        intList.push_back(num);
    }
    return intList;
}

void Controller::run(std::atomic<bool>& program_is_running, unsigned int update_interval_millisecs) {
    while(running) {
        /* OPEN PORT */
        int USB = open("/dev/ttyACM0", O_RDWR | O_NOCTTY);
        /* SET PARAMETERS */
        struct termios tty;
        struct termios tty_old;
        memset(&tty, 0, sizeof tty);

        /* Error Handling */
        if (tcgetattr(USB, &tty) != 0) {
            std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
        }

        /* Save old tty parameters */
        tty_old = tty;

        /* Set Baud Rate */
        cfsetospeed(&tty, (speed_t) B9600);
        cfsetispeed(&tty, (speed_t) B9600);

        /* Setting other Port Stuff */
        tty.c_cflag &= ~PARENB;            // Make 8n1
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CSIZE;
        tty.c_cflag |= CS8;

        tty.c_cflag &= ~CRTSCTS;           // no flow control
        tty.c_cc[VMIN] = 1;                  // read doesn't block
        tty.c_cc[VTIME] = 5;                  // 0.5 seconds read timeout
        tty.c_cflag |= CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

        /* Make raw */
        cfmakeraw(&tty);

        /* Flush Port, then applies attributes */
        tcflush(USB, TCIFLUSH);
        if (tcsetattr(USB, TCSANOW, &tty) != 0) {
            std::cout << "Error " << errno << " from tcsetattr" << std::endl;
        }

        std::list<int> myList;

        myList = stringToInt(readUSB(USB));
        std::cout << "[ ";
        for (const int &number : myList) {
            std::cout << number << " ";
        }
        std::cout << "]\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(update_interval_millisecs));

        /* WRITE */
        /*
        unsigned char cmd[] = "INIT \r";
        int n_written = 0,
                spot = 0;

        do {
            n_written = write( USB, &cmd[spot], 1 );
            spot += n_written;
        } while (cmd[spot-1] != '\r' && n_written > 0);
         */
    }
}