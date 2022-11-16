#include "inimigo.h"

class Javali : public Inimigo {
private:
public:
	Javali(sf::Vector2f pos, Jogador* p1, Jogador* p2, int vida, int dano, int visao, ID i = ID::javali);
	~Javali();
	void executar();
};