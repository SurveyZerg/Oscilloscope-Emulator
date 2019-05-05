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

protected:
	std::vector<bool> Channels_on_off;
	std::vector<Electrical_Equipment*> Channels_connected;

	Electrical_Equipment();
	~Electrical_Equipment();

	void Set_manufacturer(std::string manufacturer);
	void Set_device_model(std::string device_model);
	void Set_year_of_issue(int year_of_issue);
	void Set_amount_of_ñhannels(int amount_of_ñhannels);


	int Get_year_of_issue();

	void Make_Channels(int amount_of_channels);
public:
	void Set_connection_of_channel(int number_of_channel, bool on_off, Electrical_Equipment* = 0);

	virtual bool Get_connection_of_channel(int number_of_channel, std::string show) = 0;
	int Get_amount_of_ñhannels();
	std::string Get_manufacturer();
	std::string Get_device_model();
};
