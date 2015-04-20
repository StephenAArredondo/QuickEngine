#ifndef _GAME_H_
#define _GAME_H_

class Game : public QReceiver<Game>
{
private:

	// Managers
	QEntityManager* m_EntityManager;
	QEventManager* m_EventManager;
	QSystemManager* m_SystemManager;

	//GameStateManager* m_pGameStateManager;

	SDL_Window* m_Window;
	SDL_GLContext m_GLContext;
	bool m_bRunning;
	QTimer m_Timer;
	SDL_Renderer* m_Renderer;

	FPS m_FPS;

	Config* m_pConfig;
	OpenGL* m_pOpenGL;

	Camera m_Camera;

	void CheckEvents();
	void SetWindowStyle();

public:

	Game();
	~Game();

	void Start();
	void LoadSystems();
	void UnloadSystems();

	void GameLoop();
	void Shutdown();
	void Draw();

	void DrawShapes();
	void DrawGrid();

	void receive(const InputEvent& input);
};

#endif