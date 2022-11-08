#pragma once
#include <SFML/Graphics.hpp>
#include "coords.h"

namespace Entidades {

	class Entidade {
	protected:
		sf::RectangleShape body;
		sf::RenderWindow* window;
		Math::CoordF position;
		Math::CoordF size;
		Math::CoordF velocidade;

	public:
		Entidade(Math::CoordF pos = Math::CoordF(0.f, 0.f), Math::CoordF tam = Math::CoordF(0.f, 0.f));
		~Entidade();
		void setPosition(Math::CoordF pos);
		Math::CoordF getPosition() const;
		void setSize(Math::CoordF siz);
		Math::CoordF getSize() const;
		void setVelocidade(Math::CoordF vel);
		Math::CoordF getVelocidade();
		void setWindow(sf::RenderWindow* window);
		sf::RectangleShape getBody();
		void draw();
		virtual void executar() = 0;
	};
}