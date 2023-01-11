#include "caracol.h"
#include "jogador.h"

#define ALCANCE 400
#define VMAXX 0

Caracol::Caracol(Math::CoordF pos, Jogador* p1, Jogador* p2, int ven, Gosma* pGosma) :
	Inimigo(pos, p1, p2) {
	id = caracol;
	gosma = pGosma;
	setSprite("Assets/caracol.png");
	setTamanho(Math::CoordF(125, 120));
	setEscala(Math::CoordF(5, 5));
	setPosicao(pos);
	alcance = ALCANCE;
	veneno = ven;
	inicializa(veneno);
	vmax.x = VMAXX;
	cuspir = false;
	velocidade.y = 0;
	pGosma->setCaracol(this);
}

Caracol::~Caracol() { }

void Caracol::inicializa(int veneno) {
	vida = veneno;
	visao = (veneno* 100);
}

bool Caracol::getCuspir() { return cuspir;  }

void Caracol::ataca(Jogador* pJ){ // por algum motivo esse ponteiro nao funciona
	if(fabs(pJ1->getPosicao().x - getPosicao().x) < visao 
		|| fabs(pJ2->getPosicao().x - getPosicao().x) < visao){
		cuspir = true;	
	}
	else
		cuspir = false;
}


void Caracol::executar() {
	remover();
	atualizar();
	atacado(pJ1);
	atacado(pJ2);
	ataca(pJ1);
	ataca(pJ2);

	renderizar();
}

