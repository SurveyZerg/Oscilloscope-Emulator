//analog_oscilloscope.h
#pragma once

#include "oscilloscope.h"

// Нужно также добавить в цифровой и аналоговый осциллографы реалзиации виртуальных методов

class Analog_Oscilloscope :public Oscilloscope, public I_Oscilloscope
{
private:
	int amount_of_beams;
	static int s_amount_of_analog_oscilloscopes;
	std::vector<bool> Channels;

	void Make_Channels(int amount_of_channels) override;

	void Set_amount_of_beams(int amount_of_beams);

	int Get_amount_of_beams();
public:
	void Set_connection_of_channel(int number_of_channel, bool on_off) override;
	void Set_voltage_scale(int voltage_scale) override;
	void Set_seconds_scale(int seconds_scale) override;

	bool Get_connection_of_channel(int number_of_channel) override;

	Analog_Oscilloscope(int amount_of_сhannels, int voltage_divisions, int seconds_divisions, std::string manufacturer = "noname", std::string device_model = "", int year_of_issue = 0, int amount_of_beams = 0);
	~Analog_Oscilloscope();

	friend std::ostream& operator << (std::ostream &out, Analog_Oscilloscope &device);
};