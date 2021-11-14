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

namespace di8b
{

UINT name2key(char const * name);
char const * key2name(UINT key);

enum class DeviceKind { mouse, keyboard, joystick, other };

class Flag;

class BlockingCIDirectInputDevice8 : public CIDirectInputDevice8
{
public:
  virtual HRESULT GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);

  BlockingCIDirectInputDevice8(std::shared_ptr<Flag> const & spFlag);

private:
  std::shared_ptr<Flag> spFlag_;
};


class BoundBlockingCIDirectInputDevice8 : public CIDirectInputDevice8
{
public:
  typedef std::function<void()> on_destroy_t;

  virtual HRESULT GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);

  void set_state(bool s);
  bool get_state() const;

  BoundBlockingCIDirectInputDevice8(bool state, on_destroy_t const & onDestroy = on_destroy_t());
  ~BoundBlockingCIDirectInputDevice8();

private:
  bool state_;
  on_destroy_t onDestroy_;
};


class WrappingCIDirectInput8 : public CIDirectInput8
{
public:
  virtual HRESULT CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  
  virtual ~WrappingCIDirectInput8();
};

class FactoryCIDirectInput8 : public CIDirectInput8
{
public:
  typedef std::function<std::unique_ptr<CIDirectInputDevice8> (REFGUID)> make_callback_t;

  virtual HRESULT CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);

  FactoryCIDirectInput8(make_callback_t const & make_callback);

private:
  make_callback_t make_callback_;
};

} //namespace di8b

#endif
