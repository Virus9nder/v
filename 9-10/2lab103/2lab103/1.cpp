#include <Windows.h>
#include "WORLD.h"

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//�������� � ������������� �������� ����������������� ����
	World obj1("����", 600), obj2("������", 5000), obj3("������", 250000), obj4("�����", 7000000);
	//�������� ���������� map F
	map<int, World> F;
	//���������� F
	F.insert(pair<int, World>(1, obj1));
	F.insert(pair<int, World>(2, obj2));
	F.insert(pair<int, World>(3, obj3));
	F.insert(pair<int, World>(4, obj4));
	cout << "F �� ����������" << endl;
	for (auto it = F.begin(); it != F.end(); ++it)
		cout << it->first << " : " << it->second << endl;
	F = Srtng(F, 0); //���������� �� �������� (0-�� ��������, 1-�� �����������)
	cout << "F ����� ����������" << endl;
	for (auto it = F.begin(); it != F.end(); ++it)
		cout << it->first << " : " << it->second << endl;
	//����� �������� �� �������
	auto ftemp = find_if(F.rbegin(), F.rend(), IfCName);
	cout << "�������, ��������������� ������� World::name == \"������\":" << endl;
	cout << ftemp->first << " : " << ftemp->second << endl;
	//lower_bound, upper_bound
	/*pair<int, World> bound(3, obj3);
	auto p1 = lower_bound(F.begin(), F.end(), bound, ComparisonL);
	auto p2 = upper_bound(F.begin(), F.end(), bound, ComparisonU);
	cout << "����� � ����������� lower_bound" << p1->first << " : " << p1->second << endl;
	cout << "����� � ����������� upper_bound" << p2->first << " : " << p2->second << endl;*/

	//�������� ���������� Set S � ��� ���������� �������� ������� World::ppl > 50 000
	set<World> S;
	for (auto it = F.begin(); it != F.end(); ++it)
	{
		if (IfPpl(*it))
			S.insert(it->second);
	}
	cout << "����� ��������� ��������� S �� �����:" << endl;
	copy(S.begin(), S.end(), ostream_iterator<World>(cout, "\n"));

	//���������� F � S �� �����������
	F = Srtng(F, 1);
	cout << "����� ��������� F ����� ���������� �� �����������:" << endl;
	for (auto it = F.begin(); it != F.end(); ++it)
		cout << it->first << " : " << it->second << endl;
	//S ��� �������������

	//�������� 3-��� ���������� � ���������� ���� ������� ������ ����
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
	cout << "����� ��������� ������ L �� �����:" << endl;
	copy(L.begin(), L.end(), ostream_iterator<World>(cout, "\n"));

	//����� ���-�� ��������� �� ��������� �������
	int c = count_if(L.begin(), L.end(), IfPplW);
	cout << "���-�� ��������� � L, ��������������� World::ppl > 50 000: " << c << endl;
	cout << "\n�������� �� ������� �������� � L �������� �������: World::ppl == 250 000:" << endl;
	if (any_of(L.begin(), L.end(), IfCW))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	cout << endl;
	//string
	cout << "������������ ������ string:" << endl;
	string s1;
	string s2("text");
	string s3(s2);
	string s4 = s3;
	cout << "2)" << s2 << " - Default\n3)" << s3 << " - Copy\n4)" << s4 << " - Move" << endl; // ������������: �������, �����������, �����������
	cout << "string.substr(0,2): " << s2.substr(0, 2) << endl; //����� ���������
	s3.append(4, 'e'); //���������� � ����� ��������
	cout << "string.append(4,\'e\'): " << s3 << endl;
	s4.erase(1, 2);
	cout << "string.erase(1,2): " << s4 << endl; //�������� �� 2-�� �� 3-��
	cout << endl;
	//��������
	cout << "������������ ������ ���������:" << endl;
	Func1 f1;
	Func2 f2;
	list<int> obj = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto itf = bind(f1, obj);
	cout << "���-�� ��������� > 5: " << itf() << endl;
	auto its = bind(f2, obj, 8);
	cout << "���-�� ��������� < 8: " << its() << endl;
}
