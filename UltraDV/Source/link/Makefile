NAME= DV
TYPE= LIB
SRCS= AppAlerts.cpp AppGlobals.cpp AppUtils.cpp Benaphore.cpp DebugUtils.cpp fft.cpp \
FileIO.cpp MuseumApp.cpp ResourceManager.cpp TAboutBox.cpp TActionCuePalette.cpp \
TActionCuePaletteView.cpp TAddChannel.cpp TArray.cpp TAudibleEffect.cpp \
TAudioCaptureToolbar.cpp TAudioCaptureWindow.cpp TAudioCompressionView.cpp TAudioLevelsView.cpp\
TAudioSampleView.cpp TAudioSettingsDialog.cpp TAudioSettingsTabView.cpp TAudioSettingsView.cpp \
TAudioSourceView.cpp TBitmapButton.cpp TBitmapStream.cpp TBitmapView.cpp TBrowserTabView.cpp\
TBrowserWindow.cpp TChannelCueButton.cpp TChannelName.cpp TChannelNameView.cpp TChaser.cpp\
TCollection.cpp TCompositor.cpp  TContractAllButton.cpp TCueButton.cpp TCueChannel.cpp\
TCueChannelHeader.cpp TCueData.cpp TCueEffect.cpp TCueEffectView.cpp TCueMenu.cpp \
TCuePosition.cpp TCueSheetPrefs.cpp TCueSheetScrollBarH.cpp TCueSheetScrollBarV.cpp TCueSheetTimeView.cpp \
TCueSheetView.cpp TCueSheetWindow.cpp TCueTimeText.cpp TCueTransitionButton.cpp  \
TCursor.cpp TDeleteChannel.cpp TElementsScrollBarH.cpp TElementsScrollBarV.cpp TElementsSorter.cpp \
TElementsTrackerView.cpp TElementsView.cpp TExpandAllButton.cpp TExpandButton.cpp TExportText.cpp \
TExportTimeView.cpp TExportZone.cpp THeaderContainerView.cpp TIconView.cpp TimedBufferQueue.cpp \
TKeyFrame.cpp TLevelsSlider.cpp TLockButton.cpp TMediaCuePalette.cpp TMediaCuePaletteView.cpp \
TMediaTabView.cpp TMIDIConductor.cpp TMIDIFile.cpp TMIDITrack.cpp TMouseWatcher.cpp TMuseumClipboard.cpp \
TMuseumIcons.cpp TMuseumMenus.cpp TMuseumPrefs.cpp TMuseumSlider.cpp TMuteButton.cpp TNewProject.cpp \
TNewProjectBox.cpp TNumberBevelTextView.cpp TNumberTextControl.cpp TNumberTextView.cpp TOpacityDialog.cpp \
TOpacitySlider.cpp TPaletteStatusView.cpp TPasteCues.cpp TPictureCueEditor.cpp TPictureCueEditorToolbar.cpp \
TPlaybackList.cpp TPointerButton.cpp TPolygon.cpp TPreset.cpp TPreviewUpdater.cpp TProjectSettings.cpp \
TRadioBitmapButton.cpp TRazorButton.cpp TRecordPrefsDialog.cpp TRefFilter.cpp TRotateDialog.cpp \
TRotateSlider.cpp  TSettingsTabView.cpp TSizeScrollView.cpp TSlider.cpp TSoloButton.cpp \
TSoundRecorder.cpp TStageCue.cpp TStageCueMenu.cpp  TStageSetup.cpp \
TStageToolButton.cpp TStageTools.cpp TStageToolsView.cpp TStageView.cpp TStageWindow.cpp \
TStatusView.cpp TThread.cpp TThumbnailView.cpp TTimeBevelTextView.cpp TTimelineView.cpp TTimePalette.cpp \
TTimePaletteView.cpp TTimer.cpp TTimeScalerView.cpp TTimeText.cpp TTimeTextView.cpp TToolbar.cpp TTransformEffect.cpp \
TTransition.cpp TTransitionEffect.cpp TTransitionMenu.cpp  TTransitionsTabView.cpp \
TTransportPalette.cpp TTransportPaletteView.cpp TUndo.cpp TUndoEngine.cpp TVideoCaptureToolbar.cpp TVideoCaptureView.cpp \
TVideoCaptureWindow.cpp TVideoCompressionView.cpp TVideoEditorButton.cpp TVideoImageView.cpp TVideoPreviewView.cpp \
TVideoSettings.cpp TVideoSettingsDialog.cpp TVideoSettingsSlider.cpp TVideoSettingsTabView.cpp TVideoSettingsView.cpp \
TVideoSourceView.cpp  TVisualEffect.cpp TZoomButton.cpp \
TCueView.cpp TVisualCue.cpp

# bad cpp files
#TCueView.cpp - contains redundant MuseumApp global
# TConductor.cpp 
#TScaleDialog.cpp
#TStageMovieCue.cpp
#TStagePictureCue.cpp
#TStageTextView.cpp
#TTransitionMenuLooper.cpp
#TVisualCue.cpp

RSRCS= ../../Resources/Museum.rsrc
LIBPATHS= /boot/home/Desktop/UltraDV/so4 /boot/system/lib /boot/develop/lib/x86/gcc4/lib

LIBS= translation tracker root be media stdc++.r4 \
Engines.so Sorter.so Media.so Transitions.so Editors.so 

Link:
	ld *.o -o DV 

#-ltranslation -ltracker -lroot -lbe -lmedia -lstdc++.r4 

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
COMPILER_FLAGS= -fpermissive -Wwrite-strings -fPIC
LINKER_FLAGS= -L-lbe

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
