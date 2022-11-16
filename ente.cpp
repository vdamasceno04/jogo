#pragma once
#include "ente.h"

Ente::Ente(ID i) {
	this->id = vazio;
	pGG = NULL;
}

Ente::~Ente() { pGG = NULL; }

void Ente::setpGG(Managers::Graphics* p) { pGG = p; }

ID Ente::getId() { return id; }
