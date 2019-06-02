//analog_oscilloscope.h
#pragma once

#include "oscilloscope.h"
#include <fstream>

class Analog_Oscilloscope :public Oscilloscope
{
private:
	int amount_of_beams;
	static int s_amount_of_analog_oscilloscopes;

	
	void Set_amount_of_beams(int amount_of_beams);

	int Get_amount_of_beams();

	//Analog_Oscilloscope(int amount_of_ñhannels, int voltage_divisions, int seconds_divisions, std::string manufacturer = "noname", std::string device_model = "", int year_of_issue = 0, int amount_of_beams = 0, Analog_Oscilloscope* p_next = 0, Analog_Oscilloscope* p_prev = 0);
public:
	Analog_Oscilloscope();
	~Analog_Oscilloscope();
	Analog_Oscilloscope(std::ifstream& load);
	
	Analog_Oscilloscope* p_next;
	Analog_Oscilloscope* p_prev;

	void Type_information(bool all_information) override;

	friend std::ostream& operator << (std::ostream &out, Analog_Oscilloscope &device);
	friend std::istream& operator >> (std::istream &in, Analog_Oscilloscope &device);
};