#include <cstring>
#include <stdexcept>
#include <windows.h>
#include <dinput.h>
#pragma pack(1)

#define DLLEXPORT __declspec(dllexport)

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
}


BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason,LPVOID v)
try {
	if (reason == DLL_PROCESS_ATTACH)
	{
    g_imports.fill();
	}
  else if (reason == DLL_PROCESS_DETACH)
	{
	}

	return TRUE;
} catch (std::exception const & e) 
{
  //TODO Log exception info here
  return FALSE;
}

extern "C" {

HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter)
{
  return g_imports.dinput8.DirectInput8Create(hinst, dwVersion, riidltf, ppvOut, punkOuter);
}

HRESULT WINAPI DllCanUnloadNow()
{
  return g_imports.dinput8.DllCanUnloadNow();
}

HRESULT WINAPI DllGetClassObject (REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
  return g_imports.dinput8.DllGetClassObject(rclsid, riid, ppv);
}

HRESULT WINAPI DllRegisterServer()
{
  return g_imports.dinput8.DllRegisterServer();
}

HRESULT WINAPI DllUnregisterServer()
{
  return g_imports.dinput8.DllUnregisterServer();
}

} // extern "C"
