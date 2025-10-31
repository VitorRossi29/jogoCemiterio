#include "ListaEntidade.h"


void CaveiraDeCristal::Listas::ListaEntidade::executar(sf::RenderWindow* window)
{
	int tamanho = objListaEntidade.getTam();
	CaveiraDeCristal::Entidades::Entidade* aux = nullptr;
	int i;
	for(i = 0; i < this->getTam(); i++)
	{
		aux = objListaEntidade.operator[](i);
		aux->atualizar();
		window->draw(aux->getCorpo());
	}
}