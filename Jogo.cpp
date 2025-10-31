#include "Jogo.h"
#include "Entidade.h"

Jogo::Jogo() : 
window(sf::VideoMode(1000, 600), "Jogo TecProg", sf::Style::Close),
shape(sf::Vector2f(100.f, 100.f))
{
	textura_jogador2.loadFromFile("Assets/Imagens/cacadorLongo.png");
	shape.setTexture(&textura_jogador2);
    executar();
}

Jogo::~Jogo() {}

void Jogo::executar()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            shape.move(sf::Vector2f(-0.2f, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            shape.move(sf::Vector2f(0.2f, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            shape.move(sf::Vector2f(0, -0.2f));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            shape.move(sf::Vector2f(0, 0.2f));
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

}