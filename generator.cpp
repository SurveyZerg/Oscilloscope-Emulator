//generator.cpp

#include "generator.h"

void Generator::Set_maximum_output_frequency(int maximum_output_frequency)
{
	this->maximum_output_frequency = maximum_output_frequency;
}
void Generator::Set_connection_of_channel(int number_of_channel,bool on_off)
{
	Channels[number_of_channel - 1] = on_off;
}
void Generator::Set_output_frequency(int output_frequency)
{
	this->output_frequency = output_frequency;
}
void Generator::Set_peak_to_peak_voltage(int peak_to_peak_voltage) 
{
	this->peak_to_peak_voltage = peak_to_peak_voltage;
}

int Generator::Get_maximum_output_frequency()
{
	return maximum_output_frequency;
}
bool Generator::Get_connection_of_channel(int number_of_channel)
{
	return Channels[number_of_channel - 1];
}

Generator::Generator(int amount_of_channels, std::string manufacturer, std::string device_model, int year_of_issue, int maximum_output_frequency)
{
#ifdef _DEBUG
	std::cout << "Constructor Generator was called" << std::endl;
#endif

	Set_manufacturer(manufacturer);
	Set_device_model(device_model);
	Set_year_of_issue(year_of_issue);
	Set_maximum_output_frequency(maximum_output_frequency);
	Set_amount_of_ñhannels(amount_of_channels);

	Make_Channels(amount_of_channels);
}

Generator::~Generator()
{
#ifdef _DEBUG
	std::cout << "Default Destructor Generator was called" << std::endl;
#endif

}

std::ostream& operator<< (std::ostream &out, Generator &device)
{
	out <<"---------"<< std::endl <<"Generator "<< device.Get_manufacturer() << " " << device.Get_device_model()
		<< "(" << device.Get_year_of_issue() << "year)" << " : Amount of channels - " 
		<< device.Get_amount_of_ñhannels() << ", Maximum output frequency - "
		<< device.Get_maximum_output_frequency() << " MHz" << std::endl << "---------" << std::endl;
	return out;
}

void Generator::Make_Channels(int amount_of_channels)
{
	Channels.resize(amount_of_channels);
}