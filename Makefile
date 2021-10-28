#i686-w64-mingw32-gcc-win32 -o dinput8.dll *.c -shared -I ../include -I /media/veracrypt1/axf/devel/dx9-sdk/c-sdk-directx9/Include -ldxguid -Wl,--out-implib,dinput8.lib,--output-def,dinput8.def

CC = i686-w64-mingw32-g++-win32
TARGET = dinput8.dll
DEF = $(TARGET:.dll=.def)
CFLAGS = -shared -I.
#First stage - build dll and def, edit def
SOURCES = *.cpp
LDFLAGS = -Wl,--output-def,$(DEF)
#Second stage - build dll using edited def
SOURCES_DEF = $(SOURCES) $(DEF)
LDFLAGS_DEF = 

build_def: $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

build: $(SOURCES) $(DEF)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES_DEF) $(LDFLAGS_DEF) 

clean:
	rm  *.o *.def *.lib *.dll
