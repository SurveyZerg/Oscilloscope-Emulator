#include <iostream>
#include <string>
#include "oscyloskop.h"

#define _DEBUG
int Oscyloskop::s_liczba_oscyloskopow = 0;


Oscyloskop::Oscyloskop()
{
#ifdef _DEBUG
	cout << "Wywolany zerowy konstruktor" << endl;
#endif
	m_index = 0;
	m_producent = "-";
	m_model = "-";
	m_product_year = 0;
	m_voltage_z_generatora = 0;
}

Oscyloskop::Oscyloskop(int index, std::string producent, std::string model, int product_year, int voltage_z_generatora)
{
#ifdef _DEBUG
	cout << "Wywolany konstruktor" << endl;
#endif
	s_liczba_oscyloskopow++;

	m_index = index;
	m_producent = producent;
	m_model = model;
	m_product_year = product_year;
	m_voltage_z_generatora = voltage_z_generatora;
}

Oscyloskop::Oscyloskop(const Oscyloskop &other)
{
#ifdef _DEBUG
	cout << "Wywolany kopiujacy konstruktor" << endl;
#endif
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

Oscyloskop::~Oscyloskop()
{
#ifdef _DEBUG
	cout << "Wywolany destruktor" << endl;
#endif
	//s_liczba_oscyloskopow--;
}


int Oscyloskop::GetLiczbaOscyloskopow()
{
	return s_liczba_oscyloskopow;
}

void Oscyloskop::SetIndex(int index)
{
	m_index = index;
}

void Oscyloskop::SetModel(string model)
{
	m_model = model;
}

void Oscyloskop::SetYear(int product_year)
{
	m_product_year = product_year;
}


Oscyloskop Oscyloskop::operator = (const Oscyloskop &other)
{
#ifdef _DEBUG
	cout << "Wywolany operator = \n";
#endif
	this->m_index = other.m_index;
	this->m_model = other.m_model;
	this->m_producent = other.m_producent;
	this->m_product_year = other.m_product_year;
	this->m_voltage_z_generatora = other.m_voltage_z_generatora;

	return *this;
}

Oscyloskop Oscyloskop::operator + (const Oscyloskop &other)
{
#ifdef _DEBUG
	cout << "Wywolany operator + \n";
#endif
	this->m_voltage_z_generatora = this->m_voltage_z_generatora + other.m_voltage_z_generatora;
	return *this;
}

Oscyloskop Oscyloskop::operator -- ()
{
#ifdef _DEBUG
	cout << "Wywolany operator -- \n";
#endif
	this->m_voltage_z_generatora = this->m_voltage_z_generatora - 1;
	return *this;
}

Oscyloskop::operator int()
{
#ifdef _DEBUG
	cout << "Wywolany operator Oscyloskop ---> int \n";
#endif
	return m_voltage_z_generatora;
}

bool operator == (const Oscyloskop &other1, const Oscyloskop &other2)
{
#ifdef _DEBUG
	cout << "Wywolany operator == \n";
#endif
	return (other1.m_voltage_z_generatora == other2.m_voltage_z_generatora);
}

bool operator > (const Oscyloskop &other1, const Oscyloskop &other2)
{
#ifdef _DEBUG
	cout << "Wywolany operator > \n";
#endif
	return (other1.m_voltage_z_generatora > other2.m_voltage_z_generatora);
}


void Oscyloskop::Print()
{
	std::cout << "--------------------------------\n"
		<< "Objekt #" << m_index << std::endl << "Oscyloskop " << m_producent << " " << m_model << " " << m_product_year << " year voltage:"<< m_voltage_z_generatora << "V\n"
		<< "--------------------------------\n";
} 

void Oscyloskop::AddOscyloskop(int index, std::string producent, std::string model, int product_year, int voltage_z_generatora)
{
	Oscyloskop *ptr;
	ptr = new Oscyloskop(index,producent,model,product_year, voltage_z_generatora);
	delete ptr;
} 
