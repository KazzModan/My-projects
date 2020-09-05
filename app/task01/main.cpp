#include <iostream>

using namespace std;
class Player
{
private:
	string name;
	int age;
	int hp;
public:
	Player()
	{
		this->name = "Noname";
		this->age = 0;
		this->hp = 0;
	}
	Player(string name="Valera",int hp=0,int age=0)
	{
		this->name = name;
		this->age = hp;
		this->hp = age;
	}
	enum MAX
	{
		MAX_AGE = 100, MAX_HP = 100
	};

	void SetName(string& name)
	{
		if (!name.empty())
			this->name=name;
	}
	void SetAge(int age)
	{
		if (age < MAX_AGE)
			this->age = age;
	}
	void SetHp(int hp)
	{
		if (hp < MAX_HP)
			this->hp = hp;
	}
	string  GetName() const
	{
		return this->name;
	}
	int GetAge() const
	{
		return this->age;
	}
	int GetHp() const
	{
		return this->age;
	}
	void enter()
	{
		cout << "Enter name for new player: ";
		cin >> name;
		cout << "Enter age for new player: ";
		cin >> age;
		cout << "Enter hp for new player: ";
		cin >>hp;
	}
	void show() const
	{
		cout << "name = > " << name << endl;
		cout << "age = > " << age << endl;
		cout << "hp = > " << hp << endl;
	}
};
int main()
{
	Player newPlayer("Petya");
	newPlayer.show();
	/*player.SetName(name);
	player.SetHp(33);
	player.SetAge(28);
	player.show();*/
	return 0;
}