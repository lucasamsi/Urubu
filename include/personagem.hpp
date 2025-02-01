

#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <string>
#include <iostream>


class Personagem {
protected:
    std::string nome;  
    int vida;          
    int maxVida;       
    int ataque;        
    int defesa;        
    int agilidade;     
    int carisma;     

public:
   
    Personagem(const std::string& nome, int vida, int ataque, int defesa, int agilidade, int carisma);

    
    std::string getNome() const;
    int getVida() const;
    void setVida(int novaVida);
    int getDefesa() const;
    void setDefesa(int novaDefesa);
    int getAtaque()const;
    void setAtaque(int novoAtaque);

    
    virtual void atacar(Personagem& alvo);
    virtual void defender();
    virtual void curar(Personagem& aliado);
    virtual void convencer(Personagem& alvo);
};

#endif
