//generator.h
#pragma once

#include "electrical_equipment.h"

class I_Generator
{
public:
	void virtual Set_output_frequency(int output_frequency) = 0;
	void virtual Set_peak_to_peak_voltage(int peak_to_peak_voltage) = 0;
};

class Generator :public Electrical_Equipment, public I_Generator
{
private:
	int output_frequency = 2000; // [Hz]
	int peak_to_peak_voltage = 6000; // [milliVolts]
	int maximum_output_frequency = 25;// [MHz]
	std::vector<bool> Channels;

	void Make_Channels(int amount_of_channels) override;
protected:

	void Set_maximum_output_frequency(int maximum_output_frequency);

	int Get_maximum_output_frequency();
public:

	Generator(int amount_of_channels,std::string manufacturer = "noname", std::string device_model = "", int year_of_issue = 0, int maximum_output_frequency = 0);
	~Generator();

	friend std::ostream& operator << (std::ostream &out, Generator &device);

	void Set_connection_of_channel(int number_of_channel, bool on_off) override;
	void Set_output_frequency(int output_frequency) override;
	void Set_peak_to_peak_voltage(int peak_to_peak_voltage) override;

	bool Get_connection_of_channel(int number_of_channel) override;
};