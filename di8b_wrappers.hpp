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
/* WIDirectInputDevice8A */
struct VIDirectInputDevice8A
{
  /*** IUnknown methods ***/
  HRESULT (WINAPI *QueryInterface)(LPDIRECTINPUTDEVICE8 This, REFIID riid, void** ppvObject);
  ULONG (WINAPI *AddRef)(LPDIRECTINPUTDEVICE8 This);
  ULONG (WINAPI *Release)(LPDIRECTINPUTDEVICE8 This);
  /*** IDirectInputDeviceA methods ***/
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
  /*** IDirectInputDevice2A methods ***/
  HRESULT (WINAPI *CreateEffect)(LPDIRECTINPUTDEVICE8 This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  HRESULT (WINAPI *EnumEffects)(LPDIRECTINPUTDEVICE8 This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  HRESULT (WINAPI *GetEffectInfo)(LPDIRECTINPUTDEVICE8 This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  HRESULT (WINAPI *GetForceFeedbackState)(LPDIRECTINPUTDEVICE8 This, LPDWORD pdwOut);
  HRESULT (WINAPI *SendForceFeedbackCommand)(LPDIRECTINPUTDEVICE8 This, DWORD dwFlags);
  HRESULT (WINAPI *EnumCreatedEffectObjects)(LPDIRECTINPUTDEVICE8 This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  HRESULT (WINAPI *Escape)(LPDIRECTINPUTDEVICE8 This, LPDIEFFESCAPE pesc);
  HRESULT (WINAPI *Poll)(LPDIRECTINPUTDEVICE8 This);
  HRESULT (WINAPI *SendDeviceData)(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7A methods ***/
  HRESULT (WINAPI *EnumEffectsInFile)(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  HRESULT (WINAPI *WriteEffectToFile)(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  /*** IDirectInputDevice8A methods ***/
  HRESULT (WINAPI *BuildActionMap)(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *SetActionMap)(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  HRESULT (WINAPI *GetImageInfo)(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader);
};

class BIDirectInputDevice8A
{
public:
  /*** IUnknown methods ***/
  static HRESULT WINAPI QueryInterface(LPDIRECTINPUTDEVICE8 This, REFIID riid, void** ppvObject);
  static ULONG WINAPI AddRef(LPDIRECTINPUTDEVICE8 This);
  static ULONG WINAPI Release(LPDIRECTINPUTDEVICE8 This);
  /*** IDirectInputDeviceA methods ***/
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
  /*** IDirectInputDevice2A methods ***/
  static HRESULT WINAPI CreateEffect(LPDIRECTINPUTDEVICE8 This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
  static HRESULT WINAPI EnumEffects(LPDIRECTINPUTDEVICE8 This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType);
  static HRESULT WINAPI GetEffectInfo(LPDIRECTINPUTDEVICE8 This, LPDIEFFECTINFOA pdei, REFGUID rguid);
  static HRESULT WINAPI GetForceFeedbackState(LPDIRECTINPUTDEVICE8 This, LPDWORD pdwOut);
  static HRESULT WINAPI SendForceFeedbackCommand(LPDIRECTINPUTDEVICE8 This, DWORD dwFlags);
  static HRESULT WINAPI EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE8 This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
  static HRESULT WINAPI Escape(LPDIRECTINPUTDEVICE8 This, LPDIEFFESCAPE pesc);
  static HRESULT WINAPI Poll(LPDIRECTINPUTDEVICE8 This);
  static HRESULT WINAPI SendDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
  /*** IDirectInputDevice7A methods ***/
  static HRESULT WINAPI EnumEffectsInFile(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags);
  static HRESULT WINAPI WriteEffectToFile(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags);
  /*** IDirectInputDevice8A methods ***/
  static HRESULT WINAPI BuildActionMap(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI SetActionMap(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags);
  static HRESULT WINAPI GetImageInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader);

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

} //namespace di8b

#endif
