//analog_oscilloscope.h
#pragma once

#include "oscilloscope.h"

// Нужно также добавить в цифровой и аналоговый осциллографы реалзиации виртуальных методов

class Analog_Oscilloscope :public Oscilloscope
{
private:
	int amount_of_beams;
	static int s_amount_of_analog_oscilloscopes;

	void Set_amount_of_beams(int amount_of_beams);

	int Get_amount_of_beams();

public:

	Analog_Oscilloscope(int amount_of_сhannels, int voltage_divisions, int seconds_divisions, std::string manufacturer = "noname", std::string device_model = "", int year_of_issue = 0, int amount_of_beams = 0);
	~Analog_Oscilloscope();

	friend std::ostream& operator << (std::ostream &out, Analog_Oscilloscope &device);
};