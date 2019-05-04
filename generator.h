//generator.h
#pragma once

#include "electrical_equipment.h"

class Generator :public Electrical_Equipment
{
private:
	int maximum_output_frequency = 25;// [MHz]
	std::vector<bool> Channels;

	void Make_Channels(int amount_of_channels);
public:
	void Set_maximum_output_frequency(int maximum_output_frequency);
	void Set_connection_of_channel(int number_of_channel, bool on_off);

	int Get_maximum_output_frequency();
	bool Get_connection_of_channel(int number_of_channel);

	Generator(int amount_of_channels,std::string manufacturer = "noname", std::string device_model = "", int year_of_issue = 0, int maximum_output_frequency = 0);
	~Generator();

	friend std::ostream& operator << (std::ostream &out, Generator &device);
};