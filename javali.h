#include "inimigo.h"

class Javali : public Inimigo {
private:
	int idade;
public:
	Javali(sf::Vector2f pos, Jogador* p1, Jogador* p2, int idade);
	~Javali();
	void inicializa(int idade);
	void executar();
	void colidir(Entidade* pEnt, ID id);
};