#include <di8b.hpp>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <mingw.thread.h>
#include <mingw.mutex.h>
#include <cstdio>
#include <cstdlib>
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


/* globals */
config_t g_config;
class KeysTick;
std::shared_ptr<KeysTick> g_spKeysTick;

/* Tick */
class Tick
{
public:
  virtual void tick() =0;

  virtual ~Tick() =default;
};


enum class KeyEventType : int { pressed=0, released=1 };


class Binding
{
public:
  Binding()
  {
    log_debug("Binding::Binding(%p)", this);
  }

  virtual ~Binding()
  {
    log_debug("Binding::~Binding(%p)", this);
  }
};


class BindingHolder
{
public:
  void add_binding(std::shared_ptr<Binding> const & spBinding)
  {
    bindings_.push_back(spBinding);
  }

  BindingHolder() : bindings_()
  {
    log_debug("BindingHolder::BindingHolder(%p)", this);
  }
  
  ~BindingHolder()
  {
    log_debug("BindingHolder::~BindingHolder(%p)", this);
  }

private:
  std::vector<std::shared_ptr<Binding> > bindings_;
};


class KeysTick : public Tick
{
public:
  typedef UINT key_t;
  typedef std::function<void()> callback_t;
  typedef unsigned int handle_t;
  class KTBinding : public Binding
  {
  public:
    KTBinding(KeysTick * pKeysTick,key_t key, KeyEventType ket, handle_t handle)
      : pKeysTick_(pKeysTick), key_(key), ket_(ket), handle_(handle)
    {}
    ~KTBinding()
    {
      pKeysTick_->remove(this);
    }
  private:
    friend class KeysTick;
    KeysTick * pKeysTick_;
    key_t key_;
    KeyEventType ket_;
    handle_t handle_;
  };

  virtual void tick()
  {
    lock_t lock (mutex_);

    for (auto & p : data_)
    {
      auto const & key = p.first;
      bool currentState = GetKeyState(key) & 0x8000;
      auto & prevState = p.second.state;
      if (currentState != prevState)
      {
        auto const ket = (currentState && !prevState) ? KeyEventType::pressed : KeyEventType::released;
        for (auto & cb : p.second.callbacks[static_cast<int>(ket)])
          cb.second();
        prevState = currentState;
      }
    }
  }

  std::shared_ptr<KTBinding> add(key_t key, KeyEventType ket, callback_t const & cb)
  {
    lock_t lock (mutex_);

    auto handle = ++handle_;
    auto it = data_.find(key);
    if (it == data_.end())
      data_[key] = Data();
    data_[key].callbacks[static_cast<int>(ket)][handle] = cb;
    ++handle_;
    auto spBinding = std::make_shared<KTBinding>(this, key, ket, handle);
    return spBinding;
  }

  bool remove(KTBinding* pBinding)
  {
    lock_t lock (mutex_);

    auto it = data_.find(pBinding->key_);
    if (it == data_.end())
      return false;
    auto & callbacks = it->second.callbacks;
    auto it2 = it->second.callbacks.find(static_cast<int>(pBinding->ket_));
    if (it2 == callbacks.end())
      return false;
    auto & t = it2->second;
    auto it3 = t.find(pBinding->handle_);
    if (it3 == t.end())
      return false;
    t.erase(it3);
    return true;
  }

  KeysTick() : data_()
  {
    log_debug("KeysTick::KeysTick(%p)", this);
  }

  ~KeysTick()
  {
    log_debug("KeysTick::~KeysTick(%p)", this);
  }

private:
  typedef std::recursive_mutex mutex_t;
  typedef std::unique_lock<mutex_t> lock_t;

  struct Data
  {
    typedef std::map<int, std::map<unsigned int, callback_t> > callbacks_t;

    callbacks_t callbacks;
    bool state;

    Data() : callbacks(), state(false)
    {
      KeyEventType kets[] = { KeyEventType::pressed, KeyEventType::released };
      for (auto ket : kets)
        callbacks[static_cast<int>(ket)] = std::map<unsigned int, callback_t>();
    }
  };

  std::map<key_t, Data> data_;
  unsigned int handle_ = 0;
  mutex_t mutex_;
};


/* Flag */
class Flag
{
public:
  virtual bool get() const =0;
  virtual void on_change(Flag* pFlag, bool o, bool n) =0;

  virtual void set_parent(Flag* pParent) { pParent_ = pParent; }
  virtual Flag* get_parent() const { return pParent_; }

  Flag(Flag* pParent = nullptr) : pParent_(pParent) {}
  virtual ~Flag() =default;

private:
  Flag* pParent_;
};


class CompositeFlag : public Flag
{
public:
  virtual bool get() const
  {
    return v_;
  }

  virtual void on_change(Flag* pFlag, bool o, bool n)
  {
    auto old = v_;
    update_();
    if (v_ == old)
      return;
    if (get_parent())
      get_parent()->on_change(this, old, v_);
  }

  void add(std::shared_ptr<Flag> const & spFlag)
  {
    if (!spFlag) throw std::runtime_error("Flag pointer is NULL");
    flags_.push_back(spFlag);
    spFlag->set_parent(this);
    update_();
  }

  CompositeFlag(std::function<bool(bool,bool)> const & combine, Flag* pParent = nullptr)
    : Flag(pParent), flags_(), combine_(combine), v_(false)
  {}

  CompositeFlag(std::vector<std::shared_ptr<Flag> > const & flags, std::function<bool(bool,bool)> const & combine, Flag* pParent = nullptr)
    : Flag(pParent), flags_(flags), combine_(combine), v_(false)
  {
    for (auto const & spFlag : flags)
      if (!spFlag) throw std::runtime_error("Flag pointer is NULL");
    update_();
  }

private:
  virtual void update_()
  {
    auto first = true;
    auto result = false;
    for (auto const & spFlag : flags_)
      result = first ? first = false, spFlag->get() : combine_(result, spFlag->get());
    log_debug("CompositeFlag::get(%p): result: %d", this, result);
    v_ = result;
  }

  std::vector<std::shared_ptr<Flag> > flags_;
  std::function<bool(bool,bool)> combine_;
  bool v_;
};


class CallbackFlag : public Flag
{
public:
  typedef std::function<void(bool,bool)> callback_t;

  virtual bool get() const
  {
    return spNext_ ? spNext_->get() : false;
  }

  virtual void on_change(Flag* pFlag, bool o, bool n)
  {
    if (pFlag != spNext_.get())
      throw std::runtime_error("Flags mismatch.");
    if (cb_)
      cb_(o, n);
  }

  void set_callback(callback_t const & cb)
  {
    cb_ = cb;
  }

  CallbackFlag(callback_t const & cb, std::shared_ptr<Flag> const & spNext)
    : cb_(cb), spNext_(spNext)
  {
    log_debug("CallbackFlag::CallbackFlag(%p)", this); 
    spNext->set_parent(this);
  }

  CallbackFlag(std::shared_ptr<Flag> const & spNext)
    : cb_(), spNext_(spNext)
  {
    log_debug("CallbackFlag::CallbackFlag(%p)", this); 
    spNext->set_parent(this);
  }

  ~CallbackFlag()
  {
    log_debug("CallbackFlag::~CallbackFlag(%p)", this); 
  }

private:
  callback_t cb_;
  std::shared_ptr<Flag> spNext_;
};


class ConstantFlag : public Flag
{
public:
  virtual bool get() const { return v_; }

  void set(bool b)
  {
    if (v_ == b)
      return;
    auto o = v_;
    v_ = b;
    if (get_parent())
      get_parent()->on_change(this, o, b);
  }

  virtual void on_change(Flag* pFlag, bool o, bool n)
  {
    throw std::runtime_error("ConstantFlag::on_change() should not be called.");
  }

  ConstantFlag(bool v, Flag* pParent = nullptr) : Flag(pParent), v_(v) {}

private:
  bool v_;
};


class BoundConstantFlag : public ConstantFlag, public BindingHolder
{
public:
  BoundConstantFlag(bool v, Flag* pParent = nullptr)
    : ConstantFlag(v, pParent)
  {
    log_debug("BoundConstantFlag::BoundConstantFlag(%p)", this);
  }
  
  ~BoundConstantFlag()
  {
    log_debug("BoundConstantFlag::~BoundConstantFlag(%p)", this);
  }
};


/* Template-based implementations. */
template <class B>
class BlockingWIDirectInputDevice : public B
{
public:
  typedef BlockingWIDirectInputDevice<B> this_type;
  typedef B base_type;

  static HRESULT WINAPI GetDeviceState(this_type* This, DWORD cbData, LPVOID lpvData)
  {
    log_debug("BlockingWIDirectInputDevice::GetDeviceState(%p)", This);
    auto hr = base_type::GetDeviceState(This, cbData, lpvData);
    auto flag = This->spFlag_->get();
    if ((hr == DI_OK) && !flag)
    {
      /* TODO Account for relative and absolute devices: zero-out for relative and return saved date for absolute. */
      log_debug("BlockingWIDirectInputDevice::GetDeviceState(%p): erasing state", This);
      std::memset(lpvData, 0, cbData);
    }
    return hr;
  }

  static HRESULT WINAPI GetDeviceData(this_type* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
  {
    log_debug("BlockingWIDirectInputDevice::GetDeviceData(%p)", This);
    auto hr = base_type::GetDeviceData(This, cbObjectData, rgdod, pdwInOut, dwFlags);
    auto flag = This->spFlag_->get();
    if ((hr == DI_OK) && !flag)
    {
      log_debug("BlockingWIDirectInputDevice::GetDeviceData(%p): erasing data", This);
      *pdwInOut = 0;
    }
    return hr;
  }

  template <class T>
  BlockingWIDirectInputDevice(T const & t)
    : base_type(t), spFlag_(t.spFlag)
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

typedef WIDirectInputDevice8A<BlockingWIDirectInputDevice<BIDirectInputDevice8A> > BlockingWIDirectInputDevice8A;
typedef WIDirectInputDevice8W<BlockingWIDirectInputDevice<BIDirectInputDevice8W> > BlockingWIDirectInputDevice8W;


template <class B>
class OnDestroyCallbackHolder : public B
{
public:
  typedef std::function<void()> on_destroy_callback_type;

  void add_on_destroy_callback(on_destroy_callback_type const & cb)
  {
    onDestroyCallbacks_.push_back(cb);
  }

  template <class T>
  OnDestroyCallbackHolder(T const & t)
    : B(t)
  {
    log_debug("OnDestroyCallbackHolder::OnDestroyCallbackHolder(%p)", this);
  }

  ~OnDestroyCallbackHolder()
  {
    log_debug("OnDestroyCallbackHolder::~OnDestroyCallbackHolder(%p)", this);
    for (auto const & cb : onDestroyCallbacks_)
      cb();
  }

private:
  std::vector<on_destroy_callback_type> onDestroyCallbacks_;
};


template <class B>
class StateBlockingWIDirectInputDevice : public B
{
public:
  typedef StateBlockingWIDirectInputDevice<B> this_type;
  typedef B base_type;

  static HRESULT WINAPI GetDeviceState(this_type* This, DWORD cbData, LPVOID lpvData)
  {
    log_debug("StateBlockingWIDirectInputDevice::GetDeviceState(%p)", This);
    auto hr = base_type::GetDeviceState(This, cbData, lpvData);
    if ((hr == DI_OK) && !This->state_)
    {
      /* TODO Account for relative and absolute devices: zero-out for relative and return saved date for absolute. */
      log_debug("StateBlockingWIDirectInputDevice::GetDeviceState(%p): erasing state", This);
      std::memset(lpvData, 0, cbData);
    }
    return hr;
  }

  static HRESULT WINAPI GetDeviceData(this_type* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
  {
    log_debug("StateBlockingWIDirectInputDevice::GetDeviceData(%p)", This);
    auto hr = base_type::GetDeviceData(This, cbObjectData, rgdod, pdwInOut, dwFlags);
    if ((hr == DI_OK) && !This->state_)
    {
      log_debug("StateBlockingWIDirectInputDevice::GetDeviceData(%p): erasing data", This);
      *pdwInOut = 0;
    }
    return hr;
  }

  void set_state(bool state)
  {
    state_ = state;
  }

  template <class T>
  StateBlockingWIDirectInputDevice(T const & t)
    : base_type(t), state_(true)
  {
    log_debug("StateBlockingWIDirectInputDevice::StateBlockingWIDirectInputDevice(%p)", this);
  }

  ~StateBlockingWIDirectInputDevice()
  {
    log_debug("StateBlockingWIDirectInputDevice::~StateBlockingWIDirectInputDevice(%p)", this);
  }

private:
  bool state_;
};

typedef WIDirectInputDevice8A<OnDestroyCallbackHolder<StateBlockingWIDirectInputDevice<BIDirectInputDevice8A> > > StateBlockingWIDirectInputDevice8A;
typedef WIDirectInputDevice8W<OnDestroyCallbackHolder<StateBlockingWIDirectInputDevice<BIDirectInputDevice8W> > > StateBlockingWIDirectInputDevice8W;


/** Makes device using external factory method */
template <class B, class IDI, class IDID>
class FactoryWIDirectInput : public B
{
public:
  typedef FactoryWIDirectInput<B, IDI, IDID> this_type;
  typedef B base_type;
  typedef std::function<IDID* (REFGUID, IDID*)> device_factory_t;
  typedef std::function<void (LPVOID, int)> reporter_t;

  static HRESULT WINAPI CreateDevice(this_type* This, REFGUID rguid, IDID** lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
  {
    log_debug("FactoryWIDirectInput::CreateDevice(%p)", This);
    IDID* pNative = nullptr;
    auto hr = base_type::CreateDevice(This, rguid, &pNative, pUnkOuter);
    if (hr == S_OK)
    {
      log_debug("FactoryWIDirectInput::CreateDevice(%p): created native device: %p", This, pNative);
      if (This->reporter_)
        This->reporter_(pNative, 0);
      if (This->deviceFactory_)
        try {
          release_unique_ptr<IDID> upNative (pNative);
          auto pDevice = This->deviceFactory_(rguid, pNative);
          if (pDevice)
          {
            log_debug("FactoryWIDirectInput::CreateDevice(%p): created wrapper device: %p", This, pDevice);
            if (This->reporter_)
              This->reporter_(pNative, 1);
            *lplpDirectInputDevice = pDevice;
          }
          else
          {
            log_debug("FactoryWIDirectInput::CreateDevice(%p): did not create wrapper for native device: %p", This, pNative);
            if (This->reporter_)
              This->reporter_(pNative, 2);
            *lplpDirectInputDevice = pNative;
          }
          upNative.release();
        } catch (...) {
          log_error("FactoryWIDirectInput::CreateDevice(%p): exception, releasing native device %p", This, pNative);
        }
      else
        *lplpDirectInputDevice = pNative;
    }
    return hr;
  }

  static HRESULT WINAPI CreateDeviceEx(this_type* This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter)
  {
    log_debug("FactoryWIDirectInput::CreateDeviceEx(%p, %s, %s, %p, %p)", This, guid2str(rguid).data(), guid2str(riid).data(), pvOut, lpUnknownOuter);
    IDID* pNative = nullptr;
    auto hr = base_type::CreateDeviceEx(This, rguid, riid, reinterpret_cast<LPVOID*>(&pNative), lpUnknownOuter);
    if (hr == S_OK)
    {
      log_debug("FactoryWIDirectInput::CreateDeviceEx(%p): created native device: %p", This, pNative);
      if (This->reporter_)
        This->reporter_(pNative, 0);
      if (This->deviceFactory_)
        try {
          release_unique_ptr<IDID> upNative (pNative);
          auto pDevice = This->deviceFactory_(rguid, pNative);
          if (pDevice)
          {
            log_debug("FactoryWIDirectInput::CreateDeviceEx(%p): created wrapper device: %p", This, pDevice);
            if (This->reporter_)
              This->reporter_(pNative, 1);
            *pvOut = pDevice;
          }
          else
          {
            log_debug("FactoryWIDirectInput::CreateDeviceEx(%p): did not create wrapper for native device: %p", This, pNative);
            if (This->reporter_)
              This->reporter_(pNative, 2);
            *pvOut = pNative;
          }
          upNative.release();
        } catch (...) {
          log_error("FactoryWIDirectInput::CreateDeviceEx(%p): exception, releasing native device %p", This, pNative);
        }
      else
        *pvOut = pNative;
    }
    return hr; 
  }

  template <class T>
  FactoryWIDirectInput(T const & t)
    : base_type(t), deviceFactory_(t.deviceFactory), reporter_(t.reporter)
  {}

private:
  device_factory_t deviceFactory_;
  reporter_t reporter_;
};

void print_ididxa_info(LPVOID lpDevice, int msg)
{
  DIDEVICEINSTANCEA ddi;
  std::memset(&ddi, 0, sizeof(ddi));
  ddi.dwSize = sizeof(ddi);
  auto pDevice = reinterpret_cast<LPDIRECTINPUTDEVICEA>(lpDevice);
  HRESULT ddiResult = pDevice->lpVtbl->GetDeviceInfo(pDevice, &ddi);
  if (ddiResult == S_OK)
  {
    switch (msg)
    {
      case 0:
      {
        static char const * fmt = "Created device: instance GUID: %s; product GUID: %s; instance name: %s; product name: %s; type: 0x%x; usage page: 0x%x; usage: 0x%x";
        log_info(fmt, guid2str(ddi.guidInstance).data(), guid2str(ddi.guidProduct).data(), ddi.tszInstanceName, ddi.tszProductName, ddi.wUsagePage, ddi.wUsage);
        break;
      }
      case 1:
      {
        static char const * fmt = "Created wrapper for device: instance GUID: %s; instance name: %s";
        log_info(fmt, guid2str(ddi.guidInstance).data(), ddi.tszInstanceName);
        break;
      }
      case 2:
      {
        static char const * fmt = "Did not create wrapper for device: instance GUID: %s; instance name: %s";
        log_info(fmt, guid2str(ddi.guidInstance).data(), ddi.tszInstanceName);
        break;
      }
    }
  }
  else
    log_error("Failed to get device info");
}

void print_ididxw_info(LPVOID lpDevice, int msg)
{
  DIDEVICEINSTANCEW ddi;
  std::memset(&ddi, 0, sizeof(ddi));
  ddi.dwSize = sizeof(ddi);
  auto pDevice = reinterpret_cast<LPDIRECTINPUTDEVICEW>(lpDevice);
  HRESULT ddiResult = pDevice->lpVtbl->GetDeviceInfo(pDevice, &ddi);
  if (ddiResult == S_OK)
  {
    switch (msg)
    {
      case 0:
      {
        static char const * fmt = "Created device: instance GUID: %s; product GUID: %s; instance name: %ls; product name: %ls; type: 0x%x; usage page: 0x%x; usage: 0x%x";
        log_info(fmt, guid2str(ddi.guidInstance).data(), guid2str(ddi.guidProduct).data(), ddi.tszInstanceName, ddi.tszProductName, ddi.wUsagePage, ddi.wUsage);
        break;
      }
      case 1:
      {
        static char const * fmt = "Created wrapper for device: instance GUID: %s; instance name: %ls";
        log_info(fmt, guid2str(ddi.guidInstance).data(), ddi.tszInstanceName);
        break;
      }
      case 2:
      {
        static char const * fmt = "Could not create wrapper for device: instance GUID: %s; instance name: %ls";
        log_info(fmt, guid2str(ddi.guidInstance).data(), ddi.tszInstanceName);
        break;
      }
    }
  }
  else
    log_error("Failed to get device info");
}

template <class DeviceWrapper, class IDID>
IDID* make_state_device_wrapper(REFGUID rguid, IDID* pDID)
{
  log_debug("make_state_device_wrapper(%s, %p)", guid2str(rguid).data(), pDID);
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

  auto const & keys = itSection->second;
  auto itToggleKey = keys.find("toggleKey");
  auto itUnblockKey = keys.find("unblockKey");
  if ((itToggleKey == keys.end()) && (itUnblockKey == keys.end()))
    return nullptr;

  auto spFlag = std::make_shared<CompositeFlag>(std::logical_or<bool>());
  if (itToggleKey != keys.end())
  {
    auto toggleKey = name2key(itToggleKey->second.data());
    auto initialState = mget_or<bool>(keys, "initialState", true);
    auto spToggleFlag = std::make_shared<BoundConstantFlag>(initialState);
    auto pToggleFlag = spToggleFlag.get();
    auto spBinding = g_spKeysTick->add(toggleKey, KeyEventType::released, [pToggleFlag]() { pToggleFlag->set(!pToggleFlag->get()); });
    spToggleFlag->add_binding(spBinding);
    spFlag->add(spToggleFlag);
  }
  if (itUnblockKey != keys.end())
  {
    auto unblockKey = name2key(itUnblockKey->second.data());
    auto spUnblockFlag = std::make_shared<BoundConstantFlag>(false);
    auto pUnblockFlag = spUnblockFlag.get();
    auto spBinding = g_spKeysTick->add(unblockKey, KeyEventType::pressed, [pUnblockFlag]() { pUnblockFlag->set(true); });
    spUnblockFlag->add_binding(spBinding);
    spBinding = g_spKeysTick->add(unblockKey, KeyEventType::released, [pUnblockFlag]() { pUnblockFlag->set(false); });
    spUnblockFlag->add_binding(spBinding);
    spFlag->add(spUnblockFlag);
  }
  if (!spFlag)
    return nullptr;
  std::shared_ptr<CallbackFlag> spCBLFlag = std::make_shared<CallbackFlag>(spFlag);
  struct T
  {
    LPVOID pNative;
  } t = { pDID };
  auto upWrapper = std::unique_ptr<DeviceWrapper>(new DeviceWrapper(t));
  auto pWrapper = upWrapper.get();
  spCBLFlag->set_callback([pWrapper](bool o, bool n) { pWrapper->set_state(n); });
  pWrapper->add_on_destroy_callback([spCBLFlag]() { const_cast<std::shared_ptr<CallbackFlag>&>(spCBLFlag).reset(); });
  log_debug("make_state_device_wrapper(%s, %p): created wrapper: %p", guid2str(rguid).data(), pDID, pWrapper);
  return reinterpret_cast<IDID*>(upWrapper.release());
}


LPVOID make_dinputxx_wrapper(REFIID riidltf, LPVOID lpNative)
{
  LPVOID pWrapper = nullptr;

  GUID guidsa[] = { IID_IDirectInputA, IID_IDirectInput2A, IID_IDirectInput7A };
  for (auto const & guid : guidsa)
  {
    if (IsEqualGUID(riidltf, guid))
    {
      typedef WIDirectInput7A<
        FactoryWIDirectInput<BIDirectInput7A, IDirectInput7A, IDirectInputDeviceA>
      > dinput_wrapper_t;
      struct T
      {
        LPVOID pNative;
        dinput_wrapper_t::device_factory_t deviceFactory;
        dinput_wrapper_t::reporter_t reporter;
      } t = { lpNative, make_state_device_wrapper<StateBlockingWIDirectInputDevice8A, IDirectInputDeviceA>, print_ididxa_info };
      pWrapper = new dinput_wrapper_t(t);
    }
  }

  if (pWrapper == nullptr && IsEqualGUID(riidltf, IID_IDirectInput8A))
  {
    typedef WIDirectInput8A<
      FactoryWIDirectInput<BIDirectInput8A, IDirectInput8A, IDirectInputDevice8A>
    > dinput_wrapper_t;
    struct T
    {
      LPVOID pNative;
      dinput_wrapper_t::device_factory_t deviceFactory;
      dinput_wrapper_t::reporter_t reporter;
    } t = { lpNative, make_state_device_wrapper<StateBlockingWIDirectInputDevice8A, IDirectInputDevice8A>, print_ididxa_info };
    pWrapper = new dinput_wrapper_t(t);
  }

  GUID guidsw[] = { IID_IDirectInputW, IID_IDirectInput2W, IID_IDirectInput7W };
  for (auto const & guid : guidsw)
  {
    if (IsEqualGUID(riidltf, guid))
    {
      typedef WIDirectInput7W<
        FactoryWIDirectInput<BIDirectInput7W, IDirectInput7W, IDirectInputDeviceW>
      > dinput_wrapper_t;
      struct T
      {
        LPVOID pNative;
        dinput_wrapper_t::device_factory_t deviceFactory;
        dinput_wrapper_t::reporter_t reporter;
      } t = { lpNative, make_state_device_wrapper<StateBlockingWIDirectInputDevice8W, IDirectInputDeviceW>, print_ididxw_info };
      pWrapper = new dinput_wrapper_t(t);
   }
  }

  if (pWrapper == nullptr && IsEqualGUID(riidltf, IID_IDirectInput8W))
  {
    typedef WIDirectInput8W<
      FactoryWIDirectInput<BIDirectInput8W, IDirectInput8W, IDirectInputDevice8W>
    > dinput_wrapper_t;
    struct T
    {
      LPVOID pNative;
      dinput_wrapper_t::device_factory_t deviceFactory;
      dinput_wrapper_t::reporter_t reporter;
    } t = { lpNative, make_state_device_wrapper<StateBlockingWIDirectInputDevice8W, IDirectInputDevice8W>, print_ididxw_info };
    pWrapper = new dinput_wrapper_t(t);
  }

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
    << "#Log level (available levels: NOTSET, TRACE, DEBUG, INFO, WARNING, ERROR).\n"
    << "#logLevel=level\n"
    << "#Path to next dll. If not specified, will try to load dll from system directory.\n"
    << "#next=pathToNextDll\n"
    << "#Section with key bindings for a device is an instance guid (i.e. 6F1D2B60-D5A0-11CF-BFC7-444553540000). Instance guids of created devices are included in device info written to log as INFO-level messages\n"
    << "#[device instance guid]\n"
    << "#Key to toggle device blocking.\n"
    << "#toggleKey=keyName\n"
    << "#Key to press to unblock a blocked device.\n"
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

  char const * configFileName = std::getenv("DINPUT8_BLOCKER_CONFIG");
  if (configFileName == nullptr)
    configFileName = "dinput8_blocker.ini";
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
    log_debug("Loop::operator()(%p): exiting", this);
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
    lock_t l (mutex_);
    log_debug("Loop::exit(%p): exiting", this);
    exiting_ = true;
  }

  mutex_t & get_mutex()
  {
    return mutex_;
  }

  Loop(unsigned int sleepTime)
    : ticks_(), sleepTime_(sleepTime)
  {
    log_debug("Loop::Loop(%p)", this);
  }

  ~Loop()
  {
    log_debug("Loop::~Loop(%p)", this);
  }
private:
  void cleanup()
  {
    ticks_.erase(std::remove(ticks_.begin(), ticks_.end(), nullptr), ticks_.end());
  }

  std::vector<std::shared_ptr<Tick> > ticks_;
  volatile bool exiting_ = false;
  volatile bool dirty_ = false;
  unsigned int sleepTime_;

  mutex_t mutex_;
};


Loop * g_pLoop;

void start_loop()
{
  g_pLoop = new Loop (100);
  g_spKeysTick = std::make_shared<KeysTick>();
  g_pLoop->add_tick(g_spKeysTick);

  std::thread t (&Loop::operator(), g_pLoop);
  t.detach();
}

void stop_loop()
{
  g_pLoop->exit();
  delete g_pLoop;
  g_spKeysTick = nullptr;
}

HMODULE get_next_handle(LPCSTR dllName)
{
  auto const & mainSection = g_config[""];
  auto const itNext = mainSection.find("next");

  char path[MAX_PATH];
  if (itNext != mainSection.end())
    strcpy(path, itNext->second.data());
  else
  {
    if (!GetSystemDirectory(path, sizeof(path)))
      throw std::runtime_error("Failed to get system directory path");
    strcat(path, "\\");
    strcat(path, dllName);
  }

  log_info("Loading next %s from %s", dllName, path);
  HMODULE hNext = LoadLibrary(path);
  if (!hNext)
  {
    char msg[MAX_PATH+100];
    snprintf(msg, sizeof(msg), "Failed to load next %s from %s", dllName, path);
    throw std::runtime_error(msg);
  }

  return hNext;
}

} // namespace di8b 
