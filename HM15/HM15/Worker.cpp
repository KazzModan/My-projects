#include "Worker.h"

Worker::Worker()
{
	this->name = "no name";
	this->age = 0;
	this->expirience = 0;
	this->salary = 0;
	this->positionRatings = 0;
	this->status = Status::NONE;
}

Worker::Worker(string name, size_t age, size_t expirience, size_t salary, size_t position, Status status)
{
	setName(name);
	setAge(age);
	setExpirience(expirience);
	setSalary(salary);
	setPositionRatings(position);
	setStatus(status);
}

bool Worker::setName(string name)
{
	return ch::CheckPeopleName(this->name, name);
}

bool Worker::setAge(size_t age)
{
	return ch::CheckRangeEnum(this->age, age, 0, MAX_AGE);
}

bool Worker::setExpirience(size_t expirience)
{
	return ch::CheckRangeEnum(this->expirience, expirience, 0, MAX_EXPIRIENCE);
}

bool Worker::setSalary(size_t salary)
{
	return ch::CheckRangeEnum(this->salary, salary, 0, MAX_SALARY);
}

bool Worker::setPositionRatings(size_t position)
{
	return ch::CheckRangeEnum(this->positionRatings, position, 0, MAX_POSITION);
}

bool Worker::setStatus(Status status)
{
	this->status = status;
	return true;
}

string Worker::getName() const
{
	return this->name;
}

size_t Worker::getAge() const
{
	return this->age;
}

size_t Worker::getExpirience() const
{
	return this->expirience;
}

size_t Worker::getSalary() const
{
	return this->salary;
}

size_t Worker::getPositionRatings() const
{
	return this->positionRatings;
}

Worker::Status Worker::getStatus() const
{
	return this->status;
}

string Worker::getStringStatus() const
{
	switch (this->status)
	{
	case Status::FREE:			return "FREE";			break;
	case Status::ON_WORK:		return "ON_WORK";		break;
	case Status::SINGLE_WORK:	return "SINGLE_WORK";	break;
	default:					return "NONE";			break;
	}
}

void Worker::print() const
{
	cout << "name: " << getName() << endl;
	cout << "age: " << getAge() << endl;
	cout << "expirience: " << getExpirience() << endl;
	cout << "salary: " << getSalary() << endl;
	cout << "positionRatings: " << getPositionRatings() << endl;
	cout << "status: " << getStringStatus() << endl;
}
