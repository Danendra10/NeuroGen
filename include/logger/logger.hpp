#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <cstdarg>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
namespace fs = std::filesystem;

namespace logging {

    const std::string RED = "\033[0;31m";
    const std::string GREEN = "\033[0;32m";
    const std::string YELLOW = "\033[0;33m";
    const std::string BLUE = "\033[0;34m";
    const std::string MAGENTA = "\033[0;35m";
    const std::string CYAN = "\033[0;36m";
    const std::string WHITE = "\033[0;37m";
    const std::string RESET = "\033[0m";

    class Logger {
    private:
        std::string log_dir;
        void SaveLog(const char *msg, va_list args);

    public:
        Logger();
        void Log(const std::string color, const char *msg, ...);
    };

}  // namespace logger

#endif  // LOGGER_HPP_
