#include <iostream>
#include <vector>
#include <functional>
using namespace std;
void ch1(string z)
{
	if (!z.empty())
	{
		cout << "xorosho" << endl;
	}
	else
	{
		return;
	}
}
enum pl
{
	PC, PS, XBOX, N
};
enum junr
{
	anime, hentai, iaoi, Kodzima
};
enum cr
{
	FakeTaxi, FakeHostel, FakePolice, FakeAgent, Brazzers, MakeAmGrAg
};

class Game
{
public:

	Game()
	{
		_imia;
		_jn;
		_cr = MakeAmGrAg;
		_pl = N;
	}
	Game(string z1, junr z2, cr z3, pl pl)
	{
		_imia = z1;
		_jn = z2;
		_cr = z3;
		_pl = pl;
	}
	string _imia;
	junr _jn;
	cr _cr;
	pl _pl;
	void print()
	{
		cout << "name: " << _imia<<endl;
		cout << "creater: ";
		switch (_cr)
		{
		case FakeTaxi:
			cout << "Activision\n";
			break;
		case FakeHostel:
			cout << "Dice\n";
			break;
		case FakePolice:
			cout << "FromSf\n";
			break;
		case FakeAgent:
			cout << "Valve\n";
			break;
		case Brazzers:
			cout << "Blizzard\n";
			break;
		case MakeAmGrAg:
			cout << "GGG\n";
			break;
		default:
			break;
		}
		cout << "Junr: ";
		switch (_jn)
		{
		case anime:
			cout << "Action\n";
			break;
		case  hentai:
			cout << "Shooter\n";
			break;
		case iaoi:
			cout << "Platformer\n";
			break;
		case Kodzima:
			cout << "Minecraft\n";
			break;
		default:
			break;
		}
		cout << "Platform: ";
		switch (_pl)
		{
		case PC:
			cout << "PC\n";
			break;
		case PS:
			cout << "PS\n";
			break;
		case XBOX:
			cout << "XYAN\n";
			break;
		case N:
			cout << "ALL\n";
			break;
		default:
			break;
		}
	}

};

void show(vector <Game> v)
{
	for (int i = 0; i < v.size(); i++)
		v[i].print();
}
void cringebyname(string n, vector <Game> v)
{
	for (int i = 0; i < v.size(); i++)
		if (n == v[i]._imia)
			v[i].print();
}
void cringebyjnr(size_t n, vector <Game> v)
{
	for (int i = 0; i < v.size(); i++)
		if (n == v[i]._jn)
			v[i].print();
}
void cringebycr(size_t n, vector <Game> v)
{
	for (int i = 0; i < v.size(); i++)
		if (n == v[i]._cr)
			v[i].print();
}
void cringebypl(size_t n, vector <Game> v)
{
	for (int i = 0; i < v.size(); i++)
		if (n == v[i]._pl)
			v[i].print();
}
void main()
{
	bool isOpen=true;
	int choose;
	vector<Game> anime;
	Game gm("SaloLogvinov", iaoi, FakeTaxi, N);
	Game gm1("xXxApelsinxXx", hentai, Brazzers, PS);
	anime.push_back(gm);
	anime.push_back(gm1);

	do
	{
		cout << "Choose: ";
		cin >> choose;
		cout << "1.ShowAllGames: " << endl;
		cout << "2.SearcByName: " << endl;
		cout << "3.SeacrcByDev:" << endl;
		cout << "4.SearchByPl:  " << endl;
		cout << "5.SearchByJn" << endl;
		cout << "6. exit" << endl;
		if (choose == 1)
		{
			function<void(vector <Game> v)> t = show;
			t(anime);
		}
		if (choose == 2)
		{
			string n;
			function<void(string n, vector <Game> v)> t = cringebyname;
			cout << "Enter name of func\n";
			cin >> n;
			t(n,anime);
		}
		if (choose == 3)
		{
			size_t size;
			function<void(size_t n, vector <Game> v)> t = cringebycr;
			cout << "Enter name of creator in numb\n";
			cin >> size;
			t(size, anime);
		}
		if (choose == 4)
		{
			size_t size;
			function<void(size_t n, vector <Game> v)> t = cringebypl;
			cout << "Enter name of platform in numb\n";
			cin >> size;
			t(size, anime);
		}
		if (choose == 5)
		{
			size_t size;
			function<void(size_t n, vector <Game> v)> t = cringebypl;
			cout << "Enter name of junr in numb\n";
			cin >> size;
			t(size, anime);
		}
		if (choose == 5)
		{
			isOpen = false;
		}
	} while (isOpen);
}