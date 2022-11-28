#pragma once
#include "Menu.h"
#include "MenuEscolha.h"
#include "MenuLeaderboard.h"
#include<map>
#include<fstream>
#define CAMINHO "./Assets/ranking.txt"

class MenuPrincipal : public Menu
{
private:


public:
	MenuPrincipal();
	~MenuPrincipal();

	void setValores();
	void desenhar();
	void loop();
	void insereNome();
	void executar();

};

