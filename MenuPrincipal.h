#pragma once
#include "Menu.h"
#include "MenuEscolha.h"
#include "MenuLeaderboard.h"

class MenuPrincipal : public Menu
{
private:


public:
	MenuPrincipal();
	~MenuPrincipal();

	void setValores();
	void desenhar();
	void loop();
	void executar();

};

