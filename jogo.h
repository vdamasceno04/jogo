#pragma once
#include <SFML/Graphics.hpp>
#include "Fase.h"

using namespace Managers;

class Jogo
{
private:
	Fase fase1;
	Managers::Graphics* pGG;

public:
	Jogo();
	~Jogo();
	void inicializar();
	void executar();
};