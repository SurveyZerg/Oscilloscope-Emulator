// main.cpp
// ��������� � ��������� ������������� ���� ������������ ���������� ������������

/*  
����������� ���� ���������:
	1 - ������������� �����������, ������������� � ��������, ������� ��������� ���� ���� ������
		������� �� ��� ������ ��� ������ ������ ������:
			�������������:
				Researcher ���_������������� (research_position, name, surname, age)
				���� ��� �� �������� ���� ��������� �������������, ���, ������� � �������, �� ������ ������ �� ��������� �������
				����������, � ��� ����� ���������� "Mr. Noname"
			���������� �����������:
				Analog_Oscilloscope ���_������������ (amount_of_�hannels, voltage_divisions, seconds_divisions, manufacturer, device_model, year_of_issue, amount_of_beams)
				���� ��� ���������� �������������, ������, ��� ������� ��� ���-�� ����� - �� �������. ���������� ���:
				Analog_Oscilloscope ���_������������ (amount_of_�hannels, voltage_divisions, seconds_divisions)
				���-�� �������, � ����� ���-�� ������� ���������� ����� ��� ���������� ������ ���������, ������� ������ �������� ���������� �������
			�������� �����������:
				Digital_Oscilloscope ���_������������ (amount_of_�hannels, voltage_divisions, seconds_divisions, manufacturer, device_model, year_of_issue, memory_depth)
				���� ��� ���������� �������������, ������, ��� ������� ��� ���-�� ������ - �� �������. ���������� ���:
				Digital_Oscilloscope ���_������������ (amount_of_�hannels, voltage_divisions, seconds_divisions)
				���-�� �������, � ����� ���-�� ������� ���������� ����� ��� ���������� ������ ���������, ������� ������ �������� ���������� �������
			���������:
				Generator ���_����������(manufacturer, device_model, year_of_issue, maximum_output_frequency)
				���� ��� ���������� �������������, ������, ��� ������� ��� ���-�� ������ - �� �������. ���������� ���:
				Generator ���_���������� (amount_of_�hannels)
				���-�� ������� ���������� ����� ��� ���������� ������ ���������, ������� ������ �������� ���������� �������
	2 - ����� ���� ���������� � ������ ����������� ��� �������� � �������
		������� ��� ����� ��� ������ ������� cout << ���_������������\���_����������\���_�������������
		����� ����� �������� ��� ��������� ���� ���������� � ������ �����������.
*/
#include <iostream>
#include <fstream>
#include "researcher.h"

using namespace std;

int main()
{
	// ������������� ������������ ������������� � ����������� � �������������
	Researcher Andrew("Leading researcher", "Andrew", "Werner", 24);
	Analog_Oscilloscope Device_1(2, 8, 8, "B&K Precision", "2125C", 1997, 2); //Characteristics may be unreliable
	Digital_Oscilloscope Device_2(2, 8, 10, "Siglent", "SDS1202X-E", 2016, 14); //Characteristics may be unreliable
	Generator Device_3(2, "Siglent", "SDG1025", 2015, 25); //Characteristics may be unreliable
	// ���������� ��������� <<, ����� ����� ������� �������� ��� ���������� � ��������
	ofstream save;
	save.open("saved.txt");
	save << Device_1;
	save << Device_2;
	save << Device_3;
	Andrew.Connect(Device_1, 1, Device_3, 1);
	Andrew.Connect(Device_2, 1, Device_3, 2);
	save << Device_1;
	save << Device_2;
	save << Device_3;




	//������� �������� �������� �������� �� ������ ������� � ����������� ������������� ���������� ������������ � �����������

	Device_3.Set_signal(2000,6000);
	Andrew.Connect(Device_2, 2, Device_3, 1);

	Device_2.Get_connection_of_channel(2, "yes");
	Device_3.Get_connection_of_channel(1, "yes");
	Device_3.Get_connection_of_channel(2, "yes");
	Device_2.Get_connection_of_channel(1, "yes");

	Device_2.Set_voltage_scale(500);
	Device_2.Set_seconds_scale(10);
	Andrew.Connect(Device_2, 1, Device_3, 2);

	Device_2.Set_seconds_scale(500);
	Device_2.Set_voltage_scale(6000);
	Andrew.Read_voltage(Device_2, 2);
	Andrew.Read_voltage(Device_1, 2);

	Device_3.Set_signal(1000, 2000);
	Andrew.Read_voltage(Device_2, 2);
	system("Pause");
	return 0;
} 