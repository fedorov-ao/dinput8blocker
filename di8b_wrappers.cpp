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
