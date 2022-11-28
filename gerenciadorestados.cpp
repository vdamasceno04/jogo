#include "gerenciadorestados.h"


    Gerenciadores::GerenciadorEstado* Gerenciadores::GerenciadorEstado::pGerenciadorEstado = nullptr;

    Gerenciadores::GerenciadorEstado::GerenciadorEstado() :
        pilhaEstados()
    {

    }

    Gerenciadores::GerenciadorEstado* Gerenciadores::GerenciadorEstado::getGerenciadorEstado() {
        if (pGerenciadorEstado == nullptr) {
            pGerenciadorEstado = new GerenciadorEstado();
        }
        return pGerenciadorEstado;
    }

    Gerenciadores::GerenciadorEstado::~GerenciadorEstado() {
        //deleta todos os estados da minha pilha
        while (!pilhaEstados.empty()) {
            delete(pilhaEstados.top());
            pilhaEstados.top() = nullptr;
            pilhaEstados.pop();
        }

        if (pGerenciadorEstado) {
            delete(pGerenciadorEstado);
            pGerenciadorEstado = nullptr;
        }
    }
    Ente* Gerenciadores::GerenciadorEstado::criaestado(const ID id) {
        if (id == 15)
            return static_cast<Ente*>(new MenuPrincipal);
        else if (id == 16)
            return static_cast<Ente*>(new MenuLeaderboard);
        else if (id == 17)
            return static_cast<Ente*>(new MenuEscolha);

        else if (id == 12) {
            Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::FlorestaVerde(false, Gerenciadores::Graphics::getInstance(), Gerenciadores::GerenciadorColisoes::getInstancia(&fase->listaMov, &fase->listaMov)));
            return static_cast<Ente*>(fase);
        }
        else if (id == 13) {
            Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::FlorestaVermelha(false, Gerenciadores::Graphics::getInstance(), Gerenciadores::GerenciadorColisoes::getInstancia(&fase->listaMov, &fase->listaMov)));
            return static_cast<Ente*>(fase);
        }
        else if (id == 22) {
            Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::FlorestaVerde(true, Gerenciadores::Graphics::getInstance(), Gerenciadores::GerenciadorColisoes::getInstancia(&fase->listaMov, &fase->listaMov)));
            return static_cast<Ente*>(fase);
        }
        else if (id == 23) {
            Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::FlorestaVermelha(true, Gerenciadores::Graphics::getInstance(), Gerenciadores::GerenciadorColisoes::getInstancia(&fase->listaMov, &fase->listaMov)));
            return static_cast<Ente*>(fase);
        }
    }

    void Gerenciadores::GerenciadorEstado::addEstado(const ID ID) {
        Ente* ente =criaestado(ID);
        if (ente == nullptr) {
            std::cout << " nullptr" << std::endl;
            exit(1);
        }
        pilhaEstados.push(ente);
    }

    void Gerenciadores::GerenciadorEstado::removerEstado() {
        if (pilhaEstados.top() != nullptr) {
            delete(pilhaEstados.top());
            pilhaEstados.top() = nullptr;
            pilhaEstados.pop();
        }
        
        else if (pilhaEstados.empty()) {
            Gerenciadores::Graphics* pGrafico = pGrafico->getInstance();
            pGrafico->closeWindow();
        }
    }

    Ente* Gerenciadores::GerenciadorEstado::getEstadoAtual() {
        return pilhaEstados.top();
    }

    int Gerenciadores::GerenciadorEstado::tamanhoPilha() {
        return pilhaEstados.size();
    }

    void Gerenciadores::GerenciadorEstado::executar() {
        //executa o estado que está no topo da minha pilha
        if (!pilhaEstados.empty()) {
            pilhaEstados.top()->executar();
            
            if (pilhaEstados.top()->getId() == 15) { //menu principal

                if (pilhaEstados.top()->getEstado() == 0)
                    pilhaEstados.top()->executar();

                else if (pilhaEstados.top()->getEstado() == -1) 
                    removerEstado();
                
                else if (pilhaEstados.top()->getEstado() == 1) {
                    pilhaEstados.top()->setEstado(-2);
                    addEstado(menuescolha);
                }

                else if (pilhaEstados.top()->getEstado() == 2) {
                    pilhaEstados.top()->setEstado(-2);
                    addEstado(leaderboard);
                }
            }

            else if (pilhaEstados.top()->getId() == 16) { //leaderboard

                if (pilhaEstados.top()->getEstado() == 0)
                    pilhaEstados.top()->executar();

                else if (pilhaEstados.top()->getEstado() == -1) {
                    pilhaEstados.top()->setEstado(-2);
                    removerEstado();
                    pilhaEstados.top()->setEstado(0);
                }
            }

            else if (pilhaEstados.top()->getId() == 17) { //menuescolha

                if (pilhaEstados.top()->getEstado() == 0)
                    pilhaEstados.top()->executar();

                else if (pilhaEstados.top()->getEstado() == -1) {
                    pilhaEstados.top()->setEstado(-2);
                    removerEstado();
                    pilhaEstados.top()->setEstado(0);
                }

                else if (pilhaEstados.top()->getEstado() == 1) {
                    pilhaEstados.top()->setEstado(-2);
                    addEstado(fase1);
                }

                else if (pilhaEstados.top()->getEstado() == 2) {
                    pilhaEstados.top()->setEstado(-2);
                    addEstado(fase12jog);
                }

                else if (pilhaEstados.top()->getEstado() == 3) {
                    pilhaEstados.top()->setEstado(-2);
                    addEstado(fase2);
                }

                else if (pilhaEstados.top()->getEstado() == 4) {
                    pilhaEstados.top()->setEstado(-2);
                    addEstado(fase22jog);
                }
            }

            else if (pilhaEstados.top()->getId() == 12 || pilhaEstados.top()->getId() == 13 || pilhaEstados.top()->getId() == 22 || pilhaEstados.top()->getId() == 23) {
                if (pilhaEstados.top()->getEstado() == 0)
                    pilhaEstados.top()->executar();

                else if (pilhaEstados.top()->getEstado() == -1) {
                    pilhaEstados.top()->setEstado(-2);
                    removerEstado();
                    pilhaEstados.top()->setEstado(0);
                }
            }
        }
        cout << "estado: " << pilhaEstados.top()->getId() << endl;
    }

   

