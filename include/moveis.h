#ifndef MOVEIS_H
#define MOVEIS_H

#include <GL/glut.h>
#include "dimensoes.h"
#include "makePolygon.h"
#include "cama.h"

/**
 * Desenha todos os móveis e objetos do museu, incluindo cama colonial
 */
void draw_moveis_museu();

/**
 * Desenha uma mesa de exposição
 * @param x, y, z - Posição da mesa
 */
void draw_mesa_exposicao(float x, float y, float z);

#endif // MOVEIS_H
