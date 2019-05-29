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
	int amount_of_�hannels;

protected:
	std::vector<bool> Channels_on_off;

	void Set_manufacturer(std::string manufacturer);
	void Set_device_model(std::string device_model);
	void Set_year_of_issue(int year_of_issue);
	void Set_amount_of_�hannels(int amount_of_�hannels);

	int Get_year_of_issue();

	virtual void Make_Channels(int amount_of_channels) = 0;
public:

	Electrical_Equipment();
	~Electrical_Equipment();

	Electrical_Equipment* p_next;
	Electrical_Equipment* p_prev;

	virtual bool Get_connection_of_channel(int number_of_channel, std::string show) = 0;
	virtual void Type_information(bool all_information) = 0;
	int Get_amount_of_�hannels();
	std::string Get_manufacturer();
	std::string Get_device_model();
};
