#pragma once
#include"inimigo.h"
#include <string>

class ListaEntidades;

namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem {
		protected:
		public:
			Jogador(sf::Vector2f pos);
			~Jogador();
			virtual void executar() = 0;
			virtual void controlar() = 0;
			void ataca();
		};
	}
}