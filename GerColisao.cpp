#include "GerColisao.h"


CaveiraDeCristal::Gerenciadores::GerColisao::GerColisao(Listas::ListaEntidade* listaPersonagens, Listas::ListaEntidade* listaPlataformas) :
	listaPersonagens(listaPersonagens),
	listaPlataformas(listaPlataformas)
{

}

CaveiraDeCristal::Gerenciadores::GerColisao::~GerColisao()
{
	if(listaPersonagens)
	{
		delete listaPersonagens;
		listaPersonagens = nullptr;
	}
	if(listaPlataformas)
	{
		delete listaPlataformas;
		listaPlataformas = nullptr;
	}
}

const CaveiraDeCristal::Gerenciadores::GerColisao::ResultadoColisao CaveiraDeCristal::Gerenciadores::GerColisao::testaSobreposicao(Entidades::Entidade* objA, Entidades::Entidade* objB)
{
	ResultadoColisao colisao;
	colisao.colidiu = false;

	//para verificar a sobreposicao, deve-se encontrar a distancia entre os centros dos objetos, em x e y

	colisao.sobreposicao.x = fabs(objA->getPosicao().x - objB->getPosicao().x);
	//aqui obtida a distancia entre os centros dos objetos em x

	colisao.sobreposicao.x -= (objA->getTamanho().x + objB->getTamanho().x) / 2;
	//a distancia é reduzida pelo tamanho dos objetos, se estiverem sobrepostos, sera negativo

	colisao.sobreposicao.y = fabs(objA->getPosicao().y - objB->getPosicao().y);
	//mesma coisa para y
	colisao.sobreposicao.y -= (objA->getTamanho().y + objB->getTamanho().y) / 2;

	if (colisao.sobreposicao.x < 0.0f && colisao.sobreposicao.y < 0.0f)
		colisao.colidiu = true;

	return colisao;
}

void CaveiraDeCristal::Gerenciadores::GerColisao::executar()
{ 
	int i, j;

	//funcao similar ao codigo do ex-monitor Giovane Limas Salvi

	// Aqui se verifica a colisao entre dois personagens

	for (i = 0; i < listaPersonagens->getTam() - 1; i++)
	{
		Entidades::Entidade* ent1 = listaPersonagens->operator[](i);
		for (j = i + 1; j < listaPersonagens->getTam(); j++)
		{
			Entidades::Entidade* ent2 = listaPersonagens->operator[](j);
			ResultadoColisao colisao = testaSobreposicao(ent1, ent2);
			if(colisao.colidiu)
			{
				ent1->colisao(ent2, colisao.sobreposicao);
			}
		}
	}

	i = 0;
	j = 0;

	//Nesse loop se verifica a colisao entre personagens e plataformas/obstaculos

	for(i = 0; i< listaPersonagens->getTam(); i++)
	{
		Entidades::Entidade* ent1 = listaPersonagens->operator[](i);
		for(j = 0; j < listaPlataformas->getTam(); j++)
		{
			Entidades::Entidade* ent2 = listaPlataformas->operator[](j);;
			ResultadoColisao colisao = testaSobreposicao(ent1, ent2);
			if(colisao.colidiu)
			{
				if (ent2->getID() == IDs::IDs::plataforma)
				{
					ent2->colisao(ent1);
				}
				
				else
				{
					//outro obstaculo
				}
			}
		}
	}
}

