#include "../include/casa.h"
#include "../include/dimensoes.h"
#include "../include/makePolygon.h"
#include <GL/glut.h>
#include <math.h>

void draw_casa_museu()
{
    glPushMatrix();
    glTranslatef(CASA_POS_X, CASA_POS_Y, CASA_POS_Z);
    
    // Desenhar componentes da casa na ordem correta
    draw_paredes_externas();
    draw_paredes_internas();
    draw_teto();
    draw_primeiro_andar();
    draw_portas();
    draw_janelas();
    
    glPopMatrix();
}

void draw_paredes_externas()
{

}

void draw_paredes_internas()
{
    
}

void draw_primeiro_andar()
{
 
}

void draw_teto()
{
    
}

void draw_portas()
{
    
}

void draw_janelas()
{
    
}

void draw_parede_retangular(float x1, float z1, float x2, float z2, 
                           float altura, float y_base, Color3D cor)
{
    Vertex3D vertices[4];
    
    // Calcular os vértices da parede
    vertices[0].x = x1; vertices[0].y = y_base; vertices[0].z = z1;
    vertices[1].x = x2; vertices[1].y = y_base; vertices[1].z = z2;
    vertices[2].x = x2; vertices[2].y = y_base + altura; vertices[2].z = z2;
    vertices[3].x = x1; vertices[3].y = y_base + altura; vertices[3].z = z1;
    
    makePolygon(vertices, 4, cor);
}
