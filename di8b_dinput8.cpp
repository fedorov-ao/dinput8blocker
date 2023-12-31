#include "di8b.hpp"

extern "C"
{

DLLEXPORT HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter);
DLLEXPORT HRESULT WINAPI DllCanUnloadNow();
DLLEXPORT HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv);
DLLEXPORT HRESULT WINAPI DllRegisterServer();
DLLEXPORT HRESULT WINAPI DllUnregisterServer();

} // extern "C"

namespace di8b
{

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
} g_imports;


void fill_imports()
{
  log_debug("Filling imports");

  LPCSTR dllName = "dinput8.dll";
  HMODULE hNext = get_next_handle(dllName);

  auto & dinput8 = g_imports.dinput8;
  dinput8.DirectInput8Create = reinterpret_cast<decltype(::DirectInput8Create) *>(GetProcAddress(hNext,"DirectInput8Create"));
  dinput8.DllCanUnloadNow = reinterpret_cast<decltype(::DllCanUnloadNow) *>(GetProcAddress(hNext,"DllCanUnloadNow"));
  dinput8.DllGetClassObject = reinterpret_cast<decltype(::DllGetClassObject) *>(GetProcAddress(hNext,"DllGetClassObject"));
  dinput8.DllRegisterServer = reinterpret_cast<decltype(::DllRegisterServer) *>(GetProcAddress(hNext,"DllRegisterServer"));
  dinput8.DllUnregisterServer = reinterpret_cast<decltype(::DllUnregisterServer) *>(GetProcAddress(hNext,"DllUnregisterServer"));

  log_debug("Filled imports");
}

} //di8b

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason,LPVOID v)
try {
  if (reason == DLL_PROCESS_ATTACH)
  {
    di8b::log_set_level(di8b::LogLevel::info);
    di8b::log_info("Dll attached");
    di8b::open_and_parse_config();
    di8b::init_log();
    di8b::fill_imports();
    di8b::start_loop();
  }

  if (reason == DLL_PROCESS_DETACH)
  {
    di8b::log_info("Dll detached");
    di8b::stop_loop();
  }

  return TRUE;
} catch (std::exception const & e)
{
  di8b::log_error(e.what());
  return FALSE;
}

extern "C"
{

DLLEXPORT HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter)
{
  di8b::log_debug("DirectInput8Create(%p, 0x%x, %s, %p, %p)", hinst, dwVersion, di8b::guid2str(riidltf).data(), ppvOut, punkOuter);
  LPVOID pvNative = nullptr;
  HRESULT result = di8b::g_imports.dinput8.DirectInput8Create(hinst, dwVersion, riidltf, &pvNative, punkOuter);
  if (result == S_OK)
  {
    di8b::log_debug("DirectInput8Create(): created native device: %p", pvNative);
    try
    {
      di8b::release_unique_ptr<IUnknown> upNative (reinterpret_cast<IUnknown*>(pvNative));
      LPVOID pWrapper = di8b::make_dinputxx_wrapper(riidltf, pvNative);
      if (pWrapper)
      {
        di8b::log_debug("DirectInput8Create(): created wrapper: %p", pWrapper);
        *ppvOut = pWrapper;
      }
      else
      {
        di8b::log_debug("DirectInput8Create(): could not create wrapper for: %p, using native", pvNative);
        *ppvOut = pvNative;
      }
      upNative.release();
    }
    catch (...)
    {
      di8b::log_error("DirectInput8Create(): Exception while creating wrapper, releasing native");
      throw;
    }
  }
  return result;
}

DLLEXPORT HRESULT WINAPI DllCanUnloadNow()
{
  di8b::log_debug("DllCanUnloadNow()");
  return di8b::g_imports.dinput8.DllCanUnloadNow();
}

DLLEXPORT HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
  di8b::log_debug("DllGetClassObject()");
  return di8b::g_imports.dinput8.DllGetClassObject(rclsid, riid, ppv);
}

DLLEXPORT HRESULT WINAPI DllRegisterServer()
{
  di8b::log_debug("DllRegisterServer()");
  return di8b::g_imports.dinput8.DllRegisterServer();
}

DLLEXPORT HRESULT WINAPI DllUnregisterServer()
{
  di8b::log_debug("DllUnregisterServer()");
  return di8b::g_imports.dinput8.DllUnregisterServer();
}

} // extern "C"
