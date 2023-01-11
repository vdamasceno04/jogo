#pragma once
#include "entidade.h"

class Fundo : public Entidades::Entidade {
private:
	bool dia;
public:
	Fundo(Math::CoordF pos, bool dia);
	~Fundo();
	void executar();
};