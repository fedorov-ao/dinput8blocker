#include <di8b_common.hpp>
#include <cstdio>
#include <mingw.thread.h>
#include <mingw.mutex.h>

namespace di8b
{

char const * ll2cs(LogLevel level)
{
  return level == LogLevel::debug ? "DEBUG" :
    level == LogLevel::info ? "INFO" :
    level == LogLevel::error ? "ERROR" : "";
}

int ct2cs(char * buf, int n, char const * fmt)
{
  auto tNow = std::time(nullptr);
  auto tmNow = std::localtime(&tNow);
  return std::strftime(buf, n, fmt, tmNow);
}


void log(LogLevel level, char const * fmt, ...)
{
  std::va_list args;
  va_start(args, fmt);
  vlog(level, fmt, args);
  va_end(args);
}

void vlog(LogLevel level, char const * fmt, va_list vlist)
{
  static char const * fname = "dinput8_blocker.log";
  static auto * f = std::fopen(fname, "w");
  struct Fmgr
  {
    Fmgr(std::FILE * f) : f_(f)
    {
      char const * fmt = "%d.%m.%Y %H:%M:%S";
      char buf [128] = {0};
      ct2cs(buf, sizeof(buf), fmt);
      std::fprintf(f_, "Logging started at %s\n", buf);
      std::fflush(f_);
    }
    ~Fmgr()
    {
      char const * fmt = "%d.%m.%Y %H:%M:%S";
      char buf [128] = {0};
      ct2cs(buf, sizeof(buf), fmt);
      std::fprintf(f_, "Logging ended at %s\n", buf);
      std::fflush(f_);
      std::fclose(f_);
    }
    std::FILE * f_;
  };
  static Fmgr fmgr (f);

  static std::mutex m;

  std::lock_guard<std::mutex> l (m);
  char buf[128] = {0};
  ct2cs(buf, sizeof(buf), "%H:%M:%S");
  std::fprintf(f, "%s: [%s] ", buf, ll2cs(level));
  std::vfprintf(f, fmt, vlist);
  std::fprintf(f, "\n");
  std::fflush(f);
}

void log_debug(char const * fmt, ...)
{
  std::va_list args;
  va_start(args, fmt);
  vlog(LogLevel::debug, fmt, args);
  va_end(args);
}

void log_info(char const * fmt, ...)
{
  std::va_list args;
  va_start(args, fmt);
  vlog(LogLevel::info, fmt, args);
  va_end(args);
}

void log_error(char const * fmt, ...)
{
  std::va_list args;
  va_start(args, fmt);
  vlog(LogLevel::error, fmt, args);
  va_end(args);
}


}
