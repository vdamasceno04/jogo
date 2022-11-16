#include"entidade.h"
using namespace Entidades;

Entidade::Entidade(sf::Vector2f pos, ID i): Ente(i) {
	setPosition(pos);
	window = NULL;
	remove = false;
}

Entidade::~Entidade() { window = NULL; }

void Entidade::setPosition(sf::Vector2f pos) { 
	position = pos;
	body.setPosition(position);
	sprite.setPosition(position);
}

sf::Vector2f Entidade::getPosition() const { return position; }

void Entidade::setSize(sf::Vector2f siz) {body.setSize(siz); }

sf::Vector2f Entidade::getSize() const { return size; }

void Entidade::setWindow(sf::RenderWindow* window) { this->window = window; }

sf::RectangleShape Entidade::getBody() { return body; }

bool Entidade::getRemove() { return remove; }

void Entidade::renderizar() { pGG->render(&sprite); }

void Entidade::setSprite(const char* local) {
	textura.loadFromFile(local);
	sprite.setTexture(textura);
}

