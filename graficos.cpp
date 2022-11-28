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
	float Graphics::dt = 0;
	Graphics* Graphics::instance = NULL;

	//padrão de projeto singleton

	Graphics* Graphics::getInstance() {
		if (instance == NULL)
			instance = new Graphics();
		return instance;
	}

	void Graphics::apagarInstance() {
		if (instance != NULL)
			instance = NULL;
	}
	Graphics::Graphics() :
		window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Ibama++")),
		view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),
		clock() {
		font = NULL;
	}

	Graphics::~Graphics() {
		delete(window);
		apagarInstance();
	}

	sf::Clock Graphics::getClock() {
		return clock;
	}
	// desenha na janela um corpo apontado pelo ponteiro
	void Graphics::render(sf::Sprite* sprite) {
		window->draw(*sprite);
	}

	// desenha na janela um texto apontado pelo ponteiro
	void Graphics::render(sf::Text* text) {
		window->draw(*text);
	}

	// mostra tudo que foi desenhado na janela
	void Graphics::display() {
		if (isWindowOpen())
			window->display();
	}

	// limpa a janela
	void Graphics::clear() {
		if (isWindowOpen())
			window->clear();
	}

	// testa se a janela está aberta
	bool Graphics::isWindowOpen() const {
		if (window->isOpen())
			return true;
		return false;
	}

	//	fecha a janela
	void Graphics::closeWindow() {
		window->close();
	}


	// define o tamamho da janela
	void Graphics::setWindowSize(sf::Vector2u size) {
		window->setSize(sf::Vector2u(size.x, size.y));
		view.setSize(size.x, size.y);
		window->setView(view);
	}

	// retorna o tamanho da janela
	sf::Vector2u Graphics::getWindowSize() const {
		return sf::Vector2u(window->getSize().x, window->getSize().y);
	}


	// muda a visão do centro da janela
	void Graphics::centerView(sf::Vector2f pos) {
		view.setCenter(sf::Vector2f(pos.x, pos.y));
		window->setView(view);
	}

	sf::Vector2f Graphics::getView() {
		return view.getCenter();
	}

	// pega a fonte definida
	sf::Font* Graphics::getFont() {
		return font;
	}

	// retorna o objeto janela
	sf::RenderWindow* Graphics::getWindow() {
		return window;
	}

	// incrementa o tempo passado
	void Graphics::updateTime() {
		dt = clock.getElapsedTime().asSeconds();
		clock.restart();
	}
}
