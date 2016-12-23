#include "WORLD.h"

//Блок функций класса World
void World::set(string Name)
{
	name = Name;
}
void World::set(int num)
{
	ppl = num;
}
void World::set(string Name, int num)
{
	name = Name;
	ppl = num;
}
void World::get()
{
	cout << "1)Имя - " << name << endl;
	cout << "2)Население - " << ppl << endl;
}

// Friend-функции
//Функции-предикаты
bool ComparisonL(pair<int, World> obj1, pair<int, World> obj2)
{
	if (obj1.second.ppl < obj2.second.ppl)
		return true;
	else
		return false;
}
bool ComparisonU(pair<int, World> obj1, pair<int, World> obj2)
{
	return (!(obj1.second.ppl > obj2.second.ppl));
}
bool IfPpl(pair<int, World> obj)
{
	if (obj.second.ppl < 50000)
		return false;
	else
		return true;
}
bool IfPplW(World obj)
{
	if (obj.ppl < 50000)
		return false;
	else
		return true;
}
bool IfCName(pair<int, World> obj)
{
	return (obj.second.name == "Венера");
}
bool IfCW(World obj)
{
	return (obj.ppl == 250000);
}
//Перегрузка операторов
ostream& operator<<(ostream& os, World obj)
{
	os << "\n\t1." << obj.name << "\n\t2." << obj.ppl << endl;
	return os;
}
bool operator==(World obj1, World obj2)
{
	return (obj1.name == obj2.name && obj1.ppl == obj2.ppl);
}
bool operator<(World obj1, World obj2)
{
	if (obj1.ppl < obj2.ppl)
		return true;
	else
		return false;
}

//Независимые функции
map<int, World> Srtng(map<int, World> obj, int How)
{
	//Создание нового контейнера
	map<int, World> New;
	//Перенос значений из старого контейнера в новый
	for (auto tt = obj.begin(); tt != obj.end(); ++tt)
		New.insert(pair<int, World>(tt->first, tt->second));
	//Алгоритм сортировки:
	// поочерёдное изменение значений в новом контейнере
	// начиная с первого на те же самые, но по убыванию
	for (int i = 1, k = 4; i <= 4; i++, k--) ///После нахождение максимального элемента уменьшаем область просмотра
	{										 /// т. е. не трогаем его k--
		auto it = obj.begin(); ///Каждый раз на начало
		if (How == 0)
		{
			for (int j = 1; j < k; j++) ///Нахождение максимального элемента
			if (it->second < obj.find(j + 1)->second)
				it = obj.find(j + 1); ///Сохранение максимального элемента
		}
		else
		{
			for (int j = 1; j < k; j++) ///Нахождение максимального элемента
			if (!(it->second < obj.find(j + 1)->second))
				it = obj.find(j + 1); ///Сохранение минимального элемента
		}
		New.at(i) = it->second; ///Добавление максимального элемента на i-ое место
	}
	return New;
}