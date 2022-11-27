#include<stack>
#include"graphics.h"
#include"construtorestado.h"

class GerenciadorEstado {
private:
    std::stack<Estado*> pilhaEstados;
    ConstrutorEstado construtorEstado;

    //padrão de projeto singleton
    static GerenciadorEstado* pGerenciadorEstado;
    GerenciadorEstado();
public:
    ~GerenciadorEstado();
    static GerenciadorEstado* getGerenciadorEstado();
    void executar();
    void addEstado(const ID ID);
    void removerEstado();
    Estado* getEstadoAtual();
};
