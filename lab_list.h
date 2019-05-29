// lab_list.h
#pragma once

#include "electrical_equipment.h"

template <class T>
class Lab_List
{
private:
	 
	Electrical_Equipment* head;
	Electrical_Equipment* tail;

	int amount_of_electrical_devices;
public:
	Lab_List();
	~Lab_List();

	void push_back(T *device);
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
	//this->clear();
}

template<class T>
inline void Lab_List<T>::push_back(T *device)
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
		device->p_prev = this->tail;
		this->tail = this->tail->p_next;
		this->tail = device;
		device->p_next = nullptr;
		this->amount_of_electrical_devices++;
	}
}
