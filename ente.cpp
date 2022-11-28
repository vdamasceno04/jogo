#pragma once
#include "ente.h"

Ente::Ente() {
	this->id = vazio;
}

int Ente::pontuacao = 0;

Ente::~Ente() {}

Gerenciadores::Graficos* Ente::pGG = NULL;

void Ente::setpGG(Gerenciadores::Graficos* p) { pGG = p; }

ID Ente::getId() { return id; }

void Ente::operator+=(int valor) {
	pontuacao += valor;
}

void Ente::operator-=(int valor) {
	pontuacao -= valor;
}

void Ente::setPontos(int p) { pontuacao += p; }

int Ente::getPontuacao() { return pontuacao; }

int Ente::getPontos(ID id) {
	if (id == 6)
		return 200;
	else if (id == 7)
		return 800;
	else if (id == 8)
		return 300;
	return 0;

}
