#include"entidade.h"
using namespace Entidades;

Entidade::Entidade(sf::Vector2f pos, ID i) : Ente(i) {
	janela = NULL;
	remove = false;

	posicao = pos;

	esqCima = pos;
	esqBaixo = sf::Vector2f(pos.x, pos.y + getTamanho().y);
	dirCima = sf::Vector2f(pos.x + getTamanho().x, pos.y);
	dirBaixo = sf::Vector2f(pos.x + getTamanho().x, pos.y + getTamanho().y);
}

Entidade::~Entidade() { janela = NULL; }

void Entidade::setPosicao(sf::Vector2f pos) {
	posicao = pos;
	body.setPosition(posicao);
	sprite.setPosition(posicao);

	atualizaPontos();
}

sf::Vector2f Entidade::getPosicao() const { return posicao; }

void Entidade::setTamanho(sf::Vector2f tam) { body.setSize(tam); }

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

void Entidade::atualizaPontos() {
	sf::Vector2f pos = posicao;

	esqCima = pos;
	esqBaixo = sf::Vector2f(pos.x, pos.y + getTamanho().y);
	dirCima = sf::Vector2f(pos.x + getTamanho().x, pos.y);
	dirBaixo = sf::Vector2f(pos.x + getTamanho().x, pos.y + getTamanho().y);


}

sf::Sprite Entidade::getSprite() {
	return sprite;
}

//Del Soon
float Entidade::getLadoCima() { return posicao.y; }
float Entidade::getLadoEsquerdo() { return posicao.x; }
float Entidade::getLadoDireito() { return posicao.x + tamanho.x; }
float Entidade::getLadoBaixo() { return posicao.y + tamanho.y; }

