#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class gost
{
public:
	sf::Texture gt;
	sf::RectangleShape gs;
	int speed;
	bool vis[21][25] = { 0 };
	struct path
	{
		int x;
		int y;
		int brv;
	};
	struct npair
	{
		int x;
		int y;
	};
	vector<path>nodes;
	vector<npair>final_path;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	gost(sf::RenderWindow& window, string s, int x, int y, int spd);
	void move();
	void display();
	void BFS(int x_position, int y_position, int t_x, int t_y, int maze_arr[21][25]);

	///////////////////////////////////////
};