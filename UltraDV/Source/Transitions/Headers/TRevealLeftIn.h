#if !defined(__TREVEALLEFTIN_H__)
#define __TREVEALLEFTIN_H__

//---------------------------------------------------------------------
//
//	File:	TRevealLeftIn.h
//
//	Author:	Gene Z. Ragan
//
//	Date:	11.11.98
//
//	Desc:
//
//---------------------------------------------------------------------

// This is required to make the vector class work...
#define MSIPL_DEF_TEMPARG

//	Includes
#include "AppUtils.h"

#include "TTransitionEffect.h"

//	Forward Declarations
class TCuePosition;

class TRevealLeftIn : public TTransitionEffect 
{
	public:
		TRevealLeftIn();
		
		// Construct self from a message
		TRevealLeftIn(BMessage* msg);
		
		//----------------------
		// BArchivable overrides (file support)
		static BArchivable* Instantiate(BMessage* data);
		virtual status_t Archive(BMessage* data, bool deep) const;
		
		// Return a name to identify the effect by. This is used in 
		// the tool palette, in menus and within the cue view.
		string Name() const;
		
		BBitmap *TransformBitmap(uint32 time, const BBitmap* source,
								 const TCuePosition& registration, DisplayQuality quality);

	protected:			
		//	Name string
		static const char	*kTransitionName;
		
};

#endif