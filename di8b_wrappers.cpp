#include <di8b_wrappers.hpp>
#include <cassert>

namespace di8b
{

/* WIDirectInputDevice8 */
VIDirectInputDevice8::VIDirectInputDevice8() : QueryInterface(WIDirectInputDevice8::QueryInterface), AddRef(WIDirectInputDevice8::AddRef), Release(WIDirectInputDevice8::Release), GetCapabilities(WIDirectInputDevice8::GetCapabilities), EnumObjects(WIDirectInputDevice8::EnumObjects), GetProperty(WIDirectInputDevice8::GetProperty), SetProperty(WIDirectInputDevice8::SetProperty), Acquire(WIDirectInputDevice8::Acquire), Unacquire(WIDirectInputDevice8::Unacquire), GetDeviceState(WIDirectInputDevice8::GetDeviceState), GetDeviceData(WIDirectInputDevice8::GetDeviceData), SetDataFormat(WIDirectInputDevice8::SetDataFormat), SetEventNotification(WIDirectInputDevice8::SetEventNotification), SetCooperativeLevel(WIDirectInputDevice8::SetCooperativeLevel), GetObjectInfo(WIDirectInputDevice8::GetObjectInfo), GetDeviceInfo(WIDirectInputDevice8::GetDeviceInfo), RunControlPanel(WIDirectInputDevice8::RunControlPanel), Initialize(WIDirectInputDevice8::Initialize), CreateEffect(WIDirectInputDevice8::CreateEffect), EnumEffects(WIDirectInputDevice8::EnumEffects), GetEffectInfo(WIDirectInputDevice8::GetEffectInfo), GetForceFeedbackState(WIDirectInputDevice8::GetForceFeedbackState), SendForceFeedbackCommand(WIDirectInputDevice8::SendForceFeedbackCommand), EnumCreatedEffectObjects(WIDirectInputDevice8::EnumCreatedEffectObjects), Escape(WIDirectInputDevice8::Escape), Poll(WIDirectInputDevice8::Poll), SendDeviceData(WIDirectInputDevice8::SendDeviceData), EnumEffectsInFile(WIDirectInputDevice8::EnumEffectsInFile), WriteEffectToFile(WIDirectInputDevice8::WriteEffectToFile), BuildActionMap(WIDirectInputDevice8::BuildActionMap), SetActionMap(WIDirectInputDevice8::SetActionMap), GetImageInfo(WIDirectInputDevice8::GetImageInfo)
{}

VIDirectInputDevice8 const WIDirectInputDevice8::vIDirectInputDevice8;

WIDirectInputDevice8::WIDirectInputDevice8(LPDIRECTINPUTDEVICE8 pNative, CIDirectInputDevice8* pCallback)
  : pVtbl_(&vIDirectInputDevice8), pNative_(pNative), pCallback_(pCallback)
{
  log_debug("WIDirectInputDevice8::WIDirectInputDevice8(%p)", this);
}

HRESULT WINAPI WIDirectInputDevice8::QueryInterface(LPDIRECTINPUTDEVICE8 This, REFIID riid, void** ppvObject)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->QueryInterface(That->pNative_, riid, ppvObject);
}

ULONG WINAPI WIDirectInputDevice8::AddRef(LPDIRECTINPUTDEVICE8 This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->AddRef(That->pNative_);
}

ULONG WINAPI WIDirectInputDevice8::Release(LPDIRECTINPUTDEVICE8 This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  auto refcount = That->pCallback_->Release(That->pNative_);
  if (refcount == 0)
  {
    log_debug("WIDirectInputDevice8::Release(%p): deleting self", This);
    delete That;
  }
  return refcount;
}

HRESULT WINAPI WIDirectInputDevice8::GetCapabilities(LPDIRECTINPUTDEVICE8 This, LPDIDEVCAPS lpDIDevCaps)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetCapabilities(That->pNative_, lpDIDevCaps);
}

HRESULT WINAPI WIDirectInputDevice8::EnumObjects(LPDIRECTINPUTDEVICE8 This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumObjects(That->pNative_, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::GetProperty(LPDIRECTINPUTDEVICE8 This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetProperty(That->pNative_, rguidProp, pdiph);
}

HRESULT WINAPI WIDirectInputDevice8::SetProperty(LPDIRECTINPUTDEVICE8 This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetProperty(That->pNative_, rguidProp, pdiph);
}

HRESULT WINAPI WIDirectInputDevice8::Acquire(LPDIRECTINPUTDEVICE8 This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Acquire(That->pNative_);
}

HRESULT WINAPI WIDirectInputDevice8::Unacquire(LPDIRECTINPUTDEVICE8 This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Unacquire(That->pNative_);
}

HRESULT WINAPI WIDirectInputDevice8::GetDeviceState(LPDIRECTINPUTDEVICE8 This, DWORD cbData, LPVOID lpvData)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetDeviceState(That->pNative_, cbData, lpvData);
}

HRESULT WINAPI WIDirectInputDevice8::GetDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetDeviceData(That->pNative_, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::SetDataFormat(LPDIRECTINPUTDEVICE8 This, LPCDIDATAFORMAT lpdf)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetDataFormat(That->pNative_, lpdf);
}

HRESULT WINAPI WIDirectInputDevice8::SetEventNotification(LPDIRECTINPUTDEVICE8 This, HANDLE hEvent)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetEventNotification(That->pNative_, hEvent);
}

HRESULT WINAPI WIDirectInputDevice8::SetCooperativeLevel(LPDIRECTINPUTDEVICE8 This, HWND hwnd, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetCooperativeLevel(That->pNative_, hwnd, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::GetObjectInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetObjectInfo(That->pNative_, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI WIDirectInputDevice8::GetDeviceInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEINSTANCEA pdidi)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetDeviceInfo(That->pNative_, pdidi);
}

HRESULT WINAPI WIDirectInputDevice8::RunControlPanel(LPDIRECTINPUTDEVICE8 This, HWND hwndOwner, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->RunControlPanel(That->pNative_, hwndOwner, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::Initialize(LPDIRECTINPUTDEVICE8 This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Initialize(That->pNative_, hinst, dwVersion, rguid);
}

HRESULT WINAPI WIDirectInputDevice8::CreateEffect(LPDIRECTINPUTDEVICE8 This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->CreateEffect(That->pNative_, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI WIDirectInputDevice8::EnumEffects(LPDIRECTINPUTDEVICE8 This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumEffects(That->pNative_, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI WIDirectInputDevice8::GetEffectInfo(LPDIRECTINPUTDEVICE8 This, LPDIEFFECTINFOA pdei, REFGUID rguid)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetEffectInfo(That->pNative_, pdei, rguid);
}

HRESULT WINAPI WIDirectInputDevice8::GetForceFeedbackState(LPDIRECTINPUTDEVICE8 This, LPDWORD pdwOut)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetForceFeedbackState(That->pNative_, pdwOut);
}

HRESULT WINAPI WIDirectInputDevice8::SendForceFeedbackCommand(LPDIRECTINPUTDEVICE8 This, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SendForceFeedbackCommand(That->pNative_, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE8 This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumCreatedEffectObjects(That->pNative_, lpCallback, pvRef, fl);
}

HRESULT WINAPI WIDirectInputDevice8::Escape(LPDIRECTINPUTDEVICE8 This, LPDIEFFESCAPE pesc)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Escape(That->pNative_, pesc);
}

HRESULT WINAPI WIDirectInputDevice8::Poll(LPDIRECTINPUTDEVICE8 This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Poll(That->pNative_);
}

HRESULT WINAPI WIDirectInputDevice8::SendDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SendDeviceData(That->pNative_, cbObjectData, rgdod, pdwInOut, fl);
}

HRESULT WINAPI WIDirectInputDevice8::EnumEffectsInFile(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumEffectsInFile(That->pNative_, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::WriteEffectToFile(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->WriteEffectToFile(That->pNative_, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::BuildActionMap(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->BuildActionMap(That->pNative_, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::SetActionMap(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetActionMap(That->pNative_, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::GetImageInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetImageInfo(That->pNative_, lpdiDevImageInfoHeader);
}


/* CIDirectInputDevice8 */
HRESULT CIDirectInputDevice8::QueryInterface(LPDIRECTINPUTDEVICE8 This, REFIID riid, void** ppvObject)
{
  return This->lpVtbl->QueryInterface(This, riid, ppvObject);
}

ULONG CIDirectInputDevice8::AddRef(LPDIRECTINPUTDEVICE8 This)
{
  return This->lpVtbl->AddRef(This);
}

ULONG CIDirectInputDevice8::Release(LPDIRECTINPUTDEVICE8 This)
{
  auto refcount = This->lpVtbl->Release(This);
  if (refcount == 0)
  {
    log_debug("CIDirectInputDevice8::Release(%p): deleting self", this);
    delete this;
  }
  return refcount;
}

HRESULT CIDirectInputDevice8::GetCapabilities(LPDIRECTINPUTDEVICE8 This, LPDIDEVCAPS lpDIDevCaps)
{
  return This->lpVtbl->GetCapabilities(This, lpDIDevCaps);
}

HRESULT CIDirectInputDevice8::EnumObjects(LPDIRECTINPUTDEVICE8 This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  return This->lpVtbl->EnumObjects(This, lpCallback, pvRef, dwFlags);
}

HRESULT CIDirectInputDevice8::GetProperty(LPDIRECTINPUTDEVICE8 This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  return This->lpVtbl->GetProperty(This, rguidProp, pdiph);
}

HRESULT CIDirectInputDevice8::SetProperty(LPDIRECTINPUTDEVICE8 This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  return This->lpVtbl->SetProperty(This, rguidProp, pdiph);
}

HRESULT CIDirectInputDevice8::Acquire(LPDIRECTINPUTDEVICE8 This)
{
  return This->lpVtbl->Acquire(This);
}

HRESULT CIDirectInputDevice8::Unacquire(LPDIRECTINPUTDEVICE8 This)
{
  return This->lpVtbl->Unacquire(This);
}

HRESULT CIDirectInputDevice8::GetDeviceState(LPDIRECTINPUTDEVICE8 This, DWORD cbData, LPVOID lpvData)
{
  return This->lpVtbl->GetDeviceState(This, cbData, lpvData);
}

HRESULT CIDirectInputDevice8::GetDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  return This->lpVtbl->GetDeviceData(This, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT CIDirectInputDevice8::SetDataFormat(LPDIRECTINPUTDEVICE8 This, LPCDIDATAFORMAT lpdf)
{
  return This->lpVtbl->SetDataFormat(This, lpdf);
}

HRESULT CIDirectInputDevice8::SetEventNotification(LPDIRECTINPUTDEVICE8 This, HANDLE hEvent)
{
  return This->lpVtbl->SetEventNotification(This, hEvent);
}

HRESULT CIDirectInputDevice8::SetCooperativeLevel(LPDIRECTINPUTDEVICE8 This, HWND hwnd, DWORD dwFlags)
{
  return This->lpVtbl->SetCooperativeLevel(This, hwnd, dwFlags);
}

HRESULT CIDirectInputDevice8::GetObjectInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  return This->lpVtbl->GetObjectInfo(This, pdidoi, dwObj, dwHow);
}

HRESULT CIDirectInputDevice8::GetDeviceInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEINSTANCEA pdidi)
{
  return This->lpVtbl->GetDeviceInfo(This, pdidi);
}

HRESULT CIDirectInputDevice8::RunControlPanel(LPDIRECTINPUTDEVICE8 This, HWND hwndOwner, DWORD dwFlags)
{
  return This->lpVtbl->RunControlPanel(This, hwndOwner, dwFlags);
}

HRESULT CIDirectInputDevice8::Initialize(LPDIRECTINPUTDEVICE8 This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  return This->lpVtbl->Initialize(This, hinst, dwVersion, rguid);
}

HRESULT CIDirectInputDevice8::CreateEffect(LPDIRECTINPUTDEVICE8 This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  return This->lpVtbl->CreateEffect(This, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT CIDirectInputDevice8::EnumEffects(LPDIRECTINPUTDEVICE8 This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  return This->lpVtbl->EnumEffects(This, lpCallback, pvRef, dwEffType);
}

HRESULT CIDirectInputDevice8::GetEffectInfo(LPDIRECTINPUTDEVICE8 This, LPDIEFFECTINFOA pdei, REFGUID rguid)
{
  return This->lpVtbl->GetEffectInfo(This, pdei, rguid);
}

HRESULT CIDirectInputDevice8::GetForceFeedbackState(LPDIRECTINPUTDEVICE8 This, LPDWORD pdwOut)
{
  return This->lpVtbl->GetForceFeedbackState(This, pdwOut);
}

HRESULT CIDirectInputDevice8::SendForceFeedbackCommand(LPDIRECTINPUTDEVICE8 This, DWORD dwFlags)
{
  return This->lpVtbl->SendForceFeedbackCommand(This, dwFlags);
}

HRESULT CIDirectInputDevice8::EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE8 This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  return This->lpVtbl->EnumCreatedEffectObjects(This, lpCallback, pvRef, fl);
}

HRESULT CIDirectInputDevice8::Escape(LPDIRECTINPUTDEVICE8 This, LPDIEFFESCAPE pesc)
{
  return This->lpVtbl->Escape(This, pesc);
}

HRESULT CIDirectInputDevice8::Poll(LPDIRECTINPUTDEVICE8 This)
{
  return This->lpVtbl->Poll(This);
}

HRESULT CIDirectInputDevice8::SendDeviceData(LPDIRECTINPUTDEVICE8 This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  return This->lpVtbl->SendDeviceData(This, cbObjectData, rgdod, pdwInOut, fl);
}

HRESULT CIDirectInputDevice8::EnumEffectsInFile(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  return This->lpVtbl->EnumEffectsInFile(This, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT CIDirectInputDevice8::WriteEffectToFile(LPDIRECTINPUTDEVICE8 This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  return This->lpVtbl->WriteEffectToFile(This, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

HRESULT CIDirectInputDevice8::BuildActionMap(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  return This->lpVtbl->BuildActionMap(This, lpdiaf, lpszUserName, dwFlags);
}

HRESULT CIDirectInputDevice8::SetActionMap(LPDIRECTINPUTDEVICE8 This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  return This->lpVtbl->SetActionMap(This, lpdiaf, lpszUserName, dwFlags);
}

HRESULT CIDirectInputDevice8::GetImageInfo(LPDIRECTINPUTDEVICE8 This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader)
{
  return This->lpVtbl->GetImageInfo(This, lpdiDevImageInfoHeader);
}

CIDirectInputDevice8::~CIDirectInputDevice8() {}


/* WIDirectInput8 */
VIDirectInput8::VIDirectInput8() : QueryInterface(WIDirectInput8::QueryInterface), AddRef(WIDirectInput8::AddRef), Release(WIDirectInput8::Release), CreateDevice(WIDirectInput8::CreateDevice), EnumDevices(WIDirectInput8::EnumDevices), GetDeviceStatus(WIDirectInput8::GetDeviceStatus), RunControlPanel(WIDirectInput8::RunControlPanel), Initialize(WIDirectInput8::Initialize), FindDevice(WIDirectInput8::FindDevice), EnumDevicesBySemantics(WIDirectInput8::EnumDevicesBySemantics), ConfigureDevices(WIDirectInput8::ConfigureDevices)
{}

VIDirectInput8 const WIDirectInput8::vIDirectInput8;

WIDirectInput8::WIDirectInput8(LPDIRECTINPUT8 pNative, CIDirectInput8* pCallback)
  : pVtbl_(&vIDirectInput8), pNative_(pNative), pCallback_(pCallback)
{}

HRESULT WINAPI WIDirectInput8::QueryInterface(LPDIRECTINPUT8 This, REFIID riid, void** ppvObject)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->QueryInterface(That->pNative_, riid, ppvObject);
}

ULONG WINAPI WIDirectInput8::AddRef(LPDIRECTINPUT8 This)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->AddRef(That->pNative_);
}

ULONG WINAPI WIDirectInput8::Release(LPDIRECTINPUT8 This)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  auto refcount = That->pCallback_->Release(That->pNative_);
  if (refcount == 0)
  {
    log_debug("WIDirectInput8::Release(%p): deleting self", This);
    delete That;
  }
  return refcount;
}

HRESULT WINAPI WIDirectInput8::CreateDevice(LPDIRECTINPUT8 This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->CreateDevice(That->pNative_, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT WINAPI WIDirectInput8::EnumDevices(LPDIRECTINPUT8 This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumDevices(That->pNative_, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInput8::GetDeviceStatus(LPDIRECTINPUT8 This, REFGUID rguidInstance)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetDeviceStatus(That->pNative_, rguidInstance);
}

HRESULT WINAPI WIDirectInput8::RunControlPanel(LPDIRECTINPUT8 This, HWND hwndOwner, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->RunControlPanel(That->pNative_, hwndOwner, dwFlags);
}

HRESULT WINAPI WIDirectInput8::Initialize(LPDIRECTINPUT8 This, HINSTANCE hinst, DWORD dwVersion)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Initialize(That->pNative_, hinst, dwVersion);
}

HRESULT WINAPI WIDirectInput8::FindDevice(LPDIRECTINPUT8 This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->FindDevice(That->pNative_, rguid, pszName, pguidInstance);
}

HRESULT WINAPI WIDirectInput8::EnumDevicesBySemantics(LPDIRECTINPUT8 This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumDevicesBySemantics(That->pNative_, ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInput8::ConfigureDevices(LPDIRECTINPUT8 This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->ConfigureDevices(That->pNative_, lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}


HRESULT CIDirectInput8::QueryInterface(LPDIRECTINPUT8 This, REFIID riid, void** ppvObject)
{
  return This->lpVtbl->QueryInterface(This, riid, ppvObject);
}

ULONG CIDirectInput8::AddRef(LPDIRECTINPUT8 This)
{
  return This->lpVtbl->AddRef(This);
}

ULONG CIDirectInput8::Release(LPDIRECTINPUT8 This)
{
  auto refcount = This->lpVtbl->Release(This);
  if (refcount == 0)
  {
    log_debug("CIDirectInput8::Release(%p): deleting self", this);
    delete this;
  }
  return refcount;
}

HRESULT CIDirectInput8::CreateDevice(LPDIRECTINPUT8 This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  return This->lpVtbl->CreateDevice(This, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT CIDirectInput8::EnumDevices(LPDIRECTINPUT8 This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  return This->lpVtbl->EnumDevices(This, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT CIDirectInput8::GetDeviceStatus(LPDIRECTINPUT8 This, REFGUID rguidInstance)
{
  return This->lpVtbl->GetDeviceStatus(This, rguidInstance);
}

HRESULT CIDirectInput8::RunControlPanel(LPDIRECTINPUT8 This, HWND hwndOwner, DWORD dwFlags)
{
  return This->lpVtbl->RunControlPanel(This, hwndOwner, dwFlags);
}

HRESULT CIDirectInput8::Initialize(LPDIRECTINPUT8 This, HINSTANCE hinst, DWORD dwVersion)
{
  return This->lpVtbl->Initialize(This, hinst, dwVersion);
}

HRESULT CIDirectInput8::FindDevice(LPDIRECTINPUT8 This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  return This->lpVtbl->FindDevice(This, rguid, pszName, pguidInstance);
}

HRESULT CIDirectInput8::EnumDevicesBySemantics(LPDIRECTINPUT8 This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  return This->lpVtbl->EnumDevicesBySemantics(This, ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT CIDirectInput8::ConfigureDevices(LPDIRECTINPUT8 This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
  return This->lpVtbl->ConfigureDevices(This, lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}

CIDirectInput8::~CIDirectInput8() {}


/* Templates */
/* WIDirectInputDevice8A */
#define NATIVE reinterpret_cast<LPDIRECTINPUTDEVICE8A>(This->pNative_)
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDevice8A::QueryInterface(BIDirectInputDevice8A* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDevice8A::QueryInterface(%p)", This);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
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
  if ((r == 0) && (This->deleteSelf_))
  {
    log_debug("BIDirectInputDevice8A::Release(%p): deleting self", This);
    delete This;
  }
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

BIDirectInputDevice8A::BIDirectInputDevice8A(LPVOID pNative, VIDirectInputDevice8A const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInputDevice8A::BIDirectInputDevice8A(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInputDevice8A::~BIDirectInputDevice8A()
{
  log_debug("BIDirectInputDevice8A::~BIDirectInputDevice8A(%p)", this);
}

VIDirectInputDevice8A const BIDirectInputDevice8A::vtbl_ =
{
  /*** IUnknown methods ***/
  &BIDirectInputDevice8A::QueryInterface,
  &BIDirectInputDevice8A::AddRef,
  &BIDirectInputDevice8A::Release,
  /*** IDirectInputDeviceA methods ***/
  &BIDirectInputDevice8A::GetCapabilities,
  &BIDirectInputDevice8A::EnumObjects,
  &BIDirectInputDevice8A::GetProperty,
  &BIDirectInputDevice8A::SetProperty,
  &BIDirectInputDevice8A::Acquire,
  &BIDirectInputDevice8A::Unacquire,
  &BIDirectInputDevice8A::GetDeviceState,
  &BIDirectInputDevice8A::GetDeviceData,
  &BIDirectInputDevice8A::SetDataFormat,
  &BIDirectInputDevice8A::SetEventNotification,
  &BIDirectInputDevice8A::SetCooperativeLevel,
  &BIDirectInputDevice8A::GetObjectInfo,
  &BIDirectInputDevice8A::GetDeviceInfo,
  &BIDirectInputDevice8A::RunControlPanel,
  &BIDirectInputDevice8A::Initialize,
  /*** IDirectInputDevice2A methods ***/
  &BIDirectInputDevice8A::CreateEffect,
  &BIDirectInputDevice8A::EnumEffects,
  &BIDirectInputDevice8A::GetEffectInfo,
  &BIDirectInputDevice8A::GetForceFeedbackState,
  &BIDirectInputDevice8A::SendForceFeedbackCommand,
  &BIDirectInputDevice8A::EnumCreatedEffectObjects,
  &BIDirectInputDevice8A::Escape,
  &BIDirectInputDevice8A::Poll,
  &BIDirectInputDevice8A::SendDeviceData,
  /*** IDirectInputDevice7A methods ***/
  &BIDirectInputDevice8A::EnumEffectsInFile,
  &BIDirectInputDevice8A::WriteEffectToFile,
  /*** IDirectInputDevice8A methods ***/
  &BIDirectInputDevice8A::BuildActionMap,
  &BIDirectInputDevice8A::SetActionMap,
  &BIDirectInputDevice8A::GetImageInfo
};


/* WIDirectInputDevice8W */
#define NATIVE reinterpret_cast<LPDIRECTINPUTDEVICE8W>(This->pNative_)
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDevice8W::QueryInterface(BIDirectInputDevice8W* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDevice8W::QueryInterface(%p)", This);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
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
  if ((r == 0) && (This->deleteSelf_))
  {
    log_debug("BIDirectInputDevice8W::Release(%p): deleting self", This);
    delete This;
  }
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

BIDirectInputDevice8W::BIDirectInputDevice8W(LPVOID pNative, VIDirectInputDevice8W const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInputDevice8W::BIDirectInputDevice8W(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInputDevice8W::~BIDirectInputDevice8W()
{
  log_debug("BIDirectInputDevice8W::~BIDirectInputDevice8W(%p)", this);
}

VIDirectInputDevice8W const BIDirectInputDevice8W::vtbl_ =
{
  /*** IUnknown methods ***/
  &BIDirectInputDevice8W::QueryInterface,
  &BIDirectInputDevice8W::AddRef,
  &BIDirectInputDevice8W::Release,
  /*** IDirectInputDeviceW methods ***/
  &BIDirectInputDevice8W::GetCapabilities,
  &BIDirectInputDevice8W::EnumObjects,
  &BIDirectInputDevice8W::GetProperty,
  &BIDirectInputDevice8W::SetProperty,
  &BIDirectInputDevice8W::Acquire,
  &BIDirectInputDevice8W::Unacquire,
  &BIDirectInputDevice8W::GetDeviceState,
  &BIDirectInputDevice8W::GetDeviceData,
  &BIDirectInputDevice8W::SetDataFormat,
  &BIDirectInputDevice8W::SetEventNotification,
  &BIDirectInputDevice8W::SetCooperativeLevel,
  &BIDirectInputDevice8W::GetObjectInfo,
  &BIDirectInputDevice8W::GetDeviceInfo,
  &BIDirectInputDevice8W::RunControlPanel,
  &BIDirectInputDevice8W::Initialize,
  /*** IDirectInputDevice2W methods ***/
  &BIDirectInputDevice8W::CreateEffect,
  &BIDirectInputDevice8W::EnumEffects,
  &BIDirectInputDevice8W::GetEffectInfo,
  &BIDirectInputDevice8W::GetForceFeedbackState,
  &BIDirectInputDevice8W::SendForceFeedbackCommand,
  &BIDirectInputDevice8W::EnumCreatedEffectObjects,
  &BIDirectInputDevice8W::Escape,
  &BIDirectInputDevice8W::Poll,
  &BIDirectInputDevice8W::SendDeviceData,
  /*** IDirectInputDevice7W methods ***/
  &BIDirectInputDevice8W::EnumEffectsInFile,
  &BIDirectInputDevice8W::WriteEffectToFile,
  /*** IDirectInputDevice8W methods ***/
  &BIDirectInputDevice8W::BuildActionMap,
  &BIDirectInputDevice8W::SetActionMap,
  &BIDirectInputDevice8W::GetImageInfo
};


/* WIDirectInputA */
#define THAT reinterpret_cast<BIDirectInputA*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInputA::QueryInterface(LPDIRECTINPUTA This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputA::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInputA::AddRef(LPDIRECTINPUTA This)
{
  log_debug("BIDirectInputA::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputA::Release(LPDIRECTINPUTA This)
{
  log_debug("BIDirectInputA::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInputA::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

HRESULT WINAPI BIDirectInputA::CreateDevice(LPDIRECTINPUTA This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInputA::CreateDevice(%p)", THAT);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT WINAPI BIDirectInputA::EnumDevices(LPDIRECTINPUTA This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputA::EnumDevices(%p)", THAT);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputA::GetDeviceStatus(LPDIRECTINPUTA This, REFGUID rguidInstance)
{
  log_debug("BIDirectInputA::GetDeviceStatus(%p)", THAT);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInputA::RunControlPanel(LPDIRECTINPUTA This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputA::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputA::Initialize(LPDIRECTINPUTA This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInputA::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInputA::BIDirectInputA(LPDIRECTINPUTA pNative, VIDirectInputA const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInputA::BIDirectInputA(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInputA::~BIDirectInputA()
{
  log_debug("BIDirectInputA::~BIDirectInputA(%p)", this);
}

VIDirectInputA const BIDirectInputA::vtbl_ =
{
  &BIDirectInputA::QueryInterface,
  &BIDirectInputA::AddRef,
  &BIDirectInputA::Release,
  &BIDirectInputA::CreateDevice,
  &BIDirectInputA::EnumDevices,
  &BIDirectInputA::GetDeviceStatus,
  &BIDirectInputA::RunControlPanel,
  &BIDirectInputA::Initialize
};


/* WIDirectInput2A */
#define THAT reinterpret_cast<BIDirectInput2A*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInput2A::QueryInterface(LPDIRECTINPUT2A This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput2A::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInput2A::AddRef(LPDIRECTINPUT2A This)
{
  log_debug("BIDirectInput2A::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput2A::Release(LPDIRECTINPUT2A This)
{
  log_debug("BIDirectInput2A::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInput2A::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

HRESULT WINAPI BIDirectInput2A::CreateDevice(LPDIRECTINPUT2A This, REFGUID rguid, LPDIRECTINPUTDEVICE2A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput2A::CreateDevice(%p)", THAT);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, reinterpret_cast<LPDIRECTINPUTDEVICEA*>(lplpDirectInputDevice), pUnkOuter);
}

HRESULT WINAPI BIDirectInput2A::EnumDevices(LPDIRECTINPUT2A This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput2A::EnumDevices(%p)", THAT);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput2A::GetDeviceStatus(LPDIRECTINPUT2A This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput2A::GetDeviceStatus(%p)", THAT);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput2A::RunControlPanel(LPDIRECTINPUT2A This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput2A::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput2A::Initialize(LPDIRECTINPUT2A This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput2A::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput2A::FindDevice(LPDIRECTINPUT2A This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput2A::FindDevice(%p)", THAT);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInput2A::BIDirectInput2A(LPDIRECTINPUT2A pNative, VIDirectInput2A const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInput2A::BIDirectInput2A(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInput2A::~BIDirectInput2A()
{
  log_debug("BIDirectInput2A::~BIDirectInput2A(%p)", this);
}

VIDirectInput2A const BIDirectInput2A::vtbl_ =
{
  &BIDirectInput2A::QueryInterface,
  &BIDirectInput2A::AddRef,
  &BIDirectInput2A::Release,
  &BIDirectInput2A::CreateDevice,
  &BIDirectInput2A::EnumDevices,
  &BIDirectInput2A::GetDeviceStatus,
  &BIDirectInput2A::RunControlPanel,
  &BIDirectInput2A::Initialize,
  &BIDirectInput2A::FindDevice
};


/* WIDirectInput7A */
#define THAT reinterpret_cast<BIDirectInput7A*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInput7A::QueryInterface(LPDIRECTINPUT7A This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput7A::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInput7A::AddRef(LPDIRECTINPUT7A This)
{
  log_debug("BIDirectInput7A::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput7A::Release(LPDIRECTINPUT7A This)
{
  log_debug("BIDirectInput7A::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInput7A::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

HRESULT WINAPI BIDirectInput7A::CreateDevice(LPDIRECTINPUT7A This, REFGUID rguid, LPDIRECTINPUTDEVICE7A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput7A::CreateDevice(%p)", THAT);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, reinterpret_cast<LPDIRECTINPUTDEVICEA*>(lplpDirectInputDevice), pUnkOuter);
}

HRESULT WINAPI BIDirectInput7A::EnumDevices(LPDIRECTINPUT7A This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput7A::EnumDevices(%p)", THAT);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput7A::GetDeviceStatus(LPDIRECTINPUT7A This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput7A::GetDeviceStatus(%p)", THAT);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput7A::RunControlPanel(LPDIRECTINPUT7A This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput7A::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput7A::Initialize(LPDIRECTINPUT7A This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput7A::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput7A::FindDevice(LPDIRECTINPUT7A This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput7A::FindDevice(%p)", THAT);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}

HRESULT WINAPI BIDirectInput7A::CreateDeviceEx(LPDIRECTINPUT7A This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter)
{
  log_debug("BIDirectInput7A::CreateDeviceEx(%p)", THAT);
  return CALL_NATIVE(CreateDeviceEx)(NATIVE, rguid, riid, pvOut, lpUnknownOuter);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInput7A::BIDirectInput7A(LPDIRECTINPUT7A pNative, VIDirectInput7A const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInput7A::BIDirectInput7A(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInput7A::~BIDirectInput7A()
{
  log_debug("BIDirectInput7A::~BIDirectInput7A(%p)", this);
}

VIDirectInput7A const BIDirectInput7A::vtbl_ =
{
  &BIDirectInput7A::QueryInterface,
  &BIDirectInput7A::AddRef,
  &BIDirectInput7A::Release,
  &BIDirectInput7A::CreateDevice,
  &BIDirectInput7A::EnumDevices,
  &BIDirectInput7A::GetDeviceStatus,
  &BIDirectInput7A::RunControlPanel,
  &BIDirectInput7A::Initialize,
  &BIDirectInput7A::FindDevice,
  &BIDirectInput7A::CreateDeviceEx
};


/* WIDirectInput8A */
#define THAT reinterpret_cast<BIDirectInput8A*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInput8A::QueryInterface(LPDIRECTINPUT8A This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput8A::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInput8A::AddRef(LPDIRECTINPUT8A This)
{
  log_debug("BIDirectInput8A::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput8A::Release(LPDIRECTINPUT8A This)
{
  log_debug("BIDirectInput8A::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInput8A::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

HRESULT WINAPI BIDirectInput8A::CreateDevice(LPDIRECTINPUT8A This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput8A::CreateDevice(%p)", THAT);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT WINAPI BIDirectInput8A::EnumDevices(LPDIRECTINPUT8A This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput8A::EnumDevices(%p)", THAT);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput8A::GetDeviceStatus(LPDIRECTINPUT8A This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput8A::GetDeviceStatus(%p)", THAT);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput8A::RunControlPanel(LPDIRECTINPUT8A This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput8A::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput8A::Initialize(LPDIRECTINPUT8A This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput8A::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput8A::FindDevice(LPDIRECTINPUT8A This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput8A::FindDevice(%p)", THAT);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}

HRESULT WINAPI BIDirectInput8A::EnumDevicesBySemantics(LPDIRECTINPUT8A This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput8A::EnumDevicesBySemantics(%p)", THAT);
  return CALL_NATIVE(EnumDevicesBySemantics)(NATIVE, ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput8A::ConfigureDevices(LPDIRECTINPUT8A This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
  log_debug("BIDirectInput8A::ConfigureDevices(%p)", THAT);
  return CALL_NATIVE(ConfigureDevices)(NATIVE, lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInput8A::BIDirectInput8A(LPDIRECTINPUT8A pNative, VIDirectInput8A const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInput8A::BIDirectInput8A(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInput8A::~BIDirectInput8A()
{
  log_debug("BIDirectInput8A::~BIDirectInput8A(%p)", this);
}

VIDirectInput8A const BIDirectInput8A::vtbl_ =
{
  &BIDirectInput8A::QueryInterface,
  &BIDirectInput8A::AddRef,
  &BIDirectInput8A::Release,
  &BIDirectInput8A::CreateDevice,
  &BIDirectInput8A::EnumDevices,
  &BIDirectInput8A::GetDeviceStatus,
  &BIDirectInput8A::RunControlPanel,
  &BIDirectInput8A::Initialize,
  &BIDirectInput8A::FindDevice,
  &BIDirectInput8A::EnumDevicesBySemantics,
  &BIDirectInput8A::ConfigureDevices
};


/* WIDirectInputW */
#define THAT reinterpret_cast<BIDirectInputW*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInputW::QueryInterface(LPDIRECTINPUTW This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputW::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInputW::AddRef(LPDIRECTINPUTW This)
{
  log_debug("BIDirectInputW::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputW::Release(LPDIRECTINPUTW This)
{
  log_debug("BIDirectInputW::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInputW::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

HRESULT WINAPI BIDirectInputW::CreateDevice(LPDIRECTINPUTW This, REFGUID rguid, LPDIRECTINPUTDEVICEW *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInputW::CreateDevice(%p)", THAT);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT WINAPI BIDirectInputW::EnumDevices(LPDIRECTINPUTW This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputW::EnumDevices(%p)", THAT);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputW::GetDeviceStatus(LPDIRECTINPUTW This, REFGUID rguidInstance)
{
  log_debug("BIDirectInputW::GetDeviceStatus(%p)", THAT);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInputW::RunControlPanel(LPDIRECTINPUTW This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputW::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputW::Initialize(LPDIRECTINPUTW This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInputW::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInputW::BIDirectInputW(LPDIRECTINPUTW pNative, VIDirectInputW const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInputW::BIDirectInputW(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInputW::~BIDirectInputW()
{
  log_debug("BIDirectInputW::~BIDirectInputW(%p)", this);
}

VIDirectInputW const BIDirectInputW::vtbl_ =
{
  &BIDirectInputW::QueryInterface,
  &BIDirectInputW::AddRef,
  &BIDirectInputW::Release,
  &BIDirectInputW::CreateDevice,
  &BIDirectInputW::EnumDevices,
  &BIDirectInputW::GetDeviceStatus,
  &BIDirectInputW::RunControlPanel,
  &BIDirectInputW::Initialize
};

/* WIDirectInput2W */
#define THAT reinterpret_cast<BIDirectInput2W*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInput2W::QueryInterface(LPDIRECTINPUT2W This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput2W::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInput2W::AddRef(LPDIRECTINPUT2W This)
{
  log_debug("BIDirectInput2W::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput2W::Release(LPDIRECTINPUT2W This)
{
  log_debug("BIDirectInput2W::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInput2W::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

HRESULT WINAPI BIDirectInput2W::CreateDevice(LPDIRECTINPUT2W This, REFGUID rguid, LPDIRECTINPUTDEVICE2W *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput2W::CreateDevice(%p)", THAT);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, reinterpret_cast<LPDIRECTINPUTDEVICEW*>(lplpDirectInputDevice), pUnkOuter);
}

HRESULT WINAPI BIDirectInput2W::EnumDevices(LPDIRECTINPUT2W This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput2W::EnumDevices(%p)", THAT);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput2W::GetDeviceStatus(LPDIRECTINPUT2W This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput2W::GetDeviceStatus(%p)", THAT);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput2W::RunControlPanel(LPDIRECTINPUT2W This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput2W::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput2W::Initialize(LPDIRECTINPUT2W This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput2W::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput2W::FindDevice(LPDIRECTINPUT2W This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput2W::FindDevice(%p)", THAT);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInput2W::BIDirectInput2W(LPDIRECTINPUT2W pNative, VIDirectInput2W const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInput2W::BIDirectInput2W(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInput2W::~BIDirectInput2W()
{
  log_debug("BIDirectInput2W::~BIDirectInput2W(%p)", this);
}

VIDirectInput2W const BIDirectInput2W::vtbl_ =
{
  &BIDirectInput2W::QueryInterface,
  &BIDirectInput2W::AddRef,
  &BIDirectInput2W::Release,
  &BIDirectInput2W::CreateDevice,
  &BIDirectInput2W::EnumDevices,
  &BIDirectInput2W::GetDeviceStatus,
  &BIDirectInput2W::RunControlPanel,
  &BIDirectInput2W::Initialize,
  &BIDirectInput2W::FindDevice
};

/* WIDirectInput7W */
#define THAT reinterpret_cast<BIDirectInput7W*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInput7W::QueryInterface(LPDIRECTINPUT7W This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput7W::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInput7W::AddRef(LPDIRECTINPUT7W This)
{
  log_debug("BIDirectInput7W::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput7W::Release(LPDIRECTINPUT7W This)
{
  log_debug("BIDirectInput7W::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInput7W::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

HRESULT WINAPI BIDirectInput7W::CreateDevice(LPDIRECTINPUT7W This, REFGUID rguid, LPDIRECTINPUTDEVICE7W *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput7W::CreateDevice(%p)", THAT);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, reinterpret_cast<LPDIRECTINPUTDEVICEW*>(lplpDirectInputDevice), pUnkOuter);
}

HRESULT WINAPI BIDirectInput7W::EnumDevices(LPDIRECTINPUT7W This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput7W::EnumDevices(%p)", THAT);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput7W::GetDeviceStatus(LPDIRECTINPUT7W This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput7W::GetDeviceStatus(%p)", THAT);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput7W::RunControlPanel(LPDIRECTINPUT7W This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput7W::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput7W::Initialize(LPDIRECTINPUT7W This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput7W::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput7W::FindDevice(LPDIRECTINPUT7W This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput7W::FindDevice(%p)", THAT);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}

HRESULT WINAPI BIDirectInput7W::CreateDeviceEx(LPDIRECTINPUT7W This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter)
{
  log_debug("BIDirectInput7W::CreateDeviceEx(%p)", THAT);
  return CALL_NATIVE(CreateDeviceEx)(NATIVE, rguid, riid, pvOut, lpUnknownOuter);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInput7W::BIDirectInput7W(LPDIRECTINPUT7W pNative, VIDirectInput7W const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInput7W::BIDirectInput7W(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInput7W::~BIDirectInput7W()
{
  log_debug("BIDirectInput7W::~BIDirectInput7W(%p)", this);
}

VIDirectInput7W const BIDirectInput7W::vtbl_ =
{
  &BIDirectInput7W::QueryInterface,
  &BIDirectInput7W::AddRef,
  &BIDirectInput7W::Release,
  &BIDirectInput7W::CreateDevice,
  &BIDirectInput7W::EnumDevices,
  &BIDirectInput7W::GetDeviceStatus,
  &BIDirectInput7W::RunControlPanel,
  &BIDirectInput7W::Initialize,
  &BIDirectInput7W::FindDevice,
  &BIDirectInput7W::CreateDeviceEx
};

/* WIDirectInput8W */
#define THAT reinterpret_cast<BIDirectInput8W*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInput8W::QueryInterface(LPDIRECTINPUT8W This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput8W::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInput8W::AddRef(LPDIRECTINPUT8W This)
{
  log_debug("BIDirectInput8W::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput8W::Release(LPDIRECTINPUT8W This)
{
  log_debug("BIDirectInput8W::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInput8W::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

HRESULT WINAPI BIDirectInput8W::CreateDevice(LPDIRECTINPUT8W This, REFGUID rguid, LPDIRECTINPUTDEVICE8W *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput8W::CreateDevice(%p)", THAT);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT WINAPI BIDirectInput8W::EnumDevices(LPDIRECTINPUT8W This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput8W::EnumDevices(%p)", THAT);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput8W::GetDeviceStatus(LPDIRECTINPUT8W This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput8W::GetDeviceStatus(%p)", THAT);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput8W::RunControlPanel(LPDIRECTINPUT8W This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput8W::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput8W::Initialize(LPDIRECTINPUT8W This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput8W::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput8W::FindDevice(LPDIRECTINPUT8W This, REFGUID rguid, LPCWSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput8W::FindDevice(%p)", THAT);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}

HRESULT WINAPI BIDirectInput8W::EnumDevicesBySemantics(LPDIRECTINPUT8W This, LPCWSTR ptszUserName, LPDIACTIONFORMATW lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput8W::EnumDevicesBySemantics(%p)", THAT);
  return CALL_NATIVE(EnumDevicesBySemantics)(NATIVE, ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput8W::ConfigureDevices(LPDIRECTINPUT8W This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSW lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
  log_debug("BIDirectInput8W::ConfigureDevices(%p)", THAT);
  return CALL_NATIVE(ConfigureDevices)(NATIVE, lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInput8W::BIDirectInput8W(LPDIRECTINPUT8W pNative, VIDirectInput8W const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInput8W::BIDirectInput8W(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInput8W::~BIDirectInput8W()
{
  log_debug("BIDirectInput8W::~BIDirectInput8W(%p)", this);
}

VIDirectInput8W const BIDirectInput8W::vtbl_ =
{
  &BIDirectInput8W::QueryInterface,
  &BIDirectInput8W::AddRef,
  &BIDirectInput8W::Release,
  &BIDirectInput8W::CreateDevice,
  &BIDirectInput8W::EnumDevices,
  &BIDirectInput8W::GetDeviceStatus,
  &BIDirectInput8W::RunControlPanel,
  &BIDirectInput8W::Initialize,
  &BIDirectInput8W::FindDevice,
  &BIDirectInput8W::EnumDevicesBySemantics,
  &BIDirectInput8W::ConfigureDevices
};

} //namespace di8b
