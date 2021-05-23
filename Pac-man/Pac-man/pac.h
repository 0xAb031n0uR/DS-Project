#include<SFML/Graphics.hpp>
#include<iostream>
#include"maze.h"
class pac
{
public:
	sf::Texture pacman_pic;
	sf::CircleShape pac_man;
	sf::Sprite sprite;
	pac(sf::RenderWindow& window);
	sf::Vector2f position;
	int posx, posy;
	int dirction = 0;
	void move(maze& maze);
	void action(maze& maze);
};