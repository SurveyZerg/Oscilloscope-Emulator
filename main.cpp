#include <iostream>
#include "oscyloskop.h"

using namespace std;

int main()
{
	Oscyloskop obj1(1, "HP", "M3428", 1998);
	obj1.Print(); //obiekt automatyczny
	Oscyloskop obj2(obj1); //obiekt kopiujacy
	obj2.Print();
	obj2.SetModel("M5100");
	obj2.SetYear(2010);
	obj2.Print();
	obj2.AddOscyloskop(3, "Appa", "3700", 2003); //obiekt dynamiczny
	
	cout << Oscyloskop::GetLiczbaOscyloskopow() << endl; // test statycznego pola + metody
	system("Pause");
	return 0;
} 