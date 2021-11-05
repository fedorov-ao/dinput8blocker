#ifndef DINPUT8_BLOCKER_HPP
#define DINPUT8_BLOCKER_HPP

#define DIRECTINPUT_VERSION  0x0800
#define CINTERFACE

#include <cstring>
#include <stdexcept>
#include <fstream>
#include <functional>
#include <map>
#include <windows.h>
#include <olectl.h>
#include <dinput.h>
#pragma pack(1)

namespace di8b
{

std::ostream & logger();

void log_debug(char const * msg);
void log_info(char const * msg);
void log_error(char const * msg);

enum class DeviceKind { mouse, keyboard, joystick, other };

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

class BlockingCIDirectInputDevice8 : public CIDirectInputDevice8
{
public:
  typedef std::function<bool()> check_state_t;

  virtual HRESULT GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);

  BlockingCIDirectInputDevice8(check_state_t const & check_state);

private:
  check_state_t check_state;
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

class WrappingCIDirectInput8 : public CIDirectInput8
{
public:
  virtual HRESULT CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
  
  virtual ~WrappingCIDirectInput8();
};

class BlockingCIDirectInput8 : public CIDirectInput8
{
public:
  typedef std::map<DeviceKind, BlockingCIDirectInputDevice8::check_state_t> check_states_t;

  virtual HRESULT CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);

  BlockingCIDirectInput8(check_states_t const & check_states);

private:
  check_states_t check_states;
};

} //namespace di8b

#endif
