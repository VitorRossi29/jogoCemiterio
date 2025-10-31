#pragma once

#include "Elemento.hpp"

namespace CaveiraDeCristal
{
	namespace Listas
	{ 
		template<class TL>
		class Lista
		{
		private:
			Elemento<TL>* pPrimeiro;
			Elemento<TL>* pUltimo;
			unsigned int tamanho;
		public:
			Lista();
			~Lista();
			void addElemento(TL* novoElemento);
			void removerElemento(TL* elemento);
			void removerElemento(int posicao);
			const int getTam() const;
			TL* operator[](int posicao);
		};

		template <class TL>
		Lista<TL>::Lista() :
			pPrimeiro(nullptr),
			pUltimo(nullptr),
			tamanho(0)
		{
		}
	}
}


