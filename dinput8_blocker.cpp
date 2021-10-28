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

HRESULT WINAPI SampleExport() { return S_OK; }

} 
