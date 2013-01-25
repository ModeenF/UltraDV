//---------------------------------------------------------------------
//
//	File:	AVIViewer.cpp
//
//	Author:	Gene Z. Ragan
//
//	Date:	08.25.98
//
//	Desc:	AVIReaderNode
//
//	Copyright ©1998 mediapede Software
//
//---------------------------------------------------------------------


//	Includes
#include <TrinityDefs.h>
#include <OS.h>
#include <Debug.h>
#include <Buffer.h>
#include <BufferGroup.h>
#include <TimeSource.h>

#include <stdio.h>
#include <string.h>

#include "BuildApp.h"

#include "AVIViewer.h"



//-------------------------------------------------------------------
//	Constructor
//-------------------------------------------------------------------
//
//	Default Contructor
//

AVIViewer::AVIViewer() : BBufferConsumer(B_MEDIA_MULTISTREAM)
{
	printf("AVIViewer::AVIViewer\n");
	
	//	Init variables

	//	Default initialization
}


//-------------------------------------------------------------------
//	Destructor
//-------------------------------------------------------------------
//
//	Defualt Destructor
//

AVIViewer::~AVIViewer()
{
	printf("AVIViewer::~AVIViewer\n");
	
}
