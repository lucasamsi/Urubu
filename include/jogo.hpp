// Arquivo: jogo.hpp

#ifndef JOGO_HPP
#define JOGO_HPP

#include <memory>
#include "personagem.hpp"
#include "loja.hpp"
#include "inimigo.hpp"

// Classe Jogo
class Jogo {
private:
    std::unique_ptr<Personagem> jogador; // Jogador (polimórfico)
    int ouro; // Quantidade de ouro do jogador

public:
    // Construtor
    Jogo();

    // Método para iniciar o jogo
    void iniciar();

    // Método para executar os níveis do jogo
    void jogar();
};

#endif
