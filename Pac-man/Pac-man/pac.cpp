#include "pac.h"
#include<iostream>
#include<vector>
#include "maze.h"

using namespace std;
pac::pac(sf::RenderWindow& window)
{
	if (!pacman_pic.loadFromFile("pac_man.jpg"))
	{
		cout << "hello world";
	}
	pac_man.setTexture(&pacman_pic);
	pac_man.setRadius(15);
	pac_man.setPosition(sf::Vector2f(400, 670));
	window.draw(pac_man);
}

void pac::move(maze &maze)
{
    position = pac_man.getPosition();
	int y = position.x / 40;
	int x = position.y / 40 - 1;
	cout << x << " " << y << endl;
	cout << maze.maze_arr[x][y] << " **************** " << endl;
	cout << " //////////////////// " << pac_man.getPosition().x << "    " << pac_man.getPosition().y << endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		//pac_man.setRotation(180.f);
		if (pac_man.getPosition().x  )
		{
			if (maze.maze_arr[x][y - 1] != 2 || (pac_man.getPosition().x <= 79 && pac_man.getPosition().x >=45 ))
			{
				pac_man.move(-3.0f, 0.0f);
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
	//	pac_man.setRotation(0.f);
		if (maze.maze_arr[x][y+1] != 2)
			pac_man.move(3.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
	//	pac_man.setRotation(270.f);
		if (maze.maze_arr[x-1][y] != 2)
			pac_man.move(0.0f, -3.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
	//	pac_man.setRotation(90.f);
		if (maze.maze_arr[x+1][y] != 2)
			pac_man.move(0.0f, 3.f);
	}
}

