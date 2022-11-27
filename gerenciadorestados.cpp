#include "gerenciadorestados.h"


    GerenciadorEstado* GerenciadorEstado::pGerenciadorEstado = nullptr;

    GerenciadorEstado::GerenciadorEstado() :
        pilhaEstados()
    {

    }

    GerenciadorEstado* GerenciadorEstado::getGerenciadorEstado() {
        if (pGerenciadorEstado == nullptr) {
            pGerenciadorEstado = new GerenciadorEstado();
        }
        return pGerenciadorEstado;
    }

    GerenciadorEstado::~GerenciadorEstado() {
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
    Ente* GerenciadorEstado::criaestado(const ID id) {
        if (id == 15)
            return static_cast<Ente*>(new MenuPrincipal);
        else if (id == 16)
            return static_cast<Ente*>(new MenuLeaderboard);
        else if (id == 17)
            return static_cast<Ente*>(new MenuEscolha);
        else if (id == 12) {
            Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::FlorestaVerde(Managers::Graphics::getInstance(), Managers::GerenciadorColisoes::getInstancia(&fase->listaMov, &fase->listaMov)));
            return static_cast<Ente*>(fase);
        }
        else if (id == 13) {
            Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::FlorestaVermelha(Managers::Graphics::getInstance(), Managers::GerenciadorColisoes::getInstancia(&fase->listaMov, &fase->listaMov)));
            return static_cast<Ente*>(fase);
        }
    }

    void GerenciadorEstado::addEstado(const ID ID) {
        Ente* ente =criaestado(ID);
        if (ente == nullptr) {
            std::cout << " nullptr" << std::endl;
            exit(1);
        }
        pilhaEstados.push(ente);
    }

    void GerenciadorEstado::removerEstado() {
        if (pilhaEstados.top() != nullptr) {
            delete(pilhaEstados.top());
            pilhaEstados.top() = nullptr;
            pilhaEstados.pop();
        }
        
        if (pilhaEstados.empty()) {
            Managers::Graphics* pGrafico = pGrafico->getInstance();
            pGrafico->closeWindow();
        }
    }

    Ente* GerenciadorEstado::getEstadoAtual() {
        return pilhaEstados.top();
    }


    void GerenciadorEstado::executar() {
        //executa o estado que está no topo da minha pilha
        if (!pilhaEstados.empty()) {
            pilhaEstados.top()->executar();
        }
    }

   

