#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging
#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging

int main(int argc, char* argv[]) {
    try {
        // Create basic file logger (not rotated)
        auto my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.txt");
        // create a file rotating logger with 5mb size max and 3 rotated files
        auto file_logger = spdlog::rotating_logger_mt("file_logger", "myfilename", 1024 * 1024 * 5, 3);
        
        my_logger->info("This is a basic logger.");

        for (int i = 0; i < 1024 * 1024 * 5 * 4; i++)
            file_logger->info("This is a rotating logger: #{}", i);
    } catch (const spdlog::spdlog_ex& ex) {
        std::cout << "Log initialization failed: " << ex.what() << std::endl;
    } 
}
