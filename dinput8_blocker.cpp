#include <windows.h>
#include <dinput.h>
#pragma pack(1)

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason,LPVOID v)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
	}
  else if (reason == DLL_PROCESS_DETACH)
	{
	}

	return TRUE;
}

extern "C" {

HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter)
{
  return E_FAIL;
}

HRESULT WINAPI DllCanUnloadNow()
{
  return E_FAIL;
}

HRESULT WINAPI DllGetClassObject (REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
  return E_FAIL;
}

HRESULT WINAPI DllRegisterServer()
{
  return E_FAIL;
}

HRESULT WINAPI DllUnregisterServer()
{
  return E_FAIL;
}

} // extern "C"
