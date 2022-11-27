#include "construtorfase.h"


ConstrutorFase::ConstrutorFase() {

}

ConstrutorFase::~ConstrutorFase() {

}

Fases::Fase* ConstrutorFase::criarFlorestaVerde() {
Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::FlorestaVerde(Managers::Graphics::getInstance(), Managers::GerenciadorColisoes::getInstancia(&fase->listaMov, &fase->listaMov)));
if (fase == nullptr) {
    std::cout << "ConstrutorFase::nao foi possivel criar Fase Floresta vERDE" << std::endl;
    exit(1);
}
return fase;
}

Fases::Fase* ConstrutorFase::criarFlorestaVermelha() {
Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::FlorestaVermelha(Managers::Graphics::getInstance(), Managers::GerenciadorColisoes::getInstancia(&fase->listaMov, &fase->listaMov)));
if (fase == nullptr) {
    std::cout << "ConstrutorFase::nao foi possivel criar Fase Floresta Vermelha" << std::endl;
    exit(1);
}
return fase;
}

Fases::Fase* ConstrutorFase::criarFase(const ID ID) {
Fases::Fase* fase = nullptr;
switch (ID)
{
case (jogarfase1): {
    fase = criarFlorestaVerde();
}
break;
case (jogarfase2):
{
    fase = criarFlorestaVermelha();
}
break;
default:
{
    std::cout << "Jungle::Construtor::ConstrutorFase::ID da Fase invalido" << std::endl;
    exit(1);
}
break;
}
fase->criafundo(true);
return fase;
}
