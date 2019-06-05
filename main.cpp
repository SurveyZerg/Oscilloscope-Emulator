// main.cpp

/*TO DO LIST 
1. Ñäåëàòü êëàññ îñöèëëîãðàôîâ àáñòðàêòíûì
2. Ðàçîáðàòüñÿ ñ êîíñòðóêòîðàìè ïî óìîë÷àíèþ ó âñåõ òðåõ îñíîâíûõ êëàññîâ
3. Íàéòè âñå âîçìîæíûå ìåñòà îøèáîê è äîáàâèòü èñêëþ÷åíèÿ
4. Èñïðàâèòü âñå ìîäèôèêàòîðû äîñòóïà
5. Îãðàíè÷èòü øàáëîííîñòü äî òîëüêî ÍÓÆÍÛÕ êëàññîâ
6. Äàòü ïîëüçîâàòåëþ âîçìîæíîñòü äîáàâëÿòü è âûñâå÷èâàòü ñåáå ëþáîé ýëåìåíò êîíòåéíåðà
7. Â ìåíþ èñïðàâèòü íîâûå êîíñòðóêòîðû
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
	//SETUP

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
	Researcher scientist;

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
  
	// MAIN PROGRAM CYCLE
	bool end = false;
	bool setup = true;
	while (!end)
	{
		if (setup == true) //Beginning of the programm
		{
			int role;
			cout << "Hello everynyan, I'm your Guide to this world of Oscilloscopes\nFirst of all choose your role\n1 - Codder\n2 - User\n";
			cin >> role;
			cout << endl;
			if (role == 1) //Codder
			{

			}
			else if (role == 2) //User
			{
				int data_type1;
				std::cout << "First of all you must describe yourself\nSo, who are you?\n\n";
				std::cout << "1 - Answer from keyboard\n2 - Answer by data from load_reseacher.txt\n";
				cin >> data_type1;
				cout << endl;
				if (data_type1 == 1)//From keyboard
				{
					scientist.Type_information(1);
				}
				else if (data_type1 == 2)//From file
				{
					load_researcher >> scientist;
				}


				int type_of_oscilloscope;
				cout << "My greetings " << scientist.Get_research_position() << " " << scientist.Get_name() << " " << scientist.Get_surname() << endl<<endl;
				cout << "Mr. " << scientist.Get_research_position() << ", to work with this soft, you must create at least one generator and oscilloscope\nMr. " << scientist.Get_name()
					<< ", what type of osclloscope do you want to initialize?\n1 - Analog\n2 - Digital\n";
				cin >> type_of_oscilloscope;
				cout << endl;


				int data_type2;
				cout << "Good. Now, do you want to initialize oscilloscope by keyboard or file, my master?\n1 - Keyboard\n2 - File\n";
				cin >> data_type2;
				cout << endl;
				if (type_of_oscilloscope == 1 && data_type2 == 1) //Analog Oscilloscope from keyboard
				{
					cin >> List_of_Analog_Osc;
				}
				else if (type_of_oscilloscope == 1 && data_type2 == 2) //Analog Oscilloscope from file
				{
					load_analog_osc >> List_of_Analog_Osc;
				}
				else if (type_of_oscilloscope == 2 && data_type2 == 1) //Digital Oscilloscope from keyboard
				{
					cin >> List_of_Digital_Osc;
				}
				else if (type_of_oscilloscope == 2 && data_type2 == 2) //Digital Oscilloscope from file
				{
					load_digital_osc >> List_of_Digital_Osc;
				}


				int data_type3;
				cout << "Nice. Now, do you want to initialize generator by keyboard or file?\n1 - Keyboard\n2 - File\n";
				cin >> data_type3;
				cout << endl;
				if (data_type3 == 1) //Generator from keyboard
				{
					cin >> List_of_Gen;
				}
				else if (data_type3 == 2) //Generator from file
				{
					load_gen >> List_of_Gen;
				}
				

				cout << "Perfectly done. Really. Now you can start working with the program\nGood luck in your research!!\n\n";
				setup = false;
			}
		}
		else if (setup == false) //Main programm
		{

			/*int menu;
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
			}*/


			//end = true;
		}
	}
	//ENDING

	//Íàäîáíîñòü íèæíåãî ñîìíèòåëüíàÿ, ò.ê. ofstream ñàì ôàéë ñîçäàåò àâòîìàòè÷åñêè
	/* 
	try
{
	if (!save.is_open())
	{
		throw exception("ERROR #10\nYou tried to close file saved.txt, that doesn't exist\n");
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
			throw exception("ERROR #10\nYou tried to close file load_analog_oscilloscope.txt, that doesn't exist\n");
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
			throw exception("ERROR #10\nYou tried to close file load_digital_oscilloscope.txt, that doesn't exist\n");
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
			throw exception("ERROR #10\nYou tried to close file load_generator.txt, that doesn't exist\n");
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
			throw exception("ERROR #10\nYou tried to close file load_researcher.txt, that doesn't exist\n");
		}
		load_researcher.close();
	}
	catch (const exception &ex)
	{
		std::cout << ex.what() << std::endl;
		system("Pause");
	}
	/*
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