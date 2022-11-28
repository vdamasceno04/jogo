#include "Plataforma.h"

namespace Entidades {
	namespace Obstaculos {
		Plataforma::Plataforma(sf::Vector2f pos, bool verm) :
			Obstaculo(pos)
		{
			vermelho = verm;
			id = plataforma;
			if (vermelho)
				setSprite("Assets/chaovermelho.png");
			else
				setSprite("Assets/chaoverde.png");
			setPosicao(pos);
			body.setSize(sf::Vector2f(67, 133));
			setEscala(sf::Vector2f(2, 2));
		}

		Plataforma::~Plataforma() {}

		void Plataforma::executar() {
			renderizar();
			atualizar();
		}
	}
}