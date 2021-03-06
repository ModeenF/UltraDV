//-------------------------------------------------------------------
//
//	File:	TToolbar.h
//
//	Author:	Gene Z. Ragan
//
//	Date:	02.16.98
//
//-------------------------------------------------------------------

#ifndef __TTOOLBAR_H__
#define __TTOOLBAR_H__
 
// Button Enumeration
enum
{
	kPointer,
	kContractAll,
	kExpandAll,
	kRazor,
	kZoom,
	kTotalToolButtons
};

// Class Declarations
class TToolbar: public BView
{
	public:
		TToolbar(BRect bounds, TCueSheetWindow *parent);
		TToolbar(BMessage *data);
		~TToolbar();
		
		void 	Init();
		
		static BArchivable *Instantiate(BMessage *archive);
		status_t 	Archive(BMessage *data, bool deep) const;
		
		void 	Draw(BRect updateRect);
		
		void 	AttachedToWindow();
		
		
		//	Accessor Functions
		void 	SetParent(TCueSheetWindow *parent);
		
	private:
					
		// Member Functions
						
		// Member variables
		TCueSheetWindow		*m_Parent;
		TPointerButton		*m_PointerButton;
		TContractAllButton	*m_ContractAllButton;
		TExpandAllButton	*m_ExpandAllButton;
		TRazorButton		*m_RazorButton;
		TZoomButton			*m_ZoomButton;
};

#endif
