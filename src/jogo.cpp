// Arquivo: jogo.cpp

#include "jogo.h"
#include "guerreiro.h"
#include "bardo.h"
#include "inimigo.h"
#include "loja.h"
#include <iostream>
#include <vector>
#include <memory>

// Construtor da classe Jogo
Jogo::Jogo() : jogador(nullptr), ouro(100) {}

// Método para iniciar o jogo
void Jogo::iniciar() {
    std::cout << "Bem-vindo ao jogo de turnos!\n";

    // Escolha da classe do jogador
    std::cout << "Escolha sua classe:\n1. Guerreiro\n2. Bardo\n";
    int escolha;
    std::cin >> escolha;

    if (escolha == 1) {
        jogador = std::make_unique<Guerreiro>("Guerreiro Valente");
    } else if (escolha == 2) {
        jogador = std::make_unique<Bardo>("Bardo Inspirador");
    } else {
        std::cout << "Escolha inválida. Criando Guerreiro por padrão.\n";
        jogador = std::make_unique<Guerreiro>("Guerreiro Valente");
    }

    // Jogar os níveis
    jogar();
}

// Método para executar o jogo
void Jogo::jogar() {
    std::vector<Inimigo> inimigos = {
        Inimigo("Goblin", 50, 10, 5, 3),
        Inimigo("Orc", 80, 15, 8, 2),
        Inimigo("Dragão", 120, 20, 10, 5)
    };

    Loja loja;

    for (size_t i = 0; i < inimigos.size(); ++i) {
        std::cout << "\n--- Nível " << i + 1 << " ---\n";

        // Loop de combate
        while (jogador->getVida() > 0 && inimigos[i].getVida() > 0) {
            jogador->atacar(inimigos[i]);
            if (inimigos[i].getVida() > 0) {
                inimigos[i].atacar(*jogador);
            }
        }

        if (jogador->getVida() <= 0) {
            std::cout << "Você foi derrotado!\n";
            return;
        }

        std::cout << "Você derrotou " << inimigos[i].getNome() << "!\n";

        // Loja entre níveis
        if (i < inimigos.size() - 1) {
            std::cout << "Bem-vindo à loja. Você tem " << ouro << " ouro.\n";
            loja.exibirItens();
            std::cout << "Escolha um item para comprar (0 para sair): ";
            int escolha;
            std::cin >> escolha;
            if (escolha != 0) {
                loja.comprarItem(escolha, *jogador, ouro);
            }
        }
    }

    std::cout << "\nParabéns! Você completou o jogo!\n";
}
