#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal() :
	Menu()	
{
	id = menuprincipal;
	setValores();
	estado = 0;
}

MenuPrincipal::~MenuPrincipal()
{

}

void MenuPrincipal::insereNome() { //funcionalidade de registrar nome nao acabada
	/*system("clear||cls");
	string nome;
	cout << "pontuacao = " << Ente::getPontuacao() << endl << "insira seu nome" << endl;
	cin >> nome;
	string filename(CAMINHO);
	fstream output_fstream;

	output_fstream.open(filename, std::ios_base::out);
	if (!output_fstream.is_open()) {
		cerr << "Failed to open " << filename << '\n';
	}
	else {
		output_fstream << nome << endl << Ente::getPontuacao() << endl;
	}

	std::ifstream readFile;

	readFile.open(CAMINHO, std::ios::in);

	std::multimap<int, std::string> mapaRanking;

	if (readFile) {

		unsigned int pontos;
		std::string name;
		std::string pointsString;

		for (int i = 0; i < 10; i++) {
			std::getline(readFile, pointsString);
			std::getline(readFile, name);
			if (pointsString.length() > 0)
				mapaRanking.insert(std::pair<int, std::string>(std::stoi(pointsString), name));
		}

		readFile.close();
	}


	if (Ente::getPontuacao() != 0)//&& input.getString().length() > 1)
		mapaRanking.insert(std::pair<int, std::string>(Ente::getPontuacao(), nome));

	std::ofstream writeFile;

	writeFile.open(CAMINHO, std::ios::out | std::ios::trunc);

	if (!writeFile) {
		std::cout << "Erro ao escrever pontuacao" << std::endl;
		exit(1);
	}

	while (mapaRanking.size() > 10)
		mapaRanking.erase(mapaRanking.begin());

	for (auto itr = mapaRanking.rbegin(); itr != mapaRanking.rend(); ++itr) {
		writeFile << (*itr).first << std::endl;
		writeFile << (*itr).second << std::endl;
	}

	writeFile.close();*/
}
void MenuPrincipal::setValores()
{

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
			estado = 1; // opcao para menu de escolha
		}
		else if (pos == 1)
		{
			estado = 2; // opcao para leaderboard
		}
		else if (pos == 2)
		{
			insereNome();
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
	loop();
	desenhar();
	
}
