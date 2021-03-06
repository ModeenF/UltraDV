//---------------------------------------------------------------------
//
//	File:	TVideoSettingsTabView.h
//
//	Author:	Gene Z. Ragan
//
//	Date:	05.20.98
//
//
//	Copyright ©1998 mediapede Software
//
//---------------------------------------------------------------------


#ifndef __TVideoSettingsTabView__
#define __TVideoSettingsTabView__

// Forward Declarations
class TVideoCompressionView;
class TVideoImageView;
class TVideoSourceView;
class TVideoPreviewView;
class TVideoSettingsView;

// Class Definition
class TVideoSettingsTabView : public BTabView 
{
	public:
		// Member Functions
		TVideoSettingsTabView(TVideoSettingsView *parent, BRect frame, const char *name);
		TVideoSettingsTabView(BMessage*);
								
		static	BArchivable*	Instantiate(BMessage*);
		status_t				Archive(BMessage*, bool deep=true) const;
		
	
		// Inlines
		inline TVideoSettingsView *GetParent(){ return m_Parent; }
	private:
		// Member Functions
		void Init();		
		
		// Member Variables
		TVideoSettingsView		*m_Parent;
		TVideoCompressionView 	*m_CompressionView;
		TVideoImageView 		*m_ImageView;
		TVideoSourceView 		*m_SourceView;
};

#endif
