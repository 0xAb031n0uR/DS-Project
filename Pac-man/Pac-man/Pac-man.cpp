#include <SFML/Graphics.hpp>
#include<iostream>
#include"maze.h"
#include "pac.h"
using namespace sf;
int main()
{
	RenderWindow window(sf::VideoMode(843, 900), "PAC-MAN");
	CircleShape shape;
	pac p(window);
	shape.setRadius(50);
	maze maz;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed :
				window.close();
			case sf::Event::MouseMoved :
				std::cout << event.mouseMove.x << " " << event.mouseMove.y << std::endl;
 			default:
				break;
			} 
		}
		
		p.move(maz);
		window.clear();
		maz.display(window);
		window.draw(p.pac_man);
		window.display();
	}

	return 0;
}