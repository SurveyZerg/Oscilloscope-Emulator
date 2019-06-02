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
	void swap(unsigned int D1, unsigned int D2);

	void clear();
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
inline void Lab_List<T>::swap(unsigned int D1, unsigned int D2)
{
	//Здесь нужно проверку делать на голову и хвост у второго и первого индекса, чтобы не сбился коннект
	if (D1 == D2)
	{
		std::cout << "Ты дебил?" << std::endl;
	}
	if (D2 > D1)
	{
		int temp = D1;
		D2 = D1;
		D1 = temp;
	}

	if (((D2 - 1) == D1) || ((D1 - 1) == D2))
	{
		T* temp1 = head;
		T* temp2 = head;

		for (int i = 0; i < (D1 - 1); i++)
		{
			temp1 = temp1->p_next;
		}
		for (int i = 0; i < (D2 + 1); i++)
		{
			temp2 = temp2->p_next;
		}

		temp1->p_next = &((*this)[D2]);
		temp2->p_prev = &((*this)[D1]);
		/* Эта хуйня работает, но так не делается, пацаны
		T* a = &((*this)[D2]);
		a->p_prev = temp1;
		*/
		(*this)[D2].p_prev = temp1;
		(*this)[D2].p_next = &((*this)[D1]);
		(*this)[D1].p_prev = &((*this)[D2]);
		(*this)[D1].p_next = temp2;
		// понять, как работает присвоение ссылок
		//плохо работает
	}
	else
	{
		T* temp_D1_1 = head;
		T* temp_D1_2 = head;
		T* temp_D2_1 = head;
		T* temp_D2_2 = head;
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
inline T& Lab_List<T>::operator[](unsigned int index)
{
	T* p_current = this->head;
	for (int i = 0; i < index; i++)
	{
		p_current = p_current->p_next;
	}
	return *p_current;
}
