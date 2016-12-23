#include <Windows.h>
#include "WORLD.h"

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Создание и инициализация объектов пользовательского типа
	World obj1("Марс", 600), obj2("Юпитер", 5000), obj3("Венера", 250000), obj4("Земля", 7000000);
	//Создание контейнера map F
	map<int, World> F;
	//Заполнение F
	F.insert(pair<int, World>(1, obj1));
	F.insert(pair<int, World>(2, obj2));
	F.insert(pair<int, World>(3, obj3));
	F.insert(pair<int, World>(4, obj4));
	cout << "F до сортировки" << endl;
	for (auto it = F.begin(); it != F.end(); ++it)
		cout << it->first << " : " << it->second << endl;
	F = Srtng(F, 0); //Сортировка по убыванию (0-по убыванию, 1-по возрастанию)
	cout << "F после сортировки" << endl;
	for (auto it = F.begin(); it != F.end(); ++it)
		cout << it->first << " : " << it->second << endl;
	//Поиск элемента по условию
	auto ftemp = find_if(F.rbegin(), F.rend(), IfCName);
	cout << "Элемент, соответствующий условию World::name == \"Венера\":" << endl;
	cout << ftemp->first << " : " << ftemp->second << endl;
	//lower_bound, upper_bound
	/*pair<int, World> bound(3, obj3);
	auto p1 = lower_bound(F.begin(), F.end(), bound, ComparisonL);
	auto p2 = upper_bound(F.begin(), F.end(), bound, ComparisonU);
	cout << "Поиск с применением lower_bound" << p1->first << " : " << p1->second << endl;
	cout << "Поиск с применением upper_bound" << p2->first << " : " << p2->second << endl;*/

	//Создание контейнера Set S и его заполнение согласно условию World::ppl > 50 000
	set<World> S;
	for (auto it = F.begin(); it != F.end(); ++it)
	{
		if (IfPpl(*it))
			S.insert(it->second);
	}
	cout << "Вывод элементов множества S на экран:" << endl;
	copy(S.begin(), S.end(), ostream_iterator<World>(cout, "\n"));

	//Сортировка F и S по возрастанию
	F = Srtng(F, 1);
	cout << "Вывод элементов F после портировки по возрастанию:" << endl;
	for (auto it = F.begin(); it != F.end(); ++it)
		cout << it->first << " : " << it->second << endl;
	//S уже отсортирована

	//Создание 3-его контейнера и заполнение путём слияния первых двух
	list<World> L;
	auto it1 = F.begin(); auto it2 = S.begin();
	for (int i = 0; i < F.size() + S.size(); i++)
	{
		if (it1 != F.end())
		{
			L.push_back(it1->second);
			++it1;
		}
		if (it2 != S.end())
		{
			L.push_back(*it2);
			++it2;
		}
	}
	cout << "Вывод элементов списка L на экран:" << endl;
	copy(L.begin(), L.end(), ostream_iterator<World>(cout, "\n"));

	//Вывод кол-ва элементов по заданному условию
	int c = count_if(L.begin(), L.end(), IfPplW);
	cout << "Кол-во элементов в L, удовлетворяющих World::ppl > 50 000: " << c << endl;
	cout << "\nПроверка на наличие элемента в L согласно условию: World::ppl == 250 000:" << endl;
	if (any_of(L.begin(), L.end(), IfCW))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	cout << endl;
	//string
	cout << "Демонстрация работы string:" << endl;
	string s1;
	string s2("text");
	string s3(s2);
	string s4 = s3;
	cout << "2)" << s2 << " - Default\n3)" << s3 << " - Copy\n4)" << s4 << " - Move" << endl; // Конструкторы: обычный, копирования, перемещения
	cout << "string.substr(0,2): " << s2.substr(0, 2) << endl; //Вывод подстроки
	s3.append(4, 'e'); //Добавление в конец элемента
	cout << "string.append(4,\'e\'): " << s3 << endl;
	s4.erase(1, 2);
	cout << "string.erase(1,2): " << s4 << endl; //Удаление со 2-го по 3-ий
	cout << endl;
	//Функторы
	cout << "Демонстрация работы функторов:" << endl;
	Func1 f1;
	Func2 f2;
	list<int> obj = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto itf = bind(f1, obj);
	cout << "Кол-во элементов > 5: " << itf() << endl;
	auto its = bind(f2, obj, 8);
	cout << "Кол-во элементов < 8: " << its() << endl;
}
