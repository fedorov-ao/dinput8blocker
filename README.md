# dinput8_blocker

## Description

A dinput8.dll wrapper that blocks DirectInput for specific application. Blocking can be enabled and disabled, i.e. by pressing specified key on keyboard.

## Usage

Place compiled dinput8.dll in the same folder where application binary is located. Upon starting the application, it should load this wrapper dll. When app is running, press specified key to enable or disable input.

## Building

Written in C++. Compiled with mingw32-w64.

## Sources

* <https://github.com/SeanPesce/Library_Wrappers/>
* <https://github.com/elishacloud/dxwrapper/>
* <https://stackoverflow.com/questions/2720246/how-to-create-dll-using-gcc-compiler-mingw-for-visual-basic>
