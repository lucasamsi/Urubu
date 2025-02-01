

#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "personagem.hpp"


class Inimigo : public Personagem {
public:
   
    Inimigo(const std::string& nome, int vida, int ataque, int defesa, int agilidade);


    void atacar(Personagem& alvo) override;
};

#endif
