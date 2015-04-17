#ifndef _ASSET_H_
#define _ASSET_H_

#include <string>

class Asset
{
public:

	enum Type
	{
		SHADER = 0,
		IMAGE,
		FONT,
		MESH,
		ANIMATION,
		SOUND,
		MUSIC,
		INVALID_TYPE
	};

	Asset();
	virtual ~Asset();

	Asset::Type type() const;
	std::string path() const;
	std::string fileName() const;

	friend inline bool operator<(const Asset& lhs, const Asset& rhs);
	friend inline bool operator==(const Asset& lhs, const Asset& rhs);
	friend inline bool operator!=(const Asset& lhs, const Asset& rhs);

protected:

	Asset::Type m_eType;
	std::string m_strSubFolder;
	std::string m_strFileName;

private:

	static const std::string m_strBase;
};

inline bool operator<(const Asset& lhs, const Asset& rhs)
{
	return lhs.path() < rhs.path();
}

inline bool operator==(const Asset& lhs, const Asset& rhs)
{
	return((lhs.m_eType == rhs.m_eType) && (lhs.m_strFileName == rhs.m_strFileName));
}

inline bool operator!=(const Asset& lhs, const Asset& rhs)
{
	return !(lhs == rhs);
}

class AssetShader : public Asset
{
public:
	AssetShader();
	explicit AssetShader(const std::string& resource);
	virtual ~AssetShader();
};

class AssetImage : public Asset
{
public:
	AssetImage();
	explicit AssetImage(const std::string& resource);
	virtual ~AssetImage();
};

class AssetFont : public Asset
{
public:
	AssetFont();
	explicit AssetFont(const std::string& resource);
	virtual ~AssetFont();
};

class AssetMesh : public Asset
{
public:
	AssetMesh();
	explicit AssetMesh(const std::string& resource);
	virtual ~AssetMesh();
};

class AssetAnimation : public Asset
{
public:
	AssetAnimation();
	explicit AssetAnimation(const std::string& resource);
	virtual ~AssetAnimation();
};

class AssetSound : public Asset
{
public:
	AssetSound();
	explicit AssetSound(const std::string& resource);
	virtual ~AssetSound();
};

class AssetMusic : public Asset
{
public:
	AssetMusic();
	explicit AssetMusic(const std::string& resource);
	virtual ~AssetMusic();
};

#endif//_ASSET_H_