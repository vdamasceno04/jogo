#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Pedra : public Obstaculo {
		private:
		public:
			Pedra(sf::Vector2f pos);
			~Pedra();
			void executar();
			virtual void efeito(Entidade* p) {};
		};
	}
}
