#include "inimigo.h"


Inimigo::Inimigo(Math::CoordF pos, Math::CoordF tam, int v, int d, float dC, float dA, float vR) :
	Personagem(pos, tam, v, d, dC, dA)
{
	viewRange = vR;
}

Inimigo::~Inimigo() {}

void Inimigo::setViewRange(float vR) {
	viewRange = vR;
}

float Inimigo::getViewRange() {
	return viewRange;
}