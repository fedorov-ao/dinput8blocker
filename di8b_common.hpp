#ifndef DI8B_COMMON_HPP
#define DI8B_COMMON_HPP

#include <cstdarg>

namespace di8b
{

enum class LogLevel { debug, info, error };

void log(LogLevel level, char const * fmt, ...);
void vlog(LogLevel level, char const * fmt, std::va_list vlist);

void log_debug(char const * fmt, ...);
void log_info(char const * fmt, ...);
void log_error(char const * fmt, ...);

}

#endif 
