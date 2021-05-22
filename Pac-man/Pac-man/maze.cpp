#include "maze.h"
#include<iostream>
using namespace std;
maze::maze()
{
	block.setSize(Vector2f(30.0f, 30.0f));
	block.setFillColor(Color::Black);
	block.setOutlineThickness(3.f);
	block.setOutlineColor(Color(30, 85, 225));
	smal_dot.setRadius(4);
	big_dot.setRadius(11);
	smal_dot.setFillColor(Color(242, 221, 49));
	big_dot.setFillColor(Color(242, 221, 49));


}
void maze::display(RenderWindow& window)
{

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (maze_arr[i][j] == 1)
			{
				//cout << i << "  ***********  " << j << endl;
			}
			else if (maze_arr[i][j] == 2)
			{
				//if (i == 18)cout <<"# care ! " <<(40 * i) +70 << endl;
				block.setPosition(j * 40 + 6, 70 + i * 40);
				window.draw(block);
			}
			else if (maze_arr[i][j] == 3)
			{
				
			}
			else if (maze_arr[i][j] == 4)
			{
				smal_dot.setPosition(13 + j * 40, 80 + i * 40);
				window.draw(smal_dot);
			}
			else if (maze_arr[i][j] == 5)
			{
				big_dot.setPosition(8 + j * 40, 75 + i * 40);
				window.draw(big_dot);
			}



		}
	}
}
