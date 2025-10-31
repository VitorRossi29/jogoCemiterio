#pragma once

namespace CaveiraDeCristal
{
	namespace Listas
	{
		template <class TE>
		class Elemento
		{
		private:
			Elemento<TE>* pProximo;
			TE* elemento;
		public:
			Elemento();
			~Elemento();
			void setProximo(Elemento<TE>* proximo);
			Elemento<TE>* getProximo() const;
			void setElemento(TE* novoElemento);
			TE* getElemento() const;
		};

		template <class TE>
		Elemento<TE>::Elemento() :
			pProximo(nullptr),
			elemento(nullptr)
		{}
	}
}

