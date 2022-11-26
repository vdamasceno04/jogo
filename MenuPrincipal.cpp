#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal():
	Menu(),
	menuEscolha(),
	menuLeaderboard()
{
	setValores();
}

MenuPrincipal::~MenuPrincipal()
{

}

bool MenuPrincipal::getEscolhaAtivo() { return menuEscolha.getAtivo(); }

bool MenuPrincipal::getLeaderboardAtivo() { return menuLeaderboard.getAtivo(); }

int MenuPrincipal::getEscolheu() { return menuEscolha.getEscolha(); }

int MenuPrincipal::getEscolhaFase() { return menuEscolha.getFase(); }

int MenuPrincipal::getEscolhaJogador() { return menuEscolha.getJogador(); }

void MenuPrincipal::setValores()
{
	ativo = true;

	textura.loadFromFile("Assets/Ibama.png");
	sprite.setTexture(textura);
	opcao = { "Jogar", "Leaderboard", "Sair" };
	coordenadas = { {153.f,280.f}, {102.f,410.f}, {166.f,532.f} };
	tamanhos = { 32,32,32 };

	textos.resize(3); // São 3 opções
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

void MenuPrincipal::loop()
{
	selecionado = false;

	//Click para baixo (S)
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)/* || sf::Keyboard::isKeyPressed(sf::Keyboard::S)*/) && !pressionado)
	{
		if (pos < 2)
		{
			pos++;
			pressionado = true;
			textos[pos].setOutlineThickness(4);
			textos[pos - 1].setOutlineThickness(0);
			pressionado = false;
		}
	}
	//Click para cima (W)
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)/* || sf::Keyboard::isKeyPressed(sf::Keyboard::W)*/) && !pressionado)
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
	//Quando o objeto marcado for selecionado
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && !selecionado)
	{
		selecionado = true;

		if (pos == 0)
		{
			ativo = false;
			menuEscolha.setAtivo(true);
		}
		else if (pos == 1)
		{
			ativo = false;
			menuLeaderboard.setAtivo(true);
		}
		else if (pos == 2)
		{
			pGG->closeWindow();
		}
	}
}

void MenuPrincipal::desenhar()
{
	pGG->render(&sprite);
	for (auto t : textos) {
		pGG->render(&t);
	}
}

void MenuPrincipal::executar()
{
	if (ativo)
	{
		loop();
		desenhar();
	}
	else if (menuEscolha.getAtivo())
	{
		menuEscolha.executar();
		if (!menuEscolha.getAtivo() && menuEscolha.getEscolha() == 0)
			ativo = true;
	}
	else if (menuLeaderboard.getAtivo()) 
	{
		menuLeaderboard.executar();
		if (!menuLeaderboard.getAtivo())
			ativo = true;
	}
}
