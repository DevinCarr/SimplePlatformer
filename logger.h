#ifndef LOGGER_H_
#define LOGGER_H_

#include <fstream>
#include <string>

#include "time.h"

#include <iostream>

//using namespace std;
class Log {
public:

    enum loggingLevels {
        general,
        warning,
        error
    };

    Log();
    Log(const Log&);
    ~Log();
    Log(std::string);
    void openFile(std::string fileName, std::fstream::openmode mode = std::fstream::in | std::fstream::out | std::fstream::trunc);
    void closeFile();
    void writeMessage(std::string msg, int level = 0);

private:
    std::fstream logFile;
    std::string fileName;
//    time_t timer;
//    double seconds;
};
#endif // LOGGER_H_
