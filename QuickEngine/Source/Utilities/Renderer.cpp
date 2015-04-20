#include <Common.h>
#include "Renderer.h"

// Renderer* Renderer::GetInstance()
// {
// 	static Renderer pInstance;
// 	return &pInstance;
// }
// 
// Renderer::Renderer()
// {
// 	m_bWindowHasFocus = true;
// 	m_pDrawWindow = NULL;
// }
// 
// bool Renderer::Initialize()
// {
// 	return true;
// }
// 
// void Renderer::AcquireWindow(SDL_Window* pWindow)
// {
// 	m_pDrawWindow = (pWindow) ? SDL_CreateRenderer( pWindow, -1, SDL_RENDERER_ACCELERATED ) : nullptr;
// }
// 
// void Renderer::Draw2D()
// {
// 
// }
// 
// void Renderer::Shutdown()
// {
// 
// }
// 
// void Renderer::Enable2D()
// {
// 	GLint iViewport[4];
// 
// 	// Get a copy of the viewport
// 	glGetIntegerv( GL_VIEWPORT, iViewport );
// 
// 	// Save a copy of the projection matrix so that we can restore it 
// 	// when it's time to do 3D rendering again.
// 	glMatrixMode(GL_PROJECTION);
// 	glPushMatrix();
// 	glLoadIdentity();
// 
// 	// Set up the orthographic projection
// 	glOrtho(iViewport[0], iViewport[0] + iViewport[2], iViewport[1] + iViewport[3], iViewport[1], -1, 1);
// 
// 	glMatrixMode(GL_MODELVIEW);
// 	glPushMatrix();
// 	glLoadIdentity();
// 
// 	// Make sure depth testing and lighting are disabled for 2D rendering until
// 	// we are finished rendering in 2D
// 	glPushAttrib(GL_DEPTH_BUFFER_BIT | GL_LIGHTING_BIT);
// 	glDisable(GL_DEPTH_TEST);
// 	glDisable(GL_LIGHTING);
// }
// 
// void Renderer::Disable2D()
// {
// 	glPopAttrib();
// 	glMatrixMode( GL_PROJECTION );
// 	glPopMatrix();
// 	glMatrixMode( GL_MODELVIEW );
// 	glPopMatrix();
// }