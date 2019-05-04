//researcher.h
#pragma once

#include "analog_oscilloscope.h"
#include "digital_oscilloscope.h"
#include "generator.h"

class Researcher
{
private:
	std::string research_position; //junior researcher, researcher, senior researcher, leading researcher, principal researcher
	std::string name;
	std::string surname;
	int age;
public:
	Researcher(std::string research_position = "Mr.", std::string name = "", std::string surname = "Noname", int age = 0);
	~Researcher();

	std::string Get_research_position();
	std::string Get_name();
	std::string Get_surname();
	int Get_age();

	friend std::ostream& operator<< (std::ostream &out, Researcher &scientist);

	void Connect(Oscilloscope &osc,int number_of_channel_osc, Generator &gen, int number_of_channel_gen);
};