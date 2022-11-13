#pragma once
#include"ente.h"
#define HEIGHT 720
#define WIDTH 1080
namespace Entidades{

	class Entidade: public Ente{
	protected:
		sf::Texture textura;
		sf::Sprite sprite;
		sf::RectangleShape body;
		sf::RenderWindow* window;
		sf::Vector2f position;
		sf::Vector2f size;
		sf::Vector2f velocidade;

	public:
		Entidade(sf::Vector2f pos, sf::Vector2f tam);
		~Entidade();
		void setPosition(sf::Vector2f pos);
		sf::Vector2f getPosition() const;
		void setSize(sf::Vector2f siz);
		sf::Vector2f getSize() const;
		void setVelocidade(sf::Vector2f vel);
		sf::Vector2f getVelocidade();
		void setWindow(sf::RenderWindow* window);
		sf::RectangleShape getBody();
		virtual void executar() = 0;
	};
}