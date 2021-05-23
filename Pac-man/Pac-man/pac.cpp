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
	pac_man.setPosition(sf::Vector2f(10 * 40 + 13, (15 * 40) + 70));
	window.draw(pac_man);
}
void pac::move(maze& maze)
{
	position = pac_man.getPosition();
	int y = (position.y - 60) / 40;
	int x = (position.x +19) / 40;
	cout << x << " ************ " << y << endl;
	posx = position.x;
	posy = position.y;
	action(maze);

	if (dirction == 0) // done
	{

		if (maze.maze_arr[int((posy - 40) / 40)][int((posx - 11) / 40)] != 2 && maze.maze_arr[int((posy - 62) / 40)][int((posx - 11) / 40)] != 2)
		{
			if (x == 0 && y == 9)
			{
				pac_man.setPosition(sf::Vector2f(20 * 40 + 5, (9 * 40) + 70));
			}
			pac_man.move(-1.0f, 0.0f);
			if (maze.maze_arr[y][x] == 4)
			{
				maze.maze_arr[y][x] = 6;
			}
			if (maze.maze_arr[y][x] == 5)
			{
				maze.maze_arr[y][x] = 6;
			}
		}
	}
	if (dirction == 1) // done
	{
		if (maze.maze_arr[int((posy - 40) / 40)][int((posx + 35) / 40)] != 2 && maze.maze_arr[int((posy - 62) / 40)][int((posx + 35) / 40)] != 2)
		{
			if (x == 20 && y == 9)
			{
				pac_man.setPosition(sf::Vector2f(0 * 40 + 5, (9 * 40) + 70));
			}
			pac_man.move(1.0f, 0.0f);
			if (maze.maze_arr[y][x] == 4)
			{
				maze.maze_arr[y][x] = 6;
			}
			if (maze.maze_arr[y][x] == 5)
			{
				maze.maze_arr[y][x] = 6;
			}
		
		}

	}
	if (dirction == 2) // DONE
	{

		if (maze.maze_arr[int((posy - 70) / 40)][int((posx - 4) / 40)] != 2 && maze.maze_arr[int((posy - 70) / 40)][int((posx + 25) / 40)] != 2)
		{
			pac_man.move(0.0f, -1.0f);
			if (maze.maze_arr[y][x] == 4)
			{
				maze.maze_arr[y][x] = 6;
			}
			if (maze.maze_arr[y][x] == 5)
			{
				maze.maze_arr[y][x] = 6;
			}
		}

	}
	if (dirction == 3)
	{
		if (maze.maze_arr[int((posy - 30) / 40)][int((posx + 25) / 40)] != 2 && maze.maze_arr[int((posy - 30) / 40)][int((posx - 4) / 40)] != 2)
		{
			pac_man.move(0.0f, 1.f);
			if (maze.maze_arr[y][x] == 4)
			{
				maze.maze_arr[y][x] = 6;
			}
			if (maze.maze_arr[y][x] == 5)
			{
				maze.maze_arr[y][x] = 6;
			}
		}
	}


}

void pac::action(maze &maze)
{
	position = pac_man.getPosition();
	posx = position.x;
	posy = position.y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (maze.maze_arr[int((posy - 40) / 40)][int((posx - 11) / 40)] != 2 && maze.maze_arr[int((posy - 60) / 40)][int((posx - 11) / 40)] != 2)
			dirction = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (maze.maze_arr[int((posy - 40) / 40)][int((posx + 35) / 40)] != 2 && maze.maze_arr[int((posy - 62) / 40)][int((posx + 35) / 40)] != 2)
			dirction = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (maze.maze_arr[int((posy - 70) / 40)][int((posx - 4) / 40)] != 2 && maze.maze_arr[int((posy - 70) / 40)][int((posx + 25) / 40)] != 2)
			dirction = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		if (maze.maze_arr[int((posy - 30) / 40)][int((posx + 25) / 40)] != 2 && maze.maze_arr[int((posy - 30) / 40)][int((posx - 4) / 40)] != 2)
			dirction = 3;
	}

}