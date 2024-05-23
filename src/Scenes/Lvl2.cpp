#include "Lvl2.hpp"

lvl2::lvl2(ScenePublicData* sceneData)
	: Scene(sceneData)
{

	switch (sceneData->gameState)
	{
	case WIN:
		gameStateGraph.setString(L"����������! ������ ;D");
		break;
	case LOSE:
		gameStateGraph.setString(L"��������� ��� :'(");
		break;
	case SECRET:
		gameStateGraph.setString(L"1 2 3 �������� ���������");
		break;
	}

	background.setPosition(0, 0);
	background.setFillColor(Color(255, 255, 255));

	font.loadFromFile("Resources/Edwardian.ttf");
	gameStateGraph.setPos(windowSize.width / 2, windowSize.height / 5);
	gameStateGraph.text.setOrigin(gameStateGraph.text.getGlobalBounds().width * 0.5, gameStateGraph.text.getGlobalBounds().height * 0.5);

	exitB.setOriginCenter();
	playAgainB.setOriginCenter();
}

lvl2::~lvl2()
{
}

void lvl2::updateSfmlEvents(Event event)
{
	exitB.update(mousePosView);
	exitB.ButtonBoxfunc(true, mousePosView, 5, Color::Black);
	playAgainB.ButtonBoxfunc(true, mousePosView, 5, Color::Black);

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (exitB.isPressed())
			Game::getInstance().endApp();

		if (playAgainB.isPressed())
			Game::getInstance().changeScene(0, sceneData);
	}
}

void lvl2::updateInput(const float& deltatime)
{
}

void lvl2::update(const float& deltaTime)
{
	updateInput(deltaTime);
	updateMousePosition();
}

void lvl2::render(RenderTarget* target, RenderStates* states)
{
	if (!target)
		target = window;

	target->draw(background);

	exitB.render(target);
	playAgainB.render(target);

	gameStateGraph.render(target);
}
