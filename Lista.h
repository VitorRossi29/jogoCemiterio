#pragma once

#include "Elemento.h"

namespace CaveiraDeCristal
{
	namespace Listas
	{ 
		template<class TL>
		class Lista
		{
		private:
			Elemento<TL>* primeiro;
			Elemento<TL>* ultimo;
			unsigned int tamanho;
		public:
			Lista();
			~Lista();
			void adicionarNoFim(TL novoElemento);
			void removerElemento(TL removido);
			void removerElemento(int posicao);
			const int getTam() const;
			TL operator[](int posicao);
		};
	}
}


