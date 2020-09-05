#include <iostream>
using namespace std;
class Time
{
private:
	size_t hours;
	size_t minutes;
	size_t seconds;

public:
	Time()
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	void operator=(Time& time)
	{
		this->hours = time.hours;
		this->minutes = time.minutes;
		this->seconds = time.seconds;
	}
	Time operator+(Time& time)
	{
		this->hours += time.hours;
		this->minutes += time.minutes;
		this->seconds += time.seconds;
		return *this;
	}
	Time operator-(Time& time)
	{
		this->hours -= time.hours;
		this->minutes -= time.minutes;
		this->seconds -= time.seconds;
		return *this;
	}
	void setHours(int hours)
	{
		if(hours>0||hours<24)
		this->hours = hours;
	}
	void setMin(int min)
	{
		if (min > 0 || min < 60)
			this->minutes = min;
	}
	void setSec(int sec)
	{
		if (sec > 0 || sec < 60)
		this->seconds = sec;
	}
	friend ostream& operator<<(ostream& output, const Time& time)
	{
		output  <<time.hours<<":" << time.minutes<<":"<<time.seconds<<endl;
		return output;
	}
	friend istream& operator >>(istream& input, Time& time)
	{
		cout << " Enter time: \n";
		input >> ;
		return input;
	}

};



int main()
{

	return 0;
}