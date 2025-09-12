#ifndef CAMA_H
#define CAMA_H

#include <GL/glut.h>
#include "dimensoes.h"
#include "makePolygon.h"

/**
 * Desenha todas as camas do museu
 */
void draw_camas_museu();

/**
 * Desenha uma cama colonial completa
 * @param x, y, z - Posição da cama
 * @param comprimento - Comprimento da cama
 * @param largura - Largura da cama
 * @param altura - Altura da base da cama
 * @param rotacao - Rotação da cama em graus
 */
void draw_cama_colonial(float x, float y, float z, float comprimento, 
                       float largura, float altura, float rotacao);

/**
 * Desenha a toalha de renda sobre o colchão
 * @param comprimento - Comprimento da toalha
 * @param largura - Largura da toalha
 * @param altura_base - Altura onde a toalha será posicionada
 */
void draw_toalha_renda(float comprimento, float largura, float altura_base);

/**
 * Desenha os detalhes decorativos da cabeceira colonial
 * @param comprimento - Largura da cabeceira
 * @param altura_cabeceira - Altura da cabeceira
 * @param z_pos - Posição Z da cabeceira
 */
void draw_detalhes_cabeceira_colonial(float comprimento, float altura_cabeceira, float z_pos);

#endif // CAMA_H