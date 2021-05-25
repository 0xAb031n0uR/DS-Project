#include "our_button.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
our_button::our_button(string words, int posx,int posy,int sz, sf::RenderWindow& window)
{
	/*//font.loadFromFile("arial.ttf");
	//text.setFont(font);
	stringstream ss;
	Text scoretext;
	Font font;
	font.loadFromFile("FFF Tusj Bold.ttf");
	scoretext.setFont(font);
	ss << score;
	scoretext.setString(ss.str());
	scoretext.setFillColor(Color::Yellow);
	scoretext.setCharacterSize(36);
	scoretext.setPosition(160, 900);
	window.draw(scoretext);

	current = 1;
	rect.setSize(sf::Vector2f(posx, posy));
	rect.setPosition(posx, posy);
	rect.setFillColor(sf::Color::Green);*/

}
void our_button::checkClick(int x, int y) {
		
	if (x >rect.getPosition().x   &&  x < rect.getPosition().x + rect.getSize().x) {
		if (y > rect.getPosition().y   &&  y< rect.getPosition().y+ rect.getSize().y) {
			setState(!current);
		}
	}
}
void our_button::setState(bool which) {
	current = which;
	cout << "gonna kill me self" << endl;
	if ( current) {
		window.draw(rect);
		window.draw(text);
	}
	else
	{
		window.draw(text);
	}
}

