//analog_oscilloscope.cpp

#include "analog_oscilloscope.h"
#include "generator.h"

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

std::ostream& operator << (std::ostream &out, Analog_Oscilloscope &device)
{
	out << "---------" << std::endl
		<< "Analog Oscilloscope " << device.Get_manufacturer() << " "
		<< device.Get_device_model() << "(" << device.Get_year_of_issue() << "year)" << " : Amount of channels - "
		<< device.Get_amount_of_ñhannels() << ", Amount of beams - " << device.Get_amount_of_beams() << std::endl;
	out << "Interface of Oscilloscope:\nDisplay is " << device.Get_seconds_divisions() << " x " << device.Get_voltage_divisions()
		<< "\nSeconds scale = " << device.Get_seconds_scale() << " microSec/div and Voltage Scale = "
		<< device.Get_voltage_scale() << " milliVolts/div\n";
	for (int i = 0; i < device.Get_amount_of_ñhannels(); i++)
	{
		out << "Channel #" << i + 1 << " is";
		if (device.Get_connection_of_channel(i + 1))
		{
			out << " busy: Connected Generator " << device.Channels_connected[i]->Get_manufacturer() << " "
				<< device.Channels_connected[i]->Get_device_model() <<"\nWith Output frequency = "
				<< device.Channels_connected[i]->Get_output_frequency() << " Hz and Peak to Peak Voltage = "
				<< device.Channels_connected[i]->Get_peak_to_peak_voltage() << " milliVolts\n";
		}
		else
		{
			out << " free\n";
		}
	}
	out << "---------" << std::endl;
	return out;
}
std::istream& operator >> (std::istream &in, Analog_Oscilloscope &device)
{
	int amount_of_ñhannels, voltage_divisions, seconds_divisions, year_of_issue, amount_of_beams;
	std::string manufacturer, device_model;
	in >> amount_of_ñhannels >> voltage_divisions >> seconds_divisions >> manufacturer >> device_model >> year_of_issue >> amount_of_beams;
	
	device.Set_manufacturer(manufacturer);
	device.Set_device_model(device_model);
	device.Set_year_of_issue(year_of_issue);
	device.Set_amount_of_ñhannels(amount_of_ñhannels);
	device.Set_amount_of_beams(amount_of_beams);
	device.Set_voltage_divisions(voltage_divisions);
	device.Set_seconds_divisions(seconds_divisions);

	return in;
}
