#include "Lista.h"

template <typename TL>
	CaveiraDeCristal::Listas::Lista<TL>::Lista() :
	primeiro(nullptr),
	ultimo(nullptr),
	tamanho(0)
{
}

template <typename TL>
CaveiraDeCristal::Listas::Lista<TL>::~Lista()
{
	Elemento<TL>* atual = primeiro;
	Elemento<TL>* proximo = nullptr;
	while (atual != nullptr)
	{
		proximo = atual->getProximo();
		delete atual;
		atual = proximo;
	}
}

template <typename TL>
void CaveiraDeCristal::Listas::Lista<TL>::adicionarNoFim(TL novoElemento)
{
	Elemento<TL>* elemento = new Elemento<TL>(novoElemento);
	if (tamanho == 0)
	{
		primeiro = elemento;
		ultimo = elemento;
	}
	else
	{
		ultimo->setProximo(elemento);
		ultimo = elemento;
	}
	tamanho++;
}

template <typename TL>
void CaveiraDeCristal::Listas::Lista<TL>::removerElemento(TL removido)
{
	if (primeiro == nullptr)
		return;

	Elemento<TL>* seraRemovido = primeiro;

	if (primeiro->getApontado() == removido)
	{
		primeiro = seraRemovido->getProximo();

		if (primeiro == nullptr)
			ultimo = nullptr;
	}
	else
	{
		while (seraRemovido->getProximo() != nullptr && seraRemovido->getProximo()->getApontado() != removido)
		{
			seraRemovido = seraRemovido->getProximo();
		}

		if (seraRemovido->getProximo() == nullptr)
			return;

		Elemento<TL>* antesDoRemovido = seraRemovido;

		seraRemovido = seraRemovido->getProximo();

		antesDoRemovido->setProximo(seraRemovido->getProximo());

		if (seraRemovido == ultimo)
			ultimo = antesDoRemovido;
	}

	if (seraRemovido->getApontado() != nullptr)
		delete seraRemovido->getApontado();
	seraRemovido->setProximo(nullptr);
	delete seraRemovido;

	tamanho--;
}

template <typename TL>
void CaveiraDeCristal::Listas::Lista<TL>::removerElemento(int posicao)
{
	if (primeiro == nullptr || posicao < 0 || posicao >= tamanho)
		return;

	Elemento<TL>* seraRemovido = primeiro;

	if (posicao == 0)
	{
		primeiro = seraRemovido->getProximo();

		if (primeiro == nullptr)
			ultimo = nullptr;
	}
	else
	{
		int i = 0;

		Elemento<TL>* antesDoRemovido = nullptr;
		for (int i = 0; i < posicao; i++)
		{
			antesDoRemovido = seraRemovido;
			seraRemovido = seraRemovido->getProximo();
		}


		antesDoRemovido->setProximo(seraRemovido->getProximo());

		if (seraRemovido == ultimo)
			ultimo = antesDoRemovido;
	}

	if (seraRemovido->getApontado() != nullptr)
		delete seraRemovido->getApontado();
	seraRemovido->setProximo(nullptr);
	delete seraRemovido;

	tamanho--;
}

template <typename TL>
const int CaveiraDeCristal::Listas::Lista<TL>::getTam() const
{
	return tamanho;
}

template <typename TL>
TL* CaveiraDeCristal::Listas::Lista<TL>::operator[](int posicao)
{
	int i;

	Elemento<TL>* elemento = primeiro;

	for (i = 0; i < posicao; i++)
	{
		elemento = elemento->getProximo();
	}

	if (elemento != nullptr)
	{
		return elemento;
	}
}