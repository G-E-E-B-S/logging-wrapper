#include "logger/log.h"
#if IS_ANDROID
#include <android/log.h>
#endif
#include <cstring>

std::ostringstream os;

namespace logger
{
    void _log(const char *format, va_list args)
    {
        int bufferSize = MAX_LG_LENGTH;
        char* buf = nullptr;

        do
        {
            buf = new (std::nothrow) char[bufferSize];
            if (buf == nullptr)
            {
                return; // not enough memory
            }

            int ret = vsnprintf(buf, bufferSize - 3, format, args);
            if (ret < 0)
            {
                bufferSize *= 2;
                delete [] buf;
            }
            else
            {
                break;
            } 

        } while (true);

        std::strcat(buf, "\n");

    #if (IS_ANDROID)
        __android_log_print(ANDROID_LOG_DEBUG, "cocos2d-x debug info", "%s", buf);
    #else
        // Linux, Mac, iOS, etc
        fprintf(stdout, "%s", buf);
        fflush(stdout);
    #endif

        delete [] buf;
    }

    void log(const char* format, ...)
    {
        va_list args;
        va_start(args, format);
        _log(format, args);
        va_end(args);
    }
}