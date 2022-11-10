#pragma once
#include <SFML/Graphics.hpp>
#include "coords.h"
#include "graphics.h"

class Ente {
protected:
	int id;
	Managers::Graphics* pGG;
public:
	Ente();
	~Ente();
	virtual void executar() = 0;
};