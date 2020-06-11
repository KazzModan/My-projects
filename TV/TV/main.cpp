#include <iostream>

using namespace std;

class TV
{
public:
	friend class Remote;

	TV()
	{
		_isOn = false;
		_volume = 0;
		_channels = 0;
	}
	TV(bool isOn, int volume, int channels)
	{
		setVol(volume);
		setState(isOn);
		setCh(channels);
	}
	~TV()
	{
		_isOn = false;
		_volume = 0;
		_channels = 0;
	}
	bool setVol(int vol)
	{
		if (vol >= 0 && vol <= VOLUME)
		{
			_volume = vol;
			return true;
		}
		return false;
	}
	bool setCh(int channels)
	{
		if (channels >= 0 && channels <= CHANNELS)
		{
			_channels = channels;
			return true;
		}
		return false;
	}
	void setState(bool state)
	{
		_isOn = state;
	}
	void power()
	{
		if (!_isOn)
			_isOn = true;
		else
			cout << "tv has already switched on\n";
	}
	void incVol(size_t value)
	{
		if (_volume + value <= VOLUME)
			setVol(value + _volume);
		else
			cout << "It's too loud dude\n";
	}
	void decVol(size_t value)
	{
		if (_volume - value >= 0)
			setVol(value + _volume);
		else
			cout << "It's too quiet dude\n";
	}
	void nextChannel()
	{
		if (_channels + 1<=CHANNELS)
			setCh(_channels + 1);
		else
			cout << "U trying to go out from list\n";
	}
	void prevChannel()
	{
		if (_channels + 1 >= 0)
			setCh(_channels - 1);
		else
			cout << "U trying to go out from list\n";
	}
	void print()
	{
		if (_isOn)
			cout << "Tv switch on\n";
		else
			cout << "Tv switch off\n";
		cout << "currect channel is: " << _channels << endl;
		cout << "currect volume is: " << _volume << endl;

	}
	
private:
	bool _isOn;
	int _volume;
	int _channels;
	enum Max
	{
		VOLUME = 100, CHANNELS = 32
	};
};
class Remote
{
public:
	void remPower()
	{
		this->tv->power();
	}
	void operator++()
	{
		this->tv->nextChannel();
	}
	void operator--()
	{
		this->tv->prevChannel();
	}
	Remote(TV *tv)
	{
		this->tv = tv;
	}
	void operator+()
	{
		this->tv->incVol(1);
	}

	void operator-()
	{
		this->tv->decVol(1);
	}
private:
	TV* tv;
};

int main()
{	
	TV tv(false, 1, 1);
	Remote rem(&tv);
	rem.remPower();
	++rem;
	tv.print();
	return 0;
}