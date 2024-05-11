#pragma once
#include "Scenes/Lvl1.h"

class lvl2 : public Scene
{
protected:

	VideoMode windowSize = sceneData->windowSize;

	Font font;
	Text2 gameStateGraph = Text2("", 56, Color::Black);

	RectangleShape background = RectangleShape(Vector2f(windowSize.width, windowSize.height));

	std::wstring exitS = L"Выйти из игры", playAgainS = L"Сыграть еще раз";
	Button exitB = Button(windowSize.width / 2, windowSize.height / 1.3, 200, 50, exitS, "", Color::White, Color::Yellow, Color::Green);
	Button playAgainB = Button(windowSize.width / 2, windowSize.height / 1.1, 200, 50, playAgainS, "", Color::White, Color::Yellow, Color::Green);

public:
	lvl2(ScenePublicData* sceneData);
	virtual ~lvl2();

	void updateSfmlEvents(Event event);
	void updateInput(const float& deltatime);
	void update(const float& deltaTime);
	void render(RenderTarget* target = nullptr, RenderStates* states = nullptr);

};

