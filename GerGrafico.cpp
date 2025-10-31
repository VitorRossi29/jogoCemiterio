#include "GerGrafico.h"

CaveiraDeCristal::Gerenciadores::GerGrafico* CaveiraDeCristal::Gerenciadores::GerGrafico::pGrafico = nullptr;

CaveiraDeCristal::Gerenciadores::GerGrafico::GerGrafico() :
	window(new sf::RenderWindow(sf::VideoMode(800.0f, 600.0f), "A Caveira de Cristal"))
{
	if (window == nullptr)
	{
		std::cout << "Erro para criar janela grafica" << std::endl;
		exit(1);
	}
}

CaveiraDeCristal::Gerenciadores::GerGrafico::~GerGrafico()
{
	if (window)
	{
		delete window;
		window = nullptr;
	}
}

CaveiraDeCristal::Gerenciadores::GerGrafico* CaveiraDeCristal::Gerenciadores::GerGrafico::getGerGrafico()
{
	if (pGrafico == nullptr)
	{
		pGrafico = new GerGrafico();
	}
	return pGrafico;
}

sf::RenderWindow* CaveiraDeCristal::Gerenciadores::GerGrafico::getWindow()
{
	return window;
}

void CaveiraDeCristal::Gerenciadores::GerGrafico::limpaJanela()
{
	window->clear();
}

void CaveiraDeCristal::Gerenciadores::GerGrafico::desenhaElemento(const sf::RectangleShape& corpo)
{
	window->draw(corpo);
}

void CaveiraDeCristal::Gerenciadores::GerGrafico::mostraElementos()
{
	window->display();
}

void CaveiraDeCristal::Gerenciadores::GerGrafico::fecharJanela()
{
	window->close();
}

bool CaveiraDeCristal::Gerenciadores::GerGrafico::verificaAbertura() const
{
	return window->isOpen();
}