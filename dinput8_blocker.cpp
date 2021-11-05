#include <dinput8_blocker.hpp>
#include <ctime>
#include <iomanip>
#include <mingw.thread.h>
#include <chrono>
#include <cassert>

#define DLLEXPORT __declspec(dllexport)

namespace di8b
{

struct print_time
{
  char const * fmt_;
  print_time(char const * fmt) : fmt_(fmt) {}
};

std::ostream & operator<< (std::ostream & os, print_time const & pt)
{
  auto tNow = std::time(nullptr);
  auto tmNow = std::localtime(&tNow);
  return os << std::put_time(tmNow, pt.fmt_);
}

std::ostream & logger()
{
  static std::ofstream of ("dinput8_blocker.log");
  static struct Reporter
  {
    char const * fmt = "%d.%m.%Y %H:%M:%S";
    Reporter() { of << "Logging started at " << print_time(fmt) << std::endl; }
    ~Reporter() { of << "Logging ended at " << print_time(fmt) << std::endl; }
  } reporter;
  auto tNow = std::time(nullptr);
  auto tmNow = std::localtime(&tNow);
  return of << print_time("%H:%M:%S: ");
}

void log_debug(char const * msg)
{
  logger() << "[DEBUG] " << msg << std::endl;
}

void log_info(char const * msg)
{
  logger() << "[INFO] " << msg << std::endl;
}

void log_error(char const * msg)
{
  logger() << "[ERROR] " << msg << std::endl;
}


bool g_state = true;
bool g_exiting = false;


/* WIDirectInputDevice8 */
VIDirectInputDevice8::VIDirectInputDevice8() : QueryInterface(WIDirectInputDevice8::QueryInterface), AddRef(WIDirectInputDevice8::AddRef), Release(WIDirectInputDevice8::Release), GetCapabilities(WIDirectInputDevice8::GetCapabilities), EnumObjects(WIDirectInputDevice8::EnumObjects), GetProperty(WIDirectInputDevice8::GetProperty), SetProperty(WIDirectInputDevice8::SetProperty), Acquire(WIDirectInputDevice8::Acquire), Unacquire(WIDirectInputDevice8::Unacquire), GetDeviceState(WIDirectInputDevice8::GetDeviceState), GetDeviceData(WIDirectInputDevice8::GetDeviceData), SetDataFormat(WIDirectInputDevice8::SetDataFormat), SetEventNotification(WIDirectInputDevice8::SetEventNotification), SetCooperativeLevel(WIDirectInputDevice8::SetCooperativeLevel), GetObjectInfo(WIDirectInputDevice8::GetObjectInfo), GetDeviceInfo(WIDirectInputDevice8::GetDeviceInfo), RunControlPanel(WIDirectInputDevice8::RunControlPanel), Initialize(WIDirectInputDevice8::Initialize), CreateEffect(WIDirectInputDevice8::CreateEffect), EnumEffects(WIDirectInputDevice8::EnumEffects), GetEffectInfo(WIDirectInputDevice8::GetEffectInfo), GetForceFeedbackState(WIDirectInputDevice8::GetForceFeedbackState), SendForceFeedbackCommand(WIDirectInputDevice8::SendForceFeedbackCommand), EnumCreatedEffectObjects(WIDirectInputDevice8::EnumCreatedEffectObjects), Escape(WIDirectInputDevice8::Escape), Poll(WIDirectInputDevice8::Poll), SendDeviceData(WIDirectInputDevice8::SendDeviceData), EnumEffectsInFile(WIDirectInputDevice8::EnumEffectsInFile), WriteEffectToFile(WIDirectInputDevice8::WriteEffectToFile), BuildActionMap(WIDirectInputDevice8::BuildActionMap), SetActionMap(WIDirectInputDevice8::SetActionMap), GetImageInfo(WIDirectInputDevice8::GetImageInfo)
{}

VIDirectInputDevice8 const WIDirectInputDevice8::vIDirectInputDevice8;

WIDirectInputDevice8::WIDirectInputDevice8(::IDirectInputDevice8* pNative, CIDirectInputDevice8* pCallback) 
  : pVtbl_(&vIDirectInputDevice8), pNative_(pNative), pCallback_(pCallback)
{
  log_debug("WIDirectInputDevice8::WIDirectInputDevice8()");
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
    log_debug("WIDirectInputDevice8::Release(): deleting self");
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
    log_debug("CIDirectInputDevice8::Release(): deleting self");
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


/* BlockingCIDirectInputDevice8 */
HRESULT BlockingCIDirectInputDevice8::GetDeviceData(::IDirectInputDevice8* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
  auto result = This->lpVtbl->GetDeviceData(This, cbObjectData, rgdod, pdwInOut, dwFlags);

  if (result == DI_OK && check_state() == false)
  {
    *pdwInOut = 0;
  }

  return result;
}

BlockingCIDirectInputDevice8::BlockingCIDirectInputDevice8(BlockingCIDirectInputDevice8::check_state_t const & check_state_) 
  : check_state(check_state_)
{}


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
    log_debug("WIDirectInput8::Release(): deleting self");
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
    log_debug("CIDirectInput8::Release(): deleting self");
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


/* WrappingCIDirectInput8 */
HRESULT WrappingCIDirectInput8::CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  auto result = CIDirectInput8::CreateDevice(This, rguid, lplpDirectInputDevice, pUnkOuter);
  if (result == S_OK)
  {
    auto upDeviceCallback = std::unique_ptr<CIDirectInputDevice8>(new CIDirectInputDevice8);
    auto upDeviceWrapper = std::unique_ptr<WIDirectInputDevice8>(new WIDirectInputDevice8(*lplpDirectInputDevice, upDeviceCallback.get()));
    *lplpDirectInputDevice = reinterpret_cast<LPDIRECTINPUTDEVICE8A>(upDeviceWrapper.release());
    upDeviceCallback.release();
  }
  return result;
}

WrappingCIDirectInput8::~WrappingCIDirectInput8() {}


DeviceKind get_device_kind(REFGUID rguid)
{
  if (IsEqualGUID(rguid, GUID_SysKeyboard))
    return DeviceKind::keyboard;
  else if (IsEqualGUID(rguid, GUID_SysMouse))
    return DeviceKind::mouse;
  else if (IsEqualGUID(rguid, GUID_Joystick))
    return DeviceKind::joystick;
  else
    return DeviceKind::other;
}


/* FactoryCIDirectInput8 */
HRESULT FactoryCIDirectInput8::CreateDevice(::IDirectInput8* This, REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
  HRESULT result = CIDirectInput8::CreateDevice(This, rguid, lplpDirectInputDevice, pUnkOuter);
  if (result == S_OK)
  {
    auto upDeviceCallback = make_callback_(rguid);
    auto upDeviceWrapper = std::unique_ptr<WIDirectInputDevice8>(new WIDirectInputDevice8(*lplpDirectInputDevice, upDeviceCallback.get()));
    *lplpDirectInputDevice = reinterpret_cast<LPDIRECTINPUTDEVICE8A>(upDeviceWrapper.release());
    upDeviceCallback.release();
  }
  return result;
}

FactoryCIDirectInput8::FactoryCIDirectInput8(FactoryCIDirectInput8::make_callback_t const & make_callback)
  : make_callback_(make_callback)
{}


std::unique_ptr<CIDirectInputDevice8> g_make_device_callback(REFGUID rguid)
{
  auto const deviceKind = get_device_kind(rguid);
  BlockingCIDirectInputDevice8::check_state_t check_state;
  switch (deviceKind)
  {
    case DeviceKind::mouse:
      check_state = [](){ return g_state; };
      break;
    default:
      check_state = [](){ return true; };
      break;
  }
  return std::unique_ptr<CIDirectInputDevice8>(new BlockingCIDirectInputDevice8(check_state));
}

/* loop */
void loop()
{
  while (true)
  {
    if (g_exiting)
      return;

    static auto wasPressed = false;
    static auto state = true, state2 = true;
    auto isPressed = GetKeyState(DI8B_TOGGLE_BLOCK_KEY) & 0x8000;
    if (isPressed && !wasPressed)
    {
      state = !state;
    }
    wasPressed = isPressed;

    state2 = GetKeyState(DI8B_UNBLOCK_KEY) & 0x8000;

    g_state = state || state2;

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

void start_loop()
{
  std::thread t (loop);
  t.detach();
}


/* Imports */
struct Imports
{
  struct Dinput8
  {
    decltype(::DirectInput8Create) * DirectInput8Create;
    decltype(::DllCanUnloadNow) * DllCanUnloadNow;
    decltype(::DllGetClassObject) * DllGetClassObject;
    decltype(::DllRegisterServer) * DllRegisterServer;
    decltype(::DllUnregisterServer) * DllUnregisterServer;
  } dinput8;

  void fill();
} g_imports;


void Imports::fill()
{
  log_debug("Filling imports");
  char szPath[MAX_PATH];

  if (!GetSystemDirectory(szPath, sizeof(szPath)))
    throw std::runtime_error("Failed to get system directory path");

  strcat(szPath, "\\dinput8.dll");
  HMODULE hNativeDinput8Dll = LoadLibrary(szPath);

  if (!hNativeDinput8Dll)
    throw std::runtime_error("Failed to get native dinput8.dll handle");

  dinput8.DirectInput8Create = reinterpret_cast<decltype(::DirectInput8Create) *>(GetProcAddress(hNativeDinput8Dll,"DirectInput8Create"));
  dinput8.DllCanUnloadNow = reinterpret_cast<decltype(::DllCanUnloadNow) *>(GetProcAddress(hNativeDinput8Dll,"DllCanUnloadNow"));
  dinput8.DllGetClassObject = reinterpret_cast<decltype(::DllGetClassObject) *>(GetProcAddress(hNativeDinput8Dll,"DllGetClassObject"));
  dinput8.DllRegisterServer = reinterpret_cast<decltype(::DllRegisterServer) *>(GetProcAddress(hNativeDinput8Dll,"DllRegisterServer"));
  dinput8.DllUnregisterServer = reinterpret_cast<decltype(::DllUnregisterServer) *>(GetProcAddress(hNativeDinput8Dll,"DllUnregisterServer"));

  log_debug("Filled imports");
  return;
}

} // namespace di8b


BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason,LPVOID v)
try {
  if (reason == DLL_PROCESS_ATTACH)
  {
    di8b::log_info("Dll attached");
    di8b::g_imports.fill();
    di8b::start_loop();
  }

  if (reason == DLL_PROCESS_DETACH)
  {
    di8b::log_info("Dll detached");
    di8b::g_exiting = true;
  }

  di8b::log_debug("DllMain success");
  return TRUE;
} catch (std::exception const & e)
{
  di8b::log_error(e.what());
  return FALSE;
}

extern "C" {

DLLEXPORT HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter)
{
  di8b::log_debug("DirectInput8Create");
  HRESULT result = di8b::g_imports.dinput8.DirectInput8Create(hinst, dwVersion, riidltf, ppvOut, punkOuter);
  if (result == S_OK)
  {
    auto upCallback = std::unique_ptr<di8b::FactoryCIDirectInput8>(new di8b::FactoryCIDirectInput8(di8b::g_make_device_callback));
    auto pIDirectInput8 = reinterpret_cast<IDirectInput8*>(*ppvOut);
    auto upWrapper = std::unique_ptr<di8b::WIDirectInput8>(new di8b::WIDirectInput8(pIDirectInput8, upCallback.get()));
    *ppvOut = upWrapper.release();
    upCallback.release();
  }
  return result;
}

DLLEXPORT HRESULT WINAPI DllCanUnloadNow()
{
  di8b::log_debug("DllCanUnloadNow");
  return di8b::g_imports.dinput8.DllCanUnloadNow();
}

DLLEXPORT HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
  di8b::log_debug("DllGetClassObject");
  return di8b::g_imports.dinput8.DllGetClassObject(rclsid, riid, ppv);
}

DLLEXPORT HRESULT WINAPI DllRegisterServer()
{
  di8b::log_debug("DllRegisterServer");
  return di8b::g_imports.dinput8.DllRegisterServer();
}

DLLEXPORT HRESULT WINAPI DllUnregisterServer()
{
  di8b::log_debug("DllUnregisterServer");
  return di8b::g_imports.dinput8.DllUnregisterServer();
}

} // extern "C"
