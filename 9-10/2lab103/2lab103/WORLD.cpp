#include "WORLD.h"

//���� ������� ������ World
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
	cout << "1)��� - " << name << endl;
	cout << "2)��������� - " << ppl << endl;
}

// Friend-�������
//�������-���������
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
	return (obj.second.name == "������");
}
bool IfCW(World obj)
{
	return (obj.ppl == 250000);
}
//���������� ����������
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

//����������� �������
map<int, World> Srtng(map<int, World> obj, int How)
{
	//�������� ������ ����������
	map<int, World> New;
	//������� �������� �� ������� ���������� � �����
	for (auto tt = obj.begin(); tt != obj.end(); ++tt)
		New.insert(pair<int, World>(tt->first, tt->second));
	//�������� ����������:
	// ���������� ��������� �������� � ����� ����������
	// ������� � ������� �� �� �� �����, �� �� ��������
	for (int i = 1, k = 4; i <= 4; i++, k--) ///����� ���������� ������������� �������� ��������� ������� ���������
	{										 /// �. �. �� ������� ��� k--
		auto it = obj.begin(); ///������ ��� �� ������
		if (How == 0)
		{
			for (int j = 1; j < k; j++) ///���������� ������������� ��������
			if (it->second < obj.find(j + 1)->second)
				it = obj.find(j + 1); ///���������� ������������� ��������
		}
		else
		{
			for (int j = 1; j < k; j++) ///���������� ������������� ��������
			if (!(it->second < obj.find(j + 1)->second))
				it = obj.find(j + 1); ///���������� ������������ ��������
		}
		New.at(i) = it->second; ///���������� ������������� �������� �� i-�� �����
	}
	return New;
}