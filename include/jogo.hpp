

#ifndef JOGO_HPP
#define JOGO_HPP

#include <memory>
#include "personagem.hpp"
#include "loja.hpp"
#include "inimigo.hpp"


class Jogo {
private:
    std::unique_ptr<Personagem> jogador; 
    int ouro; 

public:
    
    Jogo();

    void iniciar();

    void jogar();
};

#endif
