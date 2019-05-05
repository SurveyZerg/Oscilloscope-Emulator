// main.cpp
// Программа с примерами использования всех возможностей библиотеки Осциллографа

/*  
Возможности моей программы:
	1 - Инициализация генераторов, осциллографов и человека, который управляет всем этим добром
		Сделать вы это можете при помощи данных команд:
			Исследователь:
				Researcher Имя_Исследователя (research_position, name, surname, age)
				Если вам не известно ваша должность исследователя, имя, фамилия и возраст, то можете просто не вписывать никаких
				параметров, к вам будут обращаться "Mr. Noname"
			Аналоговый Осциллограф:
				Analog_Oscilloscope Имя_Осциллографа (amount_of_сhannels, voltage_divisions, seconds_divisions, manufacturer, device_model, year_of_issue, amount_of_beams)
				Если вам неизвестен производитель, модель, год выпуска или кол-во лучей - не страшно. Вписывайте так:
				Analog_Oscilloscope Имя_Осциллографа (amount_of_сhannels, voltage_divisions, seconds_divisions)
				Кол-во каналов, а также кол-во делений необходимо знать для корректной работы программы, поэтому данный параметр необходимо вписать
			Цифровой Осциллограф:
				Digital_Oscilloscope Имя_Осциллографа (amount_of_сhannels, voltage_divisions, seconds_divisions, manufacturer, device_model, year_of_issue, memory_depth)
				Если вам неизвестен производитель, модель, год выпуска или кол-во памяти - не страшно. Вписывайте так:
				Digital_Oscilloscope Имя_Осциллографа (amount_of_сhannels, voltage_divisions, seconds_divisions)
				Кол-во каналов, а также кол-во делений необходимо знать для корректной работы программы, поэтому данный параметр необходимо вписать
			Генератор:
				Generator Имя_Генератора(manufacturer, device_model, year_of_issue, maximum_output_frequency)
				Если вам неизвестен производитель, модель, год выпуска или кол-во памяти - не страшно. Вписывайте так:
				Generator Имя_Генератора (amount_of_сhannels)
				Кол-во каналов необходимо знать для корректной работы программы, поэтому данный параметр необходимо вписать
	2 - Вывод всей информации о данных устройствах или человеке в консоль
		Сделать это можно при помощи команды cout << Имя_Осциллографа\Имя_Генератора\Имя_Исследователя
		Тогда будет выведена вся вписанная вами информация о данных устройствах.
*/
#include <iostream>
#include <fstream>
#include "researcher.h"

using namespace std;

int main()
{
	// Инициализация подключенных Осциллографов и Генераторов и Исследователя
	Researcher Andrew("Leading researcher", "Andrew", "Werner", 24);
	Analog_Oscilloscope Device_1(2, 8, 8, "B&K Precision", "2125C", 1997, 2); //Characteristics may be unreliable
	Digital_Oscilloscope Device_2(2, 8, 10, "Siglent", "SDS1202X-E", 2016, 14); //Characteristics may be unreliable
	Generator Device_3(2, "Siglent", "SDG1025", 2015, 25); //Characteristics may be unreliable
	// Перегрузку оператора <<, чтобы одним сиаутом выводить всю информацию о приборах
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




	//Функции создания массивов проводов на основе каналов и возможность исследователя подключать осциллографы к генераторам

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