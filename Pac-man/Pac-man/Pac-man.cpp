#include <SFML/Graphics.hpp>
#include<iostream>
#include"maze.h"
#include "pac.h"
#include "gost.h"
using namespace sf;
RenderWindow window(sf::VideoMode(843, 900), "PAC-MAN");
pac p(window);
CircleShape shape;
string s1 = "g1.jpeg", s2 = "g2.jpeg", s3 = "g3.jpeg", s4 = "g4.jpeg";
gost g1(window, s1, 8, 9),
g2(window, s2, 9, 9),
g3(window, s3, 11, 9),
g4(window, s4, 12, 9);
maze maz;
void move(gost &g) {
	Vector2f gpos = g.gs.getPosition();

	g.BFS(9, 8, 1, 19, maz.maze_arr);
//	cout << gpos.x / 40 << " " << (gpos.y - 70) / 40 << " " << p.x << " " << p.y << endl;
	for (int i = 0; i < g.final_path.size(); i++)
	{
		cout << g.final_path[i].x << " " << g.final_path[i].y << endl;
	}
	cout << endl << endl;
	if (g.final_path.size() == 0) {
		return;
	}
	int n = g.final_path.size();

	g.gs.setPosition(sf::Vector2f(g.final_path[n - 1].x * 40 + 13, (g.final_path[n - 1].y * 40) + 70));
	g.final_path.pop_back();
}

int main()
{
	int frame = 0;
	shape.setRadius(50);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
			case sf::Event::MouseMoved:

			default:
				break;
			}
		}

		p.move(maz);
		frame++;
		if (frame == 200) {
			frame = 0;
			move(g1);
		}


		window.clear();
		maz.display(window);

		window.draw(p.pac_man);
		window.draw(g1.gs);
		// window.draw(g2.gs);
		 //window.draw(g3.gs);
		// window.draw(g4.gs);

		window.display();
	}

	return 0;
}