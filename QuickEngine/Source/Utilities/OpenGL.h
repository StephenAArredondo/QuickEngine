#ifndef _OPENGL_H_
#define _OPENGL_H_

#include <Common.h>

class Config;

class OpenGL
{
private:

	bool m_bInitialized;

	union VERSION
	{
		struct SVersion
		{
			short m_sMajor;
			short m_sMinor;

		} m_SVersion;	

		float m_fVersion;
	} m_Version;

	Config* m_pConfig;

// 	sf::ContextSettings m_Settings;
// 	sf::VideoMode m_CurrVideoMode;
	unsigned int m_Style;

	unsigned int m_uiNumVideoModes;
	//std::vector<sf::VideoMode> m_vFullScreenVideoModes;

	float m_fAspectRatio;
	float m_fNearPlane;
	float m_fFarPlane;
	bool  m_bFullScreenMode;

	bool  m_bEnabled2D;

	OpenGL();
	~OpenGL();
	OpenGL(const OpenGL&){}
	OpenGL& operator=(const OpenGL){}


public:

	bool InitGL();
	void DefaultVideoMode();

	void GLEnable2D();
	void GLDisable2D();

	bool Initialize();
	bool Shutdown();

	inline bool IsInitialized() { return m_bInitialized; }

	//////////////////////////////////////////////////////////////////////////
	// Accessors
// 	inline const sf::ContextSettings& GetContextSettings() { return m_Settings; }
// 	inline const sf::VideoMode& GetCurrVideoMode() { return m_CurrVideoMode; }
	inline const unsigned int GetStyle() { return m_Style; }
	
// 	inline const unsigned int GetBitDepth() { return m_Settings.depthBits; }
// 	inline const unsigned int GetAALevel() { return m_Settings.antialiasingLevel; }
	
// 	inline const unsigned int GetScreenWidth() { return m_CurrVideoMode.width; }
// 	inline const unsigned int GetScreenHeight() { return m_CurrVideoMode.height; }

	inline const unsigned int GetNumVideoModes() { return m_uiNumVideoModes; }
	//inline const std::vector<sf::VideoMode>& GetFullScreenVideoModes() { return m_vFullScreenVideoModes; }

	//////////////////////////////////////////////////////////////////////////
	// Modifiers
	void SetStyle(unsigned int _uiStyle) { m_Style = _uiStyle; }

	static OpenGL* GetInstance();
};

#endif