#include "jogo.h"
#include<stdio.h>
#include<map>
#include<fstream>
using std::ofstream;
using std::string;
using std::cerr;
using std::fstream;

using namespace Fases;
#define CAMINHO "ranking.txt"
Jogo::Jogo() :
    pGG(Graphics::getInstance()), pGC(GerenciadorColisoes::getInstancia(&Fase::listaMov, &Fase::listaEst)),
    pGE(GerenciadorEstado::getGerenciadorEstado()) //singleton tudo isso aqui
{
    Ente::setpGG(Graphics::getInstance());
    tela = 0;
    flagFase = true;

    pGE->addEstado(menuprincipal);
    executar();
}

Jogo::~Jogo() {
    Managers::Graphics::apagarInstance();
}

void Jogo::executar() {
    
    sf::Event event;
    while (pGG->isWindowOpen())
    {
        while (pGG->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGG->closeWindow();
        }
        pGG->clear();
        if (pGE->tamanhoPilha() != 0)
            pGE->executar();
        else
            pGG->closeWindow();
        pGG->display();
    }
    //system("clear||cls");
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

    writeFile.close();
}