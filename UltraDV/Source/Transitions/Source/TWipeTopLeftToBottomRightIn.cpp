//---------------------------------------------------------------------
//
//	File:	TWipeTopLeftToBottomRightIn.cpp
//
//	Author:	Gene Z. Ragan
//
//	Date:	11.14.98
//
//	Desc:	Transition wipe from top to botton
//
//---------------------------------------------------------------------

#include "BuildApp.h"

#include <support/Debug.h>		// for ASSERT()

#include "TCuePosition.h"		// For class decl

#include "TWipeTopLeftToBottomRightIn.h"


//	Local Constants
const char *TWipeTopLeftToBottomRightIn::kTransitionName = "WipeTopLeftToBottomRightIn";

//---------------------------------------------------------------------
//	Constructor/destructor
//---------------------------------------------------------------------
//

TWipeTopLeftToBottomRightIn::TWipeTopLeftToBottomRightIn() : TTransitionEffect(true)	//	This is an In Transition
{
}


TWipeTopLeftToBottomRightIn::TWipeTopLeftToBottomRightIn(BMessage* msg) : TTransitionEffect(msg)
{
}

//---------------------------------------------------------------------
// BArchivable overrides (file support)
//---------------------------------------------------------------------
//
//

BArchivable* TWipeTopLeftToBottomRightIn::Instantiate(BMessage* data)
{
	return NULL; 
}

status_t TWipeTopLeftToBottomRightIn::Archive(BMessage* data, bool deep) const
{
	// Start by calling inherited archive
	status_t err = TTransitionEffect::Archive(data, deep);
	if (err != B_OK)
		return err;
	
	// Add ourselves to the archive
	data->AddString("class", "TWipeTopLeftToBottomRightIn");	
			
	// NOTE: add local data here
	return B_OK;
}


//---------------------------------------------------------------------
//	Name()
//---------------------------------------------------------------------
//	
//	Return a name to identify the effect by.
//

string TWipeTopLeftToBottomRightIn::Name() const
{
	return( string(kTransitionName));
}

#pragma mark -
#pragma mark === Bitmap Transformation ===

//---------------------------------------------------------------------
// TransformBitmap
//---------------------------------------------------------------------
//
//	Return a transformed version of 'bits' at 'time'. Caller
// 	takes ownership of new'd BBitmap return value. Return
// 	zero if nothing need be done. 
//

BBitmap *TWipeTopLeftToBottomRightIn::TransformBitmap(uint32 time, const BBitmap *source,
			const TCuePosition &registration, DisplayQuality quality)
{
	//	Only create offscreen at first pass
	if (!m_Inited)
	{
		BRect offRect = registration.Enclosure();
		offRect.OffsetTo(0, 0);
		InitOffscreen(offRect);
	}
		
	//	Calculate times
	const uint32 taskTime 	= time - StartTime();
	const uint32 endTime 	= StartTime() + Duration();
		
	// percentDone is on a scale of 0 to 1000.  Check for overflow...
	int32  percentDone;
	
	if ( time < endTime)
		percentDone = taskTime * 1000L / Duration();
	else
		percentDone = 1001;
	
	if (percentDone > 1000)
		percentDone = 1000;
			
	// Set up source rectangle				
	BRect srcRect 	= registration.Enclosure();	
	srcRect.OffsetTo(0, 0);	
	srcRect.right 	= srcRect.left + srcRect.Width() * percentDone / 1000;
	srcRect.bottom 	= srcRect.top + srcRect.Height() * percentDone / 1000;
		
	// Set up destination rectangle
	BRect dstRect 	= registration.Enclosure();
	dstRect.OffsetTo(0, 0);
	dstRect.right 	= dstRect.left + srcRect.Width();
	dstRect.bottom 	= dstRect.top + srcRect.Height();							

		
	// Draw bitmap
	if (m_OffscreenView->LockLooper())
	{
		//	Clear offscreen
		m_OffscreenView->SetHighColor(B_TRANSPARENT_32_BIT);		
		m_OffscreenView->FillRect(m_OffscreenView->Bounds());
		
		//	Do transitioned data
		m_OffscreenView->DrawBitmap(source, srcRect, dstRect);
		m_OffscreenView->Sync();

		m_OffscreenView->UnlockLooper();	
	}
	
	//	Clone offscreen
	BBitmap *newBitmap = CloneBitmap(*m_OffscreenBitmap);
	ASSERT(newBitmap);
		
	return newBitmap;
}
