//Неявное подключение библиотеки
#pragma comment(lib,"MyDll.lib")
#include "MyDll.h"
#include <iostream>
#include "windows.h"

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Rus");

	//Неявное подключение
	MyDll sg;
	sg.printInfo();
	Virus();

	//Динмаическое подключение 
	HINSTANCE hModule = NULL;
	typedef  void(WINAPI ViRus)();
	ViRus* virus;
	//Поиск библиотеки
	hModule = ::LoadLibrary(L"MyDLL.dll");
	//system("pause");
	//Virus();
	//MyDll;
	//MyDll printInfo();
	if (hModule != NULL)
	{
		//Поиск в библиотеке нужной функции
		virus = (ViRus*)::GetProcAddress(hModule, "Virus");
		if (virus != NULL)
		{
			virus();
		}
		else
		{
			cout << "Ошибка загрузки функции" << endl;
			cout << GetLastError() << endl;
		}
		//Освобождение памяти
		::FreeLibrary(hModule);
	}
	else cout << "Ошибка загрузки Dll" << endl;


}