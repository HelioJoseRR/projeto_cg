#ifndef MAKEPOLYGON_H
#define MAKEPOLYGON_H

#include <GL/glut.h>

// Estrutura para representar um vértice 3D
typedef struct {
    float x, y, z;
} Vertex3D;

// Estrutura para representar uma cor RGB
typedef struct {
    float r, g, b;
} Color3D;

/**
 * Desenha uma parede poligonal com n vértices
 * @param vertices - Array de vértices que formam o polígono
 * @param num_vertices - Número de vértices do polígono
 * @param color - Cor da parede (RGB)
 */
void makePolygon(Vertex3D vertices[], int num_vertices, Color3D color);

/**
 * Desenha uma casa quadrada com teto triangular
 * @param base_size - Tamanho da base da casa
 * @param height - Altura das paredes
 * @param roof_height - Altura do teto
 * @param x, y, z - Posição da casa
 */
void drawHouse(float base_size, float height, float roof_height, float x, float y, float z);

#endif // MAKEPOLYGON_H