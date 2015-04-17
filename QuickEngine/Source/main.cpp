#include <Common.h>
#include "Game.h"

#ifdef __cplusplus
	extern "C"
#endif

int main(int argc, char *argv[])
{
	Game _Game;
	_Game.Start();
	_Game.GameLoop();
	_Game.Shutdown();

	return 0;
}