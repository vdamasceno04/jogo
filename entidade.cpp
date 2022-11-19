#include"entidade.h"
using namespace Entidades;

Entidade::Entidade(sf::Vector2f pos): Ente() {
	janela = NULL;
	remove = false;
	colidiu = false;
	posicao = pos;

}

Entidade::~Entidade() { janela = NULL; }

void Entidade::setPosicao(sf::Vector2f pos) {
	posicao = pos;
	body.setPosition(posicao);
	sprite.setPosition(posicao);
}

sf::Vector2f Entidade::getPosicao() const { return body.getPosition(); }

void Entidade::setTamanho(sf::Vector2f tam) { body.setSize(tam); }

sf::Vector2f Entidade::getTamanho() const { return body.getSize(); }

void Entidade::setEscala(sf::Vector2f scale) {
	body.setScale(scale);
	sprite.setScale(scale);
}

void Entidade::setJanela(sf::RenderWindow* j) { this->janela = j; }

sf::RectangleShape Entidade::getBody() { return body; }

bool Entidade::getRemove() { return remove; }

int Entidade::getDano() { return dano; }

void Entidade::renderizar() { pGG->render(&sprite); }

void Entidade::setVelocidade(sf::Vector2f vel) {
	velocidade = vel;
}

sf::Vector2f Entidade::getVelocidade() {
	return velocidade;
}

void Entidade::setSprite(const char* local) {
	textura.loadFromFile(local);
	sprite.setTexture(textura);
}


void Entidade::resolverColisao(Entidade* pEnt, float ix, float iy)
{
	if (ix < iy)
	{
		if (getPosicao().x > pEnt->getPosicao().x)
			setPosicao(sf::Vector2f(getPosicao().x + ix, getPosicao().y));
		else
			setPosicao(sf::Vector2f(getPosicao().x - ix, getPosicao().y));
		setVelocidade(sf::Vector2f(0, getVelocidade().y));
	}
	else
	{
		if (getPosicao().y > pEnt->getPosicao().y)
			setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y + iy));
		else
			setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y - iy));
		setVelocidade(sf::Vector2f(getVelocidade().x, 0));
	}
}
/*void Entidade::setColidido(Entidade* e) { colidido = e; }

Entidade* Entidade::getColidido() { return colidido; }

void Entidade::setColidiu(bool c) { colidiu = c; }

bool Entidade::getColidiu() { return colidiu; }
*/

sf::Sprite Entidade::getSprite() {
	return sprite;
}

