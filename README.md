# Urubu, o RPG

Este é um jogo simples de combate por turnos, inspirado no estilo Pokémon, desenvolvido como parte de um projeto acadêmico. O jogo é totalmente baseado em terminal e foi implementado utilizando o paradigma de **orientação a objetos** em **C++**.

---

## **Descrição do Jogo**

No jogo, você assume o controle de um personagem jogável com uma das três especializações disponíveis: 
- **Lutador (Fighter):** Focado em combate direto, com habilidades para causar grande dano.
- **Curandeiro (Healer):** Especialista em itens e cura para suporte.
- **Diplomata (Diplomat):** Hábil em negociar, podendo evitar combates usando lábia.

### **Objetivo**
Enfrente inimigos em três fases de combate, intercaladas com fases de loja, onde você pode comprar itens para melhorar seu desempenho. O objetivo final é vencer todos os inimigos ou negociar sua vitória através de conversas.

---

## **Funcionalidades**
- **Sistema de Turnos:** Durante os combates, você pode escolher entre quatro ações:
  - **Atacar:** Causa dano ao inimigo.
  - **Defender:** Reduz o dano recebido no próximo turno.
  - **Curar:** Recupera pontos de vida (HP).
  - **Conversar:** Tenta negociar com o inimigo para evitar a luta.
- **Loja:** Compre itens que ajudam durante os combates, como poções de cura, itens de suporte e equipamentos de ataque.
- **Progressão:** Ganhe XP e dinheiro ao derrotar inimigos ou ao negociar com eles.
- **Salvamento de Progresso:** O jogo salva automaticamente seu progresso em arquivos, permitindo continuar de onde parou.

---

## **Estrutura do Projeto**
O jogo foi desenvolvido seguindo o paradigma de orientação a objetos, com uma arquitetura modular composta pelas seguintes classes principais:

### **1. Personagens**
- `Character` (abstrata): Base para todos os personagens.
  - Subclasses: `PlayerCharacter`, `EnemyCharacter`, `Fighter`, `Healer`, `Diplomat`, `BossEnemy`, `StandardEnemy`.

### **2. Itens**
- `Item` (abstrata): Base para todos os itens do jogo.
  - Subclasses: `HealingItem`, `CombatItem`, `SupportItem`.

### **3. Outras Classes**
- `Shop`: Gerencia a loja e as transações de itens.
- `BattleSystem`: Gerencia os turnos e as interações durante o combate.
- `Game`: Controla o fluxo geral do jogo, salvamento e carregamento de dados.

---

## **Requisitos**
Para executar o jogo, é necessário ter:
- Um compilador compatível com **C++17** ou superior.
- Sistema operacional Linux ou Windows com terminal habilitado.

---

## **Como Executar**
1. Clone este repositório:
   ```bash
   git clone https://github.com/lucasamsi/Urubu.git
   cd Urubu
