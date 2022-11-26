#include "Menu.h"

#define HEIGHT 720
#define WIDTH 1280

Menu::Menu() :
	Ente()
{
	setValores();
}

Menu::~Menu()
{
	opcao.clear();
	coordenadas.clear();
	textos.clear();
	tamanhos.clear();
}

void Menu::setValores()
{
	pos = 0;
	selecionado = pressionado = false;
	fonte.loadFromFile("C:/Users/Usuario/Desktop/OmegaCringe/Assets/MainFont.ttf");
}

int Menu::getAtivo() { return ativo; }

void Menu::setAtivo(bool at) { ativo = at; }