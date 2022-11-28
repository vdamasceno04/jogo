#pragma once
#include "entidade.h"

namespace Entidades {
	class Fundo : public Entidade {
	private:
		bool dia;
	public:
		Fundo(sf::Vector2f pos, bool dia);
		~Fundo();
		void executar();
	};
}