#include <cstring>
#include <stdexcept>
#include <fstream>
#include <windows.h>
#include <olectl.h>
#define DIRECTINPUT_VERSION  0x0800
#include <dinput.h>
#pragma pack(1)

#define DLLEXPORT __declspec(dllexport)

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


BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason,LPVOID v)
try {
  if (reason == DLL_PROCESS_ATTACH)
  {
    log_info("Dll attached");
    g_imports.fill();
  }
  
  if (reason == DLL_PROCESS_DETACH)
  {
    log_info("Dll detached");
  }

  log_debug("DllMain success");
  return TRUE;
} catch (std::exception const & e) 
{
  log_error(e.what());
  return FALSE;
}

extern "C" {

DLLEXPORT HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter)
{
  log_debug("DirectInput8Create");
  return g_imports.dinput8.DirectInput8Create(hinst, dwVersion, riidltf, ppvOut, punkOuter);
}

DLLEXPORT HRESULT WINAPI DllCanUnloadNow()
{
  log_debug("DllCanUnloadNow");
  return g_imports.dinput8.DllCanUnloadNow();
}

DLLEXPORT HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
  log_debug("DllGetClassObject");
  return g_imports.dinput8.DllGetClassObject(rclsid, riid, ppv);
}

DLLEXPORT HRESULT WINAPI DllRegisterServer()
{
  log_debug("DllRegisterServer");
  return g_imports.dinput8.DllRegisterServer();
}

DLLEXPORT HRESULT WINAPI DllUnregisterServer()
{
  log_debug("DllUnregisterServer");
  return g_imports.dinput8.DllUnregisterServer();
}

} // extern "C"
