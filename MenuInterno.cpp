#include "MenuInterno.h"

MenuInterno::MenuInterno() :
	Menu()
{

}

MenuInterno::~MenuInterno() {};

bool MenuInterno::getParar() { return parar; }

bool MenuInterno::getSair() { return sair; }

void MenuInterno::setValores()
{
	ativo = sair = false;
	parar = true;

	textura.loadFromFile("Assets/Escolha.png");
	sprite.setTexture(textura);
	opcao = { "Continuar", "Salvar", "Carregar", "Sair" };
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

void MenuInterno::desenhar()
{
	pGG->render(&sprite);
	for (auto t : textos) {
		pGG->render(&t);
	}
}

void MenuInterno::loop() 
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
			parar = false;
			break;
		case(1):
			std::cout << "Não implementado ainda" << std::endl;
			parar = false;
			break;
		case(2):
			std::cout << "Não implementado ainda" << std::endl;
			parar = false;
			break;
		case(3):			
			sair = true;
			parar = false;
			break;
		}
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && !selecionado)
	{
		ativo = false;
		pos = 0;
	}
}

void MenuInterno::executar() 
{
	loop();
	desenhar();
}