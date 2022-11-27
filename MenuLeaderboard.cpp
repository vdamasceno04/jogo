#include "MenuLeaderboard.h"

//Terminar Leaderboard depois

MenuLeaderboard::MenuLeaderboard():
	Menu()
{
    setValores();
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
	arquivo.open(caminho, std::ios::binary | std::ios::in);


	if (!arquivo) { // Se não abrir - criar
		std::ofstream writeFile(caminho, std::ios::out | std::ios::trunc);
		writeFile.close();
	}

	std::string name;
	std::string textString;
	std::string pointsString;

	
    textos.resize(11);
	for (int i = 1; i < textos.size(); ++i)
    {
        std::getline(arquivo, pointsString);
        std::getline(arquivo, name);

        textString = " *  " + name + " ";
        textos[i].setFont(fonte);
        textos[i].setString(textString + " - " + pointsString);
        textos[i].setCharacterSize(30);
        textos[i].setPosition(450.f, 50 + 60*i);
        textos[i].setFillColor(sf::Color::Black);

		name = "";
		pointsString = "";
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
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && !selecionado)
		ativo = false;
}

void MenuLeaderboard::executar()
{
	loop();
	desenhar();
}