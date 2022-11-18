#pragma once
#include "entidade.h"

class Personagem;

namespace Obstaculos {

	class Obstaculo : public Entidades::Entidade {
	protected:

		

	public:
		Obstaculo(sf::Vector2f pos);
		~Obstaculo();

		virtual void efeito(Personagem* p){}
		virtual void executar() = 0;
		virtual void colidir(Entidade* pEnt, ID id) { }
	};
}