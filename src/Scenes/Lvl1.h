#pragma once
#include "Lvl0.h"
#include "Game.h"

using namespace sf;

class lvl1 : public Scene
{
protected:

	VideoMode windowSize = sceneData->windowSize;


	int wordsCount = sceneData->difficulty;
	double charBoxOffset = windowSize.width / 3;

	std::vector<sf::String> wordsEasy = {"����", "����", "����", "����"};
	std::vector<sf::String> wordsNormal = { "������", "������", "������", "������"};
	std::vector<sf::String> wordsHard = { "��������", "��������", "��������", "��������" };

	sf::String wordCur = "";
	sf::String wordOnScreen = "";

	Text2 wordCurGraph = Text2(wordOnScreen, 56, Color::Black);

	int spritesToRender = 0;

	RectangleShape background = RectangleShape(Vector2f(windowSize.width, windowSize.height));

	Font font;

	std::vector<RectangleShape> wordGridVector;
	std::vector<Sprite2> hangmanSprites;
	std::vector<Texture> hangmanTextures;
	std::vector<Button> keyboardButtons;
	std::wstring alphabet = L"��������������������������������";

	Text2 title = Text2("hangman", 48, Color::Black);

public:
	lvl1(ScenePublicData* sceneData);
	virtual ~lvl1();

	void Keyboard();
	void WordBoxesDraw();
	void HangDrawFunction();

	void updateSfmlEvents(Event event);
	void updateInput(const float& deltatime);
	void update(const float& deltaTime);
	void render(RenderTarget* target = nullptr, RenderStates* states = nullptr);

};



