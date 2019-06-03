// lab_list.h
#pragma once

#include "./include/Devices/electrical_equipment.h"

template <class T>
class Lab_List
{
private:
	 
	T* head;
	T* tail;

	int amount_of_electrical_devices;

public:
	Lab_List();
	~Lab_List();

	T* begin();
	int size();


	void push_back(T* device);
	void push_front(T* device);
	void insert(T* device, int index);
	void swap(int D1, int D2);

	void clear();
	void show_all();

	T& operator[](int index);
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
		device->p_prev = this->tail; // предыдущий элемент девайса

		device->p_prev->p_next = device; // след элемент пред девайса

		this->tail = device; // хвост

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
			throw std::exception("ERROR # \nYou tried to swap negative element of list, that of course doesnt exist\n");
		}
		if (D1 > (this->size() - 1) || D2 > (this->size() - 1))
		{
			throw std::exception("ERROR # \nYou tried to swap element beyond the list\n");
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
inline void Lab_List<T>::clear()
{
	for (int i = 0; i < this->size(); i++)
	{
		T* temp = tail;
		tail = tail->p_prev;
		delete temp;
	}
	amount_of_electrical_devices = 0;
}

template<class T>
inline void Lab_List<T>::show_all()
{
	for (int i = 0; i < this->amount_of_electrical_devices; i++)
	{
		std::cout << (*this)[i];
	}
}

template<class T>
inline T& Lab_List<T>::operator[](int index)
{
	try
	{
		if (index < 0)
		{
			throw std::exception("ERROR # \nElements of list begin from 0, not negative number\n");
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
