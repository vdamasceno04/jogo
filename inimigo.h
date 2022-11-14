#pragma once
#include"personagem.h"

class Jogador;

class Inimigo : public Personagem {
protected:
	float viewRange; //Se o jogador entrar nessa distancia o inimigo atira ou persegue o jogador
	Jogador* pJ1;
	Jogador* pJ2;
public:
	Inimigo(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float alc, float dC, float dA, float vR, Jogador* p1, Jogador* p2);
	~Inimigo();
	virtual void executar() = 0;
	void setViewRange(float vR);
//	void setpJogador(Jogador* p);
	float getViewRange();
	bool setPersegue(Jogador* pJ);
	Jogador* setPerseguido(Jogador* pJ1, Jogador* pJ2);
	void perseguicao(Jogador* pJ);
};
