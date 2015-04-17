#include <Common.h>
#include "Config.h"
#include <fstream>

Config* Config::GetInstance()
{
	static Config pInstance;
	return &pInstance;
}

Config::Config()
{
	m_bIsLoaded = false;
	m_uiScreenWidth = 800;
	m_uiScreenHeight = 600;
	m_bFullScreen = false;
	m_bVerticalSync = true;
	m_bBorderless = true;
	m_uiMusicVolume = 80;
	m_uiSoundVolume = 100;
}

Config::~Config()
{
	m_bIsLoaded = false;
	m_uiScreenWidth = 0;
	m_uiScreenHeight = 0;
	m_bFullScreen = false;
	m_bVerticalSync = true;
	m_bBorderless = true;
	m_uiMusicVolume = 0;
	m_uiSoundVolume = 0;
}

// Resets all members to default values
void Config::SetDefault()
{
	m_uiScreenWidth = 800;
	m_uiScreenHeight = 600;
	m_bFullScreen = false;
	m_bVerticalSync = false;
	m_bBorderless = true;
	m_uiMusicVolume = 80;
	m_uiSoundVolume = 100;
}

// Reads in the config.txt file
void Config::LoadConfig()
{
	std::fstream ioFile;
	ioFile.open("Config.txt", std::ios::in);

	if(ioFile.is_open())
	{
		std::string szData = "";
		int nIndex = -1;
		
		getline(ioFile, szData);

		if(strlen(szData.c_str()) > 0)
		{
			getline(ioFile, szData);

			//////////////////////////////////////////////////////////////////////////
			// Screen Width
			getline(ioFile, szData);
			nIndex = szData.find_last_of(":");
			
			if(nIndex > -1)
			{
				szData.erase(0, nIndex + 2);
				m_uiScreenWidth = atoi(szData.c_str());

				if(m_uiScreenWidth == 0)
					m_uiScreenWidth = 600;
			}
			else
				m_uiScreenWidth = 600;

			//////////////////////////////////////////////////////////////////////////
			//Screen Height
			getline(ioFile, szData);
			nIndex = szData.find_last_of(":");
			if(nIndex > -1)
			{
				szData.erase(0, nIndex + 2);
				m_uiScreenHeight = atoi(szData.c_str());
				
				if(m_uiScreenHeight == 0)
					m_uiScreenHeight = 800;
			}
			else
				m_uiScreenWidth = 800;

			//////////////////////////////////////////////////////////////////////////
			//Full Screen
			getline(ioFile, szData);
			nIndex = szData.find_last_of(":");
			if(nIndex > -1)
			{
				szData.erase(0, nIndex + 2);
				m_bFullScreen = (atoi(szData.c_str()) == 1) ? true : false;
			}
			else
				m_bFullScreen = false;

			//////////////////////////////////////////////////////////////////////////
			//Borderless
			getline(ioFile, szData);
			nIndex = szData.find_last_of(":");
			if(nIndex > -1)
			{
				szData.erase(0, nIndex + 2);
				m_bBorderless = (atoi(szData.c_str()) == 1) ? true : false;
			}
			else
				m_bBorderless = true;

			//////////////////////////////////////////////////////////////////////////
			//Vertical Sync
			getline(ioFile, szData);
			nIndex = szData.find_last_of(":");
			if(nIndex > -1)
			{
				szData.erase(0, nIndex + 2);
				m_bVerticalSync = (atoi(szData.c_str()) == 1) ? true : false;
			}
			else
				m_bVerticalSync = true;
		}

		ioFile.close();
	}
	else
		SetDefault();

	m_bIsLoaded = true;
}

// Writes out the config.txt file
void Config::SaveConfig()
{
	std::fstream ioFile;
	ioFile.open("Config.txt", std::ios::out | std::ios::trunc);

	if(ioFile.is_open())
	{
		ioFile << "Video Configurations\n\n";
		ioFile << "Screen Width: " << m_uiScreenWidth << std::endl;
		ioFile << "Screen Height: " << m_uiScreenHeight << std::endl;
		ioFile << "Full Screen: " << m_bFullScreen << std::endl;
		ioFile << "Borderless: " << m_bBorderless << std::endl;
		ioFile << "Vertical Sync: " << m_bVerticalSync << std::endl;

		ioFile.close();
	}
}

// void Config::SetOpenGLVerison(int _nMajor, int _nMinor)
// {
// 	char text[16];
// 	sprintf_s(text, "%d.%d", _nMajor, _nMinor);
// 	m_szOpenGLVersion = text;
// }