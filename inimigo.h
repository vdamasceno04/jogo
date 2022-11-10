#pragma once
#include"personagem.h"

class Inimigo : public Personagem {
protected:
	float viewRange; //Se o jogador entrar nessa distancia o inimigo atira ou persegue o jogador

public:
	Inimigo(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float dC, float dA, float vR);
	~Inimigo();
	virtual void executar() = 0;
	void setViewRange(float vR);
	float getViewRange();
};
