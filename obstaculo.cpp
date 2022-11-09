#include "obstaculo.h"
using namespace Obstaculos;

Obstaculo::Obstaculo(Math::CoordF pos, Math::CoordF tam, int d, float dC) :
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