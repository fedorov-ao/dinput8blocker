#define DIRECTINPUT_VERSION  0x0800
#define CINTERFACE

#include <cstring>
#include <stdexcept>
#include <fstream>
#include <windows.h>
#include <olectl.h>
#include <dinput.h>
#pragma pack(1)

#define DLLEXPORT __declspec(dllexport)

namespace di8b
{

std::ofstream & logger()
{
  static std::ofstream of ("dinput8_blocker.log");
  return of;
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


struct WIDirectInput8
{
  static HRESULT WINAPI QueryInterface(::IDirectInput8* This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(::IDirectInput8* This);
  static ULONG WINAPI Release(::IDirectInput8* This);

  static HRESULT WINAPI CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(::IDirectInput8* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(::IDirectInput8* This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(::IDirectInput8* This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(::IDirectInput8* This, HINSTANCE hinst, DWORD dwVersion);
  static HRESULT WINAPI FindDevice(::IDirectInput8* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  static HRESULT WINAPI EnumDevicesBySemantics(::IDirectInput8* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI ConfigureDevices(::IDirectInput8* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);

  static struct VIDirectInput8
  {
    HRESULT (WINAPI *QueryInterface)(::IDirectInput8* This, REFIID riid, void** ppvObject);
    ULONG (WINAPI *AddRef)(::IDirectInput8* This);
    ULONG (WINAPI *Release)(::IDirectInput8* This);

    HRESULT (WINAPI *CreateDevice)(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
    HRESULT (WINAPI *EnumDevices)(::IDirectInput8* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
    HRESULT (WINAPI *GetDeviceStatus)(::IDirectInput8* This, REFGUID rguidInstance);
    HRESULT (WINAPI *RunControlPanel)(::IDirectInput8* This, HWND hwndOwner, DWORD dwFlags);
    HRESULT (WINAPI *Initialize)(::IDirectInput8* This, HINSTANCE hinst, DWORD dwVersion);
    HRESULT (WINAPI *FindDevice)(::IDirectInput8* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
    HRESULT (WINAPI *EnumDevicesBySemantics)(::IDirectInput8* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags);
    HRESULT (WINAPI *ConfigureDevices)(::IDirectInput8* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);

    VIDirectInput8();
  } vIDirectInput8;

  VIDirectInput8* pvtbl;
  ::IDirectInput8* pimpl;

  WIDirectInput8(::IDirectInput8* pimpl);
};

WIDirectInput8::VIDirectInput8 WIDirectInput8::vIDirectInput8;

WIDirectInput8::VIDirectInput8::VIDirectInput8()
{
  this->QueryInterface = WIDirectInput8::QueryInterface;
  this->AddRef = WIDirectInput8::AddRef;
  this->Release = WIDirectInput8::Release;
  this->CreateDevice = WIDirectInput8::CreateDevice;
  this->EnumDevices = WIDirectInput8::EnumDevices;
  this->GetDeviceStatus = WIDirectInput8::GetDeviceStatus;
  this->RunControlPanel = WIDirectInput8::RunControlPanel;
  this->Initialize = WIDirectInput8::Initialize;
  this->FindDevice = WIDirectInput8::FindDevice;
  this->EnumDevicesBySemantics = WIDirectInput8::EnumDevicesBySemantics;
  this->ConfigureDevices = WIDirectInput8::ConfigureDevices;
}

WIDirectInput8::WIDirectInput8(::IDirectInput8* pimpl_) : pvtbl(&vIDirectInput8), pimpl(pimpl_) {}

HRESULT WINAPI WIDirectInput8::QueryInterface(::IDirectInput8* This, REFIID riid, void** ppvObject)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  return That->pimpl->lpVtbl->QueryInterface(That->pimpl, riid, ppvObject);
}

ULONG WINAPI WIDirectInput8::AddRef(::IDirectInput8* This)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  return That->pimpl->lpVtbl->AddRef(That->pimpl);
}

ULONG WINAPI WIDirectInput8::Release(::IDirectInput8* This)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  ULONG refcount = That->pimpl->lpVtbl->Release(That->pimpl);
  if (refcount == 0) delete That;
  return refcount;
}

HRESULT WINAPI WIDirectInput8::CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("di8b::WIDirectInput8::CreateDevice");
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  return That->pimpl->lpVtbl->CreateDevice(That->pimpl, rguid, lplpDirectInputDevice, pUnkOuter);
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
  }
  
  if (reason == DLL_PROCESS_DETACH)
  {
    di8b::log_info("Dll detached");
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
