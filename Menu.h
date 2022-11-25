#pragma once
#include "ente.h"
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;

class Menu : public Ente{
protected:
	int pos;
	bool selecionado;
	bool pressionado;
	bool ativo;

	sf::Font fonte;

	//Menu Principal
	sf::Texture textura;
	sf::Sprite sprite;
	vector <const char*> opcao;
	vector <sf::Vector2f> coordenadas;
	vector <sf::Text> textos;
	vector <size_t> tamanhos;

public:
	Menu();
	~Menu();
	void setValores();

	int getAtivo();
	void setAtivo(bool at);

	virtual void executar() = 0;
	virtual void loop() = 0;
	virtual void desenhar() = 0;

};
