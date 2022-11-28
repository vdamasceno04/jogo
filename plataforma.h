 #pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculos::Obstaculo {
		private:
			bool vermelho;
		public:
			Plataforma(sf::Vector2f pos, bool verm);
			~Plataforma();
			void executar();
			virtual void efeito(Entidade* p) {};
		};
	}
}