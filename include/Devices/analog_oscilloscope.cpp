//analog_oscilloscope.cpp

#include <fstream>
#include <sstream>
#include "analog_oscilloscope.h"
#include "generator.h"

int Analog_Oscilloscope::s_amount_of_analog_oscilloscopes = 0;

void Analog_Oscilloscope::Set_amount_of_beams(int amount_of_beams)
{
	this->amount_of_beams = amount_of_beams;
}

int Analog_Oscilloscope::Get_amount_of_beams()
{
	return this->amount_of_beams;
}

Analog_Oscilloscope::Analog_Oscilloscope()
{
#ifdef _DEBUG
	std::cout << "Default Constructor Analog Oscilloscope was called" << std::endl;
#endif
	this->Type_information(true);
	this->p_next = nullptr;
	this->p_prev = nullptr;
	Make_Channels(Get_amount_of_ñhannels());
	(this->s_amount_of_analog_oscilloscopes)++;
}
Analog_Oscilloscope::Analog_Oscilloscope(std::ifstream& load)
{
#ifdef _DEBUG
	std::cout << "Constructor Analog Oscilloscope was called" << std::endl;
#endif
	try
	{
		if (!load.is_open())
		{
			throw std::exception("ERROR #9\nYou tried to create object from file, that doesn't exist\n");
		}
		load >> *this;
		this->p_next = nullptr;
		this->p_prev = nullptr;
		Make_Channels(this->Get_amount_of_ñhannels());
		(this->s_amount_of_analog_oscilloscopes)++;
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
/*Analog_Oscilloscope::Analog_Oscilloscope(int amount_of_ñhannels, int voltage_divisions, int seconds_divisions, std::string manufacturer, std::string device_model, int year_of_issue,  int amount_of_beams, Analog_Oscilloscope* p_next, Analog_Oscilloscope* p_prev)
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
	this->p_next = p_next;
	this->p_prev = p_prev;
	Make_Channels(amount_of_ñhannels);
}*/
Analog_Oscilloscope::~Analog_Oscilloscope()
{
#ifdef _DEBUG
	std::cout << "Destructor Analog Oscilloscope was called" << std::endl;
#endif

	(this->s_amount_of_analog_oscilloscopes)--;
}

void Analog_Oscilloscope::Type_information(bool all_information)
{
	if (all_information)
	{
		int amount_of_ñhannels, voltage_divisions, seconds_divisions, year_of_issue, amount_of_beams;
		std::string manufacturer, device_model;
		std::cout << "Type amount of channels - ";
		std::cin >> amount_of_ñhannels;
		std::cout << "Type voltage divisions (Oy) - ";
		std::cin >> voltage_divisions;
		std::cout << "Type seconds divisions (Ox) - ";
		std::cin >> seconds_divisions;
		std::cout << "Type manufacturer - ";
		std::cin >> manufacturer;
		std::cout << "Type device model - ";
		std::cin >> device_model;
		std::cout << "Type year of issue - ";
		std::cin >> year_of_issue;
		std::cout << "Type amount of beams - ";
		std::cin >> amount_of_beams;
	
		Set_manufacturer(manufacturer);
		Set_device_model(device_model);
		Set_year_of_issue(year_of_issue);
		Set_amount_of_ñhannels(amount_of_ñhannels);
		Set_amount_of_beams(amount_of_beams);
		Set_voltage_divisions(voltage_divisions);
		Set_seconds_divisions(seconds_divisions);
	}
	else
	{
		int amount_of_ñhannels, voltage_divisions, seconds_divisions;

		std::cout << "Type amount of channels - ";
		std::cin >> amount_of_ñhannels;
		std::cout << "Type voltage divisions (Oy) - ";
		std::cin >> voltage_divisions;
		std::cout << "Type seconds divisions (Ox) - ";
		std::cin >> seconds_divisions;

		Set_amount_of_ñhannels(amount_of_ñhannels);
		Set_voltage_divisions(voltage_divisions);
		Set_seconds_divisions(seconds_divisions);
	}

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
	std::string manufacturer, device_model,buff;

	std::getline(in, buff, '\n');
	std::stringstream stream_buff;

	stream_buff << buff;
	stream_buff >> amount_of_ñhannels;
	stream_buff >> voltage_divisions; 
	stream_buff >> seconds_divisions;
	stream_buff >> manufacturer;
	stream_buff >> device_model;
	stream_buff >> year_of_issue;
	stream_buff >> amount_of_beams;

	device.Set_manufacturer(manufacturer);
	device.Set_device_model(device_model);
	device.Set_year_of_issue(year_of_issue);
	device.Set_amount_of_ñhannels(amount_of_ñhannels);
	device.Set_amount_of_beams(amount_of_beams);
	device.Set_voltage_divisions(voltage_divisions);
	device.Set_seconds_divisions(seconds_divisions);

	return in;
}

