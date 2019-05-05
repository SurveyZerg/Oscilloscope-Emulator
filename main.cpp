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
#include "researcher.h"

using namespace std;

int main()
{
	// ������������� ������������ ������������� � ����������� � �������������
	Researcher Andrew("Leading researcher", "Andrew", "Werner", 24);
	Researcher N;
	Analog_Oscilloscope Device_1(2, 8, 8, "B&K Precision", "2125C", 1997, 2); //Characteristics may be unreliable
	Digital_Oscilloscope Device_2(2, 8, 10, "Siglent", "SDS1202X-E", 2016, 14); //Characteristics may be unreliable
	Generator Device_3(2, "Siglent", "SDG1025", 2015, 25); //Characteristics may be unreliable
	Generator Device_4(1);
	// ���������� ��������� <<, ����� ����� ������� �������� ��� ���������� � ��������
	cout << N;
	cout << Andrew;
	cout << Device_1;
	cout << Device_2;
	cout << Device_3;
	cout << Device_4;
	//������� �������� �������� �������� �� ������ ������� � ����������� ������������� ���������� ������������ � �����������

	Andrew.Connect(Device_1, 2, Device_3, 1);
	Andrew.Connect(Device_1, 1, Device_3, 1);
	system("Pause");
	return 0;
} 