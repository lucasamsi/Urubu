

#ifndef BARDO_HPP
#define BARDO_HPP

#include "personagem.hpp"


class Bardo : public Personagem {
public:
    
    Bardo(const std::string& nome);

    
    void convencer(Personagem& alvo) override;
};

#endif
