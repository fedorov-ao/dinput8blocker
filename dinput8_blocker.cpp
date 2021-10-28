#include <cstring>
#include <stdexcept>
#include <fstream>
#include <windows.h>
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
    typedef HRESULT WINAPI (DirectInput8Create_t)(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter);
		DirectInput8Create_t * DirectInput8Create;

    typedef HRESULT WINAPI (DllCanUnloadNow_t)();
    DllCanUnloadNow_t * DllCanUnloadNow;

    typedef HRESULT WINAPI (DllGetClassObject_t)(REFCLSID rclsid, REFIID riid, LPVOID *ppv);
    DllGetClassObject_t * DllGetClassObject;

    typedef HRESULT WINAPI (DllRegisterServer_t)();
		DllRegisterServer_t * DllRegisterServer;
    
    typedef HRESULT WINAPI (DllUnregisterServer_t)();
		DllUnregisterServer_t * DllUnregisterServer;
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

  dinput8.DirectInput8Create = reinterpret_cast<Dinput8::DirectInput8Create_t *>(GetProcAddress(hNativeDinput8Dll,"DirectInput8Create"));
  dinput8.DllCanUnloadNow = reinterpret_cast<Dinput8::DllCanUnloadNow_t *>(GetProcAddress(hNativeDinput8Dll,"DllCanUnloadNow"));
  dinput8.DllGetClassObject = reinterpret_cast<Dinput8::DllGetClassObject_t *>(GetProcAddress(hNativeDinput8Dll,"DllGetClassObject"));
  dinput8.DllRegisterServer = reinterpret_cast<Dinput8::DllRegisterServer_t *>(GetProcAddress(hNativeDinput8Dll,"DllRegisterServer"));
  dinput8.DllUnregisterServer = reinterpret_cast<Dinput8::DllUnregisterServer_t *>(GetProcAddress(hNativeDinput8Dll,"DllUnregisterServer"));

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
