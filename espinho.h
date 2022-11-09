#pragma once
#include "Obstaculo.h"

class Espinho :public Obstaculos::Obstaculo {
private:
	sf::Sprite Espinho;
	string caminhoSprite;

public:
	Espinho(Math::CoordF pos, Math::CoordF tam, int d, float dC, string cS);
	~Espinho();


};
