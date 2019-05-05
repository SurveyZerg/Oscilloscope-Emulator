//digital_oscilloscope.cpp

#include "digital_oscilloscope.h"
#include "generator.h"

int Digital_Oscilloscope::s_amount_of_digital_oscilloscopes = 0;

void Digital_Oscilloscope::Set_memory_depth(int memory_depth)
{
	this->memory_depth = memory_depth;
}

int Digital_Oscilloscope::Get_memory_depth()
{
	return memory_depth;
}


Digital_Oscilloscope::Digital_Oscilloscope(int amount_of_ñhannels, int voltage_divisions, int seconds_divisions, std::string manufacturer, std::string device_model, int year_of_issue,  int memory_depth)
{
#ifdef _DEBUG
	std::cout << "Constructor Digital Oscilloscope was called" << std::endl;
#endif

	(this->s_amount_of_digital_oscilloscopes)++;

	Set_manufacturer(manufacturer);
	Set_device_model(device_model);
	Set_year_of_issue(year_of_issue);
	Set_amount_of_ñhannels(amount_of_ñhannels);
	Set_memory_depth(memory_depth);
	Set_voltage_divisions(voltage_divisions);
	Set_seconds_divisions(seconds_divisions);

	Make_Channels(amount_of_ñhannels);
}
Digital_Oscilloscope::~Digital_Oscilloscope()
{
#ifdef _DEBUG
	std::cout << "Destructor Digital Oscilloscope was called" << std::endl;
#endif

	(this->s_amount_of_digital_oscilloscopes)--;
}

std::ostream& operator << (std::ostream &out, Digital_Oscilloscope &device)
{
	out << "---------" << std::endl
		<< "Digital Oscilloscope " << device.Get_manufacturer()
		<< " " << device.Get_device_model() << "(" << device.Get_year_of_issue() << "year)"
		<< " : Amount of channels - " << device.Get_amount_of_ñhannels() << ", Memory depth - "
		<< device.Get_memory_depth() << " Mpts/CH" << std::endl;
	out << "Interface of Oscilloscope:\nDisplay is " << device.Get_seconds_divisions() << " x " << device.Get_voltage_divisions()
		<< "\nSeconds scale = " << device.Get_seconds_scale() << " microSec/div and Voltage Scale = "
		<< device.Get_voltage_scale() << " milliVolts/div\n";
	for (int i = 0; i < device.Get_amount_of_ñhannels(); i++)
	{
		out << "Channel #" << i + 1 << " is";
		if (device.Get_connection_of_channel(i + 1))
		{
			out << " busy: Connected Generator " << device.Channels_connected[i]->Get_manufacturer() << " "
				<< device.Channels_connected[i]->Get_device_model() << "\nWith Output frequency = "
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
std::istream& operator >> (std::istream &in, Digital_Oscilloscope &device)
{
	int amount_of_ñhannels, voltage_divisions, seconds_divisions, year_of_issue, memory_depth;
	std::string manufacturer, device_model;
	in >> amount_of_ñhannels >> voltage_divisions >> seconds_divisions >> manufacturer >> device_model >> year_of_issue >> memory_depth;

	device.Set_manufacturer(manufacturer);
	device.Set_device_model(device_model);
	device.Set_year_of_issue(year_of_issue);
	device.Set_amount_of_ñhannels(amount_of_ñhannels);
	device.Set_memory_depth(memory_depth);
	device.Set_voltage_divisions(voltage_divisions);
	device.Set_seconds_divisions(seconds_divisions);

	return in;
}

