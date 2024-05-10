#pragma once
#include "Scenes/Lvl1.h"

class lvl2 : public Scene
{
protected:

	VideoMode windowSize = sceneData->windowSize;

	Font font;
	sf::String state;
	Text2 gameStateGraph = Text2(state, 56, Color::Black);

	RectangleShape background = RectangleShape(Vector2f(windowSize.width, windowSize.height));

public:
	lvl2(ScenePublicData* sceneData);
	virtual ~lvl2();

	void updateSfmlEvents(Event event);
	void updateInput(const float& deltatime);
	void update(const float& deltaTime);
	void render(RenderTarget* target = nullptr, RenderStates* states = nullptr);

};

