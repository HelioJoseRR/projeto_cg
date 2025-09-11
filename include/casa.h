#ifndef CASA_H
#define CASA_H

#include <GL/glut.h>
#include "dimensoes.h"
#include "makePolygon.h"

/**
 * Desenha a estrutura completa da Casa Museu de Marechal Deodoro
 */
void draw_casa_museu();

/**
 * Desenha as paredes externas da casa
 */
void draw_paredes_externas();

/**
 * Desenha as paredes internas da casa
 */
void draw_paredes_internas();

/**
 * Desenha o primeiro andar da casa
 */
void draw_primeiro_andar();

/**
 * Desenha o teto da casa
 */
void draw_teto();

/**
 * Desenha portas da casa
 */
void draw_portas();

/**
 * Desenha janelas da casa
 */
void draw_janelas();

/**
 * Função auxiliar para desenhar uma parede retangular
 * @param x1, z1 - Coordenadas do primeiro ponto
 * @param x2, z2 - Coordenadas do segundo ponto
 * @param altura - Altura da parede
 * @param y_base - Altura base da parede
 * @param cor - Cor da parede
 */
void draw_parede_retangular(float x1, float z1, float x2, float z2, 
                           float altura, float y_base, Color3D cor);

#endif // CASA_H
