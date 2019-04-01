#ifndef OSCYLOSLOP_H
#define OSCYLOSLOP_H

#include <iostream>
#include <string>

using namespace std;

class Oscyloskop
{
private:
	int m_index;
	std::string m_producent; //Обнови названия на нормальные
	std::string m_model;
	int m_product_year;

	static int s_liczba_oscyloskopow;
	
public:

	Oscyloskop()
	{
		cout << "Wywolany zerowy konstruktor" << endl;

		m_index = 0;
		m_producent = "-";
		m_model = "-";
		m_product_year = 0;
	}
	//Не забудь добавлять поля в конструктор + перенести его реализацию в cpp 
	Oscyloskop(int index, std::string producent, std::string model, int product_year)
	{
		cout << "Wywolany konstruktor" << endl;

		s_liczba_oscyloskopow++;

		m_index = index;
		m_producent = producent;
		m_model = model;
		m_product_year = product_year;
	}
	Oscyloskop(const Oscyloskop &other)
	{
		cout << "Wywolany kopiujacy konstruktor" << endl;
		Oscyloskop *ptr;
		ptr = new Oscyloskop();
		this->m_index = other.m_index + 1;
		this->m_model = other.m_model;
		this->m_producent = other.m_producent;
		this->m_product_year = other.m_product_year;
		s_liczba_oscyloskopow++;
		delete ptr;
	}
	~Oscyloskop()
	{
		cout << "Wywolany destruktor" << endl;

		//s_liczba_oscyloskopow--;
	}

	static int GetLiczbaOscyloskopow();

	void SetIndex(int index);
	void SetModel(string model);
	void SetYear(int product_year);

	void Print();
	void AddOscyloskop(int index, std::string producent, std::string model, int product_year);


};
#endif