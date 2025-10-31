#pragma once

#include <SFML/Graphics.hpp>

class Jogo
{
private:
    sf::RenderWindow window;
    sf::RectangleShape shape;
    sf::Texture textura_jogador2;
public:
    Jogo();
    ~Jogo();
    void executar();
};

