#pragma once
#include "coords.h"
#include <SFML/Graphics.hpp>
#include <map>

namespace Managers {
	
	class Graphics {
	protected:
		Graphics(); //padrão de projeto singleton
	private:
		sf::RenderWindow* window;
		sf::View view;
		std::map<const char*, sf::Texture*> mapaTextura;
		sf::Font* font;
		sf::Clock clock;
		static float dt;
<<<<<<< Updated upstream
		static Managers::Graphics* instance;
		Graphics();
=======
		static Managers::Graphics* instance; //padrão de projeto singleton

>>>>>>> Stashed changes
	public:
		~Graphics();
		static Graphics* getInstance();
		void render(sf::RectangleShape* body);
		void render(sf::Text* text);
		void display();
		void clear();
		bool isWindowOpen() const;
		void closeWindow();
<<<<<<< Updated upstream
		void handleWindowResize();
		sf::Vector2u getWindowSize() const;
		void centerView(Math::CoordF pos);
		sf::Texture* loadTexture(const char* path);
		sf::Font* getFont();
		void updateDeltaTime();


=======
		void setWindowSize(Math::CoordU size);
		Math::CoordU getWindowSize() const;
		void centerView(Math::CoordF pos);
		sf::Texture* loadTexture(const char* path);
		sf::Font* getFont();
		void updateTime();
>>>>>>> Stashed changes
	};
}