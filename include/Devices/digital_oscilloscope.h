//digital_oscilloscope.h
#pragma once

#include "oscilloscope.h"
#include <fstream>

class Digital_Oscilloscope :public Oscilloscope
{
private:
	int memory_depth; //in single channel mode [Mpts/CH]

	void Set_memory_depth(int memory_depth);

	int Get_memory_depth();

	Digital_Oscilloscope();
	//Digital_Oscilloscope(int amount_of_ñhannels, int voltage_divisions, int seconds_divisions, std::string manufacturer = "noname", std::string device_model = "", int year_of_issue = 0, int memory_depth = 0, Digital_Oscilloscope* p_next = 0, Digital_Oscilloscope* p_prev = 0);
public:
	Digital_Oscilloscope(bool all_info);
	Digital_Oscilloscope(std::ifstream& load);
	Digital_Oscilloscope(const Digital_Oscilloscope &device);
	~Digital_Oscilloscope();

	Digital_Oscilloscope* p_next;
	Digital_Oscilloscope* p_prev;

	void Type_information(bool all_information) override;

	friend std::ostream& operator << (std::ostream &out, Digital_Oscilloscope &device);
	friend std::istream& operator >> (std::istream &in, Digital_Oscilloscope &device);
};