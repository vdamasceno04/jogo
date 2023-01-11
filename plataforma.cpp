#include "Plataforma.h"

Plataforma::Plataforma(Math::CoordF pos, bool verm) :
	Obstaculo(pos)
{
	vermelho = verm;
	id = plataforma;
	if(vermelho)
		setSprite("Assets/chaovermelho.png");
	else
		setSprite("Assets/chaoverde.png");
	setPosicao(pos);
	setTamanho(Math::CoordF(67, 133));
	setEscala(Math::CoordF(2, 2));
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {
	renderizar();
	atualizar();
}