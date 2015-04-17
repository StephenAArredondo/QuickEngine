#include <Common.h>
#include "Asset.h"

Asset::Asset() : m_eType(INVALID_TYPE), m_strSubFolder(""), m_strFileName("") {}

Asset::~Asset() {}

Asset::Type Asset::type() const
{
	return m_eType;
}

std::string Asset::path() const
{
	return m_strSubFolder + m_strFileName;
}

std::string Asset::fileName() const
{
	return m_strFileName;
}

AssetShader::AssetShader()
{
	m_eType = SHADER;
	m_strSubFolder = std::string("shaders/");
	m_strFileName = "";
}
AssetShader::AssetShader(const std::string& resource)
{
	m_eType = SHADER;
	m_strSubFolder = std::string("shaders/");
	m_strFileName = resource;
}
AssetShader::~AssetShader() {}

AssetImage::AssetImage()
{
	m_eType = IMAGE;
	m_strSubFolder = std::string("images/");
	m_strFileName = "";
}
AssetImage::AssetImage(const std::string& resource)
{
	m_eType = IMAGE;
	m_strSubFolder = std::string("images/");
	m_strFileName = resource;
}
AssetImage::~AssetImage() {}

AssetFont::AssetFont()
{
	m_eType = FONT;
	m_strSubFolder = std::string("fonts/");
	m_strFileName = "";
}
AssetFont::AssetFont(const std::string& resource)
{
	m_eType = FONT;
	m_strSubFolder = std::string("fonts/");
	m_strFileName = resource;
}
AssetFont::~AssetFont() {}

AssetMesh::AssetMesh()
{
	m_eType = MESH;
	m_strSubFolder = std::string("meshes/");
	m_strFileName = "";
}
AssetMesh::AssetMesh(const std::string& resource)
{
	m_eType = MESH;
	m_strSubFolder = std::string("meshes/");
	m_strFileName = resource;
}
AssetMesh::~AssetMesh() {}

AssetAnimation::AssetAnimation()
{
	m_eType = ANIMATION;
	m_strSubFolder = std::string("animations/");
	m_strFileName = "";
}
AssetAnimation::AssetAnimation(const std::string& resource)
{
	m_eType = ANIMATION;
	m_strSubFolder = std::string("animations/");
	m_strFileName = resource;
}
AssetAnimation::~AssetAnimation() {}

AssetSound::AssetSound()
{
	m_eType = SOUND;
	m_strSubFolder = std::string("sounds/");
	m_strFileName = "";
}
AssetSound::AssetSound(const std::string& resource)
{
	m_eType = SOUND;
	m_strSubFolder = std::string("sounds/");
	m_strFileName = resource;
}
AssetSound::~AssetSound() {}

AssetMusic::AssetMusic()
{
	m_eType = MUSIC;
	m_strSubFolder = std::string("music/");
	m_strFileName = "";
}
AssetMusic::AssetMusic(const std::string& resource)
{
	m_eType = MUSIC;
	m_strSubFolder = std::string("music/");
	m_strFileName = resource;
}
AssetMusic::~AssetMusic() {}