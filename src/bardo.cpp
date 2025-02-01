

#include "bardo.hpp"
#include <iostream>
#include <cstdlib> 


Bardo::Bardo(const std::string& nome)
    : Personagem(nome, 100, 10, 8, 6, 12) {}


void Bardo::convencer(Personagem& alvo) {
    int chance = carisma * 10; 
    if (rand() % 100 < chance) {
        std::cout << nome << " convenceu " << alvo.getNome() << " a recuar temporariamente!\n";
        alvo.setVida(alvo.getVida() - 5); 
    } else {
        std::cout << nome << " tentou convencer " << alvo.getNome() << ", mas falhou.\n";
    }
}
