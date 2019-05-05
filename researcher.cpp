//researcher.cpp

#include <ctime>
#include "researcher.h"

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
		std::cout << "Connection of Generator " << gen.Get_manufacturer() << " " << gen.Get_device_model() << " and Oscilloscope " << osc.Get_manufacturer() << " " << osc.Get_device_model() << " Successfully completed, but you can't read the signal, because at least one period and amplitude of the sinusoid is't visible\nYou can change voltage and seconds scale to fix it\n";
	}
}
void Researcher::Read_voltage(Oscilloscope &osc, int number_of_channel)
{
	srand(time(0));
	int random_number = -100 + rand() % 100; //�������� ����������� ������������
	if ((1000000 / osc.Get_connected_generator(number_of_channel)->Get_output_frequency()) < (osc.Get_seconds_scale() * osc.Get_seconds_divisions()) && osc.Get_connected_generator(number_of_channel)->Get_peak_to_peak_voltage() < (osc.Get_voltage_scale() * osc.Get_voltage_divisions()))
	{
		std::cout <<"Peak to Peak Voltage is "<< osc.Get_connected_generator(number_of_channel)->Get_peak_to_peak_voltage() + random_number <<" milliVolts"<< std::endl;
	}
}