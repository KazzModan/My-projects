#pragma once
#include<iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* next;
};


template <typename T>
class SList
{
public:
	SList() = default;
	void addOnFirst(const T& element);
	void addOnLast(const T& element);
	void deleteFirst();
	void print();
	bool isEmpty();
	void DeleteAll();
	~SList();
private:
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	int size = 0;
};
template<typename T>
inline void SList<T>::addOnFirst(const T& element)
{
	Node<T>* newNode = new Node<T>{ element, nullptr };
	if (isEmpty()) {
		first = newNode;
		last = newNode;
	}
	else {
		newNode->next = first;
		first = newNode;
	}
	++size;
}

template<typename T>
inline void SList<T>::addOnLast(const T& element)
{
	Node<T>* newNode = new Node<T>{ element, nullptr };
	if (isEmpty()) {
		first = newNode;
		last = newNode;
	}
	else
	{
		++size;
		Node<T>* newNode = new Node<T>{ element, nullptr };
		last = newNode;
		Node<T>* temp = first;
		for (int i = 0; i < size; i++)
		{
			if (i == size - 2)
				temp->next = last;
			else
				temp = temp->next;
		}
	}
}

template<typename T>
inline void SList<T>::deleteFirst()
{
	Node<T>* temp = first->next;
	delete first;
	first = temp;
	this->size--;
}

template<typename T>
inline void SList<T>::print()
{
	if (isEmpty())
		return;
	Node<T>* temp = first;
	cout << "List: \t";
	while (temp != nullptr)
	{
		cout << temp->data << "\t ";
		temp = temp->next;
	}
	cout << endl;
}

template<typename T>
inline bool SList<T>::isEmpty()
{
	return first == nullptr;
}

template<typename T>
inline void SList<T>::DeleteAll()

{
	if (!isEmpty())
	{
		for (size_t i = 0; i < size; i++)
			deleteFirst();

		size = 0;
	}
}


template<typename T>
inline SList<T>::~SList()
{
	if (!isEmpty()) {
		delete first;
		delete last;
	}
}