//---------------------------------------------------------------------
//
//	File:	TPreset.cpp
//
//	Author:	Gene Z. Ragan
//
//	Date:	05.18.98
//
//	Desc:	Object that contains Project preset data.
//
//	Copyright ©1998 mediapede Software
//
//---------------------------------------------------------------------

// Includes
#include "BuildApp.h"

#include <app/Application.h>
#include <support/Debug.h>

#include "AppConstants.h"
#include "AppTypes.h"
#include "ResourceManager.h"

#include "TPreset.h"

//---------------------------------------------------------------------
//	Constructor
//---------------------------------------------------------------------
//
//

TPreset::TPreset(char *theName)
{
	// Set up member variables
	strcpy(m_Name, theName);
	
}


//---------------------------------------------------------------------
//	Constructor
//---------------------------------------------------------------------
//
//	Construct from message or archive
//

TPreset::TPreset(BMessage *data)
{
	char 	*tmpStr;
	int16 	tmpInt16;
	
	data->FindString("Name", &tmpStr);
	strcpy(m_Name, tmpStr);
	
	data->FindString("Description01", &tmpStr);
	strcpy(m_Description01, tmpStr);
	
	data->FindString("Description02", &tmpStr);
	strcpy(m_Description02, tmpStr);

	data->FindString("Description03", &tmpStr);
	strcpy(m_Description03, tmpStr);

	data->FindString("Description04", &tmpStr);
	strcpy(m_Description04, tmpStr);

	data->FindString("Description05", &tmpStr);
	strcpy(m_Description05, tmpStr);

	data->FindInt16("TimeBase", &tmpInt16);
	m_Timebase = (timecode_type)tmpInt16;
	
	data->FindInt16("AudioCompressor", &tmpInt16);
	m_AudioCompressor = (audio_compressor_type)tmpInt16;

	data->FindInt16("VideoCompressor", &tmpInt16);
	m_VideoCompressor = (video_compressor_type)tmpInt16;
	
	data->FindInt32("FrameWidth", &m_FrameWidth);
	data->FindInt32("FrameHeight", &m_FrameHeight);
}


//---------------------------------------------------------------------
//	Destructor
//---------------------------------------------------------------------
//
//

TPreset::~TPreset()
{

}


#pragma mark -
#pragma mark === Archiving Functions ===

//---------------------------------------------------------------------
//	Instantiate
//---------------------------------------------------------------------
//
//

BArchivable *TPreset::Instantiate(BMessage *archive) 
{ 

	if ( validate_instantiation(archive, "TPreset") ) 
		return new TPreset(archive); 
		
	return NULL; 
}
   
//---------------------------------------------------------------------
//	Archive
//---------------------------------------------------------------------
//
//

status_t TPreset::Archive(BMessage *data, bool deep) const
{
		
	status_t myErr;
	
	// Start by calling inherited archive
	myErr = BArchivable::Archive(data, deep);
						
	if (myErr == B_OK)
	{				
		// Add our class name to the archive
		data->AddString("class", "TPreset");
				
		data->AddString("Name", m_Name);
		data->AddString("Description01", m_Description01);
		data->AddString("Description02", m_Description02);
		data->AddString("Description03", m_Description03);
		data->AddString("Description04", m_Description04);
		data->AddString("Description05", m_Description05);
		data->AddInt16("TimeBase", m_Timebase);
		data->AddInt16("AudioCompressor", m_AudioCompressor);
		data->AddInt16("VideoCompressor", m_VideoCompressor);
		data->AddInt32("FrameWidth", m_FrameWidth);
		data->AddInt32("FrameHeight", m_FrameHeight);

		// Add attached data
		if (deep)
		{			              		
		}
	}
		
	return myErr;
}

#pragma mark -
#pragma mark === Utility Routines ===

//---------------------------------------------------------------------
//	SetName
//---------------------------------------------------------------------
//
//	Set preset name
//

void TPreset::SetName(char *theName)
{
	strcpy(m_Name, theName);
}


//---------------------------------------------------------------------
//	SetTimebase
//---------------------------------------------------------------------
//
//	Set timeBase type
//

void TPreset::SetTimebase(timecode_type theTimebase)
{
	m_Timebase = theTimebase;
}


//---------------------------------------------------------------------
//	WriteToFile
//---------------------------------------------------------------------
//
//	Basic dump to binary file
//

void TPreset::WriteToFile(char *theName)
{
	status_t retVal;
	
	// Archive our data
	BMessage *archive = new BMessage();
	retVal = Archive(archive, true);

	
	// Dump shared variables to file
	PresetChunk theChunk;
	theChunk.ArchivedData = archive;
	
	// Now write preset information out
	ChunkHeader	theHeader;
	
	theHeader.chunkID 	= kPresetChunkID;
	theHeader.chunkSize = archive->FlattenedSize();
	
	BFile theFile;
	
	// Write file to disk in our apps "presets" directory	
	app_info appInfo;
	be_app->GetAppInfo(&appInfo); 	
	BEntry entry(&appInfo.ref);
	BDirectory parentDir;
	entry.GetParent(&parentDir);
	parentDir.SetTo(&parentDir, kPresetsPathString); 	
	
	retVal = parentDir.CreateFile(theName, &theFile, false); 
	
	if (retVal == B_OK)
	{ 	
		// Write out file	
		theFile.Write(&theHeader, sizeof(theHeader));
		archive->Flatten(&theFile);
				
		// Set file type
		BNodeInfo info(&theFile);
		if ( info.InitCheck() == B_OK )
		{		
			retVal = info.SetType(kCueSheetTypeString);
			
			// Give it some nice icons
			BBitmap *smallIcon = GetMICNFromResource(kSettingsTypeString);
			ASSERT(smallIcon);
			info.SetIcon( smallIcon, B_MINI_ICON);
			
			BBitmap *largeIcon = GetICONFromResource(kSettingsTypeString);				
			ASSERT(largeIcon);
			info.SetIcon( largeIcon, B_LARGE_ICON);
			
			delete smallIcon;
			delete largeIcon;	
		}
	}
}

