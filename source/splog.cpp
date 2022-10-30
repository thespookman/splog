#include "splog.hpp"

#include <ctime>
#include <iostream>

Log::Log () : Log (debug) {}
Log::Log (Level _log_level) : log_level (_log_level) {}

void Log::dbg (std::string message) {
    if (log_level != debug) return;
    print_log (std::string ("DEBUG   : ") + message);
}

void Log::inf (std::string message) {
    print_log (std::string ("          ") + message);
}

void Log::wrn (std::string message) {
    if (log_level == error) return;
    print_log (std::string ("WARNING : ") + message);
}

void Log::err (std::string message) {
    print_err (std::string ("ERROR   : ") + message);
}

void Log::print_log (std::string message) {
    std::cout << (log_level == debug ? time () : "") << message
              << std::endl;
}

void Log::print_err (std::string message) {
    std::cerr << (log_level == debug ? time () : "") << message
              << std::endl;
}

std::string Log::time () {
    char        buffer[21];
    std::time_t raw_time  = std::time (NULL);
    struct tm*  time_info = localtime (&raw_time);
    strftime (buffer, 21, "%F %T ", time_info);
    return std::string (buffer);
}
