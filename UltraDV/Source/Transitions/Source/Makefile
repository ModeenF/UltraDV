NAME= DV
TYPE= LIB
SRCS= TRevealBottomLeftTopRightIn.cpp TRevealBottomRightTopLeftIn.cpp TRevealDownIn. \
TRevealDownOut.cpp TRevealLeftIn.cpp TRevealLeftOut.cpp TRevealRightIn.cpp \
TRevealRightOut.cpp TRevealTopLeftBottomRightIn.cpp TRevealTopRightBottomLeftIn.cpp \
TRevealUpIn.cpp TRevealUpOut.cpp TTransitionView.cpp TWipeBottomLeftToTopRightIn.cpp \
TWipeBottomLeftToTopRightOut.cpp TWipeBottomRightToTopLeftIn.cpp TWipeBottomRightToTopLeftOut.cpp \
TWipeDownIn.cpp TWipeDownOut.cpp TWipeLeftIn.cpp TWipeLeftOut.cpp TWipeRightIn.cpp \
TWipeRightOut.cpp TWipeTopLeftToBottomRightIn.cpp TWipeTopLeftToBottomRightOut.cpp \
TWipeTopRightToBottomLeftOut.cpp TWipeUpIn.cpp TWipeUpOut.cpp WipeTopRightToBottomLeftIn.cpp



# bad cpp files
#TCueView.cpp - contains redundant MuseumApp global
# TConductor.cpp 
#TScaleDialog.cpp
#TStageMovieCue.cpp
#TStagePictureCue.cpp
#TStageTextView.cpp
#TTransitionMenuLooper.cpp
#TVisualCue.cpp

RSRCS=
LIBS= /boot/develop/lib/x86/libroot.so be /boot/develop/lib/x86/libmedia.so \
/boot/develop/lib/x86/libjpeg.so /boot/home/Desktop/UltraDV/so/Editors.so \
/boot/home/Desktop/UltraDV/so/Engines.so /boot/home/Desktop/UltraDV/so/Sorter.so \
/boot/home/Desktop/UltraDV/so/Media.so \
/boot/develop/lib/x86/libstdc++.r4.so \
translation tracker 

LIBPATHS= /boot/home/Desktop/UltraDV/so 
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
/boot/home/Desktop/UltraDV/Source/Sorter \
/boot/home/Desktop/UltraDV/Source/Transitions/Headers

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

SO2:
	cd objects.x86-gcc2-release; gcc -shared -o Transitions.so *.o; cp Transitions.so ../../../../so2/Transitions.so

SO4:
	cd objects.x86-gcc4-release; gcc -shared -o Transitions.so *.o; cp Transitions.so ../../../../so4/Transitions.so

OBJ:
	cd objects.x86-gcc4-release;  cp *.o ../../../link


Clean:
	rm -f objects.x86-gcc4-release/*.o
	rm -f objects.x86-gcc4-release/*.d
	rm -f objects.x86-gcc2-release/*.o
	rm -f objects.x86-gcc2-release/*.d
