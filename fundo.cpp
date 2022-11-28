#include "fundo.h"

namespace Entidades {
	Fundo::Fundo(sf::Vector2f pos, bool d) : Entidade(pos)
	{
		dia = d;
		id = fundo;
		if (dia)
			setSprite("Assets/fundodia.png");
		else
			setSprite("Assets/fundonoite.png");
		body.setSize(sf::Vector2f(WIDTH, HEIGHT));;
		setEscala(sf::Vector2f(3.21, 3.75));
		setPosicao(pos);
	}

	Fundo::~Fundo() {}

	void Fundo::executar() {
		renderizar();
	}

}