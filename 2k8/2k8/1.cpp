

#include <iostream>
#include <conio.h>
#include "windows.h"
#include "Exeptions.h"
#include "Stack.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		Stack<int> St;
		Stack<int> Test;
		Stack<int> St1;
		Stack<double> St2;
	//	Stack<float> St3;
		//St1.push(5);

		St.push(1);
		St + 4;
		if (!St.operator bool())cout << "\n—тек не пустой\n";;
		St + 16;
		St.push(5);
		St.push(4);
		St.push(10);
		int p = 1;

		St > St1;
		int da = St.prosto(St);

		St2.push((7.2));
		St2.push(7);
		St2.push(6.9);

		//St3.push((7.2));
	//	St3.push((7));
	//	St3.push((6.9));
		cout << "St1: " << St.pros(St, 7) << endl << endl;
		cout << "St2: " << St2.prose(St2, 6.99) << endl << endl;
		cout << "St2: " << St2.pros(St2, (6.89)) << endl << endl;

		//cout << "St3: " << St3.pros(St3, (7)) << endl << endl;

		for (int i = 0; i < da; i++)St--;
		cout << '\n';

		cout << "Ёлементы стека St1: ";
		St1.print();
		St1--;
		cout << endl<<endl;
		/////////
		//1-пустой
		//Test.pop();
		//Test.top();
		//Test.print();
		//2-отрицатеельный
		//Test.push(-2);

		//3-нет больши’
		//Test.pros(Test,100);
		//4-нечетное
		Test + 3;
		//5-слишком большое
		Test.push(1200);


	}
	catch (Empty obj)
	{
		obj.printMessage();
	}
	catch (NoGreater obj)
	{
		obj.printMessage();
	}
	catch (Ne4et obj)
	{
		obj.printMessage();
	}
	catch (NoPlus obj)
	{
		obj.printMessage();
	}
	catch (Limited100 obj)
	{
		obj.printMessage();
	}
	


	return 0;
}