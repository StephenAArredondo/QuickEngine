#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#include "BaseManager.h"
#include <map>
#include "..\Utilities\Texture.h"

class TextureManager : public BaseManager
{
private:
	std::string strTextureDir;

	std::map<unsigned int, Texture*> m_vTextures;
	bool m_bDefaultLoaded;

	TextureManager();
	~TextureManager();
	TextureManager(const TextureManager&){}
	TextureManager* operator=(const TextureManager&){}

public:

	void Initialize();
	void Shutdown();

	Texture* GetTexture(unsigned int _uiTextureID);
	unsigned int LoadTexture(std::string _szFileName, std::string _szFilePath = "");
	unsigned int CreateTexture(SDL_Color _pColor, unsigned int _uiWidth, unsigned int _uiHeight, std::string _szColorName);
	void ReGenAllTextures();

	static TextureManager* GetInstance();

};

/*
	if (Event.Key.Code == sf::Key::F1)
	{
		sf::Image Screen = App.Capture();
		Screen.SaveToFile("screenshot.jpg");
	}
*/

#endif