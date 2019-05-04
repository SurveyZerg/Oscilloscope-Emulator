// oscilloscope.h
#pragma once

#include "electrical_equipment.h"

class I_Oscilloscope
{
public:

};

// Это надо превратить в абстрактный класс с виртуальными методами
class Oscilloscope :public Electrical_Equipment
{
private:
	static int s_amount_of_oscilloscopes;
	int voltage_divisions;
	int seconds_divisions;
public:
	int Set_voltage_divisions(int voltage_divisions);
	int Set_seconds_divisions(int seconds_divisions);

	Oscilloscope();
	~Oscilloscope();
};