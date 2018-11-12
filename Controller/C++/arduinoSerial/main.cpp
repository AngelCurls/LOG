#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions

#include <iostream>
#include <vector>

bool isValidChar(char buffer) {
    return (buffer != '\n') && (buffer != '\r');
}

bool isValidString(std::string buffer) {
    return (buffer != "") && (buffer != "\n") && (buffer != "\r");
}

std::vector<std::string> read(int USB) {
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

    std::vector<std::string> outputList;
    std::string number = "";
    for (const char &character : response) {
        if (isValidChar(character)){
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

std::vector<int> stringToInt(std::vector<std::string> stringList) {
    std::vector<int> intList;
    for(const std::string &number : stringList) {
        if (isValidString(number)) {
            int num = std::stoi(number);
            intList.push_back(num);
        }
    }
    return intList;
}

int main() {
    /* OPEN PORT */
    int USB = open( "/dev/ttyACM0", O_RDWR| O_NOCTTY );

    /* SET PARAMETERS */
    struct termios tty;
    struct termios tty_old;
    memset (&tty, 0, sizeof tty);

    /* Error Handling */
    if ( tcgetattr ( USB, &tty ) != 0 ) {
        std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
    }

    /* Save old tty parameters */
    tty_old = tty;

    /* Set Baud Rate */
    cfsetospeed (&tty, (speed_t)B9600);
    cfsetispeed (&tty, (speed_t)B9600);

    /* Setting other Port Stuff */
    tty.c_cflag     &=  ~PARENB;            // Make 8n1
    tty.c_cflag     &=  ~CSTOPB;
    tty.c_cflag     &=  ~CSIZE;
    tty.c_cflag     |=  CS8;

    tty.c_cflag     &=  ~CRTSCTS;           // no flow control
    tty.c_cc[VMIN]   =  1;                  // read doesn't block
    tty.c_cc[VTIME]  =  5;                  // 0.5 seconds read timeout
    tty.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

    /* Make raw */
    cfmakeraw(&tty);

    /* Flush Port, then applies attributes */
    tcflush( USB, TCIFLUSH );
    if ( tcsetattr ( USB, TCSANOW, &tty ) != 0) {
        std::cout << "Error " << errno << " from tcsetattr" << std::endl;
    }

    std::vector<int> myList;

    bool running = true;

    while(running) {
        myList = stringToInt(read(USB));
        std::vector<int> finalList{ std::make_move_iterator(std::begin(myList)),
                                    std::make_move_iterator(std::end(myList)) };
        std::cout << "[ ";
        for(const int &number : finalList) {
            std::cout << number << " ";
        }
        std::cout << "]\n";
        std::string command = "xdotool mousemove " + std::to_string(finalList.at(0) + 200) + " " + std::to_string(finalList.at(1));
        system(command.c_str());

        if (finalList.at(2) == 0) {
            //system("xdotool click 1");
            system("xdotool key q");
        }
    }

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