#include "inimigo.h"

class Abelha : public Inimigo {
private:

public:
	Abelha(sf::Vector2f pos = sf::Vector2f(250, HEIGHT * 0.65), sf::Vector2f tam = sf::Vector2f(22, 42),
		int v = 6, int d = 1, float dC = 1.1, float dA = 0.2, float vR = 200.2, Jogador* pJ = NULL, Jogador* pJ2 =NULL);
	~Abelha();
	void executar();
};