#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
class our_button
{
public:
	sf::Font font;
	sf::Text text;
	sf::RectangleShape rect;
	sf::RenderWindow window;
	our_button(string words, int posx, int posy, int sz, sf::RenderWindow& window);
	void checkClick(int x,int y);
	void setState(bool);
	void setText(std::string);
	bool getVar();
	

	
	sf::String String;
	bool current;
};





