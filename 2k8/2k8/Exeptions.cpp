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
	cout << "стек пуст" << endl;
	cout << "код ошибки: " << Exeption::getErrorCode() << endl;
}
Empty::Empty()
{
	Exeption::errorCode = 1;
}

void Ne4et::printMessage()
{

	cout << "¬веден нечетный элемент" << endl;
	cout << "код ошибки: " << Exeption::getErrorCode() << endl;
}
Ne4et::Ne4et()
{
	Exeption::errorCode = 2;
}

void NoGreater::printMessage()
{

	cout << "нет элементов больше заданного" << endl;
	cout << "код ошибки: " << Exeption::getErrorCode() << endl;
}
NoGreater::NoGreater()
{
	Exeption::errorCode = 3;
}

void NoPlus::printMessage()
{

	cout << "¬веден отрицательный элемент" << endl;
	cout << "код ошибки: " << Exeption::getErrorCode() << endl;
}
NoPlus::NoPlus()
{
	Exeption::errorCode = 4;
}

void Limited100::printMessage()
{

	cout << "Ёлемент больше верхней границы дозволенных значений" << endl;
	cout << "код ошибки: " << Exeption::getErrorCode() << endl;
}
Limited100::Limited100()
{
	Exeption::errorCode = 5;
}