//---------------------------------------------------------------------
//
//	File:	TRefFilter.h
//
//	Author:	Gene Z. Ragan
//
//	Date:	05.25.98
//
//
//	Copyright ©1998 mediapede Software
//
//---------------------------------------------------------------------

#ifndef __TREFFILTER_H__
#define __TREFFILTER_H__

typedef enum 
{
	kAudioFilter,
	kImageFilter,
	kTextFilter,
	kVideoFilter,
	kCueSheetFilter
} FilterType;

// Class Definition
class TRefFilter : public BRefFilter 
{
	public:
		TRefFilter(FilterType filterType);
		
		bool	Filter(const entry_ref *, BNode *, struct stat *, const char *mimetype);
		
	private:
		FilterType m_FilterType;

};

#endif
