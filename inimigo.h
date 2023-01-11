#pragma once
#include"personagem.h"

class Jogador;

class Inimigo : public Personagem {
protected:
	int visao; //Se o jogador entrar nessa distancia o inimigo atira ou persegue o jogador
	int pontos;
	Jogador* pJ1;
	Jogador* pJ2;

public:
	Inimigo(Math::CoordF pos, Jogador* p1, Jogador* p2);
	~Inimigo();
	virtual void executar() = 0;
	void setVisao(float visao);
	float getVisao();
	bool getPersegue(Jogador* pJ);
	Jogador* definePerseguido(Jogador* pJ1, Jogador* pJ2);
	void perseguicao(Jogador* pJ);
	void atacado(Jogador* pJ);
	virtual void ataca(Jogador* pJ) {};
	void hostilizar();
};
