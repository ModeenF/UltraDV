//---------------------------------------------------------------------
//
//	File:	TControlCue.cpp
//
//	Author:	Gene Z. Ragan
//
//	Date:	01.26.98
//
//	Desc:	
//
//	Copyright ©1998 mediapede Software
//
//---------------------------------------------------------------------

// Includes
#include "BuildApp.h"

#include <app/Application.h>
#include <support/Debug.h>

#include "AppConstants.h"
#include "AppMessages.h"
//#include "MuseumUtils.h"
#include "BaseCueChunk.h"
#include "ResourceManager.h"

#include "TBitmapView.h"
#include "TCueView.h"
#include "TControlCue.h"
#include "TCueTimeText.h"
#include "TCueChannel.h"
#include "TCueSheetView.h"

//---------------------------------------------------------------------
//	Constructor
//---------------------------------------------------------------------
//
//

TControlCue::TControlCue(int16 id, TCueChannel *parent, BRect bounds, BPoint point,  long startTime) : 
			TCueView(id, parent, bounds, point, startTime, "ControlCue")
{	
	// Perform default initialization
	Init();
}


//---------------------------------------------------------------------
//	Constructor
//---------------------------------------------------------------------
//
//	Construct from a CueChunk

TControlCue::TControlCue(BaseCueChunk *theChunk, TCueChannel *parent, BRect bounds) : 
				TCueView(theChunk, parent, bounds, "ControlCue")
{	
	// Perform default initialization
	Init(theChunk);
}


//---------------------------------------------------------------------
//	Constructor
//---------------------------------------------------------------------
//
//	Construct from a BMessage
//

TControlCue::TControlCue(BMessage *theMessage) : TCueView(theMessage)
{	
	// Load cue icon
	LoadCueIcon();	
}


//---------------------------------------------------------------------
//	Destructor
//---------------------------------------------------------------------
//
//

TControlCue::~TControlCue()
{
}


//---------------------------------------------------------------------
//	Init
//---------------------------------------------------------------------
//
//	Perform default initialization tasks

void TControlCue::Init()
{		
	// Set up default duration
	m_Duration = 1000;
	
	// Set up default settings
	m_IsLocked = false;
	
	m_IsSelected = false;
	
	m_LowColor 		= kWhite;	
	m_HighColor 	= kBlack;	
	m_IsPrepared 	= false;
	m_IsPlaying 	= false;

	m_HasDuration 	= true;
	
	/*
	bool			m_CanStretch;			// true if cue is stretchable
	bool			m_CanWindow;			// true if cue can window into file
	bool			m_CanLoop;				// true if cue can loop
	bool			m_CanEnvelope;			// true if cue can volume envelope
	bool			m_HasDuration;			// true if cue has a duration
	bool			m_IsVisible;			// true if cue is visual
	bool			m_CanCrop;				// true if cue can visual crop
	bool			m_CanTransition;		// true if cue can transition
	bool			m_CanTransitionOut;		// true if cue can transition out
	bool			m_CanPath;				// true if cue can path
	bool			m_HasEditor;			// true if cue has internal editor
		
	BRect			m_OriginalArea;			// Visual size of untouched image
	BRect			m_Area;					// Total visual area (in stage coords).
	BRect			m_CroppedArea;			// Crop area (in itsArea coords).
	*/
	
	// Default initialization
	TCueView::Init();
	
	// Add the cue to the cue channel
	if ( m_Channel->CanInsertCue(this, m_InsertPoint, true))
	{
		m_Channel->AddChild(this);
		m_Channel->InsertCue(this, m_InsertPoint, m_InsertTime);		
		Select();								
	}

	// We are now fully instantiated
	m_IsInstantiated = true;
	
}



//---------------------------------------------------------------------
//	Init
//---------------------------------------------------------------------
//
//	Init from BaseCueChunk	
//

void TControlCue::Init(BaseCueChunk *theChunk)
{
	TCueView::Init(theChunk);	
}


#pragma mark -
#pragma mark === Archiving Functions ===


//---------------------------------------------------------------------
//	Instantiate
//---------------------------------------------------------------------
//
//

BArchivable *TControlCue::Instantiate(BMessage *archive) 
{ 	
	if ( validate_instantiation(archive, "TControlCue") ) 
		return new TControlCue(archive); 
		
	return NULL; 
}
  

//---------------------------------------------------------------------
//	Archive
//---------------------------------------------------------------------
//
//

status_t TControlCue::Archive(BMessage *data, bool deep) const
{
		
	status_t myErr;
	
	Looper()->Lock();
	
	// Start by calling inherited archive
	myErr = TCueView::Archive(data, deep);
	
	if (myErr == B_OK)
	{				
		// Add ourselves to the archive
		data->AddString("class", "TControlCue");						
	}
	
	Looper()->Unlock();
		
	return myErr;
}

#pragma mark -
#pragma mark === Drawing Functions ===

//---------------------------------------------------------------------
//	Draw
//---------------------------------------------------------------------
//
//

void TControlCue::Draw(BRect updateRect)
{
	// Save colors
	rgb_color saveColor = HighColor();
	
	// Restore color
	SetHighColor(saveColor);
	
	// Pass up to parent
	TCueView::Draw(updateRect);

}

//---------------------------------------------------------------------
//	MouseDown
//---------------------------------------------------------------------
//
//	Handle mouse down events
//

void TControlCue::MouseDown(BPoint where)
{
	// Pass up to parent
	TCueView::MouseDown(where);
}


//---------------------------------------------------------------------
//	MouseUp
//---------------------------------------------------------------------
//
//	Handle mouse up events
//

void TControlCue::MouseUp(BPoint where)
{
	// Pass up to parent
	TCueView::MouseUp(where);
}

//---------------------------------------------------------------------
//	MouseMoved
//---------------------------------------------------------------------
//
//	Handle mouse moved events
//

void TControlCue::MouseMoved( BPoint where, uint32 code, const BMessage *a_message )
{
	// Pass up to parent
	TCueView::MouseMoved(where, code, a_message);
}

//---------------------------------------------------------------------
//	WindowActivated
//---------------------------------------------------------------------
//
//	Handle window activated events
//

void TControlCue::WindowActivated(bool state)
{
}


//---------------------------------------------------------------------
//	KeyDown
//---------------------------------------------------------------------
//
//	Handle key down event
//

void TControlCue::KeyDown(const char *bytes, int32 numBytes)
{
	TCueView::KeyDown(bytes, numBytes);
}



//---------------------------------------------------------------------
//	KeyDown
//---------------------------------------------------------------------
//
//	Handle key up event
//

void TControlCue::KeyUp(const char *bytes, int32 numBytes)
{
}


//---------------------------------------------------------------------
//	MessageReceived
//---------------------------------------------------------------------
//
//	Receive messages
//
void TControlCue::MessageReceived(BMessage *message)
{
	switch(message->what)
	{
		default:
			TCueView::MessageReceived(message);						
			break;
	}
}

//---------------------------------------------------------------------
//	OpenEditor
//---------------------------------------------------------------------
//
//	Open data editor if cue can edit it's data
//

void TControlCue::OpenEditor()
{

}

#pragma mark -
#pragma mark === Utility Functions ===

//---------------------------------------------------------------------
//	LoadCueIcon
//---------------------------------------------------------------------
//
//	Load cues identifying icon
//

void TControlCue::LoadCueIcon()
{
	BBitmap *cueIcon = NULL;
	
	cueIcon = GetCicnFromResource("ControlCue");

	if (cueIcon)
	{
		BRect area(0, 0+(kTimeTextHeight+kTimeTextOffset+3), kCueIconWidth-1, (kCueIconWidth-1)+(kTimeTextHeight+kTimeTextOffset+3));
		area.OffsetBy(kResizeZoneWidth+5, 0);		
		m_CueIcon = new TBitmapView(area, "ControlCue", cueIcon, false);
		AddChild(m_CueIcon);		
	}	
}
