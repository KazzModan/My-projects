#pragma once
#include <iostream>
using namespace std;
class BuildMats
{
public:
	virtual void work() = 0;
	int getProgress() { return this->progress; }
	int progress;
};
class Window :public BuildMats
{
public:
	Window()
	{
		this->progress = 15;
	}
	void work() override
	{
		cout << "Planting windows\n";
	}
	int getProgress() { return this->progress; }

};
class Brick : public BuildMats
{
public:
	Brick()
	{
		this->progress = 1;
	}
	void work() override
	{
		cout << "creating walls\n";
	}
	int getProgress()const { return this->progress; }

};
class Roof :public BuildMats
{
public:
	Roof()
	{
		this->progress = 10;
	}
	void work() override
	{
		cout << "creating roof on house\n";
	}
	int getProgress() const  { return this->progress; }

};
class Cements :public BuildMats
{
public:
	Cements()
	{
		this->progress = 5;
	}
	void work() override
	{
		cout << "pour cement on  the man\n";
	}
	int getProgress() const { return this->progress; }

};
class Rebar :public BuildMats
{
public:
	Rebar()
	{
		this->progress = 11;
	}
	void work() override
	{
		cout << "Planting revar on roof\n";
	}
	int getProgress() const { return this->progress; }

};
class Blocks :public BuildMats
{
public:
	Blocks()
	{
		this->progress = 20;
	}
	void work() override
	{
		cout << "creating cement blocks, and putting there peoples \n";
	}
	int getProgress() const { return this->progress; }

};