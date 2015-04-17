#ifndef _SURFACE_H
#define _SURFACE_H

#include "Asset.h"

class Surface
{
public:
	Surface();
	Surface(const AssetImage& imageFile);
	Surface(SDL_Surface* surface);
	~Surface();

	void loadImage(const AssetImage& imageFile);
	void setSurface(SDL_Surface& surface);
	SDL_Surface* getSurface();

	void setGlTextureId(GLuint textureID, QVector2 size);

	GLuint glBind() const;
	void prepareForGL();

	GLuint getTextureID() const;

	unsigned int getWidth() const;
	unsigned int getHeight() const;
	QVector2 getSize() const;



private:

	void release();

	SDL_Surface* m_pSurface;
	GLuint m_uiTextureID;
	SDL_Rect m_ImageRect;
	bool m_bIsMaxFiltering;
	float m_fRepeatFactor;

	Surface(const Surface& c);
	Surface& operator=(const Surface& c);

};

#endif//_SURFACE_H