#pragma once

#include <SFML/Graphics.hpp>
#include<cmath>
#include "ListaEntidade.h"

namespace CaveiraDeCristal
{
	namespace Gerenciadores
	{
		class GerColisao
		{
		private:
			Listas::ListaEntidade* listaPersonagens;
			Listas::ListaEntidade* listaPlataformas;
		public:

			struct ResultadoColisao {
				bool colidiu = false;
				sf::Vector2f sobreposicao = { 0.f, 0.f };
			};

			GerColisao(Listas::ListaEntidade* listaPersonagens, Listas::ListaEntidade* listaPlataformas);
			~GerColisao();
			const ResultadoColisao testaSobreposicao(Entidades::Entidade* objA, Entidades::Entidade* objB);
			void executar();
		};
	}
}

