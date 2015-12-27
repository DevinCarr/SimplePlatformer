#ifndef LOGGER_H_
#define LOGGER_H_

#include <fstream>
#include <string>

#include <ctime>

#include <iostream>

/*
Set to 1 for any DEBUG messages to be sent to the output
Set to 0 to remove only the DEBUG (logger.d()) messages from the log output
*/
#define LOGGING 1

//using namespace std;
class Log {
public:

    enum loggingLevels {
        general,
        warning,
        error
    };

    Log();
    ~Log();
    Log(std::string);
    void openFile();
    void closeFile();
    void writeMessage(std::string msg, int level = 0);
    void d(std::string msg);
    void w(std::string msg);
    void e(std::string msg);

private:
    std::ofstream logFile;
    std::string fileName;
    
    std::string print_time();
//    time_t timer;
//    double seconds;
};
#endif // LOGGER_H_
