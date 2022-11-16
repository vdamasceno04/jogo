#include"jogador.h"

class Explorador : public Jogador {
private:
public:
	Explorador(sf::Vector2f pos = sf::Vector2f(0, HEIGHT * 0.635));
	~Explorador();
	void move();
	void executar();
};