#include "Elemento.h"

template <class TE>
CaveiraDeCristal::Listas::Elemento<TE>::Elemento(TE* apontado) :
	objetoApontado(apontado),
	proximo(nullptr)
{}

template <class TE>
CaveiraDeCristal::Listas::Elemento<TE>::~Elemento()
{
	delete objetoApontado;
}

template <class TE>
void CaveiraDeCristal::Listas::Elemento<TE>::setProximo(Elemento<TE>* seraProximo)
{
	proximo = seraProximo;
}

template <class TE>
const CaveiraDeCristal::Listas::Elemento<TE>* CaveiraDeCristal::Listas::Elemento<TE>::getProximo() const
{
	return proximo;
	//Aqui retorna o objeto da classe elemento que aponta para um objeto
}

template <class TE>
const TE* CaveiraDeCristal::Listas::Elemento<TE>::getApontado() const
{
	return objetoApontado;
}
