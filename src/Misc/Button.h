#pragma once

#include "Sprite2.h"
#include "Text2.h"

using namespace sf;

enum Button_states
{
	BTN_IDLE = 0,
	BTN_HOVER = 1,
	BTN_ACTIVE = 2,
};

class Button
{
	short unsigned ButtonState;
	float width, height;
	bool ButtonBoxAct = false;
	//
	Font font;
	
	RectangleShape ButtonBox;

	Color idleColor;
	Color hoverColor;
	Color activeColor;

	void ButtonSetup(float x, float y, float width, float height, String text, Color idleColor, Color hoverColor, Color activeColor);
	void setColorB(Color color);

public:
	Button() = default;
	Button(float x, float y, float width, float height,
		String text, Texture* image,
		Color idleColor, Color hoverColor, Color activeColor);

	Button(float x, float y, float width, float height,
		String text, std::string image,
		Color idleColor, Color hoverColor, Color activeColor);

	~Button();

	void setFont(Font* b_font);

	Text ButtonT;
	Texture texture;
	Sprite ButtonS;
	//Sprite ButtonS;
	//Texture texture;
	const bool isPressed()const;
	void unPress();
	bool isHover();

	void ButtonBoxfunc(bool act, Vector2f mousePos, int thick = 0, Color color = Color::Transparent);
	void setOriginCenter();

	void updateEvented(Vector2f mousePos, Event event, bool fullColor = false);
	void update(Vector2f mousePos, bool fullColor = false);
	void render(RenderTarget* target);
};

