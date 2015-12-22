#include "logger.h"


Log::Log() {}

Log::Log(std::string file) {
    fileName = file;
    openFile(fileName);
}
Log::~Log() {
//    closeFile();
//    std::cout << "closing log" << std::endl;
}

Log::Log(const Log& log) {
}

void Log::openFile(std::string file, std::ios_base::openmode mode) {
    if(!logFile.is_open()) {
        fileName = file;
        std::cout << "Loading log file: " << fileName << std::endl;

        logFile.open(fileName, mode);

        std::string border = "==============================================================\n";
        std::string logMessage = "Begin Logging\n";
//    std::cout << sizeof(border)/sizeof(char);
        logFile.write(border.c_str(), border.size());
        logFile.write(logMessage.c_str(), logMessage.size());
        logFile.write(border.c_str(), border.size());
        logFile.flush();
    }
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
