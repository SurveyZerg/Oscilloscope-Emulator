// oscilloscope.h
#pragma once

#include "electrical_equipment.h"

class Generator;

class I_Oscilloscope
{
public:
	void virtual Set_seconds_scale(int seconds_scale) = 0;
	void virtual Set_voltage_scale(int voltage_scale) = 0;
};

class Oscilloscope :public Electrical_Equipment, public I_Oscilloscope
{
private:
	static int s_amount_of_oscilloscopes;
	int voltage_divisions;
	int seconds_divisions;

protected:
	int seconds_scale = 500; // [microSec\div]
	int voltage_scale = 1000; // [milliVolts\div]

	std::vector<Generator*> Channels_connected;

	void Set_voltage_divisions(int voltage_divisions);
	void Set_seconds_divisions(int seconds_divisions);

	void Make_Channels(int amount_of_channels)override;
public:
	Oscilloscope();
	~Oscilloscope();

	void Set_voltage_scale(int voltage_scale) override;
	void Set_seconds_scale(int seconds_scale) override;
	void Set_connection_of_channel(int number_of_channel, bool on_off, Generator* device = 0);

	bool Get_connection_of_channel(int number_of_channel, std::string show = "no") override;
	int Get_voltage_divisions();
	int Get_seconds_divisions();
	int Get_seconds_scale();
	int Get_voltage_scale();
	Generator* Get_connected_generator(int number_of_channel);
};