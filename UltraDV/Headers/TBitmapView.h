//-------------------------------------------------------------------
//
//	File:	TBitmapView.h
//
//	Author:	Gene Z. Ragan
//
//	Date:	11.02.97
//
//-------------------------------------------------------------------

#ifndef __TBITMAPVIEW_H__
#define __TBITMAPVIEW_H__

class TBitmapView : public BView
{	
	public:
		TBitmapView( BRect area, char *name, BBitmap *bitmap, bool own, uint32 resizeFlags = B_FOLLOW_NONE);
		~TBitmapView();
						
		virtual void Draw( BRect area);
					
	private:
		BBitmap *m_Bitmap;
		bool	m_Ownership;
					
};

#endif
