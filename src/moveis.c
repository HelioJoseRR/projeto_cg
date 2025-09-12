#include "../include/moveis.h"
#include "../include/dimensoes.h"
#include "../include/makePolygon.h"
#include <GL/glut.h>
#include <math.h>

void draw_moveis_museu()
{
    // Sala principal (térreo)
    draw_mesa_exposicao(CASA_LARGURA/2 + 2.0f, 0.0f, CASA_PROFUNDIDADE - 5.0f);
    glPushMatrix();
    glTranslatef(-CASA_LARGURA/2 - 3.8f, 1.7f, -(CASA_PROFUNDIDADE - 6.0f));
    draw_cabideiro();
    glPopMatrix();
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

void draw_cabideiro(){
    Color3D cor_cabideiro = {COR_MOVEL_R, COR_MOVEL_G, COR_MOVEL_B};
    Color3D cor_cabides = {COR_MOVEL_R + 0.1f, COR_MOVEL_G + 0.1f, COR_MOVEL_B + 0.1f};

    glPushMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

    glPushMatrix();
    // Base do cabideiro parte da frente
    Vertex3D base[4] = {
        {-CABIDEIRO_LARGURA/2.0f, 0.0f, 0.0f},                    // inferior esquerda
        {CABIDEIRO_LARGURA/2.0f, 0.0f, 0.0f},                     // inferior direita
        {CABIDEIRO_LARGURA/2.0f, CABIDEIRO_ALTURA, 0.0f},         // superior direita
        {-CABIDEIRO_LARGURA/2.0f, CABIDEIRO_ALTURA, 0.0f}         // superior esquerda
    };
    makePolygon(base, 4, cor_cabideiro);

    // laterais do cabideiro
    Vertex3D lado_esquerdo[4] = {
        {-CABIDEIRO_LARGURA/2.0f, 0.0f, -CABIDEIRO_PROFUNDIDADE},                    // inferior esquerda
        {-CABIDEIRO_LARGURA/2.0f, 0.0f, 0.0f},                     // inferior direita
        {-CABIDEIRO_LARGURA/2.0f, CABIDEIRO_ALTURA, 0.0f},         // superior direita
        {-CABIDEIRO_LARGURA/2.0f, CABIDEIRO_ALTURA, -CABIDEIRO_PROFUNDIDADE}         // superior esquerda
    };
    makePolygon(lado_esquerdo, 4, cor_cabideiro);

    Vertex3D lado_direito[4] = {
        {CABIDEIRO_LARGURA/2.0f, 0.0f, -CABIDEIRO_PROFUNDIDADE},                    // inferior esquerda
        {CABIDEIRO_LARGURA/2.0f, 0.0f, 0.0f},                     // inferior direita
        {CABIDEIRO_LARGURA/2.0f, CABIDEIRO_ALTURA, 0.0f},         // superior direita
        {CABIDEIRO_LARGURA/2.0f, CABIDEIRO_ALTURA, -CABIDEIRO_PROFUNDIDADE}         // superior esquerda
    };
    makePolygon(lado_direito, 4, cor_cabideiro);

    // lateral infreior
    Vertex3D base_inferior[4] = {
        {-CABIDEIRO_LARGURA/2.0f, 0.0f, -CABIDEIRO_PROFUNDIDADE},                    // inferior esquerda
        {CABIDEIRO_LARGURA/2.0f, 0.0f, -CABIDEIRO_PROFUNDIDADE},                     // inferior direita
        {CABIDEIRO_LARGURA/2.0f, 0.0f, 0.0f},         // superior direita
        {-CABIDEIRO_LARGURA/2.0f, 0.0f, 0.0f}         // superior esquerda
    };
    makePolygon(base_inferior, 4, cor_cabideiro);

    // lateral superior
    Vertex3D base_superior[4] = {
        {-CABIDEIRO_LARGURA/2.0f, CABIDEIRO_ALTURA, -CABIDEIRO_PROFUNDIDADE},                    // inferior esquerda
        {CABIDEIRO_LARGURA/2.0f, CABIDEIRO_ALTURA, -CABIDEIRO_PROFUNDIDADE},                     // inferior direita
        {CABIDEIRO_LARGURA/2.0f, CABIDEIRO_ALTURA, 0.0f},         // superior direita
        {-CABIDEIRO_LARGURA/2.0f, CABIDEIRO_ALTURA, 0.0f}         // superior esquerda
    };
    makePolygon(base_superior, 4, cor_cabideiro);

    // Cabides (representados como pequenos teapots)
    int qtd_cabides = 5;
    float espacamento = CABIDEIRO_LARGURA / (qtd_cabides + 1);
    for(int i = 1; i <= qtd_cabides; i++){
        glPushMatrix();
        glTranslatef(-CABIDEIRO_LARGURA/2 + i * espacamento, CABIDEIRO_ALTURA - 0.1f, -0.05f);
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        glColor3f(cor_cabides.r, cor_cabides.g, cor_cabides.b);
        glutSolidTeapot(0.08f);
        glPopMatrix();
    }
    
    glPopMatrix();
    glPopMatrix();
}
