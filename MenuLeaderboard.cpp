#include "MenuLeaderboard.h"

//Terminar Leaderboard depois

MenuLeaderboard::MenuLeaderboard():
	Menu()
{

}

MenuLeaderboard::~MenuLeaderboard()
{

}

void MenuLeaderboard::setValores()
{

}

void MenuLeaderboard::desenhar()
{

}

void MenuLeaderboard::loop()
{

}

void MenuLeaderboard::executar()
{
	selecionado = false;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && !selecionado)
		ativo = false;
}