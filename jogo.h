#pragma once
#include <SFML/Graphics.hpp>
#include "ListaEntidades.h"
#include "inimigo.h"
#include "jogador.h"
#include"graphics.h"

using namespace Managers;

class Jogo
{
private:
	sf::RenderWindow window;
	Managers::Graphics* pGG;

public:
	Jogo();
	~Jogo();
	void inicializar();
	void executar();
};