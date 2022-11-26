#pragma once

namespace Listas {
	template <class TE> class Elemento {
	private:
		Elemento<TE>* pProx;
		TE* item;
	public:
		Elemento();
		~Elemento() {}
		void setpProx(Elemento<TE>* pProx) { this->pProx = pProx; }
		void setItem(TE* item) { this->item = item; }
		Elemento<TE>* getpProx() { return pProx; }
		TE* getItem() { return item; }

	};

	template<class TE>
	inline Elemento<TE>::Elemento() {
		pProx = nullptr;
		item = nullptr;
	}
}