#include "GerEventos.h"


CaveiraDeCristal::Gerenciadores::GerEventos* CaveiraDeCristal::Gerenciadores::GerEventos::pEvento = nullptr;

CaveiraDeCristal::Gerenciadores::GerEventos::GerEventos() :
	pGrafico(GerGrafico::getGerGrafico()),
	pJogador(nullptr)
{
	if (pGrafico == nullptr)
	{
		std::cout << "Erro para criar gerenciador de eventos" << std::endl;
		exit(1);
	}
}

CaveiraDeCristal::Gerenciadores::GerEventos::~GerEventos() {}

CaveiraDeCristal::Gerenciadores::GerEventos* CaveiraDeCristal::Gerenciadores::GerEventos::getGerEventos()
{
	if (pEvento == nullptr)
	{
		pEvento = new GerEventos();
	}
	return pEvento;
}

void CaveiraDeCristal::Gerenciadores::GerEventos::setjogador(CaveiraDeCristal::Entidades::Personagens::Jogador* pJog)
{
	this->pJogador = pJog;
}

void CaveiraDeCristal::Gerenciadores::GerEventos::verificaTeclaPressionada(sf::Keyboard::Key tecla)
{
	bool esquerda = true;
	//variavel criada para ficar mais claro o paramentro de andar

	if (tecla == sf::Keyboard::A)
	{
		pJogador->andar(esquerda);
	}
	else if (tecla == sf::Keyboard::D)
	{
		pJogador->andar(!esquerda);
	}
	else if(tecla == sf::Keyboard::Escape)
	{
		pGrafico->fecharJanela();
	}

	/*
	Jogador 1 se move com A e D, pula com W e ataca com S
	Jogador 2 se move com <- e ->, pula com seta pra cima e ataca com seta pra baixo
	*/
}

void CaveiraDeCristal::Gerenciadores::GerEventos::verificaTeclaSolta(sf::Keyboard::Key tecla)
{
	if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::D)
	{
		pJogador->parar();
	}
}

void CaveiraDeCristal::Gerenciadores::GerEventos::executar()
{
	sf::Event evento;
	if (pGrafico->getWindow()->pollEvent(evento))
	{
		if (evento.type == sf::Event::Closed)
		{
			pGrafico->fecharJanela();
		}
		else if (evento.type == sf::Event::KeyPressed)
		{
			verificaTeclaPressionada(evento.key.code);
		}
		else if (evento.type == sf::Event::KeyReleased)
		{
			verificaTeclaSolta(evento.key.code);
		}
	}
}