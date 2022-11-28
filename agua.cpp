#include "Agua.h"
#include "personagem.h"


#define LENTIDAO 0.2

namespace Entidades {
	namespace Obstaculos {

		Agua::Agua(sf::Vector2f pos) :
			Obstaculo(pos)
		{
			id = agua;
			lentidao = LENTIDAO;
			body.setSize(sf::Vector2f(100, 137));
			setSprite("Assets/agua.png");
			sprite.setTextureRect(sf::IntRect(0, 5, 60, 60));
			setPosicao(pos);
			setEscala(sf::Vector2f(3, 4));
		}

		Agua::~Agua() {}

		float Agua::getLentidao() { return lentidao; }

		void Agua::efeito(Entidade* p) {
			p->setVelocidade(sf::Vector2f(p->getVelocidade().x * lentidao, p->getVelocidade().y));
		}

		void Agua::executar() {
			renderizar();
			atualizar();
		}
	}
}