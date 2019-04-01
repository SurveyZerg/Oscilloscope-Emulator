#include <iostream>
#include "oscyloskop.h"

int Oscyloskop::s_liczba_oscyloskopow = 0;

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

void Oscyloskop::Print()
{
	std::cout << "--------------------------------\n"
		<< "Objekt #" << m_index << std::endl << "Oscyloskop " << m_producent << " " << m_model << " " << m_product_year << " year\n"
		<< "--------------------------------\n";
} 
//Ќе забудь добавл€ть сюда вывод по мере добавлени€ новых полей

void Oscyloskop::AddOscyloskop(int index, std::string producent, std::string model, int product_year)
{
	Oscyloskop *ptr;
	ptr = new Oscyloskop(index,producent,model,product_year);
	delete ptr;
} 

//—делай нормальное название дл€ этого