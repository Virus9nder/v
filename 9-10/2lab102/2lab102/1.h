#pragma once
#pragma once
#include<iostream> 
#include <conio.h>
class World
{
public:
	int nas;
public:
	World()
	{
		nas = 0;
	}
	World(int d)
	{
		nas = d;
	}
	void setnas(int d)
	{
		nas = d;
	}
	int getnas()
	{
		return nas;
	}
	friend void operator >> (std::istream& input, World& a)
	{
		input >> a.nas;
	}
	friend std::ostream& operator << (std::ostream& out, World& a)
	{
		out << a.nas;
		return out;
	}

};