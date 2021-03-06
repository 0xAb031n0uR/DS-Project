#include "maze.h"
#include<iostream>
using namespace std;
maze::maze()
{

	dot.setRadius(4 / level_number);

	//pac_dots
	pac_dot.setRadius(12 / level_number);


	//wall designe
	wall.setSize(sf::Vector2f(32 / (level_number), 32 / (level_number)));
	wall.setFillColor(Color(0, 0, 0));
	wall.setOutlineThickness(5 / (level_number));
	wall.setOutlineColor(Color(30, 85, 225));

	//dot designe
	dot.setFillColor(Color(242, 221, 49));

	//pac_dot design
	pac_dot.setFillColor(Color(242, 221, 49));
}
void maze::display(RenderWindow& window)
{

	for (int j = 0; j < 25 * level_number; j++)
	{
		for (int i = 0; i < 21 * level_number; i++)
		{
			if (maze_arr[i][j] == 0)
			{
				dot.setPosition(j * (42 / level_number) + (10 / level_number), i * (42 / level_number) + (10 / level_number));
				window.draw(dot);

			}
			else if (maze_arr[i][j] == 1)
			{
				wall.setPosition(j * (42 / level_number), i * (42 / level_number));
				window.draw(wall);

			}
			else if (maze_arr[i][j] == 4)
			{
				pac_dot.setPosition(j * (42 / level_number) + (5 / level_number), i * (42 / level_number) + (5 / level_number));
				window.draw(pac_dot);

			}

		}

	}
}
