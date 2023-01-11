#include "fundo.h"

Fundo::Fundo(Math::CoordF pos, bool d) : Entidade(pos)
{
	dia = d;
	id = fundo;
	if(dia)
		setSprite("Assets/fundodia.png");
	else
		setSprite("Assets/fundonoite.png");
	setTamanho(Math::CoordF(WIDTH, HEIGHT));;
	setEscala(Math::CoordF(3.21, 3.75));
	setPosicao(pos);
}

Fundo::~Fundo() {}

void Fundo::executar() {
	renderizar();
}
