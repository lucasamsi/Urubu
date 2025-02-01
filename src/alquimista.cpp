#include "alquimista.hpp"
#include <iostream>
#include <cstdlib> 


Alquimista::Alquimista(const std::string& nome)
    : Personagem(nome, 90, 12, 6, 8, 14) {} 


void Alquimista::criarPocao() {
    int efeito = rand() % 3; 

    switch (efeito) {
        case 0: 
            std::cout << nome << " criou uma Poção de Cura e restaurou 20 pontos de vida!\n";
            setVida(getVida() + 20);
            break;

        case 1: 
            std::cout << nome << " criou uma Poção de Força! Seu ataque aumentou temporariamente.\n";
            setAtaque(getAtaque() + 5);
            break;

        case 2: 
            std::cout << nome << " criou uma Poção de Agilidade! Sua defesa aumentou temporariamente.\n";
            setDefesa(getDefesa() + 5);
            break;
    }
}