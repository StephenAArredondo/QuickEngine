#include <Common.h>
#include "TextureManager.h"
#include "..\Utilities\Color.h"

TextureManager* TextureManager::GetInstance()
{
	static TextureManager pInstance;
	return &pInstance;
}

TextureManager::TextureManager()
{
	m_vTextures.clear();
	m_bInitialized = false;
	strTextureDir = "..\\..\\Assets\\Textures\\";
}

TextureManager::~TextureManager()
{
	if(m_bInitialized)
		Shutdown();
}

void TextureManager::Initialize()
{
	m_vTextures.clear();

	if(LoadTexture("UV_Grid.png", strTextureDir) == INVALID_RESOURCE_ID)
		CreateTexture(CColor::Cyan().GetColor(), 8, 8, "Cyan");

	m_bDefaultLoaded = true;
	m_bInitialized = true;
}

void TextureManager::Shutdown()
{
	std::map<unsigned int, Texture*>::iterator pIter = m_vTextures.begin();

	while(pIter != m_vTextures.end())
	{
		pIter->second->DeleteTextures();
		delete pIter->second;
		pIter->second = NULL;

		++pIter;
	}

	m_vTextures.clear();
	m_bDefaultLoaded = false;
	m_bInitialized = false;
}

Texture* TextureManager::GetTexture(unsigned int _uiTextureID)
{
	std::map<unsigned int, Texture*>::iterator pIter = m_vTextures.find(_uiTextureID);
	
	if(pIter != m_vTextures.end())
		return pIter->second;

	return m_vTextures[0];
}

unsigned int TextureManager::LoadTexture(std::string _szFileName, std::string _szFilePath)
{
	std::map<unsigned int, Texture*>::iterator pIter = m_vTextures.begin();

	while(pIter != m_vTextures.end())
	{
		if(pIter->second->GetTextureName() == _szFileName)
		{
			pIter->second->AddRef();
			return pIter->first;
		}

		++pIter;
	}

	Texture* pNewTexture = new Texture();
	if(!pNewTexture->LoadTexture(_szFileName, _szFilePath))
	{
		delete pNewTexture;
		return (m_bDefaultLoaded) ? 0 : INVALID_RESOURCE_ID;
	}

	unsigned int uiUniqueID = 0;
	pIter = m_vTextures.begin();

	while(pIter != m_vTextures.end())
	{
		if(pIter->first != uiUniqueID)
			break;

		++uiUniqueID;
		++pIter;
	}

	pNewTexture->SetUniqueID(uiUniqueID);
	pNewTexture->AddRef();
	m_vTextures[uiUniqueID] = pNewTexture;

	return uiUniqueID;
}

unsigned int TextureManager::CreateTexture(SDL_Color _pColor, unsigned int _uiWidth, unsigned int _uiHeight, std::string _szColorName)
{
	std::map<unsigned int, Texture*>::iterator pIter = m_vTextures.begin();

	while(pIter != m_vTextures.end())
	{
		if(pIter->second->GetTextureName() == _szColorName)
		{
			if((pIter->second->GetTextureWidth() == _uiWidth) && (pIter->second->GetTextureHeight() == _uiHeight))
			{
				pIter->second->AddRef();
				return pIter->first;
			}
		}
		++pIter;
	}

	Texture* pNewTexture = new Texture();
	if(!pNewTexture->CreateTexture(_uiWidth, _uiWidth, _pColor, _szColorName))
	{
		delete pNewTexture;
		return (m_bDefaultLoaded) ? 0 : INVALID_RESOURCE_ID;
	}

	unsigned int uiUniqueID = 0;
	pIter = m_vTextures.begin();

	while(pIter != m_vTextures.end())
	{
		if(pIter->first != uiUniqueID)
			break;

		++uiUniqueID;
		++pIter;
	}

	pNewTexture->SetUniqueID(uiUniqueID);
	pNewTexture->AddRef();	
	m_vTextures[uiUniqueID] = pNewTexture;

	return uiUniqueID;
}

void TextureManager::ReGenAllTextures()
{

}