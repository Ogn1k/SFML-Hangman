#pragma once
#include "Scene.h"
#include "Lvl1.h"

class lvl0 : public Scene
{
	VideoMode windowSize = sceneData->windowSize;
	Text2 title = Text2("hangman", 48, Color::Black);

	

	RectangleShape background = RectangleShape(Vector2f(windowSize.width, windowSize.height));
	std::wstring te1 = L"Начать", te2 = L"Настройки", te3 = L"Назад", te4 = L"О приложении";
	Button gameStartb = Button(windowSize.width / 2, windowSize.height / 1.8, 200, 50, te1, "", Color::White, Color::Yellow, Color::Green);
	Button settingsb = Button(windowSize.width / 2, windowSize.height / 1.5, 200, 50, te2, "", Color::White, Color::Yellow, Color::Green);
	Button aboutb = Button(windowSize.width / 2, windowSize.height / 1.3, 200, 50, te4, "", Color::White, Color::Yellow, Color::Green);

	Text2 aboutText = Text2(L"Работу сделали\n Егор Квашнев и Федорушкин Стас :3", 48, Color::Black);
	Button buttonBack = Button(50, 50, 70, 50, te3, "", Color::White, Color::Yellow, Color::Green);

	std::wstring easyS = L"Легкая сложность", normalS = L"Средняя сложность", hardS = L"ХАРДКОООР";
	Button easyB = Button(windowSize.width / 2, windowSize.height / 1.8, 200, 50, easyS, "", Color::White, Color::Yellow, Color::Green);
	Button normalB = Button(windowSize.width / 2, windowSize.height / 1.3, 200, 50, normalS, "", Color::White, Color::Yellow, Color::Green);
	Button hardB = Button(windowSize.width / 2, windowSize.height / 1.1, 200, 50, hardS, "", Color::White, Color::Yellow, Color::Green);

	Text2 difficultyText = Text2(L"Сложность", 48, Color::Black);

	bool aboutbb = false;
	bool settingsbb = false;

public:
	lvl0(ScenePublicData* sceneData);

	virtual ~lvl0();
	void endScene();

	void updateSfmlEvents(Event event);
	void updateInput(const float& deltatime);
	void update(const float& deltaTime);
	void render(RenderTarget* target = nullptr, RenderStates* states = nullptr);
};

