// electrical_equipment.cpp

#include "electrical_equipment.h"

Electrical_Equipment::Electrical_Equipment()
{
#ifdef _DEBUG
	std::cout << "Default Electrical_Equipment Constructor was called" << std::endl;
#endif
}

Electrical_Equipment::~Electrical_Equipment()
{
#ifdef _DEBUG
	std::cout << "Default Electrical_Equipment Destructor was called" << std::endl;
#endif
}

void Electrical_Equipment::Set_amount_of_�hannels(int amount_of_�hannels)
{
	this->amount_of_�hannels = amount_of_�hannels;
}
void Electrical_Equipment::Set_manufacturer(std::string manufacturer)
{
	this->manufacturer = manufacturer;
}
void Electrical_Equipment::Set_device_model(std::string device_model)
{
	this->device_model = device_model;
}
void Electrical_Equipment::Set_year_of_issue(int year_of_issue)
{
	this->year_of_issue = year_of_issue;
}

int Electrical_Equipment::Get_amount_of_�hannels()
{
	return amount_of_�hannels;
}
std::string Electrical_Equipment::Get_manufacturer()
{
	return manufacturer;
}
std::string Electrical_Equipment::Get_device_model()
{
	return device_model;
}
int Electrical_Equipment::Get_year_of_issue()
{
	return year_of_issue;
}