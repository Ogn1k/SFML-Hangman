#include "Button.hpp"


Button::Button(float x, float y, float width, float height,
	String text, Texture* image,
	Color idleColor, Color hoverColor, Color activeColor)
{
	ButtonS.setTexture(*image);
	ButtonS.setPosition(x, y);

	texture = *image;

	//ButtonT.setString(text);

	ButtonSetup(x, y, width, height, text, idleColor, hoverColor, activeColor);
}

Button::Button(float x, float y, float width, float height,
	String text, std::string image,
	Color idleColor, Color hoverColor, Color activeColor)
{
	if (image == "")
	{

	}
	else if (!texture.loadFromFile(image))
		texture.loadFromFile("Resources/Textures/missing.png");
	ButtonS.setTexture(texture);

	ButtonSetup(x, y, width, height, text, idleColor, hoverColor, activeColor);
}



Button::~Button()
{

}

void Button::setFont(Font* b_font)
{
	ButtonT.setFont(*b_font);
}

void Button::ButtonSetup(float x, float y, float width, float height, String text, Color idleColor, Color hoverColor, Color activeColor)
{
	ButtonState = BTN_IDLE;

	ButtonS.setPosition(x, y);
	ButtonS.setScale(width / ButtonS.getGlobalBounds().width, height / ButtonS.getGlobalBounds().height);

	font.loadFromFile("Resources/Edwardian.ttf");
	ButtonT.setFont(font);
	ButtonT.setString(text);
	ButtonT.setFillColor(Color::Black);
	ButtonT.setPosition(x, y - 8);
	ButtonT.setCharacterSize(28);

	ButtonBox = RectangleShape(Vector2f(width, height));
	ButtonBox.setPosition(x, y);

	this->activeColor = activeColor;
	this->hoverColor = hoverColor;
	this->idleColor = idleColor;
}

void Button::unPress()
{
	ButtonState = BTN_IDLE;
}

bool Button::isHover()
{
	if (ButtonState == BTN_HOVER)
		return true;
	return false;
}

const bool Button::isPressed() const
{
	if (ButtonState == BTN_ACTIVE)
		return true;
	return false;
}

void Button::setColorB(Color color)
{
	Image image = texture.copyToImage();
	auto const sz = image.getSize();
	for (std::size_t y = 0; y < sz.y; ++y) {
		for (std::size_t x = 0; x < sz.x; ++x) {
			Color pixel = image.getPixel(x, y);
			pixel.r = 255;
			pixel.g = 255;
			pixel.b = 255;
			image.setPixel(x, y, pixel);
		}
	}
	texture.loadFromImage(image);
	ButtonS.setColor(color);
}

void Button::ButtonBoxfunc(bool act, Vector2f mousePos, int thick, Color color)
{
	ButtonBoxAct = act;
	if (ButtonBoxAct)
	{
		//std::cout << "asd" << std::endl;
		ButtonBox.setOutlineColor(color);
		ButtonBox.setOutlineThickness(thick);
		ButtonState = BTN_IDLE;
		if (ButtonBox.getGlobalBounds().contains(mousePos))
		{
			ButtonState = BTN_HOVER;
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				ButtonState = BTN_ACTIVE;
			}
		}
		if (ButtonState == BTN_IDLE)
			ButtonBox.setFillColor(idleColor);
		else if (ButtonState == BTN_HOVER)
			ButtonBox.setFillColor(hoverColor);
		else if (ButtonState == BTN_ACTIVE)
			ButtonBox.setFillColor(activeColor);

	}
}

void Button::setOriginCenter()
{
	ButtonT.setOrigin(Vector2f(ButtonT.getGlobalBounds().width * 0.5, ButtonT.getGlobalBounds().height * 0.5));
	ButtonBox.setOrigin(Vector2f(ButtonBox.getSize().x * 0.5, ButtonBox.getSize().y * 0.5));
	ButtonS.setOrigin(Vector2f(ButtonBox.getSize().x * 0.5, ButtonBox.getSize().y * 0.5));
}


void Button::updateEvented(Vector2f mousePos, Event event, bool fullColor)
{
	ButtonState = BTN_IDLE;
	if (ButtonS.getGlobalBounds().contains(mousePos))
	{
		ButtonState = BTN_HOVER;
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			ButtonState = BTN_ACTIVE;
		}
	}
	if (fullColor)
	{
		if (ButtonState == BTN_IDLE)
			setColorB(idleColor);
		else if (ButtonState == BTN_HOVER)
			setColorB(hoverColor);
		else if (ButtonState == BTN_ACTIVE)
			setColorB(activeColor);
	}
	else
	{
		if (ButtonState == BTN_IDLE)
			ButtonS.setColor(idleColor);
		else if (ButtonState == BTN_HOVER)
			ButtonS.setColor(hoverColor);
		else if (ButtonState == BTN_ACTIVE)
			ButtonS.setColor(activeColor);
	}

}

void Button::update(Vector2f mousePos, bool fullColor)
{
	ButtonState = BTN_IDLE;
	if (ButtonS.getGlobalBounds().contains(mousePos))
	{
		ButtonState = BTN_HOVER;
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			ButtonState = BTN_ACTIVE;
		}
	}
	if (fullColor)
	{
		if (ButtonState == BTN_IDLE)
			setColorB(idleColor);
		else if (ButtonState == BTN_HOVER)
			setColorB(hoverColor);
		else if (ButtonState == BTN_ACTIVE)
			setColorB(activeColor);
	}
	else
	{
		if (ButtonState == BTN_IDLE)
			ButtonS.setColor(idleColor);
		else if (ButtonState == BTN_HOVER)
			ButtonS.setColor(hoverColor);
		else if (ButtonState == BTN_ACTIVE)
			ButtonS.setColor(activeColor);
	}
}

void Button::render(RenderTarget* target)
{

	if (ButtonBoxAct)
		target->draw(ButtonBox);
	target->draw(ButtonS);
	target->draw(ButtonT);
}
