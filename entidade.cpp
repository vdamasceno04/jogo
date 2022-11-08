#include"entidade.h"
using namespace Entidades;

Entidade::Entidade(Math::CoordF pos, Math::CoordF tam) {
	position = pos;
	size = size;
	window = NULL;
}

Entidade::~Entidade() {}

void Entidade::setPosition(Math::CoordF pos) { position = pos; }

Math::CoordF Entidade::getPosition() const { return position; }

void Entidade::setSize(Math::CoordF siz) {size = siz; }

Math::CoordF Entidade::getSize() const { return size; }

void Entidade::setVelocidade(Math::CoordF vel) { velocidade = vel; }

Math::CoordF Entidade::getVelocidade() { return velocidade; }

void Entidade::setWindow(sf::RenderWindow* window) { this->window = window; }

sf::RectangleShape Entidade::getBody() { return body; }

void Entidade::draw() { window->draw(body); }
