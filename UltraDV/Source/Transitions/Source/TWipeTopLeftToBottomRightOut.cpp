//---------------------------------------------------------------------
//
//	File:	TWipeTopLeftToBottomRightOut.cpp
//
//	Author:	Gene Z. Ragan
//
//	Date:	11.11.98
//
//	Desc:	Transition wipe from right to left
//
//---------------------------------------------------------------------

#include "BuildApp.h"

#include <support/Debug.h>		// for ASSERT()

#include "TCuePosition.h"		// For class decl

#include "TWipeTopLeftToBottomRightOut.h"


//	Local Constants
const char *TWipeTopLeftToBottomRightOut::kTransitionName = "WipeTopLeftToBottomRightOut";

//---------------------------------------------------------------------
//	Constructor/destructor
//---------------------------------------------------------------------
//

TWipeTopLeftToBottomRightOut::TWipeTopLeftToBottomRightOut() : TTransitionEffect(false)	//	This is an Out Transition
{
}


TWipeTopLeftToBottomRightOut::TWipeTopLeftToBottomRightOut(BMessage* msg) : TTransitionEffect(msg)
{
}

//---------------------------------------------------------------------
// BArchivable overrides (file support)
//---------------------------------------------------------------------
//
//

BArchivable* TWipeTopLeftToBottomRightOut::Instantiate(BMessage* data)
{
	return NULL; 
}

status_t TWipeTopLeftToBottomRightOut::Archive(BMessage* data, bool deep) const
{
	// Start by calling inherited archive
	status_t err = TTransitionEffect::Archive(data, deep);
	if (err != B_OK)
		return err;
	
	// Add ourselves to the archive
	data->AddString("class", "TWipeTopLeftToBottomRightOut");	
			
	// NOTE: add local data here
	return B_OK;
}


//---------------------------------------------------------------------
//	Name()
//---------------------------------------------------------------------
//	
//	Return a name to identify the effect by.
//

string TWipeTopLeftToBottomRightOut::Name() const
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

BBitmap *TWipeTopLeftToBottomRightOut::TransformBitmap(uint32 time, const BBitmap *source,
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
	BRect srcRect = registration.Enclosure();		
	srcRect.OffsetTo(0, 0);
	srcRect.left 	+= srcRect.Width() * percentDone / 1000;
	srcRect.top 	+= srcRect.Height() * percentDone / 1000;
		
	// Set up destination rectangle
	BRect dstRect = registration.Enclosure();
	dstRect.OffsetTo(0, 0);
	dstRect.left 	+= dstRect.Width() * percentDone / 1000;
	dstRect.top 	+= dstRect.Height() * percentDone / 1000;
		
	// Draw bitmap
	if (m_OffscreenView->LockLooper())
	{
		//	Clear offscreen
		m_OffscreenView->SetHighColor(B_TRANSPARENT_32_BIT);		
		m_OffscreenView->FillRect(m_OffscreenView->Bounds());
		m_OffscreenView->Sync();
		
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
