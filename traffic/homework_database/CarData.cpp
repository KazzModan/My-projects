#include "CarData.h"

CarData::CarData()
{
	this->ownerName = "none";
}

CarData::CarData(string carNumber, string ownerName)
{
	setCarNumber(carNumber);
	setOwnerName(ownerName);
}

bool CarData::setCarNumber(string carNumber)
{
	return this->carNumber.setAll(carNumber);
}

bool CarData::setOwnerName(string name)
{
	if (!CheckPeopleName(name))
		return false;

	this->ownerName = name;
	return true;
}

bool CarData::setOffenseList(const list<Offense>& offense)
{
	if (offense.empty())
		return false;

	this->offenseList = offense;
	return true;
}

string CarData::getCarNumber() const
{
	return this->carNumber.getNumber();
}

string CarData::getOwnerName() const
{
	return this->ownerName;
}

const list<Offense>& CarData::getOffenseList() const
{
	return this->offenseList;
}

CarNumber& CarData::getNumber()
{
	return this->carNumber;
}

void CarData::operator=(const CarData& carData)
{
	this->ownerName = carData.getOwnerName();
	this->carNumber = carData.getCarNumber();
	this->offenseList = carData.getOffenseList();
}

bool CarData::operator==(CarData& carData) const
{
	return this->carNumber == carData.getNumber();
}

bool CarData::operator!=(CarData& carData) const
{
	return this->carNumber != carData.getNumber();
}

bool CarData::operator>(CarData& carData) const
{
	return this->carNumber > carData.getNumber();
}

bool CarData::operator<(CarData& carData) const
{
	return this->carNumber < carData.getNumber();
}

bool CarData::operator>=(CarData& carData) const
{
	return this->carNumber >= carData.getNumber();
}

bool CarData::operator<=(CarData& carData) const
{
	return this->carNumber <= carData.getNumber();
}

bool CarData::operator==(string filter) const
{
	return auxiliaryOperator(filter, 0);
}

bool CarData::operator!=(string filter) const
{
	return auxiliaryOperator(filter, 1);
}

bool CarData::operator>(string filter) const
{
	return auxiliaryOperator(filter, 2);
}

bool CarData::operator<(string filter) const
{
	return auxiliaryOperator(filter, 3);
}

bool CarData::operator>=(string filter) const
{
	return auxiliaryOperator(filter, 4);
}

bool CarData::operator<=(string filter) const
{
	return auxiliaryOperator(filter, 5);
}

void CarData::addOffense()
{
	Offense temp;
	string tempText;
	size_t tempNumber;

	do
	{

		cout << "enter offense title: ";
		lcin >> tempText;
	} while (!temp.setTitle(tempText));

	do
	{
		cout << "enter offense info: ";
		lcin >> tempText;
	} while (!temp.setInfo(tempText));

	do
	{
		cout << "enter offense fine: ";
		lcin >> tempNumber;
	} while (!temp.setFine(tempNumber));

	this->offenseList.push_back(temp);
}

void CarData::SetParameters(CarNumber& carNumber, string filter)
{
	string region;
	string series;

	region += filter[0];
	region += filter[1];
	series += filter[2];
	series += filter[3];

	carNumber.setRegion(region);
	carNumber.setSeries(series);
}

bool CarData::auxiliaryOperator(string filter, size_t type) const
{
	if (!CheckUpperLetters(filter))
		return false;

	CarNumber temp;

	if (filter.length() == 2)
	{
		temp.setRegion(filter);
		size_t left = this->carNumber.getRegionPriority();
		size_t rigth = temp.getRegionPriority();
		return auxiliaryOperatorDaughter(type, left, rigth);
	}
	else if (filter.length() == 4)
	{
		SetParameters(temp, filter);

		size_t left = this->carNumber.getRegionPriority() + this->carNumber.getSeriesPriority();
		size_t rigth = temp.getRegionPriority() + temp.getSeriesPriority();
		return auxiliaryOperatorDaughter(type, left, rigth);
	}

	cl::SetColor(cl::Red);
	cout << "uncorectly filter\n";
	return false;
}

bool CarData::auxiliaryOperatorDaughter(size_t type, size_t left, size_t rigth) const
{
	switch (type)
	{
	case 0:
		return left == rigth;
		break;
	case 1:
		return left != rigth;
		break;
	case 2:
		return left > rigth;
		break;
	case 3:
		return left < rigth;
		break;
	case 4:
		return left >= rigth;
		break;
	case 5:
		return left <= rigth;
		break;
	}
}

ostream& operator<<(ostream& out, const CarData& car)
{
	out << "owner name: " << car.getOwnerName() << endl;
	out << "car name: " << car.getCarNumber() << endl;

	cout << endl;

	for (const Offense& item : car.getOffenseList())
	{
		item.print();
		cout << endl;
	}

	return out;
}
