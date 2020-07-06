#include "Game.h"

Game::Game(Team fTeam, Team sT)
{
	this->fTeam = fTeam;
	this->sTeam = sTeam;
}

void Game::Play()
{
	do
	{
		fTeam.print();
		cout << "VS\n";
		sTeam.print();
		fTeam.
	} while (true);
}
