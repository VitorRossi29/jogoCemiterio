#include "Lista.h"

template <typename TL>
	CaveiraDeCristal::Listas::Lista<TL>::Lista() :
	pPrimeiro(nullptr),
	pUltimo(nullptr),
	tamanho(0)
{
}

template <typename TL>
CaveiraDeCristal::Listas::Lista<TL>::~Lista()
{
	Elemento<TL>* atual = pPrimeiro;
	Elemento<TL>* proximo = nullptr;
	while (atual != nullptr)
	{
		proximo = atual->getProximo();
		delete atual;
		atual = proximo;
	}
}

template <typename TL>
void CaveiraDeCristal::Listas::Lista<TL>::addElemento(TL* novoElemento)
{
	Elemento<TL>* elemento = new Elemento<TL>();
	elemento->setElemento(novoElemento);
	if (tamanho == 0)
	{
		pPrimeiro = elemento;
		pUltimo = elemento;
	}
	else
	{
		pUltimo->setProximo(elemento);
		pUltimo = elemento;
	}
	tamanho++;
}