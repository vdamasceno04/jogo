#include "Obstaculo.h"
using namespace Obstaculos;

Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam, int d, float dC, bool dan, bool l) :
	Entidade::Entidade(pos, tam)
{
	danificar = dan;
	liquido = l;

	if (danificar) {
		dano = d;
		danoCooldown = dC;
	}
	else {
		dano = 0;
		danoCooldown = 0.0;
	}
}

Obstaculo::~Obstaculo() {}

void Obstaculo::setDanificar(bool d) {
	danificar = d;
}

void Obstaculo::setDano(int d) {
	dano = d;
}

void Obstaculo::setDanoCooldown(float dC) {
	danoCooldown = dC;
}

void Obstaculo::setLiquido(bool l) {
	liquido = l;
}