#pragma once
#include "ente.h"
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;

class Menu : public Ente{
private:
	int pos;
	int tela;
	bool selecionado;
	bool pressionado;

	bool principal;
	bool escolha;
	bool placar;

	sf::Font fonte;

	//Menu Principal
	sf::Texture textura;
	sf::Sprite sprite;
	vector <const char*> opcao;
	vector <sf::Vector2f> coordenadas;
	vector <sf::Text> textos;
	vector <size_t> tamanhos;

	//Menu de Escolhas
	sf::Texture texturaEscolha;
	sf::Sprite spriteEscolha;
	vector <const char*> opcaoEscolha;
	vector <sf::Vector2f> coordEscolha;
	vector <sf::Text> textosEscolha;
	vector <size_t> tamEscolha;

public:
	Menu();
	~Menu();
	void setValores();

	void executar();

	void loopPrincipal();
	void desenharPrincipal();
	int loopEscolha();
	void desenharEscolha();
	void loopPlacar();
	void desenharPlacar();

	int getTela();
};
