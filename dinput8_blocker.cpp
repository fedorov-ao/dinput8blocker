#include <dinput8_blocker.hpp>
#include <ctime>
#include <iomanip>
#include <mingw.thread.h>
#include <chrono>

#define DLLEXPORT __declspec(dllexport)

namespace di8b
{

struct print_time
{
  char const * fmt_;
  print_time(char const * fmt) : fmt_(fmt) {}
};

std::ostream & operator<< (std::ostream & os, print_time const & pt)
{
  auto tNow = std::time(nullptr);
  auto tmNow = std::localtime(&tNow);
  return os << std::put_time(tmNow, pt.fmt_);
}

std::ostream & logger()
{
  static std::ofstream of ("dinput8_blocker.log");
  static struct Reporter
  {
    char const * fmt = "%d.%m.%Y %H:%M:%S";
    Reporter() { of << "Logging started at " << print_time(fmt) << std::endl; }
    ~Reporter() { of << "Logging ended at " << print_time(fmt) << std::endl; }
  } reporter;
  auto tNow = std::time(nullptr);
  auto tmNow = std::localtime(&tNow);
  return of << print_time("%H:%M:%S: ");
}

void log_debug(char const * msg)
{
  logger() << "[DEBUG] " << msg << std::endl;
}

void log_info(char const * msg)
{
  logger() << "[INFO] " << msg << std::endl;
}

void log_error(char const * msg)
{
  logger() << "[ERROR] " << msg << std::endl;
}


bool g_state = false;
bool g_exiting = false;


VIDirectInputDevice8::VIDirectInputDevice8() : QueryInterface(WIDirectInputDevice8::QueryInterface), AddRef(WIDirectInputDevice8::AddRef), Release(WIDirectInputDevice8::Release), GetCapabilities(WIDirectInputDevice8::GetCapabilities), EnumObjects(WIDirectInputDevice8::EnumObjects), GetProperty(WIDirectInputDevice8::GetProperty), SetProperty(WIDirectInputDevice8::SetProperty), Acquire(WIDirectInputDevice8::Acquire), Unacquire(WIDirectInputDevice8::Unacquire), GetDeviceState(WIDirectInputDevice8::GetDeviceState), GetDeviceData(WIDirectInputDevice8::GetDeviceData), SetDataFormat(WIDirectInputDevice8::SetDataFormat), SetEventNotification(WIDirectInputDevice8::SetEventNotification), SetCooperativeLevel(WIDirectInputDevice8::SetCooperativeLevel), GetObjectInfo(WIDirectInputDevice8::GetObjectInfo), GetDeviceInfo(WIDirectInputDevice8::GetDeviceInfo), RunControlPanel(WIDirectInputDevice8::RunControlPanel), Initialize(WIDirectInputDevice8::Initialize), CreateEffect(WIDirectInputDevice8::CreateEffect), EnumEffects(WIDirectInputDevice8::EnumEffects), GetEffectInfo(WIDirectInputDevice8::GetEffectInfo), GetForceFeedbackState(WIDirectInputDevice8::GetForceFeedbackState), SendForceFeedbackCommand(WIDirectInputDevice8::SendForceFeedbackCommand), EnumCreatedEffectObjects(WIDirectInputDevice8::EnumCreatedEffectObjects), Escape(WIDirectInputDevice8::Escape), Poll(WIDirectInputDevice8::Poll), SendDeviceData(WIDirectInputDevice8::SendDeviceData), EnumEffectsInFile(WIDirectInputDevice8::EnumEffectsInFile), WriteEffectToFile(WIDirectInputDevice8::WriteEffectToFile), BuildActionMap(WIDirectInputDevice8::BuildActionMap), SetActionMap(WIDirectInputDevice8::SetActionMap), GetImageInfo(WIDirectInputDevice8::GetImageInfo)
{}

VIDirectInputDevice8 const WIDirectInputDevice8::vIDirectInputDevice8;

WIDirectInputDevice8::WIDirectInputDevice8(::IDirectInputDevice8* pimpl_, DeviceKind deviceKind_) : pvtbl(&vIDirectInputDevice8), pimpl(pimpl_), deviceKind(deviceKind_)
{
  log_debug("WIDirectInputDevice8::WIDirectInputDevice8()");
}

HRESULT WINAPI WIDirectInputDevice8::QueryInterface(::IDirectInputDevice8* This, REFIID riid, void** ppvObject)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->QueryInterface(That->pimpl, riid, ppvObject);
}

ULONG WINAPI WIDirectInputDevice8::AddRef(::IDirectInputDevice8* This)
{
  log_debug("WIDirectInputDevice8::AddRef()");
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->AddRef(That->pimpl);
}

ULONG WINAPI WIDirectInputDevice8::Release(::IDirectInputDevice8* This)
{
  log_debug("WIDirectInputDevice8::Release()");
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  auto refcount = That->pimpl->lpVtbl->Release(That->pimpl);
  if (refcount == 0)
  {
    log_debug("WIDirectInputDevice8::Release(): deleting self");
    delete That;
  }
  return refcount;
}

HRESULT WINAPI WIDirectInputDevice8::GetCapabilities(::IDirectInputDevice8* This, LPDIDEVCAPS lpDIDevCaps)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->GetCapabilities(That->pimpl, lpDIDevCaps);
}

HRESULT WINAPI WIDirectInputDevice8::EnumObjects(::IDirectInputDevice8* This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->EnumObjects(That->pimpl, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::GetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->GetProperty(That->pimpl, rguidProp, pdiph);
}

HRESULT WINAPI WIDirectInputDevice8::SetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->SetProperty(That->pimpl, rguidProp, pdiph);
}

HRESULT WINAPI WIDirectInputDevice8::Acquire(::IDirectInputDevice8* This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->Acquire(That->pimpl);
}

HRESULT WINAPI WIDirectInputDevice8::Unacquire(::IDirectInputDevice8* This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->Unacquire(That->pimpl);
}

HRESULT WINAPI WIDirectInputDevice8::GetDeviceState(::IDirectInputDevice8* This, DWORD cbData, LPVOID lpvData)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->GetDeviceState(That->pimpl, cbData, lpvData);
}

HRESULT WINAPI WIDirectInputDevice8::GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  auto result = That->pimpl->lpVtbl->GetDeviceData(That->pimpl, cbObjectData, rgdod, pdwInOut, dwFlags);

  if (result == DI_OK && That->deviceKind == DeviceKind::mouse && g_state == true)
  {
    *pdwInOut = 0;
  }

  return result;
}

HRESULT WINAPI WIDirectInputDevice8::SetDataFormat(::IDirectInputDevice8* This, LPCDIDATAFORMAT lpdf)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->SetDataFormat(That->pimpl, lpdf);
}

HRESULT WINAPI WIDirectInputDevice8::SetEventNotification(::IDirectInputDevice8* This, HANDLE hEvent)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->SetEventNotification(That->pimpl, hEvent);
}

HRESULT WINAPI WIDirectInputDevice8::SetCooperativeLevel(::IDirectInputDevice8* This, HWND hwnd, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->SetCooperativeLevel(That->pimpl, hwnd, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::GetObjectInfo(::IDirectInputDevice8* This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->GetObjectInfo(That->pimpl, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI WIDirectInputDevice8::GetDeviceInfo(::IDirectInputDevice8* This, LPDIDEVICEINSTANCEA pdidi)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->GetDeviceInfo(That->pimpl, pdidi);
}

HRESULT WINAPI WIDirectInputDevice8::RunControlPanel(::IDirectInputDevice8* This, HWND hwndOwner, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->RunControlPanel(That->pimpl, hwndOwner, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::Initialize(::IDirectInputDevice8* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->Initialize(That->pimpl, hinst, dwVersion, rguid);
}

HRESULT WINAPI WIDirectInputDevice8::CreateEffect(::IDirectInputDevice8* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->CreateEffect(That->pimpl, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI WIDirectInputDevice8::EnumEffects(::IDirectInputDevice8* This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->EnumEffects(That->pimpl, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI WIDirectInputDevice8::GetEffectInfo(::IDirectInputDevice8* This, LPDIEFFECTINFOA pdei, REFGUID rguid)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->GetEffectInfo(That->pimpl, pdei, rguid);
}

HRESULT WINAPI WIDirectInputDevice8::GetForceFeedbackState(::IDirectInputDevice8* This, LPDWORD pdwOut)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->GetForceFeedbackState(That->pimpl, pdwOut);
}

HRESULT WINAPI WIDirectInputDevice8::SendForceFeedbackCommand(::IDirectInputDevice8* This, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->SendForceFeedbackCommand(That->pimpl, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::EnumCreatedEffectObjects(::IDirectInputDevice8* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->EnumCreatedEffectObjects(That->pimpl, lpCallback, pvRef, fl);
}

HRESULT WINAPI WIDirectInputDevice8::Escape(::IDirectInputDevice8* This, LPDIEFFESCAPE pesc)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->Escape(That->pimpl, pesc);
}

HRESULT WINAPI WIDirectInputDevice8::Poll(::IDirectInputDevice8* This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->Poll(That->pimpl);
}

HRESULT WINAPI WIDirectInputDevice8::SendDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->SendDeviceData(That->pimpl, cbObjectData, rgdod, pdwInOut, fl);
}

HRESULT WINAPI WIDirectInputDevice8::EnumEffectsInFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->EnumEffectsInFile(That->pimpl, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::WriteEffectToFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->WriteEffectToFile(That->pimpl, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::BuildActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->BuildActionMap(That->pimpl, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::SetActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->SetActionMap(That->pimpl, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::GetImageInfo(::IDirectInputDevice8* This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  return That->pimpl->lpVtbl->GetImageInfo(That->pimpl, lpdiDevImageInfoHeader);
}


VIDirectInput8::VIDirectInput8() : QueryInterface(WIDirectInput8::QueryInterface), AddRef(WIDirectInput8::AddRef), Release(WIDirectInput8::Release), CreateDevice(WIDirectInput8::CreateDevice), EnumDevices(WIDirectInput8::EnumDevices), GetDeviceStatus(WIDirectInput8::GetDeviceStatus), RunControlPanel(WIDirectInput8::RunControlPanel), Initialize(WIDirectInput8::Initialize), FindDevice(WIDirectInput8::FindDevice), EnumDevicesBySemantics(WIDirectInput8::EnumDevicesBySemantics), ConfigureDevices(WIDirectInput8::ConfigureDevices)
{}

VIDirectInput8 const WIDirectInput8::vIDirectInput8;

WIDirectInput8::WIDirectInput8(::IDirectInput8* pimpl_) : pvtbl(&vIDirectInput8), pimpl(pimpl_) {}

HRESULT WINAPI WIDirectInput8::QueryInterface(::IDirectInput8* This, REFIID riid, void** ppvObject)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  return That->pimpl->lpVtbl->QueryInterface(That->pimpl, riid, ppvObject);
}

ULONG WINAPI WIDirectInput8::AddRef(::IDirectInput8* This)
{
  log_debug("WIDirectInput8::AddRef()");
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  return That->pimpl->lpVtbl->AddRef(That->pimpl);
}

ULONG WINAPI WIDirectInput8::Release(::IDirectInput8* This)
{
  log_debug("WIDirectInput8::Release()");
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  ULONG refcount = That->pimpl->lpVtbl->Release(That->pimpl);
  if (refcount == 0)
  {
    log_debug("WIDirectInput8::Release(): deleting self");
    delete That;
  }
  return refcount;
}

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

HRESULT WINAPI WIDirectInput8::CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("di8b::WIDirectInput8::CreateDevice");
  auto That = reinterpret_cast<WIDirectInput8*>(This);

  HRESULT result = That->pimpl->lpVtbl->CreateDevice(That->pimpl, rguid, lplpDirectInputDevice, pUnkOuter);
  if (result == S_OK)
  {
    auto kind = get_device_kind(rguid);
    auto pWrapper = new di8b::WIDirectInputDevice8(reinterpret_cast<::IDirectInputDevice8*>(*lplpDirectInputDevice), kind);
    *lplpDirectInputDevice = reinterpret_cast<LPDIRECTINPUTDEVICE8A>(pWrapper);
  }
  return result;
}

HRESULT WINAPI WIDirectInput8::EnumDevices(::IDirectInput8* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("di8b::WIDirectInput8::EnumDevices");
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  return That->pimpl->lpVtbl->EnumDevices(That->pimpl, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInput8::GetDeviceStatus(::IDirectInput8* This, REFGUID rguidInstance)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  return That->pimpl->lpVtbl->GetDeviceStatus(That->pimpl, rguidInstance);
}

HRESULT WINAPI WIDirectInput8::RunControlPanel(::IDirectInput8* This, HWND hwndOwner, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  return That->pimpl->lpVtbl->RunControlPanel(That->pimpl, hwndOwner, dwFlags);
}

HRESULT WINAPI WIDirectInput8::Initialize(::IDirectInput8* This, HINSTANCE hinst, DWORD dwVersion)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  return That->pimpl->lpVtbl->Initialize(That->pimpl, hinst, dwVersion);
}

HRESULT WINAPI WIDirectInput8::FindDevice(::IDirectInput8* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  return That->pimpl->lpVtbl->FindDevice(That->pimpl, rguid, pszName, pguidInstance);
}

HRESULT WINAPI WIDirectInput8::EnumDevicesBySemantics(::IDirectInput8* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  return That->pimpl->lpVtbl->EnumDevicesBySemantics(That->pimpl, ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInput8::ConfigureDevices(::IDirectInput8* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  return That->pimpl->lpVtbl->ConfigureDevices(That->pimpl, lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}


void loop()
{
  while (true)
  {
    if (g_exiting)
      return;

    static auto wasPressed = false;
    auto isPressed = GetKeyState(VK_SCROLL) & 0x8000;
    if (isPressed && !wasPressed)
    {
      g_state = !g_state;
    }
    wasPressed = isPressed;

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

void start_loop()
{
  std::thread t (loop);
  t.detach();
}


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
    di8b::g_imports.fill();
    di8b::start_loop();
  }

  if (reason == DLL_PROCESS_DETACH)
  {
    di8b::log_info("Dll detached");
    di8b::g_exiting = true;
  }

  di8b::log_debug("DllMain success");
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
    auto pWrapper = new di8b::WIDirectInput8(reinterpret_cast<IDirectInput8*>(*ppvOut));
    *ppvOut = pWrapper;
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
