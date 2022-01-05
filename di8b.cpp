#include <di8b.hpp>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <mingw.thread.h>
#include <mingw.mutex.h>
#include <chrono>
#include <cstdio>
#include <string>
#include <cassert>

namespace di8b
{

struct { char const * name; UINT key; } g_keyNames[] = { { "LBUTTON", VK_LBUTTON }, { "RBUTTON", VK_RBUTTON }, { "CANCEL", VK_CANCEL }, { "MBUTTON", VK_MBUTTON }, { "XBUTTON1", VK_XBUTTON1 }, { "XBUTTON2", VK_XBUTTON2 }, { "BACK", VK_BACK }, { "TAB", VK_TAB }, { "CLEAR", VK_CLEAR }, { "RETURN", VK_RETURN }, { "SHIFT", VK_SHIFT }, { "CONTROL", VK_CONTROL }, { "MENU", VK_MENU }, { "PAUSE", VK_PAUSE }, { "CAPITAL", VK_CAPITAL }, { "KANA", VK_KANA }, { "HANGEUL", VK_HANGEUL }, { "HANGUL", VK_HANGUL }, { "JUNJA", VK_JUNJA }, { "FINAL", VK_FINAL }, { "HANJA", VK_HANJA }, { "KANJI", VK_KANJI }, { "ESCAPE", VK_ESCAPE }, { "CONVERT", VK_CONVERT }, { "NONCONVERT", VK_NONCONVERT }, { "ACCEPT", VK_ACCEPT }, { "MODECHANGE", VK_MODECHANGE }, { "SPACE", VK_SPACE }, { "PRIOR", VK_PRIOR }, { "NEXT", VK_NEXT }, { "END", VK_END }, { "HOME", VK_HOME }, { "LEFT", VK_LEFT }, { "UP", VK_UP }, { "RIGHT", VK_RIGHT }, { "DOWN", VK_DOWN }, { "SELECT", VK_SELECT }, { "PRINT", VK_PRINT }, { "EXECUTE", VK_EXECUTE }, { "SNAPSHOT", VK_SNAPSHOT }, { "INSERT", VK_INSERT }, { "DELETE", VK_DELETE }, { "HELP", VK_HELP }, { "LWIN", VK_LWIN }, { "RWIN", VK_RWIN }, { "APPS", VK_APPS }, { "SLEEP", VK_SLEEP }, { "NUMPAD0", VK_NUMPAD0 }, { "NUMPAD1", VK_NUMPAD1 }, { "NUMPAD2", VK_NUMPAD2 }, { "NUMPAD3", VK_NUMPAD3 }, { "NUMPAD4", VK_NUMPAD4 }, { "NUMPAD5", VK_NUMPAD5 }, { "NUMPAD6", VK_NUMPAD6 }, { "NUMPAD7", VK_NUMPAD7 }, { "NUMPAD8", VK_NUMPAD8 }, { "NUMPAD9", VK_NUMPAD9 }, { "MULTIPLY", VK_MULTIPLY }, { "ADD", VK_ADD }, { "SEPARATOR", VK_SEPARATOR }, { "SUBTRACT", VK_SUBTRACT }, { "DECIMAL", VK_DECIMAL }, { "DIVIDE", VK_DIVIDE }, { "F1", VK_F1 }, { "F2", VK_F2 }, { "F3", VK_F3 }, { "F4", VK_F4 }, { "F5", VK_F5 }, { "F6", VK_F6 }, { "F7", VK_F7 }, { "F8", VK_F8 }, { "F9", VK_F9 }, { "F10", VK_F10 }, { "F11", VK_F11 }, { "F12", VK_F12 }, { "F13", VK_F13 }, { "F14", VK_F14 }, { "F15", VK_F15 }, { "F16", VK_F16 }, { "F17", VK_F17 }, { "F18", VK_F18 }, { "F19", VK_F19 }, { "F20", VK_F20 }, { "F21", VK_F21 }, { "F22", VK_F22 }, { "F23", VK_F23 }, { "F24", VK_F24 }, { "NUMLOCK", VK_NUMLOCK }, { "SCROLL", VK_SCROLL }, { "OEM_NEC_EQUAL", VK_OEM_NEC_EQUAL }, { "OEM_FJ_JISHO", VK_OEM_FJ_JISHO }, { "OEM_FJ_MASSHOU", VK_OEM_FJ_MASSHOU }, { "OEM_FJ_TOUROKU", VK_OEM_FJ_TOUROKU }, { "OEM_FJ_LOYA", VK_OEM_FJ_LOYA }, { "OEM_FJ_ROYA", VK_OEM_FJ_ROYA }, { "LSHIFT", VK_LSHIFT }, { "RSHIFT", VK_RSHIFT }, { "LCONTROL", VK_LCONTROL }, { "RCONTROL", VK_RCONTROL }, { "LMENU", VK_LMENU }, { "RMENU", VK_RMENU }, { "BROWSER_BACK", VK_BROWSER_BACK }, { "BROWSER_FORWARD", VK_BROWSER_FORWARD }, { "BROWSER_REFRESH", VK_BROWSER_REFRESH }, { "BROWSER_STOP", VK_BROWSER_STOP }, { "BROWSER_SEARCH", VK_BROWSER_SEARCH }, { "BROWSER_FAVORITES", VK_BROWSER_FAVORITES }, { "BROWSER_HOME", VK_BROWSER_HOME }, { "VOLUME_MUTE", VK_VOLUME_MUTE }, { "VOLUME_DOWN", VK_VOLUME_DOWN }, { "VOLUME_UP", VK_VOLUME_UP }, { "MEDIA_NEXT_TRACK", VK_MEDIA_NEXT_TRACK }, { "MEDIA_PREV_TRACK", VK_MEDIA_PREV_TRACK }, { "MEDIA_STOP", VK_MEDIA_STOP }, { "MEDIA_PLAY_PAUSE", VK_MEDIA_PLAY_PAUSE }, { "LAUNCH_MAIL", VK_LAUNCH_MAIL }, { "LAUNCH_MEDIA_SELECT", VK_LAUNCH_MEDIA_SELECT }, { "LAUNCH_APP1", VK_LAUNCH_APP1 }, { "LAUNCH_APP2", VK_LAUNCH_APP2 }, { "OEM_1", VK_OEM_1 }, { "OEM_PLUS", VK_OEM_PLUS }, { "OEM_COMMA", VK_OEM_COMMA }, { "OEM_MINUS", VK_OEM_MINUS }, { "OEM_PERIOD", VK_OEM_PERIOD }, { "OEM_2", VK_OEM_2 }, { "OEM_3", VK_OEM_3 }, { "OEM_4", VK_OEM_4 }, { "OEM_5", VK_OEM_5 }, { "OEM_6", VK_OEM_6 }, { "OEM_7", VK_OEM_7 }, { "OEM_8", VK_OEM_8 }, { "OEM_AX", VK_OEM_AX }, { "OEM_102", VK_OEM_102 }, { "ICO_HELP", VK_ICO_HELP }, { "ICO_00", VK_ICO_00 }, { "PROCESSKEY", VK_PROCESSKEY }, { "ICO_CLEAR", VK_ICO_CLEAR }, { "PACKET", VK_PACKET }, { "OEM_RESET", VK_OEM_RESET }, { "OEM_JUMP", VK_OEM_JUMP }, { "OEM_PA1", VK_OEM_PA1 }, { "OEM_PA2", VK_OEM_PA2 }, { "OEM_PA3", VK_OEM_PA3 }, { "OEM_WSCTRL", VK_OEM_WSCTRL }, { "OEM_CUSEL", VK_OEM_CUSEL }, { "OEM_ATTN", VK_OEM_ATTN }, { "OEM_FINISH", VK_OEM_FINISH }, { "OEM_COPY", VK_OEM_COPY }, { "OEM_AUTO", VK_OEM_AUTO }, { "OEM_ENLW", VK_OEM_ENLW }, { "OEM_BACKTAB", VK_OEM_BACKTAB }, { "ATTN", VK_ATTN }, { "CRSEL", VK_CRSEL }, { "EXSEL", VK_EXSEL }, { "EREOF", VK_EREOF }, { "PLAY", VK_PLAY }, { "ZOOM", VK_ZOOM }, { "NONAME", VK_NONAME }, { "PA1", VK_PA1 }, { "OEM_CLEAR", VK_OEM_CLEAR }, { "A", 0x41 }, { "B", 0x42 }, { "C", 0x43 }, { "D", 0x44 }, { "E", 0x45 }, { "F", 0x46 }, { "G", 0x47 }, { "H", 0x48 }, { "I", 0x49 }, { "J", 0x4a }, { "K", 0x4b }, { "L", 0x4c }, { "M", 0x4d }, { "N", 0x4e }, { "O", 0x4f }, { "P", 0x50 }, { "Q", 0x51 }, { "R", 0x52 }, { "S", 0x53 }, { "T", 0x54 }, { "U", 0x55 }, { "V", 0x56 }, { "W", 0x57 }, { "X", 0x58 }, { "Y", 0x59 }, { "Z", 0x5a }, { "0", 0x30 }, { "1", 0x31 }, { "2", 0x32 }, { "3", 0x33 }, { "4", 0x34 }, { "5", 0x35 }, { "6", 0x36 }, { "7", 0x37 }, { "8", 0x38 }, { "9", 0x39 } };

UINT name2key(char const * name)
{
  for (auto const & p : g_keyNames)
    if (std::strcmp(p.name, name) == 0)
      return p.key;
  return 0;
}

char const * key2name(UINT key)
{
  for (auto const & p : g_keyNames)
    if (p.key == key)
      return p.name;
  return "";
}


size_t guid2cstr(char * buf, size_t n, REFGUID rguid)
{
  char const * fmt = "%08lX-%04hX-%04hX-%02hhX%02hhX-%02hhX%02hhX%02hhX%02hhX%02hhX%02hhX"; 
  return snprintf(buf, n, fmt,
    rguid.Data1, rguid.Data2, rguid.Data3, 
    rguid.Data4[0], rguid.Data4[1], rguid.Data4[2], rguid.Data4[3],
    rguid.Data4[4], rguid.Data4[5], rguid.Data4[6], rguid.Data4[7]);
}


std::string guid2str(REFGUID rguid)
{
  size_t const n = 37;
  char buf[n] = {0};
  guid2cstr(buf, n, rguid);
  return buf;
}


std::string preset_guid2str(REFGUID rguid)
{
  static struct { REFGUID rguid; char const * name; } names[] =
  {
    { GUID_SysKeyboard, "keyboard" },
    { GUID_SysMouse, "mouse" },
    { GUID_Joystick, "joystick" }
  };

  for (auto const & p : names)
  {
    if (IsEqualGUID(p.rguid, rguid))
      return p.name;
  }
  return "";
}

/* Flag */
class Flag
{
public:
  virtual bool get() const =0;

  virtual ~Flag() =default;
};

class Tick
{
public:
  virtual void tick() =0;

  virtual ~Tick() =default;
};


class CompositeTick : public Tick
{
public:
  virtual void tick()
  {
    for (auto const & pt : ticks_)
    {
      pt->tick();
    }
  }

  void add(std::shared_ptr<Tick> const & spTick)
  {
    if (!spTick) throw std::runtime_error("Tick pointer is NULL");
    ticks_.push_back(spTick);
  }

private:
  std::vector<std::shared_ptr<Tick> > ticks_;
};


class CallbackTick : public Tick
{
public:
  typedef std::function<void(bool)> callback_t;

  virtual void tick()
  {
    assert(cb_);
    assert(spFlag_);

    bool b = spFlag_->get();
    if (b != b_)
    {
      cb_(b);
      b_ = b;
    }
  }

  CallbackTick(callback_t const & cb, std::shared_ptr<Flag> const & spFlag)
    : cb_(cb), spFlag_(spFlag)
  {
    if (!cb) throw std::runtime_error("Callback is empty");
    if (!spFlag) throw std::runtime_error("Flag pointer is NULL");
    b_ = spFlag_->get();
    cb_(b_);
  }

private:
  bool b_ = false;
  callback_t cb_;
  std::shared_ptr<Flag> spFlag_;
};


enum class KeyEventType : int { pressed=0, released=1 };

class KeyListenerTick : public Tick
{
public:
  typedef UINT key_t;
  typedef unsigned int callback_handle_t;
  typedef std::function<void()> callback_t;

  virtual void tick()
  {
    /* In case some callbacks were removed between tick() calls. */
    if (dirty_ == true)
    {
      cleanup();
      dirty_ = false;
    }

    bool isPressed = GetKeyState(key_) & 0x8000;
    if (isPressed != wasPressed_)
    {
      auto const ket = (isPressed && !wasPressed_) ? KeyEventType::pressed : KeyEventType::released;
      for (auto & p : callbacks_[static_cast<int>(ket)])
        if (p.second != 0)
          p.first();
      wasPressed_ = isPressed;
    }

    /* In case some callbacks were removed during this tick() call (i.e. by callback itself). */
    if (dirty_ == true)
    {
      cleanup();
      dirty_ = false;
    }
  }

  callback_handle_t add(KeyEventType ket, callback_t const & cb)
  {
    auto handle = handles_ + 1;
    callbacks_[static_cast<int>(ket)].push_back(std::make_pair(cb, handle));
    ++handles_;
    if (handles_ == 0) ++handles_;
    return handle;
  }

  bool remove(callback_handle_t const & ch)
  {
    KeyEventType const kets[] = { KeyEventType::pressed, KeyEventType::released };
    for (auto const & ket : kets)
    {
      auto cbs = callbacks_[static_cast<int>(ket)];
      auto it = std::find_if(cbs.begin(), cbs.end(), [&ch](decltype(cbs)::value_type const & v){ return v.second == ch; });
      if (it != cbs.end())
      {
        it->second = 0;
        dirty_ = true;
        return true;
      }
    }
    return false;
  }

  KeyListenerTick(key_t key) : key_(key) {}

private:
  void cleanup()
  {
    KeyEventType const kets[] = { KeyEventType::pressed, KeyEventType::released };
    for (auto const & ket : kets)
    {
      auto cbs = callbacks_[static_cast<int>(ket)];
      cbs.erase(std::remove_if(cbs.begin(), cbs.end(), [](decltype(cbs)::value_type & v) { return v.second == 0; }), cbs.end());
    }
  }

  typedef std::vector<std::pair<callback_t, callback_handle_t> > callbacks_t;
  callbacks_t callbacks_[2];
  callback_handle_t handles_ = 0;

  key_t key_;
  bool wasPressed_ = false;
  bool dirty_ = false;
};


class ToggleTickFlag : public Tick, public Flag
{
public:
  virtual bool get() const
  {
    if (updateOnGet_)
      const_cast<ToggleTickFlag&>(*this).tick();
    log_debug("ToggleTickFlag::get(%p): flag_: %d", this, flag_);
    return flag_;
  }

  virtual void tick()
  {
    auto isPressed = GetKeyState(key_) & 0x8000;
    if (isPressed && !wasPressed_) { flag_ = !flag_; }
    wasPressed_ = isPressed;
  }

  ToggleTickFlag(UINT key, bool initial=true, bool updateOnGet=false)
    : wasPressed_(false), flag_(initial), key_(key), updateOnGet_(updateOnGet)
  {
    wasPressed_ = GetKeyState(key_) & 0x8000;
  }

private:
  bool wasPressed_;
  bool flag_;
  UINT key_;
  bool updateOnGet_;
};

class PressTickFlag : public Tick, public Flag
{
public:
  virtual bool get() const
  {
    if (updateOnGet_)
      const_cast<PressTickFlag&>(*this).tick();
    log_debug("PressTickFlag::get(%p): flag_: %d", this, flag_);
    return flag_;
  }

  virtual void tick()
  {
    flag_ = GetKeyState(key_) & 0x8000;
  }

  PressTickFlag(UINT key, bool updateOnGet=false) : flag_(false), key_(key), updateOnGet_(updateOnGet) {}

private:
  bool flag_;
  UINT key_;
  bool updateOnGet_;
};

class NotFlag : public Flag
{
public:
  virtual bool get() const { return !spNext_->get(); }

  NotFlag(std::shared_ptr<Flag> const & spNext) : spNext_(spNext) {}

private:
  std::shared_ptr<Flag> spNext_;
};

class CompositeFlag : public Flag
{
public:
  virtual bool get() const
  {
    auto first = true;
    auto result = false;
    for (auto const & spFlag : flags_)
      result = first ? first = false, spFlag->get() : combine_(result, spFlag->get());
    log_debug("CompositeFlag::get(%p): result: %d", this, result);
    return result;
  }

  void add(std::shared_ptr<Flag> const & spFlag)
  {
    if (!spFlag) throw std::runtime_error("Flag pointer is NULL");
    flags_.push_back(spFlag);
  }

  CompositeFlag(std::function<bool(bool,bool)> const & combine)
    : flags_(), combine_(combine)
  {}

  CompositeFlag(std::vector<std::shared_ptr<Flag> > const & flags, std::function<bool(bool,bool)> const & combine)
    : flags_(flags), combine_(combine)
  {
    for (auto const & spFlag : flags)
      if (!spFlag) throw std::runtime_error("Flag pointer is NULL");
  }

private:
  std::vector<std::shared_ptr<Flag> > flags_;
  std::function<bool(bool,bool)> combine_;
};

class ConstantFlag : public Flag
{
public:
  virtual bool get() const { return v_; }
  void set(bool b) { v_ = b; }

  ConstantFlag(bool v) : v_(v) {}

private:
  bool v_;
};


/* BlockingCIDirectInputDevice8 */
HRESULT BlockingCIDirectInputDevice8::GetDeviceState(LPDIRECTINPUTDEVICE8 This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BlockingCIDirectInputDevice8::GetDeviceState(%p)", This);
  auto result = This->lpVtbl->GetDeviceState(This, cbData, lpvData);

  if (result == DI_OK && spFlag_->get() == false)
  {
    /* TODO Account for relative and absolute devices: zero-out for relative and return saved date for absolute. */
    std::memset(lpvData, 0, cbData);
  }

  return result;
}

HRESULT BlockingCIDirectInputDevice8::GetDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BlockingCIDirectInputDevice8::GetDeviceData(%p)", This);
  auto result = This->lpVtbl->GetDeviceData(This, cbObjectData, rgdod, pdwInOut, dwFlags);

  if (result == DI_OK && spFlag_->get() == false)
  {
    *pdwInOut = 0;
  }

  return result;
}

BlockingCIDirectInputDevice8::BlockingCIDirectInputDevice8(std::shared_ptr<Flag> const & spFlag)
  : spFlag_(spFlag)
{}


/* BoundBlockingCIDirectInputDevice8 */
HRESULT BoundBlockingCIDirectInputDevice8::GetDeviceState(LPDIRECTINPUTDEVICE8 This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BoundBlockingCIDirectInputDevice8::GetDeviceState(%p)", This);
  auto result = This->lpVtbl->GetDeviceState(This, cbData, lpvData);

  if (result == DI_OK && state_ == false)
  {
    /* TODO Account for relative and absolute devices: zero-out for relative and return saved date for absolute. */
    std::memset(lpvData, 0, cbData);
  }

  return result;
}

HRESULT BoundBlockingCIDirectInputDevice8::GetDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BoundBlockingCIDirectInputDevice8::GetDeviceData(%p)", This);

  /* Setting dwFlags to 0 to read all messages in supplied buffer and thus definitely clear dinput message queue. */
  if (state_ == false)
    dwFlags = 0;
  /* Setting rgdod to nullptr leaves messages in internal dinput queue, so have to read them into supplied buffer. */
  auto const num = *pdwInOut;
  auto result = This->lpVtbl->GetDeviceData(This, cbObjectData, rgdod, pdwInOut, dwFlags);
  if (state_ == false)
  {
    if (clearBuffer_ == true)
      std::memset(rgdod, 0, num*cbObjectData);
    *pdwInOut = 0;
  }

  return result;
}

void BoundBlockingCIDirectInputDevice8::set_state(bool s)
{
  state_ = s;
}

bool BoundBlockingCIDirectInputDevice8::get_state() const
{
  return state_;
}

BoundBlockingCIDirectInputDevice8::BoundBlockingCIDirectInputDevice8(bool state, bool clearBuffer, BoundBlockingCIDirectInputDevice8::on_destroy_t const & onDestroy)
  : state_(state), clearBuffer_(clearBuffer), onDestroy_(onDestroy)
{}

BoundBlockingCIDirectInputDevice8::~BoundBlockingCIDirectInputDevice8()
{
  if (onDestroy_) onDestroy_();
}


/* WrappingCIDirectInput8 */
HRESULT WrappingCIDirectInput8::CreateDevice(LPDIRECTINPUT8 This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  auto result = CIDirectInput8::CreateDevice(This, rguid, lplpDirectInputDevice, pUnkOuter);
  if (result == S_OK)
  {
    auto upDeviceCallback = std::unique_ptr<CIDirectInputDevice8>(new CIDirectInputDevice8);
    auto upDeviceWrapper = std::unique_ptr<WIDirectInputDevice8>(new WIDirectInputDevice8(*lplpDirectInputDevice, upDeviceCallback.get()));
    *lplpDirectInputDevice = reinterpret_cast<LPDIRECTINPUTDEVICE8A>(upDeviceWrapper.release());
    upDeviceCallback.release();
  }
  return result;
}

WrappingCIDirectInput8::~WrappingCIDirectInput8() {}


DeviceKind get_device_kind(REFGUID rguid)
{
  if (IsEqualGUID(rguid, GUID_SysKeyboard))
    return DeviceKind::keyboard;
  else if (IsEqualGUID(rguid, GUID_SysMouse))
    return DeviceKind::mouse;
  else if (IsEqualGUID(rguid, GUID_Joystick))
    return DeviceKind::joystick;
  else
    return DeviceKind::other;
}


/* FactoryCIDirectInput8 */
HRESULT FactoryCIDirectInput8::CreateDevice(LPDIRECTINPUT8 This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  char csGuid [37];
  guid2cstr(csGuid, sizeof(csGuid), rguid);
  log_debug("Creating device for GUID: %s", csGuid);
  HRESULT result = CIDirectInput8::CreateDevice(This, rguid, lplpDirectInputDevice, pUnkOuter);
  if (result == S_OK)
  {
    DIDEVICEINSTANCE ddi;
    std::memset(&ddi, 0, sizeof(ddi));
    ddi.dwSize = sizeof(ddi);
    HRESULT ddiResult = (*lplpDirectInputDevice)->lpVtbl->GetDeviceInfo(*lplpDirectInputDevice, &ddi);
    if (ddiResult == S_OK)
    {
      log_debug("Created device: GUID: %s; name: %s", csGuid, ddi.tszInstanceName);
    }

    auto upDeviceCallback = make_callback_(rguid);
    auto upDeviceWrapper = std::unique_ptr<WIDirectInputDevice8>(new WIDirectInputDevice8(*lplpDirectInputDevice, upDeviceCallback.get()));
    *lplpDirectInputDevice = reinterpret_cast<LPDIRECTINPUTDEVICE8A>(upDeviceWrapper.release());
    upDeviceCallback.release();
  }
  return result;
}

FactoryCIDirectInput8::FactoryCIDirectInput8(FactoryCIDirectInput8::make_callback_t const & make_callback)
  : make_callback_(make_callback)
{}


typedef std::map<std::string, std::map<std::string, std::string> > config_t;
config_t g_config;

typedef std::unique_ptr<CIDirectInputDevice8> device_callback_ptr_t;
std::function<device_callback_ptr_t(std::map<std::string,std::string> const &)> g_device_callback_factory;

device_callback_ptr_t g_make_device_callback(REFGUID rguid)
{
  auto itBindings = g_config.find(guid2str(rguid));
  if (itBindings == g_config.end())
  {
    auto s = preset_guid2str(rguid);
    if (s != "")
      itBindings = g_config.find(preset_guid2str(rguid));
  }

  auto upDevice =
    itBindings == g_config.end() ?
    device_callback_ptr_t(new CIDirectInputDevice8) :
    g_device_callback_factory(itBindings->second);
  return upDevice;
}


/* Template-based implementations. */
template <template <class> class B, class LPDID>
class BlockingWIDirectInputDevice : public B<BlockingWIDirectInputDevice<B, LPDID> >
{
public:
  typedef BlockingWIDirectInputDevice<B, LPDID> that_type;
  typedef B<that_type> base_type;

  static HRESULT WINAPI GetDeviceState(LPDID This, DWORD cbData, LPVOID lpvData)
  {
    log_debug("BlockingWIDirectInputDevice:GetDeviceState(%p)", This);
    auto That = reinterpret_cast<that_type*>(This);
    auto hr = base_type::GetDeviceState(This, cbData, lpvData);
    auto flag = That->spFlag_->get();
    if ((hr == DI_OK) && !flag)
    {
      /* TODO Account for relative and absolute devices: zero-out for relative and return saved date for absolute. */
      log_debug("BlockingWIDirectInputDevice:GetDeviceState(%p): erasing state", This);
      std::memset(lpvData, 0, cbData);
    }
    return hr;
  }

  static HRESULT WINAPI GetDeviceData(LPDID This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
  {
    log_debug("BlockingWIDirectInputDevice::GetDeviceData(%p)", This);
    auto That = reinterpret_cast<that_type*>(This);
    auto hr = base_type::GetDeviceData(This, cbObjectData, rgdod, pdwInOut, dwFlags);
    auto flag = That->spFlag_->get();
    if ((hr == DI_OK) && !flag)
    {
      log_debug("BlockingWIDirectInputDevice:GetDeviceData(%p): erasing data", This);
      *pdwInOut = 0;
    }
    return hr;
  }

  BlockingWIDirectInputDevice(LPDID pNative, std::shared_ptr<Flag> const & spFlag)
    : base_type(pNative), spFlag_(spFlag)
  {
    log_debug("BlockingWIDirectInputDevice::BlockingWIDirectInputDevice(%p)", this);
  }

  ~BlockingWIDirectInputDevice()
  {
    log_debug("BlockingWIDirectInputDevice::~BlockingWIDirectInputDevice(%p)", this);
  }

private:
  std::shared_ptr<Flag> spFlag_;
};

typedef BlockingWIDirectInputDevice<WIDirectInputDeviceA, LPDIRECTINPUTDEVICEA> BlockingWIDirectInputDeviceA;
typedef BlockingWIDirectInputDevice<WIDirectInputDeviceW, LPDIRECTINPUTDEVICEW> BlockingWIDirectInputDeviceW;
typedef BlockingWIDirectInputDevice<WIDirectInputDevice2A, LPDIRECTINPUTDEVICE2A> BlockingWIDirectInputDevice2A;
typedef BlockingWIDirectInputDevice<WIDirectInputDevice2W, LPDIRECTINPUTDEVICE2W> BlockingWIDirectInputDevice2W;
typedef BlockingWIDirectInputDevice<WIDirectInputDevice7A, LPDIRECTINPUTDEVICE7A> BlockingWIDirectInputDevice7A;
typedef BlockingWIDirectInputDevice<WIDirectInputDevice7W, LPDIRECTINPUTDEVICE7W> BlockingWIDirectInputDevice7W;
typedef BlockingWIDirectInputDevice<WIDirectInputDevice8A, LPDIRECTINPUTDEVICE8A> BlockingWIDirectInputDevice8A;
typedef BlockingWIDirectInputDevice<WIDirectInputDevice8W, LPDIRECTINPUTDEVICE8W> BlockingWIDirectInputDevice8W;


/** Makes device using external factory method */
template <template <class> class B, class LPDI, class LPDID>
class FactoryWIDirectInput : public B<FactoryWIDirectInput<B, LPDI, LPDID> >
{
public:
  typedef FactoryWIDirectInput<B, LPDI, LPDID> that_type;
  typedef B<that_type> base_type;
  typedef std::function<LPDID (REFGUID, LPDID)> device_factory_t;
  typedef std::function<void (LPVOID)> reporter_t;

  static HRESULT WINAPI CreateDevice(LPDI This, REFGUID rguid, LPDID *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
  {
    log_debug("FactoryWIDirectInput::CreateDevice(%p)", This);
    auto That = reinterpret_cast<that_type*>(This);
    auto hr = base_type::CreateDevice(This, rguid, lplpDirectInputDevice, pUnkOuter);
    if (hr == S_OK)
    {
      if (That->reporter_)
        That->reporter_(*lplpDirectInputDevice);
      if (That->deviceFactory_)
        try {
          log_debug("FactoryWIDirectInput::CreateDevice(%p): created native device: %p", This, *lplpDirectInputDevice);
          auto pDevice = That->deviceFactory_(rguid, *lplpDirectInputDevice);
          log_debug("FactoryWIDirectInput::CreateDevice(%p): created wrapper device: %p", This, pDevice);
          *lplpDirectInputDevice = pDevice;
        } catch (...) {
          log_error("FactoryWIDirectInput::CreateDevice(%p): exception, releasing native device %p", This, *lplpDirectInputDevice);
          (*lplpDirectInputDevice)->lpVtbl->Release(*lplpDirectInputDevice);
          throw;
        }
    }
    return hr;
  }

  static HRESULT WINAPI CreateDeviceEx(LPDI This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter)
  {
    log_debug("FactoryWIDirectInput::CreateDeviceEx(%p, %s, %s, %p, %p)", This, guid2str(rguid).data(), guid2str(riid).data(), pvOut, lpUnknownOuter);
    auto That = reinterpret_cast<that_type*>(This);
    auto hr = base_type::CreateDeviceEx(This, rguid, riid, pvOut, lpUnknownOuter);
    if (hr == S_OK)
    {
      if (That->reporter_)
        That->reporter_(*pvOut);
      if (That->deviceFactory_)
        try {
          log_debug("FactoryWIDirectInput::CreateDeviceEx(%p): created native device: %p", This, *pvOut);
          auto pDevice = That->deviceFactory_(rguid, reinterpret_cast<LPDID>(*pvOut));
          log_debug("FactoryWIDirectInput::CreateDevice(%p): created wrapper device: %p", This, pDevice);
          *pvOut = pDevice;
        } catch (...) {
          log_error(
            "FactoryWIDirectInput::CreateDeviceEx(%p, %s, %s, %p, %p): exception, releasing native device %p",
            This, guid2str(rguid).data(), guid2str(riid).data(), pvOut, lpUnknownOuter, *pvOut
          );
          auto pNative = reinterpret_cast<LPUNKNOWN>(*pvOut);
          pNative->lpVtbl->Release(pNative);
          throw;
        }
    }
    return hr; 
  }


  FactoryWIDirectInput(LPDI pNative, device_factory_t const & deviceFactory, reporter_t const & reporter=reporter_t())
    : base_type(pNative), deviceFactory_(deviceFactory), reporter_(reporter)
  {}

private:
  device_factory_t deviceFactory_;
  reporter_t reporter_;
};

void print_ididxa_info(LPVOID lpDevice)
{
  DIDEVICEINSTANCEA ddi;
  std::memset(&ddi, 0, sizeof(ddi));
  ddi.dwSize = sizeof(ddi);
  auto pDevice = reinterpret_cast<LPDIRECTINPUTDEVICEA>(lpDevice);
  HRESULT ddiResult = pDevice->lpVtbl->GetDeviceInfo(pDevice, &ddi);
  if (ddiResult == S_OK)
  {
    static char const * fmt = "Created device: instance GUID: %s; product GUID: %s; instance name: %s; product name: %s; type: 0x%x; usage page: 0x%x; usage: 0x%x";
    log_info(fmt, guid2str(ddi.guidInstance).data(), guid2str(ddi.guidProduct).data(), ddi.tszInstanceName, ddi.tszProductName, ddi.wUsagePage, ddi.wUsage);
  }
  else
    log_error("Failed to get device info");
}

void print_ididxw_info(LPVOID lpDevice)
{
  DIDEVICEINSTANCEW ddi;
  std::memset(&ddi, 0, sizeof(ddi));
  ddi.dwSize = sizeof(ddi);
  auto pDevice = reinterpret_cast<LPDIRECTINPUTDEVICEW>(lpDevice);
  HRESULT ddiResult = pDevice->lpVtbl->GetDeviceInfo(pDevice, &ddi);
  if (ddiResult == S_OK)
  {
    static char const * fmt = "Created device: instance GUID: %s; product GUID: %s; instance name: %ls; product name: %ls; type: 0x%x; usage page: 0x%x; usage: 0x%x";
    log_info(fmt, guid2str(ddi.guidInstance).data(), guid2str(ddi.guidProduct).data(), ddi.tszInstanceName, ddi.tszProductName, ddi.wUsagePage, ddi.wUsage);
  }
  else
    log_error("Failed to get device info");
}

typedef FactoryWIDirectInput<WIDirectInputA, LPDIRECTINPUTA, LPDIRECTINPUTDEVICEA> FactoryWIDirectInputA;
typedef FactoryWIDirectInput<WIDirectInputW, LPDIRECTINPUTW, LPDIRECTINPUTDEVICEW> FactoryWIDirectInputW;
typedef FactoryWIDirectInput<WIDirectInput2A, LPDIRECTINPUT2A, LPDIRECTINPUTDEVICE2A> FactoryWIDirectInput2A;
typedef FactoryWIDirectInput<WIDirectInput2W, LPDIRECTINPUT2W, LPDIRECTINPUTDEVICE2W> FactoryWIDirectInput2W;
typedef FactoryWIDirectInput<WIDirectInput7A, LPDIRECTINPUT7A, LPDIRECTINPUTDEVICE7A> FactoryWIDirectInput7A;
typedef FactoryWIDirectInput<WIDirectInput7W, LPDIRECTINPUT7W, LPDIRECTINPUTDEVICE7W> FactoryWIDirectInput7W;
typedef FactoryWIDirectInput<WIDirectInput8A, LPDIRECTINPUT8A, LPDIRECTINPUTDEVICE8A> FactoryWIDirectInput8A;
typedef FactoryWIDirectInput<WIDirectInput8W, LPDIRECTINPUT8W, LPDIRECTINPUTDEVICE8W> FactoryWIDirectInput8W;


std::shared_ptr<Flag> make_flag(REFGUID rguid)
{
  auto strGuid = guid2str(rguid);
  auto itSection = g_config.find(strGuid);
  if (itSection == g_config.end())
  {
    auto strPreset = preset_guid2str(rguid);
    if (strPreset != "")
      itSection = g_config.find(strPreset);
  }
  if (itSection == g_config.end())
    return nullptr;

  auto const & bindings = itSection->second;
  auto itToggleBinding = bindings.find("toggleKey");
  auto itUnblockBinding = bindings.find("unblockKey");
  if ((itToggleBinding == bindings.end()) && (itUnblockBinding == bindings.end()))
    return nullptr;

  auto spFlag = std::make_shared<CompositeFlag>(std::logical_or<bool>());
  if (itToggleBinding != bindings.end())
  {
    auto toggleKey = name2key(itToggleBinding->second.data());
    spFlag->add(std::make_shared<ToggleTickFlag>(toggleKey, true, true));
  }
  if (itUnblockBinding != bindings.end())
  {
    auto unblockKey = name2key(itUnblockBinding->second.data());
    auto spUnblockFlag = std::make_shared<PressTickFlag>(unblockKey, true);
    spFlag->add(spUnblockFlag);
  }
  return spFlag;
}

template <class DeviceWrapper, class LPDID>
LPDID make_device_wrapper(REFGUID rguid, LPDID pDID)
{
  log_debug("make_device_wrapper(%s, %p)", guid2str(rguid).data(), pDID);
  auto spFlag = make_flag(rguid);
  if (!spFlag)
    return pDID;
  auto pWrapper = reinterpret_cast<LPDID>(new DeviceWrapper(pDID, spFlag));
  log_debug("make_device_wrapper(%s, %p): created wrapper: %p", guid2str(rguid).data(), pDID, pWrapper);
  return pWrapper;
}

LPVOID make_dinputxx_wrapper(REFIID riidltf, LPVOID lpNative)
{
  LPVOID pWrapper = nullptr;
  if (IsEqualGUID(riidltf, IID_IDirectInputA))
  {
    pWrapper = new FactoryWIDirectInputA(
      reinterpret_cast<LPDIRECTINPUTA>(lpNative),
      make_device_wrapper<BlockingWIDirectInputDeviceA, LPDIRECTINPUTDEVICEA>,
      print_ididxa_info
    );
  }
  else if (IsEqualGUID(riidltf, IID_IDirectInput2A))
  {
    pWrapper = new FactoryWIDirectInput2A(
      reinterpret_cast<LPDIRECTINPUT2A>(lpNative),
      make_device_wrapper<BlockingWIDirectInputDevice2A, LPDIRECTINPUTDEVICE2A>,
      print_ididxa_info
    );
  }
  else if (IsEqualGUID(riidltf, IID_IDirectInput7A))
  {
    pWrapper = new FactoryWIDirectInput7A(
      reinterpret_cast<LPDIRECTINPUT7A>(lpNative),
      make_device_wrapper<BlockingWIDirectInputDevice7A, LPDIRECTINPUTDEVICE7A>,
      print_ididxa_info
    );
  }
  else if (IsEqualGUID(riidltf, IID_IDirectInput8A))
  {
    pWrapper = new FactoryWIDirectInput8A(
      reinterpret_cast<LPDIRECTINPUT8A>(lpNative),
      make_device_wrapper<BlockingWIDirectInputDevice8A, LPDIRECTINPUTDEVICE8A>,
      print_ididxa_info
    );
  }
  else if (IsEqualGUID(riidltf, IID_IDirectInputW))
  {
    pWrapper = new FactoryWIDirectInputW(
      reinterpret_cast<LPDIRECTINPUTW>(lpNative),
      make_device_wrapper<BlockingWIDirectInputDeviceW, LPDIRECTINPUTDEVICEW>,
      print_ididxw_info
    );
  }
  else if (IsEqualGUID(riidltf, IID_IDirectInput2W))
  {
    pWrapper = new FactoryWIDirectInput2W(
      reinterpret_cast<LPDIRECTINPUT2W>(lpNative),
      make_device_wrapper<BlockingWIDirectInputDevice2W, LPDIRECTINPUTDEVICE2W>,
      print_ididxw_info
    );
  }
  else if (IsEqualGUID(riidltf, IID_IDirectInput7W))
  {
    pWrapper = new FactoryWIDirectInput7W(
      reinterpret_cast<LPDIRECTINPUT7W>(lpNative),
      make_device_wrapper<BlockingWIDirectInputDevice7W, LPDIRECTINPUTDEVICE7W>,
      print_ididxw_info
    );
  }
  else if (IsEqualGUID(riidltf, IID_IDirectInput8W))
  {
    pWrapper = new FactoryWIDirectInput8W(
      reinterpret_cast<LPDIRECTINPUT8W>(lpNative),
      make_device_wrapper<BlockingWIDirectInputDevice8W, LPDIRECTINPUTDEVICE8W>,
      print_ididxw_info
    );
  }
  else
    log_debug("make_dinputxx_wrapper(): unknown GUID: %s", guid2str(riidltf).data());
  if (pWrapper)
    log_debug("make_dinputxx_wrapper(): created wrapper: %p", pWrapper);
  else
    log_debug("make_dinputxx_wrapper(): could not create wrapper for: %p", lpNative);
  return pWrapper;
}


/* config */
config_t parse_config(std::istream & configStream, char const * configName)
{
  config_t config;
  std::string section ("");
  config[section] = config_t::mapped_type();
  auto validSection = true;

  std::string buf;
  int i = 0;

  while (std::getline(configStream, buf))
  {
    ++i;
    if (0 == buf.length())
    {
      log_debug("%d: Skipping empty line", i);
      continue;
    }
    else if ('#' == buf.front())
    {
      log_debug("%d: Parsed %s: skipping comment", i, buf.data());
      continue;
    }
    else if ('[' == buf.front())
    {
      char sectionName[64] = {0};
      char dummy[2];
      if (2 == std::sscanf(buf.data(), "[%[^] \t\n\r]%[]]", sectionName, dummy))
      {
        log_debug("%d: Parsed %s: section:%s", i, buf.data(), sectionName);
        section = sectionName;
        config[section] = config_t::mapped_type();
        validSection = true;
      }
      else
      {
        log_error("%s:%d: Invalid section definition:\"%s\" (should be [sectionName])", configName, i, buf.data());
        validSection = false;
      }
    }
    else if (std::strstr(buf.data(), "="))
    {
      char k[64] = {0};
      char v[64] = {0};
      if (2 == std::sscanf(buf.data(), "%[^= \t\n\r]=%[^= \t\n\r]", k, v))
      {
        if (!validSection)
        {
          log_debug("%d: Parsed %s: skipping due to invalid section", i, buf.data(), section.data());
          continue;
        }
        else
        {
          log_debug("%d: Parsed %s: k:%s; v:%s; adding to section:%s", i, buf.data(), k, v, section.data());
          config[section][k] = v;
        }
      }
      else
      {
        log_error("%s:%d: Invalid property definition:\"%s\" (should be property=value)", configName, i, buf.data());
      }
    }
    else
    {
      log_error("%s:%d: Can't parse:\"%s\" (must be [sectionName] or property=value)", configName, i, buf.data());
      continue;
    }
  }

  return config;
}

void write_sample_config(std::ofstream& sampleConfigFileStream)
{
  sampleConfigFileStream 
    << "#Sample configuration file for DirectInput/DirectInput8 blocker\n"
    << "#Comments start with \"#\"\n"
    << "#Log level (available levels: NOTSET, TRACE, DEBUG, INFO, WARNING, ERROR):\n"
    << "#logLevel=level\n"
    << "#Section with key bindings for a device is an instance guid (i.e. 6F1D2B60-D5A0-11CF-BFC7-444553540000). Instance guids of created devices are included in device info written to log as INFO-level messages\n"
    << "#[device instance guid]\n"
    << "#Key to toggle device blocking:\n"
    << "#toggleKey=keyName\n"
    << "#Key to press to unblock a blocked device:\n"
    << "#unblockKey=keyName\n"
    << "#available keys are: ";
    bool first = true;
    for (auto const & p : g_keyNames)
      sampleConfigFileStream << (first ? first=false, "" : ", ") << p.name;
  sampleConfigFileStream << "\n";
}

void open_and_parse_config()
{
  log_debug("Parsing config");

  auto configFileName = "dinput8_blocker.ini";
  auto configFileStream = std::ifstream(configFileName);
  if (!configFileStream.is_open())
  {
    log_info("Can't open config %s for reading, writing it as sample config", configFileName);
    auto sampleConfigFileStream = std::ofstream(configFileName);
    if (!sampleConfigFileStream.is_open())
      log_error("Can't open config %s for writing sample config", configFileName);
    else
      write_sample_config(sampleConfigFileStream);
    return;
  }
  else
  {
    log_info("Found config: %s", configFileName);
  }

  g_config = parse_config(configFileStream, configFileName);
  log_debug("Parsed config");
}

void init_log()
try {
  auto const & strLogLevel = g_config.at("").at("logLevel");
  auto logLevel = name2loglevel(strLogLevel.data());
  log_set_level(logLevel);
} catch (...) {
  log_set_level(LogLevel::notset);
}


/* loop */
class Loop
{
public:
  typedef std::recursive_mutex mutex_t;
  typedef std::unique_lock<mutex_t> lock_t;

  void operator()()
  {
    while (!exiting_)
    {
      lock_t l (mutex_);

      if (dirty_)
      {
        cleanup();
        dirty_ = false;
      }

      for (auto const & spTick : ticks_)
        if (spTick)
          spTick->tick();

      l.unlock();

      std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime_));
    }
  }

  bool add_tick(std::shared_ptr<Tick> const & spTick)
  {
    lock_t l (mutex_);
    if (spTick && std::find(ticks_.cbegin(), ticks_.cend(), spTick) != ticks_.end()) return false;
    ticks_.push_back(spTick);
    return true;
  }

  bool remove_tick(Tick const * pTick)
  {
    lock_t l (mutex_);
    auto itTick = std::find_if(
      ticks_.begin(),
      ticks_.end(),
      [pTick](std::shared_ptr<Tick> const & spTick){ return spTick.get() == pTick; }
    );
    if (itTick != ticks_.end())
    {
      itTick->reset();
      dirty_ = true;
      return true;
    }
    return false;
  }

  bool remove_tick(std::shared_ptr<Tick> const & spTick)
  {
    return remove_tick(spTick.get());
  }

  void exit()
  {
    exiting_ = true;
  }

  mutex_t & get_mutex()
  {
    return mutex_;
  }

  Loop(unsigned int sleepTime) : ticks_(), sleepTime_(sleepTime) {}

private:
  void cleanup()
  {
    ticks_.erase(std::remove(ticks_.begin(), ticks_.end(), nullptr), ticks_.end());
  }

  std::vector<std::shared_ptr<Tick> > ticks_;
  bool exiting_ = false;
  bool dirty_ = false;
  unsigned int sleepTime_;

  mutex_t mutex_;
};

Loop * g_pLoop;

void start_loop()
{
  g_pLoop = new Loop (10);

  g_device_callback_factory = [](std::map<std::string,std::string> const & bindings)
  {
    auto spCompositeFlag = std::make_shared<CompositeFlag>(std::logical_or<bool>());
    auto spCompositeTick = std::make_shared<CompositeTick>();
    auto pCompositeTick = spCompositeTick.get();

    auto onDestroy = [pCompositeTick]()
    {
      Loop::lock_t l (g_pLoop->get_mutex());
      g_pLoop->remove_tick(pCompositeTick);
    };

    std::unique_ptr<BoundBlockingCIDirectInputDevice8> upDevice (new BoundBlockingCIDirectInputDevice8 (true, false, onDestroy));

    {
      /* TODO Error checking.*/
      auto const & keyName = bindings.at("toggleKey");
      auto key = name2key(keyName.data());
      auto spFlag = std::make_shared<ConstantFlag>(true);
      auto spKeyTick = std::make_shared<KeyListenerTick>(key);
      spKeyTick->add(KeyEventType::pressed, [spFlag](){ spFlag->set(!spFlag->get()); });
      spCompositeFlag->add(spFlag);
      spCompositeTick->add(spKeyTick);
    }
    {
      /* TODO Error checking.*/
      auto const & keyName = bindings.at("unblockKey");
      auto key = name2key(keyName.data());
      auto spFlag = std::make_shared<ConstantFlag>(false);
      auto spKeyTick = std::make_shared<KeyListenerTick>(key);
      spKeyTick->add(KeyEventType::pressed, [spFlag](){ spFlag->set(true); });
      spKeyTick->add(KeyEventType::released, [spFlag](){ spFlag->set(false); });
      spCompositeFlag->add(spFlag);
      spCompositeTick->add(spKeyTick);
    }
    {
      auto pDevice = upDevice.get();
      /* TODO Guard set_state() with mutex or make state_ atomic. */
      auto spTick = std::make_shared<CallbackTick>([pDevice](bool b){ pDevice->set_state(b); }, spCompositeFlag);
      spCompositeTick->add(spTick);
    }

    Loop::lock_t l (g_pLoop->get_mutex());
    g_pLoop->add_tick(spCompositeTick);
    return upDevice;
  };

  std::thread t (&Loop::operator(), g_pLoop);
  t.detach();
}

void stop_loop()
{
  g_pLoop->exit();
}

} // namespace di8b 
