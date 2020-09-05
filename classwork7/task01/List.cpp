#include "List.h"
#include <iostream>
using namespace std;

template<typename T>
List<T>::List()
{
	size = 0;
	var = nullptr;
	isEmpty = true;
}

template<typename T>
List<T>::~List()
{
	delete[] var;
	var = nullptr;
	size = 0;
}

template<typename T>
List<T>::List(T* var, size_t size)
{
	SetVar(var);
	setSize(size);
}

template<typename T>
List<T>::List(const List& list, size_t size)
{
	SetVar(list.SetVar());
	setSize(list.getSize());
}

template<typename T>
void List<T>::SetVar(T* var)
{
	this->var = var;
}

template<typename T>
T List<T>::getVar() const
{
	return this->var;
}

template<typename T>
void List<T>::setEmpty(bool isEmpty)
{
	this->isEmpty = isEmpty;
}

template<typename T>
bool List<T>::getEmpty() const
{
	return this->isEmpty;
}

template<typename T>
size_t List<T>::getSize(size_t size)
{
	return this->size;
}

template<typename T>
void List<T>::setSize(size_t size)
{
	this->size = size;
}

template<typename T>
void List<T>::addBack(T nVar)
{
	if (size = 0)
	{
		this->var = new T[1]
			this->var[0] = nVar;
		this->size++;
	}
	newVar = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newVar[i] = var[i];
	}
	newVar[size] = nVar;
	this->size++;
	delete[] var;
	this->var = newVar;
}
template<typename T>
void List<T>::Delete(size_t index)
{
	if (index >= size)
	{
		cout << "Incorrect number";
		return;
	}
	this->size--;
	T* newList = new T[size];
	size_t count = 0;

	for (size_t i = 1; i < this->size; i++)
	{
		if (i != index)
			newList[count++] = this->var[i];
	}

	delete[] this->var;
	this->var = newList;
}
template<typename T>
void List<T>::addFront(T nVar)
{
	if (size = 0)
	{
		this->var = new T[1]
			this->var[0] = nVar;
		this->size++;
	}
	newVar = new T[size + 1];
	newVar[0] = nVar;
	for (size_t i = 0; i < size; i++)
	{
		newVar[i + 1] = var[i];
	}
	newVar[size] = nVar;
	this->size++;
	delete[] var;
	this->var = newVar;
}
template<typename T>
void List<T>::print()
{
	for (size_t i = 0; i < size; i++)
	{
		cout<<<<"[" << i << "] :" << var[i] << endl;
	}
}
template<typename T>
void List<T>::operator = (const List& data)
{
	delete[] this->list;

	this->list = data.get();
	this->size = data.getSize();
}
template<typename T>
const T& List<T>::operator [] (size_t index) const
{
	if (index >= 0 && index < getSize())
		return this->list[index];

	return none;
}
template<typename T>
void List<T> :: operator += (const List& data)
{
	T* newList = new T[getSize() + data.getSize()];

	for (size_t i = 0; i < this->size; i++)
		newList[i] = this->list[i];

	size_t count = 0;

	for (size_t i = getSize(); i < getSize() + data.getSize(); i++)
		newList[i] = data[count++];

	this->size = getSize() + data.getSize();
	delete[] this->list;
	this->list = newList;
}
template<typename T>
void List<T> ::operator += (const T& data)
{
	T* newList = new T[getSize() + 1];

	for (size_t i = 0; i < this->size; i++)
		newList[i] = this->list[i];

	newList[this->size] = data;

	this->size++;
	delete[] this->list;
	this->list = newList;
}

template<typename T>
void List<T>::find(size_t index)
{
	if (index >= size)
	{
		cout << "Incorrect number\n";
			return;
	}

	for (size_t i = 0; i < size; i++)
	{
		if(index==i)
		cout<<<<"[" << i << "] :" << var[i] << endl;
	}

}
template<typename T>

ostream& operator<<(ostream& out,const List<T>& var)
{
	out << "size: " << var.getSize() << endl;
	for (size_t i = 0; i < var.getSize(); i++)
		out << "[" << i << "] :\t" << var[i] << endl;
	return out;
}
template<typename T>

void List<T>::sort(size_t leftIndex, size_t rightIndex)
{
	int i = leftIndex, j = rightIndex;
	int middle = (rightIndex + leftIndex) / 2;

	do
	{
		while (this->var[i] < this->var[middle])
			i++;
		while (this->var[middle] < this->var[j])
			j--;

		if (i <= j)
		{
			swap(this->var[i], this->var[j]);
			i++;
			j--;
		}
	} while (i < j);

	if (leftIndex < j)
		sort(leftIndex, j);
	if (i < rightIndex)
		sort(i, rightIndex);
}
