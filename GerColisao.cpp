#include "GerColisao.h"

CaveiraDeCristal::Gerenciadores::GerColisao::GerColisao(Lista::ListaEntidades* listaPersonagens, Lista::ListaEndidades* listaPlataformas)
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

const sf::Vector2f CaveiraDeCristal::Gerenciadores::GerColisao::verificarColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2)
{
	sf::Vector2f pos1 = ent1->getPos();
	sf::Vector2f pos2 = ent2->getPos();

	sf::Vector2f tam1 = ent1->getTam();
	sf::Vector2f tam2 = ent2->getTam();

	sf::Vector2f distanciaDosCentros
		(
			fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
			fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f))
		);

	sf::Vector2f somaMetades
		(
			(tam1.x / 2.0f) + (tam2.x / 2.0f),
			(tam1.y / 2.0f) + (tam2.y / 2.0f)
		);

	return sf::Vector2f(distanciaDosCentros.x - somaMetades.x, distanciaDosCentros.y - somaMetades.y);
}

void CaveiraDeCristal::Gerenciadores::GerColisao::executar()
{ 
	int i, j;

	// Aqui se verifica a colisao entre dois personagens

	for (i = 0; i < listaPersonagens->getTam() - 1; i++)
	{
		Entidades::Entidade* ent1 = listaPersonagens->operator[](i);
		for (j = i + 1; j < listaPersonagens->getTam(); j++)
		{
			Entidades::Entidade* ent2 = listaPersonagens->operator[](j);
			sf::Vector2f distancia = verificarColisao(ent1, ent2);
			if(distancia.x < 0.0f && distancia.y < 0.0f)
			{
				ent1->colisao(ent2);
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
			Entidades::Entidade* ent2 = listaPlataformas->operator[](j);
			sf::Vector2f distancia = distancia.y < 0.0f)
			{
				if (ent2->getID() == IDs::IDs::plataforma)
				{
					ent2->colisao(ent1, colidir);
				}
				
				else
				{
					//outro obstaculo
				}
			}
		}
	}
}