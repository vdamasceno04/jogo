#include"jogador.h"

class Explorador : public Jogador {
private:
public:
	Explorador();
	~Explorador();
	void move();
	void executar();
};