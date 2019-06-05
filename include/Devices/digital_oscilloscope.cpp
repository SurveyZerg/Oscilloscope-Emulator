//digital_oscilloscope.cpp

#include <sstream>
#include "digital_oscilloscope.h"
#include "generator.h"

void Digital_Oscilloscope::Set_memory_depth(int memory_depth)
{
	this->memory_depth = memory_depth;
}

int Digital_Oscilloscope::Get_memory_depth()
{
	return memory_depth;
}

Digital_Oscilloscope::Digital_Oscilloscope()
{
#ifdef _DEBUG
	std::cout << "Default Constructor Digital Oscilloscope was called" << std::endl;
#endif
	this->p_next = nullptr;
	this->p_prev = nullptr;
}

Digital_Oscilloscope::Digital_Oscilloscope(bool all_info)
{
#ifdef _DEBUG
	std::cout << "Constructor Digital Oscilloscope was called" << std::endl;
#endif
	this->Type_information(all_info);
	this->p_next = nullptr;
	this->p_prev = nullptr;
	Make_Channels(Get_amount_of_ñhannels());
}
Digital_Oscilloscope::Digital_Oscilloscope(std::ifstream& load)
{
	//Íåëüçÿ ýòî èñïîëüçîâàòü â îòäåëüíîñòè, òîëüêî ñ áëîêîì òðàé êåò÷

#ifdef _DEBUG
	std::cout << "Constructor Digital Oscilloscope was called" << std::endl;
#endif
	if (!load.is_open())
	{
		throw std::exception("ERROR #9\nYou tried to create object from file, that doesn't exist\n");
	}
	load >> *this;
	this->p_next = nullptr;
	this->p_prev = nullptr;
	Make_Channels(this->Get_amount_of_ñhannels());
}
/*Digital_Oscilloscope::Digital_Oscilloscope(int amount_of_ñhannels, int voltage_divisions, int seconds_divisions, std::string manufacturer, std::string device_model, int year_of_issue,  int memory_depth, Digital_Oscilloscope* p_next, Digital_Oscilloscope* p_prev)
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
	this->p_next = p_next;
	this->p_prev = p_prev;

	Make_Channels(amount_of_ñhannels);
}*/
Digital_Oscilloscope::Digital_Oscilloscope(const Digital_Oscilloscope &device)
{
#ifdef _DEBUG
	std::cout << "Copy Constructor Digital Ocilloscope was called\n";
#endif
	this->Set_manufacturer(device.manufacturer);
	this->Set_device_model(device.device_model);
	this->Set_year_of_issue(device.year_of_issue);
	this->Set_amount_of_ñhannels(device.amount_of_ñhannels);
	this->Set_memory_depth(device.memory_depth);
	this->Set_voltage_divisions(device.voltage_divisions);
	this->Set_seconds_divisions(device.seconds_divisions);
	Make_Channels(this->Get_amount_of_ñhannels());
}
Digital_Oscilloscope::~Digital_Oscilloscope()
{
#ifdef _DEBUG
	std::cout << "Destructor Digital Oscilloscope was called" << std::endl;
#endif
}

void Digital_Oscilloscope::Type_information(bool all_information)
{
	if (all_information)
	{
		int amount_of_ñhannels, voltage_divisions, seconds_divisions, year_of_issue, memory_depth;
		std::string manufacturer, device_model;

		std::cout << "Type amount of channels - ";
		std::cin >> amount_of_ñhannels;
		while (std::cin.fail() || amount_of_ñhannels < 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Amount of channels must be natural number\nTry again\nAmount of channels - ";
			std::cin >> amount_of_ñhannels;
		}

		std::cout << "Type voltage divisions (Oy) - ";
		std::cin >> voltage_divisions;
		while (std::cin.fail() || voltage_divisions < 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Voltage divisions must be natural number\nTry again\nVoltage divisions - ";
			std::cin >> voltage_divisions;
		}

		std::cout << "Type seconds divisions (Ox) - ";
		std::cin >> seconds_divisions;
		while (std::cin.fail() || seconds_divisions < 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Seconds divisions must be natural number\nTry again\nSeconds divisions - ";
			std::cin >> seconds_divisions;
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

		std::cout << "Type memory depth - ";
		std::cin >> memory_depth;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Memory depth must be natural number\nTry again\nMemory depth - ";
			std::cin >> memory_depth;
		}


		Set_manufacturer(manufacturer);
		Set_device_model(device_model);
		Set_year_of_issue(year_of_issue);
		Set_amount_of_ñhannels(amount_of_ñhannels);
		Set_memory_depth(memory_depth);
		Set_voltage_divisions(voltage_divisions);
		Set_seconds_divisions(seconds_divisions);
	}
	else
	{
		int amount_of_ñhannels, voltage_divisions, seconds_divisions;

		std::cout << "Type amount of channels - ";
		std::cin >> amount_of_ñhannels;
		while (std::cin.fail() || amount_of_ñhannels < 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Amount of channels must be natural number\nTry again\nAmount of channels - ";
			std::cin >> amount_of_ñhannels;
		}

		std::cout << "Type voltage divisions (Oy) - ";
		std::cin >> voltage_divisions;
		while (std::cin.fail() || voltage_divisions < 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Voltage divisions must be natural number\nTry again\nVoltage divisions - ";
			std::cin >> voltage_divisions;
		}

		std::cout << "Type seconds divisions (Ox) - ";
		std::cin >> seconds_divisions;
		while (std::cin.fail() || seconds_divisions < 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Seconds divisions must be natural number\nTry again\nSeconds divisions - ";
			std::cin >> seconds_divisions;
		}

		Set_manufacturer("noname");
		Set_device_model("");
		Set_year_of_issue(1366);
		Set_amount_of_ñhannels(amount_of_ñhannels);
		Set_memory_depth(14);
		Set_voltage_divisions(voltage_divisions);
		Set_seconds_divisions(seconds_divisions);
	}
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
	std::string manufacturer, device_model, buff;

	std::getline(in, buff, '\n');
	std::stringstream stream_buff;
	stream_buff << buff;

	stream_buff >> amount_of_ñhannels;
	if (amount_of_ñhannels < 1)
	{
		throw std::exception("ERROR # \nIn load_digital_oscilloscope.txt amount of channels isn't natural number\n");
		return in;
	}
	stream_buff >> voltage_divisions;
	if (amount_of_ñhannels < 1)
	{
		throw std::exception("ERROR # \nIn load_digital_oscilloscope.txt voltage divisions aren't natural number\n");
		return in;
	}
	stream_buff >> seconds_divisions;
	if (amount_of_ñhannels < 1)
	{
		throw std::exception("ERROR # \nIn load_digital_oscilloscope.txt seconds divisions aren't natural number\n");
		return in;
	}
	stream_buff >> manufacturer;
	stream_buff >> device_model;
	stream_buff >> year_of_issue;
	stream_buff >> memory_depth;

	device.Set_manufacturer(manufacturer);
	device.Set_device_model(device_model);
	device.Set_year_of_issue(year_of_issue);
	device.Set_amount_of_ñhannels(amount_of_ñhannels);
	device.Set_memory_depth(memory_depth);
	device.Set_voltage_divisions(voltage_divisions);
	device.Set_seconds_divisions(seconds_divisions);
	return in;
}

