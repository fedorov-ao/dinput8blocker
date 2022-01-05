#ifndef DI8B_WRAPPERS_HPP
#define DI8B_WRAPPERS_HPP

#define DIRECTINPUT_VERSION  0x0800
#define CINTERFACE

#include <dinput.h>
#include <di8b_common.hpp>
#pragma pack(1)

namespace di8b
{

struct VIDirectInputDevice8
{
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUTDEVICE8 This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUTDEVICE8 This);
  ULONG (WINAPI *Release)(LPDIRECTINPUTDEVICE8 This);
  HRESULT (WINAPI *GetCapabilities)(LPDIRECTINPUTDEVICE8 This, LPDIDEVCAPS lpDIDevCaps);
  HRESULT (WINAPI *EnumObjects)(LPDIRECTINPUTDEVICE8 This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetProperty)(LPDIRECTINPUTDEVICE8 This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  HRESULT (WINAPI *SetProperty)(LPDIRECTINPUTDEVICE8 This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  HRESULT (WINAPI *Acquire)(LPDIRECTINPUTDEVICE8 This);
  HRESULT (WINAPI *Unacquire)(LPDIRECTINPUTDEVICE8 This);
  HRESULT (WINAPI *GetDeviceState)(LPDIRECTINPUTDEVICE8 This, DWORD cbData, LPVOID lpvData);
  HRESULT (WINAPI *GetDeviceData)(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  HRESULT (WINAPI *SetDataFormat)(LPDIRECTINPUTDEVICE8 This, LPCDIDATAFORMAT lpdf);
  HRESULT (WINAPI *SetEventNotification)(LPDIRECTINPUTDEVICE8 This, HANDLE hEvent);
  HRESULT (WINAPI *SetCooperativeLevel)(LPDIRECTINPUTDEVICE8 This, HWND hwnd, DWORD dwFlags);
  HRESULT (WINAPI *GetObjectInfo)(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  HRESULT (WINAPI *GetDeviceInfo)(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEINSTANCEA pdidi);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUTDEVICE8 This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUTDEVICE8 This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  HRESULT (WINAPI *CreateEffect)(LPDIRECTINPUTDEVICE8 This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  HRESULT (WINAPI *EnumEffects)(LPDIRECTINPUTDEVICE8 This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  HRESULT (WINAPI *GetEffectInfo)(LPDIRECTINPUTDEVICE8 This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  HRESULT (WINAPI *GetForceFeedbackState)(LPDIRECTINPUTDEVICE8 This, LPDWORD pdwOut);
  HRESULT (WINAPI *SendForceFeedbackCommand)(LPDIRECTINPUTDEVICE8 This, DWORD dwFlags);
  HRESULT (WINAPI *EnumCreatedEffectObjects)(LPDIRECTINPUTDEVICE8 This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  HRESULT (WINAPI *Escape)(LPDIRECTINPUTDEVICE8 This, LPDIEFFESCAPE pesc);
  HRESULT (WINAPI *Poll)(LPDIRECTINPUTDEVICE8 This);
  HRESULT (WINAPI *SendDeviceData)(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  HRESULT (WINAPI *EnumEffectsInFile)(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  HRESULT (WINAPI *WriteEffectToFile)(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  HRESULT (WINAPI *BuildActionMap)(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *SetActionMap)(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *GetImageInfo)(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader);

  VIDirectInputDevice8();
};

class CIDirectInputDevice8;

class WIDirectInputDevice8
{
public:
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUTDEVICE8 This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUTDEVICE8 This);
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE8 This);
  static HRESULT WINAPI GetCapabilities(LPDIRECTINPUTDEVICE8 This, LPDIDEVCAPS lpDIDevCaps);
  static HRESULT WINAPI EnumObjects(LPDIRECTINPUTDEVICE8 This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetProperty(LPDIRECTINPUTDEVICE8 This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  static HRESULT WINAPI SetProperty(LPDIRECTINPUTDEVICE8 This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  static HRESULT WINAPI Acquire(LPDIRECTINPUTDEVICE8 This);
  static HRESULT WINAPI Unacquire(LPDIRECTINPUTDEVICE8 This);
  static HRESULT WINAPI GetDeviceState(LPDIRECTINPUTDEVICE8 This, DWORD cbData, LPVOID lpvData);
  static HRESULT WINAPI GetDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  static HRESULT WINAPI SetDataFormat(LPDIRECTINPUTDEVICE8 This, LPCDIDATAFORMAT lpdf);
  static HRESULT WINAPI SetEventNotification(LPDIRECTINPUTDEVICE8 This, HANDLE hEvent);
  static HRESULT WINAPI SetCooperativeLevel(LPDIRECTINPUTDEVICE8 This, HWND hwnd, DWORD dwFlags);
  static HRESULT WINAPI GetObjectInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  static HRESULT WINAPI GetDeviceInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEINSTANCEA pdidi);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUTDEVICE8 This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUTDEVICE8 This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  static HRESULT WINAPI CreateEffect(LPDIRECTINPUTDEVICE8 This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  static HRESULT WINAPI EnumEffects(LPDIRECTINPUTDEVICE8 This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  static HRESULT WINAPI GetEffectInfo(LPDIRECTINPUTDEVICE8 This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  static HRESULT WINAPI GetForceFeedbackState(LPDIRECTINPUTDEVICE8 This, LPDWORD pdwOut);
  static HRESULT WINAPI SendForceFeedbackCommand(LPDIRECTINPUTDEVICE8 This, DWORD dwFlags);
  static HRESULT WINAPI EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE8 This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  static HRESULT WINAPI Escape(LPDIRECTINPUTDEVICE8 This, LPDIEFFESCAPE pesc);
  static HRESULT WINAPI Poll(LPDIRECTINPUTDEVICE8 This);
  static HRESULT WINAPI SendDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  static HRESULT WINAPI EnumEffectsInFile(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  static HRESULT WINAPI WriteEffectToFile(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  static HRESULT WINAPI BuildActionMap(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI SetActionMap(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI GetImageInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader);

  WIDirectInputDevice8(LPDIRECTINPUTDEVICE8 pNative, CIDirectInputDevice8* pCallback);

private:
  static VIDirectInputDevice8 const vIDirectInputDevice8;

  VIDirectInputDevice8 const * const pVtbl_;
  LPDIRECTINPUTDEVICE8 pNative_;
  CIDirectInputDevice8* pCallback_;
};

class CIDirectInputDevice8
{
public:
  virtual HRESULT QueryInterface(LPDIRECTINPUTDEVICE8 This, REFIID riid, void** ppvObject);
  virtual ULONG AddRef(LPDIRECTINPUTDEVICE8 This);
  virtual ULONG Release(LPDIRECTINPUTDEVICE8 This);
  virtual HRESULT GetCapabilities(LPDIRECTINPUTDEVICE8 This, LPDIDEVCAPS lpDIDevCaps);
  virtual HRESULT EnumObjects(LPDIRECTINPUTDEVICE8 This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  virtual HRESULT GetProperty(LPDIRECTINPUTDEVICE8 This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  virtual HRESULT SetProperty(LPDIRECTINPUTDEVICE8 This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  virtual HRESULT Acquire(LPDIRECTINPUTDEVICE8 This);
  virtual HRESULT Unacquire(LPDIRECTINPUTDEVICE8 This);
  virtual HRESULT GetDeviceState(LPDIRECTINPUTDEVICE8 This, DWORD cbData, LPVOID lpvData);
  virtual HRESULT GetDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  virtual HRESULT SetDataFormat(LPDIRECTINPUTDEVICE8 This, LPCDIDATAFORMAT lpdf);
  virtual HRESULT SetEventNotification(LPDIRECTINPUTDEVICE8 This, HANDLE hEvent);
  virtual HRESULT SetCooperativeLevel(LPDIRECTINPUTDEVICE8 This, HWND hwnd, DWORD dwFlags);
  virtual HRESULT GetObjectInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  virtual HRESULT GetDeviceInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEINSTANCEA pdidi);
  virtual HRESULT RunControlPanel(LPDIRECTINPUTDEVICE8 This, HWND hwndOwner, DWORD dwFlags);
  virtual HRESULT Initialize(LPDIRECTINPUTDEVICE8 This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  virtual HRESULT CreateEffect(LPDIRECTINPUTDEVICE8 This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  virtual HRESULT EnumEffects(LPDIRECTINPUTDEVICE8 This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  virtual HRESULT GetEffectInfo(LPDIRECTINPUTDEVICE8 This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  virtual HRESULT GetForceFeedbackState(LPDIRECTINPUTDEVICE8 This, LPDWORD pdwOut);
  virtual HRESULT SendForceFeedbackCommand(LPDIRECTINPUTDEVICE8 This, DWORD dwFlags);
  virtual HRESULT EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE8 This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  virtual HRESULT Escape(LPDIRECTINPUTDEVICE8 This, LPDIEFFESCAPE pesc);
  virtual HRESULT Poll(LPDIRECTINPUTDEVICE8 This);
  virtual HRESULT SendDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  virtual HRESULT EnumEffectsInFile(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  virtual HRESULT WriteEffectToFile(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  virtual HRESULT BuildActionMap(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  virtual HRESULT SetActionMap(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  virtual HRESULT GetImageInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader);

  virtual ~CIDirectInputDevice8();
};

struct VIDirectInput8
{
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUT8 This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUT8 This);
  ULONG (WINAPI *Release)(LPDIRECTINPUT8 This);

  HRESULT (WINAPI *CreateDevice)(LPDIRECTINPUT8 This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(LPDIRECTINPUT8 This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(LPDIRECTINPUT8 This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUT8 This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUT8 This, HINSTANCE hinst, DWORD dwVersion);
  HRESULT (WINAPI *FindDevice)(LPDIRECTINPUT8 This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  HRESULT (WINAPI *EnumDevicesBySemantics)(LPDIRECTINPUT8 This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *ConfigureDevices)(LPDIRECTINPUT8 This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);

  VIDirectInput8();
};

class CIDirectInput8;

class WIDirectInput8
{
public:
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUT8 This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUT8 This);
  static ULONG WINAPI Release(LPDIRECTINPUT8 This);

  static HRESULT WINAPI CreateDevice(LPDIRECTINPUT8 This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(LPDIRECTINPUT8 This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(LPDIRECTINPUT8 This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUT8 This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUT8 This, HINSTANCE hinst, DWORD dwVersion);
  static HRESULT WINAPI FindDevice(LPDIRECTINPUT8 This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  static HRESULT WINAPI EnumDevicesBySemantics(LPDIRECTINPUT8 This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI ConfigureDevices(LPDIRECTINPUT8 This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);

  WIDirectInput8(LPDIRECTINPUT8 pNative, CIDirectInput8* pCallback);

private:
  static VIDirectInput8 const vIDirectInput8;

  VIDirectInput8 const * const pVtbl_;
  LPDIRECTINPUT8 pNative_;
  CIDirectInput8* pCallback_;
};

class CIDirectInput8
{
public:
  virtual HRESULT QueryInterface(LPDIRECTINPUT8 This, REFIID riid, void** ppvObject);
  virtual ULONG AddRef(LPDIRECTINPUT8 This);
  virtual ULONG Release(LPDIRECTINPUT8 This);

  virtual HRESULT CreateDevice(LPDIRECTINPUT8 This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  virtual HRESULT EnumDevices(LPDIRECTINPUT8 This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  virtual HRESULT GetDeviceStatus(LPDIRECTINPUT8 This, REFGUID rguidInstance);
  virtual HRESULT RunControlPanel(LPDIRECTINPUT8 This, HWND hwndOwner, DWORD dwFlags);
  virtual HRESULT Initialize(LPDIRECTINPUT8 This, HINSTANCE hinst, DWORD dwVersion);
  virtual HRESULT FindDevice(LPDIRECTINPUT8 This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  virtual HRESULT EnumDevicesBySemantics(LPDIRECTINPUT8 This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags);
  virtual HRESULT ConfigureDevices(LPDIRECTINPUT8 This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);
  
  virtual ~CIDirectInput8();
};


/* Templates */
/* IDirectInputDevice... */
/* WIDirectInputDeviceA */
struct VIDirectInputDeviceA
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUTDEVICEA This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUTDEVICEA This);
  ULONG (WINAPI *Release)(LPDIRECTINPUTDEVICEA This);
  /*** IDirectInputDeviceA methods ***/
  HRESULT (WINAPI *GetCapabilities)(LPDIRECTINPUTDEVICEA This, LPDIDEVCAPS lpDIDevCaps);
  HRESULT (WINAPI *EnumObjects)(LPDIRECTINPUTDEVICEA This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetProperty)(LPDIRECTINPUTDEVICEA This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  HRESULT (WINAPI *SetProperty)(LPDIRECTINPUTDEVICEA This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  HRESULT (WINAPI *Acquire)(LPDIRECTINPUTDEVICEA This);
  HRESULT (WINAPI *Unacquire)(LPDIRECTINPUTDEVICEA This);
  HRESULT (WINAPI *GetDeviceState)(LPDIRECTINPUTDEVICEA This, DWORD cbData, LPVOID lpvData);
  HRESULT (WINAPI *GetDeviceData)(LPDIRECTINPUTDEVICEA This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  HRESULT (WINAPI *SetDataFormat)(LPDIRECTINPUTDEVICEA This, LPCDIDATAFORMAT lpdf);
  HRESULT (WINAPI *SetEventNotification)(LPDIRECTINPUTDEVICEA This, HANDLE hEvent);
  HRESULT (WINAPI *SetCooperativeLevel)(LPDIRECTINPUTDEVICEA This, HWND hwnd, DWORD dwFlags);
  HRESULT (WINAPI *GetObjectInfo)(LPDIRECTINPUTDEVICEA This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  HRESULT (WINAPI *GetDeviceInfo)(LPDIRECTINPUTDEVICEA This, LPDIDEVICEINSTANCEA pdidi);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUTDEVICEA This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUTDEVICEA This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
};

class BIDirectInputDeviceA
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUTDEVICEA This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUTDEVICEA This);
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICEA This);
  /*** IDirectInputDeviceA methods ***/
  static HRESULT WINAPI GetCapabilities(LPDIRECTINPUTDEVICEA This, LPDIDEVCAPS lpDIDevCaps);
  static HRESULT WINAPI EnumObjects(LPDIRECTINPUTDEVICEA This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetProperty(LPDIRECTINPUTDEVICEA This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  static HRESULT WINAPI SetProperty(LPDIRECTINPUTDEVICEA This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  static HRESULT WINAPI Acquire(LPDIRECTINPUTDEVICEA This);
  static HRESULT WINAPI Unacquire(LPDIRECTINPUTDEVICEA This);
  static HRESULT WINAPI GetDeviceState(LPDIRECTINPUTDEVICEA This, DWORD cbData, LPVOID lpvData);
  static HRESULT WINAPI GetDeviceData(LPDIRECTINPUTDEVICEA This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  static HRESULT WINAPI SetDataFormat(LPDIRECTINPUTDEVICEA This, LPCDIDATAFORMAT lpdf);
  static HRESULT WINAPI SetEventNotification(LPDIRECTINPUTDEVICEA This, HANDLE hEvent);
  static HRESULT WINAPI SetCooperativeLevel(LPDIRECTINPUTDEVICEA This, HWND hwnd, DWORD dwFlags);
  static HRESULT WINAPI GetObjectInfo(LPDIRECTINPUTDEVICEA This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  static HRESULT WINAPI GetDeviceInfo(LPDIRECTINPUTDEVICEA This, LPDIDEVICEINSTANCEA pdidi);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUTDEVICEA This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUTDEVICEA This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);

  BIDirectInputDeviceA(LPDIRECTINPUTDEVICEA pNative, VIDirectInputDeviceA const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputDeviceA();

private:
  static VIDirectInputDeviceA const vtbl_;

  VIDirectInputDeviceA const * pVtbl_;
  LPDIRECTINPUTDEVICEA pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputDeviceA : public BIDirectInputDeviceA
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICEA This);
  WIDirectInputDeviceA(LPDIRECTINPUTDEVICEA pNative);

private:
  static VIDirectInputDeviceA const vtbl_;
};

template <class D>
VIDirectInputDeviceA const WIDirectInputDeviceA<D>::vtbl_ =
{
  /*** IUnknown methods ***/
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  /*** IDirectInputDeviceA methods ***/
  &D::GetCapabilities,
  &D::EnumObjects,
  &D::GetProperty,
  &D::SetProperty,
  &D::Acquire,
  &D::Unacquire,
  &D::GetDeviceState,
  &D::GetDeviceData,
  &D::SetDataFormat,
  &D::SetEventNotification,
  &D::SetCooperativeLevel,
  &D::GetObjectInfo,
  &D::GetDeviceInfo,
  &D::RunControlPanel,
  &D::Initialize
};

template <class D>
ULONG WINAPI WIDirectInputDeviceA<D>::Release(LPDIRECTINPUTDEVICEA This)
{
  ULONG r = BIDirectInputDeviceA::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInputDeviceA<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInputDeviceA<D>::WIDirectInputDeviceA(LPDIRECTINPUTDEVICEA pNative) : BIDirectInputDeviceA(pNative, &vtbl_, false)
{}

/* WIDirectInputDevice2A */
struct VIDirectInputDevice2A
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUTDEVICE2A This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUTDEVICE2A This);
  ULONG (WINAPI *Release)(LPDIRECTINPUTDEVICE2A This);
  /*** IDirectInputDeviceA methods ***/
  HRESULT (WINAPI *GetCapabilities)(LPDIRECTINPUTDEVICE2A This, LPDIDEVCAPS lpDIDevCaps);
  HRESULT (WINAPI *EnumObjects)(LPDIRECTINPUTDEVICE2A This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetProperty)(LPDIRECTINPUTDEVICE2A This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  HRESULT (WINAPI *SetProperty)(LPDIRECTINPUTDEVICE2A This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  HRESULT (WINAPI *Acquire)(LPDIRECTINPUTDEVICE2A This);
  HRESULT (WINAPI *Unacquire)(LPDIRECTINPUTDEVICE2A This);
  HRESULT (WINAPI *GetDeviceState)(LPDIRECTINPUTDEVICE2A This, DWORD cbData, LPVOID lpvData);
  HRESULT (WINAPI *GetDeviceData)(LPDIRECTINPUTDEVICE2A This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  HRESULT (WINAPI *SetDataFormat)(LPDIRECTINPUTDEVICE2A This, LPCDIDATAFORMAT lpdf);
  HRESULT (WINAPI *SetEventNotification)(LPDIRECTINPUTDEVICE2A This, HANDLE hEvent);
  HRESULT (WINAPI *SetCooperativeLevel)(LPDIRECTINPUTDEVICE2A This, HWND hwnd, DWORD dwFlags);
  HRESULT (WINAPI *GetObjectInfo)(LPDIRECTINPUTDEVICE2A This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  HRESULT (WINAPI *GetDeviceInfo)(LPDIRECTINPUTDEVICE2A This, LPDIDEVICEINSTANCEA pdidi);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUTDEVICE2A This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUTDEVICE2A This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2A methods ***/
  HRESULT (WINAPI *CreateEffect)(LPDIRECTINPUTDEVICE2A This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  HRESULT (WINAPI *EnumEffects)(LPDIRECTINPUTDEVICE2A This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  HRESULT (WINAPI *GetEffectInfo)(LPDIRECTINPUTDEVICE2A This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  HRESULT (WINAPI *GetForceFeedbackState)(LPDIRECTINPUTDEVICE2A This, LPDWORD pdwOut);
  HRESULT (WINAPI *SendForceFeedbackCommand)(LPDIRECTINPUTDEVICE2A This, DWORD dwFlags);
  HRESULT (WINAPI *EnumCreatedEffectObjects)(LPDIRECTINPUTDEVICE2A This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  HRESULT (WINAPI *Escape)(LPDIRECTINPUTDEVICE2A This, LPDIEFFESCAPE pesc);
  HRESULT (WINAPI *Poll)(LPDIRECTINPUTDEVICE2A This);
  HRESULT (WINAPI *SendDeviceData)(LPDIRECTINPUTDEVICE2A This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
};

class BIDirectInputDevice2A
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUTDEVICE2A This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUTDEVICE2A This);
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE2A This);
  /*** IDirectInputDeviceA methods ***/
  static HRESULT WINAPI GetCapabilities(LPDIRECTINPUTDEVICE2A This, LPDIDEVCAPS lpDIDevCaps);
  static HRESULT WINAPI EnumObjects(LPDIRECTINPUTDEVICE2A This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetProperty(LPDIRECTINPUTDEVICE2A This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  static HRESULT WINAPI SetProperty(LPDIRECTINPUTDEVICE2A This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  static HRESULT WINAPI Acquire(LPDIRECTINPUTDEVICE2A This);
  static HRESULT WINAPI Unacquire(LPDIRECTINPUTDEVICE2A This);
  static HRESULT WINAPI GetDeviceState(LPDIRECTINPUTDEVICE2A This, DWORD cbData, LPVOID lpvData);
  static HRESULT WINAPI GetDeviceData(LPDIRECTINPUTDEVICE2A This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  static HRESULT WINAPI SetDataFormat(LPDIRECTINPUTDEVICE2A This, LPCDIDATAFORMAT lpdf);
  static HRESULT WINAPI SetEventNotification(LPDIRECTINPUTDEVICE2A This, HANDLE hEvent);
  static HRESULT WINAPI SetCooperativeLevel(LPDIRECTINPUTDEVICE2A This, HWND hwnd, DWORD dwFlags);
  static HRESULT WINAPI GetObjectInfo(LPDIRECTINPUTDEVICE2A This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  static HRESULT WINAPI GetDeviceInfo(LPDIRECTINPUTDEVICE2A This, LPDIDEVICEINSTANCEA pdidi);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUTDEVICE2A This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUTDEVICE2A This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2A methods ***/
  static HRESULT WINAPI CreateEffect(LPDIRECTINPUTDEVICE2A This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  static HRESULT WINAPI EnumEffects(LPDIRECTINPUTDEVICE2A This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  static HRESULT WINAPI GetEffectInfo(LPDIRECTINPUTDEVICE2A This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  static HRESULT WINAPI GetForceFeedbackState(LPDIRECTINPUTDEVICE2A This, LPDWORD pdwOut);
  static HRESULT WINAPI SendForceFeedbackCommand(LPDIRECTINPUTDEVICE2A This, DWORD dwFlags);
  static HRESULT WINAPI EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE2A This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  static HRESULT WINAPI Escape(LPDIRECTINPUTDEVICE2A This, LPDIEFFESCAPE pesc);
  static HRESULT WINAPI Poll(LPDIRECTINPUTDEVICE2A This);
  static HRESULT WINAPI SendDeviceData(LPDIRECTINPUTDEVICE2A This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);

  BIDirectInputDevice2A(LPDIRECTINPUTDEVICE2A pNative, VIDirectInputDevice2A const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputDevice2A();

private:
  static VIDirectInputDevice2A const vtbl_;

  VIDirectInputDevice2A const * pVtbl_;
  LPDIRECTINPUTDEVICE2A pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputDevice2A : public BIDirectInputDevice2A
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE2A This);
  WIDirectInputDevice2A(LPDIRECTINPUTDEVICE2A pNative);

private:
  static VIDirectInputDevice2A const vtbl_;
};

template <class D>
VIDirectInputDevice2A const WIDirectInputDevice2A<D>::vtbl_ =
{
  /*** IUnknown methods ***/
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  /*** IDirectInputDeviceA methods ***/
  &D::GetCapabilities,
  &D::EnumObjects,
  &D::GetProperty,
  &D::SetProperty,
  &D::Acquire,
  &D::Unacquire,
  &D::GetDeviceState,
  &D::GetDeviceData,
  &D::SetDataFormat,
  &D::SetEventNotification,
  &D::SetCooperativeLevel,
  &D::GetObjectInfo,
  &D::GetDeviceInfo,
  &D::RunControlPanel,
  &D::Initialize,
  /*** IDirectInputDevice2A methods ***/
  &D::CreateEffect,
  &D::EnumEffects,
  &D::GetEffectInfo,
  &D::GetForceFeedbackState,
  &D::SendForceFeedbackCommand,
  &D::EnumCreatedEffectObjects,
  &D::Escape,
  &D::Poll,
  &D::SendDeviceData
};

template <class D>
ULONG WINAPI WIDirectInputDevice2A<D>::Release(LPDIRECTINPUTDEVICE2A This)
{
  ULONG r = BIDirectInputDevice2A::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInputDevice2A<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInputDevice2A<D>::WIDirectInputDevice2A(LPDIRECTINPUTDEVICE2A pNative) : BIDirectInputDevice2A(pNative, &vtbl_, false)
{}

/* WIDirectInputDevice7A */
struct VIDirectInputDevice7A
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUTDEVICE7A This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUTDEVICE7A This);
  ULONG (WINAPI *Release)(LPDIRECTINPUTDEVICE7A This);
  /*** IDirectInputDeviceA methods ***/
  HRESULT (WINAPI *GetCapabilities)(LPDIRECTINPUTDEVICE7A This, LPDIDEVCAPS lpDIDevCaps);
  HRESULT (WINAPI *EnumObjects)(LPDIRECTINPUTDEVICE7A This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetProperty)(LPDIRECTINPUTDEVICE7A This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  HRESULT (WINAPI *SetProperty)(LPDIRECTINPUTDEVICE7A This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  HRESULT (WINAPI *Acquire)(LPDIRECTINPUTDEVICE7A This);
  HRESULT (WINAPI *Unacquire)(LPDIRECTINPUTDEVICE7A This);
  HRESULT (WINAPI *GetDeviceState)(LPDIRECTINPUTDEVICE7A This, DWORD cbData, LPVOID lpvData);
  HRESULT (WINAPI *GetDeviceData)(LPDIRECTINPUTDEVICE7A This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  HRESULT (WINAPI *SetDataFormat)(LPDIRECTINPUTDEVICE7A This, LPCDIDATAFORMAT lpdf);
  HRESULT (WINAPI *SetEventNotification)(LPDIRECTINPUTDEVICE7A This, HANDLE hEvent);
  HRESULT (WINAPI *SetCooperativeLevel)(LPDIRECTINPUTDEVICE7A This, HWND hwnd, DWORD dwFlags);
  HRESULT (WINAPI *GetObjectInfo)(LPDIRECTINPUTDEVICE7A This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  HRESULT (WINAPI *GetDeviceInfo)(LPDIRECTINPUTDEVICE7A This, LPDIDEVICEINSTANCEA pdidi);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUTDEVICE7A This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUTDEVICE7A This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2A methods ***/
  HRESULT (WINAPI *CreateEffect)(LPDIRECTINPUTDEVICE7A This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  HRESULT (WINAPI *EnumEffects)(LPDIRECTINPUTDEVICE7A This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  HRESULT (WINAPI *GetEffectInfo)(LPDIRECTINPUTDEVICE7A This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  HRESULT (WINAPI *GetForceFeedbackState)(LPDIRECTINPUTDEVICE7A This, LPDWORD pdwOut);
  HRESULT (WINAPI *SendForceFeedbackCommand)(LPDIRECTINPUTDEVICE7A This, DWORD dwFlags);
  HRESULT (WINAPI *EnumCreatedEffectObjects)(LPDIRECTINPUTDEVICE7A This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  HRESULT (WINAPI *Escape)(LPDIRECTINPUTDEVICE7A This, LPDIEFFESCAPE pesc);
  HRESULT (WINAPI *Poll)(LPDIRECTINPUTDEVICE7A This);
  HRESULT (WINAPI *SendDeviceData)(LPDIRECTINPUTDEVICE7A This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7A methods ***/
  HRESULT (WINAPI *EnumEffectsInFile)(LPDIRECTINPUTDEVICE7A This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  HRESULT (WINAPI *WriteEffectToFile)(LPDIRECTINPUTDEVICE7A This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
};

class BIDirectInputDevice7A
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUTDEVICE7A This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUTDEVICE7A This);
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE7A This);
  /*** IDirectInputDeviceA methods ***/
  static HRESULT WINAPI GetCapabilities(LPDIRECTINPUTDEVICE7A This, LPDIDEVCAPS lpDIDevCaps);
  static HRESULT WINAPI EnumObjects(LPDIRECTINPUTDEVICE7A This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetProperty(LPDIRECTINPUTDEVICE7A This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  static HRESULT WINAPI SetProperty(LPDIRECTINPUTDEVICE7A This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  static HRESULT WINAPI Acquire(LPDIRECTINPUTDEVICE7A This);
  static HRESULT WINAPI Unacquire(LPDIRECTINPUTDEVICE7A This);
  static HRESULT WINAPI GetDeviceState(LPDIRECTINPUTDEVICE7A This, DWORD cbData, LPVOID lpvData);
  static HRESULT WINAPI GetDeviceData(LPDIRECTINPUTDEVICE7A This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  static HRESULT WINAPI SetDataFormat(LPDIRECTINPUTDEVICE7A This, LPCDIDATAFORMAT lpdf);
  static HRESULT WINAPI SetEventNotification(LPDIRECTINPUTDEVICE7A This, HANDLE hEvent);
  static HRESULT WINAPI SetCooperativeLevel(LPDIRECTINPUTDEVICE7A This, HWND hwnd, DWORD dwFlags);
  static HRESULT WINAPI GetObjectInfo(LPDIRECTINPUTDEVICE7A This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  static HRESULT WINAPI GetDeviceInfo(LPDIRECTINPUTDEVICE7A This, LPDIDEVICEINSTANCEA pdidi);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUTDEVICE7A This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUTDEVICE7A This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2A methods ***/
  static HRESULT WINAPI CreateEffect(LPDIRECTINPUTDEVICE7A This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  static HRESULT WINAPI EnumEffects(LPDIRECTINPUTDEVICE7A This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  static HRESULT WINAPI GetEffectInfo(LPDIRECTINPUTDEVICE7A This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  static HRESULT WINAPI GetForceFeedbackState(LPDIRECTINPUTDEVICE7A This, LPDWORD pdwOut);
  static HRESULT WINAPI SendForceFeedbackCommand(LPDIRECTINPUTDEVICE7A This, DWORD dwFlags);
  static HRESULT WINAPI EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE7A This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  static HRESULT WINAPI Escape(LPDIRECTINPUTDEVICE7A This, LPDIEFFESCAPE pesc);
  static HRESULT WINAPI Poll(LPDIRECTINPUTDEVICE7A This);
  static HRESULT WINAPI SendDeviceData(LPDIRECTINPUTDEVICE7A This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7A methods ***/
  static HRESULT WINAPI EnumEffectsInFile(LPDIRECTINPUTDEVICE7A This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  static HRESULT WINAPI WriteEffectToFile(LPDIRECTINPUTDEVICE7A This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);

  BIDirectInputDevice7A(LPDIRECTINPUTDEVICE7A pNative, VIDirectInputDevice7A const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputDevice7A();

private:
  static VIDirectInputDevice7A const vtbl_;

  VIDirectInputDevice7A const * pVtbl_;
  LPDIRECTINPUTDEVICE7A pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputDevice7A : public BIDirectInputDevice7A
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE7A This);
  WIDirectInputDevice7A(LPDIRECTINPUTDEVICE7A pNative);

private:
  static VIDirectInputDevice7A const vtbl_;
};

template <class D>
VIDirectInputDevice7A const WIDirectInputDevice7A<D>::vtbl_ =
{
  /*** IUnknown methods ***/
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  /*** IDirectInputDeviceA methods ***/
  &D::GetCapabilities,
  &D::EnumObjects,
  &D::GetProperty,
  &D::SetProperty,
  &D::Acquire,
  &D::Unacquire,
  &D::GetDeviceState,
  &D::GetDeviceData,
  &D::SetDataFormat,
  &D::SetEventNotification,
  &D::SetCooperativeLevel,
  &D::GetObjectInfo,
  &D::GetDeviceInfo,
  &D::RunControlPanel,
  &D::Initialize,
  /*** IDirectInputDevice2A methods ***/
  &D::CreateEffect,
  &D::EnumEffects,
  &D::GetEffectInfo,
  &D::GetForceFeedbackState,
  &D::SendForceFeedbackCommand,
  &D::EnumCreatedEffectObjects,
  &D::Escape,
  &D::Poll,
  &D::SendDeviceData,
  /*** IDirectInputDevice7A methods ***/
  &D::EnumEffectsInFile,
  &D::WriteEffectToFile
};

template <class D>
ULONG WINAPI WIDirectInputDevice7A<D>::Release(LPDIRECTINPUTDEVICE7A This)
{
  ULONG r = BIDirectInputDevice7A::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInputDevice7A<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInputDevice7A<D>::WIDirectInputDevice7A(LPDIRECTINPUTDEVICE7A pNative) : BIDirectInputDevice7A(pNative, &vtbl_, false)
{}

/* WIDirectInputDevice8A */
struct VIDirectInputDevice8A
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUTDEVICE8A This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUTDEVICE8A This);
  ULONG (WINAPI *Release)(LPDIRECTINPUTDEVICE8A This);
  /*** IDirectInputDeviceA methods ***/
  HRESULT (WINAPI *GetCapabilities)(LPDIRECTINPUTDEVICE8A This, LPDIDEVCAPS lpDIDevCaps);
  HRESULT (WINAPI *EnumObjects)(LPDIRECTINPUTDEVICE8A This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetProperty)(LPDIRECTINPUTDEVICE8A This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  HRESULT (WINAPI *SetProperty)(LPDIRECTINPUTDEVICE8A This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  HRESULT (WINAPI *Acquire)(LPDIRECTINPUTDEVICE8A This);
  HRESULT (WINAPI *Unacquire)(LPDIRECTINPUTDEVICE8A This);
  HRESULT (WINAPI *GetDeviceState)(LPDIRECTINPUTDEVICE8A This, DWORD cbData, LPVOID lpvData);
  HRESULT (WINAPI *GetDeviceData)(LPDIRECTINPUTDEVICE8A This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  HRESULT (WINAPI *SetDataFormat)(LPDIRECTINPUTDEVICE8A This, LPCDIDATAFORMAT lpdf);
  HRESULT (WINAPI *SetEventNotification)(LPDIRECTINPUTDEVICE8A This, HANDLE hEvent);
  HRESULT (WINAPI *SetCooperativeLevel)(LPDIRECTINPUTDEVICE8A This, HWND hwnd, DWORD dwFlags);
  HRESULT (WINAPI *GetObjectInfo)(LPDIRECTINPUTDEVICE8A This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  HRESULT (WINAPI *GetDeviceInfo)(LPDIRECTINPUTDEVICE8A This, LPDIDEVICEINSTANCEA pdidi);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUTDEVICE8A This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUTDEVICE8A This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2A methods ***/
  HRESULT (WINAPI *CreateEffect)(LPDIRECTINPUTDEVICE8A This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  HRESULT (WINAPI *EnumEffects)(LPDIRECTINPUTDEVICE8A This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  HRESULT (WINAPI *GetEffectInfo)(LPDIRECTINPUTDEVICE8A This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  HRESULT (WINAPI *GetForceFeedbackState)(LPDIRECTINPUTDEVICE8A This, LPDWORD pdwOut);
  HRESULT (WINAPI *SendForceFeedbackCommand)(LPDIRECTINPUTDEVICE8A This, DWORD dwFlags);
  HRESULT (WINAPI *EnumCreatedEffectObjects)(LPDIRECTINPUTDEVICE8A This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  HRESULT (WINAPI *Escape)(LPDIRECTINPUTDEVICE8A This, LPDIEFFESCAPE pesc);
  HRESULT (WINAPI *Poll)(LPDIRECTINPUTDEVICE8A This);
  HRESULT (WINAPI *SendDeviceData)(LPDIRECTINPUTDEVICE8A This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7A methods ***/
  HRESULT (WINAPI *EnumEffectsInFile)(LPDIRECTINPUTDEVICE8A This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  HRESULT (WINAPI *WriteEffectToFile)(LPDIRECTINPUTDEVICE8A This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  /*** IDirectInputDevice8A methods ***/
  HRESULT (WINAPI *BuildActionMap)(LPDIRECTINPUTDEVICE8A This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *SetActionMap)(LPDIRECTINPUTDEVICE8A This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *GetImageInfo)(LPDIRECTINPUTDEVICE8A This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader);
};

class BIDirectInputDevice8A
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUTDEVICE8A This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUTDEVICE8A This);
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE8A This);
  /*** IDirectInputDeviceA methods ***/
  static HRESULT WINAPI GetCapabilities(LPDIRECTINPUTDEVICE8A This, LPDIDEVCAPS lpDIDevCaps);
  static HRESULT WINAPI EnumObjects(LPDIRECTINPUTDEVICE8A This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetProperty(LPDIRECTINPUTDEVICE8A This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  static HRESULT WINAPI SetProperty(LPDIRECTINPUTDEVICE8A This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  static HRESULT WINAPI Acquire(LPDIRECTINPUTDEVICE8A This);
  static HRESULT WINAPI Unacquire(LPDIRECTINPUTDEVICE8A This);
  static HRESULT WINAPI GetDeviceState(LPDIRECTINPUTDEVICE8A This, DWORD cbData, LPVOID lpvData);
  static HRESULT WINAPI GetDeviceData(LPDIRECTINPUTDEVICE8A This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  static HRESULT WINAPI SetDataFormat(LPDIRECTINPUTDEVICE8A This, LPCDIDATAFORMAT lpdf);
  static HRESULT WINAPI SetEventNotification(LPDIRECTINPUTDEVICE8A This, HANDLE hEvent);
  static HRESULT WINAPI SetCooperativeLevel(LPDIRECTINPUTDEVICE8A This, HWND hwnd, DWORD dwFlags);
  static HRESULT WINAPI GetObjectInfo(LPDIRECTINPUTDEVICE8A This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  static HRESULT WINAPI GetDeviceInfo(LPDIRECTINPUTDEVICE8A This, LPDIDEVICEINSTANCEA pdidi);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUTDEVICE8A This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUTDEVICE8A This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2A methods ***/
  static HRESULT WINAPI CreateEffect(LPDIRECTINPUTDEVICE8A This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  static HRESULT WINAPI EnumEffects(LPDIRECTINPUTDEVICE8A This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  static HRESULT WINAPI GetEffectInfo(LPDIRECTINPUTDEVICE8A This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  static HRESULT WINAPI GetForceFeedbackState(LPDIRECTINPUTDEVICE8A This, LPDWORD pdwOut);
  static HRESULT WINAPI SendForceFeedbackCommand(LPDIRECTINPUTDEVICE8A This, DWORD dwFlags);
  static HRESULT WINAPI EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE8A This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  static HRESULT WINAPI Escape(LPDIRECTINPUTDEVICE8A This, LPDIEFFESCAPE pesc);
  static HRESULT WINAPI Poll(LPDIRECTINPUTDEVICE8A This);
  static HRESULT WINAPI SendDeviceData(LPDIRECTINPUTDEVICE8A This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7A methods ***/
  static HRESULT WINAPI EnumEffectsInFile(LPDIRECTINPUTDEVICE8A This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  static HRESULT WINAPI WriteEffectToFile(LPDIRECTINPUTDEVICE8A This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  /*** IDirectInputDevice8A methods ***/
  static HRESULT WINAPI BuildActionMap(LPDIRECTINPUTDEVICE8A This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI SetActionMap(LPDIRECTINPUTDEVICE8A This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI GetImageInfo(LPDIRECTINPUTDEVICE8A This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader);

  BIDirectInputDevice8A(LPDIRECTINPUTDEVICE8A pNative, VIDirectInputDevice8A const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputDevice8A();

private:
  static VIDirectInputDevice8A const vtbl_;

  VIDirectInputDevice8A const * pVtbl_;
  LPDIRECTINPUTDEVICE8A pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputDevice8A : public BIDirectInputDevice8A
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE8A This);
  WIDirectInputDevice8A(LPDIRECTINPUTDEVICE8A pNative);

private:
  static VIDirectInputDevice8A const vtbl_;
};

template <class D>
VIDirectInputDevice8A const WIDirectInputDevice8A<D>::vtbl_ =
{
  /*** IUnknown methods ***/
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  /*** IDirectInputDeviceA methods ***/
  &D::GetCapabilities,
  &D::EnumObjects,
  &D::GetProperty,
  &D::SetProperty,
  &D::Acquire,
  &D::Unacquire,
  &D::GetDeviceState,
  &D::GetDeviceData,
  &D::SetDataFormat,
  &D::SetEventNotification,
  &D::SetCooperativeLevel,
  &D::GetObjectInfo,
  &D::GetDeviceInfo,
  &D::RunControlPanel,
  &D::Initialize,
  /*** IDirectInputDevice2A methods ***/
  &D::CreateEffect,
  &D::EnumEffects,
  &D::GetEffectInfo,
  &D::GetForceFeedbackState,
  &D::SendForceFeedbackCommand,
  &D::EnumCreatedEffectObjects,
  &D::Escape,
  &D::Poll,
  &D::SendDeviceData,
  /*** IDirectInputDevice7A methods ***/
  &D::EnumEffectsInFile,
  &D::WriteEffectToFile,
  /*** IDirectInputDevice8A methods ***/
  &D::BuildActionMap,
  &D::SetActionMap,
  &D::GetImageInfo
};

template <class D>
ULONG WINAPI WIDirectInputDevice8A<D>::Release(LPDIRECTINPUTDEVICE8A This)
{
  ULONG r = BIDirectInputDevice8A::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInputDevice8A<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInputDevice8A<D>::WIDirectInputDevice8A(LPDIRECTINPUTDEVICE8A pNative) : BIDirectInputDevice8A(pNative, &vtbl_, false)
{}


/* WIDirectInputDeviceW */
struct VIDirectInputDeviceW
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUTDEVICEW This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUTDEVICEW This);
  ULONG (WINAPI *Release)(LPDIRECTINPUTDEVICEW This);
  /*** IDirectInputDeviceW methods ***/
  HRESULT (WINAPI *GetCapabilities)(LPDIRECTINPUTDEVICEW This, LPDIDEVCAPS lpDIDevCaps);
  HRESULT (WINAPI *EnumObjects)(LPDIRECTINPUTDEVICEW This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetProperty)(LPDIRECTINPUTDEVICEW This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  HRESULT (WINAPI *SetProperty)(LPDIRECTINPUTDEVICEW This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  HRESULT (WINAPI *Acquire)(LPDIRECTINPUTDEVICEW This);
  HRESULT (WINAPI *Unacquire)(LPDIRECTINPUTDEVICEW This);
  HRESULT (WINAPI *GetDeviceState)(LPDIRECTINPUTDEVICEW This, DWORD cbData, LPVOID lpvData);
  HRESULT (WINAPI *GetDeviceData)(LPDIRECTINPUTDEVICEW This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  HRESULT (WINAPI *SetDataFormat)(LPDIRECTINPUTDEVICEW This, LPCDIDATAFORMAT lpdf);
  HRESULT (WINAPI *SetEventNotification)(LPDIRECTINPUTDEVICEW This, HANDLE hEvent);
  HRESULT (WINAPI *SetCooperativeLevel)(LPDIRECTINPUTDEVICEW This, HWND hwnd, DWORD dwFlags);
  HRESULT (WINAPI *GetObjectInfo)(LPDIRECTINPUTDEVICEW This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow);
  HRESULT (WINAPI *GetDeviceInfo)(LPDIRECTINPUTDEVICEW This, LPDIDEVICEINSTANCEW pdidi);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUTDEVICEW This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUTDEVICEW This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
};

class BIDirectInputDeviceW
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUTDEVICEW This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUTDEVICEW This);
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICEW This);
  /*** IDirectInputDeviceW methods ***/
  static HRESULT WINAPI GetCapabilities(LPDIRECTINPUTDEVICEW This, LPDIDEVCAPS lpDIDevCaps);
  static HRESULT WINAPI EnumObjects(LPDIRECTINPUTDEVICEW This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetProperty(LPDIRECTINPUTDEVICEW This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  static HRESULT WINAPI SetProperty(LPDIRECTINPUTDEVICEW This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  static HRESULT WINAPI Acquire(LPDIRECTINPUTDEVICEW This);
  static HRESULT WINAPI Unacquire(LPDIRECTINPUTDEVICEW This);
  static HRESULT WINAPI GetDeviceState(LPDIRECTINPUTDEVICEW This, DWORD cbData, LPVOID lpvData);
  static HRESULT WINAPI GetDeviceData(LPDIRECTINPUTDEVICEW This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  static HRESULT WINAPI SetDataFormat(LPDIRECTINPUTDEVICEW This, LPCDIDATAFORMAT lpdf);
  static HRESULT WINAPI SetEventNotification(LPDIRECTINPUTDEVICEW This, HANDLE hEvent);
  static HRESULT WINAPI SetCooperativeLevel(LPDIRECTINPUTDEVICEW This, HWND hwnd, DWORD dwFlags);
  static HRESULT WINAPI GetObjectInfo(LPDIRECTINPUTDEVICEW This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow);
  static HRESULT WINAPI GetDeviceInfo(LPDIRECTINPUTDEVICEW This, LPDIDEVICEINSTANCEW pdidi);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUTDEVICEW This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUTDEVICEW This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);

  BIDirectInputDeviceW(LPDIRECTINPUTDEVICEW pNative, VIDirectInputDeviceW const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputDeviceW();

private:
  static VIDirectInputDeviceW const vtbl_;

  VIDirectInputDeviceW const * pVtbl_;
  LPDIRECTINPUTDEVICEW pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputDeviceW : public BIDirectInputDeviceW
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICEW This);
  WIDirectInputDeviceW(LPDIRECTINPUTDEVICEW pNative);

private:
  static VIDirectInputDeviceW const vtbl_;
};

template <class D>
VIDirectInputDeviceW const WIDirectInputDeviceW<D>::vtbl_ =
{
  /*** IUnknown methods ***/
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  /*** IDirectInputDeviceW methods ***/
  &D::GetCapabilities,
  &D::EnumObjects,
  &D::GetProperty,
  &D::SetProperty,
  &D::Acquire,
  &D::Unacquire,
  &D::GetDeviceState,
  &D::GetDeviceData,
  &D::SetDataFormat,
  &D::SetEventNotification,
  &D::SetCooperativeLevel,
  &D::GetObjectInfo,
  &D::GetDeviceInfo,
  &D::RunControlPanel,
  &D::Initialize
};

template <class D>
ULONG WINAPI WIDirectInputDeviceW<D>::Release(LPDIRECTINPUTDEVICEW This)
{
  ULONG r = BIDirectInputDeviceW::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInputDeviceW<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInputDeviceW<D>::WIDirectInputDeviceW(LPDIRECTINPUTDEVICEW pNative) : BIDirectInputDeviceW(pNative, &vtbl_, false)
{}

/* WIDirectInputDevice2W */
struct VIDirectInputDevice2W
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUTDEVICE2W This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUTDEVICE2W This);
  ULONG (WINAPI *Release)(LPDIRECTINPUTDEVICE2W This);
  /*** IDirectInputDeviceW methods ***/
  HRESULT (WINAPI *GetCapabilities)(LPDIRECTINPUTDEVICE2W This, LPDIDEVCAPS lpDIDevCaps);
  HRESULT (WINAPI *EnumObjects)(LPDIRECTINPUTDEVICE2W This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetProperty)(LPDIRECTINPUTDEVICE2W This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  HRESULT (WINAPI *SetProperty)(LPDIRECTINPUTDEVICE2W This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  HRESULT (WINAPI *Acquire)(LPDIRECTINPUTDEVICE2W This);
  HRESULT (WINAPI *Unacquire)(LPDIRECTINPUTDEVICE2W This);
  HRESULT (WINAPI *GetDeviceState)(LPDIRECTINPUTDEVICE2W This, DWORD cbData, LPVOID lpvData);
  HRESULT (WINAPI *GetDeviceData)(LPDIRECTINPUTDEVICE2W This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  HRESULT (WINAPI *SetDataFormat)(LPDIRECTINPUTDEVICE2W This, LPCDIDATAFORMAT lpdf);
  HRESULT (WINAPI *SetEventNotification)(LPDIRECTINPUTDEVICE2W This, HANDLE hEvent);
  HRESULT (WINAPI *SetCooperativeLevel)(LPDIRECTINPUTDEVICE2W This, HWND hwnd, DWORD dwFlags);
  HRESULT (WINAPI *GetObjectInfo)(LPDIRECTINPUTDEVICE2W This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow);
  HRESULT (WINAPI *GetDeviceInfo)(LPDIRECTINPUTDEVICE2W This, LPDIDEVICEINSTANCEW pdidi);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUTDEVICE2W This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUTDEVICE2W This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2W methods ***/
  HRESULT (WINAPI *CreateEffect)(LPDIRECTINPUTDEVICE2W This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  HRESULT (WINAPI *EnumEffects)(LPDIRECTINPUTDEVICE2W This, LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType);
  HRESULT (WINAPI *GetEffectInfo)(LPDIRECTINPUTDEVICE2W This, LPDIEFFECTINFOW pdei, REFGUID rguid);
  HRESULT (WINAPI *GetForceFeedbackState)(LPDIRECTINPUTDEVICE2W This, LPDWORD pdwOut);
  HRESULT (WINAPI *SendForceFeedbackCommand)(LPDIRECTINPUTDEVICE2W This, DWORD dwFlags);
  HRESULT (WINAPI *EnumCreatedEffectObjects)(LPDIRECTINPUTDEVICE2W This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  HRESULT (WINAPI *Escape)(LPDIRECTINPUTDEVICE2W This, LPDIEFFESCAPE pesc);
  HRESULT (WINAPI *Poll)(LPDIRECTINPUTDEVICE2W This);
  HRESULT (WINAPI *SendDeviceData)(LPDIRECTINPUTDEVICE2W This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
};

class BIDirectInputDevice2W
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUTDEVICE2W This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUTDEVICE2W This);
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE2W This);
  /*** IDirectInputDeviceW methods ***/
  static HRESULT WINAPI GetCapabilities(LPDIRECTINPUTDEVICE2W This, LPDIDEVCAPS lpDIDevCaps);
  static HRESULT WINAPI EnumObjects(LPDIRECTINPUTDEVICE2W This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetProperty(LPDIRECTINPUTDEVICE2W This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  static HRESULT WINAPI SetProperty(LPDIRECTINPUTDEVICE2W This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  static HRESULT WINAPI Acquire(LPDIRECTINPUTDEVICE2W This);
  static HRESULT WINAPI Unacquire(LPDIRECTINPUTDEVICE2W This);
  static HRESULT WINAPI GetDeviceState(LPDIRECTINPUTDEVICE2W This, DWORD cbData, LPVOID lpvData);
  static HRESULT WINAPI GetDeviceData(LPDIRECTINPUTDEVICE2W This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  static HRESULT WINAPI SetDataFormat(LPDIRECTINPUTDEVICE2W This, LPCDIDATAFORMAT lpdf);
  static HRESULT WINAPI SetEventNotification(LPDIRECTINPUTDEVICE2W This, HANDLE hEvent);
  static HRESULT WINAPI SetCooperativeLevel(LPDIRECTINPUTDEVICE2W This, HWND hwnd, DWORD dwFlags);
  static HRESULT WINAPI GetObjectInfo(LPDIRECTINPUTDEVICE2W This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow);
  static HRESULT WINAPI GetDeviceInfo(LPDIRECTINPUTDEVICE2W This, LPDIDEVICEINSTANCEW pdidi);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUTDEVICE2W This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUTDEVICE2W This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2W methods ***/
  static HRESULT WINAPI CreateEffect(LPDIRECTINPUTDEVICE2W This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  static HRESULT WINAPI EnumEffects(LPDIRECTINPUTDEVICE2W This, LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType);
  static HRESULT WINAPI GetEffectInfo(LPDIRECTINPUTDEVICE2W This, LPDIEFFECTINFOW pdei, REFGUID rguid);
  static HRESULT WINAPI GetForceFeedbackState(LPDIRECTINPUTDEVICE2W This, LPDWORD pdwOut);
  static HRESULT WINAPI SendForceFeedbackCommand(LPDIRECTINPUTDEVICE2W This, DWORD dwFlags);
  static HRESULT WINAPI EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE2W This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  static HRESULT WINAPI Escape(LPDIRECTINPUTDEVICE2W This, LPDIEFFESCAPE pesc);
  static HRESULT WINAPI Poll(LPDIRECTINPUTDEVICE2W This);
  static HRESULT WINAPI SendDeviceData(LPDIRECTINPUTDEVICE2W This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);

  BIDirectInputDevice2W(LPDIRECTINPUTDEVICE2W pNative, VIDirectInputDevice2W const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputDevice2W();

private:
  static VIDirectInputDevice2W const vtbl_;

  VIDirectInputDevice2W const * pVtbl_;
  LPDIRECTINPUTDEVICE2W pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputDevice2W : public BIDirectInputDevice2W
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE2W This);
  WIDirectInputDevice2W(LPDIRECTINPUTDEVICE2W pNative);

private:
  static VIDirectInputDevice2W const vtbl_;
};

template <class D>
VIDirectInputDevice2W const WIDirectInputDevice2W<D>::vtbl_ =
{
  /*** IUnknown methods ***/
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  /*** IDirectInputDeviceW methods ***/
  &D::GetCapabilities,
  &D::EnumObjects,
  &D::GetProperty,
  &D::SetProperty,
  &D::Acquire,
  &D::Unacquire,
  &D::GetDeviceState,
  &D::GetDeviceData,
  &D::SetDataFormat,
  &D::SetEventNotification,
  &D::SetCooperativeLevel,
  &D::GetObjectInfo,
  &D::GetDeviceInfo,
  &D::RunControlPanel,
  &D::Initialize,
  /*** IDirectInputDevice2W methods ***/
  &D::CreateEffect,
  &D::EnumEffects,
  &D::GetEffectInfo,
  &D::GetForceFeedbackState,
  &D::SendForceFeedbackCommand,
  &D::EnumCreatedEffectObjects,
  &D::Escape,
  &D::Poll,
  &D::SendDeviceData
};

template <class D>
ULONG WINAPI WIDirectInputDevice2W<D>::Release(LPDIRECTINPUTDEVICE2W This)
{
  ULONG r = BIDirectInputDevice2W::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInputDevice2W<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInputDevice2W<D>::WIDirectInputDevice2W(LPDIRECTINPUTDEVICE2W pNative) : BIDirectInputDevice2W(pNative, &vtbl_, false)
{}

/* WIDirectInputDevice7W */
struct VIDirectInputDevice7W
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUTDEVICE7W This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUTDEVICE7W This);
  ULONG (WINAPI *Release)(LPDIRECTINPUTDEVICE7W This);
  /*** IDirectInputDeviceW methods ***/
  HRESULT (WINAPI *GetCapabilities)(LPDIRECTINPUTDEVICE7W This, LPDIDEVCAPS lpDIDevCaps);
  HRESULT (WINAPI *EnumObjects)(LPDIRECTINPUTDEVICE7W This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetProperty)(LPDIRECTINPUTDEVICE7W This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  HRESULT (WINAPI *SetProperty)(LPDIRECTINPUTDEVICE7W This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  HRESULT (WINAPI *Acquire)(LPDIRECTINPUTDEVICE7W This);
  HRESULT (WINAPI *Unacquire)(LPDIRECTINPUTDEVICE7W This);
  HRESULT (WINAPI *GetDeviceState)(LPDIRECTINPUTDEVICE7W This, DWORD cbData, LPVOID lpvData);
  HRESULT (WINAPI *GetDeviceData)(LPDIRECTINPUTDEVICE7W This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  HRESULT (WINAPI *SetDataFormat)(LPDIRECTINPUTDEVICE7W This, LPCDIDATAFORMAT lpdf);
  HRESULT (WINAPI *SetEventNotification)(LPDIRECTINPUTDEVICE7W This, HANDLE hEvent);
  HRESULT (WINAPI *SetCooperativeLevel)(LPDIRECTINPUTDEVICE7W This, HWND hwnd, DWORD dwFlags);
  HRESULT (WINAPI *GetObjectInfo)(LPDIRECTINPUTDEVICE7W This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow);
  HRESULT (WINAPI *GetDeviceInfo)(LPDIRECTINPUTDEVICE7W This, LPDIDEVICEINSTANCEW pdidi);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUTDEVICE7W This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUTDEVICE7W This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2W methods ***/
  HRESULT (WINAPI *CreateEffect)(LPDIRECTINPUTDEVICE7W This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  HRESULT (WINAPI *EnumEffects)(LPDIRECTINPUTDEVICE7W This, LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType);
  HRESULT (WINAPI *GetEffectInfo)(LPDIRECTINPUTDEVICE7W This, LPDIEFFECTINFOW pdei, REFGUID rguid);
  HRESULT (WINAPI *GetForceFeedbackState)(LPDIRECTINPUTDEVICE7W This, LPDWORD pdwOut);
  HRESULT (WINAPI *SendForceFeedbackCommand)(LPDIRECTINPUTDEVICE7W This, DWORD dwFlags);
  HRESULT (WINAPI *EnumCreatedEffectObjects)(LPDIRECTINPUTDEVICE7W This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  HRESULT (WINAPI *Escape)(LPDIRECTINPUTDEVICE7W This, LPDIEFFESCAPE pesc);
  HRESULT (WINAPI *Poll)(LPDIRECTINPUTDEVICE7W This);
  HRESULT (WINAPI *SendDeviceData)(LPDIRECTINPUTDEVICE7W This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7W methods ***/
  HRESULT (WINAPI *EnumEffectsInFile)(LPDIRECTINPUTDEVICE7W This, LPCWSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  HRESULT (WINAPI *WriteEffectToFile)(LPDIRECTINPUTDEVICE7W This, LPCWSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
};

class BIDirectInputDevice7W
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUTDEVICE7W This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUTDEVICE7W This);
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE7W This);
  /*** IDirectInputDeviceW methods ***/
  static HRESULT WINAPI GetCapabilities(LPDIRECTINPUTDEVICE7W This, LPDIDEVCAPS lpDIDevCaps);
  static HRESULT WINAPI EnumObjects(LPDIRECTINPUTDEVICE7W This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetProperty(LPDIRECTINPUTDEVICE7W This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  static HRESULT WINAPI SetProperty(LPDIRECTINPUTDEVICE7W This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  static HRESULT WINAPI Acquire(LPDIRECTINPUTDEVICE7W This);
  static HRESULT WINAPI Unacquire(LPDIRECTINPUTDEVICE7W This);
  static HRESULT WINAPI GetDeviceState(LPDIRECTINPUTDEVICE7W This, DWORD cbData, LPVOID lpvData);
  static HRESULT WINAPI GetDeviceData(LPDIRECTINPUTDEVICE7W This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  static HRESULT WINAPI SetDataFormat(LPDIRECTINPUTDEVICE7W This, LPCDIDATAFORMAT lpdf);
  static HRESULT WINAPI SetEventNotification(LPDIRECTINPUTDEVICE7W This, HANDLE hEvent);
  static HRESULT WINAPI SetCooperativeLevel(LPDIRECTINPUTDEVICE7W This, HWND hwnd, DWORD dwFlags);
  static HRESULT WINAPI GetObjectInfo(LPDIRECTINPUTDEVICE7W This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow);
  static HRESULT WINAPI GetDeviceInfo(LPDIRECTINPUTDEVICE7W This, LPDIDEVICEINSTANCEW pdidi);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUTDEVICE7W This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUTDEVICE7W This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2W methods ***/
  static HRESULT WINAPI CreateEffect(LPDIRECTINPUTDEVICE7W This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  static HRESULT WINAPI EnumEffects(LPDIRECTINPUTDEVICE7W This, LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType);
  static HRESULT WINAPI GetEffectInfo(LPDIRECTINPUTDEVICE7W This, LPDIEFFECTINFOW pdei, REFGUID rguid);
  static HRESULT WINAPI GetForceFeedbackState(LPDIRECTINPUTDEVICE7W This, LPDWORD pdwOut);
  static HRESULT WINAPI SendForceFeedbackCommand(LPDIRECTINPUTDEVICE7W This, DWORD dwFlags);
  static HRESULT WINAPI EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE7W This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  static HRESULT WINAPI Escape(LPDIRECTINPUTDEVICE7W This, LPDIEFFESCAPE pesc);
  static HRESULT WINAPI Poll(LPDIRECTINPUTDEVICE7W This);
  static HRESULT WINAPI SendDeviceData(LPDIRECTINPUTDEVICE7W This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7W methods ***/
  static HRESULT WINAPI EnumEffectsInFile(LPDIRECTINPUTDEVICE7W This, LPCWSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  static HRESULT WINAPI WriteEffectToFile(LPDIRECTINPUTDEVICE7W This, LPCWSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);

  BIDirectInputDevice7W(LPDIRECTINPUTDEVICE7W pNative, VIDirectInputDevice7W const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputDevice7W();

private:
  static VIDirectInputDevice7W const vtbl_;

  VIDirectInputDevice7W const * pVtbl_;
  LPDIRECTINPUTDEVICE7W pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputDevice7W : public BIDirectInputDevice7W
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE7W This);
  WIDirectInputDevice7W(LPDIRECTINPUTDEVICE7W pNative);

private:
  static VIDirectInputDevice7W const vtbl_;
};

template <class D>
VIDirectInputDevice7W const WIDirectInputDevice7W<D>::vtbl_ =
{
  /*** IUnknown methods ***/
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  /*** IDirectInputDeviceW methods ***/
  &D::GetCapabilities,
  &D::EnumObjects,
  &D::GetProperty,
  &D::SetProperty,
  &D::Acquire,
  &D::Unacquire,
  &D::GetDeviceState,
  &D::GetDeviceData,
  &D::SetDataFormat,
  &D::SetEventNotification,
  &D::SetCooperativeLevel,
  &D::GetObjectInfo,
  &D::GetDeviceInfo,
  &D::RunControlPanel,
  &D::Initialize,
  /*** IDirectInputDevice2W methods ***/
  &D::CreateEffect,
  &D::EnumEffects,
  &D::GetEffectInfo,
  &D::GetForceFeedbackState,
  &D::SendForceFeedbackCommand,
  &D::EnumCreatedEffectObjects,
  &D::Escape,
  &D::Poll,
  &D::SendDeviceData,
  /*** IDirectInputDevice7W methods ***/
  &D::EnumEffectsInFile,
  &D::WriteEffectToFile
};

template <class D>
ULONG WINAPI WIDirectInputDevice7W<D>::Release(LPDIRECTINPUTDEVICE7W This)
{
  ULONG r = BIDirectInputDevice7W::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInputDevice7W<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInputDevice7W<D>::WIDirectInputDevice7W(LPDIRECTINPUTDEVICE7W pNative) : BIDirectInputDevice7W(pNative, &vtbl_, false)
{}

/* WIDirectInputDevice8W */
struct VIDirectInputDevice8W
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUTDEVICE8W This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUTDEVICE8W This);
  ULONG (WINAPI *Release)(LPDIRECTINPUTDEVICE8W This);
  /*** IDirectInputDeviceW methods ***/
  HRESULT (WINAPI *GetCapabilities)(LPDIRECTINPUTDEVICE8W This, LPDIDEVCAPS lpDIDevCaps);
  HRESULT (WINAPI *EnumObjects)(LPDIRECTINPUTDEVICE8W This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetProperty)(LPDIRECTINPUTDEVICE8W This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  HRESULT (WINAPI *SetProperty)(LPDIRECTINPUTDEVICE8W This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  HRESULT (WINAPI *Acquire)(LPDIRECTINPUTDEVICE8W This);
  HRESULT (WINAPI *Unacquire)(LPDIRECTINPUTDEVICE8W This);
  HRESULT (WINAPI *GetDeviceState)(LPDIRECTINPUTDEVICE8W This, DWORD cbData, LPVOID lpvData);
  HRESULT (WINAPI *GetDeviceData)(LPDIRECTINPUTDEVICE8W This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  HRESULT (WINAPI *SetDataFormat)(LPDIRECTINPUTDEVICE8W This, LPCDIDATAFORMAT lpdf);
  HRESULT (WINAPI *SetEventNotification)(LPDIRECTINPUTDEVICE8W This, HANDLE hEvent);
  HRESULT (WINAPI *SetCooperativeLevel)(LPDIRECTINPUTDEVICE8W This, HWND hwnd, DWORD dwFlags);
  HRESULT (WINAPI *GetObjectInfo)(LPDIRECTINPUTDEVICE8W This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow);
  HRESULT (WINAPI *GetDeviceInfo)(LPDIRECTINPUTDEVICE8W This, LPDIDEVICEINSTANCEW pdidi);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUTDEVICE8W This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUTDEVICE8W This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2W methods ***/
  HRESULT (WINAPI *CreateEffect)(LPDIRECTINPUTDEVICE8W This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  HRESULT (WINAPI *EnumEffects)(LPDIRECTINPUTDEVICE8W This, LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType);
  HRESULT (WINAPI *GetEffectInfo)(LPDIRECTINPUTDEVICE8W This, LPDIEFFECTINFOW pdei, REFGUID rguid);
  HRESULT (WINAPI *GetForceFeedbackState)(LPDIRECTINPUTDEVICE8W This, LPDWORD pdwOut);
  HRESULT (WINAPI *SendForceFeedbackCommand)(LPDIRECTINPUTDEVICE8W This, DWORD dwFlags);
  HRESULT (WINAPI *EnumCreatedEffectObjects)(LPDIRECTINPUTDEVICE8W This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  HRESULT (WINAPI *Escape)(LPDIRECTINPUTDEVICE8W This, LPDIEFFESCAPE pesc);
  HRESULT (WINAPI *Poll)(LPDIRECTINPUTDEVICE8W This);
  HRESULT (WINAPI *SendDeviceData)(LPDIRECTINPUTDEVICE8W This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7W methods ***/
  HRESULT (WINAPI *EnumEffectsInFile)(LPDIRECTINPUTDEVICE8W This, LPCWSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  HRESULT (WINAPI *WriteEffectToFile)(LPDIRECTINPUTDEVICE8W This, LPCWSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  /*** IDirectInputDevice8W methods ***/
  HRESULT (WINAPI *BuildActionMap)(LPDIRECTINPUTDEVICE8W This, LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *SetActionMap)(LPDIRECTINPUTDEVICE8W This, LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *GetImageInfo)(LPDIRECTINPUTDEVICE8W This, LPDIDEVICEIMAGEINFOHEADERW lpdiDevImageInfoHeader);
};

class BIDirectInputDevice8W
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUTDEVICE8W This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUTDEVICE8W This);
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE8W This);
  /*** IDirectInputDeviceW methods ***/
  static HRESULT WINAPI GetCapabilities(LPDIRECTINPUTDEVICE8W This, LPDIDEVCAPS lpDIDevCaps);
  static HRESULT WINAPI EnumObjects(LPDIRECTINPUTDEVICE8W This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetProperty(LPDIRECTINPUTDEVICE8W This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  static HRESULT WINAPI SetProperty(LPDIRECTINPUTDEVICE8W This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  static HRESULT WINAPI Acquire(LPDIRECTINPUTDEVICE8W This);
  static HRESULT WINAPI Unacquire(LPDIRECTINPUTDEVICE8W This);
  static HRESULT WINAPI GetDeviceState(LPDIRECTINPUTDEVICE8W This, DWORD cbData, LPVOID lpvData);
  static HRESULT WINAPI GetDeviceData(LPDIRECTINPUTDEVICE8W This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  static HRESULT WINAPI SetDataFormat(LPDIRECTINPUTDEVICE8W This, LPCDIDATAFORMAT lpdf);
  static HRESULT WINAPI SetEventNotification(LPDIRECTINPUTDEVICE8W This, HANDLE hEvent);
  static HRESULT WINAPI SetCooperativeLevel(LPDIRECTINPUTDEVICE8W This, HWND hwnd, DWORD dwFlags);
  static HRESULT WINAPI GetObjectInfo(LPDIRECTINPUTDEVICE8W This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow);
  static HRESULT WINAPI GetDeviceInfo(LPDIRECTINPUTDEVICE8W This, LPDIDEVICEINSTANCEW pdidi);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUTDEVICE8W This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUTDEVICE8W This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  /*** IDirectInputDevice2W methods ***/
  static HRESULT WINAPI CreateEffect(LPDIRECTINPUTDEVICE8W This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  static HRESULT WINAPI EnumEffects(LPDIRECTINPUTDEVICE8W This, LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType);
  static HRESULT WINAPI GetEffectInfo(LPDIRECTINPUTDEVICE8W This, LPDIEFFECTINFOW pdei, REFGUID rguid);
  static HRESULT WINAPI GetForceFeedbackState(LPDIRECTINPUTDEVICE8W This, LPDWORD pdwOut);
  static HRESULT WINAPI SendForceFeedbackCommand(LPDIRECTINPUTDEVICE8W This, DWORD dwFlags);
  static HRESULT WINAPI EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE8W This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  static HRESULT WINAPI Escape(LPDIRECTINPUTDEVICE8W This, LPDIEFFESCAPE pesc);
  static HRESULT WINAPI Poll(LPDIRECTINPUTDEVICE8W This);
  static HRESULT WINAPI SendDeviceData(LPDIRECTINPUTDEVICE8W This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7W methods ***/
  static HRESULT WINAPI EnumEffectsInFile(LPDIRECTINPUTDEVICE8W This, LPCWSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  static HRESULT WINAPI WriteEffectToFile(LPDIRECTINPUTDEVICE8W This, LPCWSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  /*** IDirectInputDevice8W methods ***/
  static HRESULT WINAPI BuildActionMap(LPDIRECTINPUTDEVICE8W This, LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI SetActionMap(LPDIRECTINPUTDEVICE8W This, LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI GetImageInfo(LPDIRECTINPUTDEVICE8W This, LPDIDEVICEIMAGEINFOHEADERW lpdiDevImageInfoHeader);

  BIDirectInputDevice8W(LPDIRECTINPUTDEVICE8W pNative, VIDirectInputDevice8W const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputDevice8W();

private:
  static VIDirectInputDevice8W const vtbl_;

  VIDirectInputDevice8W const * pVtbl_;
  LPDIRECTINPUTDEVICE8W pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputDevice8W : public BIDirectInputDevice8W
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE8W This);
  WIDirectInputDevice8W(LPDIRECTINPUTDEVICE8W pNative);

private:
  static VIDirectInputDevice8W const vtbl_;
};

template <class D>
VIDirectInputDevice8W const WIDirectInputDevice8W<D>::vtbl_ =
{
  /*** IUnknown methods ***/
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  /*** IDirectInputDeviceW methods ***/
  &D::GetCapabilities,
  &D::EnumObjects,
  &D::GetProperty,
  &D::SetProperty,
  &D::Acquire,
  &D::Unacquire,
  &D::GetDeviceState,
  &D::GetDeviceData,
  &D::SetDataFormat,
  &D::SetEventNotification,
  &D::SetCooperativeLevel,
  &D::GetObjectInfo,
  &D::GetDeviceInfo,
  &D::RunControlPanel,
  &D::Initialize,
  /*** IDirectInputDevice2W methods ***/
  &D::CreateEffect,
  &D::EnumEffects,
  &D::GetEffectInfo,
  &D::GetForceFeedbackState,
  &D::SendForceFeedbackCommand,
  &D::EnumCreatedEffectObjects,
  &D::Escape,
  &D::Poll,
  &D::SendDeviceData,
  /*** IDirectInputDevice7W methods ***/
  &D::EnumEffectsInFile,
  &D::WriteEffectToFile,
  /*** IDirectInputDevice8W methods ***/
  &D::BuildActionMap,
  &D::SetActionMap,
  &D::GetImageInfo
};

template <class D>
ULONG WINAPI WIDirectInputDevice8W<D>::Release(LPDIRECTINPUTDEVICE8W This)
{
  ULONG r = BIDirectInputDevice8W::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInputDevice8W<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInputDevice8W<D>::WIDirectInputDevice8W(LPDIRECTINPUTDEVICE8W pNative) : BIDirectInputDevice8W(pNative, &vtbl_, false)
{}


/* IDirectInput... */
/* WIDirectInputA */
struct VIDirectInputA
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUTA This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUTA This);
  ULONG (WINAPI *Release)(LPDIRECTINPUTA This);
  /*** IDirectInputA methods ***/
  HRESULT (WINAPI *CreateDevice)(LPDIRECTINPUTA This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(LPDIRECTINPUTA This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(LPDIRECTINPUTA This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUTA This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUTA This, HINSTANCE hinst, DWORD dwVersion);
};

class BIDirectInputA
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUTA This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUTA This);
  static ULONG WINAPI Release(LPDIRECTINPUTA This);
  /*** IDirectInputA methods ***/
  static HRESULT WINAPI CreateDevice(LPDIRECTINPUTA This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(LPDIRECTINPUTA This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(LPDIRECTINPUTA This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUTA This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUTA This, HINSTANCE hinst, DWORD dwVersion);

  BIDirectInputA(LPDIRECTINPUTA pNative, VIDirectInputA const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputA();

private:
  static VIDirectInputA const vtbl_;

  VIDirectInputA const * pVtbl_;
  LPDIRECTINPUTA pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputA : public BIDirectInputA
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUTA This);
  WIDirectInputA(LPDIRECTINPUTA pNative);

private:
  static VIDirectInputA const vtbl_;
};

template <class D>
VIDirectInputA const WIDirectInputA<D>::vtbl_ =
{
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  &D::CreateDevice,
  &D::EnumDevices,
  &D::GetDeviceStatus,
  &D::RunControlPanel,
  &D::Initialize
};

template <class D>
ULONG WINAPI WIDirectInputA<D>::Release(LPDIRECTINPUTA This)
{
  ULONG r = BIDirectInputA::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInputA<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInputA<D>::WIDirectInputA(LPDIRECTINPUTA pNative) : BIDirectInputA(pNative, &vtbl_, false)
{}

/* WIDirectInput2A */
struct VIDirectInput2A
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUT2A This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUT2A This);
  ULONG (WINAPI *Release)(LPDIRECTINPUT2A This);
  /*** IDirectInputA methods ***/
  HRESULT (WINAPI *CreateDevice)(LPDIRECTINPUT2A This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(LPDIRECTINPUT2A This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(LPDIRECTINPUT2A This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUT2A This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUT2A This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2A methods ***/
  HRESULT (WINAPI *FindDevice)(LPDIRECTINPUT2A This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
};

class BIDirectInput2A
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUT2A This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUT2A This);
  static ULONG WINAPI Release(LPDIRECTINPUT2A This);
  /*** IDirectInputA methods ***/
  static HRESULT WINAPI CreateDevice(LPDIRECTINPUT2A This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(LPDIRECTINPUT2A This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(LPDIRECTINPUT2A This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUT2A This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUT2A This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2A methods ***/
  static HRESULT WINAPI FindDevice(LPDIRECTINPUT2A This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);

  BIDirectInput2A(LPDIRECTINPUT2A pNative, VIDirectInput2A const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput2A();

private:
  static VIDirectInput2A const vtbl_;

  VIDirectInput2A const * pVtbl_;
  LPDIRECTINPUT2A pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput2A : public BIDirectInput2A
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUT2A This);
  WIDirectInput2A(LPDIRECTINPUT2A pNative);

private:
  static VIDirectInput2A const vtbl_;
};

template <class D>
VIDirectInput2A const WIDirectInput2A<D>::vtbl_ =
{
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  &D::CreateDevice,
  &D::EnumDevices,
  &D::GetDeviceStatus,
  &D::RunControlPanel,
  &D::Initialize,
  &D::FindDevice
};

template <class D>
ULONG WINAPI WIDirectInput2A<D>::Release(LPDIRECTINPUT2A This)
{
  ULONG r = BIDirectInput2A::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInput2A<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInput2A<D>::WIDirectInput2A(LPDIRECTINPUT2A pNative) : BIDirectInput2A(pNative, &vtbl_, false)
{}

/* WIDirectInput7A */
struct VIDirectInput7A
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUT7A This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUT7A This);
  ULONG (WINAPI *Release)(LPDIRECTINPUT7A This);
  /*** IDirectInputA methods ***/
  HRESULT (WINAPI *CreateDevice)(LPDIRECTINPUT7A This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(LPDIRECTINPUT7A This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(LPDIRECTINPUT7A This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUT7A This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUT7A This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2A methods ***/
  HRESULT (WINAPI *FindDevice)(LPDIRECTINPUT7A This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  /*** IDirectInput7A methods ***/
  HRESULT (WINAPI *CreateDeviceEx)(LPDIRECTINPUT7A This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter);
};

class BIDirectInput7A
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUT7A This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUT7A This);
  static ULONG WINAPI Release(LPDIRECTINPUT7A This);
  /*** IDirectInputA methods ***/
  static HRESULT WINAPI CreateDevice(LPDIRECTINPUT7A This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(LPDIRECTINPUT7A This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(LPDIRECTINPUT7A This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUT7A This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUT7A This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2A methods ***/
  static HRESULT WINAPI FindDevice(LPDIRECTINPUT7A This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  /*** IDirectInput7A methods ***/
  static HRESULT WINAPI CreateDeviceEx(LPDIRECTINPUT7A This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter);

  BIDirectInput7A(LPDIRECTINPUT7A pNative, VIDirectInput7A const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput7A();

private:
  static VIDirectInput7A const vtbl_;

  VIDirectInput7A const * pVtbl_;
  LPDIRECTINPUT7A pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput7A : public BIDirectInput7A
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUT7A This);
  WIDirectInput7A(LPDIRECTINPUT7A pNative);

private:
  static VIDirectInput7A const vtbl_;
};

template <class D>
VIDirectInput7A const WIDirectInput7A<D>::vtbl_ =
{
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  &D::CreateDevice,
  &D::EnumDevices,
  &D::GetDeviceStatus,
  &D::RunControlPanel,
  &D::Initialize,
  &D::FindDevice,
  &D::CreateDeviceEx
};

template <class D>
ULONG WINAPI WIDirectInput7A<D>::Release(LPDIRECTINPUT7A This)
{
  ULONG r = BIDirectInput7A::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInput7A<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInput7A<D>::WIDirectInput7A(LPDIRECTINPUT7A pNative) : BIDirectInput7A(pNative, &vtbl_, false)
{}

/* WIDirectInput8A */
struct VIDirectInput8A
{
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUT8A This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUT8A This);
  ULONG (WINAPI *Release)(LPDIRECTINPUT8A This);

  HRESULT (WINAPI *CreateDevice)(LPDIRECTINPUT8A This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(LPDIRECTINPUT8A This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(LPDIRECTINPUT8A This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUT8A This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUT8A This, HINSTANCE hinst, DWORD dwVersion);
  HRESULT (WINAPI *FindDevice)(LPDIRECTINPUT8A This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  HRESULT (WINAPI *EnumDevicesBySemantics)(LPDIRECTINPUT8A This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *ConfigureDevices)(LPDIRECTINPUT8A This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);
};

class BIDirectInput8A
{
public:
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUT8A This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUT8A This);
  static ULONG WINAPI Release(LPDIRECTINPUT8A This);

  static HRESULT WINAPI CreateDevice(LPDIRECTINPUT8A This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(LPDIRECTINPUT8A This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(LPDIRECTINPUT8A This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUT8A This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUT8A This, HINSTANCE hinst, DWORD dwVersion);
  static HRESULT WINAPI FindDevice(LPDIRECTINPUT8A This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  static HRESULT WINAPI EnumDevicesBySemantics(LPDIRECTINPUT8A This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI ConfigureDevices(LPDIRECTINPUT8A This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);

  BIDirectInput8A(LPDIRECTINPUT8A pNative, VIDirectInput8A const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput8A();

private:
  static VIDirectInput8A const vtbl_;

  VIDirectInput8A const * pVtbl_;
  LPDIRECTINPUT8A pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput8A : public BIDirectInput8A
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUT8A This);
  WIDirectInput8A(LPDIRECTINPUT8A pNative);

private:
  static VIDirectInput8A const vtbl_;
};

template <class D>
VIDirectInput8A const WIDirectInput8A<D>::vtbl_ =
{
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  &D::CreateDevice,
  &D::EnumDevices,
  &D::GetDeviceStatus,
  &D::RunControlPanel,
  &D::Initialize,
  &D::FindDevice,
  &D::EnumDevicesBySemantics,
  &D::ConfigureDevices
};

template <class D>
ULONG WINAPI WIDirectInput8A<D>::Release(LPDIRECTINPUT8A This)
{
  ULONG r = BIDirectInput8A::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInput8A<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInput8A<D>::WIDirectInput8A(LPDIRECTINPUT8A pNative) : BIDirectInput8A(pNative, &vtbl_, false)
{}


/* WIDirectInputW */
struct VIDirectInputW
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUTW This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUTW This);
  ULONG (WINAPI *Release)(LPDIRECTINPUTW This);
  /*** IDirectInputW methods ***/
  HRESULT (WINAPI *CreateDevice)(LPDIRECTINPUTW This, REFGUID rguid, LPDIRECTINPUTDEVICEW *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(LPDIRECTINPUTW This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(LPDIRECTINPUTW This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUTW This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUTW This, HINSTANCE hinst, DWORD dwVersion);
};

class BIDirectInputW
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUTW This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUTW This);
  static ULONG WINAPI Release(LPDIRECTINPUTW This);
  /*** IDirectInputW methods ***/
  static HRESULT WINAPI CreateDevice(LPDIRECTINPUTW This, REFGUID rguid, LPDIRECTINPUTDEVICEW *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(LPDIRECTINPUTW This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(LPDIRECTINPUTW This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUTW This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUTW This, HINSTANCE hinst, DWORD dwVersion);

  BIDirectInputW(LPDIRECTINPUTW pNative, VIDirectInputW const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputW();

private:
  static VIDirectInputW const vtbl_;

  VIDirectInputW const * pVtbl_;
  LPDIRECTINPUTW pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputW : public BIDirectInputW
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUTW This);
  WIDirectInputW(LPDIRECTINPUTW pNative);

private:
  static VIDirectInputW const vtbl_;
};

template <class D>
VIDirectInputW const WIDirectInputW<D>::vtbl_ =
{
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  &D::CreateDevice,
  &D::EnumDevices,
  &D::GetDeviceStatus,
  &D::RunControlPanel,
  &D::Initialize
};

template <class D>
ULONG WINAPI WIDirectInputW<D>::Release(LPDIRECTINPUTW This)
{
  ULONG r = BIDirectInputW::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInputW<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInputW<D>::WIDirectInputW(LPDIRECTINPUTW pNative) : BIDirectInputW(pNative, &vtbl_, false)
{}

/* WIDirectInput2W */
struct VIDirectInput2W
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUT2W This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUT2W This);
  ULONG (WINAPI *Release)(LPDIRECTINPUT2W This);
  /*** IDirectInputW methods ***/
  HRESULT (WINAPI *CreateDevice)(LPDIRECTINPUT2W This, REFGUID rguid, LPDIRECTINPUTDEVICEW *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(LPDIRECTINPUT2W This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(LPDIRECTINPUT2W This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUT2W This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUT2W This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2W methods ***/
  HRESULT (WINAPI *FindDevice)(LPDIRECTINPUT2W This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance);
};

class BIDirectInput2W
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUT2W This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUT2W This);
  static ULONG WINAPI Release(LPDIRECTINPUT2W This);
  /*** IDirectInputW methods ***/
  static HRESULT WINAPI CreateDevice(LPDIRECTINPUT2W This, REFGUID rguid, LPDIRECTINPUTDEVICEW *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(LPDIRECTINPUT2W This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(LPDIRECTINPUT2W This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUT2W This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUT2W This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2W methods ***/
  static HRESULT WINAPI FindDevice(LPDIRECTINPUT2W This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance);

  BIDirectInput2W(LPDIRECTINPUT2W pNative, VIDirectInput2W const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput2W();

private:
  static VIDirectInput2W const vtbl_;

  VIDirectInput2W const * pVtbl_;
  LPDIRECTINPUT2W pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput2W : public BIDirectInput2W
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUT2W This);
  WIDirectInput2W(LPDIRECTINPUT2W pNative);

private:
  static VIDirectInput2W const vtbl_;
};

template <class D>
VIDirectInput2W const WIDirectInput2W<D>::vtbl_ =
{
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  &D::CreateDevice,
  &D::EnumDevices,
  &D::GetDeviceStatus,
  &D::RunControlPanel,
  &D::Initialize,
  &D::FindDevice
};

template <class D>
ULONG WINAPI WIDirectInput2W<D>::Release(LPDIRECTINPUT2W This)
{
  ULONG r = BIDirectInput2W::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInput2W<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInput2W<D>::WIDirectInput2W(LPDIRECTINPUT2W pNative) : BIDirectInput2W(pNative, &vtbl_, false)
{}

/* WIDirectInput7W */
struct VIDirectInput7W
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUT7W This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUT7W This);
  ULONG (WINAPI *Release)(LPDIRECTINPUT7W This);
  /*** IDirectInputW methods ***/
  HRESULT (WINAPI *CreateDevice)(LPDIRECTINPUT7W This, REFGUID rguid, LPDIRECTINPUTDEVICEW *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(LPDIRECTINPUT7W This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(LPDIRECTINPUT7W This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUT7W This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUT7W This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2W methods ***/
  HRESULT (WINAPI *FindDevice)(LPDIRECTINPUT7W This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance);
  /*** IDirectInput7W methods ***/
  HRESULT (WINAPI *CreateDeviceEx)(LPDIRECTINPUT7W This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter);
};

class BIDirectInput7W
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUT7W This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUT7W This);
  static ULONG WINAPI Release(LPDIRECTINPUT7W This);
  /*** IDirectInputW methods ***/
  static HRESULT WINAPI CreateDevice(LPDIRECTINPUT7W This, REFGUID rguid, LPDIRECTINPUTDEVICEW *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(LPDIRECTINPUT7W This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(LPDIRECTINPUT7W This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUT7W This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUT7W This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2W methods ***/
  static HRESULT WINAPI FindDevice(LPDIRECTINPUT7W This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance);
  /*** IDirectInput7W methods ***/
  static HRESULT WINAPI CreateDeviceEx(LPDIRECTINPUT7W This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter);

  BIDirectInput7W(LPDIRECTINPUT7W pNative, VIDirectInput7W const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput7W();

private:
  static VIDirectInput7W const vtbl_;

  VIDirectInput7W const * pVtbl_;
  LPDIRECTINPUT7W pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput7W : public BIDirectInput7W
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUT7W This);
  WIDirectInput7W(LPDIRECTINPUT7W pNative);

private:
  static VIDirectInput7W const vtbl_;
};

template <class D>
VIDirectInput7W const WIDirectInput7W<D>::vtbl_ =
{
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  &D::CreateDevice,
  &D::EnumDevices,
  &D::GetDeviceStatus,
  &D::RunControlPanel,
  &D::Initialize,
  &D::FindDevice,
  &D::CreateDeviceEx
};

template <class D>
ULONG WINAPI WIDirectInput7W<D>::Release(LPDIRECTINPUT7W This)
{
  ULONG r = BIDirectInput7W::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInput7W<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInput7W<D>::WIDirectInput7W(LPDIRECTINPUT7W pNative) : BIDirectInput7W(pNative, &vtbl_, false)
{}

/* WIDirectInput8W */
struct VIDirectInput8W
{
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUT8W This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUT8W This);
  ULONG (WINAPI *Release)(LPDIRECTINPUT8W This);

  HRESULT (WINAPI *CreateDevice)(LPDIRECTINPUT8W This, REFGUID rguid, LPDIRECTINPUTDEVICE8W *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(LPDIRECTINPUT8W This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(LPDIRECTINPUT8W This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(LPDIRECTINPUT8W This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(LPDIRECTINPUT8W This, HINSTANCE hinst, DWORD dwVersion);
  HRESULT (WINAPI *FindDevice)(LPDIRECTINPUT8W This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance);
  HRESULT (WINAPI *EnumDevicesBySemantics)(LPDIRECTINPUT8W This, LPCWSTR ptszUserName, LPDIACTIONFORMATW lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBW lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *ConfigureDevices)(LPDIRECTINPUT8W This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSW lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);
};

class BIDirectInput8W
{
public:
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUT8W This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUT8W This);
  static ULONG WINAPI Release(LPDIRECTINPUT8W This);

  static HRESULT WINAPI CreateDevice(LPDIRECTINPUT8W This, REFGUID rguid, LPDIRECTINPUTDEVICE8W *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(LPDIRECTINPUT8W This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(LPDIRECTINPUT8W This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(LPDIRECTINPUT8W This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(LPDIRECTINPUT8W This, HINSTANCE hinst, DWORD dwVersion);
  static HRESULT WINAPI FindDevice(LPDIRECTINPUT8W This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance);
  static HRESULT WINAPI EnumDevicesBySemantics(LPDIRECTINPUT8W This, LPCWSTR ptszUserName, LPDIACTIONFORMATW lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBW lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI ConfigureDevices(LPDIRECTINPUT8W This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSW lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);

  BIDirectInput8W(LPDIRECTINPUT8W pNative, VIDirectInput8W const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput8W();

private:
  static VIDirectInput8W const vtbl_;

  VIDirectInput8W const * pVtbl_;
  LPDIRECTINPUT8W pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput8W : public BIDirectInput8W
{
public:
  static ULONG WINAPI Release(LPDIRECTINPUT8W This);
  WIDirectInput8W(LPDIRECTINPUT8W pNative);

private:
  static VIDirectInput8W const vtbl_;
};

template <class D>
VIDirectInput8W const WIDirectInput8W<D>::vtbl_ =
{
  &D::QueryInterface,
  &D::AddRef,
  &D::Release,
  &D::CreateDevice,
  &D::EnumDevices,
  &D::GetDeviceStatus,
  &D::RunControlPanel,
  &D::Initialize,
  &D::FindDevice,
  &D::EnumDevicesBySemantics,
  &D::ConfigureDevices
};

template <class D>
ULONG WINAPI WIDirectInput8W<D>::Release(LPDIRECTINPUT8W This)
{
  ULONG r = BIDirectInput8W::Release(This);
  if (r == 0)
  {
    auto That = reinterpret_cast<D*>(This);
    log_debug("WIDirectInput8W<D>::Release(%p): deleting self", That);
    delete That;
  }
  return r;
}

template <class D>
WIDirectInput8W<D>::WIDirectInput8W(LPDIRECTINPUT8W pNative) : BIDirectInput8W(pNative, &vtbl_, false)
{}

} //namespace di8b

#endif
