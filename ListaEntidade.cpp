#include "ListaEntidade.h"


CaveiraDeCristal::Listas::ListaEntidade::ListaEntidade() :
	listaParametrizada()
{}

CaveiraDeCristal::Listas::ListaEntidade::~ListaEntidade()
{}


void CaveiraDeCristal::Listas::ListaEntidade::addEntidade(CaveiraDeCristal::Entidades::Entidade* entidade)
{
	listaParametrizada.adicionarNoFim(entidade);
}

void CaveiraDeCristal::Listas::ListaEntidade::removerEntidade(CaveiraDeCristal::Entidades::Entidade* entidade)
{
	listaParametrizada.removerElemento(entidade);
}
void CaveiraDeCristal::Listas::ListaEntidade::removerEntidade(int posicao)
{
	listaParametrizada.removerElemento(posicao);
}

CaveiraDeCristal::Entidades::Entidade* CaveiraDeCristal::Listas::ListaEntidade::operator[](int indice)
{
	return listaParametrizada.operator[](indice);
}

const int CaveiraDeCristal::Listas::ListaEntidade::getTam() const
{
	return listaParametrizada.getTam();
}

void CaveiraDeCristal::Listas::ListaEntidade::executar(CaveiraDeCristal::Gerenciadores::GerGrafico* grafico)
{
	int tamanho = listaParametrizada.getTam();
	CaveiraDeCristal::Entidades::Entidade* navegador = nullptr;
	
	int i;
	for(i = 0; i < tamanho; i++)
	{
		navegador = listaParametrizada.operator[](i);
		navegador->executar();
		grafico->desenhaElemento(navegador->getCorpo());
	}
}