#include "Lvl2.h"

lvl2::lvl2(ScenePublicData* sceneData)
	: Scene(sceneData)
{

	switch (sceneData->gameState)
	{
	case WIN:
		state = "Поздравляю! Победа ;D";
	case LOSE:
		state = "Попытайся еще :'(";
	case SECRET:
		state = "1 2 3 проверка микрофона";
	}

	font.loadFromFile("Resources/Edwardian.ttf");
	gameStateGraph.setPos(windowSize.width / 2, windowSize.height / 1.1);
	gameStateGraph.text.setOrigin(gameStateGraph.text.getGlobalBounds().width * 0.5, gameStateGraph.text.getGlobalBounds().height * 0.5);
}

lvl2::~lvl2()
{
}

void lvl2::updateSfmlEvents(Event event)
{
}

void lvl2::updateInput(const float& deltatime)
{
}

void lvl2::update(const float& deltaTime)
{
}

void lvl2::render(RenderTarget* target, RenderStates* states)
{
}
