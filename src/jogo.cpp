#include "jogo.hpp"
#include "guerreiro.hpp"
#include "bardo.hpp"
#include "alquimista.hpp"
#include "inimigo.hpp"
#include "loja.hpp"
#include <iostream>
#include <vector>
#include <memory>

// Construtor da classe Jogo
Jogo::Jogo() : jogador(nullptr), ouro(100) {}

// Método para iniciar o jogo
void Jogo::iniciar() {
    std::cout << "Bem-vindo ao jogo de turnos!\n";

    // Escolha da classe do jogador
    std::cout << "Escolha sua classe:\n1. Guerreiro\n2. Bardo\n3. Alquimista\n";
    int escolha;
    std::cin >> escolha;

    if (escolha == 1) {
        jogador = std::make_unique<Guerreiro>("Guerreiro Valente");
    } else if (escolha == 2) {
        jogador = std::make_unique<Bardo>("Bardo Inspirador");
    } else if (escolha == 3) {
        jogador = std::make_unique<Alquimista>("Alquimista Sábio");
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

        // Loop de combate com menu de escolhas
        while (jogador->getVida() > 0 && inimigos[i].getVida() > 0) {
            std::cout << "\nEscolha sua ação:\n";
            std::cout << "1. Atacar\n";
            std::cout << "2. Defender\n";
            std::cout << "3. Usar habilidade especial\n";
            std::cout << "4. Fugir\n";
            std::cout << "Sua escolha: ";

            int escolha;
            std::cin >> escolha;

            if (escolha == 1) {
                jogador->atacar(inimigos[i]);
            } else if (escolha == 2) {
                std::cout << jogador->getNome() << " se defendeu e recebeu menos dano!\n";
                jogador->setDefesa(jogador->getDefesa() + 5); // Defesa temporária
            } else if (escolha == 3) {
                // Se for Alquimista, usar Criar Poção
                if (auto* alquimista = dynamic_cast<Alquimista*>(jogador.get())) {
                    alquimista->criarPocao();
                }
                // Se for Bardo, usar Convencer
                else if (dynamic_cast<Bardo*>(jogador.get())) {
                    dynamic_cast<Bardo*>(jogador.get())->convencer(inimigos[i]);
                }
                // Se for Guerreiro, pode adicionar uma habilidade especial no futuro
                else {
                    std::cout << jogador->getNome() << " ainda não tem uma habilidade especial!\n";
                }
            } else if (escolha == 4) {
                std::cout << jogador->getNome() << " fugiu do combate!\n";
                return; // Sai do jogo
            } else {
                std::cout << "Escolha inválida! Tente novamente.\n";
                continue; // Volta para o menu
            }

            // Inimigo ataca se ainda estiver vivo
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