#include "Document.h"

void Document::print()
{
	cout << "name of doc:" << _name << ".txt" << endl;
	cout << "size of doc: " << _size << " Bit" << endl;
	cout << "priority of doc: ";
	switch (_acces)
	{
	case Document::SUCKER:
		cout << "Sucker\n";
		break;
	case Document::WORKER:
		cout << "Worker\n";
		break;
	case Document::BOOKER:
		cout << "Booker\n";
		break;
	case Document::BOSS:
		cout << "Boss of this gym\n";
		break;
	case Document::NONE:
		cout << "None\n";
	default:
		break;
	}
}

bool Document::setName(string name)
{
	if (!name.empty())
	{
		_name = name;
		return true;
	}
	return false;
}

bool Document::setSize(size_t size)
{
	if (size < 200000)
	{
		_size = size;
		return true;
	}
	return false;
}

bool Document::setType(size_t acc)
{
	switch (acc)
	{
	case 0:
		_acces = SUCKER;
		return true;
		break;
	case 1:
		_acces = WORKER;
		return true;
		break;
	case 2:
		_acces = WORKER;
		return true;
		break;
	case 3:
		_acces = BOOKER;
		return true;
		break;
	case 4:
		_acces = BOSS;
		return true;
		break;
	default:
		_acces = NONE;
		return false;
		break;
	}
}

Document::Document()
{
	_name = "";
	_size = 0;
	_acces = NONE;
}
Document::Document(size_t size, string name, size_t acc)
{
	setSize(size);
	setName(name);
	setType(acc);
}
Document::~Document()
{
	_name = "";
	_size = 0;
	_acces = NONE;
}
Document::Document()
{
	_name = "";
	_size = 0;
	_acces = NONE;
}
