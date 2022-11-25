#include"fase.h"

class FlorestaVermelha : public Fase {

public:
	FlorestaVermelha(Managers::Graphics* pG);
	~FlorestaVermelha();
	void criacaracol();
	void criaespinho();
	void inicializar();
	void executar();
	void colidir();
};