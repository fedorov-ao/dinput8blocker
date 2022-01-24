CC = i686-w64-mingw32-g++-win32
DI_TARGET = dinput.dll
DI8_TARGET = dinput8.dll
HEADERS = di8b_common.hpp di8b_wrappers.hpp di8b.hpp 
SOURCES = di8b_common.cpp di8b_wrappers.cpp di8b.cpp
DI_SOURCES = $(SOURCES) di8b_dinput.cpp
DI8_SOURCES = $(SOURCES) di8b_dinput8.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
DI_OBJECTS = $(DI_SOURCES:%.cpp=%.o)
DI8_OBJECTS = $(DI8_SOURCES:%.cpp=%.o)
#If compiled with -On, dll can not be loaded
#CFLAGS = -std=c++11 -I. -D_WIN32_WINNT=0x0501
CFLAGS = -std=c++11 -I. -D_WIN32_WINNT=0x0501 -DNDEBUG -Os -ffunction-sections -fdata-sections
#LDFLAGS = -static-libstdc++ -static-libgcc -shared -Wl,--exclude-all-symbols,--kill-at -ldxguid
LDFLAGS = -static-libstdc++ -static-libgcc -shared -s -Wl,--gc-sections,--exclude-all-symbols,--kill-at -ldxguid
INSTALL_PATH = ~/.wine/drive_c/1946

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $*.cpp

all_debug: di_debug di8_debug

di_debug: $(DI_OBJECTS)
	$(CC) $(CFLAGS) -o $(DI_TARGET) $(DI_OBJECTS) $(LDFLAGS)

di8_debug: $(DI8_OBJECTS)
	$(CC) $(CFLAGS) -o $(DI8_TARGET) $(DI8_OBJECTS) $(LDFLAGS)

di8_install:
	cp $(DI8_TARGET) $(INSTALL_PATH)

di8_uninstall:
	rm $(INSTALL_PATH)/$(DI8_TARGET) 

clean:
	rm  *.o *.def *.lib *.dll 2>1
