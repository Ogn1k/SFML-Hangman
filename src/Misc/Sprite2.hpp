#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Sprite2
{
protected:
	Image image;
	Texture texture;
	IntRect box;
	RectangleShape debugBox;
	float scaleX = 1, scaleY = 1;
	bool active = true;
public:
	Sprite sprite;
	Sprite2() = default;
	Sprite2(Texture* patch, int x, int y)
	{
		sprite.setTexture(*patch);
		sprite.setPosition(x, y);

		box = IntRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getTextureRect().width, sprite.getTextureRect().height);

	}
	Sprite2(std::string patch, int x, int y)
	{

		if (patch == "")
		{

		}
		else if (!image.loadFromFile(patch))
			image.loadFromFile("Resources/Textures/missing.png");


		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(x, y);

		box = IntRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getTextureRect().width, sprite.getTextureRect().height);



	}
	void SetTexture(Texture* patch)
	{
		sprite.setTexture(*patch);
		box = IntRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getTextureRect().width, sprite.getTextureRect().height);
	}
	Texture getTexture()
	{
		return texture;
	}
	Vector2f getPosition()
	{
		return sprite.getPosition();
	}
	IntRect getRect()
	{
		box = IntRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getTextureRect().width * scaleX, sprite.getTextureRect().height * scaleY);
		return box;
	}
	void setColor(Color color)
	{
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
		sprite.setColor(color);
	}
	void setColorSimple(Color color)
	{
		sprite.setColor(color);
	}
	//void setOrigin(float x, float y)
	//{
	//	originX = x; originY = y;
	//	sprite.setOrigin(Vector2f(x, y));
	//}
	void setScale(float width, float height)
	{
		scaleX = width; scaleY = height;
		sprite.setScale(Vector2f(width, height));
	}
	RectangleShape renderDebug()
	{
		debugBox.setPosition(Vector2f(sprite.getPosition().x, sprite.getPosition().y));
		debugBox.setSize(Vector2f(box.width, box.height));

		return debugBox;
	}
	void setActive(bool act)
	{
		act = active;
	}

	virtual void update(const float& deltatime)
	{
	}
	virtual void render(RenderTarget* target)
	{
		//target->draw(renderDebug());
		if (active)
			target->draw(sprite);
	}
};

