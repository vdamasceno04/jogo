#include "Obstaculo.h"
using namespace Obstaculos;

Obstaculo::Obstaculo(sf::Vector2f pos) :
	Entidade::Entidade(pos)
{
	danificar = false;
	liquido = false;
	dano = 0;
	danoCooldown = 0;
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