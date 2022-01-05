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
/* WIDirectInputDeviceA */
#define THAT reinterpret_cast<BIDirectInputDeviceA*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDeviceA::QueryInterface(LPDIRECTINPUTDEVICEA This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDeviceA::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInputDeviceA::AddRef(LPDIRECTINPUTDEVICEA This)
{
  log_debug("BIDirectInputDeviceA::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputDeviceA::Release(LPDIRECTINPUTDEVICEA This)
{
  log_debug("BIDirectInputDeviceA::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInputDeviceA::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

/*** IDirectInputDeviceA methods ***/
HRESULT WINAPI BIDirectInputDeviceA::GetCapabilities(LPDIRECTINPUTDEVICEA This, LPDIDEVCAPS lpDIDevCaps)
{
  log_debug("BIDirectInputDeviceA::GetCapabilities(%p)", THAT);
  return CALL_NATIVE(GetCapabilities)(NATIVE, lpDIDevCaps);
}

HRESULT WINAPI BIDirectInputDeviceA::EnumObjects(LPDIRECTINPUTDEVICEA This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputDeviceA::EnumObjects(%p)", THAT);
  return CALL_NATIVE(EnumObjects)(NATIVE, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDeviceA::GetProperty(LPDIRECTINPUTDEVICEA This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDeviceA::GetProperty(%p)", THAT);
  return CALL_NATIVE(GetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDeviceA::SetProperty(LPDIRECTINPUTDEVICEA This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDeviceA::SetProperty(%p)", THAT);
  return CALL_NATIVE(SetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDeviceA::Acquire(LPDIRECTINPUTDEVICEA This)
{
  log_debug("BIDirectInputDeviceA::Acquire(%p)", THAT);
  return CALL_NATIVE(Acquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDeviceA::Unacquire(LPDIRECTINPUTDEVICEA This)
{
  log_debug("BIDirectInputDeviceA::Unacquire(%p)", THAT);
  return CALL_NATIVE(Unacquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDeviceA::GetDeviceState(LPDIRECTINPUTDEVICEA This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BIDirectInputDeviceA::GetDeviceState(%p)", THAT);
  return CALL_NATIVE(GetDeviceState)(NATIVE, cbData, lpvData);
}

HRESULT WINAPI BIDirectInputDeviceA::GetDeviceData(LPDIRECTINPUTDEVICEA This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BIDirectInputDeviceA::GetDeviceData(%p)", THAT);
  return CALL_NATIVE(GetDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI BIDirectInputDeviceA::SetDataFormat(LPDIRECTINPUTDEVICEA This, LPCDIDATAFORMAT lpdf)
{
  log_debug("BIDirectInputDeviceA::SetDataFormat(%p)", THAT);
  return CALL_NATIVE(SetDataFormat)(NATIVE, lpdf);
}

HRESULT WINAPI BIDirectInputDeviceA::SetEventNotification(LPDIRECTINPUTDEVICEA This, HANDLE hEvent)
{
  log_debug("BIDirectInputDeviceA::SetEventNotification(%p)", THAT);
  return CALL_NATIVE(SetEventNotification)(NATIVE, hEvent);
}

HRESULT WINAPI BIDirectInputDeviceA::SetCooperativeLevel(LPDIRECTINPUTDEVICEA This, HWND hwnd, DWORD dwFlags)
{
  log_debug("BIDirectInputDeviceA::SetCooperativeLevel(%p)", THAT);
  return CALL_NATIVE(SetCooperativeLevel)(NATIVE, hwnd, dwFlags);
}

HRESULT WINAPI BIDirectInputDeviceA::GetObjectInfo(LPDIRECTINPUTDEVICEA This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  log_debug("BIDirectInputDeviceA::GetObjectInfo(%p)", THAT);
  return CALL_NATIVE(GetObjectInfo)(NATIVE, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI BIDirectInputDeviceA::GetDeviceInfo(LPDIRECTINPUTDEVICEA This, LPDIDEVICEINSTANCEA pdidi)
{
  log_debug("BIDirectInputDeviceA::GetDeviceInfo(%p)", THAT);
  return CALL_NATIVE(GetDeviceInfo)(NATIVE, pdidi);
}

HRESULT WINAPI BIDirectInputDeviceA::RunControlPanel(LPDIRECTINPUTDEVICEA This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputDeviceA::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputDeviceA::Initialize(LPDIRECTINPUTDEVICEA This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  log_debug("BIDirectInputDeviceA::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion, rguid);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInputDeviceA::BIDirectInputDeviceA(LPDIRECTINPUTDEVICEA pNative, VIDirectInputDeviceA const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInputDeviceA::BIDirectInputDeviceA(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInputDeviceA::~BIDirectInputDeviceA()
{
  log_debug("BIDirectInputDeviceA::~BIDirectInputDeviceA(%p)", this);
}

VIDirectInputDeviceA const BIDirectInputDeviceA::vtbl_ =
{
  /*** IUnknown methods ***/
  &BIDirectInputDeviceA::QueryInterface,
  &BIDirectInputDeviceA::AddRef,
  &BIDirectInputDeviceA::Release,
  /*** IDirectInputDeviceA methods ***/
  &BIDirectInputDeviceA::GetCapabilities,
  &BIDirectInputDeviceA::EnumObjects,
  &BIDirectInputDeviceA::GetProperty,
  &BIDirectInputDeviceA::SetProperty,
  &BIDirectInputDeviceA::Acquire,
  &BIDirectInputDeviceA::Unacquire,
  &BIDirectInputDeviceA::GetDeviceState,
  &BIDirectInputDeviceA::GetDeviceData,
  &BIDirectInputDeviceA::SetDataFormat,
  &BIDirectInputDeviceA::SetEventNotification,
  &BIDirectInputDeviceA::SetCooperativeLevel,
  &BIDirectInputDeviceA::GetObjectInfo,
  &BIDirectInputDeviceA::GetDeviceInfo,
  &BIDirectInputDeviceA::RunControlPanel,
  &BIDirectInputDeviceA::Initialize
};

/* WIDirectInputDevice2A */
#define THAT reinterpret_cast<BIDirectInputDevice2A*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDevice2A::QueryInterface(LPDIRECTINPUTDEVICE2A This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDevice2A::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInputDevice2A::AddRef(LPDIRECTINPUTDEVICE2A This)
{
  log_debug("BIDirectInputDevice2A::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputDevice2A::Release(LPDIRECTINPUTDEVICE2A This)
{
  log_debug("BIDirectInputDevice2A::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInputDevice2A::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

/*** IDirectInputDeviceA methods ***/
HRESULT WINAPI BIDirectInputDevice2A::GetCapabilities(LPDIRECTINPUTDEVICE2A This, LPDIDEVCAPS lpDIDevCaps)
{
  log_debug("BIDirectInputDevice2A::GetCapabilities(%p)", THAT);
  return CALL_NATIVE(GetCapabilities)(NATIVE, lpDIDevCaps);
}

HRESULT WINAPI BIDirectInputDevice2A::EnumObjects(LPDIRECTINPUTDEVICE2A This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice2A::EnumObjects(%p)", THAT);
  return CALL_NATIVE(EnumObjects)(NATIVE, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice2A::GetProperty(LPDIRECTINPUTDEVICE2A This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice2A::GetProperty(%p)", THAT);
  return CALL_NATIVE(GetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice2A::SetProperty(LPDIRECTINPUTDEVICE2A This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice2A::SetProperty(%p)", THAT);
  return CALL_NATIVE(SetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice2A::Acquire(LPDIRECTINPUTDEVICE2A This)
{
  log_debug("BIDirectInputDevice2A::Acquire(%p)", THAT);
  return CALL_NATIVE(Acquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice2A::Unacquire(LPDIRECTINPUTDEVICE2A This)
{
  log_debug("BIDirectInputDevice2A::Unacquire(%p)", THAT);
  return CALL_NATIVE(Unacquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice2A::GetDeviceState(LPDIRECTINPUTDEVICE2A This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BIDirectInputDevice2A::GetDeviceState(%p)", THAT);
  return CALL_NATIVE(GetDeviceState)(NATIVE, cbData, lpvData);
}

HRESULT WINAPI BIDirectInputDevice2A::GetDeviceData(LPDIRECTINPUTDEVICE2A This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice2A::GetDeviceData(%p)", THAT);
  return CALL_NATIVE(GetDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice2A::SetDataFormat(LPDIRECTINPUTDEVICE2A This, LPCDIDATAFORMAT lpdf)
{
  log_debug("BIDirectInputDevice2A::SetDataFormat(%p)", THAT);
  return CALL_NATIVE(SetDataFormat)(NATIVE, lpdf);
}

HRESULT WINAPI BIDirectInputDevice2A::SetEventNotification(LPDIRECTINPUTDEVICE2A This, HANDLE hEvent)
{
  log_debug("BIDirectInputDevice2A::SetEventNotification(%p)", THAT);
  return CALL_NATIVE(SetEventNotification)(NATIVE, hEvent);
}

HRESULT WINAPI BIDirectInputDevice2A::SetCooperativeLevel(LPDIRECTINPUTDEVICE2A This, HWND hwnd, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice2A::SetCooperativeLevel(%p)", THAT);
  return CALL_NATIVE(SetCooperativeLevel)(NATIVE, hwnd, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice2A::GetObjectInfo(LPDIRECTINPUTDEVICE2A This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  log_debug("BIDirectInputDevice2A::GetObjectInfo(%p)", THAT);
  return CALL_NATIVE(GetObjectInfo)(NATIVE, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI BIDirectInputDevice2A::GetDeviceInfo(LPDIRECTINPUTDEVICE2A This, LPDIDEVICEINSTANCEA pdidi)
{
  log_debug("BIDirectInputDevice2A::GetDeviceInfo(%p)", THAT);
  return CALL_NATIVE(GetDeviceInfo)(NATIVE, pdidi);
}

HRESULT WINAPI BIDirectInputDevice2A::RunControlPanel(LPDIRECTINPUTDEVICE2A This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice2A::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice2A::Initialize(LPDIRECTINPUTDEVICE2A This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  log_debug("BIDirectInputDevice2A::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion, rguid);
}

/*** IDirectInputDevice2A methods ***/
HRESULT WINAPI BIDirectInputDevice2A::CreateEffect(LPDIRECTINPUTDEVICE2A This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  log_debug("BIDirectInputDevice2A::CreateEffect(%p)", THAT);
  return CALL_NATIVE(CreateEffect)(NATIVE, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI BIDirectInputDevice2A::EnumEffects(LPDIRECTINPUTDEVICE2A This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  log_debug("BIDirectInputDevice2A::EnumEffects(%p)", THAT);
  return CALL_NATIVE(EnumEffects)(NATIVE, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI BIDirectInputDevice2A::GetEffectInfo(LPDIRECTINPUTDEVICE2A This, LPDIEFFECTINFOA pdei, REFGUID rguid)
{
  log_debug("BIDirectInputDevice2A::GetEffectInfo(%p)", THAT);
  return CALL_NATIVE(GetEffectInfo)(NATIVE, pdei, rguid);
}

HRESULT WINAPI BIDirectInputDevice2A::GetForceFeedbackState(LPDIRECTINPUTDEVICE2A This, LPDWORD pdwOut)
{
  log_debug("BIDirectInputDevice2A::GetForceFeedbackState(%p)", THAT);
  return CALL_NATIVE(GetForceFeedbackState)(NATIVE, pdwOut);
}

HRESULT WINAPI BIDirectInputDevice2A::SendForceFeedbackCommand(LPDIRECTINPUTDEVICE2A This, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice2A::SendForceFeedbackCommand(%p)", THAT);
  return CALL_NATIVE(SendForceFeedbackCommand)(NATIVE, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice2A::EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE2A This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  log_debug("BIDirectInputDevice2A::EnumCreatedEffectObjects(%p)", THAT);
  return CALL_NATIVE(EnumCreatedEffectObjects)(NATIVE, lpCallback, pvRef, fl);
}

HRESULT WINAPI BIDirectInputDevice2A::Escape(LPDIRECTINPUTDEVICE2A This, LPDIEFFESCAPE pesc)
{
  log_debug("BIDirectInputDevice2A::Escape(%p)", THAT);
  return CALL_NATIVE(Escape)(NATIVE, pesc);
}

HRESULT WINAPI BIDirectInputDevice2A::Poll(LPDIRECTINPUTDEVICE2A This)
{
  log_debug("BIDirectInputDevice2A::Poll(%p)", THAT);
  return CALL_NATIVE(Poll)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice2A::SendDeviceData(LPDIRECTINPUTDEVICE2A This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  log_debug("BIDirectInputDevice2A::SendDeviceData(%p)", THAT);
  return CALL_NATIVE(SendDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, fl);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInputDevice2A::BIDirectInputDevice2A(LPDIRECTINPUTDEVICE2A pNative, VIDirectInputDevice2A const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInputDevice2A::BIDirectInputDevice2A(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInputDevice2A::~BIDirectInputDevice2A()
{
  log_debug("BIDirectInputDevice2A::~BIDirectInputDevice2A(%p)", this);
}

VIDirectInputDevice2A const BIDirectInputDevice2A::vtbl_ =
{
  /*** IUnknown methods ***/
  &BIDirectInputDevice2A::QueryInterface,
  &BIDirectInputDevice2A::AddRef,
  &BIDirectInputDevice2A::Release,
  /*** IDirectInputDeviceA methods ***/
  &BIDirectInputDevice2A::GetCapabilities,
  &BIDirectInputDevice2A::EnumObjects,
  &BIDirectInputDevice2A::GetProperty,
  &BIDirectInputDevice2A::SetProperty,
  &BIDirectInputDevice2A::Acquire,
  &BIDirectInputDevice2A::Unacquire,
  &BIDirectInputDevice2A::GetDeviceState,
  &BIDirectInputDevice2A::GetDeviceData,
  &BIDirectInputDevice2A::SetDataFormat,
  &BIDirectInputDevice2A::SetEventNotification,
  &BIDirectInputDevice2A::SetCooperativeLevel,
  &BIDirectInputDevice2A::GetObjectInfo,
  &BIDirectInputDevice2A::GetDeviceInfo,
  &BIDirectInputDevice2A::RunControlPanel,
  &BIDirectInputDevice2A::Initialize,
  /*** IDirectInputDevice2A methods ***/
  &BIDirectInputDevice2A::CreateEffect,
  &BIDirectInputDevice2A::EnumEffects,
  &BIDirectInputDevice2A::GetEffectInfo,
  &BIDirectInputDevice2A::GetForceFeedbackState,
  &BIDirectInputDevice2A::SendForceFeedbackCommand,
  &BIDirectInputDevice2A::EnumCreatedEffectObjects,
  &BIDirectInputDevice2A::Escape,
  &BIDirectInputDevice2A::Poll,
  &BIDirectInputDevice2A::SendDeviceData
};

/* WIDirectInputDevice7A */
#define THAT reinterpret_cast<BIDirectInputDevice7A*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDevice7A::QueryInterface(LPDIRECTINPUTDEVICE7A This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDevice7A::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInputDevice7A::AddRef(LPDIRECTINPUTDEVICE7A This)
{
  log_debug("BIDirectInputDevice7A::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputDevice7A::Release(LPDIRECTINPUTDEVICE7A This)
{
  log_debug("BIDirectInputDevice7A::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInputDevice7A::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

/*** IDirectInputDeviceA methods ***/
HRESULT WINAPI BIDirectInputDevice7A::GetCapabilities(LPDIRECTINPUTDEVICE7A This, LPDIDEVCAPS lpDIDevCaps)
{
  log_debug("BIDirectInputDevice7A::GetCapabilities(%p)", THAT);
  return CALL_NATIVE(GetCapabilities)(NATIVE, lpDIDevCaps);
}

HRESULT WINAPI BIDirectInputDevice7A::EnumObjects(LPDIRECTINPUTDEVICE7A This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7A::EnumObjects(%p)", THAT);
  return CALL_NATIVE(EnumObjects)(NATIVE, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice7A::GetProperty(LPDIRECTINPUTDEVICE7A This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice7A::GetProperty(%p)", THAT);
  return CALL_NATIVE(GetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice7A::SetProperty(LPDIRECTINPUTDEVICE7A This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice7A::SetProperty(%p)", THAT);
  return CALL_NATIVE(SetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice7A::Acquire(LPDIRECTINPUTDEVICE7A This)
{
  log_debug("BIDirectInputDevice7A::Acquire(%p)", THAT);
  return CALL_NATIVE(Acquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice7A::Unacquire(LPDIRECTINPUTDEVICE7A This)
{
  log_debug("BIDirectInputDevice7A::Unacquire(%p)", THAT);
  return CALL_NATIVE(Unacquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice7A::GetDeviceState(LPDIRECTINPUTDEVICE7A This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BIDirectInputDevice7A::GetDeviceState(%p)", THAT);
  return CALL_NATIVE(GetDeviceState)(NATIVE, cbData, lpvData);
}

HRESULT WINAPI BIDirectInputDevice7A::GetDeviceData(LPDIRECTINPUTDEVICE7A This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7A::GetDeviceData(%p)", THAT);
  return CALL_NATIVE(GetDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice7A::SetDataFormat(LPDIRECTINPUTDEVICE7A This, LPCDIDATAFORMAT lpdf)
{
  log_debug("BIDirectInputDevice7A::SetDataFormat(%p)", THAT);
  return CALL_NATIVE(SetDataFormat)(NATIVE, lpdf);
}

HRESULT WINAPI BIDirectInputDevice7A::SetEventNotification(LPDIRECTINPUTDEVICE7A This, HANDLE hEvent)
{
  log_debug("BIDirectInputDevice7A::SetEventNotification(%p)", THAT);
  return CALL_NATIVE(SetEventNotification)(NATIVE, hEvent);
}

HRESULT WINAPI BIDirectInputDevice7A::SetCooperativeLevel(LPDIRECTINPUTDEVICE7A This, HWND hwnd, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7A::SetCooperativeLevel(%p)", THAT);
  return CALL_NATIVE(SetCooperativeLevel)(NATIVE, hwnd, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice7A::GetObjectInfo(LPDIRECTINPUTDEVICE7A This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  log_debug("BIDirectInputDevice7A::GetObjectInfo(%p)", THAT);
  return CALL_NATIVE(GetObjectInfo)(NATIVE, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI BIDirectInputDevice7A::GetDeviceInfo(LPDIRECTINPUTDEVICE7A This, LPDIDEVICEINSTANCEA pdidi)
{
  log_debug("BIDirectInputDevice7A::GetDeviceInfo(%p)", THAT);
  return CALL_NATIVE(GetDeviceInfo)(NATIVE, pdidi);
}

HRESULT WINAPI BIDirectInputDevice7A::RunControlPanel(LPDIRECTINPUTDEVICE7A This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7A::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice7A::Initialize(LPDIRECTINPUTDEVICE7A This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  log_debug("BIDirectInputDevice7A::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion, rguid);
}

/*** IDirectInputDevice2A methods ***/
HRESULT WINAPI BIDirectInputDevice7A::CreateEffect(LPDIRECTINPUTDEVICE7A This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  log_debug("BIDirectInputDevice7A::CreateEffect(%p)", THAT);
  return CALL_NATIVE(CreateEffect)(NATIVE, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI BIDirectInputDevice7A::EnumEffects(LPDIRECTINPUTDEVICE7A This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  log_debug("BIDirectInputDevice7A::EnumEffects(%p)", THAT);
  return CALL_NATIVE(EnumEffects)(NATIVE, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI BIDirectInputDevice7A::GetEffectInfo(LPDIRECTINPUTDEVICE7A This, LPDIEFFECTINFOA pdei, REFGUID rguid)
{
  log_debug("BIDirectInputDevice7A::GetEffectInfo(%p)", THAT);
  return CALL_NATIVE(GetEffectInfo)(NATIVE, pdei, rguid);
}

HRESULT WINAPI BIDirectInputDevice7A::GetForceFeedbackState(LPDIRECTINPUTDEVICE7A This, LPDWORD pdwOut)
{
  log_debug("BIDirectInputDevice7A::GetForceFeedbackState(%p)", THAT);
  return CALL_NATIVE(GetForceFeedbackState)(NATIVE, pdwOut);
}

HRESULT WINAPI BIDirectInputDevice7A::SendForceFeedbackCommand(LPDIRECTINPUTDEVICE7A This, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7A::SendForceFeedbackCommand(%p)", THAT);
  return CALL_NATIVE(SendForceFeedbackCommand)(NATIVE, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice7A::EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE7A This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  log_debug("BIDirectInputDevice7A::EnumCreatedEffectObjects(%p)", THAT);
  return CALL_NATIVE(EnumCreatedEffectObjects)(NATIVE, lpCallback, pvRef, fl);
}

HRESULT WINAPI BIDirectInputDevice7A::Escape(LPDIRECTINPUTDEVICE7A This, LPDIEFFESCAPE pesc)
{
  log_debug("BIDirectInputDevice7A::Escape(%p)", THAT);
  return CALL_NATIVE(Escape)(NATIVE, pesc);
}

HRESULT WINAPI BIDirectInputDevice7A::Poll(LPDIRECTINPUTDEVICE7A This)
{
  log_debug("BIDirectInputDevice7A::Poll(%p)", THAT);
  return CALL_NATIVE(Poll)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice7A::SendDeviceData(LPDIRECTINPUTDEVICE7A This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  log_debug("BIDirectInputDevice7A::SendDeviceData(%p)", THAT);
  return CALL_NATIVE(SendDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, fl);
}

/*** IDirectInputDevice7A methods ***/
HRESULT WINAPI BIDirectInputDevice7A::EnumEffectsInFile(LPDIRECTINPUTDEVICE7A This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7A::EnumEffectsInFile(%p)", THAT);
  return CALL_NATIVE(EnumEffectsInFile)(NATIVE, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice7A::WriteEffectToFile(LPDIRECTINPUTDEVICE7A This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7A::WriteEffectToFile(%p)", THAT);
  return CALL_NATIVE(WriteEffectToFile)(NATIVE, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInputDevice7A::BIDirectInputDevice7A(LPDIRECTINPUTDEVICE7A pNative, VIDirectInputDevice7A const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInputDevice7A::BIDirectInputDevice7A(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInputDevice7A::~BIDirectInputDevice7A()
{
  log_debug("BIDirectInputDevice7A::~BIDirectInputDevice7A(%p)", this);
}

VIDirectInputDevice7A const BIDirectInputDevice7A::vtbl_ =
{
  /*** IUnknown methods ***/
  &BIDirectInputDevice7A::QueryInterface,
  &BIDirectInputDevice7A::AddRef,
  &BIDirectInputDevice7A::Release,
  /*** IDirectInputDeviceA methods ***/
  &BIDirectInputDevice7A::GetCapabilities,
  &BIDirectInputDevice7A::EnumObjects,
  &BIDirectInputDevice7A::GetProperty,
  &BIDirectInputDevice7A::SetProperty,
  &BIDirectInputDevice7A::Acquire,
  &BIDirectInputDevice7A::Unacquire,
  &BIDirectInputDevice7A::GetDeviceState,
  &BIDirectInputDevice7A::GetDeviceData,
  &BIDirectInputDevice7A::SetDataFormat,
  &BIDirectInputDevice7A::SetEventNotification,
  &BIDirectInputDevice7A::SetCooperativeLevel,
  &BIDirectInputDevice7A::GetObjectInfo,
  &BIDirectInputDevice7A::GetDeviceInfo,
  &BIDirectInputDevice7A::RunControlPanel,
  &BIDirectInputDevice7A::Initialize,
  /*** IDirectInputDevice2A methods ***/
  &BIDirectInputDevice7A::CreateEffect,
  &BIDirectInputDevice7A::EnumEffects,
  &BIDirectInputDevice7A::GetEffectInfo,
  &BIDirectInputDevice7A::GetForceFeedbackState,
  &BIDirectInputDevice7A::SendForceFeedbackCommand,
  &BIDirectInputDevice7A::EnumCreatedEffectObjects,
  &BIDirectInputDevice7A::Escape,
  &BIDirectInputDevice7A::Poll,
  &BIDirectInputDevice7A::SendDeviceData,
  /*** IDirectInputDevice7A methods ***/
  &BIDirectInputDevice7A::EnumEffectsInFile,
  &BIDirectInputDevice7A::WriteEffectToFile
};

/* WIDirectInputDevice8A */
#define THAT reinterpret_cast<BIDirectInputDevice8A*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDevice8A::QueryInterface(LPDIRECTINPUTDEVICE8A This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDevice8A::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInputDevice8A::AddRef(LPDIRECTINPUTDEVICE8A This)
{
  log_debug("BIDirectInputDevice8A::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputDevice8A::Release(LPDIRECTINPUTDEVICE8A This)
{
  log_debug("BIDirectInputDevice8A::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInputDevice8A::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

/*** IDirectInputDeviceA methods ***/
HRESULT WINAPI BIDirectInputDevice8A::GetCapabilities(LPDIRECTINPUTDEVICE8A This, LPDIDEVCAPS lpDIDevCaps)
{
  log_debug("BIDirectInputDevice8A::GetCapabilities(%p)", THAT);
  return CALL_NATIVE(GetCapabilities)(NATIVE, lpDIDevCaps);
}

HRESULT WINAPI BIDirectInputDevice8A::EnumObjects(LPDIRECTINPUTDEVICE8A This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::EnumObjects(%p)", THAT);
  return CALL_NATIVE(EnumObjects)(NATIVE, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::GetProperty(LPDIRECTINPUTDEVICE8A This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice8A::GetProperty(%p)", THAT);
  return CALL_NATIVE(GetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice8A::SetProperty(LPDIRECTINPUTDEVICE8A This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice8A::SetProperty(%p)", THAT);
  return CALL_NATIVE(SetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice8A::Acquire(LPDIRECTINPUTDEVICE8A This)
{
  log_debug("BIDirectInputDevice8A::Acquire(%p)", THAT);
  return CALL_NATIVE(Acquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8A::Unacquire(LPDIRECTINPUTDEVICE8A This)
{
  log_debug("BIDirectInputDevice8A::Unacquire(%p)", THAT);
  return CALL_NATIVE(Unacquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8A::GetDeviceState(LPDIRECTINPUTDEVICE8A This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BIDirectInputDevice8A::GetDeviceState(%p)", THAT);
  return CALL_NATIVE(GetDeviceState)(NATIVE, cbData, lpvData);
}

HRESULT WINAPI BIDirectInputDevice8A::GetDeviceData(LPDIRECTINPUTDEVICE8A This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::GetDeviceData(%p)", THAT);
  return CALL_NATIVE(GetDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::SetDataFormat(LPDIRECTINPUTDEVICE8A This, LPCDIDATAFORMAT lpdf)
{
  log_debug("BIDirectInputDevice8A::SetDataFormat(%p)", THAT);
  return CALL_NATIVE(SetDataFormat)(NATIVE, lpdf);
}

HRESULT WINAPI BIDirectInputDevice8A::SetEventNotification(LPDIRECTINPUTDEVICE8A This, HANDLE hEvent)
{
  log_debug("BIDirectInputDevice8A::SetEventNotification(%p)", THAT);
  return CALL_NATIVE(SetEventNotification)(NATIVE, hEvent);
}

HRESULT WINAPI BIDirectInputDevice8A::SetCooperativeLevel(LPDIRECTINPUTDEVICE8A This, HWND hwnd, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::SetCooperativeLevel(%p)", THAT);
  return CALL_NATIVE(SetCooperativeLevel)(NATIVE, hwnd, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::GetObjectInfo(LPDIRECTINPUTDEVICE8A This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  log_debug("BIDirectInputDevice8A::GetObjectInfo(%p)", THAT);
  return CALL_NATIVE(GetObjectInfo)(NATIVE, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI BIDirectInputDevice8A::GetDeviceInfo(LPDIRECTINPUTDEVICE8A This, LPDIDEVICEINSTANCEA pdidi)
{
  log_debug("BIDirectInputDevice8A::GetDeviceInfo(%p)", THAT);
  return CALL_NATIVE(GetDeviceInfo)(NATIVE, pdidi);
}

HRESULT WINAPI BIDirectInputDevice8A::RunControlPanel(LPDIRECTINPUTDEVICE8A This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::Initialize(LPDIRECTINPUTDEVICE8A This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  log_debug("BIDirectInputDevice8A::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion, rguid);
}

/*** IDirectInputDevice2A methods ***/
HRESULT WINAPI BIDirectInputDevice8A::CreateEffect(LPDIRECTINPUTDEVICE8A This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  log_debug("BIDirectInputDevice8A::CreateEffect(%p)", THAT);
  return CALL_NATIVE(CreateEffect)(NATIVE, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI BIDirectInputDevice8A::EnumEffects(LPDIRECTINPUTDEVICE8A This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  log_debug("BIDirectInputDevice8A::EnumEffects(%p)", THAT);
  return CALL_NATIVE(EnumEffects)(NATIVE, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI BIDirectInputDevice8A::GetEffectInfo(LPDIRECTINPUTDEVICE8A This, LPDIEFFECTINFOA pdei, REFGUID rguid)
{
  log_debug("BIDirectInputDevice8A::GetEffectInfo(%p)", THAT);
  return CALL_NATIVE(GetEffectInfo)(NATIVE, pdei, rguid);
}

HRESULT WINAPI BIDirectInputDevice8A::GetForceFeedbackState(LPDIRECTINPUTDEVICE8A This, LPDWORD pdwOut)
{
  log_debug("BIDirectInputDevice8A::GetForceFeedbackState(%p)", THAT);
  return CALL_NATIVE(GetForceFeedbackState)(NATIVE, pdwOut);
}

HRESULT WINAPI BIDirectInputDevice8A::SendForceFeedbackCommand(LPDIRECTINPUTDEVICE8A This, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::SendForceFeedbackCommand(%p)", THAT);
  return CALL_NATIVE(SendForceFeedbackCommand)(NATIVE, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE8A This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  log_debug("BIDirectInputDevice8A::EnumCreatedEffectObjects(%p)", THAT);
  return CALL_NATIVE(EnumCreatedEffectObjects)(NATIVE, lpCallback, pvRef, fl);
}

HRESULT WINAPI BIDirectInputDevice8A::Escape(LPDIRECTINPUTDEVICE8A This, LPDIEFFESCAPE pesc)
{
  log_debug("BIDirectInputDevice8A::Escape(%p)", THAT);
  return CALL_NATIVE(Escape)(NATIVE, pesc);
}

HRESULT WINAPI BIDirectInputDevice8A::Poll(LPDIRECTINPUTDEVICE8A This)
{
  log_debug("BIDirectInputDevice8A::Poll(%p)", THAT);
  return CALL_NATIVE(Poll)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8A::SendDeviceData(LPDIRECTINPUTDEVICE8A This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  log_debug("BIDirectInputDevice8A::SendDeviceData(%p)", THAT);
  return CALL_NATIVE(SendDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, fl);
}

/*** IDirectInputDevice7A methods ***/
HRESULT WINAPI BIDirectInputDevice8A::EnumEffectsInFile(LPDIRECTINPUTDEVICE8A This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::EnumEffectsInFile(%p)", THAT);
  return CALL_NATIVE(EnumEffectsInFile)(NATIVE, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::WriteEffectToFile(LPDIRECTINPUTDEVICE8A This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::WriteEffectToFile(%p)", THAT);
  return CALL_NATIVE(WriteEffectToFile)(NATIVE, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

/*** IDirectInputDevice8A methods ***/
HRESULT WINAPI BIDirectInputDevice8A::BuildActionMap(LPDIRECTINPUTDEVICE8A This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::BuildActionMap(%p)", THAT);
  return CALL_NATIVE(BuildActionMap)(NATIVE, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::SetActionMap(LPDIRECTINPUTDEVICE8A This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::SetActionMap(%p)", THAT);
  return CALL_NATIVE(SetActionMap)(NATIVE, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::GetImageInfo(LPDIRECTINPUTDEVICE8A This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader)
{
  log_debug("BIDirectInputDevice8A::GetImageInfo(%p)", THAT);
  return CALL_NATIVE(GetImageInfo)(NATIVE, lpdiDevImageInfoHeader);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInputDevice8A::BIDirectInputDevice8A(LPDIRECTINPUTDEVICE8A pNative, VIDirectInputDevice8A const * pVtbl, bool deleteSelf)
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


/* WIDirectInputDeviceW */
#define THAT reinterpret_cast<BIDirectInputDeviceW*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDeviceW::QueryInterface(LPDIRECTINPUTDEVICEW This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDeviceW::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInputDeviceW::AddRef(LPDIRECTINPUTDEVICEW This)
{
  log_debug("BIDirectInputDeviceW::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputDeviceW::Release(LPDIRECTINPUTDEVICEW This)
{
  log_debug("BIDirectInputDeviceW::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInputDeviceW::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

/*** IDirectInputDeviceW methods ***/
HRESULT WINAPI BIDirectInputDeviceW::GetCapabilities(LPDIRECTINPUTDEVICEW This, LPDIDEVCAPS lpDIDevCaps)
{
  log_debug("BIDirectInputDeviceW::GetCapabilities(%p)", THAT);
  return CALL_NATIVE(GetCapabilities)(NATIVE, lpDIDevCaps);
}

HRESULT WINAPI BIDirectInputDeviceW::EnumObjects(LPDIRECTINPUTDEVICEW This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputDeviceW::EnumObjects(%p)", THAT);
  return CALL_NATIVE(EnumObjects)(NATIVE, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDeviceW::GetProperty(LPDIRECTINPUTDEVICEW This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDeviceW::GetProperty(%p)", THAT);
  return CALL_NATIVE(GetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDeviceW::SetProperty(LPDIRECTINPUTDEVICEW This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDeviceW::SetProperty(%p)", THAT);
  return CALL_NATIVE(SetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDeviceW::Acquire(LPDIRECTINPUTDEVICEW This)
{
  log_debug("BIDirectInputDeviceW::Acquire(%p)", THAT);
  return CALL_NATIVE(Acquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDeviceW::Unacquire(LPDIRECTINPUTDEVICEW This)
{
  log_debug("BIDirectInputDeviceW::Unacquire(%p)", THAT);
  return CALL_NATIVE(Unacquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDeviceW::GetDeviceState(LPDIRECTINPUTDEVICEW This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BIDirectInputDeviceW::GetDeviceState(%p)", THAT);
  return CALL_NATIVE(GetDeviceState)(NATIVE, cbData, lpvData);
}

HRESULT WINAPI BIDirectInputDeviceW::GetDeviceData(LPDIRECTINPUTDEVICEW This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BIDirectInputDeviceW::GetDeviceData(%p)", THAT);
  return CALL_NATIVE(GetDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI BIDirectInputDeviceW::SetDataFormat(LPDIRECTINPUTDEVICEW This, LPCDIDATAFORMAT lpdf)
{
  log_debug("BIDirectInputDeviceW::SetDataFormat(%p)", THAT);
  return CALL_NATIVE(SetDataFormat)(NATIVE, lpdf);
}

HRESULT WINAPI BIDirectInputDeviceW::SetEventNotification(LPDIRECTINPUTDEVICEW This, HANDLE hEvent)
{
  log_debug("BIDirectInputDeviceW::SetEventNotification(%p)", THAT);
  return CALL_NATIVE(SetEventNotification)(NATIVE, hEvent);
}

HRESULT WINAPI BIDirectInputDeviceW::SetCooperativeLevel(LPDIRECTINPUTDEVICEW This, HWND hwnd, DWORD dwFlags)
{
  log_debug("BIDirectInputDeviceW::SetCooperativeLevel(%p)", THAT);
  return CALL_NATIVE(SetCooperativeLevel)(NATIVE, hwnd, dwFlags);
}

HRESULT WINAPI BIDirectInputDeviceW::GetObjectInfo(LPDIRECTINPUTDEVICEW This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow)
{
  log_debug("BIDirectInputDeviceW::GetObjectInfo(%p)", THAT);
  return CALL_NATIVE(GetObjectInfo)(NATIVE, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI BIDirectInputDeviceW::GetDeviceInfo(LPDIRECTINPUTDEVICEW This, LPDIDEVICEINSTANCEW pdidi)
{
  log_debug("BIDirectInputDeviceW::GetDeviceInfo(%p)", THAT);
  return CALL_NATIVE(GetDeviceInfo)(NATIVE, pdidi);
}

HRESULT WINAPI BIDirectInputDeviceW::RunControlPanel(LPDIRECTINPUTDEVICEW This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputDeviceW::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputDeviceW::Initialize(LPDIRECTINPUTDEVICEW This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  log_debug("BIDirectInputDeviceW::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion, rguid);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInputDeviceW::BIDirectInputDeviceW(LPDIRECTINPUTDEVICEW pNative, VIDirectInputDeviceW const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInputDeviceW::BIDirectInputDeviceW(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInputDeviceW::~BIDirectInputDeviceW()
{
  log_debug("BIDirectInputDeviceW::~BIDirectInputDeviceW(%p)", this);
}

VIDirectInputDeviceW const BIDirectInputDeviceW::vtbl_ =
{
  /*** IUnknown methods ***/
  &BIDirectInputDeviceW::QueryInterface,
  &BIDirectInputDeviceW::AddRef,
  &BIDirectInputDeviceW::Release,
  /*** IDirectInputDeviceW methods ***/
  &BIDirectInputDeviceW::GetCapabilities,
  &BIDirectInputDeviceW::EnumObjects,
  &BIDirectInputDeviceW::GetProperty,
  &BIDirectInputDeviceW::SetProperty,
  &BIDirectInputDeviceW::Acquire,
  &BIDirectInputDeviceW::Unacquire,
  &BIDirectInputDeviceW::GetDeviceState,
  &BIDirectInputDeviceW::GetDeviceData,
  &BIDirectInputDeviceW::SetDataFormat,
  &BIDirectInputDeviceW::SetEventNotification,
  &BIDirectInputDeviceW::SetCooperativeLevel,
  &BIDirectInputDeviceW::GetObjectInfo,
  &BIDirectInputDeviceW::GetDeviceInfo,
  &BIDirectInputDeviceW::RunControlPanel,
  &BIDirectInputDeviceW::Initialize
};

/* WIDirectInputDevice2W */
#define THAT reinterpret_cast<BIDirectInputDevice2W*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDevice2W::QueryInterface(LPDIRECTINPUTDEVICE2W This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDevice2W::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInputDevice2W::AddRef(LPDIRECTINPUTDEVICE2W This)
{
  log_debug("BIDirectInputDevice2W::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputDevice2W::Release(LPDIRECTINPUTDEVICE2W This)
{
  log_debug("BIDirectInputDevice2W::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInputDevice2W::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

/*** IDirectInputDeviceW methods ***/
HRESULT WINAPI BIDirectInputDevice2W::GetCapabilities(LPDIRECTINPUTDEVICE2W This, LPDIDEVCAPS lpDIDevCaps)
{
  log_debug("BIDirectInputDevice2W::GetCapabilities(%p)", THAT);
  return CALL_NATIVE(GetCapabilities)(NATIVE, lpDIDevCaps);
}

HRESULT WINAPI BIDirectInputDevice2W::EnumObjects(LPDIRECTINPUTDEVICE2W This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice2W::EnumObjects(%p)", THAT);
  return CALL_NATIVE(EnumObjects)(NATIVE, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice2W::GetProperty(LPDIRECTINPUTDEVICE2W This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice2W::GetProperty(%p)", THAT);
  return CALL_NATIVE(GetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice2W::SetProperty(LPDIRECTINPUTDEVICE2W This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice2W::SetProperty(%p)", THAT);
  return CALL_NATIVE(SetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice2W::Acquire(LPDIRECTINPUTDEVICE2W This)
{
  log_debug("BIDirectInputDevice2W::Acquire(%p)", THAT);
  return CALL_NATIVE(Acquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice2W::Unacquire(LPDIRECTINPUTDEVICE2W This)
{
  log_debug("BIDirectInputDevice2W::Unacquire(%p)", THAT);
  return CALL_NATIVE(Unacquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice2W::GetDeviceState(LPDIRECTINPUTDEVICE2W This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BIDirectInputDevice2W::GetDeviceState(%p)", THAT);
  return CALL_NATIVE(GetDeviceState)(NATIVE, cbData, lpvData);
}

HRESULT WINAPI BIDirectInputDevice2W::GetDeviceData(LPDIRECTINPUTDEVICE2W This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice2W::GetDeviceData(%p)", THAT);
  return CALL_NATIVE(GetDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice2W::SetDataFormat(LPDIRECTINPUTDEVICE2W This, LPCDIDATAFORMAT lpdf)
{
  log_debug("BIDirectInputDevice2W::SetDataFormat(%p)", THAT);
  return CALL_NATIVE(SetDataFormat)(NATIVE, lpdf);
}

HRESULT WINAPI BIDirectInputDevice2W::SetEventNotification(LPDIRECTINPUTDEVICE2W This, HANDLE hEvent)
{
  log_debug("BIDirectInputDevice2W::SetEventNotification(%p)", THAT);
  return CALL_NATIVE(SetEventNotification)(NATIVE, hEvent);
}

HRESULT WINAPI BIDirectInputDevice2W::SetCooperativeLevel(LPDIRECTINPUTDEVICE2W This, HWND hwnd, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice2W::SetCooperativeLevel(%p)", THAT);
  return CALL_NATIVE(SetCooperativeLevel)(NATIVE, hwnd, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice2W::GetObjectInfo(LPDIRECTINPUTDEVICE2W This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow)
{
  log_debug("BIDirectInputDevice2W::GetObjectInfo(%p)", THAT);
  return CALL_NATIVE(GetObjectInfo)(NATIVE, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI BIDirectInputDevice2W::GetDeviceInfo(LPDIRECTINPUTDEVICE2W This, LPDIDEVICEINSTANCEW pdidi)
{
  log_debug("BIDirectInputDevice2W::GetDeviceInfo(%p)", THAT);
  return CALL_NATIVE(GetDeviceInfo)(NATIVE, pdidi);
}

HRESULT WINAPI BIDirectInputDevice2W::RunControlPanel(LPDIRECTINPUTDEVICE2W This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice2W::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice2W::Initialize(LPDIRECTINPUTDEVICE2W This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  log_debug("BIDirectInputDevice2W::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion, rguid);
}

/*** IDirectInputDevice2W methods ***/
HRESULT WINAPI BIDirectInputDevice2W::CreateEffect(LPDIRECTINPUTDEVICE2W This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  log_debug("BIDirectInputDevice2W::CreateEffect(%p)", THAT);
  return CALL_NATIVE(CreateEffect)(NATIVE, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI BIDirectInputDevice2W::EnumEffects(LPDIRECTINPUTDEVICE2W This, LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  log_debug("BIDirectInputDevice2W::EnumEffects(%p)", THAT);
  return CALL_NATIVE(EnumEffects)(NATIVE, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI BIDirectInputDevice2W::GetEffectInfo(LPDIRECTINPUTDEVICE2W This, LPDIEFFECTINFOW pdei, REFGUID rguid)
{
  log_debug("BIDirectInputDevice2W::GetEffectInfo(%p)", THAT);
  return CALL_NATIVE(GetEffectInfo)(NATIVE, pdei, rguid);
}

HRESULT WINAPI BIDirectInputDevice2W::GetForceFeedbackState(LPDIRECTINPUTDEVICE2W This, LPDWORD pdwOut)
{
  log_debug("BIDirectInputDevice2W::GetForceFeedbackState(%p)", THAT);
  return CALL_NATIVE(GetForceFeedbackState)(NATIVE, pdwOut);
}

HRESULT WINAPI BIDirectInputDevice2W::SendForceFeedbackCommand(LPDIRECTINPUTDEVICE2W This, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice2W::SendForceFeedbackCommand(%p)", THAT);
  return CALL_NATIVE(SendForceFeedbackCommand)(NATIVE, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice2W::EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE2W This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  log_debug("BIDirectInputDevice2W::EnumCreatedEffectObjects(%p)", THAT);
  return CALL_NATIVE(EnumCreatedEffectObjects)(NATIVE, lpCallback, pvRef, fl);
}

HRESULT WINAPI BIDirectInputDevice2W::Escape(LPDIRECTINPUTDEVICE2W This, LPDIEFFESCAPE pesc)
{
  log_debug("BIDirectInputDevice2W::Escape(%p)", THAT);
  return CALL_NATIVE(Escape)(NATIVE, pesc);
}

HRESULT WINAPI BIDirectInputDevice2W::Poll(LPDIRECTINPUTDEVICE2W This)
{
  log_debug("BIDirectInputDevice2W::Poll(%p)", THAT);
  return CALL_NATIVE(Poll)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice2W::SendDeviceData(LPDIRECTINPUTDEVICE2W This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  log_debug("BIDirectInputDevice2W::SendDeviceData(%p)", THAT);
  return CALL_NATIVE(SendDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, fl);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInputDevice2W::BIDirectInputDevice2W(LPDIRECTINPUTDEVICE2W pNative, VIDirectInputDevice2W const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInputDevice2W::BIDirectInputDevice2W(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInputDevice2W::~BIDirectInputDevice2W()
{
  log_debug("BIDirectInputDevice2W::~BIDirectInputDevice2W(%p)", this);
}

VIDirectInputDevice2W const BIDirectInputDevice2W::vtbl_ =
{
  /*** IUnknown methods ***/
  &BIDirectInputDevice2W::QueryInterface,
  &BIDirectInputDevice2W::AddRef,
  &BIDirectInputDevice2W::Release,
  /*** IDirectInputDeviceW methods ***/
  &BIDirectInputDevice2W::GetCapabilities,
  &BIDirectInputDevice2W::EnumObjects,
  &BIDirectInputDevice2W::GetProperty,
  &BIDirectInputDevice2W::SetProperty,
  &BIDirectInputDevice2W::Acquire,
  &BIDirectInputDevice2W::Unacquire,
  &BIDirectInputDevice2W::GetDeviceState,
  &BIDirectInputDevice2W::GetDeviceData,
  &BIDirectInputDevice2W::SetDataFormat,
  &BIDirectInputDevice2W::SetEventNotification,
  &BIDirectInputDevice2W::SetCooperativeLevel,
  &BIDirectInputDevice2W::GetObjectInfo,
  &BIDirectInputDevice2W::GetDeviceInfo,
  &BIDirectInputDevice2W::RunControlPanel,
  &BIDirectInputDevice2W::Initialize,
  /*** IDirectInputDevice2W methods ***/
  &BIDirectInputDevice2W::CreateEffect,
  &BIDirectInputDevice2W::EnumEffects,
  &BIDirectInputDevice2W::GetEffectInfo,
  &BIDirectInputDevice2W::GetForceFeedbackState,
  &BIDirectInputDevice2W::SendForceFeedbackCommand,
  &BIDirectInputDevice2W::EnumCreatedEffectObjects,
  &BIDirectInputDevice2W::Escape,
  &BIDirectInputDevice2W::Poll,
  &BIDirectInputDevice2W::SendDeviceData
};

/* WIDirectInputDevice7W */
#define THAT reinterpret_cast<BIDirectInputDevice7W*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDevice7W::QueryInterface(LPDIRECTINPUTDEVICE7W This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDevice7W::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInputDevice7W::AddRef(LPDIRECTINPUTDEVICE7W This)
{
  log_debug("BIDirectInputDevice7W::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputDevice7W::Release(LPDIRECTINPUTDEVICE7W This)
{
  log_debug("BIDirectInputDevice7W::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInputDevice7W::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

/*** IDirectInputDeviceW methods ***/
HRESULT WINAPI BIDirectInputDevice7W::GetCapabilities(LPDIRECTINPUTDEVICE7W This, LPDIDEVCAPS lpDIDevCaps)
{
  log_debug("BIDirectInputDevice7W::GetCapabilities(%p)", THAT);
  return CALL_NATIVE(GetCapabilities)(NATIVE, lpDIDevCaps);
}

HRESULT WINAPI BIDirectInputDevice7W::EnumObjects(LPDIRECTINPUTDEVICE7W This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7W::EnumObjects(%p)", THAT);
  return CALL_NATIVE(EnumObjects)(NATIVE, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice7W::GetProperty(LPDIRECTINPUTDEVICE7W This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice7W::GetProperty(%p)", THAT);
  return CALL_NATIVE(GetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice7W::SetProperty(LPDIRECTINPUTDEVICE7W This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice7W::SetProperty(%p)", THAT);
  return CALL_NATIVE(SetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice7W::Acquire(LPDIRECTINPUTDEVICE7W This)
{
  log_debug("BIDirectInputDevice7W::Acquire(%p)", THAT);
  return CALL_NATIVE(Acquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice7W::Unacquire(LPDIRECTINPUTDEVICE7W This)
{
  log_debug("BIDirectInputDevice7W::Unacquire(%p)", THAT);
  return CALL_NATIVE(Unacquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice7W::GetDeviceState(LPDIRECTINPUTDEVICE7W This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BIDirectInputDevice7W::GetDeviceState(%p)", THAT);
  return CALL_NATIVE(GetDeviceState)(NATIVE, cbData, lpvData);
}

HRESULT WINAPI BIDirectInputDevice7W::GetDeviceData(LPDIRECTINPUTDEVICE7W This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7W::GetDeviceData(%p)", THAT);
  return CALL_NATIVE(GetDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice7W::SetDataFormat(LPDIRECTINPUTDEVICE7W This, LPCDIDATAFORMAT lpdf)
{
  log_debug("BIDirectInputDevice7W::SetDataFormat(%p)", THAT);
  return CALL_NATIVE(SetDataFormat)(NATIVE, lpdf);
}

HRESULT WINAPI BIDirectInputDevice7W::SetEventNotification(LPDIRECTINPUTDEVICE7W This, HANDLE hEvent)
{
  log_debug("BIDirectInputDevice7W::SetEventNotification(%p)", THAT);
  return CALL_NATIVE(SetEventNotification)(NATIVE, hEvent);
}

HRESULT WINAPI BIDirectInputDevice7W::SetCooperativeLevel(LPDIRECTINPUTDEVICE7W This, HWND hwnd, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7W::SetCooperativeLevel(%p)", THAT);
  return CALL_NATIVE(SetCooperativeLevel)(NATIVE, hwnd, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice7W::GetObjectInfo(LPDIRECTINPUTDEVICE7W This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow)
{
  log_debug("BIDirectInputDevice7W::GetObjectInfo(%p)", THAT);
  return CALL_NATIVE(GetObjectInfo)(NATIVE, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI BIDirectInputDevice7W::GetDeviceInfo(LPDIRECTINPUTDEVICE7W This, LPDIDEVICEINSTANCEW pdidi)
{
  log_debug("BIDirectInputDevice7W::GetDeviceInfo(%p)", THAT);
  return CALL_NATIVE(GetDeviceInfo)(NATIVE, pdidi);
}

HRESULT WINAPI BIDirectInputDevice7W::RunControlPanel(LPDIRECTINPUTDEVICE7W This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7W::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice7W::Initialize(LPDIRECTINPUTDEVICE7W This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  log_debug("BIDirectInputDevice7W::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion, rguid);
}

/*** IDirectInputDevice2W methods ***/
HRESULT WINAPI BIDirectInputDevice7W::CreateEffect(LPDIRECTINPUTDEVICE7W This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  log_debug("BIDirectInputDevice7W::CreateEffect(%p)", THAT);
  return CALL_NATIVE(CreateEffect)(NATIVE, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI BIDirectInputDevice7W::EnumEffects(LPDIRECTINPUTDEVICE7W This, LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  log_debug("BIDirectInputDevice7W::EnumEffects(%p)", THAT);
  return CALL_NATIVE(EnumEffects)(NATIVE, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI BIDirectInputDevice7W::GetEffectInfo(LPDIRECTINPUTDEVICE7W This, LPDIEFFECTINFOW pdei, REFGUID rguid)
{
  log_debug("BIDirectInputDevice7W::GetEffectInfo(%p)", THAT);
  return CALL_NATIVE(GetEffectInfo)(NATIVE, pdei, rguid);
}

HRESULT WINAPI BIDirectInputDevice7W::GetForceFeedbackState(LPDIRECTINPUTDEVICE7W This, LPDWORD pdwOut)
{
  log_debug("BIDirectInputDevice7W::GetForceFeedbackState(%p)", THAT);
  return CALL_NATIVE(GetForceFeedbackState)(NATIVE, pdwOut);
}

HRESULT WINAPI BIDirectInputDevice7W::SendForceFeedbackCommand(LPDIRECTINPUTDEVICE7W This, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7W::SendForceFeedbackCommand(%p)", THAT);
  return CALL_NATIVE(SendForceFeedbackCommand)(NATIVE, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice7W::EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE7W This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  log_debug("BIDirectInputDevice7W::EnumCreatedEffectObjects(%p)", THAT);
  return CALL_NATIVE(EnumCreatedEffectObjects)(NATIVE, lpCallback, pvRef, fl);
}

HRESULT WINAPI BIDirectInputDevice7W::Escape(LPDIRECTINPUTDEVICE7W This, LPDIEFFESCAPE pesc)
{
  log_debug("BIDirectInputDevice7W::Escape(%p)", THAT);
  return CALL_NATIVE(Escape)(NATIVE, pesc);
}

HRESULT WINAPI BIDirectInputDevice7W::Poll(LPDIRECTINPUTDEVICE7W This)
{
  log_debug("BIDirectInputDevice7W::Poll(%p)", THAT);
  return CALL_NATIVE(Poll)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice7W::SendDeviceData(LPDIRECTINPUTDEVICE7W This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  log_debug("BIDirectInputDevice7W::SendDeviceData(%p)", THAT);
  return CALL_NATIVE(SendDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, fl);
}

/*** IDirectInputDevice7W methods ***/
HRESULT WINAPI BIDirectInputDevice7W::EnumEffectsInFile(LPDIRECTINPUTDEVICE7W This, LPCWSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7W::EnumEffectsInFile(%p)", THAT);
  return CALL_NATIVE(EnumEffectsInFile)(NATIVE, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice7W::WriteEffectToFile(LPDIRECTINPUTDEVICE7W This, LPCWSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice7W::WriteEffectToFile(%p)", THAT);
  return CALL_NATIVE(WriteEffectToFile)(NATIVE, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInputDevice7W::BIDirectInputDevice7W(LPDIRECTINPUTDEVICE7W pNative, VIDirectInputDevice7W const * pVtbl, bool deleteSelf)
  : pVtbl_(pVtbl), pNative_(pNative), deleteSelf_(deleteSelf)
{
  log_debug("BIDirectInputDevice7W::BIDirectInputDevice7W(%p, %p, %p, %d)", this, pVtbl, pNative, deleteSelf);
  if (pVtbl_ == nullptr)
    pVtbl_ = &vtbl_;
}

BIDirectInputDevice7W::~BIDirectInputDevice7W()
{
  log_debug("BIDirectInputDevice7W::~BIDirectInputDevice7W(%p)", this);
}

VIDirectInputDevice7W const BIDirectInputDevice7W::vtbl_ =
{
  /*** IUnknown methods ***/
  &BIDirectInputDevice7W::QueryInterface,
  &BIDirectInputDevice7W::AddRef,
  &BIDirectInputDevice7W::Release,
  /*** IDirectInputDeviceW methods ***/
  &BIDirectInputDevice7W::GetCapabilities,
  &BIDirectInputDevice7W::EnumObjects,
  &BIDirectInputDevice7W::GetProperty,
  &BIDirectInputDevice7W::SetProperty,
  &BIDirectInputDevice7W::Acquire,
  &BIDirectInputDevice7W::Unacquire,
  &BIDirectInputDevice7W::GetDeviceState,
  &BIDirectInputDevice7W::GetDeviceData,
  &BIDirectInputDevice7W::SetDataFormat,
  &BIDirectInputDevice7W::SetEventNotification,
  &BIDirectInputDevice7W::SetCooperativeLevel,
  &BIDirectInputDevice7W::GetObjectInfo,
  &BIDirectInputDevice7W::GetDeviceInfo,
  &BIDirectInputDevice7W::RunControlPanel,
  &BIDirectInputDevice7W::Initialize,
  /*** IDirectInputDevice2W methods ***/
  &BIDirectInputDevice7W::CreateEffect,
  &BIDirectInputDevice7W::EnumEffects,
  &BIDirectInputDevice7W::GetEffectInfo,
  &BIDirectInputDevice7W::GetForceFeedbackState,
  &BIDirectInputDevice7W::SendForceFeedbackCommand,
  &BIDirectInputDevice7W::EnumCreatedEffectObjects,
  &BIDirectInputDevice7W::Escape,
  &BIDirectInputDevice7W::Poll,
  &BIDirectInputDevice7W::SendDeviceData,
  /*** IDirectInputDevice7W methods ***/
  &BIDirectInputDevice7W::EnumEffectsInFile,
  &BIDirectInputDevice7W::WriteEffectToFile
};

/* WIDirectInputDevice8W */
#define THAT reinterpret_cast<BIDirectInputDevice8W*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDevice8W::QueryInterface(LPDIRECTINPUTDEVICE8W This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDevice8W::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInputDevice8W::AddRef(LPDIRECTINPUTDEVICE8W This)
{
  log_debug("BIDirectInputDevice8W::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputDevice8W::Release(LPDIRECTINPUTDEVICE8W This)
{
  log_debug("BIDirectInputDevice8W::Release(%p)", THAT);
  ULONG r = CALL_NATIVE(Release)(NATIVE);
  if ((r == 0) && (THAT->deleteSelf_))
  {
    log_debug("BIDirectInputDevice8W::Release(%p): deleting self", THAT);
    delete THAT;
  }
  return r;
}

/*** IDirectInputDeviceW methods ***/
HRESULT WINAPI BIDirectInputDevice8W::GetCapabilities(LPDIRECTINPUTDEVICE8W This, LPDIDEVCAPS lpDIDevCaps)
{
  log_debug("BIDirectInputDevice8W::GetCapabilities(%p)", THAT);
  return CALL_NATIVE(GetCapabilities)(NATIVE, lpDIDevCaps);
}

HRESULT WINAPI BIDirectInputDevice8W::EnumObjects(LPDIRECTINPUTDEVICE8W This, LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::EnumObjects(%p)", THAT);
  return CALL_NATIVE(EnumObjects)(NATIVE, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::GetProperty(LPDIRECTINPUTDEVICE8W This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice8W::GetProperty(%p)", THAT);
  return CALL_NATIVE(GetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice8W::SetProperty(LPDIRECTINPUTDEVICE8W This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice8W::SetProperty(%p)", THAT);
  return CALL_NATIVE(SetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice8W::Acquire(LPDIRECTINPUTDEVICE8W This)
{
  log_debug("BIDirectInputDevice8W::Acquire(%p)", THAT);
  return CALL_NATIVE(Acquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8W::Unacquire(LPDIRECTINPUTDEVICE8W This)
{
  log_debug("BIDirectInputDevice8W::Unacquire(%p)", THAT);
  return CALL_NATIVE(Unacquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8W::GetDeviceState(LPDIRECTINPUTDEVICE8W This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BIDirectInputDevice8W::GetDeviceState(%p)", THAT);
  return CALL_NATIVE(GetDeviceState)(NATIVE, cbData, lpvData);
}

HRESULT WINAPI BIDirectInputDevice8W::GetDeviceData(LPDIRECTINPUTDEVICE8W This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::GetDeviceData(%p)", THAT);
  return CALL_NATIVE(GetDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::SetDataFormat(LPDIRECTINPUTDEVICE8W This, LPCDIDATAFORMAT lpdf)
{
  log_debug("BIDirectInputDevice8W::SetDataFormat(%p)", THAT);
  return CALL_NATIVE(SetDataFormat)(NATIVE, lpdf);
}

HRESULT WINAPI BIDirectInputDevice8W::SetEventNotification(LPDIRECTINPUTDEVICE8W This, HANDLE hEvent)
{
  log_debug("BIDirectInputDevice8W::SetEventNotification(%p)", THAT);
  return CALL_NATIVE(SetEventNotification)(NATIVE, hEvent);
}

HRESULT WINAPI BIDirectInputDevice8W::SetCooperativeLevel(LPDIRECTINPUTDEVICE8W This, HWND hwnd, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::SetCooperativeLevel(%p)", THAT);
  return CALL_NATIVE(SetCooperativeLevel)(NATIVE, hwnd, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::GetObjectInfo(LPDIRECTINPUTDEVICE8W This, LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow)
{
  log_debug("BIDirectInputDevice8W::GetObjectInfo(%p)", THAT);
  return CALL_NATIVE(GetObjectInfo)(NATIVE, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI BIDirectInputDevice8W::GetDeviceInfo(LPDIRECTINPUTDEVICE8W This, LPDIDEVICEINSTANCEW pdidi)
{
  log_debug("BIDirectInputDevice8W::GetDeviceInfo(%p)", THAT);
  return CALL_NATIVE(GetDeviceInfo)(NATIVE, pdidi);
}

HRESULT WINAPI BIDirectInputDevice8W::RunControlPanel(LPDIRECTINPUTDEVICE8W This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::Initialize(LPDIRECTINPUTDEVICE8W This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  log_debug("BIDirectInputDevice8W::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion, rguid);
}

/*** IDirectInputDevice2W methods ***/
HRESULT WINAPI BIDirectInputDevice8W::CreateEffect(LPDIRECTINPUTDEVICE8W This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  log_debug("BIDirectInputDevice8W::CreateEffect(%p)", THAT);
  return CALL_NATIVE(CreateEffect)(NATIVE, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI BIDirectInputDevice8W::EnumEffects(LPDIRECTINPUTDEVICE8W This, LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  log_debug("BIDirectInputDevice8W::EnumEffects(%p)", THAT);
  return CALL_NATIVE(EnumEffects)(NATIVE, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI BIDirectInputDevice8W::GetEffectInfo(LPDIRECTINPUTDEVICE8W This, LPDIEFFECTINFOW pdei, REFGUID rguid)
{
  log_debug("BIDirectInputDevice8W::GetEffectInfo(%p)", THAT);
  return CALL_NATIVE(GetEffectInfo)(NATIVE, pdei, rguid);
}

HRESULT WINAPI BIDirectInputDevice8W::GetForceFeedbackState(LPDIRECTINPUTDEVICE8W This, LPDWORD pdwOut)
{
  log_debug("BIDirectInputDevice8W::GetForceFeedbackState(%p)", THAT);
  return CALL_NATIVE(GetForceFeedbackState)(NATIVE, pdwOut);
}

HRESULT WINAPI BIDirectInputDevice8W::SendForceFeedbackCommand(LPDIRECTINPUTDEVICE8W This, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::SendForceFeedbackCommand(%p)", THAT);
  return CALL_NATIVE(SendForceFeedbackCommand)(NATIVE, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::EnumCreatedEffectObjects(LPDIRECTINPUTDEVICE8W This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  log_debug("BIDirectInputDevice8W::EnumCreatedEffectObjects(%p)", THAT);
  return CALL_NATIVE(EnumCreatedEffectObjects)(NATIVE, lpCallback, pvRef, fl);
}

HRESULT WINAPI BIDirectInputDevice8W::Escape(LPDIRECTINPUTDEVICE8W This, LPDIEFFESCAPE pesc)
{
  log_debug("BIDirectInputDevice8W::Escape(%p)", THAT);
  return CALL_NATIVE(Escape)(NATIVE, pesc);
}

HRESULT WINAPI BIDirectInputDevice8W::Poll(LPDIRECTINPUTDEVICE8W This)
{
  log_debug("BIDirectInputDevice8W::Poll(%p)", THAT);
  return CALL_NATIVE(Poll)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8W::SendDeviceData(LPDIRECTINPUTDEVICE8W This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  log_debug("BIDirectInputDevice8W::SendDeviceData(%p)", THAT);
  return CALL_NATIVE(SendDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, fl);
}

/*** IDirectInputDevice7W methods ***/
HRESULT WINAPI BIDirectInputDevice8W::EnumEffectsInFile(LPDIRECTINPUTDEVICE8W This, LPCWSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::EnumEffectsInFile(%p)", THAT);
  return CALL_NATIVE(EnumEffectsInFile)(NATIVE, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::WriteEffectToFile(LPDIRECTINPUTDEVICE8W This, LPCWSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::WriteEffectToFile(%p)", THAT);
  return CALL_NATIVE(WriteEffectToFile)(NATIVE, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

/*** IDirectInputDevice8W methods ***/
HRESULT WINAPI BIDirectInputDevice8W::BuildActionMap(LPDIRECTINPUTDEVICE8W This, LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::BuildActionMap(%p)", THAT);
  return CALL_NATIVE(BuildActionMap)(NATIVE, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::SetActionMap(LPDIRECTINPUTDEVICE8W This, LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8W::SetActionMap(%p)", THAT);
  return CALL_NATIVE(SetActionMap)(NATIVE, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8W::GetImageInfo(LPDIRECTINPUTDEVICE8W This, LPDIDEVICEIMAGEINFOHEADERW lpdiDevImageInfoHeader)
{
  log_debug("BIDirectInputDevice8W::GetImageInfo(%p)", THAT);
  return CALL_NATIVE(GetImageInfo)(NATIVE, lpdiDevImageInfoHeader);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInputDevice8W::BIDirectInputDevice8W(LPDIRECTINPUTDEVICE8W pNative, VIDirectInputDevice8W const * pVtbl, bool deleteSelf)
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
