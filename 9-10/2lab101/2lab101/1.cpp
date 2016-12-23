#include <iostream>
#include <list>
#include <string>
#include <Windows.h>
#include <set>
using namespace std;

void main()
{
	list<int> my_list;
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.push_back(4);
	list<int> my_list2;
	my_list2 = my_list;
	cout << "list: " << endl;
	for (int i = 0; i < my_list.size(); i++)
	{
		cout << my_list2.front() << endl;
		my_list2.pop_front();
	}
	my_list.pop_back();
	my_list.pop_back();
	my_list.push_back(111);
	my_list.push_back(112);
	my_list2 = my_list;
	int size = 4;
	cout << "list: " << endl;
	for (int i = 0; i < my_list.size(); i++)
	{
		cout << my_list2.front() << endl;
		my_list2.pop_front();
	}
	cout << "set" << endl;
	set<int> my_set;
	my_set.insert(6);
	my_set.insert(7);
	my_set.insert(8);
	my_set.insert(9);
	copy(my_set.begin(), my_set.end(), ostream_iterator<int>(cout, " "));
	int n = 0;
	int k = 0;
	cin >> n >> k;
	set<int>::iterator p;
	set<int>::iterator p1;
	p = my_set.begin();
	p1 = my_set.begin();
	for (int i = 0; i < n; i++)
	{
		p++;
		p1++;
	}
	for (int i = 0; i < k; i++)
	{
		p1++;
	}
	
	my_set.erase(p,p1); 

	cout << "Result set: ";
	copy(my_set.begin(), my_set.end(), ostream_iterator<int>(cout, " "));
	for (int i = 0; i < size; i++)
	{
		my_set.emplace(my_list.back());
		my_list.pop_back();
	}
	cout << "Result set: ";
	copy(my_set.begin(), my_set.end(),ostream_iterator<int>(cout," "));
	/*for (int i = 0; i < my_set.size(); i++)
	{
		cout << my_set[i] << " ";
	}*/
	cout << endl;
	system("pause");
}