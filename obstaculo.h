#pragma once
#include "entidade.h"

class Personagem;

namespace Entidades {
	namespace Obstaculos {

		class Obstaculo : public Entidade {
		protected:

			bool causaEfeito;

		public:
			Obstaculo(sf::Vector2f pos);
			~Obstaculo();

			virtual void efeito(Entidade* p) {};
			virtual void executar() = 0;

		};
	}
}