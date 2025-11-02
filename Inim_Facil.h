#pragma once
#include "Inimigo.h"
class Inim_Facil :
    public Inimigo
{
private:
    float raio;
    // ...
public:
    Inim_Facil();
    ~Inim_Facil();
    void danificar(Jogador* p);
    void executar();
    // ...
};

