//researcher.cpp

#include <fstream>
#include <ctime>
#include "researcher.h"

Researcher::Researcher()
{
	this->Type_information(true);
}
Researcher::Researcher(bool file_reading)
{
	std::ifstream load;
	load.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	try
	{
		load.open("load_researcher.txt");
	}
	catch (const std::ifstream::failure &ex)
	{
		std::cout << "ERROR #9\nCouldn't open the file load.txt\n";
		std::cout << ex.what() << std::endl;
		std::cout << ex.code() << std::endl;
	}
	load >> *this;
	load.close();
}
Researcher::Researcher(std::string research_position, std::string name, std::string surname, int age)
{
#ifdef _DEBUG
	std::cout << "Constructor Researcher was called" << std::endl;
#endif

	this->research_position = research_position;
	this->name = name;
	this->surname = surname;
	this->age = age;
}
Researcher::~Researcher()
{
#ifdef _DEBUG
	std::cout << "Default Destructor Researcher was called" << std::endl;
#endif
}

void Researcher::Type_information(bool all_information)
{
	if (all_information)
	{
		int age, research_position;
		std::string name,surname;
		std::cout << "Choose your research postion:\n1 - Junior researcher\n2 - Researcher\n3 - Senior researcher\n4 - Leading researcher\n5 - Principal researcher\n";
		std::cin >> research_position;
		if (research_position == 1)
		{
			this->research_position = "Junior researcher";
		}
		if (research_position == 2)
		{
			this->research_position = "Researcher";
		}
		if (research_position == 3)
		{
			this->research_position = "Senior researcher";
		}
		if (research_position == 4)
		{
			this->research_position = "Leading researcher";
		}
		if (research_position == 5)
		{
			this->research_position = "Principal researcher";
		}
		std::cout << "Type your name: ";
		std::cin >> name;
		std::cout << "Type your surname: ";
		std::cin >> surname;
		std::cout << "Type your age: ";
		std::cin >> age;

		this->name = name;
		this->surname = surname;
		this->age = age;
	}
	else
	{
		this->research_position = "Mr.";
		this->name = "Noname";
		this->surname = "";
		this->age = 999;
	}
}

std::string Researcher :: Get_research_position()
{
	return research_position;
}
std::string Researcher :: Get_name()
{
	return name;
}
std::string Researcher :: Get_surname()
{
	return surname;
}
int Researcher :: Get_age()
{
	return age;
}

std::ostream& operator<< (std::ostream &out, Researcher &scientist)
{
	out << "---------" << std::endl << scientist.Get_research_position() << " " << scientist.Get_surname() << " " << scientist.Get_name() << "(age "
		<< scientist.Get_age() << ")" << std::endl <<"---------" << std::endl;
	return out;
}
std::istream& operator >> (std::istream &in, Researcher &scientist)
{
	int age;
	std::string research_position, name, surname;
	std::getline(in,research_position);
	std::getline(in, name);
	std::getline(in, surname);
	in >> age;

	scientist.research_position = research_position;
	scientist.name = name;
	scientist.surname = surname;
	scientist.age = age;

	return in;
}

void Researcher::Connect(Oscilloscope &osc, int number_of_channel_osc, Generator &gen, int number_of_channel_gen)
{
	//�������� �� ������
	if (number_of_channel_osc > osc.Get_amount_of_�hannels() || number_of_channel_osc < 1)
	{
		std::cout << "ERROR #1\nYou picked channel of Oscilloscope, that doesn't exist\n";
		system("Pause");
		exit(EXIT_FAILURE); //�������� �� ��� �����������, ��� ���������?
	}
	if (number_of_channel_gen > gen.Get_amount_of_�hannels() || number_of_channel_gen < 1)
	{
		std::cout << "ERROR #2\nYou picked channel of Generator, that doesn't exist\n";
		system("Pause");
		exit(EXIT_FAILURE); //�������� �� ��� �����������, ��� ���������?
	}
	if (osc.Get_connection_of_channel(number_of_channel_osc) == true)
	{
		std::cout << "ERROR #3\nYou picked channel of Oscilloscope, that is already busy\n";
		system("Pause");
		exit(EXIT_FAILURE); //�������� �� ��� �����������, ��� ���������?
	}
	if (gen.Get_connection_of_channel(number_of_channel_gen) == true)
	{
		std::cout << "ERROR #4\nYou picked channel of Generator, that is already busy\n";
		system("Pause");
		exit(EXIT_FAILURE); //�������� �� ��� �����������, ��� ���������?
	}

	//�����������
	osc.Set_connection_of_channel(number_of_channel_osc, true, &gen);
	gen.Set_connection_of_channel(number_of_channel_gen, true, &osc);

	if ((1000000 / gen.Get_output_frequency()) < (osc.Get_seconds_scale() * osc.Get_seconds_divisions()) && gen.Get_peak_to_peak_voltage() < (osc.Get_voltage_scale() * osc.Get_voltage_divisions())) // ��� ���������� ��������� �����, ����� ��� ����� ����-�� ���� ������ ������� 1Hz - 1000000 microSec
	{
		std::cout << "Connection of Generator " <<gen.Get_manufacturer()<< " " <<gen.Get_device_model() << " and Oscilloscope "<<osc.Get_manufacturer() << " " << osc.Get_device_model() << " Successfully completed\n";
	}
	else if ((1000000 / gen.Get_output_frequency()) > (osc.Get_seconds_scale() * osc.Get_seconds_divisions()) && gen.Get_peak_to_peak_voltage() < (osc.Get_voltage_scale() * osc.Get_voltage_divisions()))
	{
		std::cout << "Connection of Generator " << gen.Get_manufacturer() << " " << gen.Get_device_model() << " and Oscilloscope " << osc.Get_manufacturer() << " " << osc.Get_device_model() << " Successfully completed, but you can't read the signal, because at least one period of the sinusoid is't visible\nYou can change seconds scale to fix it\n";
	}
	else if ((1000000 / gen.Get_output_frequency()) < (osc.Get_seconds_scale() * osc.Get_seconds_divisions()) && gen.Get_peak_to_peak_voltage() > (osc.Get_voltage_scale() * osc.Get_voltage_divisions()))
	{
		std::cout << "Connection of Generator " << gen.Get_manufacturer() << " " << gen.Get_device_model() << " and Oscilloscope " << osc.Get_manufacturer() << " " << osc.Get_device_model() << " Successfully completed, but you can't read the signal, because amplitude of the sinusoid is't visible\nYou can change voltage scale to fix it\n";
	}
	else if ((1000000 / gen.Get_output_frequency()) > (osc.Get_seconds_scale() * osc.Get_seconds_divisions()) && gen.Get_peak_to_peak_voltage() > (osc.Get_voltage_scale() * osc.Get_voltage_divisions()))
	{
		std::cout << "Connection of Generator " << gen.Get_manufacturer() << " " << gen.Get_device_model() << " and Oscilloscope " << osc.Get_manufacturer() << " " << osc.Get_device_model() << " Successfully completed, but you can't read the signal, because at least one period and amplitude of the sinusoid aren't visible\nYou can change voltage and seconds scale to fix it\n";
	}
}
void Researcher::Read_voltage(Oscilloscope &osc, int number_of_channel)
{
	if (osc.Get_connection_of_channel(number_of_channel))
	{
		srand(time(0));
		int random_number = -100 + rand() % 100; //�������� ����������� ������������
		if ((1000000 / osc.Get_connected_generator(number_of_channel)->Get_output_frequency()) < (osc.Get_seconds_scale() * osc.Get_seconds_divisions()) && osc.Get_connected_generator(number_of_channel)->Get_peak_to_peak_voltage() < (osc.Get_voltage_scale() * osc.Get_voltage_divisions()))
		{
			std::cout << "Peak to Peak Voltage is " << osc.Get_connected_generator(number_of_channel)->Get_peak_to_peak_voltage() + random_number << " milliVolts" << std::endl;
			std::cout << "RMS Voltage is " << ((osc.Get_connected_generator(number_of_channel)->Get_peak_to_peak_voltage() + random_number) / 2.8) << " milliVolts" << std::endl;
		}
		else if ((1000000 / osc.Get_connected_generator(number_of_channel)->Get_output_frequency()) > (osc.Get_seconds_scale() * osc.Get_seconds_divisions()) && osc.Get_connected_generator(number_of_channel)->Get_peak_to_peak_voltage() < (osc.Get_voltage_scale() * osc.Get_voltage_divisions()))
		{
			std::cout << "ERROR #5\nYou can't read the Peak to Peak and RMS Voltage, because at least one period of the sinusoid is't visible\nYou can change seconds scale to fix it\n";
		}
		else if ((1000000 / osc.Get_connected_generator(number_of_channel)->Get_output_frequency()) < (osc.Get_seconds_scale() * osc.Get_seconds_divisions()) && osc.Get_connected_generator(number_of_channel)->Get_peak_to_peak_voltage() > (osc.Get_voltage_scale() * osc.Get_voltage_divisions()))
		{
			std::cout << "ERROR #6\nYou can't read the Peak to Peak and RMS Voltage, because amplitude of the sinusoid is't visible\nYou can change voltage scale to fix it\n";
		}
		else if ((1000000 / osc.Get_connected_generator(number_of_channel)->Get_output_frequency()) > (osc.Get_seconds_scale() * osc.Get_seconds_divisions()) && osc.Get_connected_generator(number_of_channel)->Get_peak_to_peak_voltage() > (osc.Get_voltage_scale() * osc.Get_voltage_divisions()))
		{
			std::cout << "ERROR #5 and ERROR #6\nYou can't read the Peak to Peak and RMS Voltage, because at least one period and amplitude of the sinusoid aren't visible\nYou can change seconds and voltage scale to fix it\n";
		}
	}
	else
	{
		std::cout << "ERROR #7\nYou tried to read signal from channel, that isn't connected to anything\n";
	}
}