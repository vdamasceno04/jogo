#pragma once
#include "entidade.h"

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidades::Entidade {
		protected:
			bool atacando;
			float alcance;
			bool podeAtacar;
			float duracaoCooldown;
			float timerCooldown;

		public:
			Personagem(sf::Vector2f pos);
			~Personagem();
			virtual void executar() = 0;
			void setVida(int v);
			int getVida();
			bool getAtacando();
			bool morreu();
			float getAlcance();
			void contaTempoAtaque(const float dt);
			void atualizapodeAtacar();
			float distanciaPersonagens(Personagem* pP);
			bool acertaAtaque(Personagem* p);
			void golpear(Personagem* p);
			void remover();
		};
	}
}