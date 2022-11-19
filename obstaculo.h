#pragma once
#include "entidade.h"

class Personagem;

namespace Obstaculos {

	class Obstaculo : public Entidades::Entidade {
	protected:

		

	public:
		Obstaculo(sf::Vector2f pos);
		~Obstaculo();

		virtual void efeito(Entidade* p) {};
		virtual void executar() = 0;
		virtual void colidir(Entidade* pEnt, float intersec_x, float intersec_y) {} // fazer virtual pura dps
	};
}