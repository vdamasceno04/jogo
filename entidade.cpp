#include"entidade.h"
using namespace Entidades;

Entidade::Entidade(sf::Vector2f pos): Ente() {
	janela = NULL;
	remove = false;
	posicao = pos;
	dano = 0;
}

Entidade::~Entidade() { janela = NULL; }


void Entidade::setPosicao(sf::Vector2f pos) {
	posicao = pos;
	body.setPosition(posicao);
	sprite.setPosition(posicao);
}

sf::Vector2f Entidade::getPosicao() const { return body.getPosition(); }


void Entidade::setVelocidade(sf::Vector2f vel) {
	velocidade = vel;
}

sf::Vector2f Entidade::getVelocidade() {
	return velocidade;
}


void Entidade::setTamanho(sf::Vector2f tam) { body.setSize(tam); }

sf::Vector2f Entidade::getTamanho() const { return body.getSize(); }

void Entidade::setEscala(sf::Vector2f scale) {
	body.setScale(scale);
	sprite.setScale(scale);
}


void Entidade::setJanela(sf::RenderWindow* j) { this->janela = j; }

sf::RectangleShape Entidade::getBody() { return body; }

void Entidade::setSprite(const char* local) {
	textura.loadFromFile(local);
	sprite.setTexture(textura);
}


void Entidade::renderizar() { pGG->render(&sprite); }

void Entidade::atualizar() {
	float dt = 0.1;
	if (getPosicao().y + getTamanho().y < HEIGHT)
		setPosicao(sf::Vector2f(getPosicao().x + getVelocidade().x * dt, getPosicao().y + (getVelocidade().y * dt) + GRAVIDADE * dt * dt / 2));

	setVelocidade(sf::Vector2f(getVelocidade().x, getVelocidade().y + GRAVIDADE * dt));
}


void Entidade::tomaDano(int ferimento) { vida -= ferimento; }

bool Entidade::getRemove() { return remove; }

void Entidade::setRemove(bool rem) { remove = rem; }
int Entidade::getDano() { return dano; }

void Entidade::setColidindo(bool chao) { colidindo = chao; }

bool Entidade::getColidindo() { return colidindo; }


