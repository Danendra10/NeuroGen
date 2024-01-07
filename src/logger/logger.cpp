#include <logger/logger.hpp>

namespace logging {

    void Logger::SaveLog(const char *msg, va_list args) {
        char buffer[200];
        std::time_t now = std::time(0);
        std::tm *ltm = std::localtime(&now);

        vsnprintf(buffer, sizeof(buffer), msg, args);
        strcat(buffer, "\n");

        std::ofstream file(log_dir, std::ios_base::app);
        if (file.is_open()) {
            file << buffer;
        } else {
            std::cerr << "Failed to open log file." << std::endl;
        }
    }

    Logger::Logger() {
        fs::path log_directory = fs::current_path() / "../log";
        fs::path log_path = log_directory / "logger.log";

        if (!fs::exists(log_directory)) {
            fs::create_directories(log_directory);
        }

        if (fs::exists(log_path) && fs::file_size(log_path) > 5 * 1024 * 1024) {
            fs::remove(log_path);
        }

        log_dir = log_path.string();
    }

    void Logger::Log(const std::string color, const char *msg, ...) {
        char timestampBuffer[100];
        std::time_t now = std::time(0);
        std::tm *ltm = std::localtime(&now);
        snprintf(timestampBuffer, sizeof(timestampBuffer), "[%d-%d-%d %d:%d:%d] => ",
                 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
                 ltm->tm_hour, ltm->tm_min, ltm->tm_sec);

        char msgBuffer[200];
        va_list args;
        va_start(args, msg);
        vsnprintf(msgBuffer, sizeof(msgBuffer), msg, args);
        va_end(args);

        SaveLog(timestampBuffer, args);

        std::cout << color << timestampBuffer;
        std::vprintf(msg, args);
        std::cout << RESET << std::endl;
    }

}  // namespace logger
