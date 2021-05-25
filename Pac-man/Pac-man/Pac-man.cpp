#include <SFML/Graphics.hpp>
#include<iostream>
#include"maze.h"
#include "pac.h"
#include "gost.h"
#include "our_button.h"
using namespace sf;
sf::RenderWindow window(sf::VideoMode(1050, 960, 32), "pacman");
pac p(window);
string s1 = "g1.jpeg", s2 = "g2.jpeg", s3 = "g3.jpeg", s4 = "g4.jpeg";
gost g1(window, s1, 42 * 9, 9 * 42, 2),
g2(window, s2, 42 * 10, 9 * 42, 2),
g3(window, s3, 42 * 14, 9 * 42, 2),
g4(window, s4, 42 * 15, 9 * 42, 1);
maze maz;

void move(gost& g, int tx, int ty) {
	Vector2f gpos = g.gs.getPosition();
	g.BFS(gpos.y / 42, gpos.x / 42, ty, tx, maz.maze_arr);

	int n = g.final_path.size();
	if (n > 0)
	{
		int a = g.final_path[n - 1].x * 42,
			b = g.final_path[n - 1].y * 42;
		g.gs.setPosition(Vector2f(b, a));
		gpos = g.gs.getPosition();


		g.final_path.pop_back();
	}
}
void randmize_pos(int& x, int& y, int modx, int mody, bool placex, bool placey)
{
	do
	{
		x = (rand() % modx) + (placex * 10);
		y = (rand() % mody) + ((placey) * 10);
	} while (maz.maze_arr[x][y] == 2);
}
void inti() {
	
	pac p(window);
	string s1 = "g1.jpeg", s2 = "g2.jpeg", s3 = "g3.jpeg", s4 = "g4.jpeg";
	gost g1(window, s1, 42 * 9, 9 * 42, 2),
		g2(window, s2, 42 * 10, 9 * 42, 2),
		g3(window, s3, 42 * 14, 9 * 42, 2),
		g4(window, s4, 42 * 15, 9 * 42, 1);
	maze maz;


}
int main()
{
	bool menu = 0, game = 1;
	int frame = 0;
	int frame2 = 0;
	int frame3 = 0;
	int frame4 = 0;




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
		if (menu) {
			our_button B("Play",30,30,20,window);
			window.clear();
			if(Event::MouseMoved)
			B.checkClick(event.mouseMove.x, event.mouseMove.y);
			window.display();
		}
		
		if (game) {
			p.move(maz);
			frame++;
			frame2++;
			frame3++;
			frame4++;

			if (frame == 100 / g1.speed) {
				frame = 0;
				Vector2f gpos = g1.gs.getPosition();
				move(g1, p.x, p.y);

			}
			if (frame2 == 100 / g2.speed) {
				frame2 = 0;
				int x, y;
				randmize_pos(x, y, 12, 10, 1, 0);
				move(g2, x, y);
			}
			if (frame3 == 100 / g3.speed) {
				frame3 = 0;

				int x, y;
				randmize_pos(x, y, 12, 10, 0, 1);
				move(g3, x, y);


			}
			if (frame4 == 100 / g4.speed) {
				frame4 = 0;
				int x, y;
				randmize_pos(x, y, 12, 10, 0, 0);
				move(g4, p.x, p.y);

			}



			window.clear();
			maz.display(window);
			window.draw(p.pac_man);
			window.draw(g1.gs);
			window.draw(g2.gs);
			window.draw(g3.gs);
			window.draw(g4.gs);

			window.display();
		}
	}

	return 0;
}