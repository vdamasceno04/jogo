#pragma once

#include "ente.h"



class Estado : public Ente {
private:
    bool remover;
public:
    Estado(const ID ID);
    ~Estado();
    virtual void executar() = 0;
    virtual void desenhar();
    void setRemover(const bool remover = true);
    const bool getRemover() const;
};

