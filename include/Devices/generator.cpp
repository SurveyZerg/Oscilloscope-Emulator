//generator.cpp

#include <sstream>
#include "generator.h"
#include "oscilloscope.h"

void Generator::Set_maximum_output_frequency(int maximum_output_frequency)
{
	this->maximum_output_frequency = maximum_output_frequency;
}
void Generator::Set_output_frequency(__int64 output_frequency)
{
	this->output_frequency = output_frequency;
}
void Generator::Set_peak_to_peak_voltage(int peak_to_peak_voltage) 
{
	this->peak_to_peak_voltage = peak_to_peak_voltage;
}
void Generator::Set_signal(__int64 output_frequency, int peak_to_peak_voltage)
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
#ifdef _DEBUG
	std::cout << "Default Constructor Generator was called" << std::endl;
#endif
	this->p_next = nullptr;
	this->p_prev = nullptr;
}
Generator::Generator(bool all_info)
{
#ifdef _DEBUG
	std::cout << "Constructor Generator was called" << std::endl;
#endif
	this->Type_information(all_info);
	this->p_next = nullptr;
	this->p_prev = nullptr;
	Make_Channels(Get_amount_of_channels());
}
Generator::Generator(std::ifstream& load)
{
#ifdef _DEBUG
	std::cout << "Constructor Generator was called" << std::endl;
#endif
	if (!load.is_open())
		{
			throw std::exception("ERROR #8\nYou tried to create object from file, that doesn't exist\n");
		}
	load >> *this;
	this->p_next = nullptr;
	this->p_prev = nullptr;
	Make_Channels(this->Get_amount_of_channels());
}
Generator::Generator(const Generator &device)
{
#ifdef _DEBUG
	std::cout << "Copy Constructor Generator was called\n";
#endif
	this->Set_manufacturer(device.manufacturer);
	this->Set_device_model(device.device_model);
	this->Set_year_of_issue(device.year_of_issue);
	this->Set_amount_of_�hannels(device.amount_of_�hannels);
	this->Set_maximum_output_frequency(device.maximum_output_frequency);
	Make_Channels(this->Get_amount_of_channels());
}
/*Generator::Generator(int amount_of_channels, std::string manufacturer, std::string device_model, int year_of_issue, int maximum_output_frequency, Generator* p_next, Generator* p_prev)
{
#ifdef _DEBUG
	std::cout << "Constructor Generator was called" << std::endl;
#endif

	Set_manufacturer(manufacturer);
	Set_device_model(device_model);
	Set_year_of_issue(year_of_issue);
	Set_maximum_output_frequency(maximum_output_frequency);
	Set_amount_of_�hannels(amount_of_channels);
	this->p_next = p_next;
	this->p_prev = p_prev;

	Make_Channels(amount_of_channels);
}*/
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
		int amount_of_�hannels, year_of_issue, maximum_output_frequency;
		std::string manufacturer, device_model;

		std::cout << "Type amount of channels - ";
		std::cin >> amount_of_�hannels;
		while (std::cin.fail() || amount_of_�hannels < 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Amount of channels must be natural number\nTry again\nAmount of channels - ";
			std::cin >> amount_of_�hannels;
		}

		std::cout << "Type manufacturer - ";
		std::cin >> manufacturer;

		std::cout << "Type device model - ";
		std::cin >> device_model;

		std::cout << "Type year of issue - ";
		std::cin >> year_of_issue;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Year of issue must be natural number\nTry again\nYear of issue - ";
			std::cin >> year_of_issue;
		}

		std::cout << "Type maximum output frequency - ";
		std::cin >> maximum_output_frequency;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Maximum output frequency must be natural number\nTry again\nMaximum output frequency - ";
			std::cin >> maximum_output_frequency;
		}

		Set_manufacturer(manufacturer);
		Set_device_model(device_model);
		Set_year_of_issue(year_of_issue);
		Set_amount_of_�hannels(amount_of_�hannels);
		Set_maximum_output_frequency(maximum_output_frequency);
	}
	else
	{
		int amount_of_�hannels, maximum_output_frequency;

		std::cout << "Type amount of channels - ";
		std::cin >> amount_of_�hannels;
		while (std::cin.fail() || amount_of_�hannels < 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Amount of channels must be natural number\nTry again\nAmount of channels - ";
			std::cin >> amount_of_�hannels;
		}
		std::cout << "Type maximum output frequency - ";
		std::cin >> maximum_output_frequency;
		while (std::cin.fail() || maximum_output_frequency < 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Max output frequency must be natural number\nTry again\nMaximum output frequency - ";
			std::cin >> maximum_output_frequency;
		}

		Set_manufacturer("noname");
		Set_device_model("");
		Set_year_of_issue(1366);
		Set_amount_of_�hannels(amount_of_�hannels);
		Set_maximum_output_frequency(maximum_output_frequency);
	}
}

std::ostream& operator<< (std::ostream &out, Generator &device)
{
	out << "---------" << std::endl
		<< "Generator " << device.Get_manufacturer() << " " << device.Get_device_model()
		<< "(" << device.Get_year_of_issue() << "year)" << " : Amount of channels - "
		<< device.Get_amount_of_channels() << ", Maximum output frequency - "
		<< device.Get_maximum_output_frequency() << " MHz" << std::endl;
	out << "Interface of Generator:\nOutput frequency = " << device.Get_output_frequency() 
		<< " Hz and Peak to Peak Voltage = " << device.Get_peak_to_peak_voltage() << " milliVolts\n";
	for (int i = 0; i < device.Get_amount_of_channels(); i++)
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
	int amount_of_�hannels, year_of_issue, maximum_output_frequency;
	std::string manufacturer, device_model, buff;

	std::getline(in, buff, '\n');
	std::stringstream stream_buff;
	stream_buff << buff;

	stream_buff >> amount_of_�hannels;
	if (amount_of_�hannels < 1)
	{
		throw std::exception("ERROR #11\nIn load_generator.txt amount of channels isn't natural number\n");
		return in;
	}
	if (stream_buff.fail())
	{
		throw std::exception("ERROR #11\nload_generator.txt is broken\n");
		return in;
	}

	stream_buff >> manufacturer;
	if (stream_buff.fail())
	{
		device.Set_manufacturer("noname");
		stream_buff.clear();
		stream_buff.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
	}
	else
		device.Set_manufacturer(manufacturer);

	stream_buff >> device_model;
	if (stream_buff.fail())
	{
		device.Set_device_model(" ");
		stream_buff.clear();
		stream_buff.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
	}
	else
		device.Set_device_model(device_model);

	stream_buff >> year_of_issue;
	if (stream_buff.fail())
	{
		device.Set_year_of_issue(1366);
		stream_buff.clear();
		stream_buff.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
	}
	else
		device.Set_year_of_issue(year_of_issue);

	stream_buff >> maximum_output_frequency;
	if (maximum_output_frequency < 1)
	{
		throw std::exception("ERROR #11\nIn load_generator.txt max output frequency isn't natural number\n");
		return in;
	}
	if (stream_buff.fail())
	{
		throw std::exception("ERROR #11\nload_generator.txt is broken\n");
		return in;
	}

	device.Set_maximum_output_frequency(maximum_output_frequency);
	device.Set_amount_of_�hannels(amount_of_�hannels);
	return in;
}

void Generator::Make_Channels(int amount_of_channels)
{
	Channels_on_off.resize(amount_of_channels);
	Channels_connected.resize(amount_of_channels);
}