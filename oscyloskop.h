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
	int m_voltage_z_generatora;

	static int s_liczba_oscyloskopow;
	
public:

	Oscyloskop()
	{
		cout << "Wywolany zerowy konstruktor" << endl;

		m_index = 0;
		m_producent = "-";
		m_model = "-";
		m_product_year = 0;
		m_voltage_z_generatora = 0;
	}
	//Не забудь добавлять поля в конструктор + перенести его реализацию в cpp 
	Oscyloskop(int index, std::string producent, std::string model, int product_year, int voltage_z_generatora)
	{
		cout << "Wywolany konstruktor" << endl;

		s_liczba_oscyloskopow++;

		m_index = index;
		m_producent = producent;
		m_model = model;
		m_product_year = product_year;
		m_voltage_z_generatora = voltage_z_generatora;
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
		this->m_voltage_z_generatora = other.m_voltage_z_generatora;
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

	Oscyloskop operator = (const Oscyloskop &other)
	{
		cout << "Wywolany operator = \n";
		this->m_index = other.m_index;
		this->m_model = other.m_model;
		this->m_producent = other.m_producent;
		this->m_product_year = other.m_product_year;
		this->m_voltage_z_generatora = other.m_voltage_z_generatora;

		return *this;
	}

	Oscyloskop operator + (const Oscyloskop &other)
	{
		cout << "Wywolany operator + \n";
		this->m_voltage_z_generatora = this->m_voltage_z_generatora + other.m_voltage_z_generatora;
		return *this;
	}

	Oscyloskop operator -- ()
	{
		cout << "Wywolany operator -- \n";
		this->m_voltage_z_generatora = this->m_voltage_z_generatora - 1;
		return *this;
	}

	operator int()
	{
		return m_voltage_z_generatora;
	}

	friend bool operator == (const Oscyloskop &other1, const Oscyloskop &other2)
	{
		return (other1.m_voltage_z_generatora == other2.m_voltage_z_generatora);
	}

	friend bool operator > (const Oscyloskop &other1, const Oscyloskop &other2)
	{
		return (other1.m_voltage_z_generatora > other2.m_voltage_z_generatora);
	}

	void Print();
	void AddOscyloskop(int index, std::string producent, std::string model, int product_year,int voltage_z_generatora);

};
#endif