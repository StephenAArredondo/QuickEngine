#include <Common.h>
#include "OpenGL.h"

#include "Config.h"

//////////////////////////////////////////////////////////////////////////
//	Needs to be called on program start to initialize all values.
//	Values are used to help initialize the Window.
//////////////////////////////////////////////////////////////////////////

OpenGL* OpenGL::GetInstance()
{
	static OpenGL pInstance;
	return &pInstance;
}

OpenGL::OpenGL()
{
	m_bInitialized = false;
	m_pConfig = NULL;

	m_uiNumVideoModes = 0;
	
	m_fAspectRatio = 0.0f;
	m_fNearPlane = 0.0f;
	m_fFarPlane = 0.0f;
	m_bFullScreenMode = false;
	m_bEnabled2D = false;
}

OpenGL::~OpenGL()
{

}

bool OpenGL::Initialize()
{
	m_pConfig = Config::GetInstance();

	// OpenGL Version to use
	m_Version.m_fVersion = 3.2f;
	m_Version.m_SVersion.m_sMajor = 3;
	m_Version.m_SVersion.m_sMinor = 2;

	m_bFullScreenMode = m_pConfig->GetFullScreen();
	m_bInitialized = true;

	return true;
}

bool OpenGL::InitGL()
{
	if(!m_bInitialized)
		return false;

	glViewport(0, 0, 640, 480);			// Reset The Current Viewport
	glMatrixMode(GL_PROJECTION);				// Select The Projection Matrix
	glLoadIdentity();							// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	//gluPerspective(45.0, (GLfloat)_nWidth / (GLfloat)_nHeight, 0.1, 100.0);

	m_fNearPlane = 0.1f;
	m_fFarPlane = 255.0f;
	m_fAspectRatio = (float)(640 / 480);
	GLfloat fH = tan( float(45 / 360.0f * 3.14159f) ) * m_fNearPlane;
	GLfloat fW = fH * m_fAspectRatio;
	
	glFrustum( -fW, fW, -fH, fH, m_fNearPlane, m_fFarPlane );
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glEnable(GL_TEXTURE_2D);
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	return true;
}

void OpenGL::DefaultVideoMode()
{
	
}

void OpenGL::GLEnable2D()
{
	GLint iViewport[4];

	// Get a copy of the viewport
	glGetIntegerv( GL_VIEWPORT, iViewport );

	// Save a copy of the projection matrix so that we can restore it 
	// when it's time to do 3D rendering again.
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();
	glLoadIdentity();

	// Set up the orthographic projection
	glOrtho( iViewport[0], iViewport[0]+iViewport[2], iViewport[1]+iViewport[3], iViewport[1], -1, 1 );
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	glLoadIdentity();

	// Make sure depth testing and lighting are disabled for 2D rendering until
	// we are finished rendering in 2D
	glPushAttrib( GL_DEPTH_BUFFER_BIT | GL_LIGHTING_BIT );
	glDisable( GL_DEPTH_TEST );
	glDisable( GL_LIGHTING );

	m_bEnabled2D = true;
}

void OpenGL::GLDisable2D()
{
	glPopAttrib();
	glMatrixMode( GL_PROJECTION );
	glPopMatrix();
	glMatrixMode( GL_MODELVIEW );
	glPopMatrix();

	m_bEnabled2D = false;
}

bool OpenGL::Shutdown()
{
	m_bInitialized = false;
	return true;
}