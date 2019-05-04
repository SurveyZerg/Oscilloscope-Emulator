// electrical_equipment.h
#pragma once

#include <iostream>
#include <string>
#include <vector>

class Electrical_Equipment
{
private:
	std::string manufacturer;
	std::string device_model;
	int year_of_issue;
	int amount_of_ñhannels;
public:
	Electrical_Equipment ();
	~Electrical_Equipment();

	void Set_amount_of_ñhannels(int amount_of_ñhannels);
	void Set_manufacturer (std::string manufacturer);
	void Set_device_model (std::string device_model);
	void Set_year_of_issue (int year_of_issue);
	virtual void Set_connection_of_channel(int number_of_channel, bool on_off) = 0;

	std::string Get_manufacturer();
	std::string Get_device_model();
	int Get_year_of_issue();
	int Get_amount_of_ñhannels();
	virtual bool Get_connection_of_channel(int number_of_channel) = 0;

	virtual void Make_Channels(int amount_of_channels) = 0;
};
