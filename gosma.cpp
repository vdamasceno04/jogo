#include "gosma.h"
#include "caracol.h"

#define VMAXX 15
#define VMAXY -29.8
using namespace Personagens;


namespace Entidades {
	Gosma::Gosma(sf::Vector2f pos, int ven) : Entidades::Entidade(pos) {
		id = gosma;
		setPosicao(sf::Vector2f(pos.x + 20, pos.y + 60));
		setEscala(sf::Vector2f(2, 2));
		body.setSize(sf::Vector2f(4, 8));
		veneno = ven;
		vmax.x = VMAXX;
		vmax.y = VMAXY;
		setVelocidade(sf::Vector2f(-vmax.x, vmax.y));
		setSprite("Assets/gosma.png");
		inicializar();
	}

	Gosma::~Gosma() {}

	void Gosma::inicializar() {
		setVelocidade(sf::Vector2f(-vmax.x, vmax.y));
		dano = veneno - 1;
	}

	void Gosma::setCaracol(Caracol* pCar) {
		pCaracol = pCar;
	}

	void Gosma::efeito(Entidade* p) {
		p->tomaDano(dano);
		colidindo = true;
	}

	void Gosma::executar() {
		if (pCaracol->getCuspir() || (this->getPosicao().x - 20 != pCaracol->getPosicao().x)) {
			atualizar();
		}
		if (colidindo) {
			inicializar();
			setPosicao(sf::Vector2f(pCaracol->getPosicao().x + 20, pCaracol->getPosicao().y + 60));
			setColidindo(false);
			if (pCaracol->getRemove())
				setRemove(true);
		}
		renderizar();
	}
}