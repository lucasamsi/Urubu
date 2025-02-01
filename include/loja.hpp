

#ifndef LOJA_HPP
#define LOJA_HPP

#include <vector>
#include "item.hpp"
#include "personagem.hpp"


class Loja {
private:
    std::vector<Item> itens; 

public:
   
    Loja();

   
    void exibirItens();

   
    void comprarItem(int escolha, Personagem& jogador, int& ouro);
};

#endif