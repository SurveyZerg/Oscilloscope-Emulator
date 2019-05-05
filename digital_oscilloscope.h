//digital_oscilloscope.h
#pragma once

#include "oscilloscope.h"

// Нужно также добавить в цифровой и аналоговый осциллографы реалзиации виртуальных методов

class Digital_Oscilloscope :public Oscilloscope
{
private:
	int memory_depth; //in single channel mode [Mpts/CH]
	static int s_amount_of_digital_oscilloscopes;

	void Set_memory_depth(int memory_depth);

	int Get_memory_depth();
public:

	Digital_Oscilloscope(int amount_of_сhannels, int voltage_divisions, int seconds_divisions, std::string manufacturer = "noname", std::string device_model = "", int year_of_issue = 0, int memory_depth = 0);
	~Digital_Oscilloscope();

	friend std::ostream& operator << (std::ostream &out, Digital_Oscilloscope &device);
};