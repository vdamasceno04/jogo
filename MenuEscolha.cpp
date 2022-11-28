#include "MenuEscolha.h"

namespace Menus {
	MenuEscolha::MenuEscolha() :
		Menu()
	{
		setValores();
		id = menuescolha;
		estado = 0;
	}

	MenuEscolha::~MenuEscolha()
	{

	}


	void MenuEscolha::setValores()
	{

		textura.loadFromFile("Assets/Escolha.png");
		sprite.setTexture(textura);
		opcao = { "Fase 1 - um jogador", "Fase 1 - dois jogadores", "Fase 2 - um jogador", "Fase 2 - dois jogadores" };
		coordenadas = { {509.f,90.f}, {482.f,240.f}, {509.f,390.f}, {482.f,540.f} };
		tamanhos = { 28,28,28,28 };

		textos.resize(4); // São 4 opções
		for (size_t i{}; i < textos.size(); ++i)
		{
			textos[i].setFont(fonte);
			textos[i].setString(opcao[i]);
			textos[i].setCharacterSize(tamanhos[i]);
			textos[i].setPosition(coordenadas[i]);
			textos[i].setFillColor(sf::Color::Black);
			textos[i].setOutlineColor(sf::Color::Yellow);
		}
		textos[0].setOutlineThickness(4);
	}

	void MenuEscolha::desenhar()
	{
		pGG->render(&sprite);
		for (auto t : textos) {
			pGG->render(&t);
		}
	}

	void MenuEscolha::loop()
	{
		selecionado = false;

		//Click para baixo (seta pra baixo)
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)/* || sf::Keyboard::isKeyPressed(sf::Keyboard::S)*/)) && !pressionado)
		{
			if (pos < 3)
			{
				pos++;
				pressionado = true;
				textos[pos].setOutlineThickness(4);
				textos[pos - 1].setOutlineThickness(0);
				pressionado = false;
			}
		}
		//Click para cima (seta pra cima)
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)/* || sf::Keyboard::isKeyPressed(sf::Keyboard::W)*/)) && !pressionado)
		{
			if (pos > 0)
			{
				pressionado = true;
				pos--;
				textos[pos].setOutlineThickness(4);
				textos[pos + 1].setOutlineThickness(0);
				pressionado = false;
			}
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && !selecionado) {
			estado = -1;
		}


		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::E)) && !selecionado)
		{
			switch (pos)
			{
			case(0):
				estado = 1;
				break;

			case(1):
				estado = 2;
				break;

			case(2):
				estado = 3;
				break;

			case(3):
				estado = 4;
				break;
			}
		}

	}

	void MenuEscolha::executar()
	{
		desenhar();
		loop();
	}
}