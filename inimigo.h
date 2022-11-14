#pragma once
#include"personagem.h"

class Jogador;

class Inimigo : public Personagem {
protected:
	float viewRange; //Se o jogador entrar nessa distancia o inimigo atira ou persegue o jogador
	bool persegue;
	Jogador* pJogador;
public:
	Inimigo(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float dC, float dA, float vR, bool p, Jogador* pJ);
	~Inimigo();
	virtual void executar() = 0;
	void setViewRange(float vR);
	void setpJogador(Jogador* p);
	float distanciaJogador(Jogador* pJ);
	float getViewRange();
	void setPerseguir();
	void perseguicao();
};
