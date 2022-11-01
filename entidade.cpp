#include"entidade.h"
using namespace Entities;

Entidade::Entidade(Math::CoordF pos, Math::CoordF s, ID i){
	position = pos;
	size = s;
	id = i;
}

Entities::Entidade::~Entidade() {}

void Entidade::setPosition(Math::CoordF pos) { position = pos; };
void Entidade::setWindow(sf::RenderWindow* window) { this->window = window; }
void Entidade::draw() { window->draw(body); }
Math::CoordF Entidade::getPosition() const{ return position; }
Math::CoordF Entidade::getSize() const{ return size; }
ID Entidade::getId() const{ return id; }