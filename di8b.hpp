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

class BlockingCIDirectInputDevice8 : public CIDirectInputDevice8
{
public:
  virtual HRESULT GetDeviceState(LPDIRECTINPUTDEVICE8 This, DWORD cbData, LPVOID lpvData);
  virtual HRESULT GetDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);

  BlockingCIDirectInputDevice8(std::shared_ptr<Flag> const & spFlag);

private:
  std::shared_ptr<Flag> spFlag_;
};


class BoundBlockingCIDirectInputDevice8 : public CIDirectInputDevice8
{
public:
  typedef std::function<void()> on_destroy_t;

  virtual HRESULT GetDeviceState(LPDIRECTINPUTDEVICE8 This, DWORD cbData, LPVOID lpvData);
  virtual HRESULT GetDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);

  void set_state(bool s);
  bool get_state() const;

  BoundBlockingCIDirectInputDevice8(bool state, bool clearBuffer = false, on_destroy_t const & onDestroy = on_destroy_t());
  ~BoundBlockingCIDirectInputDevice8();

private:
  bool state_;
  bool clearBuffer_;
  on_destroy_t onDestroy_;
};


class WrappingCIDirectInput8 : public CIDirectInput8
{
public:
  virtual HRESULT CreateDevice(LPDIRECTINPUT8 This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  
  virtual ~WrappingCIDirectInput8();
};

class FactoryCIDirectInput8 : public CIDirectInput8
{
public:
  typedef std::function<std::unique_ptr<CIDirectInputDevice8> (REFGUID)> make_callback_t;

  virtual HRESULT CreateDevice(LPDIRECTINPUT8 This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);

  FactoryCIDirectInput8(make_callback_t const & make_callback);

private:
  make_callback_t make_callback_;
};

void open_and_parse_config();
void init_log();

void start_loop();
void stop_loop();

LPVOID make_dinputxx_wrapper(REFIID riidltf, LPVOID lpNative);

} //namespace di8b

#endif
