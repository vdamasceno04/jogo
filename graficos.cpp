#include "graficos.h"

#include<cstring>
#include<iostream>
using std::cout;
using std::endl;
#define FONT_PATH "asset"
#define WIDTH 1280
#define HEIGHT 720
#define FRAME_RATE 100

namespace Gerenciadores {
	float Graficos::dt = 0;
	Graficos* Graficos::instance = NULL;

	//padrão de projeto singleton

	Graficos* Graficos::getInstance() {
		if (instance == NULL)
			instance = new Graficos();
		return instance;
	}

	void Graficos::apagarInstance() {
		if (instance != NULL)
			instance = NULL;
	}
	Graficos::Graficos() :
		window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Ibama++")),
		view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),
		clock() {
		font = NULL;
	}

	Graficos::~Graficos() {
		delete(window);
		apagarInstance();
	}

	sf::Clock Graficos::getClock() {
		return clock;
	}
	// desenha na janela um corpo apontado pelo ponteiro
	void Graficos::render(sf::Sprite* sprite) {
		window->draw(*sprite);
	}

	// desenha na janela um texto apontado pelo ponteiro
	void Graficos::render(sf::Text* text) {
		window->draw(*text);
	}

	// mostra tudo que foi desenhado na janela
	void Graficos::display() {
		if (isWindowOpen())
			window->display();
	}

	// limpa a janela
	void Graficos::clear() {
		if (isWindowOpen())
			window->clear();
	}

	// testa se a janela está aberta
	bool Graficos::isWindowOpen() const {
		if (window->isOpen())
			return true;
		return false;
	}

	//	fecha a janela
	void Graficos::closeWindow() {
		window->close();
	}


	// define o tamamho da janela
	void Graficos::setWindowSize(sf::Vector2u size) {
		window->setSize(sf::Vector2u(size.x, size.y));
		view.setSize(size.x, size.y);
		window->setView(view);
	}

	// retorna o tamanho da janela
	sf::Vector2u Graficos::getWindowSize() const {
		return sf::Vector2u(window->getSize().x, window->getSize().y);
	}


	// muda a visão do centro da janela
	void Graficos::centerView(sf::Vector2f pos) {
		view.setCenter(sf::Vector2f(pos.x, pos.y));
		window->setView(view);
	}

	sf::Vector2f Graficos::getView() {
		return view.getCenter();
	}

	// pega a fonte definida
	sf::Font* Graficos::getFont() {
		return font;
	}

	// retorna o objeto janela
	sf::RenderWindow* Graficos::getWindow() {
		return window;
	}

	// incrementa o tempo passado
	void Graficos::updateTime() {
		dt = clock.getElapsedTime().asSeconds();
		clock.restart();
	}
}
