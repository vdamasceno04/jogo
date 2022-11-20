#pragma once
#include <SFML/Graphics.hpp>
#include "florestaverde.h"
#include "florestavermelha.h"

using namespace Managers;

class Jogo
{
private:
//	FlorestaVerde fase1;
	FlorestaVermelha fase2;
	Managers::Graphics* pGG;
	GerenciadorColisoes* pGC;

public:
	Jogo();
	~Jogo();
	void inicializar();
	void executar();
};