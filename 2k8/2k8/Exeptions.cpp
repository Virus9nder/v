#include "Exeptions.h"

using namespace std;

Exeption::Exeption()
{
	errorCode = 0;
}

int Exeption::getErrorCode()
{
	return errorCode;
}

void Empty::printMessage()
{
	cout << "���� ����" << endl;
	cout << "��� ������: " << Exeption::getErrorCode() << endl;
}
Empty::Empty()
{
	Exeption::errorCode = 1;
}

void Ne4et::printMessage()
{

	cout << "������ �������� �������" << endl;
	cout << "��� ������: " << Exeption::getErrorCode() << endl;
}
Ne4et::Ne4et()
{
	Exeption::errorCode = 2;
}

void NoGreater::printMessage()
{

	cout << "��� ��������� ������ ���������" << endl;
	cout << "��� ������: " << Exeption::getErrorCode() << endl;
}
NoGreater::NoGreater()
{
	Exeption::errorCode = 3;
}

void NoPlus::printMessage()
{

	cout << "������ ������������� �������" << endl;
	cout << "��� ������: " << Exeption::getErrorCode() << endl;
}
NoPlus::NoPlus()
{
	Exeption::errorCode = 4;
}

void Limited100::printMessage()
{

	cout << "������� ������ ������� ������� ����������� ��������" << endl;
	cout << "��� ������: " << Exeption::getErrorCode() << endl;
}
Limited100::Limited100()
{
	Exeption::errorCode = 5;
}