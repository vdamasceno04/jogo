#include "pedra.h"

Pedra::Pedra(Math::CoordF pos) :
	Obstaculo(pos)
{
	id = pedra;
	setSprite("Assets/pedra.png");
	setPosicao(pos);
	setTamanho(Math::CoordF(80, 140));
	setEscala(Math::CoordF(2, 1));
}

Pedra::~Pedra() {}

void Pedra::executar() {
	renderizar();
	atualizar();
}