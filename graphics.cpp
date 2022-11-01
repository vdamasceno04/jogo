#include "graphics.h"

#include<cstring>
#include<iostream>

#define FONT_PATH "asset"
#define WIDTH 1200
#define HEIGHT 720
#define FRAME_RATE 100

namespace Managers {
	Graphics* Graphics::instance = NULL;
	Graphics* Graphics::getInstance() {
		if (instance == NULL)
			instance = new Graphics();
		return instance;
	}
	float Graphics::dt = 0;
	
	Graphics::Graphics() :
		window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Ibama")),
		view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),
		texturesMap(), clock() {font = NULL;}
	
	Graphics::~Graphics() {
		std::map<const char*, sf::Texture*>::iterator it;
		for (it = texturesMap.begin(); it != texturesMap.end(); ++it)
			delete(it->second);

		delete(window);
	}

	void Graphics::render(sf::RectangleShape* body) {
		window->draw(*body);
	}

	void Graphics::render(sf::Text* text) {

	}
	void Graphics::display() {

	}
	void Graphics::clear() {

	}
	bool Graphics::isWindowOpen() const {

	}
	void Graphics::closeWindow() {

	}
	void Graphics::handleWindowResize() {

	}
	/*
	void Graphics::setWindowSize(Math::CoordU size) {
		window->setSize(sf::Vector2u(size.get_x(), size.get_y()));
		view.setSize(size.get_x(), size.get_y());
		window->setView(view);

	}
	sf::Vector2u Graphics::getWindowSize() const {
		return Math::CoordU(window->getSize().x, window->getSize().y);

	}*/
	void Graphics::centerView(Math::CoordF pos) {

	}
	sf::Texture* Graphics::loadTexture(const char* path) {

	}
	sf::Font* Graphics::getFont() {

	}
	void Graphics::updateTime() {

	}













}