

#include "guerreiro.hpp"
#include <iostream>


Guerreiro::Guerreiro(const std::string& nome)
    : Personagem(nome, 120, 20, 10, 5, 2) {}

void Guerreiro::atacar(Personagem& alvo) {
    std::cout << nome << " realiza um golpe devastador no inimigo!\n";
    Personagem::atacar(alvo); 
}
