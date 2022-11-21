#include "Menu.h"

Menu::Menu(Managers::Graphics* pG) 
{
	pGG = pG;
	click = new sf::RectangleShape();
	fonte = new sf::Font();
	imgMenu = new sf::Texture();

	setValores();
}

Menu::~Menu()
{
	delete click;
	delete fonte;
	delete imgMenu;

	opcao.clear();
	coordenadas.clear();
	textos.clear();
	tamanhos.clear();
}

void Menu::setValores()
{
	pos = 1;
	//pressionado = selecionado = false;

	fonte->loadFromFile("C:/Users/Usuario/Desktop/OmegaCringe/Assets/MainFont.ttf");
	imgMenu->loadFromFile("C:/Users/Usuario/Desktop/OmegaCringe/Assets/Joao.png");
	fundoMenu.setTexture(*imgMenu);

	posMouse = { 0,0 };
	coordMouse = { 0,0 };

	opcao = { "Ibama++", "Jogar", "Escolher Fase", "Leaderboard", "Sair"};
	coordenadas = { {450,30}, {450,180}, {450,300}, {450,450}, {450,620} };
	tamanhos = { 28,24,24,24,24 };

	textos.resize(5); // São 5 opções

	for (size_t i{}; i < textos.size(); ++i) 
	{
		textos[i].setFont(*fonte);
		textos[i].setString(opcao[i]);
		textos[i].setCharacterSize(tamanhos[i]);
		textos[i].setPosition(coordenadas[i]);
		textos[i].setOutlineColor(sf::Color::Black);
	}
}

void Menu::desenhar() 
{
	//Fazer funcionar com o Gerenciador Gráfico
	/*
	pGG->render(&fundoMenu);
	for (auto t : textos) {
		pGG->render(t); // Desenhar os textos
	}
	*/
}

void Menu::loop()
{
	//Selecionar a opção
	selecionado = false;
	//Click para baixo (S ou seta)
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
	{
		if (pos < 4)
		{
			pos++;
			textos[pos].setOutlineThickness(4);
			textos[pos - 1].setOutlineThickness(0);

		}
	}
	//Click para cima (W ou seta)
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
	{
		if (pos > 1)
		{
			pos--;
			textos[pos].setOutlineThickness(4);
			textos[pos + 1].setOutlineThickness(0);

		}
	}

	//Quando o objeto marcado for selecionado
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && !selecionado)
	{
		selecionado = true;

		if (pos == 1)
		{
			//Criar Fase 1 Direto?
		}
		else if (pos == 2)
		{
			menuEscolher();//Menu para escolher as fases
		}
		else if (pos == 3)
		{
			//Abrir LeaderBoard que não existe ainda
		}
		else if (pos == 4)
		{
			//pGG->getWindow()->close(); // Ou algo do tipo para fechar o jogo
		}
	}
}
int Menu::menuEscolher() {
	//pGG->clear();
	sf::Text fase1;
	sf::Text fase2;

	selecionado = false;

	fase1.setFont(*fonte);
	fase1.setString("Fase 1");
	fase1.setCharacterSize(26);
	fase1.setPosition({450,200});
	fase1.setOutlineColor(sf::Color::Black);

	fase2.setFont(*fonte);
	fase2.setString("Fase 2");
	fase2.setCharacterSize(26);
	fase2.setPosition({ 450,550 });
	fase2.setOutlineColor(sf::Color::Black);

	//Redesenhar as novas opções na tela
	/*
	pGG->render(&fundoMenu);
	pGG->render(fase1);
	pGG->render(fase2);
	*/
	//Precisa Consertar o ponteiro de Gerenciador Grafico

	int posicao = 0;

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
	{
		if (pos < 1)
		{
			pos++;
			textos[pos].setOutlineThickness(4);
			textos[pos - 1].setOutlineThickness(0);

		}
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
	{
		if (pos > 0)
		{
			pos--;
			textos[pos].setOutlineThickness(4);
			textos[pos + 1].setOutlineThickness(0);

		}
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && !selecionado)
	{
		selecionado = true;

		if (pos == 0)
		{
			return 1;
		}
		else if (pos == 1)
		{
			return 2;
		}
		else
			return 0;
	}
}

