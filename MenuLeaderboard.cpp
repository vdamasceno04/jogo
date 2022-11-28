#include "MenuLeaderboard.h"

namespace Menus {
	MenuLeaderboard::MenuLeaderboard() :
		Menu()
	{
		setValores();
		id = leaderboard;
		estado = 0;
	}

	MenuLeaderboard::~MenuLeaderboard()
	{

	}

	void MenuLeaderboard::setValores()
	{
		//Abrir Arquivo e Colocar no vetor de Text

		textura.loadFromFile("Assets/Escolha.png");
		sprite.setTexture(textura);

		caminho = ("Assets/ranking.txt");
		std::ifstream arquivo;
		try {
			arquivo.open(caminho, std::ios::binary | std::ios::in);
			if (arquivo)
				cout << "leitura realizada com sucesso" << endl;
			else
				throw(caminho);
		}
		catch (string caminho)
		{ // Se não abrir - criar
			std::ofstream writeFile(caminho, std::ios::out | std::ios::trunc);
			writeFile.close();
		}


		std::string nome;
		std::string textString;
		std::string pontos;


		textos.resize(11);
		for (int i = 1; i < textos.size(); ++i)
		{
			std::getline(arquivo, pontos);
			std::getline(arquivo, nome);

			textString = " *  " + nome + " ";
			textos[i].setFont(fonte);
			textos[i].setString(textString + " - " + pontos);
			textos[i].setCharacterSize(30);
			textos[i].setPosition(450.f, 50 + 60 * i);
			textos[i].setFillColor(sf::Color::Black);

			nome = "";
			pontos = "";
		}

	}




	void MenuLeaderboard::desenhar()
	{

		textos[0].setFont(fonte);
		textos[0].setString("Leaderboard");
		textos[0].setCharacterSize(36);
		textos[0].setPosition(460.f, 10);
		textos[0].setFillColor(sf::Color::Black);

		pGG->render(&sprite);
		for (auto t : textos) {
			pGG->render(&t);
		}
	}

	void MenuLeaderboard::loop()
	{
		selecionado = false;
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && !selecionado) {
			estado = -1;
		}
	}

	void MenuLeaderboard::executar()
	{
		loop();
		desenhar();
	}
}