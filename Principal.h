#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "GerGrafico.h"
#include "GerEventos.h"
#include "ListaEntidade.h"
#include <vector>

namespace CaveiraDeCristal
{ 
	class Principal
	{
	private:
		Gerenciadores::GerGrafico* pGrafico;
		Gerenciadores::GerEventos* pEvento;
		Listas::ListaEntidade listaEntidades;
	public:
		Principal();
		~Principal();
		void executar();
		void instanciaEntidades();
	};
}



