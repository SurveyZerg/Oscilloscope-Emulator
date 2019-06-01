//generator.cpp

#include <fstream>
#include "generator.h"
#include "oscilloscope.h"

void Generator::Set_maximum_output_frequency(int maximum_output_frequency)
{
	this->maximum_output_frequency = maximum_output_frequency;
}
void Generator::Set_output_frequency(int output_frequency)
{
	this->output_frequency = output_frequency;
}
void Generator::Set_peak_to_peak_voltage(int peak_to_peak_voltage) 
{
	this->peak_to_peak_voltage = peak_to_peak_voltage;
}
void Generator::Set_signal(int output_frequency, int peak_to_peak_voltage)
{
	Set_output_frequency(output_frequency);
	Set_peak_to_peak_voltage(peak_to_peak_voltage);
}
void Generator::Set_connection_of_channel(int number_of_channel, bool on_off, Oscilloscope* device)
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

int Generator::Get_maximum_output_frequency()
{
	return maximum_output_frequency;
}
bool Generator::Get_connection_of_channel(int number_of_channel,std::string show)
{
	if (show == "yes" && Channels_on_off[number_of_channel - 1] == true)
	{
		std::cout << "To channel #" << number_of_channel << " of Generator " << this->Get_manufacturer() << " " << this->Get_device_model() << " connected Oscilloscope " << Channels_connected[number_of_channel - 1]->Get_manufacturer() << " " << Channels_connected[number_of_channel - 1]->Get_device_model() << std::endl;
	}
	if (show == "yes" && Channels_on_off[number_of_channel - 1] == false)
	{
		std::cout << "To channel #" << number_of_channel << " of Generator " << this->Get_manufacturer() << " " << this->Get_device_model() << " nothing connected" << std::endl;
	}
	return Channels_on_off[number_of_channel - 1];
}
int Generator::Get_output_frequency()
{
	return output_frequency;
}
int Generator::Get_peak_to_peak_voltage()
{
	return peak_to_peak_voltage;
}

Generator::Generator()
{
	this->Type_information(true);
	Make_Channels(Get_amount_of_ñhannels());
}
Generator::Generator(bool file_reading)
{
	std::ifstream load;
	load.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	try
	{
		load.open("load_generator.txt");
	}
	catch (const std::ifstream::failure &ex)
	{
		std::cout << "ERROR #9\nCouldn't open the file load.txt\n";
		std::cout << ex.what() << std::endl;
		std::cout << ex.code() << std::endl;
	}
	load >> *this;
	load.close();
	Make_Channels(this->Get_amount_of_ñhannels());
}
Generator::Generator(int amount_of_channels, std::string manufacturer, std::string device_model, int year_of_issue, int maximum_output_frequency, Generator* p_next, Generator* p_prev)
{
#ifdef _DEBUG
	std::cout << "Constructor Generator was called" << std::endl;
#endif

	Set_manufacturer(manufacturer);
	Set_device_model(device_model);
	Set_year_of_issue(year_of_issue);
	Set_maximum_output_frequency(maximum_output_frequency);
	Set_amount_of_ñhannels(amount_of_channels);
	this->p_next = p_next;
	this->p_prev = p_prev;

	Make_Channels(amount_of_channels);
}
Generator::~Generator()
{
#ifdef _DEBUG
	std::cout << "Default Destructor Generator was called" << std::endl;
#endif

}

void Generator::Type_information(bool all_information)
{
	if (all_information)
	{
		int amount_of_ñhannels, year_of_issue, maximum_output_frequency;
		std::string manufacturer, device_model;
		std::cout << "Type amount of channels - ";
		std::cin >> amount_of_ñhannels;
		std::cout << "Type manufacturer - ";
		std::cin >> manufacturer;
		std::cout << "Type device model - ";
		std::cin >> device_model;
		std::cout << "Type year of issue - ";
		std::cin >> year_of_issue;
		std::cout << "Type maximum output frequency - ";
		std::cin >> maximum_output_frequency;

		Set_manufacturer(manufacturer);
		Set_device_model(device_model);
		Set_year_of_issue(year_of_issue);
		Set_amount_of_ñhannels(amount_of_ñhannels);
		Set_maximum_output_frequency(maximum_output_frequency);
	}
	else
	{
		int amount_of_ñhannels;

		std::cout << "Type amount of channels - ";
		std::cin >> amount_of_ñhannels;

		Set_amount_of_ñhannels(amount_of_ñhannels);
	}

}

std::ostream& operator<< (std::ostream &out, Generator &device)
{
	out << "---------" << std::endl
		<< "Generator " << device.Get_manufacturer() << " " << device.Get_device_model()
		<< "(" << device.Get_year_of_issue() << "year)" << " : Amount of channels - "
		<< device.Get_amount_of_ñhannels() << ", Maximum output frequency - "
		<< device.Get_maximum_output_frequency() << " MHz" << std::endl;
	out << "Interface of Generator:\nOutput frequency = " << device.Get_output_frequency() 
		<< " Hz and Peak to Peak Voltage = " << device.Get_peak_to_peak_voltage() << " milliVolts\n";
	for (int i = 0; i < device.Get_amount_of_ñhannels(); i++)
	{
		out << "Channel #" << i + 1 << " is";
		if (device.Get_connection_of_channel(i + 1))
		{
			out << " busy: Connected Oscilloscope " << device.Channels_connected[i]->Get_manufacturer() << " "
				<< device.Channels_connected[i]->Get_device_model() << "\nWith Seconds Scale = "
				<< device.Channels_connected[i]->Get_seconds_scale() << " microSec/div and Voltage Scale = "
				<< device.Channels_connected[i]->Get_voltage_scale() << " milliVolts/div\n";
		}
		else
		{
			out << " free\n";
		}
	}
	out << "---------" << std::endl;
	return out;
}
std::istream& operator >> (std::istream &in, Generator &device)
{
	int amount_of_ñhannels, year_of_issue, maximum_output_frequency;
	std::string manufacturer, device_model;
	in >> amount_of_ñhannels >>  manufacturer >> device_model >> year_of_issue >> maximum_output_frequency;

	device.Set_manufacturer(manufacturer);
	device.Set_device_model(device_model);
	device.Set_year_of_issue(year_of_issue);
	device.Set_amount_of_ñhannels(amount_of_ñhannels);
	device.Set_maximum_output_frequency(maximum_output_frequency);

	return in;
}

void Generator::Make_Channels(int amount_of_channels)
{
	Channels_on_off.resize(amount_of_channels);
	Channels_connected.resize(amount_of_channels);
}
