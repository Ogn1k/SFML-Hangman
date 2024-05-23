#include "Game.hpp"

void Game::initWin()
{

	std::ifstream ifs("config.ini");

	std::string title = "Hangman";
	VideoMode windowSize(768, 768);
	unsigned framerateLimit = 120;
	bool vertSinc = false;
	if (ifs.is_open())
	{
		ifs >> windowSize.width >> windowSize.height;
		ifs >> framerateLimit;
		ifs >> vertSinc;
	}
	ifs.close();
	//ContextSettings::
	window = new RenderWindow(windowSize, title);
	window->setFramerateLimit(framerateLimit);
	window->setVerticalSyncEnabled(vertSinc);


	//winIcon.loadFromFile("textures/cirni.png");
	//window->setIcon(winIcon.getSize().x, winIcon.getSize().y, winIcon.getPixelsPtr());
}

void Game::initScenes()
{
	a = new lvl0(&sceneData);
	b = new lvl1(&sceneData);
	c = new lvl2(&sceneData);
	scenes.push_back(a);
	//scenes.push(new lvl2(window, &scenes));

}

void Game::initSceneData()
{
	sceneData.window = window;
	sceneData.scenes = &scenes;
	std::ifstream ifs("config.ini");
	if (ifs.is_open())
	{
		ifs >> sceneData.windowSize.width >> sceneData.windowSize.height;
	}
	ifs.close();
}

Game::Game()
{

	initWin();
	initSceneData();
	initScenes();


}

Game::~Game()
{
	delete window;

	while (scenes.empty())
	{
		delete scenes.back();
		scenes.pop_back();
	}
}

void Game::endApp()
{
	window->close();

	Game::~Game();
	//saving... i guess?
}



void Game::changeScene(int lvl, ScenePublicData* scene_data)
{
	/*switch (lvl)
	{
	case 0:
		
		break;
	case 1:
		
		break;
	case 2:
		
		break;
	default:
		
		break;
	}*/
	if (lvl == 0)
	{
		std::cout << "a" << std::endl;
		scenes.front() = new lvl0(scene_data);
	}
	else if (lvl == 1)
	{
		std::cout << "b" << std::endl;
		scenes.back() = new lvl1(scene_data);
	}
	else if (lvl == 2)
	{
		std::cout << "c" << std::endl;
		scenes.back() = new lvl2(scene_data);
	}
	else
	{
		std::cout << "no lvl " << lvl << std::endl;
	}
}



Game& Game::getInstance()
{
	static Game instance;
	return instance;
}

void Game::uptadeDeltaTime()
{
	deltaTime = deltaTimeClock.restart().asSeconds();
}

void Game::updateSfmlEvents()
{
	while (window->pollEvent(sfEvent))
	{
		if (sfEvent.type == Event::Closed)
			window->close();
		if (!scenes.empty())
			scenes.back()->updateSfmlEvents(sfEvent);
	}
}

void Game::update()
{
	updateSfmlEvents();

	if (!scenes.empty())
	{
		scenes.back()->update(deltaTime);
		if (scenes.back()->getQuit())
		{
			scenes.back()->endScene();
			delete scenes.back();
			//scenes.back();
		}
	}
	else
	{
		endApp();
		window->close();
	}
}

void Game::render()
{

	window->clear();

	//
	if (!scenes.empty())
		scenes.back()->render();

	window->display();

}

void Game::run()
{
	while (window->isOpen())
	{
		uptadeDeltaTime();
		update();
		render();
	}
}
