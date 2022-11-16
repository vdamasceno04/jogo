#include "Obstaculo.h"
using namespace Obstaculos;

Obstaculo::Obstaculo(sf::Vector2f pos, ID i) :
	Entidade::Entidade(pos, i)
{
	danificar = false;
	lentidao = 0.0;
	dano = 0;
	timerCooldown = 0;
	duracaoCooldown = 0;
}

Obstaculo::~Obstaculo() {}

float Obstaculo::getLentidao() { return lentidao; }

int Obstaculo::getDano() { return dano; }

bool Obstaculo::getDanificar() { return danificar; }

float Obstaculo::getCooldown() { return duracaoCooldown; }

void Obstaculo::contaTempoCooldown(const float dt) {
	if (danificar) {
		timerCooldown = 0;
		danificar = false;
	}
	else
		timerCooldown += dt;
}

void Obstaculo::atualizaDanificar()
{
	if (duracaoCooldown <= timerCooldown)
		danificar = true;
	else
		danificar = false;
}