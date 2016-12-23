#include "MyDll.h"
#include "windows.h"
#include <iostream>

using namespace std;

int Virus()
{

	cout << "Вызвана функция Virus из MyDLL" << endl;
	int c = 0;
	ULARGE_INTEGER free;
	GetDiskFreeSpaceEx(L"C:\\", &free, NULL, NULL);
	c += free.QuadPart;
	GetDiskFreeSpaceEx(L"D:\\", &free, NULL, NULL);
	c += free.QuadPart;
	GetDiskFreeSpaceEx(L"E:\\", &free, NULL, NULL);
	c += free.QuadPart;
	GetDiskFreeSpaceEx(L"F:\\", &free, NULL, NULL);
	c += free.QuadPart;
	cout << "Суммарный объем памяти: " << (c*0.975) / 1024 / 1024 << " Мб " << endl;
	return c;
}
int Prosto()
{
	const int SIZE = 100 * 1000;
	const int N = 9500;

	int n;
	do{
		cout << "Введите номер простого числа:   ";
		cin >> n;
	} while (n < 0 || N < n);

	int a[SIZE];
	for (int i = 2; i < SIZE; ++i)
		a[i] = 1;

	int k = 1;
	int p = 2;
	while (k < n){
		for (int i = 2 * p; i < SIZE; i += p)
			a[i] = 0;
		for (int i = p + 1; i < SIZE; ++i)
		if (a[i] == 1){
			p = i;
			break;
		}
		++k;
	}

	cout << p << endl;
	return p;
}

MyDll::MyDll()
{
}


int MyDll::printInfo()
{
	cout << "Вызвана функция printInfo класса MyDll из MyDLL" << endl;
	double c = 0;
	ULARGE_INTEGER free;
	GetDiskFreeSpaceEx(L"C:\\", &free, NULL, NULL);
	c += free.QuadPart;
	GetDiskFreeSpaceEx(L"D:\\", &free, NULL, NULL);
	c += free.QuadPart;
	GetDiskFreeSpaceEx(L"E:\\", &free, NULL, NULL);
	c += free.QuadPart;
	GetDiskFreeSpaceEx(L"F:\\", &free, NULL, NULL);
	c += free.QuadPart;
	cout << "Суммарный объем памяти: " << (c*0.975) / 1024 / 1024 << " Мб " << endl;
	return c;
}
