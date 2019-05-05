//digital_oscilloscope.cpp

#include "digital_oscilloscope.h"

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

std::ostream& operator<< (std::ostream &out, Digital_Oscilloscope &device)
{
	out << "---------" << std::endl << "Digital Oscilloscope " << device.Get_manufacturer() 
		<< " " << device.Get_device_model() << "(" << device.Get_year_of_issue() << "year)"
		<< " : Amount of channels - " << device.Get_amount_of_ñhannels() << ", Memory depth - "
		<< device.Get_memory_depth() <<" Mpts/CH"<< std::endl <<"---------" << std::endl;
	return out;
}

