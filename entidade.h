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
		void setTamanho(sf::Vector2f tam);
		sf::Vector2f getTamanho() const;
		void setJanela(sf::RenderWindow* janela);
		sf::RectangleShape getBody();
		void setEscala(sf::Vector2f escala);
		void setSprite(const char* local);
		void renderizar();
		virtual void executar() = 0;
		int getDano();
		void resolverColisao(Entidade* pEnt, float intersec_x, float intersec_y);
		bool getRemove();
		void setRemove(bool rem);
		virtual void efeito(Entidade* p) {};
		void setVelocidade(sf::Vector2f vel);
		sf::Vector2f getVelocidade();
		void tomaDano(int ferimento);
		void atualizar();
		virtual void colidir(Entidade* pEnt, float intersec_x, float intersec_y) {};

	};
}