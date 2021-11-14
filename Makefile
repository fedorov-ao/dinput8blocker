CC = i686-w64-mingw32-g++-win32
TARGET = dinput8.dll
DEF = $(TARGET:%.dll=%.def)
CFLAGS = -std=c++11 -shared -I. -static-libstdc++ -static-libgcc -D_WIN32_WINNT=0x0501
HEADERS = di8b_common.hpp di8b_wrappers.hpp di8b.hpp 
SOURCES = di8b_wrappers.cpp di8b.cpp
LDFLAGS = -Wl,--exclude-all-symbols,--kill-at -ldxguid
INSTALL_PATH = ~/.wine/drive_c/1946

debug: $(HEADERS) $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

install:
	cp $(TARGET) $(INSTALL_PATH)

uninstall:
	rm $(INSTALL_PATH)/$(TARGET) 

clean:
	rm  *.o *.def *.lib *.dll
