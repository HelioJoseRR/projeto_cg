#ifndef DIMENSOES_H
#define DIMENSOES_H

// ===== DIMENSÕES GERAIS DA CASA MUSEU =====

// Dimensões da casa principal
#define CASA_LARGURA        16.0f    // Largura da casa (eixo X) - usado em house.c e moveis.c
#define CASA_PROFUNDIDADE   14.0f    // Profundidade da casa (eixo Z) - usado em house.c e moveis.c
#define CASA_ALTURA_PAREDE  3.5f     // Altura das paredes do térreo - usado em house.c
#define CASA_ALTURA_TETO    2.0f     // Altura adicional do teto - usado em house.c
#define CASA_SCALE         1.5f     // Fator de escala geral da casa - usado em main.c

// ===== DIMENSÕES DA ESCADA EM U =====

// Escada principal
#define ESCADA_LARGURA      2.0f     // Largura da escada - usado em house.c
#define ESCADA_ALTURA_TOTAL 1.6f     // Altura total da escada - usado em house.c e escada.c

// Patamar intermediário
#define PATAMAR_LARGURA     1.4f     // Largura do patamar - usado em escada.c
#define PATAMAR_PROFUNDIDADE 1.5f    // Profundidade do patamar - usado em escada.c
#define PATAMAR_ALTURA      (8 * 0.15f)     // Altura do patamar intermediário - usado em escada.c

// ===== DIMENSÕES DE PORTAS =====

// Portas
#define PORTA_LARGURA       1.0f     // Largura padrão das portas - usado em house.c
#define PORTA_ALTURA        2.2f     // Altura padrão das portas - usado em house.c

// ===== DIMENSÕES DE MÓVEIS E OBJETOS =====

// Mesa de exposição
#define MESA_LARGURA        1.5f     // Largura da mesa - usado em moveis.c
#define MESA_PROFUNDIDADE   0.8f     // Profundidade da mesa - usado em moveis.c
#define MESA_ALTURA         0.8f     // Altura da mesa - usado em moveis.c

// Cabideiro
#define CABIDEIRO_LARGURA   2.8f     // Largura do cabideiro - usado em moveis.c
#define CABIDEIRO_PROFUNDIDADE 0.1f  // Profundidade do cabideiro - usado em moveis.c
#define CABIDEIRO_ALTURA    0.2f     // Altura do cabideiro - usado em moveis.c

// ===== CORES DOS MÓVEIS =====

// Cores dos móveis
#define COR_MOVEL_R         0.5f     // Vermelho - móveis de madeira - usado em moveis.c
#define COR_MOVEL_G         0.3f     // Verde - móveis de madeira - usado em moveis.c
#define COR_MOVEL_B         0.1f     // Azul - móveis de madeira - usado em moveis.c

#endif // DIMENSOES_H