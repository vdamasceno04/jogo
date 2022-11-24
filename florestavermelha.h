#include"fase.h"

class FlorestaVermelha : public Fase {

public:
	FlorestaVermelha(Managers::Graphics* pG);
	~FlorestaVermelha();
	void criacaracol();
	void criapedra();
	void inicializar();
	void executar();
	void colidir();
};