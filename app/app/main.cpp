#include <iostream>

using namespace std;

class Car
{
private:
	bool isStarted = false;
	int maxFuel;
	int currectFuel;
	string brand;
	string model;
	int speed;
	enum MAX
	{
		MAX_FUEL = 100, MIN_FUEL = 0, MAX_SPEED = 250, MIN_SPEED = 0
	};
public:
	void setMaxFuel(int fuel)
	{
		if (fuel<MAX_FUEL && fuel>MIN_FUEL)
			this->maxFuel = fuel;
	}
	void setCurrectFuel(int fuel)
	{
		if (fuel<MAX_FUEL && fuel>MIN_FUEL)
			this->maxFuel = fuel;
	}
	void setModel(string model)
	{
		if (!model.empty())
			this->brand = brand;
	}
	void setBrand(string model)
	{
		if (!model.empty())
			this->model = model;
	}
	int GetMaxFuel() const
	{
		return this->maxFuel;
	}
	int GetSpeed() const
	{
		return this->speed;
	}
	int GetCurrectFuel()const
	{
		return this->currectFuel;
	}
	string getCurrectBrand()const
	{
		return this->brand;
	}
	string GetCurrectmodel()const
	{
		return this->model;
	}
	Car()
	{
		this->brand = "nobrand";
		this->model = "nomodel";
		this->maxFuel = 100;
		this->currectFuel = 0;
		this->isStarted = false;
	}
	void setSpeed(int speed)
	{
		if (speed > MIN_SPEED && speed < MAX_SPEED)
			this->speed = speed;
	}
	Car(string brand, string model, size_t maxFuel, size_t fuel, size_t speed)
	{
		setBrand(brand);
		setModel(model);
		setCurrectFuel(fuel);
		setMaxFuel(maxFuel);
		setSpeed(speed);
	}
	void change()
	{
		if (isStarted == false)
			isStarted = true;
		else
			isStarted = false;
	}
	void fiilUp()
	{
		do
		{
			cout << "Enter fuel,that u want to fill up: ";
			cin >> currectFuel;
		} while (currectFuel < 0 || currectFuel>maxFuel);
	}
	void enter()
	{
		cout << "Enter size of engine: ";
		cin >> maxFuel;
		cout << "Enter brand of car: ";
		cin >> brand;
		cout << "Enter model of car: ";
		cin >> model;
	}
	void output()
	{
		cout << "Size of engine: " << maxFuel << endl;
		cout << "model of car: " << model << endl;
		cout << "brand of car: " << brand << endl;
		if (isStarted == false)
			cout << "car off\n";
		else
			cout << "car on\n";
	}
	void calc()
	{
		int kilometers;
		int couter = 0;
		do
		{
			cout << "Enter how many kilometer u want drive: ";
			cin >> kilometers;
		} while (kilometers < 0);
		while (kilometers > 0)
		{
			kilometers = kilometers - 10;

			if (kilometers >= 0)
			{
				couter++;
			}
		}
		cout << "u need to burn " << couter << " liters of fuel\n";
	}
	void Acceleration()
	{
		int acceleration;
		cout << "Enter acceleration: ";
		cin >> acceleration;
		if (this->speed < acceleration + this->speed&& acceleration + this->speed<MAX_SPEED)
			setSpeed(acceleration + speed);
		else
			cout << "Wrong speed\n";
	}
	void breack()
	{
		int breack;
		cout << "Enter break: ";
		cin >> breack;
		if (this->speed > this->speed - speed)
			setSpeed(speed - breack);
		else
			cout << "Wrong speed\n";
	}
};

int main()
{
	Car myCar("x", "tesla", 100, 90, 200);
	myCar.Acceleration();
	myCar.breack();
	cout << myCar.GetSpeed() << endl;
	return 0;
}