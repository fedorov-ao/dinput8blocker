#ifndef DI8B_WRAPPERS_HPP
#define DI8B_WRAPPERS_HPP

#define DIRECTINPUT_VERSION  0x0800
#define CINTERFACE

#include <dinput.h>
#include <di8b_common.hpp>
#pragma pack(1)

namespace di8b
{

/* Templates */
/* WIDirectInputDevice8A */
class BIDirectInputDevice8A;
struct VIDirectInputDevice8A
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(BIDirectInputDevice8A* This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(BIDirectInputDevice8A* This);
  ULONG (WINAPI *Release)(BIDirectInputDevice8A* This);
  /*** IDirectInputDeviceA methods ***/
  HRESULT (WINAPI *GetCapabilities)(BIDirectInputDevice8A* This, LPDIDEVCAPS lpDIDevCaps);
  HRESULT (WINAPI *EnumObjects)(BIDirectInputDevice8A* This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetProperty)(BIDirectInputDevice8A* This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  HRESULT (WINAPI *SetProperty)(BIDirectInputDevice8A* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  HRESULT (WINAPI *Acquire)(BIDirectInputDevice8A* This);
  HRESULT (WINAPI *Unacquire)(BIDirectInputDevice8A* This);
  HRESULT (WINAPI *GetDeviceState)(BIDirectInputDevice8A* This, DWORD cbData, LPVOID lpvData);
  HRESULT (WINAPI *GetDeviceData)(BIDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  HRESULT (WINAPI *SetDataFormat)(BIDirectInputDevice8A* This, LPCDIDATAFORMAT lpdf);
  HRESULT (WINAPI *SetEventNotification)(BIDirectInputDevice8A* This, HANDLE hEvent);
  HRESULT (WINAPI *SetCooperativeLevel)(BIDirectInputDevice8A* This, HWND hwnd, DWORD dwFlags);
  HRESULT (WINAPI *GetObjectInfo)(BIDirectInputDevice8A* This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  HRESULT (WINAPI *GetDeviceInfo)(BIDirectInputDevice8A* This, LPDIDEVICEINSTANCEA pdidi);
  HRESULT (WINAPI *RunControlPanel)(BIDirectInputDevice8A* This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(BIDirectInputDevice8A* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2A methods ***/
  HRESULT (WINAPI *CreateEffect)(BIDirectInputDevice8A* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  HRESULT (WINAPI *EnumEffects)(BIDirectInputDevice8A* This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  HRESULT (WINAPI *GetEffectInfo)(BIDirectInputDevice8A* This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  HRESULT (WINAPI *GetForceFeedbackState)(BIDirectInputDevice8A* This, LPDWORD pdwOut);
  HRESULT (WINAPI *SendForceFeedbackCommand)(BIDirectInputDevice8A* This, DWORD dwFlags);
  HRESULT (WINAPI *EnumCreatedEffectObjects)(BIDirectInputDevice8A* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  HRESULT (WINAPI *Escape)(BIDirectInputDevice8A* This, LPDIEFFESCAPE pesc);
  HRESULT (WINAPI *Poll)(BIDirectInputDevice8A* This);
  HRESULT (WINAPI *SendDeviceData)(BIDirectInputDevice8A* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7A methods ***/
  HRESULT (WINAPI *EnumEffectsInFile)(BIDirectInputDevice8A* This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  HRESULT (WINAPI *WriteEffectToFile)(BIDirectInputDevice8A* This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  /*** IDirectInputDevice8A methods ***/
  HRESULT (WINAPI *BuildActionMap)(BIDirectInputDevice8A* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *SetActionMap)(BIDirectInputDevice8A* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *GetImageInfo)(BIDirectInputDevice8A* This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader);
};

class BIDirectInputDevice8A
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(BIDirectInputDevice8A* This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(BIDirectInputDevice8A* This);
  static ULONG WINAPI Release(BIDirectInputDevice8A* This);
  /*** IDirectInputDeviceA methods ***/
  static HRESULT WINAPI GetCapabilities(BIDirectInputDevice8A* This, LPDIDEVCAPS lpDIDevCaps);
  static HRESULT WINAPI EnumObjects(BIDirectInputDevice8A* This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetProperty(BIDirectInputDevice8A* This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  static HRESULT WINAPI SetProperty(BIDirectInputDevice8A* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  static HRESULT WINAPI Acquire(BIDirectInputDevice8A* This);
  static HRESULT WINAPI Unacquire(BIDirectInputDevice8A* This);
  static HRESULT WINAPI GetDeviceState(BIDirectInputDevice8A* This, DWORD cbData, LPVOID lpvData);
  static HRESULT WINAPI GetDeviceData(BIDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  static HRESULT WINAPI SetDataFormat(BIDirectInputDevice8A* This, LPCDIDATAFORMAT lpdf);
  static HRESULT WINAPI SetEventNotification(BIDirectInputDevice8A* This, HANDLE hEvent);
  static HRESULT WINAPI SetCooperativeLevel(BIDirectInputDevice8A* This, HWND hwnd, DWORD dwFlags);
  static HRESULT WINAPI GetObjectInfo(BIDirectInputDevice8A* This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  static HRESULT WINAPI GetDeviceInfo(BIDirectInputDevice8A* This, LPDIDEVICEINSTANCEA pdidi);
  static HRESULT WINAPI RunControlPanel(BIDirectInputDevice8A* This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(BIDirectInputDevice8A* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2A methods ***/
  static HRESULT WINAPI CreateEffect(BIDirectInputDevice8A* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  static HRESULT WINAPI EnumEffects(BIDirectInputDevice8A* This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  static HRESULT WINAPI GetEffectInfo(BIDirectInputDevice8A* This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  static HRESULT WINAPI GetForceFeedbackState(BIDirectInputDevice8A* This, LPDWORD pdwOut);
  static HRESULT WINAPI SendForceFeedbackCommand(BIDirectInputDevice8A* This, DWORD dwFlags);
  static HRESULT WINAPI EnumCreatedEffectObjects(BIDirectInputDevice8A* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  static HRESULT WINAPI Escape(BIDirectInputDevice8A* This, LPDIEFFESCAPE pesc);
  static HRESULT WINAPI Poll(BIDirectInputDevice8A* This);
  static HRESULT WINAPI SendDeviceData(BIDirectInputDevice8A* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7A methods ***/
  static HRESULT WINAPI EnumEffectsInFile(BIDirectInputDevice8A* This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  static HRESULT WINAPI WriteEffectToFile(BIDirectInputDevice8A* This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  /*** IDirectInputDevice8A methods ***/
  static HRESULT WINAPI BuildActionMap(BIDirectInputDevice8A* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI SetActionMap(BIDirectInputDevice8A* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI GetImageInfo(BIDirectInputDevice8A* This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader);

  BIDirectInputDevice8A(LPVOID pNative, VIDirectInputDevice8A const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputDevice8A();

private:
  static VIDirectInputDevice8A const vtbl_;

  VIDirectInputDevice8A const * pVtbl_;
  LPVOID pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputDevice8A : public BIDirectInputDevice8A
{
public:
  static ULONG WINAPI Release(D* This);
  WIDirectInputDevice8A(LPVOID pNative);

private:
  static VIDirectInputDevice8A const vtbl_;
};

template <class D>
VIDirectInputDevice8A const WIDirectInputDevice8A<D>::vtbl_ =
{
  /*** IUnknown methods ***/
  reinterpret_cast<decltype(VIDirectInputDevice8A::QueryInterface)>(&D::QueryInterface),
  reinterpret_cast<decltype(VIDirectInputDevice8A::AddRef)>(&D::AddRef),
  reinterpret_cast<decltype(VIDirectInputDevice8A::Release)>(&D::Release),
  /*** IDirectInputDeviceA methods ***/
  reinterpret_cast<decltype(VIDirectInputDevice8A::GetCapabilities)>(&D::GetCapabilities),
  reinterpret_cast<decltype(VIDirectInputDevice8A::EnumObjects)>(&D::EnumObjects),
  reinterpret_cast<decltype(VIDirectInputDevice8A::GetProperty)>(&D::GetProperty),
  reinterpret_cast<decltype(VIDirectInputDevice8A::SetProperty)>(&D::SetProperty),
  reinterpret_cast<decltype(VIDirectInputDevice8A::Acquire)>(&D::Acquire),
  reinterpret_cast<decltype(VIDirectInputDevice8A::Unacquire)>(&D::Unacquire),
  reinterpret_cast<decltype(VIDirectInputDevice8A::GetDeviceState)>(&D::GetDeviceState),
  reinterpret_cast<decltype(VIDirectInputDevice8A::GetDeviceData)>(&D::GetDeviceData),
  reinterpret_cast<decltype(VIDirectInputDevice8A::SetDataFormat)>(&D::SetDataFormat),
  reinterpret_cast<decltype(VIDirectInputDevice8A::SetEventNotification)>(&D::SetEventNotification),
  reinterpret_cast<decltype(VIDirectInputDevice8A::SetCooperativeLevel)>(&D::SetCooperativeLevel),
  reinterpret_cast<decltype(VIDirectInputDevice8A::GetObjectInfo)>(&D::GetObjectInfo),
  reinterpret_cast<decltype(VIDirectInputDevice8A::GetDeviceInfo)>(&D::GetDeviceInfo),
  reinterpret_cast<decltype(VIDirectInputDevice8A::RunControlPanel)>(&D::RunControlPanel),
  reinterpret_cast<decltype(VIDirectInputDevice8A::Initialize)>(&D::Initialize),
  /*** IDirectInputDevice2A methods ***/
  reinterpret_cast<decltype(VIDirectInputDevice8A::CreateEffect)>(&D::CreateEffect),
  reinterpret_cast<decltype(VIDirectInputDevice8A::EnumEffects)>(&D::EnumEffects),
  reinterpret_cast<decltype(VIDirectInputDevice8A::GetEffectInfo)>(&D::GetEffectInfo),
  reinterpret_cast<decltype(VIDirectInputDevice8A::GetForceFeedbackState)>(&D::GetForceFeedbackState),
  reinterpret_cast<decltype(VIDirectInputDevice8A::SendForceFeedbackCommand)>(&D::SendForceFeedbackCommand),
  reinterpret_cast<decltype(VIDirectInputDevice8A::EnumCreatedEffectObjects)>(&D::EnumCreatedEffectObjects),
  reinterpret_cast<decltype(VIDirectInputDevice8A::Escape)>(&D::Escape),
  reinterpret_cast<decltype(VIDirectInputDevice8A::Poll)>(&D::Poll),
  reinterpret_cast<decltype(VIDirectInputDevice8A::SendDeviceData)>(&D::SendDeviceData),
  /*** IDirectInputDevice7A methods ***/
  reinterpret_cast<decltype(VIDirectInputDevice8A::EnumEffectsInFile)>(&D::EnumEffectsInFile),
  reinterpret_cast<decltype(VIDirectInputDevice8A::WriteEffectToFile)>(&D::WriteEffectToFile),
  /*** IDirectInputDevice8A methods ***/
  reinterpret_cast<decltype(VIDirectInputDevice8A::BuildActionMap)>(&D::BuildActionMap),
  reinterpret_cast<decltype(VIDirectInputDevice8A::SetActionMap)>(&D::SetActionMap),
  reinterpret_cast<decltype(VIDirectInputDevice8A::GetImageInfo)>(&D::GetImageInfo)
};

template <class D>
ULONG WINAPI WIDirectInputDevice8A<D>::Release(D* This)
{
  ULONG r = BIDirectInputDevice8A::Release(This);
  if (r == 0)
  {
    log_debug("WIDirectInputDevice8A<D>::Release(%p): deleting self", This);
    delete This;
  }
  return r;
}

template <class D>
WIDirectInputDevice8A<D>::WIDirectInputDevice8A(LPVOID pNative) : BIDirectInputDevice8A(pNative, &vtbl_, false)
{}


/* WIDirectInputDevice8W */
class BIDirectInputDevice8W;
struct VIDirectInputDevice8W
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(BIDirectInputDevice8W* This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(BIDirectInputDevice8W* This);
  ULONG (WINAPI *Release)(BIDirectInputDevice8W* This);
  /*** IDirectInputDeviceW methods ***/
  HRESULT (WINAPI *GetCapabilities)(BIDirectInputDevice8W* This, LPDIDEVCAPS lpDIDevCaps);
  HRESULT (WINAPI *EnumObjects)(BIDirectInputDevice8W* This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetProperty)(BIDirectInputDevice8W* This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  HRESULT (WINAPI *SetProperty)(BIDirectInputDevice8W* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  HRESULT (WINAPI *Acquire)(BIDirectInputDevice8W* This);
  HRESULT (WINAPI *Unacquire)(BIDirectInputDevice8W* This);
  HRESULT (WINAPI *GetDeviceState)(BIDirectInputDevice8W* This, DWORD cbData, LPVOID lpvData);
  HRESULT (WINAPI *GetDeviceData)(BIDirectInputDevice8W* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  HRESULT (WINAPI *SetDataFormat)(BIDirectInputDevice8W* This, LPCDIDATAFORMAT lpdf);
  HRESULT (WINAPI *SetEventNotification)(BIDirectInputDevice8W* This, HANDLE hEvent);
  HRESULT (WINAPI *SetCooperativeLevel)(BIDirectInputDevice8W* This, HWND hwnd, DWORD dwFlags);
  HRESULT (WINAPI *GetObjectInfo)(BIDirectInputDevice8W* This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow);
  HRESULT (WINAPI *GetDeviceInfo)(BIDirectInputDevice8W* This, LPDIDEVICEINSTANCEW pdidi);
  HRESULT (WINAPI *RunControlPanel)(BIDirectInputDevice8W* This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(BIDirectInputDevice8W* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2W methods ***/
  HRESULT (WINAPI *CreateEffect)(BIDirectInputDevice8W* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  HRESULT (WINAPI *EnumEffects)(BIDirectInputDevice8W* This, LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType);
  HRESULT (WINAPI *GetEffectInfo)(BIDirectInputDevice8W* This, LPDIEFFECTINFOW pdei, REFGUID rguid);
  HRESULT (WINAPI *GetForceFeedbackState)(BIDirectInputDevice8W* This, LPDWORD pdwOut);
  HRESULT (WINAPI *SendForceFeedbackCommand)(BIDirectInputDevice8W* This, DWORD dwFlags);
  HRESULT (WINAPI *EnumCreatedEffectObjects)(BIDirectInputDevice8W* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  HRESULT (WINAPI *Escape)(BIDirectInputDevice8W* This, LPDIEFFESCAPE pesc);
  HRESULT (WINAPI *Poll)(BIDirectInputDevice8W* This);
  HRESULT (WINAPI *SendDeviceData)(BIDirectInputDevice8W* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7W methods ***/
  HRESULT (WINAPI *EnumEffectsInFile)(BIDirectInputDevice8W* This, LPCWSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  HRESULT (WINAPI *WriteEffectToFile)(BIDirectInputDevice8W* This, LPCWSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  /*** IDirectInputDevice8W methods ***/
  HRESULT (WINAPI *BuildActionMap)(BIDirectInputDevice8W* This, LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *SetActionMap)(BIDirectInputDevice8W* This, LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *GetImageInfo)(BIDirectInputDevice8W* This, LPDIDEVICEIMAGEINFOHEADERW lpdiDevImageInfoHeader);
};

class BIDirectInputDevice8W
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(BIDirectInputDevice8W* This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(BIDirectInputDevice8W* This);
  static ULONG WINAPI Release(BIDirectInputDevice8W* This);
  /*** IDirectInputDeviceW methods ***/
  static HRESULT WINAPI GetCapabilities(BIDirectInputDevice8W* This, LPDIDEVCAPS lpDIDevCaps);
  static HRESULT WINAPI EnumObjects(BIDirectInputDevice8W* This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetProperty(BIDirectInputDevice8W* This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  static HRESULT WINAPI SetProperty(BIDirectInputDevice8W* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  static HRESULT WINAPI Acquire(BIDirectInputDevice8W* This);
  static HRESULT WINAPI Unacquire(BIDirectInputDevice8W* This);
  static HRESULT WINAPI GetDeviceState(BIDirectInputDevice8W* This, DWORD cbData, LPVOID lpvData);
  static HRESULT WINAPI GetDeviceData(BIDirectInputDevice8W* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  static HRESULT WINAPI SetDataFormat(BIDirectInputDevice8W* This, LPCDIDATAFORMAT lpdf);
  static HRESULT WINAPI SetEventNotification(BIDirectInputDevice8W* This, HANDLE hEvent);
  static HRESULT WINAPI SetCooperativeLevel(BIDirectInputDevice8W* This, HWND hwnd, DWORD dwFlags);
  static HRESULT WINAPI GetObjectInfo(BIDirectInputDevice8W* This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow);
  static HRESULT WINAPI GetDeviceInfo(BIDirectInputDevice8W* This, LPDIDEVICEINSTANCEW pdidi);
  static HRESULT WINAPI RunControlPanel(BIDirectInputDevice8W* This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(BIDirectInputDevice8W* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2W methods ***/
  static HRESULT WINAPI CreateEffect(BIDirectInputDevice8W* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  static HRESULT WINAPI EnumEffects(BIDirectInputDevice8W* This, LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType);
  static HRESULT WINAPI GetEffectInfo(BIDirectInputDevice8W* This, LPDIEFFECTINFOW pdei, REFGUID rguid);
  static HRESULT WINAPI GetForceFeedbackState(BIDirectInputDevice8W* This, LPDWORD pdwOut);
  static HRESULT WINAPI SendForceFeedbackCommand(BIDirectInputDevice8W* This, DWORD dwFlags);
  static HRESULT WINAPI EnumCreatedEffectObjects(BIDirectInputDevice8W* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  static HRESULT WINAPI Escape(BIDirectInputDevice8W* This, LPDIEFFESCAPE pesc);
  static HRESULT WINAPI Poll(BIDirectInputDevice8W* This);
  static HRESULT WINAPI SendDeviceData(BIDirectInputDevice8W* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7W methods ***/
  static HRESULT WINAPI EnumEffectsInFile(BIDirectInputDevice8W* This, LPCWSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  static HRESULT WINAPI WriteEffectToFile(BIDirectInputDevice8W* This, LPCWSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  /*** IDirectInputDevice8W methods ***/
  static HRESULT WINAPI BuildActionMap(BIDirectInputDevice8W* This, LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI SetActionMap(BIDirectInputDevice8W* This, LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI GetImageInfo(BIDirectInputDevice8W* This, LPDIDEVICEIMAGEINFOHEADERW lpdiDevImageInfoHeader);

  BIDirectInputDevice8W(LPVOID pNative, VIDirectInputDevice8W const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputDevice8W();

private:
  static VIDirectInputDevice8W const vtbl_;

  VIDirectInputDevice8W const * pVtbl_;
  LPVOID pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputDevice8W : public BIDirectInputDevice8W
{
public:
  static ULONG WINAPI Release(D* This);
  WIDirectInputDevice8W(LPVOID pNative);

private:
  static VIDirectInputDevice8W const vtbl_;
};

template <class D>
VIDirectInputDevice8W const WIDirectInputDevice8W<D>::vtbl_ =
{
  /*** IUnknown methods ***/
  reinterpret_cast<decltype(VIDirectInputDevice8W::QueryInterface)>(&D::QueryInterface),
  reinterpret_cast<decltype(VIDirectInputDevice8W::AddRef)>(&D::AddRef),
  reinterpret_cast<decltype(VIDirectInputDevice8W::Release)>(&D::Release),
  /*** IDirectInputDeviceA methods ***/
  reinterpret_cast<decltype(VIDirectInputDevice8W::GetCapabilities)>(&D::GetCapabilities),
  reinterpret_cast<decltype(VIDirectInputDevice8W::EnumObjects)>(&D::EnumObjects),
  reinterpret_cast<decltype(VIDirectInputDevice8W::GetProperty)>(&D::GetProperty),
  reinterpret_cast<decltype(VIDirectInputDevice8W::SetProperty)>(&D::SetProperty),
  reinterpret_cast<decltype(VIDirectInputDevice8W::Acquire)>(&D::Acquire),
  reinterpret_cast<decltype(VIDirectInputDevice8W::Unacquire)>(&D::Unacquire),
  reinterpret_cast<decltype(VIDirectInputDevice8W::GetDeviceState)>(&D::GetDeviceState),
  reinterpret_cast<decltype(VIDirectInputDevice8W::GetDeviceData)>(&D::GetDeviceData),
  reinterpret_cast<decltype(VIDirectInputDevice8W::SetDataFormat)>(&D::SetDataFormat),
  reinterpret_cast<decltype(VIDirectInputDevice8W::SetEventNotification)>(&D::SetEventNotification),
  reinterpret_cast<decltype(VIDirectInputDevice8W::SetCooperativeLevel)>(&D::SetCooperativeLevel),
  reinterpret_cast<decltype(VIDirectInputDevice8W::GetObjectInfo)>(&D::GetObjectInfo),
  reinterpret_cast<decltype(VIDirectInputDevice8W::GetDeviceInfo)>(&D::GetDeviceInfo),
  reinterpret_cast<decltype(VIDirectInputDevice8W::RunControlPanel)>(&D::RunControlPanel),
  reinterpret_cast<decltype(VIDirectInputDevice8W::Initialize)>(&D::Initialize),
  /*** IDirectInputDevice2A methods ***/
  reinterpret_cast<decltype(VIDirectInputDevice8W::CreateEffect)>(&D::CreateEffect),
  reinterpret_cast<decltype(VIDirectInputDevice8W::EnumEffects)>(&D::EnumEffects),
  reinterpret_cast<decltype(VIDirectInputDevice8W::GetEffectInfo)>(&D::GetEffectInfo),
  reinterpret_cast<decltype(VIDirectInputDevice8W::GetForceFeedbackState)>(&D::GetForceFeedbackState),
  reinterpret_cast<decltype(VIDirectInputDevice8W::SendForceFeedbackCommand)>(&D::SendForceFeedbackCommand),
  reinterpret_cast<decltype(VIDirectInputDevice8W::EnumCreatedEffectObjects)>(&D::EnumCreatedEffectObjects),
  reinterpret_cast<decltype(VIDirectInputDevice8W::Escape)>(&D::Escape),
  reinterpret_cast<decltype(VIDirectInputDevice8W::Poll)>(&D::Poll),
  reinterpret_cast<decltype(VIDirectInputDevice8W::SendDeviceData)>(&D::SendDeviceData),
  /*** IDirectInputDevice7A methods ***/
  reinterpret_cast<decltype(VIDirectInputDevice8W::EnumEffectsInFile)>(&D::EnumEffectsInFile),
  reinterpret_cast<decltype(VIDirectInputDevice8W::WriteEffectToFile)>(&D::WriteEffectToFile),
  /*** IDirectInputDevice8W methods ***/
  reinterpret_cast<decltype(VIDirectInputDevice8W::BuildActionMap)>(&D::BuildActionMap),
  reinterpret_cast<decltype(VIDirectInputDevice8W::SetActionMap)>(&D::SetActionMap),
  reinterpret_cast<decltype(VIDirectInputDevice8W::GetImageInfo)>(&D::GetImageInfo)
};

template <class D>
ULONG WINAPI WIDirectInputDevice8W<D>::Release(D* This)
{
  ULONG r = BIDirectInputDevice8W::Release(This);
  if (r == 0)
  {
    log_debug("WIDirectInputDevice8W<D>::Release(%p): deleting self", This);
    delete This;
  }
  return r;
}

template <class D>
WIDirectInputDevice8W<D>::WIDirectInputDevice8W(LPVOID pNative) : BIDirectInputDevice8W(pNative, &vtbl_, false)
{}


/* IDirectInput... */
/* WIDirectInput7A */
class BIDirectInput7A;
struct VIDirectInput7A
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(BIDirectInput7A* This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(BIDirectInput7A* This);
  ULONG (WINAPI *Release)(BIDirectInput7A* This);
  /*** IDirectInputA methods ***/
  HRESULT (WINAPI *CreateDevice)(BIDirectInput7A* This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(BIDirectInput7A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(BIDirectInput7A* This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(BIDirectInput7A* This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(BIDirectInput7A* This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2A methods ***/
  HRESULT (WINAPI *FindDevice)(BIDirectInput7A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  /*** IDirectInput7A methods ***/
  HRESULT (WINAPI *CreateDeviceEx)(BIDirectInput7A* This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter);
};

class BIDirectInput7A
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(BIDirectInput7A* This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(BIDirectInput7A* This);
  static ULONG WINAPI Release(BIDirectInput7A* This);
  /*** IDirectInputA methods ***/
  static HRESULT WINAPI CreateDevice(BIDirectInput7A* This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(BIDirectInput7A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(BIDirectInput7A* This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(BIDirectInput7A* This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(BIDirectInput7A* This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2A methods ***/
  static HRESULT WINAPI FindDevice(BIDirectInput7A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  /*** IDirectInput7A methods ***/
  static HRESULT WINAPI CreateDeviceEx(BIDirectInput7A* This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter);

  BIDirectInput7A(LPVOID pNative, VIDirectInput7A const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput7A();

private:
  VIDirectInput7A const * pVtbl_;
  LPVOID pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput7A : public BIDirectInput7A
{
public:
  static ULONG WINAPI Release(D* This);
  WIDirectInput7A(LPVOID pNative);

private:
  static VIDirectInput7A const vtbl_;
};

template <class D>
VIDirectInput7A const WIDirectInput7A<D>::vtbl_ =
{
  reinterpret_cast<decltype(VIDirectInput7A::QueryInterface)>(&D::QueryInterface),
  reinterpret_cast<decltype(VIDirectInput7A::AddRef)>(&D::AddRef),
  reinterpret_cast<decltype(VIDirectInput7A::Release)>(&D::Release),
  reinterpret_cast<decltype(VIDirectInput7A::CreateDevice)>(&D::CreateDevice),
  reinterpret_cast<decltype(VIDirectInput7A::EnumDevices)>(&D::EnumDevices),
  reinterpret_cast<decltype(VIDirectInput7A::GetDeviceStatus)>(&D::GetDeviceStatus),
  reinterpret_cast<decltype(VIDirectInput7A::RunControlPanel)>(&D::RunControlPanel),
  reinterpret_cast<decltype(VIDirectInput7A::Initialize)>(&D::Initialize),
  reinterpret_cast<decltype(VIDirectInput7A::FindDevice)>(&D::FindDevice),
  reinterpret_cast<decltype(VIDirectInput7A::CreateDeviceEx)>(&D::CreateDeviceEx)
};

template <class D>
ULONG WINAPI WIDirectInput7A<D>::Release(D* This)
{
  ULONG r = BIDirectInput7A::Release(This);
  if (r == 0)
  {
    log_debug("WIDirectInput7A<D>::Release(%p): deleting self", This);
    delete This;
  }
  return r;
}

template <class D>
WIDirectInput7A<D>::WIDirectInput7A(LPVOID pNative) : BIDirectInput7A(pNative, &vtbl_, false)
{}

/* WIDirectInput8A */
class BIDirectInput8A;
struct VIDirectInput8A
{
  HRESULT (WINAPI *QueryInterface)(BIDirectInput8A* This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(BIDirectInput8A* This);
  ULONG (WINAPI *Release)(BIDirectInput8A* This);

  HRESULT (WINAPI *CreateDevice)(BIDirectInput8A* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(BIDirectInput8A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(BIDirectInput8A* This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(BIDirectInput8A* This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(BIDirectInput8A* This, HINSTANCE hinst, DWORD dwVersion);
  HRESULT (WINAPI *FindDevice)(BIDirectInput8A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  HRESULT (WINAPI *EnumDevicesBySemantics)(BIDirectInput8A* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *ConfigureDevices)(BIDirectInput8A* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);
};

class BIDirectInput8A
{
public:
  static HRESULT WINAPI QueryInterface(BIDirectInput8A* This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(BIDirectInput8A* This);
  static ULONG WINAPI Release(BIDirectInput8A* This);

  static HRESULT WINAPI CreateDevice(BIDirectInput8A* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(BIDirectInput8A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(BIDirectInput8A* This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(BIDirectInput8A* This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(BIDirectInput8A* This, HINSTANCE hinst, DWORD dwVersion);
  static HRESULT WINAPI FindDevice(BIDirectInput8A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  static HRESULT WINAPI EnumDevicesBySemantics(BIDirectInput8A* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI ConfigureDevices(BIDirectInput8A* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);

  BIDirectInput8A(LPVOID pNative, VIDirectInput8A const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput8A();

private:
  VIDirectInput8A const * pVtbl_;
  LPVOID pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput8A : public BIDirectInput8A
{
public:
  static ULONG WINAPI Release(D* This);
  WIDirectInput8A(LPVOID pNative);

private:
  static VIDirectInput8A const vtbl_;
};

template <class D>
VIDirectInput8A const WIDirectInput8A<D>::vtbl_ =
{
  reinterpret_cast<decltype(VIDirectInput8A::QueryInterface)>(&D::QueryInterface),
  reinterpret_cast<decltype(VIDirectInput8A::AddRef)>(&D::AddRef),
  reinterpret_cast<decltype(VIDirectInput8A::Release)>(&D::Release),
  reinterpret_cast<decltype(VIDirectInput8A::CreateDevice)>(&D::CreateDevice),
  reinterpret_cast<decltype(VIDirectInput8A::EnumDevices)>(&D::EnumDevices),
  reinterpret_cast<decltype(VIDirectInput8A::GetDeviceStatus)>(&D::GetDeviceStatus),
  reinterpret_cast<decltype(VIDirectInput8A::RunControlPanel)>(&D::RunControlPanel),
  reinterpret_cast<decltype(VIDirectInput8A::Initialize)>(&D::Initialize),
  reinterpret_cast<decltype(VIDirectInput8A::FindDevice)>(&D::FindDevice),
  reinterpret_cast<decltype(VIDirectInput8A::EnumDevicesBySemantics)>(&D::EnumDevicesBySemantics),
  reinterpret_cast<decltype(VIDirectInput8A::ConfigureDevices)>(&D::ConfigureDevices)
};

template <class D>
ULONG WINAPI WIDirectInput8A<D>::Release(D* This)
{
  ULONG r = BIDirectInput8A::Release(This);
  if (r == 0)
  {
    log_debug("WIDirectInput8A<D>::Release(%p): deleting self", This);
    delete This;
  }
  return r;
}

template <class D>
WIDirectInput8A<D>::WIDirectInput8A(LPVOID pNative) : BIDirectInput8A(pNative, &vtbl_, false)
{}


/* WIDirectInput7W */
class BIDirectInput7W;
struct VIDirectInput7W
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(BIDirectInput7W* This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(BIDirectInput7W* This);
  ULONG (WINAPI *Release)(BIDirectInput7W* This);
  /*** IDirectInputW methods ***/
  HRESULT (WINAPI *CreateDevice)(BIDirectInput7W* This, REFGUID rguid, LPDIRECTINPUTDEVICEW *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(BIDirectInput7W* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(BIDirectInput7W* This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(BIDirectInput7W* This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(BIDirectInput7W* This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2W methods ***/
  HRESULT (WINAPI *FindDevice)(BIDirectInput7W* This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance);
  /*** IDirectInput7W methods ***/
  HRESULT (WINAPI *CreateDeviceEx)(BIDirectInput7W* This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter);
};

class BIDirectInput7W
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(BIDirectInput7W* This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(BIDirectInput7W* This);
  static ULONG WINAPI Release(BIDirectInput7W* This);
  /*** IDirectInputW methods ***/
  static HRESULT WINAPI CreateDevice(BIDirectInput7W* This, REFGUID rguid, LPDIRECTINPUTDEVICEW *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(BIDirectInput7W* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(BIDirectInput7W* This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(BIDirectInput7W* This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(BIDirectInput7W* This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2W methods ***/
  static HRESULT WINAPI FindDevice(BIDirectInput7W* This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance);
  /*** IDirectInput7W methods ***/
  static HRESULT WINAPI CreateDeviceEx(BIDirectInput7W* This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter);

  BIDirectInput7W(LPVOID pNative, VIDirectInput7W const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput7W();

private:
  VIDirectInput7W const * pVtbl_;
  LPVOID pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput7W : public BIDirectInput7W
{
public:
  static ULONG WINAPI Release(D* This);
  WIDirectInput7W(LPVOID pNative);

private:
  static VIDirectInput7W const vtbl_;
};

template <class D>
VIDirectInput7W const WIDirectInput7W<D>::vtbl_ =
{
  reinterpret_cast<decltype(VIDirectInput7W::QueryInterface)>(&D::QueryInterface),
  reinterpret_cast<decltype(VIDirectInput7W::AddRef)>(&D::AddRef),
  reinterpret_cast<decltype(VIDirectInput7W::Release)>(&D::Release),
  reinterpret_cast<decltype(VIDirectInput7W::CreateDevice)>(&D::CreateDevice),
  reinterpret_cast<decltype(VIDirectInput7W::EnumDevices)>(&D::EnumDevices),
  reinterpret_cast<decltype(VIDirectInput7W::GetDeviceStatus)>(&D::GetDeviceStatus),
  reinterpret_cast<decltype(VIDirectInput7W::RunControlPanel)>(&D::RunControlPanel),
  reinterpret_cast<decltype(VIDirectInput7W::Initialize)>(&D::Initialize),
  reinterpret_cast<decltype(VIDirectInput7W::FindDevice)>(&D::FindDevice),
  reinterpret_cast<decltype(VIDirectInput7W::CreateDeviceEx)>(&D::CreateDeviceEx)
};

template <class D>
ULONG WINAPI WIDirectInput7W<D>::Release(D* This)
{
  ULONG r = BIDirectInput7W::Release(This);
  if (r == 0)
  {
    log_debug("WIDirectInput7W<D>::Release(%p): deleting self", This);
    delete This;
  }
  return r;
}

template <class D>
WIDirectInput7W<D>::WIDirectInput7W(LPVOID pNative) : BIDirectInput7W(pNative, &vtbl_, false)
{}

/* WIDirectInput8W */
class BIDirectInput8W;
struct VIDirectInput8W
{
  HRESULT (WINAPI *QueryInterface)(BIDirectInput8W* This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(BIDirectInput8W* This);
  ULONG (WINAPI *Release)(BIDirectInput8W* This);

  HRESULT (WINAPI *CreateDevice)(BIDirectInput8W* This, REFGUID rguid, LPDIRECTINPUTDEVICE8W *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(BIDirectInput8W* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(BIDirectInput8W* This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(BIDirectInput8W* This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(BIDirectInput8W* This, HINSTANCE hinst, DWORD dwVersion);
  HRESULT (WINAPI *FindDevice)(BIDirectInput8W* This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance);
  HRESULT (WINAPI *EnumDevicesBySemantics)(BIDirectInput8W* This, LPCWSTR ptszUserName, LPDIACTIONFORMATW lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *ConfigureDevices)(BIDirectInput8W* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSW lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);
};

class BIDirectInput8W
{
public:
  static HRESULT WINAPI QueryInterface(BIDirectInput8W* This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(BIDirectInput8W* This);
  static ULONG WINAPI Release(BIDirectInput8W* This);

  static HRESULT WINAPI CreateDevice(BIDirectInput8W* This, REFGUID rguid, LPDIRECTINPUTDEVICE8W *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(BIDirectInput8W* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(BIDirectInput8W* This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(BIDirectInput8W* This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(BIDirectInput8W* This, HINSTANCE hinst, DWORD dwVersion);
  static HRESULT WINAPI FindDevice(BIDirectInput8W* This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance);
  static HRESULT WINAPI EnumDevicesBySemantics(BIDirectInput8W* This, LPCWSTR ptszUserName, LPDIACTIONFORMATW lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI ConfigureDevices(BIDirectInput8W* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSW lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);

  BIDirectInput8W(LPVOID pNative, VIDirectInput8W const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput8W();

private:
  VIDirectInput8W const * pVtbl_;
  LPVOID pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput8W : public BIDirectInput8W
{
public:
  static ULONG WINAPI Release(D* This);
  WIDirectInput8W(LPVOID pNative);

private:
  static VIDirectInput8W const vtbl_;
};

template <class D>
VIDirectInput8W const WIDirectInput8W<D>::vtbl_ =
{
  reinterpret_cast<decltype(VIDirectInput8W::QueryInterface)>(&D::QueryInterface),
  reinterpret_cast<decltype(VIDirectInput8W::AddRef)>(&D::AddRef),
  reinterpret_cast<decltype(VIDirectInput8W::Release)>(&D::Release),
  reinterpret_cast<decltype(VIDirectInput8W::CreateDevice)>(&D::CreateDevice),
  reinterpret_cast<decltype(VIDirectInput8W::EnumDevices)>(&D::EnumDevices),
  reinterpret_cast<decltype(VIDirectInput8W::GetDeviceStatus)>(&D::GetDeviceStatus),
  reinterpret_cast<decltype(VIDirectInput8W::RunControlPanel)>(&D::RunControlPanel),
  reinterpret_cast<decltype(VIDirectInput8W::Initialize)>(&D::Initialize),
  reinterpret_cast<decltype(VIDirectInput8W::FindDevice)>(&D::FindDevice),
  reinterpret_cast<decltype(VIDirectInput8W::EnumDevicesBySemantics)>(&D::EnumDevicesBySemantics),
  reinterpret_cast<decltype(VIDirectInput8W::ConfigureDevices)>(&D::ConfigureDevices)
};

template <class D>
ULONG WINAPI WIDirectInput8W<D>::Release(D* This)
{
  ULONG r = BIDirectInput8W::Release(This);
  if (r == 0)
  {
    log_debug("WIDirectInput8W<D>::Release(%p): deleting self", This);
    delete This;
  }
  return r;
}

template <class D>
WIDirectInput8W<D>::WIDirectInput8W(LPVOID pNative) : BIDirectInput8W(pNative, &vtbl_, false)
{}

} //namespace di8b

#endif
