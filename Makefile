TOGGLE_BLOCK_KEY = VK_SCROLL
UNBLOCK_KEY = VK_XBUTTON2

CC = i686-w64-mingw32-g++-win32
TARGET = dinput8.dll
DEF = $(TARGET:%.dll=%.def)
CFLAGS = -std=c++11 -shared -I. -static-libstdc++ -static-libgcc -D_WIN32_WINNT=0x0501 -DDI8B_TOGGLE_BLOCK_KEY=$(TOGGLE_BLOCK_KEY) -DDI8B_UNBLOCK_KEY=$(UNBLOCK_KEY)
SOURCES = *.cpp
LDFLAGS = -Wl,--exclude-all-symbols,--enable-auto-import,--kill-at -ldxguid
INSTALL_PATH = ~/.wine/drive_c/1946

build: $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

install: build
	cp $(TARGET) $(INSTALL_PATH)

clean:
	rm  *.o *.def *.lib *.dll
