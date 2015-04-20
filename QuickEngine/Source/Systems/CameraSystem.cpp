#include <Common.h>
#include "CameraSystem.h"

void CameraSystem::configure(QEventManager& events)
{
	events.subscribe<TranslationEvent>((*this));
	events.subscribe<RotationEvent>((*this));
	events.subscribe<ScaleEvent>((*this));
	events.subscribe<KeyboardEvent>((*this));
}

void CameraSystem::update(QEntityManager& entities, QEventManager& events, QTimeDelta dt)
{
	for (auto cameras : entities.entities_with_components<CameraComponent>())
	{
		auto camera = cameras.component<CameraComponent>();

		if (camera->m_RenderContext == nullptr)
		{
			camera->m_RenderContext = SDL_CreateRenderer(m_WindowHandle, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(camera->m_RenderContext, 0, 0, 0, 255);

			//SDL_RenderSetLogicalSize(camera->m_RenderContext, 800, 600);
			//SDL_RenderSetScale(camera->m_RenderContext, 800, 600);
		}
	}
}

void CameraSystem::receive(const TranslationEvent& translation)
{
	//translation.
}

void CameraSystem::receive(const RotationEvent& rotation)
{
	//translation.
}

void CameraSystem::receive(const ScaleEvent& scale)
{
	//translation.
}

void CameraSystem::receive(const KeyboardEvent& entityInput)
{
	if (entityInput.m_Entity->has_component<CameraComponent>())
	{
		auto camera = entityInput.m_Entity->component<CameraComponent>();

		float m_fSpeed = 15.0f * 0.001f;

		if (entityInput.m_KeyboardInputs[SDL_SCANCODE_W])
		{
			camera->m_Camera.ViewTranslateLocalZ(-m_fSpeed);
		}
		if (entityInput.m_KeyboardInputs[SDL_SCANCODE_S])
		{
			camera->m_Camera.ViewTranslateLocalZ(m_fSpeed);
		}
		if (entityInput.m_KeyboardInputs[SDL_SCANCODE_SPACE])
		{
			camera->m_Camera.ViewTranslateLocalY(m_fSpeed);
		}
		 if (entityInput.m_KeyboardInputs[SDL_SCANCODE_LSHIFT])
		{
			camera->m_Camera.ViewTranslateLocalY(-m_fSpeed);
		}
		if (entityInput.m_KeyboardInputs[SDL_SCANCODE_A])
		{
			camera->m_Camera.ViewTranslateLocalX(-m_fSpeed);
		}
		if (entityInput.m_KeyboardInputs[SDL_SCANCODE_D])
		{
			camera->m_Camera.ViewTranslateLocalX(m_fSpeed);
		}
		if (entityInput.m_KeyboardInputs[SDL_SCANCODE_LEFT])
		{
			camera->m_Camera.ViewRotateGlobalY(-m_fSpeed * 10);
		}
		if (entityInput.m_KeyboardInputs[SDL_SCANCODE_RIGHT])
		{
			camera->m_Camera.ViewRotateGlobalY(m_fSpeed * 10);
		}
	}
}