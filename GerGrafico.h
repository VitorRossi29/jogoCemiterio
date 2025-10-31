#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

namespace CaveiraDeCristal
{
	namespace Gerenciadores
	{
		class GerGrafico
		{
		private:
			sf::RenderWindow* window;

			// padrão singleton
			static GerGrafico* pGrafico;
			GerGrafico();
		public:
			~GerGrafico();
			static GerGrafico* getGerGrafico();
			sf::RenderWindow* getWindow();
			void limpaJanela();
			void desenhaElemento(const sf::RectangleShape& corpo);
			void mostraElementos();
			void fecharJanela();
			bool verificaAbertura() const;
		};
	}
}

