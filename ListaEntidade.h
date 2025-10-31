#pragma once

#include "Lista.h"

namespace CaveiraDeCristal
{
	namespace Listas
	{
		class ListaEntidade
		{
		private:
			Lista<CaveiraDeCristal::Entidades::Entidade*> objListaEntidade;
		public:
			ListaEntidade();
			~ListaEntidade();
			void addEntidade(CaveiraDeCristal::Entidades::Entidade* entidade);
			void removerEntidade(CaveiraDeCristal::Entidades::Entidade* entidade);
			void removerEntidade(int posicao);
			CaveiraDeCristal::Entidades::Entidade* operator[](int indice);
			const int getTam() const;
			void executar(sf::RenderWindow* window);
		};
	}
}

