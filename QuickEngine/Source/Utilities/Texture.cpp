#include <Common.h>
#include "Texture.h"

Texture::Texture()
{
	m_uiUniqueID = INVALID_RESOURCE_ID;
	m_szTextureName = "";
	m_uiReferenceCount = 0;

	m_uiHandle = 0;
	m_uiTextureTarget = 0;
	m_uiTextureType = NONE;
}

Texture::~Texture()
{

}

Texture::Texture(std::string _szTextureName, std::string _szTexturePath)
{
	LoadTexture(_szTextureName, _szTexturePath);
}

Texture::Texture(unsigned int _uiWidth, unsigned int _uiHeight, SDL_Color _eColor, std::string _szTextureName)
{
	CreateTexture(_uiWidth, _uiHeight, _eColor, _szTextureName);
}

bool Texture::LoadTexture(std::string _szTextureName, std::string _szTexturePath)
{
	if(m_uiTextureType != NONE || _szTextureName.length() <= 4)
		return false;

	std::string szFilePath(_szTexturePath);
	szFilePath += _szTextureName;

// 	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
// 	
// 	if(loadedSurface == NULL)
// 		return false;
// 
// 	m_Image = SDL_CreateTextureFromSurface()

// 	if(!m_Image.loadFromFile(szFilePath))
// 		return false;

	m_szTextureName = _szTextureName;
	m_uiTextureType = LOADED;

	GenerateTexture();

	return true;
}

bool Texture::CreateTexture(unsigned int _uiWidth, unsigned int _uiHeight, SDL_Color _eColor, std::string _szTextureName)
{
	if(m_uiTextureType != NONE || _uiWidth == 0 || _uiHeight == 0 || _szTextureName.length() == 0)
		return false;

	m_nWidth = _uiWidth;
	m_nHeight = _uiHeight;

	//m_Image.create(_uiWidth, _uiHeight, _eColor);
	m_szTextureName = _szTextureName;

	GenerateTexture();

	return true;
}

bool Texture::SaveTexture(std::string _szFileName)
{
	if(m_uiTextureType == NONE || _szFileName.length() == 0)
		return false;

	std::string szFileName(_szFileName);
	szFileName += ".png";

// 	if(!m_Image.saveToFile(szFileName))
// 		return false;

	return true;
}

bool Texture::GenerateTexture()
{
	glGenTextures(1, &m_uiHandle);

// 	glBindTexture( GL_TEXTURE_2D, Item::texture[i] );
// 	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, t.width(), t.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, t.bits() );
// 	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
// 	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	return (m_uiHandle != INVALID_RESOURCE_ID) ? true : false;
}

void Texture::DeleteTextures()
{
	glDeleteTextures(1, &m_uiHandle);
}