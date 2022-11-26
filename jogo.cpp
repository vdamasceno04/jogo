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
    fase1(Graphics::getInstance()),
    fase2(Graphics::getInstance()),
    menuPrincipal()

{
    Ente::setpGG(Graphics::getInstance());
    executar();
}

Jogo::~Jogo() {
    Managers::Graphics::apagarInstance();
}

void Jogo::inicializar() {
//    fase1.inicializar();
    //fase2.inicializar();
    menuPrincipal.setValores();


/*
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

    /* ================================= ESCRITA ================================= 

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

}
*/

void Jogo::executar() {
    inicializar();
    sf::Event event;
    while (pGG->isWindowOpen())
    {
        while (pGG->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGG->closeWindow();

            //Executar Menus
            if (menuPrincipal.getAtivo() || menuPrincipal.getEscolhaAtivo() || menuPrincipal.getLeaderboardAtivo())
            {
                pGG->centerView(sf::Vector2f(640.f, 360.f));
                pGG->clear();
                menuPrincipal.executar();
                if (!flagFase)
                    flagFase = true;

                pGG->display();
            }
        }

        //Executar Fase
        if (!menuPrincipal.getAtivo() && !menuPrincipal.getEscolhaAtivo() && !menuPrincipal.getLeaderboardAtivo())
        {
            int auxE = menuPrincipal.getEscolheu();
            pGG->clear();
            //Fase 1 com um jogador
            if (auxE == 1)
            {
                if (flagFase) {
                    printf("entrou em 1\n");
                    fase1.inicializar();
                    fase1.set2jogadores(false);
                    flagFase = false;
                }
                if (fase1.fimFase()) {
                    menuPrincipal.setAtivo(true);
                    
                }
                fase1.executar();
                fase1.colidir();
            }
            //Fase 1 com dois jogadores
            else if (auxE == 2)
            {
                if (flagFase) {
                    printf("entrou em 2\n");
                    fase1.inicializar();
                    fase1.set2jogadores(true);
                    flagFase = false;
                }
                if (fase1.fimFase()) {
                    menuPrincipal.setAtivo(true);
                    //Resetar tela para posi��o 0 e 0
                }
                fase1.executar();
                fase1.colidir();
            }

            //Fase 2 com um jogador
            else if (auxE == 3)
            {                
                if (flagFase) {
                    printf("entrou em 3\n");
                    fase2.inicializar();
                    fase2.set2jogadores(false);
                    flagFase = false;
                }
                if (fase2.fimFase()) {
                    menuPrincipal.setAtivo(true);
                    //Resetar tela para posi��o 0 e 0
                }
                fase2.executar();
                fase2.colidir();
            }
            //Fase 2 com dois jogadores
            else if (auxE == 3)
            {                
                if (flagFase) {
                    printf("entrou em 4\n");
                    fase2.inicializar();
                    fase2.set2jogadores(true);
                    flagFase = false;
                }
                if (fase2.fimFase()) {
                    menuPrincipal.setAtivo(true);
                    //Resetar tela para posi��o 0 e 0
                }
                fase2.executar();
                fase2.colidir();
            }
            else
                menuPrincipal.setAtivo(true);

            pGG->display();

            //Abrir Menu Interno
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                while (!menuJogo.getParar()) {
                    pGG->clear();
                    menuJogo.executar();
                    pGG->display();
                }
                if (menuJogo.getSair())
                    menuPrincipal.setAtivo(true);
            }

        }

    }
}