#ifndef LOGGER_H
#define LOGGER_H

#include <cstdio>
#include <cstdarg>
#include <sstream>

#define MAX_LG_LENGTH 16*1024

extern std::ostringstream os;

namespace logger
{
    void log(const char* format, ...);

    template <typename T>
    std::string to_string(T value) {
        os << value ;
        return os.str() ;
    }
}

#endif // LOGGER_H
