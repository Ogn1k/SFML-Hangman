#include "Lvl0.hpp"

lvl0::lvl0(ScenePublicData* sceneData)
	: Scene(sceneData)
{

	background.setPosition(0, 0);
	background.setFillColor(Color(255, 255, 255));

	title.text.setOrigin(Vector2f(title.text.getGlobalBounds().width * 0.5, title.text.getGlobalBounds().height * 0.5));
	title.setPos(windowSize.width / 2, windowSize.height / 5);

	aboutText.text.setOrigin(Vector2f(aboutText.text.getGlobalBounds().width * 0.5, aboutText.text.getGlobalBounds().height * 0.5));
	aboutText.setPos(windowSize.width / 2, windowSize.height / 5);

	difficultyText.text.setOrigin(Vector2f(aboutText.text.getGlobalBounds().width * 0.5, aboutText.text.getGlobalBounds().height * 0.5));
	difficultyText.setPos(windowSize.width / 2, windowSize.height / 5);

	gameStartb.setOriginCenter();
	settingsb.setOriginCenter();
	aboutb.setOriginCenter();
	buttonBack.setOriginCenter();

	easyB.setOriginCenter();
	normalB.setOriginCenter();
	hardB.setOriginCenter();
}

lvl0::~lvl0()
{
}

void lvl0::endScene()
{
}

void lvl0::updateSfmlEvents(Event event)
{
}

void lvl0::updateInput(const float& deltatime)
{
}

void lvl0::update(const float& deltaTime)
{
	updateInput(deltaTime);
	updateMousePosition();
	if (!aboutbb && !settingsbb)
	{
		gameStartb.update(mousePosView);
		gameStartb.ButtonBoxfunc(true, mousePosView, 5, Color::Black);
		settingsb.ButtonBoxfunc(true, mousePosView, 5, Color::Black);
		aboutb.ButtonBoxfunc(true, mousePosView, 5, Color::Black);
		
		if (gameStartb.isPressed())
			Game::getInstance().changeScene(1, sceneData);
		if (aboutb.isPressed())
			aboutbb = true;
		
		if (settingsb.isPressed())
			settingsbb = true;

		

		
	}
	if (settingsbb)
	{
		easyB.ButtonBoxfunc(true, mousePosView, 5, Color::Black);
		normalB.ButtonBoxfunc(true, mousePosView, 5, Color::Black);
		hardB.ButtonBoxfunc(true, mousePosView, 5, Color::Black);

		if (easyB.isPressed())
			sceneData->difficulty = EASY;

		if (normalB.isPressed())
			sceneData->difficulty = NORMAL;

		if (hardB.isPressed())
			sceneData->difficulty = HARD;
	}
	buttonBack.ButtonBoxfunc(true, mousePosView, 5, Color::Black);
	if (buttonBack.isPressed())
	{
		aboutbb = false;
		settingsbb = false;
	}
	switch (sceneData->difficulty)
	{
	case EASY:
		difficultyText.setString(L"������ ���������");
		break;
	case NORMAL:
		difficultyText.setString(L"������� ���������");
		break;
	case HARD:
		difficultyText.setString(L"����������");
		break;
	}
}

void lvl0::render(RenderTarget* target, RenderStates* states)
{
	if (!target)
		target = window;

	target->draw(background);
	if (!aboutbb && !settingsbb)
	{
		title.render(target);
		gameStartb.render(target);
		settingsb.render(target);
		aboutb.render(target);
	}
	else if(aboutbb)
	{
		buttonBack.render(target);
		aboutText.render(target);
	}
	else if(settingsbb)
	{
		difficultyText.render(target);
		easyB.render(target);
		normalB.render(target);
		hardB.render(target);
		buttonBack.render(target);
	}
	
	
}
