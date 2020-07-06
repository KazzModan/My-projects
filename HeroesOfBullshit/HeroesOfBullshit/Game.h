#pragma once
#include "Team.h"
class Game
{
public:
	Game(Team fTeam, Team sT);
	void Play();
private:
	Team fTeam;
	Team sTeam;
};

