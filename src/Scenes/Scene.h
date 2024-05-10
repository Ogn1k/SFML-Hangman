#pragma once

#include <fstream>
#include <sstream>
#include <vector>
//#include <map>
#include "Misc/Button.h"

using namespace sf;

class Scene;

enum Difficulty
{
	EASY = 4,
	NORMAL = 6,
	HARD = 8
};

enum GameState
{
	WIN = 0,
	LOSE = 1,
	SECRET = 2
};

struct ScenePublicData
{
	ScenePublicData() {};
	RenderWindow* window;
	std::vector<Scene*>* scenes;
	Difficulty difficulty = EASY;
	GameState gameState = SECRET;

	VideoMode windowSize = VideoMode(768, 768);

};

class Scene
{
private:

protected:
	ScenePublicData* sceneData;

	std::vector<Scene*>* scenes;

	RenderWindow* window;
	bool quit;

	Vector2i mousePosScreen;
	Vector2i mousePosWindow;
	Vector2f mousePosView;

public:

	Scene(ScenePublicData* sceneData);
	virtual ~Scene();


	const bool& getQuit() const;
	virtual void checkForQuit();
	virtual void endScene();

	virtual void updateSfmlEvents(Event event) = 0;
	virtual void updateInput(const float& deltatime) = 0;
	virtual void updateMousePosition();
	virtual void update(const float& deltaTime) = 0;
	virtual void render(RenderTarget* target = nullptr, RenderStates* states = nullptr) = 0;
};

