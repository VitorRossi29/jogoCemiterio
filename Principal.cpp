#include "Principal.h"
#include <iostream>

CaveiraDeCristal::Principal::Principal() :
	personagens(),
	pGrafico(Gerenciadores::GerGrafico::getGerGrafico()),
	pEvento(Gerenciadores::GerEventos::getGerEventos())
{
	if (pGrafico == nullptr)
	{
		std::cout << "Erro para criar gerenciador grafico" << std::endl;
		exit(1);
	}

	if (pEvento == nullptr)
	{
		std::cout << "Erro para criar gerenciador de eventos" << std::endl;
		exit(1);
	}

	instanciaEntidades();

	executar();
}

CaveiraDeCristal::Principal::~Principal() {}

void CaveiraDeCristal::Principal::instanciaEntidades()
{
	CaveiraDeCristal::Entidades::Personagens::Jogador* jogador = new CaveiraDeCristal::Entidades::Personagens::Jogador(sf::Vector2f(200.0f , 200.0f), sf::Vector2f(50.0f, 50.0f), 200.0f);
	CaveiraDeCristal::Entidades::Personagens::Inimigo* inimigo1 = new CaveiraDeCristal::Entidades::Personagens::Inimigo(sf::Vector2f(100.0f, 300.0f), sf::Vector2f(40.0f, 40.0f), jogador, 100.0f);
	CaveiraDeCristal::Entidades::Personagens::Inimigo* inimigo2 = new CaveiraDeCristal::Entidades::Personagens::Inimigo(sf::Vector2f(300.0f, 100.0f), sf::Vector2f(40.0f, 40.0f), jogador, 100.0f);

	CaveiraDeCristal::Entidades::Entidade* entJog = static_cast<CaveiraDeCristal::Entidades::Entidade*> (jogador);
	CaveiraDeCristal::Entidades::Entidade* ent1 = static_cast<CaveiraDeCristal::Entidades::Entidade*> (inimigo1);
	CaveiraDeCristal::Entidades::Entidade* ent2 = static_cast<CaveiraDeCristal::Entidades::Entidade*> (inimigo2);

	listaEntidades.addEntidade(entJog);
	listaEntidades.addEntidade(ent1);
	listaEntidades.addEntidade(ent2);

	pEvento->setjogador(jogador);
}

void CaveiraDeCristal::Principal::executar()
{
	while (pGrafico->verificaAbertura())
	{
		pEvento->executar();
		pGrafico->limpaJanela();
		listaEntidades.executar(pGrafico->getWindow());
		pGrafico->mostraElementos();
	}
}
