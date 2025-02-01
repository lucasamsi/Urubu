#include "jogo.hpp"
#include "guerreiro.hpp"
#include "bardo.hpp"
#include "alquimista.hpp"
#include "inimigo.hpp"
#include "loja.hpp"
#include <iostream>
#include <vector>
#include <memory>


Jogo::Jogo() : jogador(nullptr), ouro(100) {}


void Jogo::iniciar() {
    std::cout << "\nBem-vindo ao Urubu RPG!\n\n";

    std::cout << "\nNesse mundo, o Urubu supremo estah dominando\no territorio magico da UFMG e voce, heroi\nengenheiro, precisa vencer o grande urubu do\nmau e seus discipulos!!\n\n";

   
    std::cout << "Para começar, a que tribo voce quer se juntar?\n\n1 --> Guerreiro\n2 --> Bardo\n3 --> Alquimista\n";
    std::cout << "\nSua escolha: ";
    int escolha;
    std::cin >> escolha;

    if (escolha == 1) {
        jogador = std::make_unique<Guerreiro>("Guerreiro Bravo");
    } else if (escolha == 2) {
        jogador = std::make_unique<Bardo>("Bardo Bobao");
    } else if (escolha == 3) {
        jogador = std::make_unique<Alquimista>("Alquimista Sábio");
    } else {
        std::cout << "Escolha inválida. Criando Guerreiro por padrão.\n";
        jogador = std::make_unique<Guerreiro>("Guerreiro Bravo");
    }

   
    jogar();
}


void Jogo::jogar() {
    std::vector<Inimigo> inimigos = {
        Inimigo("Rato malvado", 50, 10, 5, 3),
        Inimigo("Pedro bigode (do mau)", 80, 15, 8, 2),
        Inimigo("Urubu Supremo", 120, 20, 10, 5)
    };

    Loja loja;

    for (size_t i = 0; i < inimigos.size(); ++i) {
        std::cout << "\n       --- Nível " << i + 1 << " ---\n";

        
        while (jogador->getVida() > 0 && inimigos[i].getVida() > 0) {
            std::cout << "-----------------------------";
            std::cout << "\n|Escolha sua ação:          |\n";
            std::cout << "|1. Atacar                  |\n";
            std::cout << "|2. Defender                |\n";
            std::cout << "|3. Usar habilidade especial|\n";
            std::cout << "|4. Fugir                   |\n";
            std::cout << "-----------------------------\n";
            std::cout << "Sua escolha: ";
            

            int escolha;
            std::cin >> escolha;

            if (escolha == 1) {
                jogador->atacar(inimigos[i]);
            } else if (escolha == 2) {
                std::cout << jogador->getNome() << " se defendeu e recebeu menos dano!\n";
                jogador->setDefesa(jogador->getDefesa() + 5); 
            } else if (escolha == 3) { 
                if (auto* alquimista = dynamic_cast<Alquimista*>(jogador.get())) {
                    alquimista->criarPocao();
                }
                else if (dynamic_cast<Bardo*>(jogador.get())) {
                    dynamic_cast<Bardo*>(jogador.get())->convencer(inimigos[i]);
                }
                else {
                    std::cout << jogador->getNome() << " ainda não tem uma habilidade especial!\n";
                }
            } else if (escolha == 4) {
                std::cout << jogador->getNome() << " fugiu do combate!\n";
                return; 
            } else {
                std::cout << "Escolha inválida! Tente novamente.\n";
                continue; 
            }

           
            if (inimigos[i].getVida() > 0) {
                inimigos[i].atacar(*jogador);
            }
    std::cout << "\n............................. \n";
    std::cout << jogador->getNome() << " - Vida: " << jogador->getVida() << "\n";
    std::cout << inimigos[i].getNome() << " - Vida: " << inimigos[i].getVida() << "\n";
    std::cout << "............................. \n\n";
        }

        if (jogador->getVida() <= 0) {
            std::cout << "Você foi derrotado!\n";
            return;
        }

        std::cout << "Você derrotou " << inimigos[i].getNome() << "!\n";

      
        if (i < inimigos.size() - 1) {
            std::cout << "\n-----------------------------";
            std::cout << "\nBem-vindo à loja do Urubu!\n\nCompre ferramentas para a sua jornada \n\nVocê tem " << ouro << " ouro.\n";
            loja.exibirItens();
            std::cout << "\nEscolha um item para comprar (0 para sair): ";
            int escolha;
            std::cin >> escolha;
            if (escolha != 0) {
                loja.comprarItem(escolha, *jogador, ouro);
            }
        }
    }

    std::cout << "\nParabéns! Você completou o jogo!\n";
}