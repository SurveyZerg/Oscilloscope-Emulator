// main.cpp

#include <iostream>
#include <fstream>
#include "include/Researcher/researcher.h"
#include "include/List/lab_list.h"

using namespace std;

int main()
{
	//SETUP
	setlocale(LC_ALL, "ru");
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
  
	//Нужно сделать проверку всех синов внизу

	// MAIN PROGRAM CYCLE
	bool end = false;
	bool setup = true;
	int type_of_osc, choose_osc = 0, choose_gen = 0;
	while (!end)
	{
		if (setup == true) //Beginning of the programm
		{
			int role;
			cout << "Hello everynyan, I'm your Guide to this world of Oscilloscopes\nFirst of all choose your role\n1 - Codder (for skipping the beginning and debugging)\n2 - User\n";
			cin >> role;
			while (cin.fail() || role < 1 || role > 2)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Input error, try again - ";
				cin >> role;
			}
			cout << endl;
			if (role == 1) //Codder
			{
				//This is for dubugging code
				type_of_osc = 1;
				load_researcher >> scientist;
				load_analog_osc >> List_of_Analog_Osc;
				load_digital_osc >> List_of_Digital_Osc;
				load_gen >> List_of_Gen;


				setup = false;
			}
			else if (role == 2) //User
			{
				int data_type1;
				std::cout << "First of all you must describe yourself\nSo, who are you?\n\n";
				std::cout << "1 - Answer from keyboard\n2 - Answer by data from load_reseacher.txt\n";
				cin >> data_type1;
				while (cin.fail() || data_type1 < 1 || data_type1 > 2)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Input error, try again - ";
					cin >> data_type1;
				}
				cout << endl;
				if (data_type1 == 1)//From keyboard
				{
					scientist.Type_information(1);
				}
				else if (data_type1 == 2)//From file
				{
					load_researcher >> scientist;
				}


				cout << "My greetings " << scientist.Get_research_position() << " " << scientist.Get_name() << " " << scientist.Get_surname() << endl<<endl;
				cout << "Mr. " << scientist.Get_research_position() << ", to work with this soft, you must create at least one generator and oscilloscope\nMr. " << scientist.Get_name()
					<< ", what type of osclloscope do you want to initialize?\n1 - Analog\n2 - Digital\n";
				cin >> type_of_osc;
				while (cin.fail() || type_of_osc < 1 || type_of_osc > 2)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Input error, try again - ";
					cin >> type_of_osc;
				}
				cout << endl;


				int data_type2;
				cout << "Good. Now, do you want to initialize oscilloscope by keyboard or file, my master?\n1 - Keyboard\n2 - File\n";
				cin >> data_type2;
				while (cin.fail() || data_type2 < 1 || data_type2 > 2)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Input error, try again - ";
					cin >> data_type2;
				}
				cout << endl;
				if (type_of_osc == 1 && data_type2 == 1) //Analog Oscilloscope from keyboard
				{
					cin >> List_of_Analog_Osc;
				}
				else if (type_of_osc == 1 && data_type2 == 2) //Analog Oscilloscope from file
				{
					load_analog_osc >> List_of_Analog_Osc;
				}
				else if (type_of_osc == 2 && data_type2 == 1) //Digital Oscilloscope from keyboard
				{
					cin >> List_of_Digital_Osc;
				}
				else if (type_of_osc == 2 && data_type2 == 2) //Digital Oscilloscope from file
				{
					load_digital_osc >> List_of_Digital_Osc;
				}


				int data_type3;
				cout << "Nice. Now, do you want to initialize generator by keyboard or file?\n1 - Keyboard\n2 - File\n";
				cin >> data_type3;
				while (cin.fail() || data_type3 < 1 || data_type3 > 2)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Input error, try again - ";
					cin >> data_type3;
				}
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
			int menu;
			cout << "What do you want to do?\n1 - Add new device\n2 - Change your current devices\n3 - View current using Oscilloscope and Generator\n4 - View all added devices\n5 - Swap 2 devices in a list\n"
				<< "6 - Connect Oscilloscope to Generator\n7 - Read signal at Oscilloscope from Generator\n8 - Change seconds scale at Oscilloscope\n"
				<< "9 - Change voltage scale at Oscilloscope\n10 - Change output frequency at Generator\n11 - Change peak to peak voltage at Generator\n"
				<< "12 - Reboot everything\n13 - Delete device\n14 - Exit\n";
			cin >> menu;
			while (cin.fail() || menu < 1 || menu > 14)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Input error, try again - ";
				cin >> menu;
			}
			switch (menu)
			{
			case 1:
			{
				int type_of_new_device;
				cout << "What device do you want to add?\n1 - Analog Oscilloscope\n2 - Digital Oscilloscope\n3 - Generator\n";
				cin >> type_of_new_device;
				while (cin.fail() || type_of_new_device < 1 || type_of_new_device > 3)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Input error, try again - ";
					cin >> type_of_new_device;
				}
				cout << endl;


				int input_all_info;
				bool all_info;
				cout << "Do you want to write all info or only important for work?\n1 - Only important\n2 - all info\n";
				cin >> input_all_info;
				while (cin.fail() || input_all_info < 1 || input_all_info > 2)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Input error, try again - ";
					cin >> input_all_info;
				}
				if (input_all_info == 1)
					all_info = false;
				if (input_all_info == 2)
					all_info = true;
				cout << endl;


				if (type_of_new_device == 1)
					cout << List_of_Analog_Osc;
				else if (type_of_new_device == 2)
					cout << List_of_Digital_Osc;
				else if (type_of_new_device == 3)
					cout << List_of_Gen;


				int place_number;
				if (type_of_new_device == 1)
				{
					cout << "\nChoose place of new object in this list from 1 to " << List_of_Analog_Osc.size() + 1 << ": ";
					cin >> place_number;
					while (cin.fail() || place_number < 1 || place_number > (List_of_Analog_Osc.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> place_number;
					}
				}
				else if (type_of_new_device == 2)
				{
					cout << "\nChoose place of new object in this list from 1 to " << List_of_Digital_Osc.size() + 1 << ": ";
					cin >> place_number;
					while (cin.fail() || place_number < 1 || place_number >(List_of_Digital_Osc.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> place_number;
					}
				}
				else if (type_of_new_device == 3)
				{
					cout << "\nChoose place of new object in this list from 1 to " << List_of_Gen.size() + 1 << ": ";
					cin >> place_number;
					while (cin.fail() || place_number < 1 || place_number >(List_of_Gen.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> place_number;
					}
				}
				place_number--;
				cout << endl;


				if (type_of_new_device == 1)
					List_of_Analog_Osc.insert(List_of_Analog_Osc.addDevice(all_info),place_number);
				else if (type_of_new_device == 2)
					List_of_Digital_Osc.insert(List_of_Digital_Osc.addDevice(all_info),place_number);
				else if (type_of_new_device == 3)
					List_of_Gen.insert(List_of_Gen.addDevice(all_info),place_number);


				break;
			}
			case 2:
			{
				if (List_of_Analog_Osc.size() != 0 && List_of_Digital_Osc.size() != 0)
				{
					cout << "What type of Oscilloscope do you want to use?\n1 - Analog\n2 - Digital\n";
					cin >> type_of_osc;
					while (cin.fail() || type_of_osc < 1 || type_of_osc > 2)
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> type_of_osc;
					}
				}
				else {}
				cout << endl;
				if (type_of_osc == 1)
					cout << List_of_Analog_Osc;
				if (type_of_osc == 2)
					cout << List_of_Digital_Osc;
				

				cout << "What Oscilloscope do you want to use?\n\n";
				cin >> choose_osc;
				if (type_of_osc == 1)
					while (cin.fail() || choose_osc < 1 || choose_osc > (List_of_Analog_Osc.size() + 1))
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Input error, try again - ";
					cin >> type_of_osc;
				}
				if (type_of_osc == 1)
					while (cin.fail() || choose_osc < 1 || choose_osc > (List_of_Digital_Osc.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> type_of_osc;
					}
				cout << endl;
				choose_osc--; //Чтобы индексы были с нуля


				cout << List_of_Gen;


				cout << "What Generator do you want to use?\n\n";
				cin >> choose_gen;
				while (cin.fail() || choose_gen < 1 || choose_gen > (List_of_Gen.size() + 1))
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Input error, try again - ";
					cin >> choose_gen;
				}
				cout << endl;
				choose_gen--;


				break;
			}
			case 3:
			{
				cout << "Now you are using this Oscilloscope and Generator:\n";
				if (type_of_osc == 1)
					cout << List_of_Analog_Osc[choose_osc];
				if (type_of_osc == 2)
					cout << List_of_Digital_Osc[choose_osc];
				cout << List_of_Gen[choose_gen];
				break;
			}
			case 4:
			{
				cout << List_of_Analog_Osc;
				cout << List_of_Digital_Osc;
				cout << List_of_Gen;
				break;
			}
			case 5:
			{
				int type_of_swap_list;
				cout << "In what list do you want to swap devices?\n1 - Analog Oscilloscopes' list\n2 - Digital Oscilloscopes' list\n3 - Generators' list\n";
				cin >> type_of_swap_list;
				while (cin.fail() || type_of_swap_list < 1 || type_of_swap_list > 3)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Input error, try again - ";
					cin >> type_of_swap_list;
				}
				cout << endl;


				if (type_of_swap_list == 1)
					cout << List_of_Analog_Osc;
				else if (type_of_swap_list == 2)
					cout << List_of_Digital_Osc;
				else if (type_of_swap_list == 3)
					cout << List_of_Gen;


				int place_number_from, place_number_to;
				cout << "Swap from #";
				cin >> place_number_from;
				if (type_of_swap_list == 1)
					while (cin.fail() || place_number_from < 1 || place_number_from >(List_of_Analog_Osc.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> place_number_from;
					}
				else if (type_of_swap_list == 2)
					while (cin.fail() || place_number_from < 1 || place_number_from >(List_of_Digital_Osc.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> place_number_from;
					}
				else if (type_of_swap_list == 3)
					while (cin.fail() || place_number_from < 1 || place_number_from >(List_of_Gen.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> place_number_from;
					}
				
				cout << " to #";
				cin >> place_number_to;
				if (type_of_swap_list == 1)
					while (cin.fail() || place_number_to < 1 || place_number_to >(List_of_Analog_Osc.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> place_number_to;
					}
				else if (type_of_swap_list == 2)
					while (cin.fail() || place_number_to < 1 || place_number_to >(List_of_Digital_Osc.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> place_number_to;
					}
				else if (type_of_swap_list == 3)
					while (cin.fail() || place_number_to < 1 || place_number_to >(List_of_Gen.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> place_number_to;
					}
				place_number_from--;
				place_number_to--;
				cout << endl;

				if (type_of_swap_list == 1)
					List_of_Analog_Osc.swap(place_number_from,place_number_to);
				else if (type_of_swap_list == 2)
					List_of_Digital_Osc.swap(place_number_from, place_number_to);
				else if (type_of_swap_list == 3)
					List_of_Gen.swap(place_number_from, place_number_to);


				break;
			}
			case 6:
			{
				int channel_osc;
				cout << "What channel of Oscilloscope do you want to use?\nChannel #";
				cin >> channel_osc;
				if (type_of_osc == 1)
					while (cin.fail() || channel_osc < 1 || channel_osc >List_of_Analog_Osc[choose_osc].Get_amount_of_channels())
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> channel_osc;
					}
				else if (type_of_osc == 2)
					while (cin.fail() || channel_osc < 1 || channel_osc >List_of_Digital_Osc[choose_osc].Get_amount_of_channels())
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> channel_osc;
					}

				int channel_gen;
				cout << "What channel of Generator do you want to use?\nChannel #";
				cin >> channel_gen;
				while (cin.fail() || channel_gen < 1 || channel_osc >List_of_Gen[choose_gen].Get_amount_of_channels())
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Input error, try again - ";
					cin >> channel_gen;
				}

				if (type_of_osc == 1)
					scientist.Connect(List_of_Analog_Osc[choose_osc], channel_osc, List_of_Gen[choose_gen], channel_gen);
				else if (type_of_osc == 2)
					scientist.Connect(List_of_Digital_Osc[choose_osc], channel_osc, List_of_Gen[choose_gen], channel_gen);


				break;
			}
			case 7:
			{
				int channel_osc;
				cout << "From what channel of Oscilloscope do you want to read signal?\nChannel #";
				cin >> channel_osc;
				if (type_of_osc == 1)
					while (cin.fail() || channel_osc < 1 || channel_osc >List_of_Analog_Osc[choose_osc].Get_amount_of_channels())
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> channel_osc;
					}
				else if (type_of_osc == 2)
					while (cin.fail() || channel_osc < 1 || channel_osc >List_of_Digital_Osc[choose_osc].Get_amount_of_channels())
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> channel_osc;
					}


				if (type_of_osc == 1)
					scientist.Read_voltage(List_of_Analog_Osc[choose_osc], channel_osc);
				else if (type_of_osc == 2)
					scientist.Read_voltage(List_of_Digital_Osc[choose_osc], channel_osc);
				break;
			}
			case 8:
			{
				int seconds_scale;
				cout << "Seconds scale [microSec/div] = ";
				cin >> seconds_scale;
				if (type_of_osc == 1)
					while (cin.fail() || seconds_scale < 1)
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> seconds_scale;
					}
				else if (type_of_osc == 2)
					while (cin.fail() || seconds_scale < 1)
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> seconds_scale;
					}


				if (type_of_osc == 1)
					List_of_Analog_Osc[choose_osc].Set_seconds_scale(seconds_scale);
				if (type_of_osc == 2)
					List_of_Digital_Osc[choose_osc].Set_seconds_scale(seconds_scale);
				break;
			}
			case 9:
			{
				int voltage_scale;
				cout << "Voltage scale [milliVolts/div] = ";
				cin >> voltage_scale;
				if (type_of_osc == 1)
					while (cin.fail() || voltage_scale < 1)
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> voltage_scale;
					}
				else if (type_of_osc == 2)
					while (cin.fail() || voltage_scale < 1)
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> voltage_scale;
					}


				if (type_of_osc == 1)
					List_of_Analog_Osc[choose_osc].Set_voltage_scale(voltage_scale);
				if (type_of_osc == 2)
					List_of_Digital_Osc[choose_osc].Set_voltage_scale(voltage_scale);
				break;
			}
			case 10:
			{
				__int64 output_frequency;
				cout << "Output frequency [Hz] = ";
				cin >> output_frequency;
				while (cin.fail() || output_frequency < 1 || output_frequency > (List_of_Gen[choose_gen].Get_maximum_output_frequency() *1000000))
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (List_of_Gen[choose_gen].Get_maximum_output_frequency() * 1000000)
						cout << "Max output frequency - " << List_of_Gen[choose_gen].Get_maximum_output_frequency() * 1000000 << " Hz\n";
					cout << "Input error, try again - ";
					cin >> output_frequency;
				}
				List_of_Gen[choose_gen].Set_output_frequency(output_frequency);
				break;
			}
			case 11:
			{
				int peak_to_peak_voltage;
				cout << "Peak to peak voltage [milliVolts] = ";
				cin >> peak_to_peak_voltage;
				while (cin.fail() || peak_to_peak_voltage < 1)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Input error, try again - ";
					cin >> peak_to_peak_voltage;
				}
				List_of_Gen[choose_gen].Set_peak_to_peak_voltage(peak_to_peak_voltage);
				break;
			}
			case 12:
			{
				setup = true;
				break;
			}
			case 13:
			{
				int type_of_delete_device;
				cout << "What device do you want to delete?\n1 - Analog Oscilloscope\n2 - Digital Oscilloscope\n3 - Generator\n";
				cin >> type_of_delete_device;
				while (cin.fail() || type_of_delete_device < 1 || type_of_delete_device > 3)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Input error, try again - ";
					cin >> type_of_delete_device;
				}
				cout << endl;


				if (type_of_delete_device == 1)
					cout << List_of_Analog_Osc;
				else if (type_of_delete_device == 2)
					cout << List_of_Digital_Osc;
				else if (type_of_delete_device == 3)
					cout << List_of_Gen;


				int place_number;
				cout << "You want to delete device #";
				cin >> place_number;
				if (type_of_delete_device == 1)
					while (cin.fail() || place_number < 1 || place_number >(List_of_Analog_Osc.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> place_number;
					}
				else if (type_of_delete_device == 2)
					while (cin.fail() || place_number < 1 || place_number >(List_of_Digital_Osc.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> place_number;
					}
				else if (type_of_delete_device == 3)
					while (cin.fail() || place_number < 1 || place_number >(List_of_Gen.size() + 1))
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Input error, try again - ";
						cin >> place_number;
					}
				place_number--;


				if (type_of_delete_device == 1)
					List_of_Analog_Osc.erase(place_number);
				else if (type_of_delete_device == 2)
					List_of_Digital_Osc.erase(place_number);
				else if (type_of_delete_device == 3)
					List_of_Gen.erase(place_number);


				break;
			}
			case 14:
			{
				cout << "\nbye bye~\n";
				end = true;
				break;
			}
			}
		}
	}
	//ENDING

	save << scientist;
	save << List_of_Analog_Osc;
	save << List_of_Digital_Osc;
	save << List_of_Gen;

	save.close();

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

	return 0;
} 