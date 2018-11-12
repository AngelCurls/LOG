//
// Created by edmobe on 11/11/18.
//

#ifndef LOG_CONTROLLER_H
#define LOG_CONTROLLER_H
#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions
#include <iostream>
#include <list>
#include <chrono>
#include <thread>

class Controller {
public:
    static bool isValid(char buffer);
    static std::list<std::string> readUSB(int USB);
    static std::list<int> stringToInt(std::list<std::string> stringList);
    static void run(std::atomic<bool>& program_is_running, unsigned int update_interval_millisecs);
    static bool running;
};


#endif //LOG_CONTROLLER_H
