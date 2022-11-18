#pragma once
#include "ente.h"

Ente::Ente() {
	this->id = vazio;
}

Ente::~Ente() {}

Managers::Graphics* Ente::pGG = NULL;

void Ente::setpGG(Managers::Graphics* p) { pGG = p; }

ID Ente::getId() { return id; }
