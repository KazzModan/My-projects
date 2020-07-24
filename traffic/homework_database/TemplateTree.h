#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename T>
struct Node 
{
	T data;
	Node<T>* parent = nullptr;
	Node<T>* left = nullptr;
	Node<T>* rigth = nullptr;
};

template <typename T>
class TemplateTree
{
public:
	TemplateTree();

	void push(const T& newData);
	void print();
	T* find(T& key);
	void multipleFind(string key);

private:
	Node<T>* head;

	static void Show(Node<T>* element);
	static void ShowByFilter(Node<T>* element, string filter);
};

template<typename T>
inline TemplateTree<T>::TemplateTree()
{
	this->head = nullptr;
}

template<typename T>
inline void TemplateTree<T>::push(const T& newData)
{
	Node<T>* newElement = new Node<T>;
	newElement->data = newData;

	if (this->head == nullptr)
	{
		this->head = newElement;
		return;
	}

	Node<T>* current = this->head;
	Node<T>* temp = this->head;

	do
	{
		temp = current;

		if (newData == current->data)
			current = current->left;
		else if (newData > current->data)
			current = current->rigth;
		else
			current = current->left;

	} while (current != nullptr);

	newElement->parent = temp;

	if (newData == temp->data)
		temp->left = newElement;
	else if (newData > temp->data)
		temp->rigth = newElement;
	else if (newData < temp->data)
		temp->left = newElement;
}

template<typename T>
inline void TemplateTree<T>::print()
{
	Show(this->head);
}

template<typename T>
inline T* TemplateTree<T>::find(T& key)
{
	if (this->head == nullptr) 
		return nullptr;

	Node<T>* temp = this->head;
	Node<T>* current = this->head;

	do
	{
		temp = current;

		if (key == current->data)
			break;
		else if (key > current->data)
			current = current->rigth;
		else
			current = current->left;

	} while (current != nullptr);

	return &current->data;
}

template<typename T>
inline void TemplateTree<T>::multipleFind(string key)
{
	if (this->head != nullptr)
		ShowByFilter(this->head, key);
}

template<typename T>
inline void TemplateTree<T>::Show(Node<T>* element)
{
	if (element == nullptr)
		return;

	cout << element->data << endl;

	Show(element->left);
	Show(element->rigth);
}

template<typename T>
inline void TemplateTree<T>::ShowByFilter(Node<T>* element, string filter)
{
	if (element == nullptr)
		return;

	if (element->data == filter)
		cout << element->data << endl;

	ShowByFilter(element->left, filter);
	ShowByFilter(element->rigth, filter);
}
