//������� ����������� ����������
#pragma comment(lib,"MyDll.lib")
#include "MyDll.h"
#include <iostream>
#include "windows.h"

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Rus");

	//������� �����������
	MyDll sg;
	sg.printInfo();
	Virus();

	//������������ ����������� 
	HINSTANCE hModule = NULL;
	typedef  void(WINAPI ViRus)();
	ViRus* virus;
	//����� ����������
	hModule = ::LoadLibrary(L"MyDLL.dll");
	//system("pause");
	//Virus();
	//MyDll;
	//MyDll printInfo();
	if (hModule != NULL)
	{
		//����� � ���������� ������ �������
		virus = (ViRus*)::GetProcAddress(hModule, "Virus");
		if (virus != NULL)
		{
			virus();
		}
		else
		{
			cout << "������ �������� �������" << endl;
			cout << GetLastError() << endl;
		}
		//������������ ������
		::FreeLibrary(hModule);
	}
	else cout << "������ �������� Dll" << endl;


}