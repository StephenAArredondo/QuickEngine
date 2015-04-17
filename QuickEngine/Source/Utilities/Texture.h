#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <Common.h>
#include <string>

class Texture
{
private:

	enum eTextureType { NONE = 0, LOADED, CREATED, COPIED };

	// Unique ID given by the TextureManager for referencing this texture
	unsigned int m_uiUniqueID;

	std::string m_szTextureName;

	// Number of objects that reference this texture
	unsigned int m_uiReferenceCount;

	// Holds image size and pointer to pixel array
	SDL_Texture* m_Image;

	// Image width value
	int m_nWidth;

	// Image height value
	int m_nHeight;

	// ID returned from glGenTextures
	GLuint m_uiHandle;

	// GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_CUBE
	GLuint m_uiTextureTarget;

	// If the texture was loaded from a file or created during runtime for general use
	unsigned int m_uiTextureType;

	bool GenerateTexture();

public:

	Texture();
	~Texture();
	Texture(const Texture& _pTexture){}
	Texture* operator=(const Texture&){}

	Texture(std::string _szTextureName, std::string _szTexturePath);
	Texture(unsigned int _uiWidth, unsigned int _uiHeight, SDL_Color _eColor, std::string _szTextureName);

	// Loads a texture file specified at the file path
	bool LoadTexture(std::string _szTextureName, std::string _szTexturePath);
	
	// Creates a simple texture from memory
	bool CreateTexture(unsigned int _uiWidth, unsigned int _uiHeight, SDL_Color _eColor, std::string _szTextureName);

	// Saves the currently held texture to the HDD
	bool SaveTexture(std::string _szFileName);

	// Increase the ref count by one
	inline void AddRef() { m_uiReferenceCount++; }

	// Decreases the ref count by one and returns whether there are any remaining references
	inline bool RemoveRef() { return ((--m_uiReferenceCount) == 0) ? true : false; }

	void SetUniqueID(unsigned int _uiUniqueID) { m_uiUniqueID = _uiUniqueID; }

	inline std::string GetTextureName() { return m_szTextureName; }

	inline const SDL_Texture* GetTexture() { return m_Image; }
	
	inline unsigned int GetTextureWidth() { return m_nWidth; }

	inline unsigned int GetTextureHeight() { return m_nHeight; }	

	inline GLuint GetTextureHandle() { return m_uiHandle; }

	void DeleteTextures();
};

#endif