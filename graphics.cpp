#include "graphics.h"

#include<cstring>
#include<iostream>

#define FONT_PATH "asset"
#define WIDTH 1200
#define HEIGHT 720
#define FRAME_RATE 100

namespace Managers {
	float Graphics::dt = 0;
	Graphics* Graphics::instance = NULL;

	Graphics* Graphics::getInstance() {
		if (instance == NULL)
			instance = new Graphics();
		return instance;
	}
	
	Graphics::Graphics() :
		window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Ibama++")),
		view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),
		texturesMap(), clock() {font = NULL;}
	
	Graphics::~Graphics() {
		std::map<const char*, sf::Texture*>::iterator it;
		for (it = texturesMap.begin(); it != texturesMap.end(); ++it)
			delete(it->second);

		delete(window);
	}

// desenha na janela um corpo apontado pelo ponteiro
	void Graphics::render(sf::RectangleShape* body) {
		window->draw(*body);
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
		if(isWindowOpen())
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
	void Graphics::setWindowSize(Math::CoordU size) {
		window->setSize(sf::Vector2u(size.x, size.y));
		view.setSize(size.x, size.y);
		window->setView(view);
	}

// retorna o tamanho da janela
	Math::CoordU Graphics::getWindowSize() const {
		return Math::CoordU(window->getSize().x, window->getSize().y);
	}

// muda a visão do centro da janela
	void Graphics::centerView(Math::CoordF pos) {
		view.setCenter(sf::Vector2f(pos.x, pos.y));
		window->setView(view);
	}

// carrega a textura indicada
	sf::Texture* Graphics::loadTexture(const char* path) {
		std::map<const char*, sf::Texture*>::iterator it = texturesMap.begin();
		while (it != texturesMap.end()) {
			if (!strcmp(it->first, path)) // checa se a textura ja foi carregada
				return it->second;
			it++;
		}
		sf::Texture* tex = new sf::Texture();

		if (!tex->loadFromFile(path)) {
			std::cout << "Erro ao carregar arquivo " << path << std::endl;
			exit(1);
		}

		texturesMap.insert(std::pair<const char*, sf::Texture*>(path, tex));
		return tex;
	}

// pega a fonte definida
	sf::Font* Graphics::getFont() {
		return font;
	}

// retorna o objeto janela
	sf::RenderWindow* Graphics::getWindow() {
		return window;
	}
}