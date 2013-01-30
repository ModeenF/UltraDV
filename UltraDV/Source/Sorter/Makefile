NAME= sorter
TYPE= LIB
SRCS= TSorterBar.cpp TSorterContainer.cpp TSorterIconListItem.cpp TSorterList.cpp TSorterListItem.cpp

LIBS= /boot/develop/lib/x86/libroot.so /boot/develop/lib/x86/libbe.so /boot/develop/lib/x86/libmedia.so /boot/develop/lib/x86/libjpeg.so stdc++
LIBPATHS=
SYSTEM_INCLUDE_PATHS= /boot/develop/headers/be /boot/develop/headers/cpp /boot/develop/headers/posix /boot/home/config/include
LOCAL_INCLUDE_PATHS=  /boot/home/Desktop/UltraDV/Headers \
/boot/home/Desktop/UltraDV/Source/Editors/Headers \
/boot/home/Desktop/UltraDV/Source/AVINodes/AVIReader \
/boot/home/Desktop/UltraDV/Source/AVINodes/AVIWriter/Headers \
/boot/home/Desktop/UltraDV/Source/Engines/Headers \
/boot/home/Desktop/UltraDV/Source/Transitions/Headers \
/boot/home/Desktop/UltraDV/Source/add-ons/cues/media/Headers \
/boot/home/Desktop/UltraDV/Source/AVINodes/Shared/Headers

OPTIMIZE=NONE
#	specify any preprocessor symbols to be defined.  The symbols will not
#	have their values set automatically; you must supply the value (if any)
#	to use.  For example, setting DEFINES to "DEBUG=1" will cause the
#	compiler option "-DDEBUG=1" to be used.  Setting DEFINES to "DEBUG"
#	would pass "-DDEBUG" on the compiler's command line.
DEFINES=
#	specify special warning levels
#	if unspecified default warnings will be used
#	NONE = supress all warnings
#	ALL = enable all warnings
WARNINGS =
# Build with debugging symbols if set to TRUE
SYMBOLS=
COMPILER_FLAGS= -fpermissive  -g -fPIC
LINKER_FLAGS=

## include the makefile-engine
include $(BUILDHOME)/etc/makefile-engine

SO2:
	cd objects.x86-gcc2-release; gcc -shared -o Sorter.so *.o
	cp objects.x86-gcc2-release/Sorter.so ../../../so

SO4:
	cd objects.x86-gcc4-release; gcc -shared -o Sorter.so *.o; cp Sorter.so ../../../so4/Sorter.so

OBJ:
	cd objects.x86-gcc4-release;  cp *.o ../../link
	
Clean:
	rm -f objects.x86-gcc4-release/*.o
	rm -f objects.x86-gcc4-release/*.d
	rm -f objects.x86-gcc2-release/*.o
	rm -f objects.x86-gcc2-release/*.d

