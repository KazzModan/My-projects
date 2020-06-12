
#include <iostream>
using namespace std;
#define CHECK_TEXT ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= '0' && text[i] <= '9') || text[i] == ':')
template<typename T>
class List
{
public:
	List();

	//pop front
	void pop_front();

	//pop back
	void pop_back();

	//push front
	void push_front(T data);

	//push back
	void push_back(T data);

	//clear - delete all elements
	void clear();

	//get size
	size_t getSize() { return size; }

	//insert element to index
	void insert(T data, size_t index);

	//remove element at index
	void remove(size_t index);

	//operator []
	T& operator[](const size_t index);

	~List();

private:
	template<typename T>
	class Node
	{
	public:
		Node* next;
		T data;

		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	size_t size;
	Node<T>* head;
};


template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->next;

	delete temp;
	size--;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
		head = new Node<T>(data);
	else
	{
		Node<T>* current = this->head;

		while (current->next != nullptr)
			current = current->next;
		current->next = new Node<T>(data);
	}

	size++;
}

template<typename T>
void List<T>::clear()
{
	for (size_t i = 0; i < size; i++)
		pop_front();
}


template<typename T>
T& List<T>::operator[](const size_t index)
{
	size_t counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
			return current->data;

		current = current->next;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::insert(T data, size_t index)
{

	if (index == 0)
		push_front(data);
	else
	{
		Node<T>* previous = this->head;

		for (size_t i = 0; i < index - 1; i++)
			previous = previous->next;

		Node<T>* newNode = new Node<T>(data, previous->next);
		previous->next = newNode;
		size++;
	}
}

template<typename T>
void List<T>::remove(size_t index)
{
	if (index == 0)
		pop_front();
	else
	{
		Node<T>* previous = this->head;

		for (size_t i = 0; i < index - 1; i++)
			previous = previous->next;

		Node<T>* toDelete = previous->next;
		previous->next = toDelete->next;
		delete toDelete;

		size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	remove(size - 1);
}
class Planner
{
public:

private:
	List<Day> list;
};

class Day
{
public:
	Day(const Day& day)
	{
		this->date = day.getDate();
		this->list = day.getList();
	}

	void addEvent()
	{
		Event tempEvent;
		string temp;

		do
		{
			cout << "enter event name: ";
			cin >> temp;

		} while (!tempEvent.setHeader(temp));

		do
		{
			cout << "enter event info: ";
			 cin>>temp;

		} while (!tempEvent.setInfo(temp));

		do
		{
			cout << "this event is important? enter yes or no";
			cin >> temp;

		} while (temp != "yes" && temp != "no");

		if (tempEvent.setPrior)
		{
			list.push_front(tempEvent);
		}
		else
		{
			this->list.push_back(tempEvent);
		}
	}
	

	void removeEvent()
	{
		size_t length = this->list.getSize();
		size_t index;

		do
		{
			cout << "enter event index [0: " << length - 1 << " ]: ";
			cin >> index;
		} while (index < 0 || index >= length);

		this->list.remove(index);
	}

	void setDate()
	{
		size_t day;
		size_t month;
		size_t year;
			cout << "enter number of day, month and year : ";
			cin >> day >> month >> year;
	}
	Data getDate() const
	{
		return this->date;
	}

	List<Event> getList() const
	{
		return List<Event>(list);
	}
private:
	Data date;
	List<Event> list;
};
class Data
{
public:
	Data()
	{
		_day = 0;
		_month = 0;
		_year = 0;
	}
	~Data()
	{
		_day = 0;
		_month = 0;
		_year = 0;
	}
	void setDay(size_t day)
	{
		if (day >= MIN_DAY && day <= MAX_DAY)
		{
			_day = day;
		}
	}
	void setMonth(size_t month)
	{
		if (month >= MIN_MONTH && month <= MAX_MONTH)
		{
			_month = month;
		}
	}
	void setYear(size_t year)
	{
		if (year >= MIN_YEAR && year <= MAX_YEAR)
		{
			_year = year;
		}
	}
	enum LIMITS
	{
		MIN_DAY = 1, MIN_MONTH = 1, MIN_YEAR = 2020, MAX_DAY = 31, MAX_MONTH = 12, MAX_YEAR = 2077
	};
private:
	size_t _day;
	size_t _month;
	size_t _year;
};
class Event
{
public:
	void setDate(size_t day, size_t month, size_t year)
	{
		_data.setDay(day);
		_data.setMonth(month);
		_data.setYear(year);
	}
	bool setHeader(string text)
	{
		size_t length = text.length();
		size_t count = 0;

		for (size_t i = 0; i < length; i++)
			if (CHECK_TEXT)
				count++;
		if (count == length)
		{
			_header = text;
			return true;
		}
		return false;
	}
	void setPrior()
	{
		string temp;
		cout << "this event is important? Input yes or not: ";
		cin >> temp;
		if (temp == "yes")
		{
			_prior = true;
		}
		else
			_prior = false;
	}
	bool setInfo(string text)
	{
		size_t length = text.length();
		size_t count = 0;

		for (size_t i = 0; i < length; i++)
			if (CHECK_TEXT)
				count++;
		if (count == length)
		{
			_info = text;
			return true;
		}
		return false;
	}
private:
	Data _data;
	bool _prior;
	string _header;
	string _info;
};
int main()
{
}