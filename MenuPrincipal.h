#pragma once
#include "Menu.h"
#include "MenuEscolha.h"
#include "MenuLeaderboard.h"
#include<map>
#include<fstream>
#define CAMINHO "./deesAssets/ranking.txt"

namespace Menus {
	class MenuPrincipal : public Menu
	{
	private:


	public:
		MenuPrincipal();
		~MenuPrincipal();

		void setValores();
		void desenhar();
		void loop();
		void insereNome();
		void executar();

	};

}