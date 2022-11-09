#pragma once
#include "entidade.h"

namespace Obstaculos {

	class Obstaculo : public Entidades::Entidade {
	protected:
		bool danificar;
		bool liquido;
		int dano;
		float danoCooldown;

	public:
		Obstaculo(Math::CoordF pos, Math::CoordF tam, int d, float dC);
		~Obstaculo();
		bool  getDanificar() { return danificar; }
		bool  getLiquido() { return liquido; }
		int   getDano() { return dano; }
		float getDanoCooldown() { return danoCooldown; }
		void setDanificar(bool d);
		void setLiquido(bool l);
		void setDano(int d);
		void setDanoCooldown(float dC);
	};
}
