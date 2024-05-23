#include "Scene.hpp"

Scene::Scene(ScenePublicData* sceneData)
{
	this->sceneData = sceneData;
	this->scenes = sceneData->scenes;
	this->window = sceneData->window;
	quit = false;
}

Scene::~Scene()
{
}

const bool& Scene::getQuit() const
{
	return quit;
}

void Scene::checkForQuit()
{
}

void Scene::endScene()
{
	quit = true;
}

void Scene::updateInput(const float& deltatime)
{
}

void Scene::updateMousePosition()
{
	mousePosScreen = Mouse::getPosition();
	mousePosWindow = Mouse::getPosition(*window);
	mousePosView = window->mapPixelToCoords(Mouse::getPosition(*window));

	//system("cls");
	//std::cout << Mouse::getPosition(*window).x << " " << Mouse::getPosition(*window).y;
}
