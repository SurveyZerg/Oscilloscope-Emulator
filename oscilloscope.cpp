//oscilloscope.cpp

#include <string>
#include "oscilloscope.h"

int Oscilloscope::s_amount_of_oscilloscopes = 0;

Oscilloscope::Oscilloscope()
{
#ifdef _DEBUG
	std::cout << "Constructor Oscilloscope was called" << std::endl;
#endif

	(this->s_amount_of_oscilloscopes)++;
}
Oscilloscope::~Oscilloscope()
{
#ifdef _DEBUG
	std::cout << "Destructor Oscilloscope was called" << std::endl;
#endif

	(this->s_amount_of_oscilloscopes)--;
}

int Oscilloscope::Set_voltage_divisions(int voltage_divisions)
{
	this->voltage_divisions = voltage_divisions;
}
int Oscilloscope::Set_seconds_divisions(int seconds_divisions)
{
	this->seconds_divisions = seconds_divisions;
}

