//researcher.cpp

#include "researcher.h"

Researcher::Researcher(std::string research_position, std::string name, std::string surname, int age)
{
#ifdef _DEBUG
	std::cout << "Constructor Researcher was called" << std::endl;
#endif

	this->research_position = research_position;
	this->name = name;
	this->surname = surname;
	this->age = age;
}
Researcher::~Researcher()
{
#ifdef _DEBUG
	std::cout << "Default Destructor Researcher was called" << std::endl;
#endif
}

std::string Researcher :: Get_research_position()
{
	return research_position;
}
std::string Researcher :: Get_name()
{
	return name;
}
std::string Researcher :: Get_surname()
{
	return surname;
}
int Researcher :: Get_age()
{
	return age;
}

std::ostream& operator<< (std::ostream &out, Researcher &scientist)
{
	out << "---------" << std::endl << scientist.Get_research_position() << " " << scientist.Get_surname() << " " << scientist.Get_name() << "(age "
		<< scientist.Get_age() << ")" << std::endl <<"---------" << std::endl;
	return out;
}

void Researcher::Connect(Oscilloscope &osc, int number_of_channel_osc, Generator &gen, int number_of_channel_gen)
{
	//Проверка на дурака
	if (number_of_channel_osc > osc.Get_amount_of_сhannels() || number_of_channel_osc < 1)
	{
		std::cout << "ERROR #1\nYou picked channel of Oscilloscope, that doesn't exist\n";
		system("Pause");
		exit(EXIT_FAILURE); //Вызывает ли это деструкторы, как проверить?
	}
	if (number_of_channel_gen > gen.Get_amount_of_сhannels() || number_of_channel_gen < 1)
	{
		std::cout << "ERROR #2\nYou picked channel of Generator, that doesn't exist\n";
		system("Pause");
		exit(EXIT_FAILURE); //Вызывает ли это деструкторы, как проверить?
	}
	if (osc.Get_connection_of_channel(number_of_channel_osc) == true)
	{
		std::cout << "ERROR #3\nYou picked channel of Oscilloscope, that is already busy\n";
		system("Pause");
		exit(EXIT_FAILURE); //Вызывает ли это деструкторы, как проверить?
	}
	if (gen.Get_connection_of_channel(number_of_channel_gen) == true)
	{
		std::cout << "ERROR #4\nYou picked channel of Generator, that is already busy\n";
		system("Pause");
		exit(EXIT_FAILURE); //Вызывает ли это деструкторы, как проверить?
	}

	//Подключение
	osc.Set_connection_of_channel(number_of_channel_osc, true);
	gen.Set_connection_of_channel(number_of_channel_gen, true);

	//Cвязывание характеристик
	/* Нужно создать масштаб у осциллографов в хедере осциллографов общем, чтобы контролировать периоды и амплитуду, чтобы видеть весь сигнал и делать правильные измерения
	Для этого можно частоту генератора функции переводить в период и кол-во клеток умножить на настройку подставы часа должно быть больше либо равно этого периода */
}