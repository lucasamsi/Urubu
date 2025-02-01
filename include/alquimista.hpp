#ifndef ALQUIMISTA_HPP
#define ALQUIMISTA_HPP

#include "personagem.hpp"


class Alquimista : public Personagem {
public:
   
    Alquimista(const std::string& nome);

    
    void criarPocao();
};

#endif