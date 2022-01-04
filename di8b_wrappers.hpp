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
  HRESULT (WINAPI *QueryInterface)(::IDirectInputDevice8* This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(::IDirectInputDevice8* This);
  ULONG (WINAPI *Release)(::IDirectInputDevice8* This);
  HRESULT (WINAPI *GetCapabilities)(::IDirectInputDevice8* This, LPDIDEVCAPS lpDIDevCaps);
  HRESULT (WINAPI *EnumObjects)(::IDirectInputDevice8* This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetProperty)(::IDirectInputDevice8* This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  HRESULT (WINAPI *SetProperty)(::IDirectInputDevice8* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  HRESULT (WINAPI *Acquire)(::IDirectInputDevice8* This);
  HRESULT (WINAPI *Unacquire)(::IDirectInputDevice8* This);
  HRESULT (WINAPI *GetDeviceState)(::IDirectInputDevice8* This, DWORD cbData, LPVOID lpvData);
  HRESULT (WINAPI *GetDeviceData)(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  HRESULT (WINAPI *SetDataFormat)(::IDirectInputDevice8* This, LPCDIDATAFORMAT lpdf);
  HRESULT (WINAPI *SetEventNotification)(::IDirectInputDevice8* This, HANDLE hEvent);
  HRESULT (WINAPI *SetCooperativeLevel)(::IDirectInputDevice8* This, HWND hwnd, DWORD dwFlags);
  HRESULT (WINAPI *GetObjectInfo)(::IDirectInputDevice8* This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  HRESULT (WINAPI *GetDeviceInfo)(::IDirectInputDevice8* This, LPDIDEVICEINSTANCEA pdidi);
  HRESULT (WINAPI *RunControlPanel)(::IDirectInputDevice8* This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(::IDirectInputDevice8* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  HRESULT (WINAPI *CreateEffect)(::IDirectInputDevice8* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  HRESULT (WINAPI *EnumEffects)(::IDirectInputDevice8* This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  HRESULT (WINAPI *GetEffectInfo)(::IDirectInputDevice8* This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  HRESULT (WINAPI *GetForceFeedbackState)(::IDirectInputDevice8* This, LPDWORD pdwOut);
  HRESULT (WINAPI *SendForceFeedbackCommand)(::IDirectInputDevice8* This, DWORD dwFlags);
  HRESULT (WINAPI *EnumCreatedEffectObjects)(::IDirectInputDevice8* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  HRESULT (WINAPI *Escape)(::IDirectInputDevice8* This, LPDIEFFESCAPE pesc);
  HRESULT (WINAPI *Poll)(::IDirectInputDevice8* This);
  HRESULT (WINAPI *SendDeviceData)(::IDirectInputDevice8* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  HRESULT (WINAPI *EnumEffectsInFile)(::IDirectInputDevice8* This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  HRESULT (WINAPI *WriteEffectToFile)(::IDirectInputDevice8* This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  HRESULT (WINAPI *BuildActionMap)(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *SetActionMap)(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *GetImageInfo)(::IDirectInputDevice8* This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader);

  VIDirectInputDevice8();
};

class CIDirectInputDevice8;

class WIDirectInputDevice8
{
public:
  static HRESULT WINAPI QueryInterface(::IDirectInputDevice8* This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(::IDirectInputDevice8* This);
  static ULONG WINAPI Release(::IDirectInputDevice8* This);
  static HRESULT WINAPI GetCapabilities(::IDirectInputDevice8* This, LPDIDEVCAPS lpDIDevCaps);
  static HRESULT WINAPI EnumObjects(::IDirectInputDevice8* This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  static HRESULT WINAPI SetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  static HRESULT WINAPI Acquire(::IDirectInputDevice8* This);
  static HRESULT WINAPI Unacquire(::IDirectInputDevice8* This);
  static HRESULT WINAPI GetDeviceState(::IDirectInputDevice8* This, DWORD cbData, LPVOID lpvData);
  static HRESULT WINAPI GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  static HRESULT WINAPI SetDataFormat(::IDirectInputDevice8* This, LPCDIDATAFORMAT lpdf);
  static HRESULT WINAPI SetEventNotification(::IDirectInputDevice8* This, HANDLE hEvent);
  static HRESULT WINAPI SetCooperativeLevel(::IDirectInputDevice8* This, HWND hwnd, DWORD dwFlags);
  static HRESULT WINAPI GetObjectInfo(::IDirectInputDevice8* This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  static HRESULT WINAPI GetDeviceInfo(::IDirectInputDevice8* This, LPDIDEVICEINSTANCEA pdidi);
  static HRESULT WINAPI RunControlPanel(::IDirectInputDevice8* This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(::IDirectInputDevice8* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  static HRESULT WINAPI CreateEffect(::IDirectInputDevice8* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  static HRESULT WINAPI EnumEffects(::IDirectInputDevice8* This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  static HRESULT WINAPI GetEffectInfo(::IDirectInputDevice8* This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  static HRESULT WINAPI GetForceFeedbackState(::IDirectInputDevice8* This, LPDWORD pdwOut);
  static HRESULT WINAPI SendForceFeedbackCommand(::IDirectInputDevice8* This, DWORD dwFlags);
  static HRESULT WINAPI EnumCreatedEffectObjects(::IDirectInputDevice8* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  static HRESULT WINAPI Escape(::IDirectInputDevice8* This, LPDIEFFESCAPE pesc);
  static HRESULT WINAPI Poll(::IDirectInputDevice8* This);
  static HRESULT WINAPI SendDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  static HRESULT WINAPI EnumEffectsInFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  static HRESULT WINAPI WriteEffectToFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  static HRESULT WINAPI BuildActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI SetActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI GetImageInfo(::IDirectInputDevice8* This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader);

  WIDirectInputDevice8(::IDirectInputDevice8* pNative, CIDirectInputDevice8* pCallback);

private:
  static VIDirectInputDevice8 const vIDirectInputDevice8;

  VIDirectInputDevice8 const * const pVtbl_;
  ::IDirectInputDevice8* pNative_;
  CIDirectInputDevice8* pCallback_;
};

class CIDirectInputDevice8
{
public:
  virtual HRESULT QueryInterface(::IDirectInputDevice8* This, REFIID riid, void** ppvObject);
  virtual ULONG AddRef(::IDirectInputDevice8* This);
  virtual ULONG Release(::IDirectInputDevice8* This);
  virtual HRESULT GetCapabilities(::IDirectInputDevice8* This, LPDIDEVCAPS lpDIDevCaps);
  virtual HRESULT EnumObjects(::IDirectInputDevice8* This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  virtual HRESULT GetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPDIPROPHEADER pdiph);
  virtual HRESULT SetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
  virtual HRESULT Acquire(::IDirectInputDevice8* This);
  virtual HRESULT Unacquire(::IDirectInputDevice8* This);
  virtual HRESULT GetDeviceState(::IDirectInputDevice8* This, DWORD cbData, LPVOID lpvData);
  virtual HRESULT GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
  virtual HRESULT SetDataFormat(::IDirectInputDevice8* This, LPCDIDATAFORMAT lpdf);
  virtual HRESULT SetEventNotification(::IDirectInputDevice8* This, HANDLE hEvent);
  virtual HRESULT SetCooperativeLevel(::IDirectInputDevice8* This, HWND hwnd, DWORD dwFlags);
  virtual HRESULT GetObjectInfo(::IDirectInputDevice8* This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
  virtual HRESULT GetDeviceInfo(::IDirectInputDevice8* This, LPDIDEVICEINSTANCEA pdidi);
  virtual HRESULT RunControlPanel(::IDirectInputDevice8* This, HWND hwndOwner, DWORD dwFlags);
  virtual HRESULT Initialize(::IDirectInputDevice8* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
  virtual HRESULT CreateEffect(::IDirectInputDevice8* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  virtual HRESULT EnumEffects(::IDirectInputDevice8* This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  virtual HRESULT GetEffectInfo(::IDirectInputDevice8* This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  virtual HRESULT GetForceFeedbackState(::IDirectInputDevice8* This, LPDWORD pdwOut);
  virtual HRESULT SendForceFeedbackCommand(::IDirectInputDevice8* This, DWORD dwFlags);
  virtual HRESULT EnumCreatedEffectObjects(::IDirectInputDevice8* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  virtual HRESULT Escape(::IDirectInputDevice8* This, LPDIEFFESCAPE pesc);
  virtual HRESULT Poll(::IDirectInputDevice8* This);
  virtual HRESULT SendDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  virtual HRESULT EnumEffectsInFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  virtual HRESULT WriteEffectToFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  virtual HRESULT BuildActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  virtual HRESULT SetActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  virtual HRESULT GetImageInfo(::IDirectInputDevice8* This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader);

  virtual ~CIDirectInputDevice8();
};

struct VIDirectInput8
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
};

class CIDirectInput8;

class WIDirectInput8
{
public:
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

  WIDirectInput8(::IDirectInput8* pNative, CIDirectInput8* pCallback);

private:
  static VIDirectInput8 const vIDirectInput8;

  VIDirectInput8 const * const pVtbl_;
  ::IDirectInput8* pNative_;
  CIDirectInput8* pCallback_;
};

class CIDirectInput8
{
public:
  virtual HRESULT QueryInterface(::IDirectInput8* This, REFIID riid, void** ppvObject);
  virtual ULONG AddRef(::IDirectInput8* This);
  virtual ULONG Release(::IDirectInput8* This);

  virtual HRESULT CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  virtual HRESULT EnumDevices(::IDirectInput8* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  virtual HRESULT GetDeviceStatus(::IDirectInput8* This, REFGUID rguidInstance);
  virtual HRESULT RunControlPanel(::IDirectInput8* This, HWND hwndOwner, DWORD dwFlags);
  virtual HRESULT Initialize(::IDirectInput8* This, HINSTANCE hinst, DWORD dwVersion);
  virtual HRESULT FindDevice(::IDirectInput8* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  virtual HRESULT EnumDevicesBySemantics(::IDirectInput8* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags);
  virtual HRESULT ConfigureDevices(::IDirectInput8* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);
  
  virtual ~CIDirectInput8();
};


/* Templates */
/* WIDirectInputA */
struct VIDirectInputA
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(::IDirectInputA* This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(::IDirectInputA* This);
  ULONG (WINAPI *Release)(::IDirectInputA* This);
  /*** IDirectInputA methods ***/
  HRESULT (WINAPI *CreateDevice)(::IDirectInputA* This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(::IDirectInputA* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(::IDirectInputA* This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(::IDirectInputA* This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(::IDirectInputA* This, HINSTANCE hinst, DWORD dwVersion);
};

class BIDirectInputA
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(::IDirectInputA* This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(::IDirectInputA* This);
  static ULONG WINAPI Release(::IDirectInputA* This);
  /*** IDirectInputA methods ***/
  static HRESULT WINAPI CreateDevice(::IDirectInputA* This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(::IDirectInputA* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(::IDirectInputA* This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(::IDirectInputA* This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(::IDirectInputA* This, HINSTANCE hinst, DWORD dwVersion);

  BIDirectInputA(::IDirectInputA* pNative, VIDirectInputA const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInputA();

private:
  static VIDirectInputA const vtbl_;

  VIDirectInputA const * pVtbl_;
  ::IDirectInputA* pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInputA : public BIDirectInputA
{
public:
  static ULONG WINAPI Release(::IDirectInputA* This);
  WIDirectInputA(::IDirectInputA* pNative);

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
ULONG WINAPI WIDirectInputA<D>::Release(::IDirectInputA* This)
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
WIDirectInputA<D>::WIDirectInputA(::IDirectInputA* pNative) : BIDirectInputA(pNative, &vtbl_, false)
{}

/* WIDirectInput2A */
struct VIDirectInput2A
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(::IDirectInput2A* This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(::IDirectInput2A* This);
  ULONG (WINAPI *Release)(::IDirectInput2A* This);
  /*** IDirectInputA methods ***/
  HRESULT (WINAPI *CreateDevice)(::IDirectInput2A* This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(::IDirectInput2A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(::IDirectInput2A* This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(::IDirectInput2A* This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(::IDirectInput2A* This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2A methods ***/
  HRESULT (WINAPI *FindDevice)(::IDirectInput2A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
};

class BIDirectInput2A
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(::IDirectInput2A* This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(::IDirectInput2A* This);
  static ULONG WINAPI Release(::IDirectInput2A* This);
  /*** IDirectInputA methods ***/
  static HRESULT WINAPI CreateDevice(::IDirectInput2A* This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(::IDirectInput2A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(::IDirectInput2A* This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(::IDirectInput2A* This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(::IDirectInput2A* This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2A methods ***/
  static HRESULT WINAPI FindDevice(::IDirectInput2A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);

  BIDirectInput2A(::IDirectInput2A* pNative, VIDirectInput2A const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput2A();

private:
  static VIDirectInput2A const vtbl_;

  VIDirectInput2A const * pVtbl_;
  ::IDirectInput2A* pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput2A : public BIDirectInput2A
{
public:
  static ULONG WINAPI Release(::IDirectInput2A* This);
  WIDirectInput2A(::IDirectInput2A* pNative);

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
ULONG WINAPI WIDirectInput2A<D>::Release(::IDirectInput2A* This)
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
WIDirectInput2A<D>::WIDirectInput2A(::IDirectInput2A* pNative) : BIDirectInput2A(pNative, &vtbl_, false)
{}

/* WIDirectInput7A */
struct VIDirectInput7A
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(::IDirectInput7A* This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(::IDirectInput7A* This);
  ULONG (WINAPI *Release)(::IDirectInput7A* This);
  /*** IDirectInputA methods ***/
  HRESULT (WINAPI *CreateDevice)(::IDirectInput7A* This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(::IDirectInput7A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(::IDirectInput7A* This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(::IDirectInput7A* This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(::IDirectInput7A* This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2A methods ***/
  HRESULT (WINAPI *FindDevice)(::IDirectInput7A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  /*** IDirectInput7A methods ***/
  HRESULT (WINAPI *CreateDeviceEx)(::IDirectInput7A* This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter);
};

class BIDirectInput7A
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(::IDirectInput7A* This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(::IDirectInput7A* This);
  static ULONG WINAPI Release(::IDirectInput7A* This);
  /*** IDirectInputA methods ***/
  static HRESULT WINAPI CreateDevice(::IDirectInput7A* This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(::IDirectInput7A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(::IDirectInput7A* This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(::IDirectInput7A* This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(::IDirectInput7A* This, HINSTANCE hinst, DWORD dwVersion);
  /*** IDirectInput2A methods ***/
  static HRESULT WINAPI FindDevice(::IDirectInput7A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  /*** IDirectInput7A methods ***/
  static HRESULT WINAPI CreateDeviceEx(::IDirectInput7A* This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter);

  BIDirectInput7A(::IDirectInput7A* pNative, VIDirectInput7A const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput7A();

private:
  static VIDirectInput7A const vtbl_;

  VIDirectInput7A const * pVtbl_;
  ::IDirectInput7A* pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput7A : public BIDirectInput7A
{
public:
  static ULONG WINAPI Release(::IDirectInput7A* This);
  WIDirectInput7A(::IDirectInput7A* pNative);

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
ULONG WINAPI WIDirectInput7A<D>::Release(::IDirectInput7A* This)
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
WIDirectInput7A<D>::WIDirectInput7A(::IDirectInput7A* pNative) : BIDirectInput7A(pNative, &vtbl_, false)
{}

/* WIDirectInput8A */
struct VIDirectInput8A
{
  HRESULT (WINAPI *QueryInterface)(::IDirectInput8A* This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(::IDirectInput8A* This);
  ULONG (WINAPI *Release)(::IDirectInput8A* This);

  HRESULT (WINAPI *CreateDevice)(::IDirectInput8A* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  HRESULT (WINAPI *EnumDevices)(::IDirectInput8A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *GetDeviceStatus)(::IDirectInput8A* This, REFGUID rguidInstance);
  HRESULT (WINAPI *RunControlPanel)(::IDirectInput8A* This, HWND hwndOwner, DWORD dwFlags);
  HRESULT (WINAPI *Initialize)(::IDirectInput8A* This, HINSTANCE hinst, DWORD dwVersion);
  HRESULT (WINAPI *FindDevice)(::IDirectInput8A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  HRESULT (WINAPI *EnumDevicesBySemantics)(::IDirectInput8A* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags);
  HRESULT (WINAPI *ConfigureDevices)(::IDirectInput8A* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);
};

class BIDirectInput8A
{
public:
  static HRESULT WINAPI QueryInterface(::IDirectInput8A* This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(::IDirectInput8A* This);
  static ULONG WINAPI Release(::IDirectInput8A* This);

  static HRESULT WINAPI CreateDevice(::IDirectInput8A* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  static HRESULT WINAPI EnumDevices(::IDirectInput8A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI GetDeviceStatus(::IDirectInput8A* This, REFGUID rguidInstance);
  static HRESULT WINAPI RunControlPanel(::IDirectInput8A* This, HWND hwndOwner, DWORD dwFlags);
  static HRESULT WINAPI Initialize(::IDirectInput8A* This, HINSTANCE hinst, DWORD dwVersion);
  static HRESULT WINAPI FindDevice(::IDirectInput8A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance);
  static HRESULT WINAPI EnumDevicesBySemantics(::IDirectInput8A* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags);
  static HRESULT WINAPI ConfigureDevices(::IDirectInput8A* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);

  BIDirectInput8A(::IDirectInput8A* pNative, VIDirectInput8A const * pVtbl=nullptr, bool deleteSelf=false);
  ~BIDirectInput8A();

private:
  static VIDirectInput8A const vtbl_;

  VIDirectInput8A const * pVtbl_;
  ::IDirectInput8A* pNative_;
  bool deleteSelf_;
};

template <class D> class WIDirectInput8A : public BIDirectInput8A
{
public:
  static ULONG WINAPI Release(::IDirectInput8A* This);
  WIDirectInput8A(::IDirectInput8A* pNative);

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
ULONG WINAPI WIDirectInput8A<D>::Release(::IDirectInput8A* This)
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
WIDirectInput8A<D>::WIDirectInput8A(::IDirectInput8A* pNative) : BIDirectInput8A(pNative, &vtbl_, false)
{}

class WrappingWIDirectInput8A : public WIDirectInput8A<WrappingWIDirectInput8A>
{
public:
  typedef WIDirectInput8A<WrappingWIDirectInput8A> base_type;

  WrappingWIDirectInput8A(::IDirectInput8A* pNative) : base_type(pNative) {}
};

} //namespace di8b

#endif
