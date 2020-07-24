#pragma once
#include <List>
#include <iostream>
#include <string>
#include "Checks.h"
#include "CarNumber.h"
#include "Offense.h"
#include "Enter.h"
using std::cout;
using std::list;
using std::ostream;
using std::endl;

class CarData
{
public:
	CarData();
	CarData(string carNumber, string ownerName);

	/*setters*/

	bool setCarNumber(string carNumber);
	bool setOwnerName(string name);
	bool setOffenseList(const list<Offense>& offense);

	/*getters*/

	string getCarNumber() const;
	string getOwnerName() const;
	const list<Offense>& getOffenseList() const;
	CarNumber& getNumber();
	
	/*operators*/

	void operator = (const CarData& carData);
	bool operator == (CarData& carData) const;
	bool operator != (CarData& carData) const;
	bool operator > (CarData& carData) const;
	bool operator < (CarData& carData) const;
	bool operator >= (CarData& carData) const;
	bool operator <= (CarData& carData) const;

	bool operator == (string filter) const;
	bool operator != (string filter) const;
	bool operator > (string filter) const;
	bool operator < (string filter) const;
	bool operator >= (string filter) const;
	bool operator <= (string filter) const;

	/*other*/

	void addOffense();
	//void removeOffense(); під питанням потрібно юзати вектор або свій лист

	friend ostream& operator << (ostream& out, const CarData& car);

private:
	CarNumber carNumber;
	string ownerName;
	list<Offense> offenseList;

	static void SetParameters(CarNumber& carNumber, string filter);
	bool auxiliaryOperator(string filter, size_t type) const;
	bool auxiliaryOperatorDaughter(size_t type, size_t left, size_t rigth) const;
};

