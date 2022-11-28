#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {

		class Agua : public Obstaculo {
		private:
			float lentidao;

		public:
			Agua(sf::Vector2f pos);
			~Agua();
			float getLentidao();
			void efeito(Entidade* p);
			void executar();
		};
	}
}