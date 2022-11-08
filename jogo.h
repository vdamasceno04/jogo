#pragma once
#include <SFML/Graphics.hpp>
#include "jogador.h"
#include "inimigo.h"
#include"graphics.h"

using namespace Managers;

class Jogo
{
private:
	Jogador jogador1;
	Inimigo inimigo1;
	sf::RenderWindow window;
	Managers::Graphics* pGG;

public:
	Jogo();
	~Jogo();

	void executar();
};