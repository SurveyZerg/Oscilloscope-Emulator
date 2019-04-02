#ifndef OSCYLOSLOP_H
#define OSCYLOSLOP_H

#include <string>

using namespace std;

class Oscyloskop
{
private:
	int m_index;
	std::string m_producent;
	std::string m_model;
	int m_product_year;
	int m_voltage_z_generatora;

	static int s_liczba_oscyloskopow;
	
public:

	Oscyloskop();
	Oscyloskop(int index, std::string producent, std::string model, int product_year, int voltage_z_generatora);
	Oscyloskop(const Oscyloskop &other);
	~Oscyloskop();

	static int GetLiczbaOscyloskopow();

	void SetIndex(int index);
	void SetModel(string model);
	void SetYear(int product_year);

	Oscyloskop operator = (const Oscyloskop &other);

	Oscyloskop operator + (const Oscyloskop &other);
	Oscyloskop operator -- ();

	operator int();
	friend bool operator == (const Oscyloskop &other1, const Oscyloskop &other2);

	friend bool operator > (const Oscyloskop &other1, const Oscyloskop &other2);

	void Print();
	void AddOscyloskop(int index, std::string producent, std::string model, int product_year,int voltage_z_generatora);

};
#endif