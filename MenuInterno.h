#pragma once
#include "Menu.h"

class MenuInterno :
    public Menu
{
private:
    bool parar;
    bool sair;

public:
    MenuInterno();
    ~MenuInterno();

    void setValores();

    bool getParar();
    bool getSair();

    void desenhar();
    void loop();
    void executar();

};

