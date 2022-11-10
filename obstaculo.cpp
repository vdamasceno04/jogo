#include "obstaculo.h"
using namespace Obstaculos;

Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam, int d, float dC) :
	Entidade::Entidade(pos, tam) {
	danificar = false;
	liquido = false;
	dano = d;
	danoCooldown = dC;
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