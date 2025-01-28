// Arquivo: guerreiro.cpp

#include "guerreiro.h"
#include <iostream>

// Construtor da classe Guerreiro
Guerreiro::Guerreiro(const std::string& nome)
    : Personagem(nome, 120, 20, 10, 5, 2) {}

// Ataque especial do Guerreiro
void Guerreiro::atacar(Personagem& alvo) {
    std::cout << nome << " realiza um golpe devastador no inimigo!\n";
    Personagem::atacar(alvo); // Usa a lógica de ataque da classe base
}
