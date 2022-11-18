#pragma once
#include "ente.h"

Ente::Ente() {
	this->id = vazio;
	pGG = NULL;
}

Ente::~Ente() { pGG = NULL; }

ID Ente::getId() { return id; }
