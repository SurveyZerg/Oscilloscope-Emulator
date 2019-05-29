//digital_oscilloscope.h
#pragma once

#include "oscilloscope.h"

class Digital_Oscilloscope :public Oscilloscope
{
private:
	int memory_depth; //in single channel mode [Mpts/CH]
	static int s_amount_of_digital_oscilloscopes;

	void Set_memory_depth(int memory_depth);

	int Get_memory_depth();

	Digital_Oscilloscope();
	Digital_Oscilloscope(bool file_reading);
public:

	Digital_Oscilloscope(int amount_of_�hannels, int voltage_divisions, int seconds_divisions, std::string manufacturer = "noname", std::string device_model = "", int year_of_issue = 0, int memory_depth = 0, Electrical_Equipment* p_next = 0, Electrical_Equipment* p_prev = 0);
	~Digital_Oscilloscope();

	void Type_information(bool all_information) override;

	friend std::ostream& operator << (std::ostream &out, Digital_Oscilloscope &device);
	friend std::istream& operator >> (std::istream &in, Digital_Oscilloscope &device);
};