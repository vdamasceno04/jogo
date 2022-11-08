#pragma once
#include <iostream>
#include"Elemento.h"

template <class TE>  class Lista
{
private:
	Elemento<TE>* pPrimeiro;
	Elemento<TE>* pUltimo;
	int len;
public:
	Lista();
	~Lista();
	int getLen() { return len; }

	TE* getItem(int posicao) {
		Elemento<TE>* temp = pPrimeiro;
		if (posicao == 0)
			return temp->getItem();
		for (int i = 0; i < posicao; i++)
			temp = temp->getpProx();
		return temp->getItem();
	}

	void push(TE* item) {
		if (pPrimeiro == nullptr) {
			pPrimeiro = new Elemento<TE>;
			pPrimeiro->setItem(item);
			pUltimo = pPrimeiro;
		}
		else {
			Elemento<TE>* temp = new Elemento<TE>;
			temp->setItem(item);
			pUltimo->setpProx(temp);
			pUltimo = temp;
		}
		len++;
	}

	void pop(TE* item) {
		Elemento<TE>* temp = pPrimeiro;
		Elemento<TE>* tempAnt = nullptr;
		while (temp->getItem() != item) {
			tempAnt = temp;
			temp = temp->getpProx();
		}
		if (temp == pPrimeiro) {
			pPrimeiro = temp->getpProx();
		}
		else if (temp == pUltimo) {
			tempAnt->setpProx(nullptr);
			pUltimo = tempAnt;
		}
		else {
			tempAnt->setpProx(temp->getpProx());
		}
		delete temp;
		len--;
	}
};

template<class TE>
inline Lista<TE>::Lista() {
	pPrimeiro = NULL;
	pUltimo = NULL;
	len = 0;
}

template<class TE>
inline Lista<TE>::~Lista() {
	pPrimeiro = NULL;
	pUltimo = NULL;
	len = 0;
}