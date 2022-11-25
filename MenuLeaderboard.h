#pragma once
#include "Menu.h"

#define CAMINHO_PLACAR "./saves/Leaderboard.txt"

class MenuLeaderboard : public Menu
{
private:

public:
	MenuLeaderboard();
	~MenuLeaderboard();

	void setValores();

	void desenhar();
	void loop();
	void executar();
};

