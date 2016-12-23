#include<iostream> 
#include "1.h"
#include<list>
using namespace std;

void main() {

	World *a = new World(123);
	World *b = new World(232);
	World *c = new World(347);
	cout << "---------------------------- list -----------------------------";
	list<World> container;
	container.push_back(*a);
	container.push_back(*b);
	container.push_back(*c);
	cout << endl;
	int size = container.size();
	for (int i = 0; i < size; i++)
	{
		cout << "----- Element " << i + 1 << " -----" << endl;
		cout << container.front();
		container.pop_front();
		cout << endl;
	}
	system("pause");
}