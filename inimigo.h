#pragma once
#include"personagem.h"

class Jogador;

class Inimigo : public Personagem {
protected:
	float viewRange; //Se o jogador entrar nessa distancia o inimigo atira ou persegue o jogador
	Jogador* pJ1;
	Jogador* pJ2;

public:
	Inimigo(sf::Vector2f pos, Jogador* p1, Jogador* p2, ID i);
	~Inimigo();
	virtual void executar() = 0;
	void setViewRange(float vR);
	float getViewRange();
	bool getPersegue(Jogador* pJ);
	Jogador* setPerseguido(Jogador* pJ1, Jogador* pJ2);
	void perseguicao(Jogador* pJ);
	void ataca(Jogador* pJ);
	void hostilizar();
};
