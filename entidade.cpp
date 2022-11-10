#include"entidade.h"
using namespace Entidades;

Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam) {
	position = pos;
	size = size;
	window = NULL;
}

Entidade::~Entidade() {}

void Entidade::setPosition(sf::Vector2f pos) { position = pos; }

sf::Vector2f Entidade::getPosition() const { return position; }

void Entidade::setSize(sf::Vector2f siz) {body.setSize(siz); }

sf::Vector2f Entidade::getSize() const { return size; }

void Entidade::setVelocidade(sf::Vector2f vel) { velocidade = vel; }

sf::Vector2f Entidade::getVelocidade() { return velocidade; }

void Entidade::setWindow(sf::RenderWindow* window) { this->window = window; }

sf::RectangleShape Entidade::getBody() { return body; }

void Entidade::draw() { window->draw(body); }
