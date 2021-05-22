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
	pac_man.setPosition(sf::Vector2f(10*40, (15*40)+70));
	window.draw(pac_man);
}
void pac::move(maze &maze)
{
	position = pac_man.getPosition();
	int y = (position.y-70) / 40;
	int x = position.x/ 40 ;
	posx = position.x;
	posy = position.y-70;
	cout << "X now = " << x << "  Y now = " << y << "       ----> " << " pac-man X now = " << pac_man.getPosition().x << "    " << " pac-man Y now = " << pac_man.getPosition().y << "    ---->   number in maze = " << maze.maze_arr[int((posy) / 40)][int((posx-1) / 40)] << endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		   //pac_man.setRotation(180.f);
		   //  y=15 , x=10 pac-man pos...?
			
		if (maze.maze_arr[int(posy/40)][int((posx-1)/40)] != 2 )
		{
				pac_man.move(-1.0f, 0.0f);
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
	//	pac_man.setRotation(0.f);
		if (maze.maze_arr[int(posy / 40)][int((posx + 1) / 40)] != 2)
			pac_man.move(1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
	//	pac_man.setRotation(270.f);
		if (maze.maze_arr[int((posy-1) / 40)][int((posx) / 40)] != 2)
			pac_man.move(0.0f, -1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
	//	pac_man.setRotation(90.f);
		if (maze.maze_arr[int((posy + 41) / 40)][int((posx) / 40)] != 2)
			pac_man.move(0.0f, 1.f);
	}
}
