#pragma once
#include "Scenes/Lvl1.h"
#include <algorithm>


using namespace sf;

class Game
{
	RenderWindow* window;
	std::vector<Scene*> scenes;

	Image winIcon;

	Event sfEvent;

	Clock deltaTimeClock;
	float deltaTime;

	Scene *a, *b, *c;


	void initWin();
	void initScenes();

public:
	ScenePublicData sceneData;
	Game();
	virtual ~Game();

	void endApp();

	void initSceneData();
	void changeScene(int lvl, ScenePublicData* scene_data);

	void uptadeDeltaTime();
	void updateSfmlEvents();
	void update();

	void render();
	void run();
	static Game& getInstance();
};

