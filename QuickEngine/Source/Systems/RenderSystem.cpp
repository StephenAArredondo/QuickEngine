#include <Common.h>
#include "RenderSystem.h"

void RenderSystem::update(QEntityManager& entities, QEventManager& events, QTimeDelta dt)
{
	for (auto cameras : entities.entities_with_components<CameraComponent>())
	{
		auto camera = cameras.component<CameraComponent>();

		glClearColor(1.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(&camera->m_Camera.GetViewMatrix().m[0][0]);

		drawGrid();
		drawShapes();

		for (auto entity : entities.entities_with_components<RenderComponent>())
		{
			auto transform = entity.component<TransformComponent>();

			glPushMatrix();

			glTranslatef(transform->m_Position.x, transform->m_Position.y, transform->m_Position.z);
			glRotatef(transform->m_Rotation.w, transform->m_Rotation.x, transform->m_Rotation.y, transform->m_Rotation.z);
			glScalef(transform->m_Scale.x, transform->m_Scale.y, transform->m_Scale.z);

			glPopMatrix();
		}

		
	}
	SDL_GL_SwapWindow(m_WindowHandle);
	//		SDL_RenderPresent(camera->m_RenderContext);
}

void RenderSystem::drawGrid()
{

	// Turn the lines GREEN
	glColor3ub(0, 255, 255);

	// Draw a 1x1 grid along the X and Z axis'
	for (float i = -50; i <= 50; i += 1)
	{
		// Start drawing some lines
		glBegin(GL_LINES);

		// Do the horizontal lines (along the X)
		glVertex3f(-50, 0, i);
		glVertex3f(50, 0, i);

		// Do the vertical lines (along the Z)
		glVertex3f(i, 0, -50);
		glVertex3f(i, 0, 50);

		// Stop drawing lines
		glEnd();
	}
}

void RenderSystem::drawShapes()
{
	glTranslatef(-1.5f, 2.0f, -6.0f);				// Move Left 1.5 Units And Into The Screen 6.0
	glColor3f(0.0f, 1.0f, 0.0f);					// Set The Color To Green

	// draw...
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, 1.0f, 0.0f);              // Top
	glVertex3f(-1.0f, -1.0f, 0.0f);              // Bottom Left
	glVertex3f(1.0f, -1.0f, 0.0f);              // Bottom Right
	glEnd();

	glTranslatef(3.0f, 0.0f, 0.0f);                   // Move Right 3 Units

	glColor3f(0.5f, 0.5f, 1.0f);              // Set The Color To Blue One Time Only
	glBegin(GL_QUADS);                      // Draw A Quad
	glVertex3f(-1.0f, 1.0f, 0.0f);              // Top Left
	glVertex3f(1.0f, 1.0f, 0.0f);              // Top Right
	glVertex3f(1.0f, -1.0f, 0.0f);              // Bottom Right
	glVertex3f(-1.0f, -1.0f, 0.0f);              // Bottom Left
	glEnd();                            // Done Drawing The Quad
}