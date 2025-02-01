

#ifndef GUERREIRO_HPP
#define GUERREIRO_HPP

#include "personagem.hpp"


class Guerreiro : public Personagem {
public:
 
    Guerreiro(const std::string& nome);

    
    void atacar(Personagem& alvo) override;
};

#endif
