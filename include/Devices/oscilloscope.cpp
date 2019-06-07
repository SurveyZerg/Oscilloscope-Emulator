//oscilloscope.cpp

#include "oscilloscope.h"
#include "generator.h"

Oscilloscope::Oscilloscope()
{
#ifdef _DEBUG
	std::cout << "Constructor Oscilloscope was called" << std::endl;
#endif
}
Oscilloscope::~Oscilloscope()
{
#ifdef _DEBUG
	std::cout << "Destructor Oscilloscope was called" << std::endl;
#endif
}

void Oscilloscope::Set_voltage_divisions(int voltage_divisions)
{
	this->voltage_divisions = voltage_divisions;
}
void Oscilloscope::Set_seconds_divisions(int seconds_divisions)
{
	this->seconds_divisions = seconds_divisions;
}
void Oscilloscope::Set_voltage_scale(int voltage_scale)
{
	this->voltage_scale = voltage_scale;
}
void Oscilloscope::Set_seconds_scale(int seconds_scale)
{
	this->seconds_scale = seconds_scale;
}
void Oscilloscope::Set_connection_of_channel(int number_of_channel, bool on_off, Generator* device)
{
	Channels_on_off[number_of_channel - 1] = on_off;
	if (on_off == true)
	{
		Channels_connected[number_of_channel - 1] = device;
	}
	else if (on_off == false)
	{
		Channels_connected[number_of_channel - 1] = 0;
	}
}

bool Oscilloscope::Get_connection_of_channel(int number_of_channel, std::string show)
{
	if (show == "yes" && Channels_on_off[number_of_channel - 1] == true)
	{
		std::cout << "To channel #" << number_of_channel << " of Oscilloscope "<< this->Get_manufacturer() <<" " << this->Get_device_model() <<" connected Generator " << Channels_connected[number_of_channel - 1]->Get_manufacturer() << " " << Channels_connected[number_of_channel - 1]->Get_device_model() << std::endl;
	}
	if (show == "yes" && Channels_on_off[number_of_channel - 1] == false)
	{
		std::cout << "To channel #" << number_of_channel << " of Oscilloscope " << this->Get_manufacturer() << " " << this->Get_device_model() << " nothing connected" << std::endl;
	}
	return Channels_on_off[number_of_channel - 1];
}
int Oscilloscope::Get_voltage_divisions()
{
	return voltage_divisions;
}
int Oscilloscope::Get_seconds_divisions()
{
	return seconds_divisions;
}
int Oscilloscope::Get_seconds_scale()
{
	return seconds_scale;
}
int Oscilloscope::Get_voltage_scale()
{
	return voltage_scale;
}
Generator* Oscilloscope::Get_connected_generator(int number_of_channel)
{
	return Channels_connected[number_of_channel - 1];
}

void Oscilloscope::Make_Channels(int amount_of_channels)
{
	Channels_on_off.resize(amount_of_channels);
	Channels_connected.resize(amount_of_channels);
}