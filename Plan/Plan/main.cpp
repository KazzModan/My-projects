#include <Windows.h>
#include <iostream>
#define CHECK_TEXT ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= '0' && text[i] <= '9') || text[i] == ':')
using namespace std;

void ShowMenu();
void Menu();
template<typename T>
class SList
{
public:
	SList();

	void deleteFromHead();

	void deleteFromTail();

	void addToHead(T data);

	void addToTail(T data);

	void clear();

	size_t getSize() { return this->size; }

	void insert(T data, size_t index);

	void remove(size_t index);

	T& operator[](const size_t index);

	~SList();

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
SList<T>::SList()
{
	this->size = 0;
	this->head = nullptr;
}


template<typename T>
SList<T>::~SList()
{
	clear();
}


template<typename T>
void SList<T>::deleteFromHead()
{
	Node<T>* temp = head;

	this->head = this->head->next;

	delete temp;
	this->size--;
}

template<typename T>
void SList<T>::addToTail(T data)
{
	if (this->head == nullptr)
		this->head = new Node<T>(data);
	else
	{
		Node<T>* current = this->head;

		while (current->next != nullptr)
			current = current->next;
		current->next = new Node<T>(data);
	}

	this->size++;
}

template<typename T>
void SList<T>::clear()
{
	for (size_t i = 0; i < this->size; i++)
		deleteFromHead();
}


template<typename T>
T& SList<T>::operator[](const size_t index)
{
	size_t counter = 0;
	Node<T>* current = this->head;

	if (index >= this->size)
		throw "error you cannot access an index that does not innovate\n";

	while (current != nullptr)
	{
		if (counter == index)
			return current->data;

		current = current->next;
		counter++;
	}

	throw "error you cannot access an index that does not innovate\n";
}

template<typename T>
void SList<T>::addToHead(T data)
{
	this->head = new Node<T>(data, this->head);
	this->size++;
}

template<typename T>
void SList<T>::insert(T data, size_t index)
{

	if (index == 0)
		addToHead(data);
	else
	{
		Node<T>* previous = this->head;

		for (size_t i = 0; i < index - 1; i++)
			previous = previous->next;

		Node<T>* newNode = new Node<T>(data, previous->next);
		previous->next = newNode;
		this->size++;
	}
}

template<typename T>
void SList<T>::remove(size_t index)
{
	if (index == 0)
		deleteFromHead();
	else
	{
		Node<T>* previous = this->head;

		for (size_t i = 0; i < index - 1; i++)
			previous = previous->next;

		Node<T>* toDelete = previous->next;
		previous->next = toDelete->next;
		delete toDelete;

		this->size--;
	}

}

template<typename T>
void SList<T>::deleteFromTail()
{
	remove(size - 1);
}



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
	void print()
	{
		if (_day < 10)
			cout << "0" << _day;
		else
			cout << _day;
		if (_month < 10)
			cout << ":0" << _month;
		else
			cout << ":" << _month;
		cout << ":" << _year << endl;
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
		cout << "this event is important? Input y or n:\n";
		cin >> temp;
		if (temp == "y")
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
	bool getPrior() const
	{
		return _prior;
	}
	void print()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		if (this->getPrior())
		{
			SetConsoleTextAttribute(hConsole, WORD(4));
			cout << "name: " << this->_header << endl;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, WORD(2));
			cout << "name: " << this->_header << endl;
		}
		SetConsoleTextAttribute(hConsole, WORD(15));
		cout << "info: " << this->_info << endl;
	}
private:
	Data _data;
	bool _prior;
	string _header;
	string _info;
};
class Day
{
public:
	Day(const Day& day)
	{
		this->date = day.getDate();
		this->list = day.getList();
	}
	Day(Data date, SList<Event>list)
	{
		this->setDate(date);
		this->list = list;
	}
	Day()
	{

	}
	void addEvent()
	{
		Event tempEvent;
		string temp;

		do
		{
			cout << "enter event name: ";
			cin >> temp;
			tempEvent.setHeader(temp);
		} while (!tempEvent.setHeader(temp));

		do
		{
			cout << "enter event info: ";
			cin >> temp;
			tempEvent.setInfo(temp);
		} while (!tempEvent.setInfo(temp));

		tempEvent.setPrior();
		if (tempEvent.getPrior())
		{
			list.addToHead(tempEvent);
		}

		else
		{
			list.addToTail(tempEvent);
		}

	}
	void print()
	{
		this->date.print();

		for (size_t i = 0; i < list.getSize(); i++)
			list[i].print();
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
	void setDate(Data date)
	{
		this->date = date;
	}
	Data getDate() const
	{
		return this->date;
	}

	SList<Event> getList() const
	{
		return SList<Event>(list);
	}
private:
	Data date;
	SList<Event> list;
};
class Planner
{
public:
	void AddDay()
	{
		char choose = 0;
		SList<Event> list;
		int day, month, year;
		Data date;
		cout << "Enter day\n";
		cin >> day;
		date.setDay(day);
		cout << "Enteer month\n";
		cin >> month;
		date.setMonth(month);
		cout << "Enter year\n";
		cin >> year;
		date.setYear(year);
		Day dayEv;
		dayEv.setDate(date);
		this->list.addToHead(dayEv);
	}
	void ShowAllDay()
	{
		system("cls");

		for (size_t i = 0; i < list.getSize(); i++)
		{
			this->list[i].print();
			cout << endl;

		}
	}
	void AddEventToDay()
	{
		int index = findDay();
		if (index == -1)
			return;
		list[index].addEvent();
	}
	void removeDay()
	{
		int index = findDay();
		if (index == -1)
			return;
		list.remove(index);
	}
	void removeEventFromDay()
	{
		int index = findDay();
		if (index == -1)
			return;
		list[index].removeEvent();
	}
	int findDay()
	{
		size_t length = this->list.getSize();
		int index;

		do
		{
			cout << "enter day index or -1 to exit [ 0: " << length - 1 << " ]: ";
			cin >> index;

			if (index == -1)
				return -1;
		} while (size_t(index) < 0 || size_t(index) >= length);

		return index;
	}


	Planner()
	{

	}
private:
	SList<Day> list;
};
int main()
{
	Menu();
}
void ShowMenu()
{
	cout << "(1) Add day.\n";
	cout << "(2) Add event to day.\n";
	cout << "(3) show planner.\n";
	cout << "(4) remove day.\n";
	cout << "(5) remove event from day.\n";
	cout << "(0) exit from menu.\n";
}

void Menu()
{
	char choise;
	bool isWork = true;
	Planner planner;


	do
	{
		ShowMenu();
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case '1':
			planner.AddDay();
			break;
		case '2':
			planner.AddEventToDay();
			break;
		case '3':
			planner.ShowAllDay();
			break;
		case '4':
			planner.removeDay();
			break;
		case '5':
			planner.removeEventFromDay();
			break;
		case '0':
			isWork = false;
			break;
		}
	} while (isWork != false);


}
