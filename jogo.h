#pragma once
#include <SFML/Graphics.hpp>
#include "jogador.h"
#include "inimigo.h"

class Jogo
{
private:
	Jogador jogador1;
	Inimigo inimigo1;
	sf::RenderWindow window;
	Managers::Graphics* pGraphicManager;

public:
	Jogo();
	~Jogo();

	void Executar();
};