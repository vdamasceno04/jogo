#include "MenuEscolha.h"

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

int MenuEscolha::getEscolha() { return escolha; }

int MenuEscolha::getJogador() { return jogadores; }

int MenuEscolha::getFase() { return fase; }

void MenuEscolha::setValores()
{
	jogadores = fase = 0;
	ativo = false;
	escolha = 0;

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

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::E)) && !selecionado)
	{
		switch (pos)
		{
		case(0):
			jogadores = 1;
			fase = 1;
			escolha = 1;
			ativo = false;
			estado = 1;
			break;
		case(1):
			jogadores = 2;
			fase = 1;
			escolha = 2;
			ativo = false;
			estado = 2;
			break;
		case(2):
			jogadores = 1;
			fase = 2;
			escolha = 3;
			ativo = false;
			estado = 3;
			break;
		case(3):
			jogadores = 2;
			fase = 2;
			escolha = 4;
			ativo = false;
			estado = 4;
			break;
		}
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && !selecionado)
	{
		ativo = false;
		pos = 0;
	}
}

void MenuEscolha::executar()
{
	desenhar();
	loop();
}