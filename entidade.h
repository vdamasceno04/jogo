#pragma once
#include"ente.h"
#define HEIGHT 720
#define WIDTH 1080
#define GRAVIDADE 2.9

namespace Entidades {

	class Entidade : public Ente {
	protected:
		sf::Texture textura;
		sf::Sprite sprite;
		sf::RectangleShape body;
		sf::RenderWindow* janela;
		sf::Vector2f posicao;
		sf::Vector2f tamanho;
		sf::Vector2f velocidade;
		sf::Vector2f vmax;
		bool remove;
		int vida;
		int dano;

	public:
		Entidade(sf::Vector2f pos);
		~Entidade();

		void setPosicao(sf::Vector2f pos);
		sf::Vector2f getPosicao() const;

		void setVelocidade(sf::Vector2f vel);
		sf::Vector2f getVelocidade();

		void setTamanho(sf::Vector2f tam);
		sf::Vector2f getTamanho() const;
		void setEscala(sf::Vector2f escala);

		void setJanela(sf::RenderWindow* janela);

		sf::RectangleShape getBody();
		void setSprite(const char* local);

		void renderizar();
		void atualizar();

		void tomaDano(int ferimento);
		int getDano();

		bool getRemove();
		void setRemove(bool rem);

		void resolverColisao(Entidade* pEnt, float intersec_x, float intersec_y);
		
		virtual void colidir(Entidade* pEnt, float intersec_x, float intersec_y) {};
		virtual void efeito(Entidade* p) {};
		virtual void executar() = 0;

	};
}