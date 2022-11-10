#pragma once
#include "Obstaculo.h"

class Espinho :public Obstaculos::Obstaculo {
private:
	sf::Sprite espinho;
	string caminhoSprite;

public:
	Espinho(sf::Vector2f pos, sf::Vector2f tam, int d, float dC, string cS);
	~Espinho();


};
