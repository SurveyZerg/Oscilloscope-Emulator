//analog_oscilloscope.cpp

#include "analog_oscilloscope.h"

int Analog_Oscilloscope::s_amount_of_analog_oscilloscopes = 0;

void Analog_Oscilloscope::Set_amount_of_beams(int amount_of_beams)
{
	this->amount_of_beams = amount_of_beams;
}

int Analog_Oscilloscope::Get_amount_of_beams()
{
	return amount_of_beams;
}

Analog_Oscilloscope::Analog_Oscilloscope(int amount_of_ñhannels, int voltage_divisions, int seconds_divisions, std::string manufacturer, std::string device_model, int year_of_issue,  int amount_of_beams)
{
#ifdef _DEBUG
	std::cout << "Constructor Analog Oscilloscope was called" << std::endl;
#endif

	(this->s_amount_of_analog_oscilloscopes)++;

	Set_manufacturer(manufacturer);
	Set_device_model(device_model);
	Set_year_of_issue(year_of_issue);
	Set_amount_of_ñhannels(amount_of_ñhannels);
	Set_amount_of_beams(amount_of_beams);
	Set_voltage_divisions(voltage_divisions);
	Set_seconds_divisions(seconds_divisions);

	Make_Channels(amount_of_ñhannels);
}
Analog_Oscilloscope::~Analog_Oscilloscope()
{
#ifdef _DEBUG
	std::cout << "Destructor Analog Oscilloscope was called" << std::endl;
#endif

	(this->s_amount_of_analog_oscilloscopes)--;
}

std::ostream& operator<< (std::ostream &out, Analog_Oscilloscope &device)
{
	out <<"---------" << std::endl << "Analog Oscilloscope "<< device.Get_manufacturer() << " " 
		<< device.Get_device_model() << "(" << device.Get_year_of_issue() << "year)"<< " : Amount of channels - " 
		<< device.Get_amount_of_ñhannels() << ", Amount of beams - "<< device.Get_amount_of_beams() <<std::endl 
		<< "---------" << std::endl;
	return out;
}
