NAME= test
TYPE= APP
SRCS= testclass.cpp main.cpp TimedBufferQueue.cpp

# bad cpp files
#TCueView.cpp - contains redundant MuseumApp global
# TConductor.cpp 
#TScaleDialog.cpp
#TStageMovieCue.cpp
#TStagePictureCue.cpp
#TStageTextView.cpp
#TimedBufferQueue.cpp


#RSRCS= ../Resources/Museum.rsrc

LIBPATHS= /boot/home/Desktop/UltraDV/so4  /boot/develop/lib/x86/gcc4/lib

SYSTEM_INCLUDE_PATHS= /boot/develop/lib/x86 /boot/develop/headers/cpp \
/boot/develop/headers/posix /boot/home/config/include 

LIBS= be root media translation tracker stdc++ 
#/boot/home/Desktop/UltraDV/so/Editors.so \
#/boot/develop/lib/x86/libroot.so /boot/develop/lib/x86/libmedia.so \
#/boot/home/Desktop/UltraDV/so/Engines.so /boot/home/Desktop/UltraDV/so/Sorter.so \
#/boot/home/Desktop/UltraDV/so/Media.so \
#/boot/home/Desktop/UltraDV/so/Transitions.so \
#/boot/develop/lib/x86/libbe.so \ 
#-L /boot/develop/lib 
#/boot/develop/lib/x86/libstdc++.r4.so \


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
COMPILER_FLAGS= -fpermissive -Wwrite-strings 
#-fPIC
LINKER_FLAGS= 

## include the makefile-engine
include $(BUILDHOME)/etc/makefile-engine

SO:
	cd objects.x86-gcc2-release; gcc -shared -o Source.so *.o
	cp Source.so ../so
Clean:
	rm -f objects.x86-gcc4-release/*.o
	rm -f objects.x86-gcc4-release/*.d
	rm -f objects.x86-gcc2-release/*.o
	rm -f objects.x86-gcc2-release/*.d
