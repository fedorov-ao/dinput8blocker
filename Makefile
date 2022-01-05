CC = i686-w64-mingw32-g++-win32
TARGET_DI = dinput.dll
TARGET_DI8 = dinput8.dll
HEADERS = di8b_common.hpp di8b_wrappers.hpp di8b.hpp 
SOURCES = di8b_common.cpp di8b_wrappers.cpp di8b.cpp
SOURCES_DI = $(SOURCES) di8b_dinput.cpp
SOURCES_DI8 = $(SOURCES) di8b_dinput8.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
OBJECTS_DI = $(SOURCES_DI:%.cpp=%.o)
OBJECTS_DI8 = $(SOURCES_DI8:%.cpp=%.o)
#If compiled with -On, dll can not be loaded
CFLAGS = -std=c++11 -I. -D_WIN32_WINNT=0x0501
#CFLAGS = -std=c++11 -I. -D_WIN32_WINNT=0x0501 -DNDEBUG -Os -ffunction-sections -fdata-sections
LDFLAGS = -static-libstdc++ -static-libgcc -shared -Wl,--exclude-all-symbols,--kill-at -ldxguid
#LDFLAGS = -static-libstdc++ -static-libgcc -shared -s -Wl,--gc-sections,--exclude-all-symbols,--kill-at -ldxguid
INSTALL_PATH = ~/.wine/drive_c/1946

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $*.cpp

debug_all: debug_di debug_di8

debug_di: $(OBJECTS_DI)
	$(CC) $(CFLAGS) -o $(TARGET_DI) $(OBJECTS_DI) $(LDFLAGS)

debug_di8: $(OBJECTS_DI8)
	$(CC) $(CFLAGS) -o $(TARGET_DI8) $(OBJECTS_DI8) $(LDFLAGS)

install_di8:
	cp $(TARGET_DI8) $(INSTALL_PATH)

uninstall_di8:
	rm $(INSTALL_PATH)/$(TARGET_DI8) 

clean:
	rm  *.o *.def *.lib *.dll
