#pragma once
#include "checks.h"
using std::cout;
using std::endl;

class Worker
{
public:
	enum class Status 
	{
		NONE,
		FREE,
		ON_WORK,
		SINGLE_WORK,
	};

	enum Limits
	{
		MAX_AGE = 100,
		MAX_SALARY = 100000,
		MAX_POSITION = 100000, // 0 == 100000+
		MAX_EXPIRIENCE = 80,
	};

	Worker();
	Worker(string name, size_t age, size_t expirience, size_t salary, size_t position, Status status);

	/*setters*/
	
	bool setName(string name);
	bool setAge(size_t age);
	bool setExpirience(size_t expirience);
	bool setSalary(size_t salary);
	bool setPositionRatings(size_t position);
	bool setStatus(Status status);

	/*getters*/

	string getName() const;
	size_t getAge() const;
	size_t getExpirience() const;
	size_t getSalary() const;
	size_t getPositionRatings() const;
	Status getStatus() const;
	string getStringStatus() const;

	void print() const;

protected:
	string name;
	size_t age;
	size_t expirience;
	size_t salary;
	size_t positionRatings;
	Status status;
};