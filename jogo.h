#pragma once
#include <SFML/Graphics.hpp>
#include "jogador.h"
#include "inimigo.h"
#include "graphics.h"

class Jogo
{
private:
	Jogador jogador1;
	Inimigo inimigo1;;
	Managers::Graphics* pGG;

public:
	Jogo();
	~Jogo();

	void Executar();
};