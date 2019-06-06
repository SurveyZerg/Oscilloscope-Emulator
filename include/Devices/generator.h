//generator.h
#pragma once

#include "electrical_equipment.h"
#include <fstream>

class Oscilloscope;

class I_Generator
{
protected:
	void virtual Set_output_frequency(__int64 output_frequency) = 0;
	void virtual Set_peak_to_peak_voltage(int peak_to_peak_voltage) = 0;
	void virtual Set_signal(__int64 output_frequency, int peak_to_peak_voltage) = 0;
};

class Generator :public Electrical_Equipment, public I_Generator
{
private:
	__int64 output_frequency = 1000; // [Hz]
	int peak_to_peak_voltage = 1000; // [milliVolts]
	int maximum_output_frequency;// [MHz]

	//Generator(int amount_of_channels, std::string manufacturer = "noname", std::string device_model = "", int year_of_issue = 0, int maximum_output_frequency = 0, Generator* p_next = 0, Generator* p_prev = 0);
	//Из-за того, что тут тоже можно только один параметр передать, то может перепутаться с конструктором, где только бул

	std::vector<Oscilloscope*> Channels_connected;

	void Set_maximum_output_frequency(int maximum_output_frequency);

	void Make_Channels(int amount_of_channels) override;

	Generator();
public:
	Generator(bool all_info);
	Generator(std::ifstream& load);
	Generator(const Generator &device);
	~Generator();

	Generator* p_next;
	Generator* p_prev;

	void Type_information(bool all_information) override;

	friend std::ostream& operator << (std::ostream &out, Generator &device);
	friend std::istream& operator >> (std::istream &in, Generator &device);

	void Set_output_frequency(__int64 output_frequency) override;
	void Set_peak_to_peak_voltage(int peak_to_peak_voltage) override;
	void Set_signal(__int64 output_frequency, int peak_to_peak_voltage) override;
	void Set_connection_of_channel(int number_of_channel, bool on_off, Oscilloscope* device = 0);

	bool Get_connection_of_channel(int number_of_channel, std::string show = "no") override;
	int Get_output_frequency();
	int Get_peak_to_peak_voltage();
	int Get_maximum_output_frequency();
};