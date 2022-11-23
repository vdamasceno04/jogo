#include "Menu.h"

#define HEIGHT 720
#define WIDTH 1280

Menu::Menu():
	Ente()
{
	//janela = nullptr;
	//janela = pGG->getWindow();
	setValores();
}

Menu::~Menu()
{
	//janela = NULL;

	opcao.clear();
	coordenadas.clear();
	textos.clear();
	tamanhos.clear();
}

void Menu::setValores()
{
	pos = tela = 0;
	selecionado = pressionado = escolha = placar = false;
	principal = true;

	//Iniciar Menu Principal
	fonte.loadFromFile("C:/Users/Usuario/Desktop/OmegaCringe/Assets/MainFont.ttf");
	textura.loadFromFile("C:/Users/Usuario/Desktop/OmegaCringe/Assets/Ibama.png");
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

	//Iniciar Menu de Escolhas
	texturaEscolha.loadFromFile("C:/Users/Usuario/Desktop/OmegaCringe/Assets/Escolha.png");
	spriteEscolha.setTexture(texturaEscolha);
	opcaoEscolha = { "Fase 1 - um jogador", "Fase 1 - dois jogadores", "Fase 2 - um jogador", "Fase 2 - dois jogadores" };
	coordEscolha = { {509.f,90.f}, {482.f,240.f}, {509.f,390.f}, {482.f,540.f} };
	tamEscolha = { 28,28,28,28 };

	textosEscolha.resize(4); // São 4 opções
	for (size_t i{}; i < textosEscolha.size(); ++i)
	{
		textosEscolha[i].setFont(fonte);
		textosEscolha[i].setString(opcaoEscolha[i]);
		textosEscolha[i].setCharacterSize(tamEscolha[i]);
		textosEscolha[i].setPosition(coordEscolha[i]);
		textosEscolha[i].setFillColor(sf::Color::Black);
		textosEscolha[i].setOutlineColor(sf::Color::Yellow);
	}
	textosEscolha[0].setOutlineThickness(4);
}

void Menu::loopPrincipal()
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
			escolha = true;
			principal = false;
		}
		else if (pos == 1)
		{
			placar = true;
			principal = false;
		}
		else if (pos == 2)
		{
			pGG->closeWindow();
		}
	}
}

void Menu::desenharPrincipal()
{
	pGG->render(&sprite);
	for (auto t : textos) {
		pGG->render(&t);
	}
}

int Menu::loopEscolha()
{
	selecionado = false;

	//Click para baixo (seta pra baixo)
	if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)/* || sf::Keyboard::isKeyPressed(sf::Keyboard::S)*/)) && !pressionado)
	{
		if (pos < 3)
		{
			pos++;
			pressionado = true;
			textosEscolha[pos].setOutlineThickness(4);
			textosEscolha[pos - 1].setOutlineThickness(0);
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
			textosEscolha[pos].setOutlineThickness(4);
			textosEscolha[pos + 1].setOutlineThickness(0);
			pressionado = false;
		}
	}
	//Quando o objeto marcado for selecionado
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::E)) && !selecionado)
	{
		selecionado = true;

		printf("Entrou\n");
		
		if (pos == 0)
		{
			return 1;
		}
		else if (pos == 1)
		{
			return 2;
		}
		else if (pos == 2)
		{
			return 3;
		}
		else if (pos == 3)
		{
			return 4;
		}
		
	}

	//Clickar Esc para voltar pro menu principal
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && !selecionado)
	{
		principal = true;
		escolha = false;
		pos = 0;
	}
	return 0;
}

void Menu::desenharEscolha()
{
	pGG->render(&spriteEscolha);
	for (auto t : textosEscolha) {
		pGG->render(&t);
	}
}

void Menu::loopPlacar()
{
	placar = false;
	principal = true;
}

void Menu::desenharPlacar()
{

}

int Menu::getTela() { return tela; }

void Menu::executar()
{
	if (principal)
	{
		loopPrincipal();
		desenharPrincipal();
	}
	else if (escolha)
	{
		tela = loopEscolha();
		desenharEscolha();
	}
	if (placar) {
		loopPlacar();
		desenharPlacar();
	}
}
