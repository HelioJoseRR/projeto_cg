#include "../include/moveis.h"
#include "../include/dimensoes.h"
#include "../include/makePolygon.h"
#include <GL/glut.h>
#include <math.h>

void draw_moveis_museu()
{
    // Sala principal (térreo)
    draw_mesa_exposicao(CASA_LARGURA/2 + 2.0f, 0.0f, CASA_PROFUNDIDADE - 5.0f);
}

void draw_mesa_exposicao(float x, float y, float z)
{
    Color3D cor_mesa = {COR_MOVEL_R, COR_MOVEL_G, COR_MOVEL_B};
    
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    
    // Tampo da mesa
    Vertex3D tampo[4] = {
        {-MESA_LARGURA/2.0f, MESA_ALTURA, -MESA_PROFUNDIDADE/2.0f},
        {MESA_LARGURA/2.0f, MESA_ALTURA, -MESA_PROFUNDIDADE/2.0f},
        {MESA_LARGURA/2.0f, MESA_ALTURA, MESA_PROFUNDIDADE/2.0f},
        {-MESA_LARGURA/2.0f, MESA_ALTURA, MESA_PROFUNDIDADE/2.0f}
    };
    makePolygon(tampo, 4, cor_mesa);
    
    // Pernas da mesa (4 cilindros pequenos)
    float perna_raio = 0.05f;
    glColor3f(cor_mesa.r, cor_mesa.g, cor_mesa.b);
    
    // Perna 1
    glPushMatrix();
    glTranslatef(-MESA_LARGURA/2.0f + 0.1f, MESA_ALTURA/2.0f, -MESA_PROFUNDIDADE/2.0f + 0.1f);
    glScalef(perna_raio, MESA_ALTURA, perna_raio);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Perna 2
    glPushMatrix();
    glTranslatef(MESA_LARGURA/2.0f - 0.1f, MESA_ALTURA/2.0f, -MESA_PROFUNDIDADE/2.0f + 0.1f);
    glScalef(perna_raio, MESA_ALTURA, perna_raio);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Perna 3
    glPushMatrix();
    glTranslatef(MESA_LARGURA/2.0f - 0.1f, MESA_ALTURA/2.0f, MESA_PROFUNDIDADE/2.0f - 0.1f);
    glScalef(perna_raio, MESA_ALTURA, perna_raio);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Perna 4
    glPushMatrix();
    glTranslatef(-MESA_LARGURA/2.0f + 0.1f, MESA_ALTURA/2.0f, MESA_PROFUNDIDADE/2.0f - 0.1f);
    glScalef(perna_raio, MESA_ALTURA, perna_raio);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glPopMatrix();
}
