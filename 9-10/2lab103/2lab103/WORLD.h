#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <functional>
#include <set>
#include <iterator>
#include <list>

using namespace std;

class World
{
private:
	string name;
	int ppl;
public:
	~World()
	{
		name = "Не определён";
		ppl = NULL;
	}
	World() : name("Не определён"), ppl(NULL)
	{}
	World(string Name, int num) : ppl(num), name(Name)
	{}
	void set(string Name);
	void set(int num);
	void set(string Name, int num);
	void get();
	//Перегрузка операторов
	friend ostream& operator<<(ostream& os, World obj);
	friend bool operator==(World obj1, World obj2);
	friend bool operator<(World obj1, World obj2);
	//Функции-предикаты
	friend bool ComparisonL(pair<int, World> obj1, pair<int, World> obj2);
	friend bool ComparisonU(pair<int, World> obj1, pair<int, World> obj2);
	friend bool IfPpl(pair<int, World> obj);
	friend bool IfPplW(World obj);
	friend bool IfCName(pair<int, World> obj);
	friend bool IfCW(World obj);
};

//Независимые функции
map<int, World> Srtng(map<int, World> obj, int How);

//Функторы
struct Func1
{
	int operator()(list<int> &obj)
	{
		int k = 0;
		for (auto it : obj)
		{
			if (it > 5)
				k++;
		}
		return k;
	}
};

struct Func2
{
	int operator()(list<int> &obj, int l)
	{
		int k = 0;
		for (auto it : obj)
		{
			if (it < l)
				k++;
		}
		return k;
	}
};