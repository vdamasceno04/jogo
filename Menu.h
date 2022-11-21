#pragma once
#include "graphics.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Menu
{
private:
	int pos;
	//bool pressionado;
	bool selecionado;

	sf::RectangleShape* click;
	sf::Font* fonte;
	sf::Texture* imgMenu;
	sf::Sprite fundoMenu;
	sf::Vector2f posMouse;
	sf::Vector2f coordMouse;

	vector <const char*> opcao;
	vector <sf::Vector2f> coordenadas;
	vector <sf::Text> textos;
	vector <size_t> tamanhos;

public:
	Managers::Graphics* pGG;
	Menu(Managers::Graphics* pG);
	~Menu();

	//void executar();
	void loop();
	void desenhar();
	void setValores();

	int menuEscolher();
};

