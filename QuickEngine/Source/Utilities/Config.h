#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>

class Config
{
private:

	bool m_bIsLoaded;

	unsigned int m_uiScreenWidth;
	unsigned int m_uiScreenHeight;
	bool m_bFullScreen;
	bool m_bVerticalSync;
	bool m_bBorderless;
	unsigned int m_uiMusicVolume;
	unsigned int m_uiSoundVolume;

	Config();
	~Config();
	Config(const Config&){}
	Config& operator=(const Config){}


public:

	// Resets all members to default values
	void SetDefault();

	// Reads in the config.txt file
	void LoadConfig();

	// Writes out the config.txt file
	void SaveConfig();

	// Accessors
	bool GetIsLoaded() const { return m_bIsLoaded; }
	unsigned int GetScreenWidth() const { return m_uiScreenWidth; }
	unsigned int GetScreenHeight() const { return m_uiScreenHeight; }
	bool GetFullScreen() const { return m_bFullScreen; }
	bool GetVerticalSync() const { return m_bVerticalSync; }
	bool GetBorderless() const { return m_bBorderless; }
	unsigned int GetMusicVolume() const { return m_uiMusicVolume; }
	unsigned int GetSoundVolume() const { return m_uiSoundVolume; }

	// Modifiers	
	void SetScreenWidth(unsigned int uiScreenWidth) { m_uiScreenWidth = uiScreenWidth; }
	void SetScreenHeight(unsigned int uiScreenHeight) { m_uiScreenHeight = uiScreenHeight; }
	void SetFullScreen(bool bFullScreen) { m_bFullScreen = bFullScreen; }
	void SetVerticalSync(bool bVerticalSync) { m_bVerticalSync = bVerticalSync; }
	void SetBorderless(bool bBorderless) { m_bBorderless = bBorderless; }
	void SetMusicVolume(unsigned int uiMusicVolume) { m_uiMusicVolume = uiMusicVolume; }
	void SetSoundVolume(unsigned int uiSoundVolume) { m_uiSoundVolume = uiSoundVolume; }

	// Instantiation
	static Config* GetInstance(void);
};

#endif