#include <Common.h>
#include "Surface.h"
#include <string>
#include <SDL_image.h>

Surface::Surface(SDL_Surface* surface)
{
	m_pSurface = surface;
	m_uiTextureID = 0;
	//m_ImageRect(0, 0, 0, 0);
	m_bIsMaxFiltering = true;
	m_fRepeatFactor = 1.0f;
}

Surface::Surface()
{
	m_pSurface = nullptr;
	m_uiTextureID = 0;
	//m_ImageRect(0, 0, 0, 0);
	m_bIsMaxFiltering = true;
	m_fRepeatFactor = 1.0f;
}

Surface::Surface(const AssetImage& imageFile)
{
	m_pSurface = nullptr;
	m_uiTextureID = 0;
	//m_ImageRect = SDL_Rect(){ 0, 0, 0, 0 };
	m_bIsMaxFiltering = true;
	m_fRepeatFactor = 1.0f;

	loadImage(imageFile);
}

Surface::~Surface()
{
	release();
}

void Surface::release()
{
	if(m_uiTextureID)
	{
		glDeleteTextures(1, &m_uiTextureID);
		m_uiTextureID = 0;
	}
}

void Surface::loadImage(const AssetImage& imageFile)
{

}