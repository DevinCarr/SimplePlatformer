#include "logger.h"


Log::Log() {
    openFile();
}

Log::Log(std::string file): fileName(file) {
    openFile();
}
Log::~Log() {
    closeFile();
}

void Log::openFile() {
    time_t rawtime;
    struct tm* timeinfo;
    char buffer [80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,80,"%F",timeinfo);
    fileName = std::string(buffer) + (fileName.size()?"_":"") + fileName + ".log";
    std::cout << "Loading log file: " << fileName << std::endl;

    logFile.open(fileName);

    std::string border = "==============================================================\n";
    std::string logMessage = "Begin Logging\n";
    std::cout << border << logMessage;
    logFile.flush();
}
void Log::closeFile() {
    if(logFile.is_open()) {
        std::cout << "Closing log file: " << fileName << std::endl;
        std::string border = "==============================================================\n";
        std::string logMessage = "End Logging\n";

        logFile.write(border.c_str(), border.size());
        logFile.write(logMessage.c_str(), logMessage.size());
        logFile.write(border.c_str(), border.size());
        logFile.close();
    }
}

void Log::writeMessage(std::string msg, int level) {
//    logFile.write(msg, (sizeof(msg) / sizeof(char)) - 1);
    int year, day, month;
    int seconds, hours, minutes;

    switch (level) {
    case 0:
        logFile.write("[General] ", 10);
        break;
    case 1:
        logFile.write("[Warning] ", 10);
        break;
    case 2:
        logFile.write("[Error] ", 8);
        break;
    }

    logFile.write(msg.c_str(), msg.size() - 1);
    logFile << std::endl;
    logFile.flush();
}

std::string Log::print_time() {
    struct tm* timeinfo;
    time_t t;
    time(&t);
    char buffer[80];
    timeinfo = localtime(&t);
    strftime(buffer,80,"[%c]",timeinfo);
    return buffer;
}

// Debug message
void Log::d(std::string msg) {
    if (LOGGING) {
    	logFile << print_time();
        logFile << "[DEBUG] ";
        logFile << msg << std::endl;
        logFile.flush();
    }
}

// Warning message
void Log::w(std::string msg) {
    logFile << print_time();
    logFile << "[WARN ] ";
    logFile << msg << std::endl;
    logFile.flush();
}

// Error message
void Log::e(std::string msg) {
    logFile << print_time();
    logFile << "[ERROR] ";
    logFile << msg << std::endl;
    logFile.flush();
}
