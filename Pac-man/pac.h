#include<SFML/Graphics.hpp>
#include<iostream>
#include"maze.h"
class pac
{
public:
	sf::Texture pacman_pic;
	sf::CircleShape pac_man;
	pac(sf::RenderWindow& window);
	sf::Vector2f position;
	int score = 0, speed = 2;
	int  x, y;
	int dirction = 0;
	int level_number = 1;
	void move(maze& maze);

	void action(maze& maze);
};
