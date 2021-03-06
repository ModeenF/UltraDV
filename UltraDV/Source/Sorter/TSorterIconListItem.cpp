//---------------------------------------------------------------------
//
//	File:	TSorterIconListItem.cpp
//
//	Author:	Gene Z. Ragan
//
//	Date:	05.23.98
//
//	Desc:	A BLIstViewItem that displays an icon instaed of text			
//
//	Copyright ©1998 mediapede Software
//
//---------------------------------------------------------------------

// Includes
#include "BuildApp.h"

#include <app/Application.h>
#include <support/Debug.h>

#include "AppConstants.h"
#include "ResourceManager.h"

#include "TSorterContainer.h"

#include "TSorterIconListItem.h"

//---------------------------------------------------------------------
//	Constructor
//---------------------------------------------------------------------
//
//

TSorterIconListItem::TSorterIconListItem(uint32 level, bool expanded, BRect bounds, TSorterIcons &theIcons, entry_ref& fileRef) : BListItem(level, expanded)
{
	
	m_EntryRef	= fileRef;
		
	// Make a copy of the icons
	m_Icons.m_MiniIcon 	= theIcons.m_MiniIcon;
	m_Icons.m_LargeIcon = theIcons.m_LargeIcon;
		
	// Perform default initialization
	Init();
}


//---------------------------------------------------------------------
//	Destructor
//---------------------------------------------------------------------
//
//

TSorterIconListItem::~TSorterIconListItem()
{
}


//---------------------------------------------------------------------
//	Init
//---------------------------------------------------------------------
//
//	Perform default initialization tasks

void TSorterIconListItem::Init()
{
}


//---------------------------------------------------------------------
//	Init
//---------------------------------------------------------------------
//
//	Perform default initialization tasks

void	TSorterIconListItem::Update(BView *owner, const BFont *font)
{
	// 	This is a cheap hack to get the height of the listItem set 
	//	properly.  We aren't actually using a font this large.
	BFont theFont;
	owner->GetFont(&theFont);
	theFont.SetSize(kSorterFontSize + 6);	

	BListItem::Update(owner, &theFont);
}

#pragma mark -
#pragma mark === Drawing Routines ===

//---------------------------------------------------------------------
//	Draw
//---------------------------------------------------------------------
//
//

void TSorterIconListItem::DrawItem(BView *owner, BRect itemRect, bool drawEverything)
{
	owner->PushState();
	
	owner->SetHighColor(owner->ViewColor());
	owner->FillRect(itemRect);
	
	// Draw our bitmap
	BPoint drawPt;
	drawPt.x = itemRect.right - m_Icons.m_MiniIcon->Bounds().Width();
	drawPt.y = itemRect.bottom - m_Icons.m_MiniIcon->Bounds().Height();
	owner->DrawBitmap(m_Icons.m_MiniIcon, drawPt);
	
	// Is it selected?  If so grey it out...
	if ( IsSelected())
	{
		//owner->SetLowColor(kBlack);
		//owner->SetHighColor(kGrey);
		//owner->SetDrawingMode(B_OP_ADD);
		//owner->FillRect(itemRect);
	}
	
	owner->PopState();
}


/*
switch(m_Mode)
	{
		case kSorterMiniMode:
			increment =	kSorterMiniHeight + kSorterRowSpacer;
			break;	

		case kSorterLargeMode:
			increment =	kSorterLargeHeight + kSorterRowSpacer;
			break;	
		
		default:
			increment =	kSorterMiniHeight + kSorterRowSpacer;
			break;
	}
*/