#include "jogo.h"
#include<stdio.h>

Jogo::Jogo():
pGG(Graphics::getInstance()) 
{
    executar();
}

Jogo::~Jogo() {}

void Jogo::inicializar() {}

void Jogo::executar()
{
    printf("a");
}
