#include <dinput8_blocker.hpp>
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

#include <fstream>


#define DLLEXPORT __declspec(dllexport)

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
  virtual bool get() const { return flag_; }

  virtual void tick()
  {
    auto isPressed = GetKeyState(key_) & 0x8000;
    if (isPressed && !wasPressed_) { flag_ = !flag_; }
    wasPressed_ = isPressed;
  }

  ToggleTickFlag(UINT key, bool initial=true)
    : wasPressed_(false), flag_(initial), key_(key)
  {
    wasPressed_ = GetKeyState(key_) & 0x8000;
  }

private:
  bool wasPressed_;
  bool flag_;
  UINT key_;
};

class PressTickFlag : public Tick, public Flag
{
public:
  virtual bool get() const { return flag_; }

  virtual void tick()
  {
    flag_ = GetKeyState(key_) & 0x8000;
  }

  PressTickFlag(UINT key) : flag_(false), key_(key) {}

private:
  bool flag_;
  UINT key_;
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


/* WIDirectInputDevice8 */
VIDirectInputDevice8::VIDirectInputDevice8() : QueryInterface(WIDirectInputDevice8::QueryInterface), AddRef(WIDirectInputDevice8::AddRef), Release(WIDirectInputDevice8::Release), GetCapabilities(WIDirectInputDevice8::GetCapabilities), EnumObjects(WIDirectInputDevice8::EnumObjects), GetProperty(WIDirectInputDevice8::GetProperty), SetProperty(WIDirectInputDevice8::SetProperty), Acquire(WIDirectInputDevice8::Acquire), Unacquire(WIDirectInputDevice8::Unacquire), GetDeviceState(WIDirectInputDevice8::GetDeviceState), GetDeviceData(WIDirectInputDevice8::GetDeviceData), SetDataFormat(WIDirectInputDevice8::SetDataFormat), SetEventNotification(WIDirectInputDevice8::SetEventNotification), SetCooperativeLevel(WIDirectInputDevice8::SetCooperativeLevel), GetObjectInfo(WIDirectInputDevice8::GetObjectInfo), GetDeviceInfo(WIDirectInputDevice8::GetDeviceInfo), RunControlPanel(WIDirectInputDevice8::RunControlPanel), Initialize(WIDirectInputDevice8::Initialize), CreateEffect(WIDirectInputDevice8::CreateEffect), EnumEffects(WIDirectInputDevice8::EnumEffects), GetEffectInfo(WIDirectInputDevice8::GetEffectInfo), GetForceFeedbackState(WIDirectInputDevice8::GetForceFeedbackState), SendForceFeedbackCommand(WIDirectInputDevice8::SendForceFeedbackCommand), EnumCreatedEffectObjects(WIDirectInputDevice8::EnumCreatedEffectObjects), Escape(WIDirectInputDevice8::Escape), Poll(WIDirectInputDevice8::Poll), SendDeviceData(WIDirectInputDevice8::SendDeviceData), EnumEffectsInFile(WIDirectInputDevice8::EnumEffectsInFile), WriteEffectToFile(WIDirectInputDevice8::WriteEffectToFile), BuildActionMap(WIDirectInputDevice8::BuildActionMap), SetActionMap(WIDirectInputDevice8::SetActionMap), GetImageInfo(WIDirectInputDevice8::GetImageInfo)
{}

VIDirectInputDevice8 const WIDirectInputDevice8::vIDirectInputDevice8;

WIDirectInputDevice8::WIDirectInputDevice8(::IDirectInputDevice8* pNative, CIDirectInputDevice8* pCallback)
  : pVtbl_(&vIDirectInputDevice8), pNative_(pNative), pCallback_(pCallback)
{
  log_debug("WIDirectInputDevice8::WIDirectInputDevice8(%p)", this);
}

HRESULT WINAPI WIDirectInputDevice8::QueryInterface(::IDirectInputDevice8* This, REFIID riid, void** ppvObject)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->QueryInterface(That->pNative_, riid, ppvObject);
}

ULONG WINAPI WIDirectInputDevice8::AddRef(::IDirectInputDevice8* This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->AddRef(That->pNative_);
}

ULONG WINAPI WIDirectInputDevice8::Release(::IDirectInputDevice8* This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  auto refcount = That->pCallback_->Release(That->pNative_);
  if (refcount == 0)
  {
    log_debug("WIDirectInputDevice8::Release(%p): deleting self", This);
    delete That;
  }
  return refcount;
}

HRESULT WINAPI WIDirectInputDevice8::GetCapabilities(::IDirectInputDevice8* This, LPDIDEVCAPS lpDIDevCaps)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetCapabilities(That->pNative_, lpDIDevCaps);
}

HRESULT WINAPI WIDirectInputDevice8::EnumObjects(::IDirectInputDevice8* This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumObjects(That->pNative_, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::GetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetProperty(That->pNative_, rguidProp, pdiph);
}

HRESULT WINAPI WIDirectInputDevice8::SetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetProperty(That->pNative_, rguidProp, pdiph);
}

HRESULT WINAPI WIDirectInputDevice8::Acquire(::IDirectInputDevice8* This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Acquire(That->pNative_);
}

HRESULT WINAPI WIDirectInputDevice8::Unacquire(::IDirectInputDevice8* This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Unacquire(That->pNative_);
}

HRESULT WINAPI WIDirectInputDevice8::GetDeviceState(::IDirectInputDevice8* This, DWORD cbData, LPVOID lpvData)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetDeviceState(That->pNative_, cbData, lpvData);
}

HRESULT WINAPI WIDirectInputDevice8::GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetDeviceData(That->pNative_, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::SetDataFormat(::IDirectInputDevice8* This, LPCDIDATAFORMAT lpdf)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetDataFormat(That->pNative_, lpdf);
}

HRESULT WINAPI WIDirectInputDevice8::SetEventNotification(::IDirectInputDevice8* This, HANDLE hEvent)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetEventNotification(That->pNative_, hEvent);
}

HRESULT WINAPI WIDirectInputDevice8::SetCooperativeLevel(::IDirectInputDevice8* This, HWND hwnd, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetCooperativeLevel(That->pNative_, hwnd, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::GetObjectInfo(::IDirectInputDevice8* This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetObjectInfo(That->pNative_, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI WIDirectInputDevice8::GetDeviceInfo(::IDirectInputDevice8* This, LPDIDEVICEINSTANCEA pdidi)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetDeviceInfo(That->pNative_, pdidi);
}

HRESULT WINAPI WIDirectInputDevice8::RunControlPanel(::IDirectInputDevice8* This, HWND hwndOwner, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->RunControlPanel(That->pNative_, hwndOwner, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::Initialize(::IDirectInputDevice8* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Initialize(That->pNative_, hinst, dwVersion, rguid);
}

HRESULT WINAPI WIDirectInputDevice8::CreateEffect(::IDirectInputDevice8* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->CreateEffect(That->pNative_, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI WIDirectInputDevice8::EnumEffects(::IDirectInputDevice8* This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumEffects(That->pNative_, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI WIDirectInputDevice8::GetEffectInfo(::IDirectInputDevice8* This, LPDIEFFECTINFOA pdei, REFGUID rguid)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetEffectInfo(That->pNative_, pdei, rguid);
}

HRESULT WINAPI WIDirectInputDevice8::GetForceFeedbackState(::IDirectInputDevice8* This, LPDWORD pdwOut)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetForceFeedbackState(That->pNative_, pdwOut);
}

HRESULT WINAPI WIDirectInputDevice8::SendForceFeedbackCommand(::IDirectInputDevice8* This, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SendForceFeedbackCommand(That->pNative_, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::EnumCreatedEffectObjects(::IDirectInputDevice8* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumCreatedEffectObjects(That->pNative_, lpCallback, pvRef, fl);
}

HRESULT WINAPI WIDirectInputDevice8::Escape(::IDirectInputDevice8* This, LPDIEFFESCAPE pesc)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Escape(That->pNative_, pesc);
}

HRESULT WINAPI WIDirectInputDevice8::Poll(::IDirectInputDevice8* This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Poll(That->pNative_);
}

HRESULT WINAPI WIDirectInputDevice8::SendDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SendDeviceData(That->pNative_, cbObjectData, rgdod, pdwInOut, fl);
}

HRESULT WINAPI WIDirectInputDevice8::EnumEffectsInFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumEffectsInFile(That->pNative_, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::WriteEffectToFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->WriteEffectToFile(That->pNative_, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::BuildActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->BuildActionMap(That->pNative_, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::SetActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetActionMap(That->pNative_, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::GetImageInfo(::IDirectInputDevice8* This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetImageInfo(That->pNative_, lpdiDevImageInfoHeader);
}


/* CIDirectInputDevice8 */
HRESULT CIDirectInputDevice8::QueryInterface(::IDirectInputDevice8* This, REFIID riid, void** ppvObject)
{
  return This->lpVtbl->QueryInterface(This, riid, ppvObject);
}

ULONG CIDirectInputDevice8::AddRef(::IDirectInputDevice8* This)
{
  return This->lpVtbl->AddRef(This);
}

ULONG CIDirectInputDevice8::Release(::IDirectInputDevice8* This)
{
  auto refcount = This->lpVtbl->Release(This);
  if (refcount == 0)
  {
    log_debug("CIDirectInputDevice8::Release(%p): deleting self", this);
    delete this;
  }
  return refcount;
}

HRESULT CIDirectInputDevice8::GetCapabilities(::IDirectInputDevice8* This, LPDIDEVCAPS lpDIDevCaps)
{
  return This->lpVtbl->GetCapabilities(This, lpDIDevCaps);
}

HRESULT CIDirectInputDevice8::EnumObjects(::IDirectInputDevice8* This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  return This->lpVtbl->EnumObjects(This, lpCallback, pvRef, dwFlags);
}

HRESULT CIDirectInputDevice8::GetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  return This->lpVtbl->GetProperty(This, rguidProp, pdiph);
}

HRESULT CIDirectInputDevice8::SetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  return This->lpVtbl->SetProperty(This, rguidProp, pdiph);
}

HRESULT CIDirectInputDevice8::Acquire(::IDirectInputDevice8* This)
{
  return This->lpVtbl->Acquire(This);
}

HRESULT CIDirectInputDevice8::Unacquire(::IDirectInputDevice8* This)
{
  return This->lpVtbl->Unacquire(This);
}

HRESULT CIDirectInputDevice8::GetDeviceState(::IDirectInputDevice8* This, DWORD cbData, LPVOID lpvData)
{
  return This->lpVtbl->GetDeviceState(This, cbData, lpvData);
}

HRESULT CIDirectInputDevice8::GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  return This->lpVtbl->GetDeviceData(This, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT CIDirectInputDevice8::SetDataFormat(::IDirectInputDevice8* This, LPCDIDATAFORMAT lpdf)
{
  return This->lpVtbl->SetDataFormat(This, lpdf);
}

HRESULT CIDirectInputDevice8::SetEventNotification(::IDirectInputDevice8* This, HANDLE hEvent)
{
  return This->lpVtbl->SetEventNotification(This, hEvent);
}

HRESULT CIDirectInputDevice8::SetCooperativeLevel(::IDirectInputDevice8* This, HWND hwnd, DWORD dwFlags)
{
  return This->lpVtbl->SetCooperativeLevel(This, hwnd, dwFlags);
}

HRESULT CIDirectInputDevice8::GetObjectInfo(::IDirectInputDevice8* This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  return This->lpVtbl->GetObjectInfo(This, pdidoi, dwObj, dwHow);
}

HRESULT CIDirectInputDevice8::GetDeviceInfo(::IDirectInputDevice8* This, LPDIDEVICEINSTANCEA pdidi)
{
  return This->lpVtbl->GetDeviceInfo(This, pdidi);
}

HRESULT CIDirectInputDevice8::RunControlPanel(::IDirectInputDevice8* This, HWND hwndOwner, DWORD dwFlags)
{
  return This->lpVtbl->RunControlPanel(This, hwndOwner, dwFlags);
}

HRESULT CIDirectInputDevice8::Initialize(::IDirectInputDevice8* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  return This->lpVtbl->Initialize(This, hinst, dwVersion, rguid);
}

HRESULT CIDirectInputDevice8::CreateEffect(::IDirectInputDevice8* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  return This->lpVtbl->CreateEffect(This, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT CIDirectInputDevice8::EnumEffects(::IDirectInputDevice8* This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  return This->lpVtbl->EnumEffects(This, lpCallback, pvRef, dwEffType);
}

HRESULT CIDirectInputDevice8::GetEffectInfo(::IDirectInputDevice8* This, LPDIEFFECTINFOA pdei, REFGUID rguid)
{
  return This->lpVtbl->GetEffectInfo(This, pdei, rguid);
}

HRESULT CIDirectInputDevice8::GetForceFeedbackState(::IDirectInputDevice8* This, LPDWORD pdwOut)
{
  return This->lpVtbl->GetForceFeedbackState(This, pdwOut);
}

HRESULT CIDirectInputDevice8::SendForceFeedbackCommand(::IDirectInputDevice8* This, DWORD dwFlags)
{
  return This->lpVtbl->SendForceFeedbackCommand(This, dwFlags);
}

HRESULT CIDirectInputDevice8::EnumCreatedEffectObjects(::IDirectInputDevice8* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  return This->lpVtbl->EnumCreatedEffectObjects(This, lpCallback, pvRef, fl);
}

HRESULT CIDirectInputDevice8::Escape(::IDirectInputDevice8* This, LPDIEFFESCAPE pesc)
{
  return This->lpVtbl->Escape(This, pesc);
}

HRESULT CIDirectInputDevice8::Poll(::IDirectInputDevice8* This)
{
  return This->lpVtbl->Poll(This);
}

HRESULT CIDirectInputDevice8::SendDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  return This->lpVtbl->SendDeviceData(This, cbObjectData, rgdod, pdwInOut, fl);
}

HRESULT CIDirectInputDevice8::EnumEffectsInFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  return This->lpVtbl->EnumEffectsInFile(This, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT CIDirectInputDevice8::WriteEffectToFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  return This->lpVtbl->WriteEffectToFile(This, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

HRESULT CIDirectInputDevice8::BuildActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  return This->lpVtbl->BuildActionMap(This, lpdiaf, lpszUserName, dwFlags);
}

HRESULT CIDirectInputDevice8::SetActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  return This->lpVtbl->SetActionMap(This, lpdiaf, lpszUserName, dwFlags);
}

HRESULT CIDirectInputDevice8::GetImageInfo(::IDirectInputDevice8* This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader)
{
  return This->lpVtbl->GetImageInfo(This, lpdiDevImageInfoHeader);
}

CIDirectInputDevice8::~CIDirectInputDevice8() {}


/* BlockingCIDirectInputDevice8 */
HRESULT BlockingCIDirectInputDevice8::GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
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
HRESULT BoundBlockingCIDirectInputDevice8::GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  auto result = This->lpVtbl->GetDeviceData(This, cbObjectData, rgdod, pdwInOut, dwFlags);

  if (result == DI_OK && state_ == false)
  {
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

BoundBlockingCIDirectInputDevice8::BoundBlockingCIDirectInputDevice8(bool state, BoundBlockingCIDirectInputDevice8::on_destroy_t const & onDestroy)
  : state_(state), onDestroy_(onDestroy)
{}

BoundBlockingCIDirectInputDevice8::~BoundBlockingCIDirectInputDevice8()
{
  if (onDestroy_) onDestroy_();
}


/* WIDirectInput8 */
VIDirectInput8::VIDirectInput8() : QueryInterface(WIDirectInput8::QueryInterface), AddRef(WIDirectInput8::AddRef), Release(WIDirectInput8::Release), CreateDevice(WIDirectInput8::CreateDevice), EnumDevices(WIDirectInput8::EnumDevices), GetDeviceStatus(WIDirectInput8::GetDeviceStatus), RunControlPanel(WIDirectInput8::RunControlPanel), Initialize(WIDirectInput8::Initialize), FindDevice(WIDirectInput8::FindDevice), EnumDevicesBySemantics(WIDirectInput8::EnumDevicesBySemantics), ConfigureDevices(WIDirectInput8::ConfigureDevices)
{}

VIDirectInput8 const WIDirectInput8::vIDirectInput8;

WIDirectInput8::WIDirectInput8(::IDirectInput8* pNative, CIDirectInput8* pCallback)
  : pVtbl_(&vIDirectInput8), pNative_(pNative), pCallback_(pCallback)
{}

HRESULT WINAPI WIDirectInput8::QueryInterface(::IDirectInput8* This, REFIID riid, void** ppvObject)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->QueryInterface(That->pNative_, riid, ppvObject);
}

ULONG WINAPI WIDirectInput8::AddRef(::IDirectInput8* This)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->AddRef(That->pNative_);
}

ULONG WINAPI WIDirectInput8::Release(::IDirectInput8* This)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  auto refcount = That->pCallback_->Release(That->pNative_);
  if (refcount == 0)
  {
    log_debug("WIDirectInput8::Release(%p): deleting self", This);
    delete That;
  }
  return refcount;
}

HRESULT WINAPI WIDirectInput8::CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->CreateDevice(That->pNative_, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT WINAPI WIDirectInput8::EnumDevices(::IDirectInput8* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumDevices(That->pNative_, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInput8::GetDeviceStatus(::IDirectInput8* This, REFGUID rguidInstance)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetDeviceStatus(That->pNative_, rguidInstance);
}

HRESULT WINAPI WIDirectInput8::RunControlPanel(::IDirectInput8* This, HWND hwndOwner, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->RunControlPanel(That->pNative_, hwndOwner, dwFlags);
}

HRESULT WINAPI WIDirectInput8::Initialize(::IDirectInput8* This, HINSTANCE hinst, DWORD dwVersion)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Initialize(That->pNative_, hinst, dwVersion);
}

HRESULT WINAPI WIDirectInput8::FindDevice(::IDirectInput8* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->FindDevice(That->pNative_, rguid, pszName, pguidInstance);
}

HRESULT WINAPI WIDirectInput8::EnumDevicesBySemantics(::IDirectInput8* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumDevicesBySemantics(That->pNative_, ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInput8::ConfigureDevices(::IDirectInput8* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->ConfigureDevices(That->pNative_, lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}


HRESULT CIDirectInput8::QueryInterface(::IDirectInput8* This, REFIID riid, void** ppvObject)
{
  return This->lpVtbl->QueryInterface(This, riid, ppvObject);
}

ULONG CIDirectInput8::AddRef(::IDirectInput8* This)
{
  return This->lpVtbl->AddRef(This);
}

ULONG CIDirectInput8::Release(::IDirectInput8* This)
{
  auto refcount = This->lpVtbl->Release(This);
  if (refcount == 0)
  {
    log_debug("CIDirectInput8::Release(%p): deleting self", this);
    delete this;
  }
  return refcount;
}

HRESULT CIDirectInput8::CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  return This->lpVtbl->CreateDevice(This, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT CIDirectInput8::EnumDevices(::IDirectInput8* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  return This->lpVtbl->EnumDevices(This, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT CIDirectInput8::GetDeviceStatus(::IDirectInput8* This, REFGUID rguidInstance)
{
  return This->lpVtbl->GetDeviceStatus(This, rguidInstance);
}

HRESULT CIDirectInput8::RunControlPanel(::IDirectInput8* This, HWND hwndOwner, DWORD dwFlags)
{
  return This->lpVtbl->RunControlPanel(This, hwndOwner, dwFlags);
}

HRESULT CIDirectInput8::Initialize(::IDirectInput8* This, HINSTANCE hinst, DWORD dwVersion)
{
  return This->lpVtbl->Initialize(This, hinst, dwVersion);
}

HRESULT CIDirectInput8::FindDevice(::IDirectInput8* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  return This->lpVtbl->FindDevice(This, rguid, pszName, pguidInstance);
}

HRESULT CIDirectInput8::EnumDevicesBySemantics(::IDirectInput8* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  return This->lpVtbl->EnumDevicesBySemantics(This, ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT CIDirectInput8::ConfigureDevices(::IDirectInput8* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
  return This->lpVtbl->ConfigureDevices(This, lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}

CIDirectInput8::~CIDirectInput8() {}


/* WrappingCIDirectInput8 */
HRESULT WrappingCIDirectInput8::CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
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
HRESULT FactoryCIDirectInput8::CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  HRESULT result = CIDirectInput8::CreateDevice(This, rguid, lplpDirectInputDevice, pUnkOuter);
  if (result == S_OK)
  {
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


std::map<DeviceKind, std::function<std::unique_ptr<CIDirectInputDevice8>()> > g_deviceFactoies;

std::unique_ptr<CIDirectInputDevice8> g_make_device_callback(REFGUID rguid)
{
  auto const deviceKind = get_device_kind(rguid);
  auto const itFactory = g_deviceFactoies.find(deviceKind);
  auto upDevice =
    itFactory == g_deviceFactoies.end() ?
    std::unique_ptr<CIDirectInputDevice8>(new CIDirectInputDevice8) :
    itFactory->second();
  return upDevice;
}


/* config */
typedef std::map<std::string, std::map<std::string, std::string> > config_t;
config_t g_config;

void parse_config()
{
  log_debug("Parsing config");

  auto configFileName = "dinput8_blocker.ini";
  auto configFile = std::ifstream(configFileName);
  if (!configFile.is_open())
  {
    log_error("Can't open config: %s", configFileName);
    return;
  }
  else
  {
    log_info("Found config: %s", configFileName);
  }

  config_t config;
  std::string section ("");
  config[section] = config_t::mapped_type();

  std::string buf;
  char k[64] = {0};
  char v[64] = {0};
  int i = 0;

  while (std::getline(configFile, buf))
  {
    ++i;
    k[0] = v[0] = '\0';
    if (0 == buf.length())
    {
      log_debug("%d: Skipping empty line", i);
      continue;
    }
    else if ('#' == buf[0])
    {
      log_debug("%d: Parsed: buf:%s; skipping comment", i, buf.data());
      continue;
    }
    else if (1 == std::sscanf(buf.data(), "[%[^] \t\n\r]]", k))
    {
      log_debug("%d: Parsed: buf:%s; section:%s", i, buf.data(), k);
      section = k;
      config[section] = config_t::mapped_type();
    }
    else if (2 == std::sscanf(buf.data(), "%[^= \t\n\r]=%[^= \t\n\r]", k, v))
    {
      log_debug("%d: Parsed: buf:%s; k:%s; v:%s; adding to section:%s", i, buf.data(), k, v, section.data());
      config[section][k] = v;
    }
    else
    {
      log_error("%s:%d: Can't parse line:%s", configFileName, i, buf.data());
      continue;
    }
  }

  g_config = config;
  log_debug("Parsed config");
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

  g_deviceFactoies[DeviceKind::mouse] = []()
  {
    auto spCompositeFlag = std::make_shared<CompositeFlag>(std::logical_or<bool>());
    auto spCompositeTick = std::make_shared<CompositeTick>();
    auto pCompositeTick = spCompositeTick.get();

    auto onDestroy = [pCompositeTick]()
    {
      Loop::lock_t l (g_pLoop->get_mutex());
      g_pLoop->remove_tick(pCompositeTick);
    };

    std::unique_ptr<BoundBlockingCIDirectInputDevice8> upDevice (new BoundBlockingCIDirectInputDevice8 (true, onDestroy));

    {
      /* TODO Error checking.*/
      auto & keyName = g_config["mouse"]["toggleKey"];
      auto key = name2key(keyName.c_str());
      auto spFlag = std::make_shared<ConstantFlag>(true);
      auto spKeyTick = std::make_shared<KeyListenerTick>(key);
      spKeyTick->add(KeyEventType::pressed, [spFlag](){ spFlag->set(!spFlag->get()); });
      spCompositeFlag->add(spFlag);
      spCompositeTick->add(spKeyTick);
    }
    {
      /* TODO Error checking.*/
      auto & keyName = g_config["mouse"]["unblockKey"];
      auto key = name2key(keyName.c_str());
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


/* Imports */
struct Imports
{
  struct Dinput8
  {
    decltype(::DirectInput8Create) * DirectInput8Create;
    decltype(::DllCanUnloadNow) * DllCanUnloadNow;
    decltype(::DllGetClassObject) * DllGetClassObject;
    decltype(::DllRegisterServer) * DllRegisterServer;
    decltype(::DllUnregisterServer) * DllUnregisterServer;
  } dinput8;

  void fill();
} g_imports;


void Imports::fill()
{
  log_debug("Filling imports");
  char szPath[MAX_PATH];

  if (!GetSystemDirectory(szPath, sizeof(szPath)))
    throw std::runtime_error("Failed to get system directory path");

  strcat(szPath, "\\dinput8.dll");
  HMODULE hNativeDinput8Dll = LoadLibrary(szPath);

  if (!hNativeDinput8Dll)
    throw std::runtime_error("Failed to get native dinput8.dll handle");

  dinput8.DirectInput8Create = reinterpret_cast<decltype(::DirectInput8Create) *>(GetProcAddress(hNativeDinput8Dll,"DirectInput8Create"));
  dinput8.DllCanUnloadNow = reinterpret_cast<decltype(::DllCanUnloadNow) *>(GetProcAddress(hNativeDinput8Dll,"DllCanUnloadNow"));
  dinput8.DllGetClassObject = reinterpret_cast<decltype(::DllGetClassObject) *>(GetProcAddress(hNativeDinput8Dll,"DllGetClassObject"));
  dinput8.DllRegisterServer = reinterpret_cast<decltype(::DllRegisterServer) *>(GetProcAddress(hNativeDinput8Dll,"DllRegisterServer"));
  dinput8.DllUnregisterServer = reinterpret_cast<decltype(::DllUnregisterServer) *>(GetProcAddress(hNativeDinput8Dll,"DllUnregisterServer"));

  log_debug("Filled imports");
  return;
}

} // namespace di8b


BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason,LPVOID v)
try {
  if (reason == DLL_PROCESS_ATTACH)
  {
    di8b::log_info("Dll attached");
    di8b::parse_config();
    di8b::g_imports.fill();
    di8b::start_loop();
  }

  if (reason == DLL_PROCESS_DETACH)
  {
    di8b::log_info("Dll detached");
    di8b::g_pLoop->exit();
  }

  return TRUE;
} catch (std::exception const & e)
{
  di8b::log_error(e.what());
  return FALSE;
}

extern "C" {

DLLEXPORT HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter)
{
  di8b::log_debug("DirectInput8Create");
  HRESULT result = di8b::g_imports.dinput8.DirectInput8Create(hinst, dwVersion, riidltf, ppvOut, punkOuter);
  if (result == S_OK)
  {
    auto upCallback = std::unique_ptr<di8b::FactoryCIDirectInput8>(new di8b::FactoryCIDirectInput8(di8b::g_make_device_callback));
    auto pIDirectInput8 = reinterpret_cast<IDirectInput8*>(*ppvOut);
    auto upWrapper = std::unique_ptr<di8b::WIDirectInput8>(new di8b::WIDirectInput8(pIDirectInput8, upCallback.get()));
    *ppvOut = upWrapper.release();
    upCallback.release();
  }
  return result;
}

DLLEXPORT HRESULT WINAPI DllCanUnloadNow()
{
  di8b::log_debug("DllCanUnloadNow");
  return di8b::g_imports.dinput8.DllCanUnloadNow();
}

DLLEXPORT HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
  di8b::log_debug("DllGetClassObject");
  return di8b::g_imports.dinput8.DllGetClassObject(rclsid, riid, ppv);
}

DLLEXPORT HRESULT WINAPI DllRegisterServer()
{
  di8b::log_debug("DllRegisterServer");
  return di8b::g_imports.dinput8.DllRegisterServer();
}

DLLEXPORT HRESULT WINAPI DllUnregisterServer()
{
  di8b::log_debug("DllUnregisterServer");
  return di8b::g_imports.dinput8.DllUnregisterServer();
}

} // extern "C"
