#ifndef DI8B_HPP
#define DI8B_HPP

#include <di8b_common.hpp>
#include <di8b_wrappers.hpp>

#include <cstring>
#include <stdexcept>
#include <functional>
#include <map>
#include <memory>
#include <cstdarg>
#include <windows.h>
#include <olectl.h>

#define DLLEXPORT __declspec(dllexport)

namespace di8b
{

UINT name2key(char const * name);
char const * key2name(UINT key);

size_t guid2cstr(char * buf, size_t n, REFGUID rguid);
std::string guid2str(REFGUID rguid);

std::string preset_guid2str(REFGUID rguid);

enum class DeviceKind { mouse, keyboard, joystick, other };

class Flag;

typedef std::map<std::string, std::map<std::string, std::string> > config_t;
extern config_t g_config;
void open_and_parse_config();

void init_log();

void start_loop();
void stop_loop();

LPVOID make_dinputxx_wrapper(REFIID riidltf, LPVOID lpNative);

HMODULE get_next_handle(LPCSTR dllName);

} //namespace di8b

#endif
