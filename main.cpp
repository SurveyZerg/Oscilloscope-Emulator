#include <iostream>
#include "oscyloskop.h"

using namespace std;

int main()
{
	Oscyloskop obj1(1, "HP", "M3428", 1998,3);
	obj1.Print(); //obiekt automatyczny
	Oscyloskop obj2(obj1); //obiekt kopiujacy
	obj2.Print();
	obj2.SetModel("M5100");
	obj2.SetYear(2010);
	obj2.Print();
	obj2.AddOscyloskop(3, "Appa", "3700", 2003,5); //obiekt dynamiczny
	
	cout << Oscyloskop::GetLiczbaOscyloskopow() << endl; // test statycznego pola + metody

	obj1 = obj2; //operator #1
	obj1.Print();
	obj2.Print();

	obj1 + obj2; //operator #2
	obj1.Print();
	obj2.Print();

	--obj2; //operator #3
	obj2.Print();
	
	cout<< "voltage " << obj2 <<endl; //operator #4

	if (obj1 == obj2) //operator #5
	{
		cout << "voltage sa rowne!" << endl;
	}
	else
	{
		cout << "voltage nie sa rowne!" << endl;
	}

	if (obj1 > obj2) //operator #6
	{
		cout << "voltag objektu 1 jest wiecej!" << endl;
	}
	else
	{
		cout << "voltag objektu 1 jest mniej!" << endl;
	}


	system("Pause");
	return 0;
} 