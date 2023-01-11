#pragma once
#include "entidade.h"

class Personagem;

namespace Obstaculos {

	class Obstaculo : public Entidades::Entidade {
	protected:

		bool causaEfeito;

	public:
		Obstaculo(Math::CoordF pos);
		~Obstaculo();

		virtual void efeito(Entidade* p) {};
		virtual void executar() = 0;
		
	};
}