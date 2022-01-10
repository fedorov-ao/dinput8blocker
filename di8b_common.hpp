#ifndef DI8B_COMMON_HPP
#define DI8B_COMMON_HPP

#include <cstdarg>

namespace di8b
{

enum class LogLevel : int { notset=0, trace=1, debug=2, info=3, error=4 };
char const * loglevel2name(LogLevel level);
LogLevel name2loglevel(char const * name);

void log_set_level(LogLevel level);
LogLevel log_get_level();

void log(LogLevel level, char const * fmt, ...);
void vlog(LogLevel level, char const * fmt, std::va_list vlist);

void log_debug(char const * fmt, ...);
void log_info(char const * fmt, ...);
void log_error(char const * fmt, ...);

template <class M>
typename M::value_type& get_or(M& m, typename M::key_type& key, typename M::value_type& dfault)
{
  auto it = m.find(key);
  return it == m.end() ? dfault : it->second;
}


} //di8b

#endif 
