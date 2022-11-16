#pragma once
#include "coords.h"
#include "graphics.h"
#include<iostream>
using std::cout;
using std::endl;

class Ente {
protected:
	int id;
	Managers::Graphics* pGG;
public:
	Ente();
	void setpGG(Managers::Graphics* p);
	~Ente();
	virtual void executar() = 0;
};