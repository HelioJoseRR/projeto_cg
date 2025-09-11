#ifndef DIMENSOES_H
#define DIMENSOES_H

// ===== DIMENSÕES GERAIS DA CASA MUSEU =====

// Dimensões da casa principal
#define CASA_LARGURA        16.0f    // Largura da casa (eixo X)
#define CASA_PROFUNDIDADE   14.0f    // Profundidade da casa (eixo Z)
#define CASA_ALTURA_PAREDE  3.5f     // Altura das paredes do térreo
#define CASA_ALTURA_TETO    2.0f     // Altura adicional do teto
#define CASA_SCALE         1.5f     // Fator de escala geral da casa

// Dimensões do primeiro andar
#define ANDAR1_ALTURA_PAREDE 3.5f    // Altura das paredes do 1º andar
#define ANDAR1_ALTURA_TETO   1.5f    // Altura adicional do teto do 1º andar

// ===== DIMENSÕES DA ESCADA EM U =====

// Escada principal (primeiro trecho - vai para frente)
#define ESCADA_LARGURA      2.0f     // Largura da escada
#define ESCADA_TRECHO1_COMP 6.0f     // Comprimento do primeiro trecho
#define ESCADA_TRECHO2_COMP 4.0f     // Comprimento do segundo trecho (volta)
#define ESCADA_ALTURA_TOTAL 1.6f     // Altura total da escada
#define ESCADA_NUM_DEGRAUS  16       // Número total de degraus
#define ESCADA_ALTURA_DEGRAU (ESCADA_ALTURA_TOTAL / ESCADA_NUM_DEGRAUS)

// Patamar intermediário
#define PATAMAR_LARGURA     1.4f     // Largura do patamar
#define PATAMAR_PROFUNDIDADE 1.5f    // Profundidade do patamar
#define PATAMAR_ALTURA      (8 * 0.15f)     // Altura do patamar intermediário

// ===== DIMENSÕES DE PORTAS E JANELAS =====

// Portas
#define PORTA_LARGURA       1.0f     // Largura padrão das portas
#define PORTA_ALTURA        2.2f     // Altura padrão das portas
#define PORTA_ESPESSURA     0.1f     // Espessura das portas

// Janelas
#define JANELA_LARGURA      1.5f     // Largura padrão das janelas
#define JANELA_ALTURA       1.2f     // Altura padrão das janelas
#define JANELA_ALTURA_BASE  1.0f     // Altura da base da janela do chão

// ===== DIMENSÕES DE MÓVEIS E OBJETOS =====

// Mesa de exposição
#define MESA_LARGURA        1.5f     // Largura da mesa
#define MESA_PROFUNDIDADE   0.8f     // Profundidade da mesa
#define MESA_ALTURA         0.8f     // Altura da mesa

// Cadeiras históricas
#define CADEIRA_LARGURA     0.5f     // Largura da cadeira
#define CADEIRA_PROFUNDIDADE 0.5f    // Profundidade da cadeira
#define CADEIRA_ALTURA      0.9f     // Altura total da cadeira

// Estantes/Vitrines
#define VITRINE_LARGURA     1.0f     // Largura da vitrine
#define VITRINE_PROFUNDIDADE 0.4f    // Profundidade da vitrine
#define VITRINE_ALTURA      1.8f     // Altura da vitrine

// ===== DIMENSÕES DE PAREDES =====

// Espessura das paredes
#define PAREDE_ESPESSURA    0.2f     // Espessura padrão das paredes
#define PAREDE_EXTERNA_ESP  0.3f     // Espessura das paredes externas

// ===== POSICIONAMENTO E LAYOUT =====

// Posição da casa no mundo
#define CASA_POS_X          0.0f     // Posição X da casa
#define CASA_POS_Y          0.0f     // Posição Y da casa (no chão)
#define CASA_POS_Z          0.0f     // Posição Z da casa

// Posição da escada dentro da casa
#define ESCADA_POS_X        -6.0f    // Posição X da escada (lado esquerdo)
#define ESCADA_POS_Y        0.0f     // Posição Y da escada (no chão)
#define ESCADA_POS_Z        2.0f     // Posição Z da escada (meio da casa)

// ===== CORES PADRONIZADAS =====

// Cores das paredes
#define COR_PAREDE_R        0.9f     // Vermelho - paredes internas
#define COR_PAREDE_G        0.85f    // Verde - paredes internas
#define COR_PAREDE_B        0.8f     // Azul - paredes internas

// Cores das paredes externas
#define COR_EXTERNA_R       0.8f     // Vermelho - paredes externas
#define COR_EXTERNA_G       0.7f     // Verde - paredes externas
#define COR_EXTERNA_B       0.6f     // Azul - paredes externas

// Cores da escada
#define COR_ESCADA_R        0.6f     // Vermelho - madeira da escada
#define COR_ESCADA_G        0.4f     // Verde - madeira da escada
#define COR_ESCADA_B        0.2f     // Azul - madeira da escada

// Cores do teto
#define COR_TETO_R          0.95f    // Vermelho - teto
#define COR_TETO_G          0.95f    // Verde - teto
#define COR_TETO_B          0.9f     // Azul - teto

// Cores dos móveis
#define COR_MOVEL_R         0.5f     // Vermelho - móveis de madeira
#define COR_MOVEL_G         0.3f     // Verde - móveis de madeira
#define COR_MOVEL_B         0.1f     // Azul - móveis de madeira

#endif // DIMENSOES_H
