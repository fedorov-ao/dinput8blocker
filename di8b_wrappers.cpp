#include <di8b_wrappers.hpp>
#include <cassert>

namespace di8b
{

/* Templates */
/* WIDirectInputDevice8A */
#define NATIVE reinterpret_cast<LPDIRECTINPUTDEVICE8A>(This->pNative_)
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDevice8A::QueryInterface(BIDirectInputDevice8A* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDevice8A::QueryInterface(%p)", This);
  auto hr = CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
  if ((hr == S_OK) && (*ppvObject == This->pNative_))
    *ppvObject = This;
  return hr;
}

ULONG WINAPI BIDirectInputDevice8A::AddRef(BIDirectInputDevice8A* This)
{
  log_debug("BIDirectInputDevice8A::AddRef(%p)", This);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputDevice8A::Release(BIDirectInputDevice8A* This)
{
  log_debug("BIDirectInputDevice8A::Release(%p)", This);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  return r;
}

/*** IDirectInputDeviceA methods ***/
HRESULT WINAPI BIDirectInputDevice8A::GetCapabilities(BIDirectInputDevice8A* This, LPDIDEVCAPS lpDIDevCaps)
{
  log_debug("BIDirectInputDevice8A::GetCapabilities(%p)", This);
  return CALL_NATIVE(GetCapabilities)(NATIVE, lpDIDevCaps);
}

HRESULT WINAPI BIDirectInputDevice8A::EnumObjects(BIDirectInputDevice8A* This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::EnumObjects(%p)", This);
  return CALL_NATIVE(EnumObjects)(NATIVE, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::GetProperty(BIDirectInputDevice8A* This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice8A::GetProperty(%p)", This);
  return CALL_NATIVE(GetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice8A::SetProperty(BIDirectInputDevice8A* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice8A::SetProperty(%p)", This);
  return CALL_NATIVE(SetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice8A::Acquire(BIDirectInputDevice8A* This)
{
  log_debug("BIDirectInputDevice8A::Acquire(%p)", This);
  return CALL_NATIVE(Acquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8A::Unacquire(BIDirectInputDevice8A* This)
{
  log_debug("BIDirectInputDevice8A::Unacquire(%p)", This);
  return CALL_NATIVE(Unacquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8A::GetDeviceState(BIDirectInputDevice8A* This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BIDirectInputDevice8A::GetDeviceState(%p)", This);
  return CALL_NATIVE(GetDeviceState)(NATIVE, cbData, lpvData);
}

HRESULT WINAPI BIDirectInputDevice8A::GetDeviceData(BIDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::GetDeviceData(%p)", This);
  return CALL_NATIVE(GetDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::SetDataFormat(BIDirectInputDevice8A* This, LPCDIDATAFORMAT lpdf)
{
  log_debug("BIDirectInputDevice8A::SetDataFormat(%p)", This);
  return CALL_NATIVE(SetDataFormat)(NATIVE, lpdf);
}

HRESULT WINAPI BIDirectInputDevice8A::SetEventNotification(BIDirectInputDevice8A* This, HANDLE hEvent)
{
  log_debug("BIDirectInputDevice8A::SetEventNotification(%p)", This);
  return CALL_NATIVE(SetEventNotification)(NATIVE, hEvent);
}

HRESULT WINAPI BIDirectInputDevice8A::SetCooperativeLevel(BIDirectInputDevice8A* This, HWND hwnd, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::SetCooperativeLevel(%p)", This);
  return CALL_NATIVE(SetCooperativeLevel)(NATIVE, hwnd, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::GetObjectInfo(BIDirectInputDevice8A* This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  log_debug("BIDirectInputDevice8A::GetObjectInfo(%p)", This);
  return CALL_NATIVE(GetObjectInfo)(NATIVE, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI BIDirectInputDevice8A::GetDeviceInfo(BIDirectInputDevice8A* This, LPDIDEVICEINSTANCEA pdidi)
{
  log_debug("BIDirectInputDevice8A::GetDeviceInfo(%p)", This);
  return CALL_NATIVE(GetDeviceInfo)(NATIVE, pdidi);
}

HRESULT WINAPI BIDirectInputDevice8A::RunControlPanel(BIDirectInputDevice8A* This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::RunControlPanel(%p)", This);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::Initialize(BIDirectInputDevice8A* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  log_debug("BIDirectInputDevice8A::Initialize(%p)", This);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion, rguid);
}

/*** IDirectInputDevice2A methods ***/
HRESULT WINAPI BIDirectInputDevice8A::CreateEffect(BIDirectInputDevice8A* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  log_debug("BIDirectInputDevice8A::CreateEffect(%p)", This);
  return CALL_NATIVE(CreateEffect)(NATIVE, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI BIDirectInputDevice8A::EnumEffects(BIDirectInputDevice8A* This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  log_debug("BIDirectInputDevice8A::EnumEffects(%p)", This);
  return CALL_NATIVE(EnumEffects)(NATIVE, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI BIDirectInputDevice8A::GetEffectInfo(BIDirectInputDevice8A* This, LPDIEFFECTINFOA pdei, REFGUID rguid)
{
  log_debug("BIDirectInputDevice8A::GetEffectInfo(%p)", This);
  return CALL_NATIVE(GetEffectInfo)(NATIVE, pdei, rguid);
}

HRESULT WINAPI BIDirectInputDevice8A::GetForceFeedbackState(BIDirectInputDevice8A* This, LPDWORD pdwOut)
{
  log_debug("BIDirectInputDevice8A::GetForceFeedbackState(%p)", This);
  return CALL_NATIVE(GetForceFeedbackState)(NATIVE, pdwOut);
}

HRESULT WINAPI BIDirectInputDevice8A::SendForceFeedbackCommand(BIDirectInputDevice8A* This, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::SendForceFeedbackCommand(%p)", This);
  return CALL_NATIVE(SendForceFeedbackCommand)(NATIVE, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::EnumCreatedEffectObjects(BIDirectInputDevice8A* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  log_debug("BIDirectInputDevice8A::EnumCreatedEffectObjects(%p)", This);
  return CALL_NATIVE(EnumCreatedEffectObjects)(NATIVE, lpCallback, pvRef, fl);
}

HRESULT WINAPI BIDirectInputDevice8A::Escape(BIDirectInputDevice8A* This, LPDIEFFESCAPE pesc)
{
  log_debug("BIDirectInputDevice8A::Escape(%p)", This);
  return CALL_NATIVE(Escape)(NATIVE, pesc);
}

HRESULT WINAPI BIDirectInputDevice8A::Poll(BIDirectInputDevice8A* This)
{
  log_debug("BIDirectInputDevice8A::Poll(%p)", This);
  return CALL_NATIVE(Poll)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8A::SendDeviceData(BIDirectInputDevice8A* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  log_debug("BIDirectInputDevice8A::SendDeviceData(%p)", This);
  return CALL_NATIVE(SendDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, fl);
}

/*** IDirectInputDevice7A methods ***/
HRESULT WINAPI BIDirectInputDevice8A::EnumEffectsInFile(BIDirectInputDevice8A* This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::EnumEffectsInFile(%p)", This);
  return CALL_NATIVE(EnumEffectsInFile)(NATIVE, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::WriteEffectToFile(BIDirectInputDevice8A* This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::WriteEffectToFile(%p)", This);
  return CALL_NATIVE(WriteEffectToFile)(NATIVE, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

/*** IDirectInputDevice8A methods ***/
HRESULT WINAPI BIDirectInputDevice8A::BuildActionMap(BIDirectInputDevice8A* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::BuildActionMap(%p)", This);
  return CALL_NATIVE(BuildActionMap)(NATIVE, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::SetActionMap(BIDirectInputDevice8A* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::SetActionMap(%p)", This);
  return CALL_NATIVE(SetActionMap)(NATIVE, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::GetImageInfo(BIDirectInputDevice8A* This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader)
{
  log_debug("BIDirectInputDevice8A::GetImageInfo(%p)", This);
  return CALL_NATIVE(GetImageInfo)(NATIVE, lpdiDevImageInfoHeader);
}
#undef CALL_NATIVE
#undef NATIVE

BIDirectInputDevice8A::~BIDirectInputDevice8A()
{
  log_debug("BIDirectInputDevice8A::~BIDirectInputDevice8A(%p)", this);
}


/* WIDirectInputDevice8W */
#define NATIVE reinterpret_cast<LPDIRECTINPUTDEVICE8W>(This->pNative_)
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDevice8W::QueryInterface(BIDirectInputDevice8W* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDevice8W::QueryInterface(%p)", This);
  auto hr = CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
  if ((hr == S_OK) && (*ppvObject == This->pNative_))
    *ppvObject = This;
  return hr;
}

ULONG WINAPI BIDirectInputDevice8W::AddRef(BIDirectInputDevice8W* This)
{
  log_debug("BIDirectInputDevice8W::AddRef(%p)", This);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputDevice8W::Release(BIDirectInputDevice8W* This)
{
  log_debug("BIDirectInputDevice8W::Release(%p)", This);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  return r;
}

/*** IDirectInputDeviceW methods ***/
HRESULT WINAPI BIDirectInputDevice8W::GetCapabilities(BIDirectInputDevice8W* This, LPDIDEVCAPS lpDIDevCaps)
{
  log_debug("BIDirectInputDevice8W::GetCapabilities(%p)", This);
  return CALL_NATIVE(GetCapabilities)(NATIVE, lpDIDevCaps);
}

HRESULT WINAPI BIDirectInputDevice8W::EnumObjects(BIDirectInputDevice8W* This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::EnumObjects(%p)", This);
  return CALL_NATIVE(EnumObjects)(NATIVE, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::GetProperty(BIDirectInputDevice8W* This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice8W::GetProperty(%p)", This);
  return CALL_NATIVE(GetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice8W::SetProperty(BIDirectInputDevice8W* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice8W::SetProperty(%p)", This);
  return CALL_NATIVE(SetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice8W::Acquire(BIDirectInputDevice8W* This)
{
  log_debug("BIDirectInputDevice8W::Acquire(%p)", This);
  return CALL_NATIVE(Acquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8W::Unacquire(BIDirectInputDevice8W* This)
{
  log_debug("BIDirectInputDevice8W::Unacquire(%p)", This);
  return CALL_NATIVE(Unacquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8W::GetDeviceState(BIDirectInputDevice8W* This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BIDirectInputDevice8W::GetDeviceState(%p)", This);
  return CALL_NATIVE(GetDeviceState)(NATIVE, cbData, lpvData);
}

HRESULT WINAPI BIDirectInputDevice8W::GetDeviceData(BIDirectInputDevice8W* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::GetDeviceData(%p)", This);
  return CALL_NATIVE(GetDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::SetDataFormat(BIDirectInputDevice8W* This, LPCDIDATAFORMAT lpdf)
{
  log_debug("BIDirectInputDevice8W::SetDataFormat(%p)", This);
  return CALL_NATIVE(SetDataFormat)(NATIVE, lpdf);
}

HRESULT WINAPI BIDirectInputDevice8W::SetEventNotification(BIDirectInputDevice8W* This, HANDLE hEvent)
{
  log_debug("BIDirectInputDevice8W::SetEventNotification(%p)", This);
  return CALL_NATIVE(SetEventNotification)(NATIVE, hEvent);
}

HRESULT WINAPI BIDirectInputDevice8W::SetCooperativeLevel(BIDirectInputDevice8W* This, HWND hwnd, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::SetCooperativeLevel(%p)", This);
  return CALL_NATIVE(SetCooperativeLevel)(NATIVE, hwnd, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::GetObjectInfo(BIDirectInputDevice8W* This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow)
{
  log_debug("BIDirectInputDevice8W::GetObjectInfo(%p)", This);
  return CALL_NATIVE(GetObjectInfo)(NATIVE, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI BIDirectInputDevice8W::GetDeviceInfo(BIDirectInputDevice8W* This, LPDIDEVICEINSTANCEW pdidi)
{
  log_debug("BIDirectInputDevice8W::GetDeviceInfo(%p)", This);
  return CALL_NATIVE(GetDeviceInfo)(NATIVE, pdidi);
}

HRESULT WINAPI BIDirectInputDevice8W::RunControlPanel(BIDirectInputDevice8W* This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::RunControlPanel(%p)", This);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::Initialize(BIDirectInputDevice8W* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  log_debug("BIDirectInputDevice8W::Initialize(%p)", This);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion, rguid);
}

/*** IDirectInputDevice2W methods ***/
HRESULT WINAPI BIDirectInputDevice8W::CreateEffect(BIDirectInputDevice8W* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  log_debug("BIDirectInputDevice8W::CreateEffect(%p)", This);
  return CALL_NATIVE(CreateEffect)(NATIVE, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI BIDirectInputDevice8W::EnumEffects(BIDirectInputDevice8W* This, LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  log_debug("BIDirectInputDevice8W::EnumEffects(%p)", This);
  return CALL_NATIVE(EnumEffects)(NATIVE, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI BIDirectInputDevice8W::GetEffectInfo(BIDirectInputDevice8W* This, LPDIEFFECTINFOW pdei, REFGUID rguid)
{
  log_debug("BIDirectInputDevice8W::GetEffectInfo(%p)", This);
  return CALL_NATIVE(GetEffectInfo)(NATIVE, pdei, rguid);
}

HRESULT WINAPI BIDirectInputDevice8W::GetForceFeedbackState(BIDirectInputDevice8W* This, LPDWORD pdwOut)
{
  log_debug("BIDirectInputDevice8W::GetForceFeedbackState(%p)", This);
  return CALL_NATIVE(GetForceFeedbackState)(NATIVE, pdwOut);
}

HRESULT WINAPI BIDirectInputDevice8W::SendForceFeedbackCommand(BIDirectInputDevice8W* This, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::SendForceFeedbackCommand(%p)", This);
  return CALL_NATIVE(SendForceFeedbackCommand)(NATIVE, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::EnumCreatedEffectObjects(BIDirectInputDevice8W* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  log_debug("BIDirectInputDevice8W::EnumCreatedEffectObjects(%p)", This);
  return CALL_NATIVE(EnumCreatedEffectObjects)(NATIVE, lpCallback, pvRef, fl);
}

HRESULT WINAPI BIDirectInputDevice8W::Escape(BIDirectInputDevice8W* This, LPDIEFFESCAPE pesc)
{
  log_debug("BIDirectInputDevice8W::Escape(%p)", This);
  return CALL_NATIVE(Escape)(NATIVE, pesc);
}

HRESULT WINAPI BIDirectInputDevice8W::Poll(BIDirectInputDevice8W* This)
{
  log_debug("BIDirectInputDevice8W::Poll(%p)", This);
  return CALL_NATIVE(Poll)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8W::SendDeviceData(BIDirectInputDevice8W* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  log_debug("BIDirectInputDevice8W::SendDeviceData(%p)", This);
  return CALL_NATIVE(SendDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, fl);
}

/*** IDirectInputDevice7W methods ***/
HRESULT WINAPI BIDirectInputDevice8W::EnumEffectsInFile(BIDirectInputDevice8W* This, LPCWSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::EnumEffectsInFile(%p)", This);
  return CALL_NATIVE(EnumEffectsInFile)(NATIVE, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::WriteEffectToFile(BIDirectInputDevice8W* This, LPCWSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::WriteEffectToFile(%p)", This);
  return CALL_NATIVE(WriteEffectToFile)(NATIVE, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

/*** IDirectInputDevice8W methods ***/
HRESULT WINAPI BIDirectInputDevice8W::BuildActionMap(BIDirectInputDevice8W* This, LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::BuildActionMap(%p)", This);
  return CALL_NATIVE(BuildActionMap)(NATIVE, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::SetActionMap(BIDirectInputDevice8W* This, LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::SetActionMap(%p)", This);
  return CALL_NATIVE(SetActionMap)(NATIVE, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::GetImageInfo(BIDirectInputDevice8W* This, LPDIDEVICEIMAGEINFOHEADERW lpdiDevImageInfoHeader)
{
  log_debug("BIDirectInputDevice8W::GetImageInfo(%p)", This);
  return CALL_NATIVE(GetImageInfo)(NATIVE, lpdiDevImageInfoHeader);
}
#undef CALL_NATIVE
#undef NATIVE

BIDirectInputDevice8W::~BIDirectInputDevice8W()
{
  log_debug("BIDirectInputDevice8W::~BIDirectInputDevice8W(%p)", this);
}


/* WIDirectInput7A */
#define NATIVE reinterpret_cast<LPDIRECTINPUT7A>(This->pNative_)
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInput7A::QueryInterface(BIDirectInput7A* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput7A::QueryInterface(%p)", This);
  auto hr = CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
  if ((hr == S_OK) && (*ppvObject == This->pNative_))
    *ppvObject = This;
  return hr;
}

ULONG WINAPI BIDirectInput7A::AddRef(BIDirectInput7A* This)
{
  log_debug("BIDirectInput7A::AddRef(%p)", This);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput7A::Release(BIDirectInput7A* This)
{
  log_debug("BIDirectInput7A::Release(%p)", This);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  return r;
}

HRESULT WINAPI BIDirectInput7A::CreateDevice(BIDirectInput7A* This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput7A::CreateDevice(%p)", This);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, reinterpret_cast<LPDIRECTINPUTDEVICEA*>(lplpDirectInputDevice), pUnkOuter);
}

HRESULT WINAPI BIDirectInput7A::EnumDevices(BIDirectInput7A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput7A::EnumDevices(%p)", This);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput7A::GetDeviceStatus(BIDirectInput7A* This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput7A::GetDeviceStatus(%p)", This);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput7A::RunControlPanel(BIDirectInput7A* This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput7A::RunControlPanel(%p)", This);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput7A::Initialize(BIDirectInput7A* This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput7A::Initialize(%p)", This);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput7A::FindDevice(BIDirectInput7A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput7A::FindDevice(%p)", This);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}

HRESULT WINAPI BIDirectInput7A::CreateDeviceEx(BIDirectInput7A* This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter)
{
  log_debug("BIDirectInput7A::CreateDeviceEx(%p)", This);
  return CALL_NATIVE(CreateDeviceEx)(NATIVE, rguid, riid, pvOut, lpUnknownOuter);
}
#undef CALL_NATIVE
#undef NATIVE

BIDirectInput7A::~BIDirectInput7A()
{
  log_debug("BIDirectInput7A::~BIDirectInput7A(%p)", this);
}


/* WIDirectInput8A */
#define NATIVE reinterpret_cast<LPDIRECTINPUT8A>(This->pNative_)
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInput8A::QueryInterface(BIDirectInput8A* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput8A::QueryInterface(%p)", This);
  auto hr = CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
  if ((hr == S_OK) && (*ppvObject == This->pNative_))
    *ppvObject = This;
  return hr;
}

ULONG WINAPI BIDirectInput8A::AddRef(BIDirectInput8A* This)
{
  log_debug("BIDirectInput8A::AddRef(%p)", This);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput8A::Release(BIDirectInput8A* This)
{
  log_debug("BIDirectInput8A::Release(%p)", This);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  return r;
}

HRESULT WINAPI BIDirectInput8A::CreateDevice(BIDirectInput8A* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput8A::CreateDevice(%p)", This);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, reinterpret_cast<LPDIRECTINPUTDEVICE8A*>(lplpDirectInputDevice), pUnkOuter);
}

HRESULT WINAPI BIDirectInput8A::EnumDevices(BIDirectInput8A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput8A::EnumDevices(%p)", This);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput8A::GetDeviceStatus(BIDirectInput8A* This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput8A::GetDeviceStatus(%p)", This);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput8A::RunControlPanel(BIDirectInput8A* This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput8A::RunControlPanel(%p)", This);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput8A::Initialize(BIDirectInput8A* This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput8A::Initialize(%p)", This);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput8A::FindDevice(BIDirectInput8A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput8A::FindDevice(%p)", This);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}

HRESULT WINAPI BIDirectInput8A::EnumDevicesBySemantics(BIDirectInput8A* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput8A::EnumDevicesBySemantics(%p)", This);
  return CALL_NATIVE(EnumDevicesBySemantics)(NATIVE, ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput8A::ConfigureDevices(BIDirectInput8A* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
  log_debug("BIDirectInput8A::ConfigureDevices(%p)", This);
  return CALL_NATIVE(ConfigureDevices)(NATIVE, lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}
#undef CALL_NATIVE
#undef NATIVE

BIDirectInput8A::~BIDirectInput8A()
{
  log_debug("BIDirectInput8A::~BIDirectInput8A(%p)", this);
}


/* WIDirectInput7W */
#define NATIVE reinterpret_cast<LPDIRECTINPUT7W>(This->pNative_)
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInput7W::QueryInterface(BIDirectInput7W* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput7W::QueryInterface(%p)", This);
  auto hr = CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
  if ((hr == S_OK) && (*ppvObject == This->pNative_))
    *ppvObject = This;
  return hr;
}

ULONG WINAPI BIDirectInput7W::AddRef(BIDirectInput7W* This)
{
  log_debug("BIDirectInput7W::AddRef(%p)", This);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput7W::Release(BIDirectInput7W* This)
{
  log_debug("BIDirectInput7W::Release(%p)", This);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  return r;
}

HRESULT WINAPI BIDirectInput7W::CreateDevice(BIDirectInput7W* This, REFGUID rguid, LPDIRECTINPUTDEVICEW *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput7W::CreateDevice(%p)", This);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, reinterpret_cast<LPDIRECTINPUTDEVICEW*>(lplpDirectInputDevice), pUnkOuter);
}

HRESULT WINAPI BIDirectInput7W::EnumDevices(BIDirectInput7W* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput7W::EnumDevices(%p)", This);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput7W::GetDeviceStatus(BIDirectInput7W* This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput7W::GetDeviceStatus(%p)", This);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput7W::RunControlPanel(BIDirectInput7W* This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput7W::RunControlPanel(%p)", This);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput7W::Initialize(BIDirectInput7W* This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput7W::Initialize(%p)", This);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput7W::FindDevice(BIDirectInput7W* This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput7W::FindDevice(%p)", This);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}

HRESULT WINAPI BIDirectInput7W::CreateDeviceEx(BIDirectInput7W* This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter)
{
  log_debug("BIDirectInput7W::CreateDeviceEx(%p)", This);
  return CALL_NATIVE(CreateDeviceEx)(NATIVE, rguid, riid, pvOut, lpUnknownOuter);
}
#undef CALL_NATIVE
#undef NATIVE

BIDirectInput7W::~BIDirectInput7W()
{
  log_debug("BIDirectInput7W::~BIDirectInput7W(%p)", this);
}


/* WIDirectInput8W */
#define NATIVE reinterpret_cast<LPDIRECTINPUT8W>(This->pNative_)
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInput8W::QueryInterface(BIDirectInput8W* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput8W::QueryInterface(%p)", This);
  auto hr = CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
  if ((hr == S_OK) && (*ppvObject == This->pNative_))
    *ppvObject = This;
  return hr;
}

ULONG WINAPI BIDirectInput8W::AddRef(BIDirectInput8W* This)
{
  log_debug("BIDirectInput8W::AddRef(%p)", This);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput8W::Release(BIDirectInput8W* This)
{
  log_debug("BIDirectInput8W::Release(%p)", This);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  return r;
}

HRESULT WINAPI BIDirectInput8W::CreateDevice(BIDirectInput8W* This, REFGUID rguid, LPDIRECTINPUTDEVICE8W *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput8W::CreateDevice(%p)", This);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, reinterpret_cast<LPDIRECTINPUTDEVICE8W*>(lplpDirectInputDevice), pUnkOuter);
}

HRESULT WINAPI BIDirectInput8W::EnumDevices(BIDirectInput8W* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput8W::EnumDevices(%p)", This);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput8W::GetDeviceStatus(BIDirectInput8W* This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput8W::GetDeviceStatus(%p)", This);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput8W::RunControlPanel(BIDirectInput8W* This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput8W::RunControlPanel(%p)", This);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput8W::Initialize(BIDirectInput8W* This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput8W::Initialize(%p)", This);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput8W::FindDevice(BIDirectInput8W* This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput8W::FindDevice(%p)", This);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}

HRESULT WINAPI BIDirectInput8W::EnumDevicesBySemantics(BIDirectInput8W* This, LPCWSTR ptszUserName, LPDIACTIONFORMATW lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput8W::EnumDevicesBySemantics(%p)", This);
  return CALL_NATIVE(EnumDevicesBySemantics)(NATIVE, ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput8W::ConfigureDevices(BIDirectInput8W* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSW lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
  log_debug("BIDirectInput8W::ConfigureDevices(%p)", This);
  return CALL_NATIVE(ConfigureDevices)(NATIVE, lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}
#undef CALL_NATIVE
#undef NATIVE

BIDirectInput8W::~BIDirectInput8W()
{
  log_debug("BIDirectInput8W::~BIDirectInput8W(%p)", this);
}

} //namespace di8b
