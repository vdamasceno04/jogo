#include "construtorestado.h"


ConstrutorEstado::ConstrutorEstado() {

}

ConstrutorEstado::~ConstrutorEstado() {

}

Estado* ConstrutorEstado::criarEstadoJogar(const ID ID) {
    Fases::Fase* fase = nullptr;
    ConstrutorFase construtorFase;

    fase = construtorFase.criarFase(ID);

    EstadoJogar* estadoJogar = new EstadoJogar(ID, fase);
    if (estadoJogar == nullptr) {
        std::cout << "Jungle::Estado::MaquinaEstado::nao foi possivel criar um Estado Jogar" << std::endl;
        exit(1);
    }
    return static_cast<Estado*>(estadoJogar);
}

Estado* ConstrutorEstado::criarEstado(const ID ID) {
    if (ID == jogarfase1 || ID == jogarfase2) {
        return criarEstadoJogar(ID);
    }
    else {
        //criar outros estados...
        //terminar...
    }
    return nullptr;
}
