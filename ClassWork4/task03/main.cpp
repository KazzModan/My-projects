#include <iostream>
#include <ctime>
using namespace std;
int quantityOfAlive = 0;
const int SIZE = 5;
char field[SIZE][SIZE];
class Fish
{
public:

	Fish()
	{
		x = 0;
		y = 0;
		hp = 1;
		quantityOfAlive++;
	}
	Fish(int x, int y, int hp)
	{

		this->setX(x);
		this->setY(y);
		this->setHp(hp);

		quantityOfAlive++;
	}
	void setX(int x)
	{
		if (x > 0 && x < 20)
			this->x = x;
	}
	void setY(int y)
	{
		if (y > 0 && y < 20)
			this->y = y;
	}
	void setHp(int hp)
	{
		if (hp > 0 && hp <= 100)
			this->hp = hp;
	}
	int getX() const
	{
		return this->x;
	}
	int getY() const
	{
		return this->y;
	}
	static void ShowFishAndCorals()
	{
		for (size_t i = 0; i < SIZE; i++)
		{
			for (size_t j = 0; j < SIZE; j++)
			{
				cout << field[i][j] << " ";
			}
			cout << endl;
		}
		cout << "- - - - -\n";
	}
	void go()
	{
		int x, y;
		cout << "enter new coords of fish: ";
		cin >> x >> y;
		if (x < 5 && y < 5)
		{
			if (field[x][y] == '$')
			{
				field[getX()][getY()] = '#';
				field[x][y] = '*';

				this->hp += 1;
			}
			else if (field[x][y] == '#')
			{
				this->hp -= 1;
				if (this->hp == 0)
				{
					field[getX()][getY()] = '#';
					field[x][y] = '#';
					cout << "fish died\n";
				}
				else
				{
					field[getX()][getY()] = '#';
					field[x][y] = '*';
				}
			}
			else if (field[x][y] == '*')
			{
				cout << "Sorry, another fish already has sat in this plase\n";
			}
		}
		else
			cout << "wrong coords\n";
	}
	static void fillOcean(Fish fFhis, Fish sFhis, Fish tFhis)
	{
		for (size_t i = 0; i < SIZE; i++)
		{
			for (size_t j = 0; j < SIZE; j++)
			{
				field[i][j] = '#';
			}
		}
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 1; j++)
			{
				field[rand() % 5][rand() % 5] = '$';
			}
		}
		field[fFhis.getX()][fFhis.getY()] = '*';
		field[sFhis.getX()][sFhis.getY()] = '*';
		field[tFhis.getX()][tFhis.getY()] = '*';
	}
	void hideFish()
	{
		field[getX()][getY()] = '#';
		cout << "it was hidden\n";
	}
	void foundFish()
	{
		field[getX()][getY()] = '*';
		cout << "it was found\n";
	}
private:
	int x;
	int y;
	int hp;
};

int main()
{
	srand(time(nullptr));
	Fish fish(2, 1, 1);
	Fish sFish(3, 4, 20);
	Fish fFish(3, 1, 30);
	Fish::fillOcean(fish, sFish, fFish);
	Fish::ShowFishAndCorals();
	fish.go();
	Fish::ShowFishAndCorals();
	sFish.hideFish();
	Fish::ShowFishAndCorals();
	sFish.foundFish();
	Fish::ShowFishAndCorals();

	return 0;
}