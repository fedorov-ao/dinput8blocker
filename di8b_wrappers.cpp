#include <di8b_wrappers.hpp>
#include <cassert>

namespace di8b
{

/* WIDirectInputDevice8 */
VIDirectInputDevice8::VIDirectInputDevice8() : QueryInterface(WIDirectInputDevice8::QueryInterface), AddRef(WIDirectInputDevice8::AddRef), Release(WIDirectInputDevice8::Release), GetCapabilities(WIDirectInputDevice8::GetCapabilities), EnumObjects(WIDirectInputDevice8::EnumObjects), GetProperty(WIDirectInputDevice8::GetProperty), SetProperty(WIDirectInputDevice8::SetProperty), Acquire(WIDirectInputDevice8::Acquire), Unacquire(WIDirectInputDevice8::Unacquire), GetDeviceState(WIDirectInputDevice8::GetDeviceState), GetDeviceData(WIDirectInputDevice8::GetDeviceData), SetDataFormat(WIDirectInputDevice8::SetDataFormat), SetEventNotification(WIDirectInputDevice8::SetEventNotification), SetCooperativeLevel(WIDirectInputDevice8::SetCooperativeLevel), GetObjectInfo(WIDirectInputDevice8::GetObjectInfo), GetDeviceInfo(WIDirectInputDevice8::GetDeviceInfo), RunControlPanel(WIDirectInputDevice8::RunControlPanel), Initialize(WIDirectInputDevice8::Initialize), CreateEffect(WIDirectInputDevice8::CreateEffect), EnumEffects(WIDirectInputDevice8::EnumEffects), GetEffectInfo(WIDirectInputDevice8::GetEffectInfo), GetForceFeedbackState(WIDirectInputDevice8::GetForceFeedbackState), SendForceFeedbackCommand(WIDirectInputDevice8::SendForceFeedbackCommand), EnumCreatedEffectObjects(WIDirectInputDevice8::EnumCreatedEffectObjects), Escape(WIDirectInputDevice8::Escape), Poll(WIDirectInputDevice8::Poll), SendDeviceData(WIDirectInputDevice8::SendDeviceData), EnumEffectsInFile(WIDirectInputDevice8::EnumEffectsInFile), WriteEffectToFile(WIDirectInputDevice8::WriteEffectToFile), BuildActionMap(WIDirectInputDevice8::BuildActionMap), SetActionMap(WIDirectInputDevice8::SetActionMap), GetImageInfo(WIDirectInputDevice8::GetImageInfo)
{}

VIDirectInputDevice8 const WIDirectInputDevice8::vIDirectInputDevice8;

WIDirectInputDevice8::WIDirectInputDevice8(::IDirectInputDevice8* pNative, CIDirectInputDevice8* pCallback)
  : pVtbl_(&vIDirectInputDevice8), pNative_(pNative), pCallback_(pCallback)
{
  log_debug("WIDirectInputDevice8::WIDirectInputDevice8(%p)", this);
}

HRESULT WINAPI WIDirectInputDevice8::QueryInterface(::IDirectInputDevice8* This, REFIID riid, void** ppvObject)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->QueryInterface(That->pNative_, riid, ppvObject);
}

ULONG WINAPI WIDirectInputDevice8::AddRef(::IDirectInputDevice8* This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->AddRef(That->pNative_);
}

ULONG WINAPI WIDirectInputDevice8::Release(::IDirectInputDevice8* This)
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

HRESULT WINAPI WIDirectInputDevice8::GetCapabilities(::IDirectInputDevice8* This, LPDIDEVCAPS lpDIDevCaps)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetCapabilities(That->pNative_, lpDIDevCaps);
}

HRESULT WINAPI WIDirectInputDevice8::EnumObjects(::IDirectInputDevice8* This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumObjects(That->pNative_, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::GetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetProperty(That->pNative_, rguidProp, pdiph);
}

HRESULT WINAPI WIDirectInputDevice8::SetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetProperty(That->pNative_, rguidProp, pdiph);
}

HRESULT WINAPI WIDirectInputDevice8::Acquire(::IDirectInputDevice8* This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Acquire(That->pNative_);
}

HRESULT WINAPI WIDirectInputDevice8::Unacquire(::IDirectInputDevice8* This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Unacquire(That->pNative_);
}

HRESULT WINAPI WIDirectInputDevice8::GetDeviceState(::IDirectInputDevice8* This, DWORD cbData, LPVOID lpvData)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetDeviceState(That->pNative_, cbData, lpvData);
}

HRESULT WINAPI WIDirectInputDevice8::GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetDeviceData(That->pNative_, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::SetDataFormat(::IDirectInputDevice8* This, LPCDIDATAFORMAT lpdf)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetDataFormat(That->pNative_, lpdf);
}

HRESULT WINAPI WIDirectInputDevice8::SetEventNotification(::IDirectInputDevice8* This, HANDLE hEvent)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetEventNotification(That->pNative_, hEvent);
}

HRESULT WINAPI WIDirectInputDevice8::SetCooperativeLevel(::IDirectInputDevice8* This, HWND hwnd, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetCooperativeLevel(That->pNative_, hwnd, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::GetObjectInfo(::IDirectInputDevice8* This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetObjectInfo(That->pNative_, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI WIDirectInputDevice8::GetDeviceInfo(::IDirectInputDevice8* This, LPDIDEVICEINSTANCEA pdidi)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetDeviceInfo(That->pNative_, pdidi);
}

HRESULT WINAPI WIDirectInputDevice8::RunControlPanel(::IDirectInputDevice8* This, HWND hwndOwner, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->RunControlPanel(That->pNative_, hwndOwner, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::Initialize(::IDirectInputDevice8* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Initialize(That->pNative_, hinst, dwVersion, rguid);
}

HRESULT WINAPI WIDirectInputDevice8::CreateEffect(::IDirectInputDevice8* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->CreateEffect(That->pNative_, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI WIDirectInputDevice8::EnumEffects(::IDirectInputDevice8* This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumEffects(That->pNative_, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI WIDirectInputDevice8::GetEffectInfo(::IDirectInputDevice8* This, LPDIEFFECTINFOA pdei, REFGUID rguid)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetEffectInfo(That->pNative_, pdei, rguid);
}

HRESULT WINAPI WIDirectInputDevice8::GetForceFeedbackState(::IDirectInputDevice8* This, LPDWORD pdwOut)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetForceFeedbackState(That->pNative_, pdwOut);
}

HRESULT WINAPI WIDirectInputDevice8::SendForceFeedbackCommand(::IDirectInputDevice8* This, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SendForceFeedbackCommand(That->pNative_, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::EnumCreatedEffectObjects(::IDirectInputDevice8* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumCreatedEffectObjects(That->pNative_, lpCallback, pvRef, fl);
}

HRESULT WINAPI WIDirectInputDevice8::Escape(::IDirectInputDevice8* This, LPDIEFFESCAPE pesc)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Escape(That->pNative_, pesc);
}

HRESULT WINAPI WIDirectInputDevice8::Poll(::IDirectInputDevice8* This)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Poll(That->pNative_);
}

HRESULT WINAPI WIDirectInputDevice8::SendDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SendDeviceData(That->pNative_, cbObjectData, rgdod, pdwInOut, fl);
}

HRESULT WINAPI WIDirectInputDevice8::EnumEffectsInFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumEffectsInFile(That->pNative_, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::WriteEffectToFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->WriteEffectToFile(That->pNative_, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::BuildActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->BuildActionMap(That->pNative_, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::SetActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->SetActionMap(That->pNative_, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI WIDirectInputDevice8::GetImageInfo(::IDirectInputDevice8* This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader)
{
  auto That = reinterpret_cast<WIDirectInputDevice8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetImageInfo(That->pNative_, lpdiDevImageInfoHeader);
}


/* CIDirectInputDevice8 */
HRESULT CIDirectInputDevice8::QueryInterface(::IDirectInputDevice8* This, REFIID riid, void** ppvObject)
{
  return This->lpVtbl->QueryInterface(This, riid, ppvObject);
}

ULONG CIDirectInputDevice8::AddRef(::IDirectInputDevice8* This)
{
  return This->lpVtbl->AddRef(This);
}

ULONG CIDirectInputDevice8::Release(::IDirectInputDevice8* This)
{
  auto refcount = This->lpVtbl->Release(This);
  if (refcount == 0)
  {
    log_debug("CIDirectInputDevice8::Release(%p): deleting self", this);
    delete this;
  }
  return refcount;
}

HRESULT CIDirectInputDevice8::GetCapabilities(::IDirectInputDevice8* This, LPDIDEVCAPS lpDIDevCaps)
{
  return This->lpVtbl->GetCapabilities(This, lpDIDevCaps);
}

HRESULT CIDirectInputDevice8::EnumObjects(::IDirectInputDevice8* This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  return This->lpVtbl->EnumObjects(This, lpCallback, pvRef, dwFlags);
}

HRESULT CIDirectInputDevice8::GetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  return This->lpVtbl->GetProperty(This, rguidProp, pdiph);
}

HRESULT CIDirectInputDevice8::SetProperty(::IDirectInputDevice8* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  return This->lpVtbl->SetProperty(This, rguidProp, pdiph);
}

HRESULT CIDirectInputDevice8::Acquire(::IDirectInputDevice8* This)
{
  return This->lpVtbl->Acquire(This);
}

HRESULT CIDirectInputDevice8::Unacquire(::IDirectInputDevice8* This)
{
  return This->lpVtbl->Unacquire(This);
}

HRESULT CIDirectInputDevice8::GetDeviceState(::IDirectInputDevice8* This, DWORD cbData, LPVOID lpvData)
{
  return This->lpVtbl->GetDeviceState(This, cbData, lpvData);
}

HRESULT CIDirectInputDevice8::GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  return This->lpVtbl->GetDeviceData(This, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT CIDirectInputDevice8::SetDataFormat(::IDirectInputDevice8* This, LPCDIDATAFORMAT lpdf)
{
  return This->lpVtbl->SetDataFormat(This, lpdf);
}

HRESULT CIDirectInputDevice8::SetEventNotification(::IDirectInputDevice8* This, HANDLE hEvent)
{
  return This->lpVtbl->SetEventNotification(This, hEvent);
}

HRESULT CIDirectInputDevice8::SetCooperativeLevel(::IDirectInputDevice8* This, HWND hwnd, DWORD dwFlags)
{
  return This->lpVtbl->SetCooperativeLevel(This, hwnd, dwFlags);
}

HRESULT CIDirectInputDevice8::GetObjectInfo(::IDirectInputDevice8* This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  return This->lpVtbl->GetObjectInfo(This, pdidoi, dwObj, dwHow);
}

HRESULT CIDirectInputDevice8::GetDeviceInfo(::IDirectInputDevice8* This, LPDIDEVICEINSTANCEA pdidi)
{
  return This->lpVtbl->GetDeviceInfo(This, pdidi);
}

HRESULT CIDirectInputDevice8::RunControlPanel(::IDirectInputDevice8* This, HWND hwndOwner, DWORD dwFlags)
{
  return This->lpVtbl->RunControlPanel(This, hwndOwner, dwFlags);
}

HRESULT CIDirectInputDevice8::Initialize(::IDirectInputDevice8* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  return This->lpVtbl->Initialize(This, hinst, dwVersion, rguid);
}

HRESULT CIDirectInputDevice8::CreateEffect(::IDirectInputDevice8* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  return This->lpVtbl->CreateEffect(This, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT CIDirectInputDevice8::EnumEffects(::IDirectInputDevice8* This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  return This->lpVtbl->EnumEffects(This, lpCallback, pvRef, dwEffType);
}

HRESULT CIDirectInputDevice8::GetEffectInfo(::IDirectInputDevice8* This, LPDIEFFECTINFOA pdei, REFGUID rguid)
{
  return This->lpVtbl->GetEffectInfo(This, pdei, rguid);
}

HRESULT CIDirectInputDevice8::GetForceFeedbackState(::IDirectInputDevice8* This, LPDWORD pdwOut)
{
  return This->lpVtbl->GetForceFeedbackState(This, pdwOut);
}

HRESULT CIDirectInputDevice8::SendForceFeedbackCommand(::IDirectInputDevice8* This, DWORD dwFlags)
{
  return This->lpVtbl->SendForceFeedbackCommand(This, dwFlags);
}

HRESULT CIDirectInputDevice8::EnumCreatedEffectObjects(::IDirectInputDevice8* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  return This->lpVtbl->EnumCreatedEffectObjects(This, lpCallback, pvRef, fl);
}

HRESULT CIDirectInputDevice8::Escape(::IDirectInputDevice8* This, LPDIEFFESCAPE pesc)
{
  return This->lpVtbl->Escape(This, pesc);
}

HRESULT CIDirectInputDevice8::Poll(::IDirectInputDevice8* This)
{
  return This->lpVtbl->Poll(This);
}

HRESULT CIDirectInputDevice8::SendDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  return This->lpVtbl->SendDeviceData(This, cbObjectData, rgdod, pdwInOut, fl);
}

HRESULT CIDirectInputDevice8::EnumEffectsInFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  return This->lpVtbl->EnumEffectsInFile(This, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT CIDirectInputDevice8::WriteEffectToFile(::IDirectInputDevice8* This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  return This->lpVtbl->WriteEffectToFile(This, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

HRESULT CIDirectInputDevice8::BuildActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  return This->lpVtbl->BuildActionMap(This, lpdiaf, lpszUserName, dwFlags);
}

HRESULT CIDirectInputDevice8::SetActionMap(::IDirectInputDevice8* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  return This->lpVtbl->SetActionMap(This, lpdiaf, lpszUserName, dwFlags);
}

HRESULT CIDirectInputDevice8::GetImageInfo(::IDirectInputDevice8* This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader)
{
  return This->lpVtbl->GetImageInfo(This, lpdiDevImageInfoHeader);
}

CIDirectInputDevice8::~CIDirectInputDevice8() {}


/* WIDirectInput8 */
VIDirectInput8::VIDirectInput8() : QueryInterface(WIDirectInput8::QueryInterface), AddRef(WIDirectInput8::AddRef), Release(WIDirectInput8::Release), CreateDevice(WIDirectInput8::CreateDevice), EnumDevices(WIDirectInput8::EnumDevices), GetDeviceStatus(WIDirectInput8::GetDeviceStatus), RunControlPanel(WIDirectInput8::RunControlPanel), Initialize(WIDirectInput8::Initialize), FindDevice(WIDirectInput8::FindDevice), EnumDevicesBySemantics(WIDirectInput8::EnumDevicesBySemantics), ConfigureDevices(WIDirectInput8::ConfigureDevices)
{}

VIDirectInput8 const WIDirectInput8::vIDirectInput8;

WIDirectInput8::WIDirectInput8(::IDirectInput8* pNative, CIDirectInput8* pCallback)
  : pVtbl_(&vIDirectInput8), pNative_(pNative), pCallback_(pCallback)
{}

HRESULT WINAPI WIDirectInput8::QueryInterface(::IDirectInput8* This, REFIID riid, void** ppvObject)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->QueryInterface(That->pNative_, riid, ppvObject);
}

ULONG WINAPI WIDirectInput8::AddRef(::IDirectInput8* This)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->AddRef(That->pNative_);
}

ULONG WINAPI WIDirectInput8::Release(::IDirectInput8* This)
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

HRESULT WINAPI WIDirectInput8::CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->CreateDevice(That->pNative_, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT WINAPI WIDirectInput8::EnumDevices(::IDirectInput8* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumDevices(That->pNative_, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInput8::GetDeviceStatus(::IDirectInput8* This, REFGUID rguidInstance)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->GetDeviceStatus(That->pNative_, rguidInstance);
}

HRESULT WINAPI WIDirectInput8::RunControlPanel(::IDirectInput8* This, HWND hwndOwner, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->RunControlPanel(That->pNative_, hwndOwner, dwFlags);
}

HRESULT WINAPI WIDirectInput8::Initialize(::IDirectInput8* This, HINSTANCE hinst, DWORD dwVersion)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->Initialize(That->pNative_, hinst, dwVersion);
}

HRESULT WINAPI WIDirectInput8::FindDevice(::IDirectInput8* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->FindDevice(That->pNative_, rguid, pszName, pguidInstance);
}

HRESULT WINAPI WIDirectInput8::EnumDevicesBySemantics(::IDirectInput8* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->EnumDevicesBySemantics(That->pNative_, ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI WIDirectInput8::ConfigureDevices(::IDirectInput8* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
  auto That = reinterpret_cast<WIDirectInput8*>(This);
  assert(That->pCallback_);
  return That->pCallback_->ConfigureDevices(That->pNative_, lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}


HRESULT CIDirectInput8::QueryInterface(::IDirectInput8* This, REFIID riid, void** ppvObject)
{
  return This->lpVtbl->QueryInterface(This, riid, ppvObject);
}

ULONG CIDirectInput8::AddRef(::IDirectInput8* This)
{
  return This->lpVtbl->AddRef(This);
}

ULONG CIDirectInput8::Release(::IDirectInput8* This)
{
  auto refcount = This->lpVtbl->Release(This);
  if (refcount == 0)
  {
    log_debug("CIDirectInput8::Release(%p): deleting self", this);
    delete this;
  }
  return refcount;
}

HRESULT CIDirectInput8::CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  return This->lpVtbl->CreateDevice(This, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT CIDirectInput8::EnumDevices(::IDirectInput8* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  return This->lpVtbl->EnumDevices(This, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT CIDirectInput8::GetDeviceStatus(::IDirectInput8* This, REFGUID rguidInstance)
{
  return This->lpVtbl->GetDeviceStatus(This, rguidInstance);
}

HRESULT CIDirectInput8::RunControlPanel(::IDirectInput8* This, HWND hwndOwner, DWORD dwFlags)
{
  return This->lpVtbl->RunControlPanel(This, hwndOwner, dwFlags);
}

HRESULT CIDirectInput8::Initialize(::IDirectInput8* This, HINSTANCE hinst, DWORD dwVersion)
{
  return This->lpVtbl->Initialize(This, hinst, dwVersion);
}

HRESULT CIDirectInput8::FindDevice(::IDirectInput8* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  return This->lpVtbl->FindDevice(This, rguid, pszName, pguidInstance);
}

HRESULT CIDirectInput8::EnumDevicesBySemantics(::IDirectInput8* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  return This->lpVtbl->EnumDevicesBySemantics(This, ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT CIDirectInput8::ConfigureDevices(::IDirectInput8* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
  return This->lpVtbl->ConfigureDevices(This, lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}

CIDirectInput8::~CIDirectInput8() {}


/* Templates */
/* WIDirectInputDevice8A */
#define THAT reinterpret_cast<BIDirectInputDevice8A*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
/*** IUnknown methods ***/
HRESULT WINAPI BIDirectInputDevice8A::QueryInterface(::IDirectInputDevice8A* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputDevice8A::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInputDevice8A::AddRef(::IDirectInputDevice8A* This)
{
  log_debug("BIDirectInputDevice8A::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputDevice8A::Release(::IDirectInputDevice8A* This)
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
HRESULT WINAPI BIDirectInputDevice8A::GetCapabilities(::IDirectInputDevice8A* This, LPDIDEVCAPS lpDIDevCaps)
{
  log_debug("BIDirectInputDevice8A::GetCapabilities(%p)", THAT);
  return CALL_NATIVE(GetCapabilities)(NATIVE, lpDIDevCaps);
}

HRESULT WINAPI BIDirectInputDevice8A::EnumObjects(::IDirectInputDevice8A* This, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::EnumObjects(%p)", THAT);
  return CALL_NATIVE(EnumObjects)(NATIVE, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::GetProperty(::IDirectInputDevice8A* This, REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice8A::GetProperty(%p)", THAT);
  return CALL_NATIVE(GetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice8A::SetProperty(::IDirectInputDevice8A* This, REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
  log_debug("BIDirectInputDevice8A::SetProperty(%p)", THAT);
  return CALL_NATIVE(SetProperty)(NATIVE, rguidProp, pdiph);
}

HRESULT WINAPI BIDirectInputDevice8A::Acquire(::IDirectInputDevice8A* This)
{
  log_debug("BIDirectInputDevice8A::Acquire(%p)", THAT);
  return CALL_NATIVE(Acquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8A::Unacquire(::IDirectInputDevice8A* This)
{
  log_debug("BIDirectInputDevice8A::Unacquire(%p)", THAT);
  return CALL_NATIVE(Unacquire)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8A::GetDeviceState(::IDirectInputDevice8A* This, DWORD cbData, LPVOID lpvData)
{
  log_debug("BIDirectInputDevice8A::GetDeviceState(%p)", THAT);
  return CALL_NATIVE(GetDeviceState)(NATIVE, cbData, lpvData);
}

HRESULT WINAPI BIDirectInputDevice8A::GetDeviceData(::IDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::GetDeviceData(%p)", THAT);
  return CALL_NATIVE(GetDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::SetDataFormat(::IDirectInputDevice8A* This, LPCDIDATAFORMAT lpdf)
{
  log_debug("BIDirectInputDevice8A::SetDataFormat(%p)", THAT);
  return CALL_NATIVE(SetDataFormat)(NATIVE, lpdf);
}

HRESULT WINAPI BIDirectInputDevice8A::SetEventNotification(::IDirectInputDevice8A* This, HANDLE hEvent)
{
  log_debug("BIDirectInputDevice8A::SetEventNotification(%p)", THAT);
  return CALL_NATIVE(SetEventNotification)(NATIVE, hEvent);
}

HRESULT WINAPI BIDirectInputDevice8A::SetCooperativeLevel(::IDirectInputDevice8A* This, HWND hwnd, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::SetCooperativeLevel(%p)", THAT);
  return CALL_NATIVE(SetCooperativeLevel)(NATIVE, hwnd, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::GetObjectInfo(::IDirectInputDevice8A* This, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
  log_debug("BIDirectInputDevice8A::GetObjectInfo(%p)", THAT);
  return CALL_NATIVE(GetObjectInfo)(NATIVE, pdidoi, dwObj, dwHow);
}

HRESULT WINAPI BIDirectInputDevice8A::GetDeviceInfo(::IDirectInputDevice8A* This, LPDIDEVICEINSTANCEA pdidi)
{
  log_debug("BIDirectInputDevice8A::GetDeviceInfo(%p)", THAT);
  return CALL_NATIVE(GetDeviceInfo)(NATIVE, pdidi);
}

HRESULT WINAPI BIDirectInputDevice8A::RunControlPanel(::IDirectInputDevice8A* This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::Initialize(::IDirectInputDevice8A* This, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
  log_debug("BIDirectInputDevice8A::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion, rguid);
}

/*** IDirectInputDevice2A methods ***/
HRESULT WINAPI BIDirectInputDevice8A::CreateEffect(::IDirectInputDevice8A* This, REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
  log_debug("BIDirectInputDevice8A::CreateEffect(%p)", THAT);
  return CALL_NATIVE(CreateEffect)(NATIVE, rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI BIDirectInputDevice8A::EnumEffects(::IDirectInputDevice8A* This, LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
  log_debug("BIDirectInputDevice8A::EnumEffects(%p)", THAT);
  return CALL_NATIVE(EnumEffects)(NATIVE, lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI BIDirectInputDevice8A::GetEffectInfo(::IDirectInputDevice8A* This, LPDIEFFECTINFOA pdei, REFGUID rguid)
{
  log_debug("BIDirectInputDevice8A::GetEffectInfo(%p)", THAT);
  return CALL_NATIVE(GetEffectInfo)(NATIVE, pdei, rguid);
}

HRESULT WINAPI BIDirectInputDevice8A::GetForceFeedbackState(::IDirectInputDevice8A* This, LPDWORD pdwOut)
{
  log_debug("BIDirectInputDevice8A::GetForceFeedbackState(%p)", THAT);
  return CALL_NATIVE(GetForceFeedbackState)(NATIVE, pdwOut);
}

HRESULT WINAPI BIDirectInputDevice8A::SendForceFeedbackCommand(::IDirectInputDevice8A* This, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::SendForceFeedbackCommand(%p)", THAT);
  return CALL_NATIVE(SendForceFeedbackCommand)(NATIVE, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::EnumCreatedEffectObjects(::IDirectInputDevice8A* This, LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
  log_debug("BIDirectInputDevice8A::EnumCreatedEffectObjects(%p)", THAT);
  return CALL_NATIVE(EnumCreatedEffectObjects)(NATIVE, lpCallback, pvRef, fl);
}

HRESULT WINAPI BIDirectInputDevice8A::Escape(::IDirectInputDevice8A* This, LPDIEFFESCAPE pesc)
{
  log_debug("BIDirectInputDevice8A::Escape(%p)", THAT);
  return CALL_NATIVE(Escape)(NATIVE, pesc);
}

HRESULT WINAPI BIDirectInputDevice8A::Poll(::IDirectInputDevice8A* This)
{
  log_debug("BIDirectInputDevice8A::Poll(%p)", THAT);
  return CALL_NATIVE(Poll)(NATIVE);
}

HRESULT WINAPI BIDirectInputDevice8A::SendDeviceData(::IDirectInputDevice8A* This, DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
  log_debug("BIDirectInputDevice8A::SendDeviceData(%p)", THAT);
  return CALL_NATIVE(SendDeviceData)(NATIVE, cbObjectData, rgdod, pdwInOut, fl);
}

/*** IDirectInputDevice7A methods ***/
HRESULT WINAPI BIDirectInputDevice8A::EnumEffectsInFile(::IDirectInputDevice8A* This, LPCSTR lpszFileName,LPDIENUMEFFECTSINFILECALLBACK pec,LPVOID pvRef,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::EnumEffectsInFile(%p)", THAT);
  return CALL_NATIVE(EnumEffectsInFile)(NATIVE, lpszFileName, pec, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::WriteEffectToFile(::IDirectInputDevice8A* This, LPCSTR lpszFileName,DWORD dwEntries,LPDIFILEEFFECT rgDiFileEft,DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::WriteEffectToFile(%p)", THAT);
  return CALL_NATIVE(WriteEffectToFile)(NATIVE, lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

/*** IDirectInputDevice8A methods ***/
HRESULT WINAPI BIDirectInputDevice8A::BuildActionMap(::IDirectInputDevice8A* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::BuildActionMap(%p)", THAT);
  return CALL_NATIVE(BuildActionMap)(NATIVE, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::SetActionMap(::IDirectInputDevice8A* This, LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
  log_debug("BIDirectInputDevice8A::SetActionMap(%p)", THAT);
  return CALL_NATIVE(SetActionMap)(NATIVE, lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI BIDirectInputDevice8A::GetImageInfo(::IDirectInputDevice8A* This, LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader)
{
  log_debug("BIDirectInputDevice8A::GetImageInfo(%p)", THAT);
  return CALL_NATIVE(GetImageInfo)(NATIVE, lpdiDevImageInfoHeader);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInputDevice8A::BIDirectInputDevice8A(::IDirectInputDevice8A* pNative, VIDirectInputDevice8A const * pVtbl, bool deleteSelf)
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


/* WIDirectInputA */
#define THAT reinterpret_cast<BIDirectInputA*>(This)
#define NATIVE THAT->pNative_
#define CALL_NATIVE(method) NATIVE->lpVtbl->method
HRESULT WINAPI BIDirectInputA::QueryInterface(::IDirectInputA* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInputA::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInputA::AddRef(::IDirectInputA* This)
{
  log_debug("BIDirectInputA::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInputA::Release(::IDirectInputA* This)
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

HRESULT WINAPI BIDirectInputA::CreateDevice(::IDirectInputA* This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInputA::CreateDevice(%p)", THAT);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT WINAPI BIDirectInputA::EnumDevices(::IDirectInputA* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInputA::EnumDevices(%p)", THAT);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInputA::GetDeviceStatus(::IDirectInputA* This, REFGUID rguidInstance)
{
  log_debug("BIDirectInputA::GetDeviceStatus(%p)", THAT);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInputA::RunControlPanel(::IDirectInputA* This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInputA::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInputA::Initialize(::IDirectInputA* This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInputA::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}
#undef CALL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInputA::BIDirectInputA(::IDirectInputA* pNative, VIDirectInputA const * pVtbl, bool deleteSelf)
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
HRESULT WINAPI BIDirectInput2A::QueryInterface(::IDirectInput2A* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput2A::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInput2A::AddRef(::IDirectInput2A* This)
{
  log_debug("BIDirectInput2A::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput2A::Release(::IDirectInput2A* This)
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

HRESULT WINAPI BIDirectInput2A::CreateDevice(::IDirectInput2A* This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput2A::CreateDevice(%p)", THAT);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT WINAPI BIDirectInput2A::EnumDevices(::IDirectInput2A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput2A::EnumDevices(%p)", THAT);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput2A::GetDeviceStatus(::IDirectInput2A* This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput2A::GetDeviceStatus(%p)", THAT);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput2A::RunControlPanel(::IDirectInput2A* This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput2A::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput2A::Initialize(::IDirectInput2A* This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput2A::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput2A::FindDevice(::IDirectInput2A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput2A::FindDevice(%p)", THAT);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}
#undef CAL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInput2A::BIDirectInput2A(::IDirectInput2A* pNative, VIDirectInput2A const * pVtbl, bool deleteSelf)
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
HRESULT WINAPI BIDirectInput7A::QueryInterface(::IDirectInput7A* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput7A::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInput7A::AddRef(::IDirectInput7A* This)
{
  log_debug("BIDirectInput7A::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput7A::Release(::IDirectInput7A* This)
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

HRESULT WINAPI BIDirectInput7A::CreateDevice(::IDirectInput7A* This, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput7A::CreateDevice(%p)", THAT);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT WINAPI BIDirectInput7A::EnumDevices(::IDirectInput7A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput7A::EnumDevices(%p)", THAT);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput7A::GetDeviceStatus(::IDirectInput7A* This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput7A::GetDeviceStatus(%p)", THAT);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput7A::RunControlPanel(::IDirectInput7A* This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput7A::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput7A::Initialize(::IDirectInput7A* This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput7A::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput7A::FindDevice(::IDirectInput7A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput7A::FindDevice(%p)", THAT);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}

HRESULT WINAPI BIDirectInput7A::CreateDeviceEx(::IDirectInput7A* This, REFGUID rguid, REFIID riid, LPVOID *pvOut, LPUNKNOWN lpUnknownOuter)
{
  log_debug("BIDirectInput7A::CreateDeviceEx(%p)", THAT);
  return CALL_NATIVE(CreateDeviceEx)(NATIVE, rguid, riid, pvOut, lpUnknownOuter);
}
#undef CAL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInput7A::BIDirectInput7A(::IDirectInput7A* pNative, VIDirectInput7A const * pVtbl, bool deleteSelf)
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
HRESULT WINAPI BIDirectInput8A::QueryInterface(::IDirectInput8A* This, REFIID riid, void** ppvObject)
{
  log_debug("BIDirectInput8A::QueryInterface(%p)", THAT);
  /* TODO Apparently should return pointer to wrapper. */
  return CALL_NATIVE(QueryInterface)(NATIVE, riid, ppvObject);
}

ULONG WINAPI BIDirectInput8A::AddRef(::IDirectInput8A* This)
{
  log_debug("BIDirectInput8A::AddRef(%p)", THAT);
  return CALL_NATIVE(AddRef)(NATIVE);
}

ULONG WINAPI BIDirectInput8A::Release(::IDirectInput8A* This)
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

HRESULT WINAPI BIDirectInput8A::CreateDevice(::IDirectInput8A* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  log_debug("BIDirectInput8A::CreateDevice(%p)", THAT);
  return CALL_NATIVE(CreateDevice)(NATIVE, rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT WINAPI BIDirectInput8A::EnumDevices(::IDirectInput8A* This, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput8A::EnumDevices(%p)", THAT);
  return CALL_NATIVE(EnumDevices)(NATIVE, dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput8A::GetDeviceStatus(::IDirectInput8A* This, REFGUID rguidInstance)
{
  log_debug("BIDirectInput8A::GetDeviceStatus(%p)", THAT);
  return CALL_NATIVE(GetDeviceStatus)(NATIVE, rguidInstance);
}

HRESULT WINAPI BIDirectInput8A::RunControlPanel(::IDirectInput8A* This, HWND hwndOwner, DWORD dwFlags)
{
  log_debug("BIDirectInput8A::RunControlPanel(%p)", THAT);
  return CALL_NATIVE(RunControlPanel)(NATIVE, hwndOwner, dwFlags);
}

HRESULT WINAPI BIDirectInput8A::Initialize(::IDirectInput8A* This, HINSTANCE hinst, DWORD dwVersion)
{
  log_debug("BIDirectInput8A::Initialize(%p)", THAT);
  return CALL_NATIVE(Initialize)(NATIVE, hinst, dwVersion);
}

HRESULT WINAPI BIDirectInput8A::FindDevice(::IDirectInput8A* This, REFGUID rguid, LPCSTR pszName, LPGUID pguidInstance)
{
  log_debug("BIDirectInput8A::FindDevice(%p)", THAT);
  return CALL_NATIVE(FindDevice)(NATIVE, rguid, pszName, pguidInstance);
}

HRESULT WINAPI BIDirectInput8A::EnumDevicesBySemantics(::IDirectInput8A* This, LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
  log_debug("BIDirectInput8A::EnumDevicesBySemantics(%p)", THAT);
  return CALL_NATIVE(EnumDevicesBySemantics)(NATIVE, ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI BIDirectInput8A::ConfigureDevices(::IDirectInput8A* This, LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
  log_debug("BIDirectInput8A::ConfigureDevices(%p)", THAT);
  return CALL_NATIVE(ConfigureDevices)(NATIVE, lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}
#undef CAL_NATIVE
#undef NATIVE
#undef THAT

BIDirectInput8A::BIDirectInput8A(::IDirectInput8A* pNative, VIDirectInput8A const * pVtbl, bool deleteSelf)
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

} //namespace di8b
