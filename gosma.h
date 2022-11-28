#pragma once
#include "entidade.h"

class Caracol;
namespace Entidades {
	class Gosma : public Entidade {
	private:
		int veneno;
		Caracol* pCaracol;
	public:
		Gosma(sf::Vector2f pos, int veneno);
		~Gosma();
		void setCaracol(Caracol* pCar);
		void inicializar();
		void executar();
		void efeito(Entidade* p);
	};
}