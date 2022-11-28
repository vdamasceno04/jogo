#pragma once
#include "Menu.h"

namespace Menus {
	class MenuEscolha : public Menu
	{
	private:

	public:
		MenuEscolha();
		~MenuEscolha();

		void setValores();


		void desenhar();
		void loop();
		void executar();

	};
}
