#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;
/*
1 pac-man
2 block
3 gost
4 point
5 big point
6 space
7 gost cant move

*/
class maze
{
public:

	RectangleShape block;
	CircleShape smal_dot;
	CircleShape big_dot;

	int maze_arr[21][23] =
	{
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},// 0
	{2,4,4,4,4,4,4,4,4,4,2,4,4,4,4,4,4,4,4,4,2},// 1 
	{2,5,2,2,4,2,2,2,2,4,2,4,2,2,2,2,4,2,2,5,2},// 2 
	{2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,2},// 3 
	{2,4,2,2,4,2,4,2,2,2,2,2,2,2,4,2,4,2,2,4,2},// 4 
	{2,4,4,4,4,2,4,4,4,4,2,4,4,4,4,2,4,4,4,4,2},// 5
	{2,2,2,2,4,2,2,2,2,4,2,4,2,2,2,2,4,2,2,2,2},// 6
	{6,6,6,2,4,2,4,4,4,4,4,4,4,4,4,2,4,2,6,6,6},// 7 
	{2,2,2,2,4,2,4,2,2,2,6,2,2,2,4,2,4,2,2,2,2},// 8
	{7,7,7,7,4,4,4,2,3,3,6,3,3,2,4,4,4,7,7,7,7},// 9
	{2,2,2,2,4,2,4,2,2,2,2,2,2,2,4,2,4,2,2,2,2},// 10
	{6,6,6,2,4,2,4,4,4,4,4,4,4,4,4,2,4,2,6,6,6},// 11
	{2,2,2,2,4,2,2,2,2,4,2,4,2,2,2,2,4,2,2,2,2},// 12
	{2,4,4,4,4,2,4,4,4,4,2,4,4,4,4,2,4,4,4,4,2},// 13
	{2,4,2,2,4,2,4,2,2,2,2,2,2,2,4,2,4,2,2,4,2},// 14
	{2,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,2},// 15
	{2,5,2,2,4,2,2,2,2,4,2,4,2,2,2,2,4,2,2,5,2},// 16
	{2,4,4,4,4,4,4,4,4,4,2,4,4,4,4,4,4,4,4,4,2},// 17
 	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2} // 18
	};
	maze();
	void display(RenderWindow& window);

};

