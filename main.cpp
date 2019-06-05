// main.cpp

/*TO DO LIST 
1. Сделать класс осциллографов абстрактным
2. Разобраться с конструкторами по умолчанию у всех трех основных классов
3. Найти все возможные места ошибок и добавить исключения
4. Исправить все модификаторы доступа
5. Ограничить шаблонность до только НУЖНЫХ классов
6. Дать пользователю возможность добавлять и высвечивать себе любой элемент контейнера
7. В меню исправить новые конструкторы
*/
#include <iostream>
#include <fstream>
#include "include/Researcher/researcher.h"
#include "include/List/lab_list.h"

using namespace std;
/*
void Init();
void Welcome();
int Get_role();
int Get_type_of_oscilloscope();
int Get_type_of_initialization();
*/

int main()
{
	ofstream save;
	save.exceptions(std::ofstream::badbit | std::ofstream::failbit);

	ifstream load_analog_osc;
	ifstream load_digital_osc;
	ifstream load_gen;
	ifstream load_researcher;
	load_analog_osc.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	load_digital_osc.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	load_gen.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	load_researcher.exceptions(std::ifstream::badbit | std::ifstream::failbit);


	Lab_List <Analog_Oscilloscope> List_of_Analog_Osc;
	Lab_List <Digital_Oscilloscope> List_of_Digital_Osc;
	Lab_List <Generator> List_of_Gen;

	try
	{
		save.open("saved.txt");
	}
	catch (const ofstream::failure &ex)
	{
		cout << "ERROR #9\nCouldn't open the file saved.txt\n";
		cout << ex.what() << std::endl;
		cout << ex.code() << std::endl;
		system("Pause");
	}

	try
	{
		load_analog_osc.open("load_analog_oscilloscope.txt");
	}
	catch (const std::ifstream::failure &ex)
	{
		std::cout << "ERROR #9\nCouldn't open the file load_analog_oscilloscope.txt\n";
		std::cout << ex.what() << std::endl;
		std::cout << ex.code() << std::endl;
		system("Pause");
	}
	try
	{
		load_digital_osc.open("load_digital_oscilloscope.txt");
	}
	catch (const std::ifstream::failure &ex)
	{
		std::cout << "ERROR #9\nCouldn't open the file load_digital_oscilloscope.txt\n";
		std::cout << ex.what() << std::endl;
		std::cout << ex.code() << std::endl;
		system("Pause");
	}
	try
	{
		load_gen.open("load_generator.txt");
	}
	catch (const std::ifstream::failure &ex)
	{
		std::cout << "ERROR #9\nCouldn't open the file load_generator.txt\n";
		std::cout << ex.what() << std::endl;
		std::cout << ex.code() << std::endl;
		system("Pause");
	}
	try
	{
		load_researcher.open("load_researcher.txt");
	}
	catch (const std::ifstream::failure &ex)
	{
		std::cout << "ERROR #9\nCouldn't open the file load_researcher.txt\n";
		std::cout << ex.what() << std::endl;
		std::cout << ex.code() << std::endl;
		system("Pause");
	}

	load_analog_osc >> List_of_Analog_Osc;
	load_digital_osc >> List_of_Digital_Osc;
	cout << List_of_Analog_Osc;
	cout << List_of_Digital_Osc;
	//До этого момента все работает отлично
	List_of_Analog_Osc = List_of_Analog_Osc;
	cout << List_of_Analog_Osc;
	cout << List_of_Digital_Osc;
	//Надобность нижнего сомнительная, т.к. ofstream сам файл создает автоматически
	/* 
	try
{
	if (!save.is_open())
	{
		throw exception("ERROR #9\nYou tried to close file saved.txt, that doesn't exist\n");
	}
	save.close();
}
	catch (const exception &ex)
{
	std::cout << ex.what() << std::endl;
	system("Pause");
}
	*/
	try
	{
		if (!load_analog_osc.is_open())
		{
			throw exception("ERROR #9\nYou tried to close file load_analog_oscilloscope.txt, that doesn't exist\n");
		}
		load_analog_osc.close();
	}
	catch (const exception &ex)
	{
		std::cout << ex.what() << std::endl;
		system("Pause");
	}
	try
	{
		if (!load_digital_osc.is_open())
		{
			throw exception("ERROR #9\nYou tried to close file load_digital_oscilloscope.txt, that doesn't exist\n");
		}
		load_digital_osc.close();
	}
	catch (const exception &ex)
	{
		std::cout << ex.what() << std::endl;
		system("Pause");
	}
	try
	{
		if (!load_gen.is_open())
		{
			throw exception("ERROR #9\nYou tried to close file load_generator.txt, that doesn't exist\n");
		}
		load_gen.close();
	}
	catch (const exception &ex)
	{
		std::cout << ex.what() << std::endl;
		system("Pause");
	}
	try
	{
		if (!load_researcher.is_open())
		{
			throw exception("ERROR #9\nYou tried to close file load_researcher.txt, that doesn't exist\n");
		}
		load_researcher.close();
	}
	catch (const exception &ex)
	{
		std::cout << ex.what() << std::endl;
		system("Pause");
	}
	/*
	ofstream save;
	try
	{
		save.open("saved.txt");
	}
	catch (const ofstream::failure &ex)
	{
		cout << "ERROR #10\nCouldn't open the file saved.txt\n";
		cout << ex.what() << std::endl;
		cout << ex.code() << std::endl;
		system("Pause");
	}

	Welcome();
	switch (Get_role())
	{
		case 1: //Codder
		{
			cout << "Read documetation :)\n";
			break;
		}
		case 2: //User
		{
			switch (Get_type_of_initialization())
			{
				case 1: //Keyboard
				{
					Researcher scientist;
					save << scientist;
					cout << "\nType characterics of Generator:\n";
					Generator gen;
					save << gen;
					switch (Get_type_of_oscilloscope())
					{
						case 1: //Analog osc
						{
							Analog_Oscilloscope osc;
							save << osc;
							bool on_off = true;
							while (on_off == true)
							{
								int menu;
								cout << "What do you want to do?\n1 - Connect Oscilloscope to Generator\n2 - Read signal at Oscilloscope from Generator\n3 - Change seconds scale at Oscilloscope\n"
									<< "4 - Change voltage scale at Oscilloscope\n5 - Change output frequency at Generator\n6 - Change peak to peak voltage at Generator\n"
									<< "7 - Initialiaze everything once more\n8 - Exit\n";
								cin >> menu;
								switch (menu)
								{
								case 1:
								{
									cout << "What channel of Oscilloscope do you want to use?\nChannel #";
									int channel_osc;
									cin >> channel_osc;
									cout << "What channel of Generator do you want to use?\nChannel #";
									int channel_gen;
									cin >> channel_gen;
									scientist.Connect(osc, channel_osc, gen, channel_gen);
									save << osc;
									save << gen;
									break;
								}
								case 2:
								{
									cout << "From what channel of Oscilloscope do you want to read signal?\nChannel #";
									int channel_osc;
									cin >> channel_osc;
									scientist.Read_voltage(osc, channel_osc);
									break;
								}
								case 3:
								{
									cout << "Seconds scale [microSec/div] = ";
									int seconds_scale;
									cin >> seconds_scale;
									osc.Set_seconds_scale(seconds_scale);
									save << osc;
									break;
								}
								case 4:
								{
									cout << "Voltage scale [milliVolts/div] = ";
									int voltage_scale;
									cin >> voltage_scale;
									osc.Set_voltage_scale(voltage_scale);
									save << osc;
									break;
								}
								case 5:
								{
									cout << "Output frequency [Hz] = ";
									int output_frequency;
									cin >> output_frequency;
									gen.Set_output_frequency(output_frequency);
									save << gen;
									break;
								}
								case 6:
								{
									cout << "Peak to peak voltage [milliVolts] = ";
									int peak_to_peak_voltage;
									cin >> peak_to_peak_voltage;
									gen.Set_peak_to_peak_voltage(peak_to_peak_voltage);
									save << gen;
									break;
								}
								case 7:
								{
									Init();
									break;
								}
								case 8:
								{
									on_off = false;
									break;
								}
								}
							}
							break;
						}
						case 2: //Digital osc
						{
							Digital_Oscilloscope osc;
							save << osc;
							bool on_off = true;
							while (on_off == true)
							{
								int menu;
								cout << "What do you want to do?\n1 - Connect Oscilloscope to Generator\n2 - Read signal at Oscilloscope from Generator\n3 - Change seconds scale at Oscilloscope\n"
									<< "4 - Change voltage scale at Oscilloscope\n5 - Change output frequency at Generator\n6 - Change peak to peak voltage at Generator\n"
									<< "7 - Initialiaze everything once more\n8 - Exit\n";
								cin >> menu;
								switch (menu)
								{
								case 1:
								{
									cout << "What channel of Oscilloscope do you want to use?\nChannel #";
									int channel_osc;
									cin >> channel_osc;
									cout << "What channel of Generator do you want to use?\nChannel #";
									int channel_gen;
									cin >> channel_gen;
									scientist.Connect(osc, channel_osc, gen, channel_gen);
									save << osc;
									save << gen;
									break;
								}
								case 2:
								{
									cout << "From what channel of Oscilloscope do you want to read signal?\nChannel #";
									int channel_osc;
									cin >> channel_osc;
									scientist.Read_voltage(osc, channel_osc);
									break;
								}
								case 3:
								{
									cout << "Seconds scale [microSec/div] = ";
									int seconds_scale;
									cin >> seconds_scale;
									osc.Set_seconds_scale(seconds_scale);
									save << osc;
									break;
								}
								case 4:
								{
									cout << "Voltage scale [milliVolts/div] = ";
									int voltage_scale;
									cin >> voltage_scale;
									osc.Set_voltage_scale(voltage_scale);
									save << osc;
									break;
								}
								case 5:
								{
									cout << "Output frequency [Hz] = ";
									int output_frequency;
									cin >> output_frequency;
									gen.Set_output_frequency(output_frequency);
									save << gen;
									break;
								}
								case 6:
								{
									cout << "Peak to peak voltage [milliVolts] = ";
									int peak_to_peak_voltage;
									cin >> peak_to_peak_voltage;
									gen.Set_peak_to_peak_voltage(peak_to_peak_voltage);
									save << gen;
									break;
								}
								case 7:
								{
									Init();
									break;
								}
								case 8:
								{
									on_off = false;
									break;
								}
								}
							}
							break;
						}
					}
					break;
				}
				case 2: //File
				{
					Researcher scientist(true);
					save << scientist;
					cout << scientist;
					Generator gen(true);
					save << gen;
					cout << gen;
					switch (Get_type_of_oscilloscope())
					{
						case 1: //Analog osc
						{
							Analog_Oscilloscope osc(true);
							save << osc;
							cout << osc;
							bool on_off = true;
							while (on_off == true)
							{
								int menu;
								cout << "What do you want to do?\n1 - Connect Oscilloscope to Generator\n2 - Read signal at Oscilloscope from Generator\n3 - Change seconds scale at Oscilloscope\n"
									<< "4 - Change voltage scale at Oscilloscope\n5 - Change output frequency at Generator\n6 - Change peak to peak voltage at Generator\n"
									<< "7 - Initialiaze everything once more\n8 - Exit\n";
								cin >> menu;
								switch (menu)
								{
									case 1:
									{
										cout << "What channel of Oscilloscope do you want to use?\nChannel #";
										int channel_osc;
										cin >> channel_osc;
										cout << "What channel of Generator do you want to use?\nChannel #";
										int channel_gen;
										cin >> channel_gen;
										scientist.Connect(osc, channel_osc, gen, channel_gen);
										save << osc;
										save << gen;
										break;
									}
									case 2:
									{
										cout << "From what channel of Oscilloscope do you want to read signal?\nChannel #";
										int channel_osc;
										cin >> channel_osc;
										scientist.Read_voltage(osc, channel_osc);
										break;
									}
									case 3:
									{
										cout << "Seconds scale [microSec/div] = ";
										int seconds_scale;
										cin >> seconds_scale;
										osc.Set_seconds_scale(seconds_scale);
										save << osc;
										break;
									}
									case 4:
									{
										cout << "Voltage scale [milliVolts/div] = ";
										int voltage_scale;
										cin >> voltage_scale;
										osc.Set_voltage_scale(voltage_scale);
										save << osc;
										break;
									}
									case 5:
									{
										cout << "Output frequency [Hz] = ";
										int output_frequency;
										cin >> output_frequency;
										gen.Set_output_frequency(output_frequency);
										save << gen;
										break;
									}
									case 6:
									{
										cout << "Peak to peak voltage [milliVolts] = ";
										int peak_to_peak_voltage;
										cin >> peak_to_peak_voltage;
										gen.Set_peak_to_peak_voltage(peak_to_peak_voltage);
										save << gen;
										break;
									}
									case 7:
									{
										Init();
										break;
									}
									case 8:
									{
										on_off = false;
										break;
									}
								}
							}
							break;
						}
						case 2: //Digital osc
						{
							Digital_Oscilloscope osc(true);
							save << osc;
							cout << osc;
							bool on_off = true;
							while (on_off == true)
							{
								int menu;
								cout << "What do you want to do?\n1 - Connect Oscilloscope to Generator\n2 - Read signal at Oscilloscope from Generator\n3 - Change seconds scale at Oscilloscope\n"
									<< "4 - Change voltage scale at Oscilloscope\n5 - Change output frequency at Generator\n6 - Change peak to peak voltage at Generator\n"
									<< "7 - Initialiaze everything once more\n8 - Exit\n";
								cin >> menu;
								switch (menu)
								{
								case 1:
								{
									cout << "What channel of Oscilloscope do you want to use?\nChannel #";
									int channel_osc;
									cin >> channel_osc;
									cout << "What channel of Generator do you want to use?\nChannel #";
									int channel_gen;
									cin >> channel_gen;
									scientist.Connect(osc, channel_osc, gen, channel_gen);
									save << osc;
									save << gen;
									break;
								}
								case 2:
								{
									cout << "From what channel of Oscilloscope do you want to read signal?\nChannel #";
									int channel_osc;
									cin >> channel_osc;
									scientist.Read_voltage(osc, channel_osc);
									break;
								}
								case 3:
								{
									cout << "Seconds scale [microSec/div] = ";
									int seconds_scale;
									cin >> seconds_scale;
									osc.Set_seconds_scale(seconds_scale);
									save << osc;
									break;
								}
								case 4:
								{
									cout << "Voltage scale [milliVolts/div] = ";
									int voltage_scale;
									cin >> voltage_scale;
									osc.Set_voltage_scale(voltage_scale);
									save << osc;
									break;
								}
								case 5:
								{
									cout << "Output frequency [Hz] = ";
									int output_frequency;
									cin >> output_frequency;
									gen.Set_output_frequency(output_frequency);
									save << gen;
									break;
								}
								case 6:
								{
									cout << "Peak to peak voltage [milliVolts] = ";
									int peak_to_peak_voltage;
									cin >> peak_to_peak_voltage;
									gen.Set_peak_to_peak_voltage(peak_to_peak_voltage);
									save << gen;
									break;
								}
								case 7:
								{
									Init();
									break;
								}
								case 8:
								{
									on_off = false;
									break;
								}
								}
							}
							break;
						}
					}
					break;
				}
			}
			break;
		}
	}
	save.close();
	*/
	system("Pause");
	return 0;
} 
/*
void Welcome()
{

	cout << "Hello everynyan, I'm your Guide to this world of Oscilloscopes\nFirst of all choose your role\n1 - Codder\n2 - User\n";

}
int Get_role()
{
	int choose_your_role;
	cin >> choose_your_role;
	return choose_your_role;
}
int Get_type_of_oscilloscope()
{
	cout << "Do you have Analog or Digital Oscilloscope?\n1 - Analog\n2 - Digital\n";
	int choose_your_oscilloscope;
	cin >> choose_your_oscilloscope;
	return choose_your_oscilloscope;
}
int Get_type_of_initialization()
{
	cout << "How do you want to initialise all objects?\n1 - From keyboard\n2 - From file\n";
	int choose_type_of_initialization;
	cin >> choose_type_of_initialization;
	return choose_type_of_initialization;
}
void Init()
{
	Welcome();
	switch (Get_role())
	{
	case 1: //Codder
	{
		cout << "Read documetation :)\n";
		break;
	}
	case 2: //User
	{
		switch (Get_type_of_initialization())
		{
		case 1: //Keyboard
		{
			Researcher scientist;
			switch (Get_type_of_oscilloscope())
			{
			case 1: //Analog osc
			{
				Analog_Oscilloscope osc;
				break;
			}
			case 2: //Digital osc
			{
				Digital_Oscilloscope osc;
				break;
			}
			}
			cout << "\nType characterics of Generator:\n";
			Generator gen;
			break;
		}
		case 2: //File
		{
			Researcher scientist(true);
			cout << scientist;
			switch (Get_type_of_oscilloscope())
			{
			case 1: //Analog osc
			{
				Analog_Oscilloscope osc(true);
				cout << osc;
				break;
			}
			case 2: //Digital osc
			{
				Digital_Oscilloscope osc(true);
				cout << osc;
				break;
			}
			}
			Generator gen(true);
			cout << gen;
			break;
		}
		}
		break;
	}
	}
}
*/