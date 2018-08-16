// Game.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>



sf::Sprite loadSprite(std::string filename)
{
	sf::Texture texture;
	texture.loadFromFile(filename);

	return sf::Sprite(texture);
}
int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default, settings);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::CircleShape triangle(80,3);

	sf::Time t1 = sf::microseconds(100000);
	sf::Time t2 = sf::microseconds(100001);
	sf::Time t3 = t1 - t2;
	sf::Texture texture;
	if (!texture.loadFromFile("src/adventurer_hurt.png"))
	{
		std::cout << "dont load texture";
	}
	
	//texture.setSmooth(true);
	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	///////////////////////////////////
	sf::Font ui_font;
	ui_font.loadFromFile("SegoeUI/SegoeUI.ttf");
	///////////////////////////////////
	sf::Text text;
	text.setFont(ui_font);
	text.setString("Hello world");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Underlined);
	///////////////////////////////////
	sf::CircleShape shape2(50);
	
	shape2.setOutlineThickness(10);
	shape2.setOutlineColor(sf::Color(250, 150, 100));
	sf::Texture wood;
	wood.loadFromFile("src/wood.jpg");
	shape2.setTexture(&wood);
	while (window.isOpen())
	{
		
		sf::Event event1;	

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			std::cout << "left arrow"<<std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			std::cout << "right arrow" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			std::cout << "up arrow" << std::endl;
		}

		while (window.pollEvent(event1))
		{
			if (event1.type == sf::Event::MouseMoved)
			{
				std::cout << "new mouse x: " << event1.mouseMove.x << std::endl;
				std::cout << "new mouse y: " << event1.mouseMove.y << std::endl;
			}
			if (event1.type == sf::Event::MouseWheelScrolled)
			{
				if (event1.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
					std::cout << "wheel type: vertical" << std::endl;
				else if (event1.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
					std::cout << "wheel type: horizontal" << std::endl;
				else
					std::cout << "wheel type: unknown" << std::endl;
				std::cout << "wheel movement: " << event1.mouseWheelScroll.delta << std::endl;
				std::cout << "mouse x: " << event1.mouseWheelScroll.x << std::endl;
				std::cout << "mouse y: " << event1.mouseWheelScroll.y << std::endl;
			}
			if (event1.type == sf::Event::MouseEntered)
				std::cout << "the mouse cursor has entered the window" << std::endl;

			if (event1.type == sf::Event::MouseLeft)
				std::cout << "the mouse cursor has left the window" << std::endl;

			if(event1.type==sf::Event::Closed)
			{
				window.close();
			}
			if(event1.type==sf::Event::TextEntered)
			{
				std::cout << (char)event1.text.unicode;
			}	
			
			if(event1.type== sf::Event::Resized)
			{
				std::cout << event1.size.width << ' ' << event1.size.height<<std::endl;
			}
		}

		window.clear(sf::Color::Black);
		//window.draw(shape);
		
		window.draw(sprite);
		window.draw(text);
		window.draw(shape2);
		//sprite.move(1, 0);
		window.display();
	}

	return 0;
}

