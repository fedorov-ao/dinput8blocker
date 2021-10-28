#i686-w64-mingw32-gcc-win32 -o dinput8.dll *.c -shared -I ../include -I /media/veracrypt1/axf/devel/dx9-sdk/c-sdk-directx9/Include -ldxguid -Wl,--out-implib,dinput8.lib,--output-def,dinput8.def

CC = i686-w64-mingw32-g++-win32
TARGET = dinput8.dll
DEF = $(TARGET:%.dll=%.def)
CFLAGS = -shared -I. -static-libstdc++ -static-libgcc
SOURCES = *.cpp
LDFLAGS = -Wl,--exclude-all-symbols,--enable-auto-import,--kill-at
INSTALL_PATH = ~/.wine/drive_c/1946

build: $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

install: build
	cp $(TARGET) $(INSTALL_PATH)

clean:
	rm  *.o *.def *.lib *.dll
