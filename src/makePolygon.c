#include "makePolygon.h"
#include <GL/glut.h>

void makePolygon(Vertex3D vertices[], int num_vertices, Color3D color)
{
    if (num_vertices < 3) return; // Precisa de pelo menos 3 vértices
    
    // Define a cor da parede
    glColor3f(color.r, color.g, color.b);
    
    // Desenha o polígono preenchido
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_vertices; i++) {
        glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
    }
    glEnd();
    
    // Desenha as bordas em preto para dar definição
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_vertices; i++) {
        glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
    }
    glEnd();
}