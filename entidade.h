#pragma once
#include <SFML/Graphics.hpp>
#include "coords.h"

namespace Entities {
	enum ID {
		empty = 0, player, platform
	};

	class Entidade {
	protected:
		sf::RectangleShape body;
		sf::RenderWindow* window;

	private:
		Math::CoordF position;
		Math::CoordF size;
		ID id;

	public:
		Entidade(Math::CoordF pos = Math::CoordF(0.f, 0.f), Math::CoordF s = Math::CoordF(0.f, 0.f), ID i = empty);
		~Entidade();

		void setPosition(Math::CoordF pos);
		Math::CoordF getPosition() const;
		Math::CoordF getSize() const;
		ID getId() const;
//		virtual void render();
//		virtual void update(float dt) = 0;
//		virtual void initialize() = 0;
		void setWindow(sf::RenderWindow* window);
		void draw();

	};
}