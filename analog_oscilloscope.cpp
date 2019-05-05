//analog_oscilloscope.cpp

#include "analog_oscilloscope.h"

int Analog_Oscilloscope::s_amount_of_analog_oscilloscopes = 0;

void Analog_Oscilloscope::Set_amount_of_beams(int amount_of_beams)
{
	this->amount_of_beams = amount_of_beams;
}
void Analog_Oscilloscope::Set_connection_of_channel(int number_of_channel, bool on_off)
{
	Channels[number_of_channel - 1] = on_off;
}
void Analog_Oscilloscope::Set_voltage_scale(int voltage_scale)
{
	this->voltage_scale = voltage_scale;
}
void Analog_Oscilloscope::Set_seconds_scale(int seconds_scale)
{
	this->seconds_scale = seconds_scale;
}

int Analog_Oscilloscope::Get_amount_of_beams()
{
	return amount_of_beams;
}
bool Analog_Oscilloscope::Get_connection_of_channel(int number_of_channel)
{
	return Channels[number_of_channel - 1];
}

Analog_Oscilloscope::Analog_Oscilloscope(int amount_of_�hannels, int voltage_divisions, int seconds_divisions, std::string manufacturer, std::string device_model, int year_of_issue,  int amount_of_beams)
{
#ifdef _DEBUG
	std::cout << "Constructor Analog Oscilloscope was called" << std::endl;
#endif

	(this->s_amount_of_analog_oscilloscopes)++;

	Set_manufacturer(manufacturer);
	Set_device_model(device_model);
	Set_year_of_issue(year_of_issue);
	Set_amount_of_�hannels(amount_of_�hannels);
	Set_amount_of_beams(amount_of_beams);
	Set_voltage_divisions(voltage_divisions);
	Set_seconds_divisions(seconds_divisions);

	Make_Channels(amount_of_�hannels);
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
		<< device.Get_amount_of_�hannels() << ", Amount of beams - "<< device.Get_amount_of_beams() <<std::endl 
		<< "---------" << std::endl;
	return out;
}

void Analog_Oscilloscope::Make_Channels(int amount_of_channels)
{
	Channels.resize(amount_of_channels);
}