NAME= AVIReader
TYPE= LIB
SRCS= AVIAddOn.cpp AVIApp.cpp AVIProducer.cpp AVIView.cpp AVIViewer.cpp AVIWindow.cpp make_media_addon.cpp TBitmapView.cpp

LIBS= be root media tracker midi stdc++ \
/boot/home/Desktop/UltraDV/so4/AVINodesShared.so \
/boot/home/Desktop/UltraDV/so4/AVIWriter.so 
#/boot/home/Desktop/UltraDV/so4/Media.so
#/boot/home/Desktop/UltraDV/so4/DVlib.so \

LIBPATHS= /boot/home/Desktop/UltraDV/so4 /boot/develop/lib/x86/gcc4/lib

SYSTEM_INCLUDE_PATHS= /boot/develop/headers/be /boot/develop/headers/cpp /boot/develop/headers/posix /boot/home/config/include
LOCAL_INCLUDE_PATHS=  /boot/home/Desktop/UltraDV/Headers \
/boot/home/Desktop/UltraDV/Source/Editors/Headers \
/boot/home/Desktop/UltraDV/Source/AVINodes/AVIReader \
/boot/home/Desktop/UltraDV/Source/AVINodes/AVIReader/Headers \
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

OBJ:
	cd objects.x86-gcc4-release;  cp *.o ../../link
	
Clean:
	rm -f objects.x86-gcc4-release/*.o
	rm -f objects.x86-gcc4-release/*.d
	rm -f objects.x86-gcc2-release/*.o
	rm -f objects.x86-gcc2-release/*.d

