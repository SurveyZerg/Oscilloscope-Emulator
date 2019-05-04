//analog_oscilloscope.h
#pragma once

#include "oscilloscope.h"

// ����� ����� �������� � �������� � ���������� ������������ ���������� ����������� �������

class Analog_Oscilloscope :public Oscilloscope, public I_Oscilloscope
{
private:
	int amount_of_beams;
	static int s_amount_of_analog_oscilloscopes;
	std::vector<bool> Channels;

	void Make_Channels(int amount_of_channels);
public:
	void Set_amount_of_beams(int amount_of_beams);
	void Set_connection_of_channel(int number_of_channel, bool on_off);

	int Get_amount_of_beams();
	bool Get_connection_of_channel(int number_of_channel);

	Analog_Oscilloscope(int amount_of_�hannels, int voltage_divisions, int seconds_divisions, std::string manufacturer = "noname", std::string device_model = "", int year_of_issue = 0, int amount_of_beams = 0);
	~Analog_Oscilloscope();

	friend std::ostream& operator << (std::ostream &out, Analog_Oscilloscope &device);
};