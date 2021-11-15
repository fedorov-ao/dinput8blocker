CC = i686-w64-mingw32-g++-win32
TARGET = dinput8.dll
HEADERS = di8b_common.hpp di8b_wrappers.hpp di8b.hpp 
SOURCES = di8b_common.cpp di8b_wrappers.cpp di8b.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
CFLAGS = -std=c++11 -I. -D_WIN32_WINNT=0x0501
LDFLAGS = -static-libstdc++ -static-libgcc -shared -Wl,--exclude-all-symbols,--kill-at -ldxguid
INSTALL_PATH = ~/.wine/drive_c/1946

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $*.cpp

debug: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

install:
	cp $(TARGET) $(INSTALL_PATH)

uninstall:
	rm $(INSTALL_PATH)/$(TARGET) 

clean:
	rm  *.o *.def *.lib *.dll
