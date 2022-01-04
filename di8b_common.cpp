#include <di8b_common.hpp>
#include <cstdio>
#include <cstring>
#include <mingw.thread.h>
#include <mingw.mutex.h>

namespace di8b
{

static struct { char const * name; LogLevel level; } g_logLevelNames[] = {
  { "NOTSET", LogLevel::notset },
  { "TRACE", LogLevel::trace },
  { "DEBUG", LogLevel::debug },
  { "INFO", LogLevel::info },
  { "ERROR", LogLevel::error }
};

char const * loglevel2name(LogLevel level)
{
  for (auto const & p : g_logLevelNames)
    if (p.level == level) 
      return p.name;
  return "";
}

LogLevel name2loglevel(char const * name)
{
  for (auto const & p : g_logLevelNames)
    if (std::strcmp(p.name, name) == 0) 
      return p.level;
  return LogLevel::notset;
}

static LogLevel g_logLevel;

void log_set_level(LogLevel level)
{
  g_logLevel = level;
}

LogLevel log_get_level()
{
  return g_logLevel;
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
  std::fprintf(f, "%s: [%s] ", buf, loglevel2name(level));
  std::vfprintf(f, fmt, vlist);
  std::fprintf(f, "\n");
  std::fflush(f);
}

void log_debug(char const * fmt, ...)
{
  if (static_cast<int>(log_get_level()) > static_cast<int>(LogLevel::debug))
    return;
  std::va_list args;
  va_start(args, fmt);
  vlog(LogLevel::debug, fmt, args);
  va_end(args);
}

void log_info(char const * fmt, ...)
{
  if (static_cast<int>(log_get_level()) > static_cast<int>(LogLevel::info))
    return;
  std::va_list args;
  va_start(args, fmt);
  vlog(LogLevel::info, fmt, args);
  va_end(args);
}

void log_error(char const * fmt, ...)
{
  if (static_cast<int>(log_get_level()) > static_cast<int>(LogLevel::error))
    return;
  std::va_list args;
  va_start(args, fmt);
  vlog(LogLevel::error, fmt, args);
  va_end(args);
}


} //di8b
