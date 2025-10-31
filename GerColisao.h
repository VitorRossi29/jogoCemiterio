#pragma once

#include <SFML/Graphics.hpp>
#include<cmath>
#include "ListaEntidades.h"

namespace CaveiraDeCristal
{
	namespace Gerenciadores
	{
		class GerColisao
		{
		private:
			Lista::ListaEntidades* listaPersonagens;
			Lista::ListaEndidades* listaPlataformas;
		public:
			GerColisao(Lista::ListaEntidades* listaPersonagens, Lista::ListaEndidades* listaPlataformas);
			~GerColisao();
			const sf::Vector2f verificarColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2);
			void executar();
		};
	}
}

