#pragma once
#include "Menu.h"
#include "MenuEscolha.h"
#include "MenuLeaderboard.h"

class MenuPrincipal : public Menu
{
private:

	//bool escolha;
	//bool leaderboard;
	//bool principal;

	MenuEscolha menuEscolha;
	MenuLeaderboard menuLeaderboard;

public:
	MenuPrincipal();
	~MenuPrincipal();

	void setValores();

	bool getEscolhaAtivo();
	bool getLeaderboardAtivo();
	int getEscolhaJogador();
	int getEscolhaFase();
	int getEscolheu();

	void desenhar();
	void loop();
	void executar();

};

