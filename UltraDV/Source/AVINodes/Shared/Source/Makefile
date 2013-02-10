NAME= ACTION
TYPE= LIB
SRCS= AVIUtils.cpp TAppleVideoCodec.cpp TAudioCodec.cpp TCinepakCodec.cpp TimedBufferQueue.cpp \
TMSRLECodec.cpp TMSVideoCodec.cpp TPCMCodec.cpp TRGBCodec.cpp TRIFFReader.cpp TRIFFWriter.cpp \
TVideoCodec.cpp InfoAlert.cpp


RSRCS=
LIBS= 


SYSTEM_INCLUDE_PATHS= /boot/develop/lib/x86 /boot/develop/headers/cpp \
/boot/develop/headers/posix /boot/home/config/include 


LOCAL_INCLUDE_PATHS=  /boot/home/Desktop/UltraDV/Headers \
/boot/home/Desktop/UltraDV/Source/Editors/Headers \
/boot/home/Desktop/UltraDV/Source/AVINodes/AVIReader \
/boot/home/Desktop/UltraDV/Source/AVINodes/AVIWriter/Headers \
/boot/home/Desktop/UltraDV/Source/Engines/Headers \
/boot/home/Desktop/UltraDV/Source/Transitions/Headers \
/boot/home/Desktop/UltraDV/Source/add-ons/cues/media/Headers \
/boot/home/Desktop/UltraDV/Source/add-ons/cues/action/Headers \
/boot/home/Desktop/UltraDV/Source/AVINodes/Shared/Headers \
/boot/home/Desktop/UltraDV/Source/Sorter

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
COMPILER_FLAGS= -fpermissive -Wwrite-strings -Fpic -g
LINKER_FLAGS=

## include the makefile-engine
include $(BUILDHOME)/etc/makefile-engine

SO2:
	cd objects.x86-gcc2-release; gcc -shared -o AVINodesShared.so *,o; cp AVINodesShared.so ../../../../../so2/AVINodesShared.so

SO4:
	cd objects.x86-gcc4-release; gcc -shared -o AVINodesShared.so *.o; cp AVINodesShared.so ../../../../../so4/AVINodesShared.so

OBJ:
	cd objects.x86-gcc4-release; cp *.o ../../../../../link


Clean:
	rm -f objects.x86-gcc2-release/*.o
	rm -f objects.x86-gcc2-release/*.d
	rm -f objects.x86-gcc4-release/*.o
	rm -f objects.x86-gcc4-release/*.d
