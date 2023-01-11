#include"entidade.h"
using namespace Entidades;

Entidade::Entidade(Math::CoordF pos): Ente() {
	janela = NULL;
	remove = false;
	colidindo = false;
	posicao = pos;
	dano = 0;
}

Entidade::~Entidade() { janela = NULL; }


void Entidade::setPosicao(Math::CoordF pos) { //	ACOPLADO
	posicao = pos;
	body.setPosition(sf::Vector2f(posicao.x, posicao.y)); 
	sprite.setPosition(sf::Vector2f(posicao.x, posicao.y));
}

Math::CoordF Entidade::getPosicao() const { return Math::CoordF(body.getPosition().x, body.getPosition().y); }


void Entidade::setVelocidade(Math::CoordF vel) {
	velocidade = vel;
}

Math::CoordF Entidade::getVelocidade() const {
	return velocidade;
}


void Entidade::setTamanho(Math::CoordF tam) { body.setSize(sf::Vector2f(tam.x, tam.y)); }

Math::CoordF Entidade::getTamanho() const { return Math::CoordF(body.getSize().x, body.getSize().y); }

void Entidade::setEscala(Math::CoordF scale) {
	body.setScale(sf::Vector2f(scale.x, scale.y));
	sprite.setScale(sf::Vector2f(scale.x, scale.y));
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
		setPosicao(Math::CoordF(getPosicao().x + getVelocidade().x * dt, getPosicao().y + (getVelocidade().y * dt) + GRAVIDADE * dt * dt / 2));

	setVelocidade(Math::CoordF(getVelocidade().x, getVelocidade().y + GRAVIDADE * dt));
}


void Entidade::tomaDano(int ferimento) { vida -= ferimento; }

bool Entidade::getRemove() { return remove; }

void Entidade::setRemove(bool rem) { remove = rem; }
int Entidade::getDano() const { return dano; }

void Entidade::setColidindo(bool chao) { colidindo = chao; }

bool Entidade::getColidindo() { return colidindo; }


