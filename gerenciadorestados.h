#include<stack>
#include"graphics.h"
#include"MenuLeaderboard.h"
#include"MenuEscolha.h"
#include"MenuPrincipal.h"
#include"florestaverde.h"
#include"florestavermelha.h"

namespace Gerenciadores {
    class GerenciadorEstado {
    protected:
        GerenciadorEstado();

    private:
        std::stack<Ente*> pilhaEstados;

        //padrão de projeto singleton
        static GerenciadorEstado* pGerenciadorEstado;
    public:
        ~GerenciadorEstado();
        static GerenciadorEstado* getGerenciadorEstado();
        void executar();
        Ente* criaestado(const ID id);
        void addEstado(const ID id);
        void removerEstado();
        Ente* getEstadoAtual();
        int tamanhoPilha();
    };
}
