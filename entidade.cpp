#include"entidade.h"
using namespace Entidades;

Entidade::Entidade(sf::Vector2f pos, ID i): Ente(i) {
	janela = NULL;
	remove = false;
}

Entidade::~Entidade() { janela = NULL; }

void Entidade::setPosicao(sf::Vector2f pos) { 
	posicao = pos;
	body.setPosition(posicao);
	sprite.setPosition(posicao);
}

sf::Vector2f Entidade::getPosicao() const { return posicao; }

void Entidade::setTamanho(sf::Vector2f tam) {body.setSize(tam); }

sf::Vector2f Entidade::getTamanho() const { return tamanho; }

void Entidade::setEscala(sf::Vector2f scale) {
	body.setScale(scale);
	sprite.setScale(scale);
}

void Entidade::setJanela(sf::RenderWindow* j) { this->janela = j; }

sf::RectangleShape Entidade::getBody() { return body; }

bool Entidade::getRemove() { return remove; }

void Entidade::renderizar() { pGG->render(&sprite); }

void Entidade::setSprite(const char* local) {
	textura.loadFromFile(local);
	sprite.setTexture(textura);
}

