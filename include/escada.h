#ifndef ESCADA_H
#define ESCADA_H

#include <GL/glut.h>
#include "dimensoes.h"
#include "makePolygon.h"

/**
 * Desenha a escada completa em formato U
 */
void draw_escada_completa();

/**
 * Desenha o primeiro trecho da escada (vai para frente)
 */
void draw_escada_trecho1();

/**
 * Desenha o patamar intermediário
 */
void draw_patamar_intermediario();

/**
 * Desenha o segundo trecho da escada (volta)
 */
void draw_escada_trecho2();

/**
 * Desenha um degrau individual
 * @param x, y, z - Posição do degrau
 * @param largura - Largura do degrau
 * @param profundidade - Profundidade do degrau
 * @param altura - Altura do degrau
 * @param rotacao - Rotação do degrau (em graus)
 */
void draw_degrau(float x, float y, float z, float largura, 
                float profundidade, float altura, float rotacao);

/**
 * Desenha o corrimão da escada
 */
void draw_corrimao();

/**
 * Desenha a base da escada (estrutura de suporte)
 */
void draw_escada_base();

#endif // ESCADA_H
