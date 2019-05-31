// lab_list.h
#pragma once

#include "electrical_equipment.h"

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

	void push_back(T *device);

	void show_all();

	T& operator[](unsigned int index);
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

template<class T>
inline void Lab_List<T>::show_all()
{
	for (int i = 0; i < this->amount_of_electrical_devices; i++)
	{
		std::cout << (*this)[i];
	}
}

template<class T>
inline T& Lab_List<T>::operator[](unsigned int index)
{
	T* p_current = this->head;
	for (int i = 0; i < index; i++)
	{
		p_current = p_current->p_next;
	}
	return *p_current;
}
