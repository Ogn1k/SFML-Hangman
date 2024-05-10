#include "lvl1.h"
#include <algorithm>
#include <time.h>

lvl1::lvl1(ScenePublicData* sceneData)
	: Scene(sceneData)
{
	font.loadFromFile("Resources/Edwardian.ttf");
	title.setPos(windowSize.width / 2, windowSize.height / 1.1);
	title.text.setOrigin(title.text.getGlobalBounds().width * 0.5, title.text.getGlobalBounds().height * 0.5);

	wordCurGraph.setPos(windowSize.width / 3, windowSize.height / 2.2);
	wordCurGraph.text.setOrigin(wordCurGraph.text.getGlobalBounds().width * 0.5, wordCurGraph.text.getGlobalBounds().height * 0.5);
	wordCurGraph.text.setLetterSpacing(13);

	srand(time(NULL));

	switch (sceneData->difficulty)
	{
		case EASY:
			charBoxOffset = windowSize.width / 3;
			wordCur = wordsEasy[rand() % wordsEasy.size()];
			break;
		case NORMAL:
			charBoxOffset = windowSize.width / 3.5;
			wordCur = wordsNormal[rand() % wordsNormal.size()];
			break;
		case HARD:
			charBoxOffset = windowSize.width / 5;
			wordCur = wordsHard[rand() % wordsHard.size()];
			break;
	}
	std::cout << wordCur.toAnsiString() << std::endl;
}

lvl1::~lvl1()
{

}

void lvl1::updateSfmlEvents(Event event)
{
	bool keyPressed = false;
	std::wstring key;
	keyboardButtons.resize(36, Button());

	auto get_wstring = [](const std::string str)->std::wstring
	{
		const char* c = str.c_str();
		const size_t cSize = str.size() + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, c, cSize);
		std::wstring w_string(wc);
		delete[] wc;
		return w_string;
	};
	
	for (int i = 0; i < 32; i++)
	{
		int x = windowSize.width / 10 + i * 60;
		int y = windowSize.height / 1.7;
		if (i > 10)
		{
			y = windowSize.height / 1.5;
			x = windowSize.width / 10 + i * 60 - 10 * 60;
		}
		if (i > 19)
		{
			y = windowSize.height / 1.35;
			x = windowSize.width / 10 + i * 60 - 18 * 60;
		}
		if (i > 26)
		{
			y = windowSize.height / 1.23;
			x = windowSize.width / 10 + i * 60 - 24 * 60;
		}
		keyboardButtons.push_back(Button(x, y, 40, 40, alphabet[i], "", Color::White, Color::Yellow, Color::Blue));
		keyboardButtons.back().setFont(&font);
		keyboardButtons.back().update(mousePosView);
		keyboardButtons.back().ButtonBoxfunc(true, mousePosView, 5, Color::Black);
		keyboardButtons.back().ButtonT.setCharacterSize(40);
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (keyboardButtons.back().isPressed())
			{
				key = alphabet[i];
				keyPressed = !keyPressed;
			}
		}
			
		//wordOnScreen.toAnsiString() = std::to_string(i);
	}
	if (keyPressed) 
	{
		std::cout << wordCur.toAnsiString() << std::endl;
		if (get_wstring(wordCur.toAnsiString()).find(key) == std::wstring::npos)
			spritesToRender++;
		else
			wordOnScreen = get_wstring(wordCur.toAnsiString());
	}
	
}
void lvl1::updateInput(const float& deltatime)
{
	checkForQuit();
}

void lvl1::Keyboard()
{
	
}

void lvl1::HangDrawFunction()
{
	for (int i = 1; i < 11; i++)
	{
		Texture hangTexture = Texture();
		hangTexture.loadFromFile("Resources/Textures/" + std::to_string(i) + ".png");
		hangmanTextures.push_back(hangTexture);

		Sprite2 hang = Sprite2(&hangTexture, windowSize.width / 4, 0);
		hang.setScale(1.5, 1.5);
		hangmanSprites.push_back(hang);
	}
}

void lvl1::WordBoxesDraw()
{
	for (int i = 0; i < wordsCount; i++)
	{
		RectangleShape wordBox = RectangleShape(Vector2f(50, 50));
		wordBox.setPosition(charBoxOffset + (i * 56), windowSize.height / 2.1);
		//wordBox.setScale(0.2f,0.2f);
		wordBox.setFillColor(Color::White);
		wordBox.setOutlineColor(Color::Black);
		wordBox.setOutlineThickness(5);
		wordGridVector.push_back(wordBox);
	}
}

void lvl1::update(const float& deltatime)
{
	updateInput(deltatime);
	updateMousePosition();

	Keyboard();
	WordBoxesDraw();
	HangDrawFunction();

	wordCurGraph.text.setString(wordOnScreen);
	
	
}

void lvl1::render(RenderTarget* target, RenderStates* states)
{
	if (!target)
		target = window;

	target->draw(background);

	for (auto& box : wordGridVector)
	{
		target->draw(box);
	}
	for (int i = 0; i < std::clamp(spritesToRender, 0, 11); i++)
	{
		hangmanSprites[i].sprite.setTexture(hangmanTextures[i]);
		hangmanSprites[i].render(target);
	}
	for (int i = 0; i < keyboardButtons.size(); i++)
	{
		keyboardButtons[i].render(target);
	}
	wordCurGraph.render(target);
	title.render(target);
}


