// oscilloscope.h
#pragma once

#include "electrical_equipment.h"

class I_Oscilloscope
{
public:
	void virtual Set_seconds_scale(int seconds_scale) = 0;
	void virtual Set_voltage_scale(int voltage_scale) = 0;
};

// Это надо превратить в абстрактный класс с виртуальными методами
class Oscilloscope :public Electrical_Equipment
{
private:
	static int s_amount_of_oscilloscopes;
	int voltage_divisions;
	int seconds_divisions;

protected:
	int seconds_scale = 500; // [microSec\div]
	int voltage_scale = 1000; // [milliVolts\div]

	void Set_voltage_divisions(int voltage_divisions);
	void Set_seconds_divisions(int seconds_divisions);

public:
	Oscilloscope();
	~Oscilloscope();
};