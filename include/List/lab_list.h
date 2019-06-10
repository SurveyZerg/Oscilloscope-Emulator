// lab_list.h
#pragma once

#include <fstream>
#include "./include/Devices/electrical_equipment.h"

template <class T>
class Lab_List
{
private:
	 
	T* head;
	T* tail;

	int amount_of_electrical_devices;

	T* addDevice(std::ifstream& load);
	T* addDevice(T device);

public:
	Lab_List();
	~Lab_List();

	T* begin();
	T* addDevice(bool info);

	int size();

	void push_back(T* device);
	void push_front(T* device);
	void pop_back();
	void pop_front();

	void insert(T* device, int index);
	void erase(int index);
	void swap(int D1, int D2);

	bool contains(T &device);
	int indexOf(const T &device);

	void moveToFront(int index);
	void moveToEnd(int index);

	void clear();
	Lab_List<T>& operator= (Lab_List<T> &list);
	T& operator[](int index);

	//friend std::istream& operator >> (std::istream &in, Lab_List<T> &list);
	//friend std::ifstream& operator >> (std::ifstream &in, Lab_List<T> &list);

	friend std::istream& operator >> (std::istream &in, Lab_List<Analog_Oscilloscope> &list);
	friend std::ifstream& operator >> (std::ifstream &in, Lab_List<Analog_Oscilloscope> &list);

	friend std::istream& operator >> (std::istream &in, Lab_List<Digital_Oscilloscope> &list);
	friend std::ifstream& operator >> (std::ifstream &in, Lab_List<Digital_Oscilloscope> &list);

	friend std::istream& operator >> (std::istream &in, Lab_List<Generator> &list);
	friend std::ifstream& operator >> (std::ifstream &in, Lab_List<Generator> &list);

	friend std::ostream& operator << (std::ostream &out, Lab_List<Analog_Oscilloscope> &list);
	friend std::ostream& operator << (std::ostream &out, Lab_List<Digital_Oscilloscope> &list);
	friend std::ostream& operator << (std::ostream &out, Lab_List<Generator> &list);
};

template<class T>
inline Lab_List<T>::Lab_List()
{
	this->head = nullptr;
	this->tail = nullptr;
	amount_of_electrical_devices = 0;
}

template<class T>
inline Lab_List<T>::~Lab_List()
{
	this->clear();
}

template<class T>
inline T * Lab_List<T>::begin()
{
	return this->head;
}

template<class T>
inline int Lab_List<T>::size()
{
	return this->amount_of_electrical_devices;
}

template<class T>
inline void Lab_List<T>::push_back(T* device)
{
	if (this->head == nullptr)
	{
		this->head = device;
		this->tail = this->head;
		device->p_next = nullptr;
		device->p_prev = nullptr;
		this->amount_of_electrical_devices++;
	}
	else
	{
		//Мы должны обработать хвост, след и пред элемент девайса и след элемент прошлого девайса
		device->p_prev = tail; // предыдущий элемент девайса

		tail->p_next = device; // след элемент пред девайса

		tail = device; // хвост

		device->p_next = nullptr; // след элемент девайса

		this->amount_of_electrical_devices++;
	}
}

template<class T>
inline void Lab_List<T>::push_front(T* device)
{
	if (this->head == nullptr)
	{
		head = device;
		tail = device;
		device->p_next = nullptr;
		device->p_prev = nullptr;
	}
	else
	{
		T* temp = head;
		head = device;
		device->p_next = temp;
		temp->p_prev = head;
		device->p_prev = nullptr;
	}
	amount_of_electrical_devices++;
}

template<class T>
inline void Lab_List<T>::pop_back()
{
	if (amount_of_electrical_devices == 0) {}
	else if (amount_of_electrical_devices == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		amount_of_electrical_devices--;
	}
	else
	{
		T* temp = tail;
		tail = tail->p_prev;
		tail->p_next = nullptr;
		delete temp;
		amount_of_electrical_devices--;
	}
}

template<class T>
inline void Lab_List<T>::pop_front()
{
	if (amount_of_electrical_devices == 0) {}
	else if (amount_of_electrical_devices == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		amount_of_electrical_devices--;
	}
	else
	{
		T* temp = head;
		head = head->p_next;
		head->p_prev = nullptr;
		delete temp;
		amount_of_electrical_devices--;
	}
}

template<class T>
inline void Lab_List<T>::insert(T* device, int index)
{
	if (this->size() == 0)
	{
		this->push_front(device);
	}
	else
	{
		if (index == 0)
		{
			this->push_front(device);
		}
		else if (index == this->size())
		{
			this->push_back(device);
		}
		else
		{
			T* temp1 = head;
			T* temp2 = head;
			for (int i = 0; i < index - 1; i++)
			{
				temp1 = temp1->p_next;
			}
			for (int i = 0; i < index; i++)
			{
				temp2 = temp2->p_next;
			}
			temp1->p_next = device;
			temp2->p_prev = device;
			device->p_prev = temp1;
			device->p_next = temp2;
			amount_of_electrical_devices++;
		}
	}
}

template<class T>
inline void Lab_List<T>::erase(int index)
{
	if (this->size() == 0) {}
	else
	{
		if (index == 0)
			this->pop_front();
		else if (index == (this->size() - 1))
			this->pop_back();
		else
		{
			T* temp1 = head;
			T* temp2 = head;
			T* temp_delete = head;
			for (int i = 0; i < index - 1; i++)
			{
				temp1 = temp1->p_next;
			}
			for (int i = 0; i < index; i++)
			{
				temp_delete = temp_delete->p_next;
			}
			for (int i = 0; i < index + 1; i++)
			{
				temp2 = temp2->p_next;
			}
			temp1->p_next = temp2;
			temp2->p_prev = temp1;
			delete temp_delete;
			amount_of_electrical_devices--;
		}
	}
}

template<class T>
inline void Lab_List<T>::swap(int D1, int D2)
{
	try
	{
		//Здесь нужно проверку делать на голову и хвост у второго и первого индекса, чтобы не сбился коннект
		if (D1 == D2)
		{
			throw std::exception("You tried to swap the same item\nDid you really want it??\n");
		}
		if (D1 > D2)
		{
			int temp = D2;
			D2 = D1;
			D1 = temp;
		}
		if (D1 < 0 || D2 < 0)
		{
			throw std::exception("ERROR #12\nYou tried to swap negative element of list, that of course doesnt exist\n");
		}
		if (D1 > (this->size() - 1) || D2 > (this->size() - 1))
		{
			throw std::exception("ERROR #12\nYou tried to swap element beyond the list\n");
		}
		T* device1 = &((*this)[D1]);
		T* device2 = &((*this)[D2]);

		if (((D2 - 1) == D1) || ((D1 - 1) == D2))
		{
			T* temp1;
			T* temp2;

			if (D1 != 0 && D2 != (this->size() - 1))
			{
				temp1 = head;
				temp2 = head;

				for (int i = 0; i < (D1 - 1); i++)
				{
					temp1 = temp1->p_next;
				}
				for (int i = 0; i < (D2 + 1); i++)
				{
					temp2 = temp2->p_next;
				}

				temp1->p_next = device2;
				temp2->p_prev = device1;

				device2->p_prev = temp1;
				device2->p_next = device1;
				device1->p_prev = device2;
				device1->p_next = temp2;
			}
			else if (D1 == 0 && D2 != (this->size() - 1))
			{
				temp1 = nullptr;
				temp2 = head;

				for (int i = 0; i < (D2 + 1); i++)
				{
					temp2 = temp2->p_next;
				}

				head = device2;
				device2->p_prev = temp1;
				device2->p_next = device1;
				temp2->p_prev = device1;
				device1->p_prev = device2;
				device1->p_next = temp2;
			}
			else if (D1 != 0 && D2 == (this->size() - 1))
			{
				temp1 = head;
				temp2 = nullptr;

				for (int i = 0; i < (D1 - 1); i++)
				{
					temp1 = temp1->p_next;
				}

				tail = device1;
				device1->p_next = temp2;
				device1->p_prev = device2;
				temp1->p_next = device2;
				device2->p_next = device1;
				device2->p_prev = temp1;
			}
			else if (D1 == 0 && D2 == (this->size() - 1))
			{
				temp1 = nullptr;
				temp2 = nullptr;

				tail = device1;
				head = device2;

				device1->p_next = temp2;
				device1->p_prev = device2;

				device2->p_next = device1;
				device2->p_prev = temp1;
			}
		}
		else
		{
			T* temp_D1_1;
			T* temp_D1_2;
			T* temp_D2_1;
			T* temp_D2_2;

			if (D1 != 0 && D2 != (this->size() - 1))
			{
				temp_D1_1 = head;
				temp_D1_2 = head;
				temp_D2_1 = head;
				temp_D2_2 = head;

				for (int i = 0; i < (D1 - 1); i++)
				{
					temp_D1_1 = temp_D1_1->p_next;
				}
				for (int i = 0; i < (D1 + 1); i++)
				{
					temp_D1_2 = temp_D1_2->p_next;
				}

				for (int i = 0; i < (D2 - 1); i++)
				{
					temp_D2_1 = temp_D2_1->p_next;
				}
				for (int i = 0; i < (D2 + 1); i++)
				{
					temp_D2_2 = temp_D2_2->p_next;
				}

				//Не уверен, но может появится ошибка, если элементы меняются через один
				temp_D1_1->p_next = device2;
				temp_D1_2->p_prev = device2;
				temp_D2_1->p_next = device1;
				temp_D2_2->p_prev = device1;

				device1->p_prev = temp_D2_1;
				device1->p_next = temp_D2_2;
				device2->p_prev = temp_D1_1;
				device2->p_next = temp_D1_2;
			}
			else if (D1 == 0 && D2 != (this->size() - 1))
			{
				temp_D1_1 = nullptr;
				temp_D1_2 = head;
				temp_D2_1 = head;
				temp_D2_2 = head;

				for (int i = 0; i < (D1 + 1); i++)
				{
					temp_D1_2 = temp_D1_2->p_next;
				}

				for (int i = 0; i < (D2 - 1); i++)
				{
					temp_D2_1 = temp_D2_1->p_next;
				}
				for (int i = 0; i < (D2 + 1); i++)
				{
					temp_D2_2 = temp_D2_2->p_next;
				}

				//Не уверен, но может появится ошибка, если элементы меняются через один
				head = device2;
				temp_D1_2->p_prev = device2;
				temp_D2_1->p_next = device1;
				temp_D2_2->p_prev = device1;

				device1->p_prev = temp_D2_1;
				device1->p_next = temp_D2_2;
				device2->p_prev = temp_D1_1;
				device2->p_next = temp_D1_2;
			}
			else if (D1 != 0 && D2 == (this->size() - 1))
			{
				temp_D1_1 = head;
				temp_D1_2 = head;
				temp_D2_1 = head;
				temp_D2_2 = nullptr;

				for (int i = 0; i < (D1 - 1); i++)
				{
					temp_D1_1 = temp_D1_1->p_next;
				}
				for (int i = 0; i < (D1 + 1); i++)
				{
					temp_D1_2 = temp_D1_2->p_next;
				}

				for (int i = 0; i < (D2 - 1); i++)
				{
					temp_D2_1 = temp_D2_1->p_next;
				}

				temp_D1_1->p_next = device2;
				temp_D1_2->p_prev = device2;
				temp_D2_1->p_next = device1;
				tail = device1;

				device1->p_prev = temp_D2_1;
				device1->p_next = temp_D2_2;
				device2->p_prev = temp_D1_1;
				device2->p_next = temp_D1_2;

			}
			else if (D1 == 0 && D2 == (this->size() - 1))
			{
				temp_D1_1 = nullptr;
				temp_D1_2 = head;
				temp_D2_1 = head;
				temp_D2_2 = nullptr;

				for (int i = 0; i < (D1 + 1); i++)
				{
					temp_D1_2 = temp_D1_2->p_next;
				}

				for (int i = 0; i < (D2 - 1); i++)
				{
					temp_D2_1 = temp_D2_1->p_next;
				}

				head = device2;
				temp_D1_2->p_prev = device2;
				temp_D2_1->p_next = device1;
				tail = device1;

				device1->p_prev = temp_D2_1;
				device1->p_next = temp_D2_2;
				device2->p_prev = temp_D1_1;
				device2->p_next = temp_D1_2;
			}
		}
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what();
		system("Pause");
	}
}

template<class T>
inline bool Lab_List<T>::contains(T & device)
{
	bool flag = false;
	T* temp = head;
	for (int i = 0; temp!=nullptr; i++)
	{
		if (temp == &device)
			flag = true;
		temp = temp->p_next;
	}
	return flag;
}

template<class T>
inline int Lab_List<T>::indexOf(const T & device)
{
	if (!contains(device))
		throw std::exception("ERROR #13\nObject isn't in a list\n");
	else
	{
		T*temp = head;
		for (int i = 0;temp != nullptr; i++)
		{
			if (temp == &(*this[i]))
				return i;
			temp = temp->p_next;
		}
	}
}

template<class T>
inline void Lab_List<T>::moveToFront(int index)
{
	if (this->size() == 0)
	{
		throw std::exception("List is empty\n");
		return;
	}
	T temp = addDevice(*this[index]);
	this->erase(index);
	this->push_front(&(*this[index]));
}

template<class T>
inline void Lab_List<T>::moveToEnd(int index)
{
	if (this->size() == 0)
	{
		throw std::exception("List is empty\n");
		return;
	}
	T temp = addDevice(*this[index]);
	this->erase(index);
	this->push_back(&(*this[index]));
}

template<class T>
inline void Lab_List<T>::clear()
{
	for (int i = 0; i < this->size(); i++)
	{
		T* temp = tail;
		tail = tail->p_prev;
		delete temp;
	}
	head = nullptr;
	tail = nullptr;
	amount_of_electrical_devices = 0;
}

template<class T>
inline Lab_List<T>& Lab_List<T>::operator=(Lab_List<T> &list)
{
	this->clear();
	for (int i = 0; i < list.size(); i++)
		this->push_back(this->addDevice(list[i]));
	return *this;
}

template<class T>
inline T * Lab_List<T>::addDevice(bool info)
{
	T* temp;
	temp = new T(info);
	return temp;
}

template<class T>
inline T * Lab_List<T>::addDevice(std::ifstream &load)
{
	T* temp;
	temp = new T(load);
	return temp;
}

template<class T>
inline T * Lab_List<T>::addDevice(T device)
{
	T* temp;
	temp = new T(device);
	return temp;
}

template<class T>
T& Lab_List<T>::operator[](int index)
{
	try
	{
		if (index < 0)
		{
			throw std::exception("ERROR #12\nElements of list begin from 0, not negative number\n");
		}
		T* p_current = this->head;
		for (int i = 0; i < index; i++)
		{
			p_current = p_current->p_next;
		}
		return *p_current;
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what();
		system("Pause");
	}
}

//Если использовать шаблоны, то вылезает ошибка LNK2001
//Jeżeli się korzystać z szablonów, otrzymam błąd LNK2001
/*
template<class T>
std::istream& operator>> (std::istream &in, Lab_List<T> &list)
{
	if (&in == &std::cin)
	{
		int temp;
		list.clear();
		std::cout << "Choose size of list\n";
		std::cin >> temp;
		list.setSize(temp);
		std::cout << std::endl;
		for (int i = 0; i < list.size(); i++)
		{
			std::cout << "Device #" << i + 1 << std::endl;
			list.push_back(list.addDevice(1));
			std::cout << std::endl;
		}
		return in;
	}
}
template<class T>
std::ifstream& operator>> (std::ifstream &in, Lab_List<T> &list)
{
	while(!in.eof())
	{
		list.push_back(list.addDevice(in));
	}
	return in;
}*/

std::istream& operator>> (std::istream &in, Lab_List<Analog_Oscilloscope> &list)
{
	if (&in == &std::cin)
	{
		int temp;
		std::cout << "Choose amount of analog oscilloscopes, that you want to add - ";
		std::cin >> temp;
		while (std::cin.fail() || temp < 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Amount of analog oscilloscopes, that you want to add, must be natural number\nTry again\nChoose amount of analog oscilloscopes, that you want to add - ";
			std::cin >> temp;
		}
		std::cout << std::endl;
		if (temp == 0)
		{
			return in;
		}
		else
		{
			for (int i = 0; i < temp; i++)
			{
				std::cout << "Analog Oscilloscope #" << list.size() + 1 << std::endl;
				list.push_back(list.addDevice(1));
				std::cout << std::endl;
			}
			return in;
		}
	}
}
std::ifstream& operator>> (std::ifstream &in, Lab_List<Analog_Oscilloscope> &list)
{
	while (!in.eof())
	{
		try
		{
			list.push_back(list.addDevice(in));
		}
		catch (const std::exception &ex)
		{
			std::cout << ex.what();
			system("Pause");
		}
	}
	return in;
}

std::istream& operator>> (std::istream &in, Lab_List<Digital_Oscilloscope> &list)
{
	if (&in == &std::cin)
	{
		int temp;
		std::cout << "Choose amount of digital oscilloscopes, that you want to add - ";
		std::cin >> temp;
		while (std::cin.fail() || temp < 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Amount of digital oscilloscopes, that you want to add, must be natural number\nTry again\nChoose amount of digital oscilloscopes, that you want to add - ";
			std::cin >> temp;
		}
		std::cout << std::endl;
		if (temp == 0)
		{
			return in;
		}
		else
		{
			for (int i = 0; i < temp; i++)
			{
				std::cout << "Digital Oscilloscope #" << list.size() + 1 << std::endl;
				list.push_back(list.addDevice(1));
				std::cout << std::endl;
			}
			return in;
		}
	}
}
std::ifstream& operator>> (std::ifstream &in, Lab_List<Digital_Oscilloscope> &list)
{
	{
		while (!in.eof())
		{
			try
			{
				list.push_back(list.addDevice(in));
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what();
				system("Pause");
			}
		}
		return in;
	}
}

std::istream& operator>> (std::istream &in, Lab_List<Generator> &list)
{
	if (&in == &std::cin)
	{
		int temp;
		std::cout << "Choose amount of generators, that you want to add - ";
		std::cin >> temp;
		while (std::cin.fail() || temp < 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Amount of generators, that you want to add, must be natural number\nTry again\nChoose amount of generators, that you want to add - ";
			std::cin >> temp;
		}
		std::cout << std::endl;
		if (temp == 0)
		{
			return in;
		}
		else
		{
			for (int i = 0; i < temp; i++)
			{
				std::cout << "Generator #" << list.size() + 1 << std::endl;
				list.push_back(list.addDevice(1));
				std::cout << std::endl;
			}
			return in;
		}
	}
}
std::ifstream& operator>> (std::ifstream &in, Lab_List<Generator> &list)
{
	while (!in.eof())
	{
		try
		{
			list.push_back(list.addDevice(in));
		}
		catch (const std::exception &ex)
		{
			std::cout << ex.what();
			system("Pause");
		}
	}
	return in;
}

std::ostream& operator << (std::ostream &out, Lab_List<Analog_Oscilloscope> &list)
{
	for (int i = 0; i < list.size(); i++)
	{
		out << "ANALOG OSCILLOSCOPE #" << i + 1 << std::endl;
		out << list[i];
	}
	return out;
}
std::ostream& operator << (std::ostream &out, Lab_List<Digital_Oscilloscope> &list)
{
	for (int i = 0; i < list.size(); i++)
	{
		out << "DIGITAL OSCILLOSCOPE #" << i + 1 << std::endl;
		out << list[i];
	}
	return out;
}
std::ostream& operator << (std::ostream &out, Lab_List<Generator> &list)
{
	for (int i = 0; i < list.size(); i++)
	{
		out << "GENERATOR #" << i + 1 << std::endl;
		out << list[i];
	}
	return out;
}