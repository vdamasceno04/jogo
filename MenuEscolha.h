#pragma once
#include "Menu.h"

class MenuEscolha : public Menu
{
private:
	int jogadores;
	int fase;
	//bool ativo;
	int escolha;

public:
	MenuEscolha();
	~MenuEscolha();

	void setValores();
	int getEscolha();

	int getFase();
	int getJogador();

	void desenhar();
	void loop();
	void executar();

};

