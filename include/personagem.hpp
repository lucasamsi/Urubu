// Arquivo: personagem.hpp

#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <string>
#include <iostream>

// Classe base Personagem
class Personagem {
protected:
    std::string nome;  // Nome do personagem
    int vida;          // Pontos de vida atuais
    int maxVida;       // Pontos de vida máximos
    int ataque;        // Força de ataque
    int defesa;        // Nível de defesa
    int agilidade;     // Agilidade do personagem
    int carisma;       // Carisma (usado para convencer)

public:
    // Construtor
    Personagem(const std::string& nome, int vida, int ataque, int defesa, int agilidade, int carisma);

    // Métodos getters
    std::string getNome() const;
    int getVida() const;
    void setVida(int novaVida);
    int getDefesa() const;

    // Métodos virtuais para ações
    virtual void atacar(Personagem& alvo);
    virtual void defender();
    virtual void curar(Personagem& aliado);
    virtual void convencer(Personagem& alvo);
};

#endif
