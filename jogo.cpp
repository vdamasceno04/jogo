#include "jogo.h"
#include<stdio.h>
#include<map>
#include<fstream>
using std::ofstream;
using std::string;
using std::cerr;
using std::fstream;
using namespace Fases;

Jogo::Jogo() :
    pGG(Graphics::getInstance()), pGC(GerenciadorColisoes::getInstancia(&Fase::listaMov, &Fase::listaEst)),
    fase1(Graphics::getInstance(), GerenciadorColisoes::getInstancia(&Fase::listaMov, &Fase::listaEst)),
    fase2(Graphics::getInstance(), GerenciadorColisoes::getInstancia(&Fase::listaMov, &Fase::listaEst)),
    menuPrincipal()
{
    Ente::setpGG(Graphics::getInstance());
    tela = 0;
    flagFase = true;
    executar();
}

Jogo::~Jogo() {
    Managers::Graphics::apagarInstance();
}

void Jogo::inicializar() {
    menuPrincipal.setValores();
}

void Jogo::executar()
{
    inicializar();
    sf::Event event;
    while (pGG->isWindowOpen())
    {
        while (pGG->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGG->closeWindow();

            //Menu
            if (tela == 0)
            {
                pGG->clear();
                menuPrincipal.executar();
                if (!flagFase)
                    flagFase = true;
                tela = menuPrincipal.getTela();
                pGG->display();
            }
        }
        //Fase 1 (era pra ser com um jogador mas tem 2)
        if (tela == 1)
        {
            pGG->clear();
            if (flagFase) {
                fase1.set2jogadores(false);
                fase1.inicializar();
                flagFase = false;
            }
            fase1.executar();
            fase1.colidir();
            pGG->display();
        }

        //Fase 1 (dois jogadores)
        else if (tela == 2)
        {
            pGG->clear();
            if (flagFase) {
                fase1.set2jogadores(true);
                fase1.inicializar();
                flagFase = false;
            }
            fase1.executar();
            fase1.colidir();
            pGG->display();
        }
        //Fase 2 (era pra ser com um jogador mas tem 2)
        else if (tela == 3)
        {
            pGG->clear();
            if (flagFase) {
                fase2.set2jogadores(false);
                fase2.inicializar();
                flagFase = false;
            }
            fase2.executar();
            fase2.colidir();
            pGG->display();
        }
        //Fase 2 (dois jogadores)
        else if (tela == 4)
        {
            pGG->clear();
            if (flagFase) {
                fase2.set2jogadores(true);
                fase2.inicializar();
                flagFase = false;
            }
            fase2.executar();
            fase2.colidir();
            pGG->display();
        }

    }
}
/*

#define CAMINHO "ranking.txt"

Jogo::Jogo() :
    pGG(Graphics::getInstance()),
    fase1(Graphics::getInstance())//,
//    fase2(Graphics::getInstance())
{
    Ente::setpGG(Graphics::getInstance());
    executar();
}

Jogo::~Jogo() {
    Managers::Graphics::apagarInstance();
}

void Jogo::inicializar() {
    fase1.inicializar();
//    fase2.inicializar();
}

void Jogo::executar()
{
    inicializar();
    while (pGG->isWindowOpen())
    {
        sf::Event event;
        while (pGG->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGG->closeWindow();
        }
        pGG->clear();
        if (fase1.fimFase())
            pGG->closeWindow();
        fase1.executar();
        fase1.colidir();

        pGG->display();

    }
 
    string nome;
    cout << "pontuacao = " << Ente::getPontuacao() << endl << "insira seu nome" << endl;
    cin >> nome;
    string filename("output.txt");
    fstream output_fstream;

    output_fstream.open(filename, std::ios_base::out);
    if (!output_fstream.is_open()) {
        cerr << "Failed to open " << filename << '\n';
    }
    else {
        output_fstream << nome << endl << Ente::getPontuacao() <<endl;
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

    // ESCRITA 
    if (Ente::getPontuacao() != 0 )//&& input.getString().length() > 1)
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

}*/