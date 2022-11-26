#pragma once
#include "Menu.h"

class MenuLeaderboard : public Menu
{
private:
	string caminho;

public:
	MenuLeaderboard();
	~MenuLeaderboard();

	void setValores();

	void desenhar();
	void loop();
	void executar();
};

