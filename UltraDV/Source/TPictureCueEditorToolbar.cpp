//---------------------------------------------------------------------
//
//	File:	TPictureCueEditorToolbar.cpp
//
//	Author:	Gene Z. Ragan
//
//	Date:	06.11.98
//
//	Desc:	Picture Editor toolbar.  Contains the following:
//
//				-- Duration
//
//	Copyright ©1998 mediapede Software
//
//---------------------------------------------------------------------

// Includes
#include "BuildApp.h"

#include <app/Application.h>

#include "AppConstants.h"
#include "AppMessages.h"
#include "AppUtils.h"
#include "ResourceManager.h"

#include "TCueView.h"
#include "TBitmapButton.h"

#include "TPictureCueEditorToolbar.h"

// Constants
	 
//---------------------------------------------------------------------
//	Constructor
//---------------------------------------------------------------------
//
//

TPictureCueEditorToolbar::TPictureCueEditorToolbar(BRect bounds, TCueView *theCue) : BView(bounds, "PictureEditToolbar", B_FOLLOW_TOP | B_FOLLOW_LEFT_RIGHT, B_WILL_DRAW)
{
	m_Cue = theCue;
	
	// Default Initialization
	Init();
}


//---------------------------------------------------------------------
//	Destructor
//---------------------------------------------------------------------
//
//

TPictureCueEditorToolbar::~TPictureCueEditorToolbar()
{
}


//---------------------------------------------------------------------
//	Init
//---------------------------------------------------------------------
//
//	Create toolbar buttons
//

const short kButtonLeftOffset 	= 5;
const short kButtonTopOffset 	= 4;
const short kToolButtonWidth	= 16;
const short kToolButtonHeight	= 16;

void TPictureCueEditorToolbar::Init()
{
	//
	// Create the toolbar buttons
	//
			
	// Create Duration button	
	BBitmap *deltaUp = GetIcon16FromResource("DeltaUp");
	BBitmap *deltaDn = GetIcon16FromResource("DeltaDown");	
	
	BRect bounds;
	bounds.left  	= Bounds().left + kButtonLeftOffset;
	bounds.right 	= bounds.left + (kToolButtonWidth-1);
	bounds.top 	 	= Bounds().top + kButtonTopOffset;
	bounds.bottom 	= bounds.top + (kToolButtonWidth-1);		
	m_DurationButton = new TBitmapButton(bounds, "DurationButton", deltaUp, deltaDn, 
										 this, new BMessage(PICTURE_DURATION_MSG)); 
	AddChild(m_DurationButton);
	m_DurationButton->Show();
					
	// Set up duration text
	m_DurationRect.left 	= bounds.right + kButtonLeftOffset;
	m_DurationRect.right 	= m_DurationRect.left + 80;	
	m_DurationRect.top 		= bounds.top;
	m_DurationRect.bottom 	= m_DurationRect.top + 15;
	
}

#pragma mark -
#pragma mark === Drawing Routines ===

//---------------------------------------------------------------------
//	Draw
//---------------------------------------------------------------------
//
//	Fill with grey background
//

void TPictureCueEditorToolbar::Draw(BRect updateRect)
{	
	// Setup environment
	PushState();
	
	BPoint startPt, endPt;
			
	// Fill background
	SetHighColor(kBlueGrey);
	FillRect(Bounds());
	
	// Frame it
	SetHighColor(kWhite);	
	MovePenTo(Bounds().left, Bounds().top+1);
	endPt.Set( Bounds().right, Bounds().top+1 );
	StrokeLine(endPt);
	
	SetHighColor(kMediumGrey);
	MovePenTo(Bounds().left, Bounds().bottom-1);
	endPt.Set( Bounds().right, Bounds().bottom-1 );
	StrokeLine(endPt);
	
	SetHighColor(kBlack);
	MovePenTo(Bounds().left, Bounds().top);
	endPt.Set( Bounds().right, Bounds().top );
	StrokeLine(endPt);	
	MovePenTo(Bounds().left, Bounds().bottom);
	endPt.Set( Bounds().right, Bounds().bottom );
	StrokeLine(endPt);
	
	// Draw text area
	SetHighColor(kBlack);
	FillRect(m_DurationRect);
	BRect bounds = m_DurationRect;
	
	SetHighColor(kTextHilite);
	startPt.Set(bounds.right, bounds.top);
	endPt.Set(bounds.right, bounds.bottom);				
	StrokeLine(startPt, endPt);
	startPt.Set(bounds.right, bounds.bottom);
	endPt.Set(bounds.left+1, bounds.bottom);												
	StrokeLine(startPt, endPt);
	SetHighColor(kTextShadow);
	startPt.Set(bounds.left, bounds.bottom);
	endPt.Set(bounds.left, bounds.top);												
	StrokeLine(startPt, endPt);
	startPt.Set(bounds.left, bounds.top);
	endPt.Set(bounds.right-1, bounds.top);												
	StrokeLine(startPt, endPt);
	
	// Draw text
	char durationStr[12];
	SetHighColor(kGreen);
	SetLowColor(kBlack);
	BFont font(be_plain_font); 
	font.SetSize(12.0); 
	SetFont(&font);
	BPoint textPt(m_DurationRect.left+8, m_DurationRect.top + (m_DurationRect.Height()/2) + 4 );
	TimeToString(m_Cue->GetDuration(), GetCurrentTimeFormat(), durationStr, false);
	DrawString(durationStr, textPt);		
		
	// Restore Environment
	PopState();
}


#pragma mark -
#pragma mark === Keyboard Handling ===

//---------------------------------------------------------------------
//	KeyDown
//---------------------------------------------------------------------
//
//	Handle key down event
//

void TPictureCueEditorToolbar::KeyDown(const char *bytes, int32 numBytes)
{

	BView::KeyDown(bytes, numBytes);
}


#pragma mark -
#pragma mark === Message Handling ===

//---------------------------------------------------------------------
//	MessageReceived
//---------------------------------------------------------------------
//
//

void TPictureCueEditorToolbar::MessageReceived(BMessage* message)
{	
	switch (message->what)
	{
		default:
			// Passes PICTURE_DURATION_MSG on up to the parent
			BView::MessageReceived(message);
			break;	
	}		
}

