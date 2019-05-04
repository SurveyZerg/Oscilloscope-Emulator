//digital_oscilloscope.h
#pragma once

#include "oscilloscope.h"

// ����� ����� �������� � �������� � ���������� ������������ ���������� ����������� �������

class Digital_Oscilloscope :public Oscilloscope, public I_Oscilloscope
{
private:
	int memory_depth; //in single channel mode [Mpts/CH]
	static int s_amount_of_digital_oscilloscopes;
	std::vector<bool> Channels;

	void Make_Channels(int amount_of_channels);
public:
	void Set_memory_depth(int memory_depth);
	void Set_connection_of_channel(int number_of_channel, bool on_off);

	int Get_memory_depth();
	bool Get_connection_of_channel(int number_of_channel);

	Digital_Oscilloscope(int amount_of_�hannels, int voltage_divisions, int seconds_divisions, std::string manufacturer = "noname", std::string device_model = "", int year_of_issue = 0, int memory_depth = 0);
	~Digital_Oscilloscope();

	friend std::ostream& operator << (std::ostream &out, Digital_Oscilloscope &device);
};