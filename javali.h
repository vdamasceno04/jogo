#include "inimigo.h"

class Javali : public Inimigo {
private:
	int idade;
public:
	Javali(Math::CoordF pos, Jogador* p1, Jogador* p2, int idade);
	~Javali();
	void inicializa(int idade);
	void executar();
	void ataca(Jogador* pJ);
};