//---------------------------------------------------------------------
//
//	File:	TAudioSampleView.cpp
//
//	Author:	Gene Z. Ragan
//
//	Date:	05.27.98
//
//	Desc:	Child view of TAudioSampleView.  Handles display of audio
//			sample settings.
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
#include "AppUtils.h"
#include "ResourceManager.h"

#include "TMuseumSlider.h"
#include "TAudioSettingsTabView.h"
#include "TAudioSettingsView.h"
#include "TAudioLevelsView.h"
#include "TLevelsSlider.h"

#include "TAudioSampleView.h"


// Constants


//---------------------------------------------------------------------
//	Constructor
//---------------------------------------------------------------------
//
//

TAudioSampleView::TAudioSampleView(TAudioSettingsTabView *parent, BMessage *archive) : BView(archive)
{
	m_Parent = parent;
	
	// Perform default initialization
	Init();
}


//---------------------------------------------------------------------
//	Init
//---------------------------------------------------------------------
//
//	Perform default initialization tasks

void TAudioSampleView::Init()
{
	// Grey background
	SetViewColor(kBeGrey); 
	
	// Locate view items	
	m_RateMenuField 	= (BMenuField *)FindView("RateMenuField");
	m_DepthMenuField 	= (BMenuField *)FindView("DepthMenuField");
	m_TypeMenuField 	= (BMenuField *)FindView("TypeMenuField");
	m_VolumeBox			= (BBox *)FindView("VolumeBox");
	
	// Set up Input Slider
	BView *inputView = (BView *)FindView("InputView");
	m_InputSlider = new TLevelsSlider(inputView->Frame(), kAudioInputSlider);
	m_VolumeBox->AddChild(m_InputSlider);
	m_VolumeBox->RemoveChild(inputView);
	delete inputView;
	m_InputSlider->Show();

	// Set up Output Slider
	BView *outputView = (BView *)FindView("OutputView");
	m_OutputSlider = new TLevelsSlider(outputView->Frame(), kAudioOutputSlider);
	m_VolumeBox->AddChild(m_OutputSlider);
	m_VolumeBox->RemoveChild(outputView);
	delete outputView;
	m_OutputSlider->Show();
	
	// Set up level indicator
	BView 	*levelsView 	= (BMenuField *)FindView("LevelsView");
	m_AudioLevelsView = new TAudioLevelsView(levelsView->Frame());
	m_VolumeBox->RemoveChild(levelsView);
	delete levelsView;
	m_VolumeBox->AddChild(m_AudioLevelsView);
	
	// Setup menus
	BMenu *theMenu;
	
	// Setup Rate menu
	theMenu = m_RateMenuField->Menu();
	if (theMenu)
	{
		// 11.025 kHz
		BMenuItem *kHz11Item = new BMenuItem("11.025 kHz", new BMessage(SAMP_11_MSG)  );		
		theMenu->AddItem(kHz11Item);	

		// 22.050 kHz
		BMenuItem *kHz22Item = new BMenuItem("22.050 kHz", new BMessage(SAMP_22_MSG)  );		
		theMenu->AddItem(kHz22Item);	
		
		// 44.100 kHz
		BMenuItem *kHz44Item = new BMenuItem("44.100 kHz", new BMessage(SAMP_44_MSG)  );		
		theMenu->AddItem(kHz44Item);	
		
		// Select the first item
		kHz44Item->SetMarked(true);
	}
	

	// Setup Depth menu
	theMenu = m_DepthMenuField->Menu();
	if (theMenu)
	{
		// 8-bit
		BMenuItem *bit8Item = new BMenuItem("8-bit", new BMessage(SAMP_BIT_EIGHT_MSG)  );		
		theMenu->AddItem(bit8Item);	

		// 16-bit
		BMenuItem *bit16Item = new BMenuItem("16-bit", new BMessage(SAMP_BIT_SIXTEEN_MSG)  );		
		theMenu->AddItem(bit16Item);	

		// Select the first item
		bit16Item->SetMarked(true);
	}


	// Setup type menu
	theMenu = m_TypeMenuField->Menu();
	if (theMenu)
	{
		// Mono
		BMenuItem *monoItem = new BMenuItem("Mono", new BMessage(SAMP_MONO_MSG)  );		
		theMenu->AddItem(monoItem);	

		// Stero
		BMenuItem *stereoItem = new BMenuItem("Stereo", new BMessage(SAMP_STEREO_MSG)  );		
		theMenu->AddItem(stereoItem);	
		
		// Select the first item
		stereoItem->SetMarked(true);
	}
}


#pragma mark -
#pragma mark === Message Handling ===

//---------------------------------------------------------------------
//	MessageReceived
//---------------------------------------------------------------------
//
//

void TAudioSampleView::MessageReceived(BMessage *theMessage)
{

	switch( theMessage->what)
	{					
		case SAMP_11_MSG:
			{
				//BDACStream theStream;
				//theStream.SetSamplingRate(11025.0);
			}
			break;
			
		case SAMP_22_MSG:
			{
				//BDACStream theStream;
				//theStream.SetSamplingRate(22050.0);
			}
			break;
			
		case SAMP_44_MSG:
			{
				//BDACStream theStream;
				//theStream.SetSamplingRate(44100.0);
			}
			break;
			
		case SAMP_BIT_EIGHT_MSG:
			break;
			
		case SAMP_BIT_SIXTEEN_MSG:
			break;
			
		case SAMP_MONO_MSG:
			break;
			
		case SAMP_STEREO_MSG:
			break;

		default:
			BView::MessageReceived(theMessage);
			break;			
	}
}

#pragma mark -
#pragma mark === Visibility Routines ===


//---------------------------------------------------------------------
//	AttachedToWindow
//---------------------------------------------------------------------
//
//	Perform initialization when attached to a window
//	

void TAudioSampleView::AttachedToWindow()
{			
	// Set up menu targets
	//
	
	// Device Menu
	BMenu *rateMenu = m_RateMenuField->Menu();
	if (rateMenu)
	{
		BMenuItem *elevenItem = rateMenu->FindItem(SAMP_11_MSG);
		elevenItem->SetTarget(this);
		
		BMenuItem *twentyItem = rateMenu->FindItem(SAMP_22_MSG);
		twentyItem->SetTarget(this);

		BMenuItem *fortyItem = rateMenu->FindItem(SAMP_44_MSG);
		fortyItem->SetTarget(this);
	
		// Select the current rate item
		//float currentRate;
		//BADCStream theStream;
		//if ( theStream.SamplingRate(&currentRate) == B_OK)
		//{
		//	if (currentRate < 22050.0)
		//		elevenItem->SetMarked(true);
		//	else if (currentRate < 44100.0)
		//		twentyItem->SetMarked(true);
		//	else
		//		fortyItem->SetMarked(true);
		//}
	}	
}


#pragma mark -
#pragma mark === Utility Routines ===

