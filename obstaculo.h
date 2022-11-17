#pragma once
#include "entidade.h"

class Personagem;

namespace Obstaculos {

	class Obstaculo : public Entidades::Entidade {
	protected:
		bool danificar;
		float lentidao;
		int dano;
		float duracaoCooldown;
		float timerCooldown;

	public:
		Obstaculo(sf::Vector2f pos, ID i);
		~Obstaculo();
		bool  getDanificar();
		int   getDano();
		float getCooldown();
		void contaTempoCooldown(const float dt);
		void atualizaDanificar();
		float getLentidao();
		virtual void executar() = 0;
		virtual void colidir(Entidade* pEnt, ID id) { }
	};
}