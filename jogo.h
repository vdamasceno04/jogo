#pragma once
#include <SFML/Graphics.hpp>
#include "Fase.h"

using namespace Managers;

class Jogo
{
private:
	Fase fase1;
	Managers::Graphics* pGG;

	Jogador j1;
	Agua a1;
	Plataforma p1;
	Espinho e1;




public:
	Jogo();
	~Jogo();
	void inicializar();
	void executar();
};