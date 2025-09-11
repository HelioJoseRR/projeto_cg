#include "../include/house.h"
#include <GL/glut.h>
#include <math.h>

void draw_colonial_window(float x, float y, float z, float width, float height)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Moldura bege da janela
    glColor3f(0.9f, 0.85f, 0.7f);
    glBegin(GL_QUADS);
        glVertex3f(-width/2 - 0.05f, -height/2 - 0.05f, 0.01f);
        glVertex3f(width/2 + 0.05f, -height/2 - 0.05f, 0.01f);
        glVertex3f(width/2 + 0.05f, height/2 + 0.05f, 0.01f);
        glVertex3f(-width/2 - 0.05f, height/2 + 0.05f, 0.01f);
    glEnd();
    
    // Fundo azul da janela
    glColor3f(0.2f, 0.3f, 0.6f);
    glBegin(GL_QUADS);
        glVertex3f(-width/2, -height/2, 0.02f);
        glVertex3f(width/2, -height/2, 0.02f);
        glVertex3f(width/2, height/2, 0.02f);
        glVertex3f(-width/2, height/2, 0.02f);
    glEnd();
    
    // Grades decorativas em formato de losango
    glColor3f(0.1f, 0.2f, 0.4f);
    glLineWidth(2.0f);
    
    // Grade horizontal central
    glBegin(GL_LINES);
        glVertex3f(-width/2, 0, 0.03f);
        glVertex3f(width/2, 0, 0.03f);
    glEnd();
    
    // Grade vertical central
    glBegin(GL_LINES);
        glVertex3f(0, -height/2, 0.03f);
        glVertex3f(0, height/2, 0.03f);
    glEnd();
    
    // Grades diagonais formando losangos
    float step_x = width / 6.0f;
    float step_y = height / 4.0f;
    
    for(int i = -2; i <= 2; i++) {
        for(int j = -1; j <= 1; j++) {
            float cx = i * step_x;
            float cy = j * step_y;
            
            // Desenhar losango
            glBegin(GL_LINE_LOOP);
                glVertex3f(cx, cy + step_y/2, 0.03f);
                glVertex3f(cx + step_x/2, cy, 0.03f);
                glVertex3f(cx, cy - step_y/2, 0.03f);
                glVertex3f(cx - step_x/2, cy, 0.03f);
            glEnd();
        }
    }
    
    glLineWidth(1.0f);
    glPopMatrix();
}

void draw_colonial_door(float x, float y, float z, float width, float height)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Moldura bege da porta
    glColor3f(0.9f, 0.85f, 0.7f);
    glBegin(GL_QUADS);
        glVertex3f(-width/2 - 0.08f, 0, 0.01f);
        glVertex3f(width/2 + 0.08f, 0, 0.01f);
        glVertex3f(width/2 + 0.08f, height + 0.08f, 0.01f);
        glVertex3f(-width/2 - 0.08f, height + 0.08f, 0.01f);
    glEnd();
    
    // Porta azul escura
    glColor3f(0.15f, 0.25f, 0.5f);
    glBegin(GL_QUADS);
        glVertex3f(-width/2, 0, 0.02f);
        glVertex3f(width/2, 0, 0.02f);
        glVertex3f(width/2, height, 0.02f);
        glVertex3f(-width/2, height, 0.02f);
    glEnd();
    
    // Detalhes da porta
    glColor3f(0.1f, 0.15f, 0.3f);
    glLineWidth(3.0f);
    
    // Divisão central vertical
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0.03f);
        glVertex3f(0, height, 0.03f);
    glEnd();
    
    // Painéis da porta
    float panel_w = width/2 - 0.1f;
    float panel_h = height - 0.2f;
    
    // Painel esquerdo
    glBegin(GL_LINE_LOOP);
        glVertex3f(-width/2 + 0.05f, 0.1f, 0.03f);
        glVertex3f(-0.05f, 0.1f, 0.03f);
        glVertex3f(-0.05f, panel_h + 0.1f, 0.03f);
        glVertex3f(-width/2 + 0.05f, panel_h + 0.1f, 0.03f);
    glEnd();
    
    // Painel direito
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.05f, 0.1f, 0.03f);
        glVertex3f(width/2 - 0.05f, 0.1f, 0.03f);
        glVertex3f(width/2 - 0.05f, panel_h + 0.1f, 0.03f);
        glVertex3f(0.05f, panel_h + 0.1f, 0.03f);
    glEnd();
    
    // Maçaneta
    glColor3f(0.8f, 0.7f, 0.3f); // Dourado
    glPushMatrix();
        glTranslatef(width/4, height/2, 0.04f);
        glutSolidSphere(0.03f, 8, 8);
    glPopMatrix();
    
    glLineWidth(1.0f);
    glPopMatrix();
}

void draw_colonial_lamp(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Poste da luminária
    glColor3f(0.2f, 0.2f, 0.2f);
    glPushMatrix();
        glRotatef(-90, 1, 0, 0);
        glutSolidCylinder(0.02f, 0.3f, 8, 8);
    glPopMatrix();
    
    // Parte superior da luminária
    glColor3f(0.1f, 0.1f, 0.1f);
    glPushMatrix();
        glTranslatef(0, 0.15f, 0);
        glScalef(1.0f, 1.5f, 1.0f);
        glutSolidCube(0.15f);
    glPopMatrix();
    
    // Vidro da luminária
    glColor3f(0.9f, 0.9f, 0.7f);
    glPushMatrix();
        glTranslatef(0, 0.15f, 0);
        glScalef(0.8f, 1.2f, 0.8f);
        glutSolidCube(0.12f);
    glPopMatrix();
    
    glPopMatrix();
}

void draw_colonial_roof(float x, float y, float z, float width, float depth, float height)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Telhas em cor terracota/marrom avermelhado
    glColor3f(0.6f, 0.3f, 0.2f);
    
    // Face frontal do telhado
    glBegin(GL_TRIANGLES);
        glVertex3f(-width/2, 0, depth/2);
        glVertex3f(width/2, 0, depth/2);
        glVertex3f(0, height, depth/2);
    glEnd();
    
    // Face traseira do telhado
    glBegin(GL_TRIANGLES);
        glVertex3f(-width/2, 0, -depth/2);
        glVertex3f(0, height, -depth/2);
        glVertex3f(width/2, 0, -depth/2);
    glEnd();
    
    // Lado esquerdo do telhado
    glBegin(GL_QUADS);
        glVertex3f(-width/2, 0, -depth/2);
        glVertex3f(-width/2, 0, depth/2);
        glVertex3f(0, height, depth/2);
        glVertex3f(0, height, -depth/2);
    glEnd();
    
    // Lado direito do telhado
    glBegin(GL_QUADS);
        glVertex3f(width/2, 0, -depth/2);
        glVertex3f(0, height, -depth/2);
        glVertex3f(0, height, depth/2);
        glVertex3f(width/2, 0, depth/2);
    glEnd();
    
    // Desenhar padrão de telhas
    glColor3f(0.5f, 0.25f, 0.15f);
    glLineWidth(2.0f);
    
    // Linhas horizontais das telhas
    for(int i = 1; i <= 5; i++) {
        float h = (height * i) / 6.0f;
        float w = width * (1.0f - (float)i / 6.0f);
        
        glBegin(GL_LINES);
            glVertex3f(-w/2, h, depth/2 + 0.01f);
            glVertex3f(w/2, h, depth/2 + 0.01f);
            glVertex3f(-w/2, h, -depth/2 - 0.01f);
            glVertex3f(w/2, h, -depth/2 - 0.01f);
        glEnd();
    }
    
    glLineWidth(1.0f);
    glPopMatrix();
}

void draw_casa_museu(float x, float y, float z, float scale)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(scale, scale, scale);
    
    // Dimensões da casa
    float house_width = 16.0f;
    float house_depth = 14.0f;
    float wall_height = 3.5f;
    float roof_height = 1.5f;
    
    // Parede principal (frente)
    glColor3f(0.95f, 0.95f, 0.95f); // Branco
    glBegin(GL_QUADS);
        glVertex3f(-house_width/2, 0, house_depth/2);
        glVertex3f(house_width/2, 0, house_depth/2);
        glVertex3f(house_width/2, wall_height, house_depth/2);
        glVertex3f(-house_width/2, wall_height, house_depth/2);
    glEnd();
    
    // Parede traseira
    glBegin(GL_QUADS);
        glVertex3f(-house_width/2, 0, -house_depth/2);
        glVertex3f(-house_width/2, wall_height, -house_depth/2);
        glVertex3f(house_width/2, wall_height, -house_depth/2);
        glVertex3f(house_width/2, 0, -house_depth/2);
    glEnd();
    
    // Parede lateral esquerda
    glBegin(GL_QUADS);
        glVertex3f(-house_width/2, 0, -house_depth/2);
        glVertex3f(-house_width/2, 0, house_depth/2);
        glVertex3f(-house_width/2, wall_height, house_depth/2);
        glVertex3f(-house_width/2, wall_height, -house_depth/2);
    glEnd();
    
    // Parede lateral direita
    glBegin(GL_QUADS);
        glVertex3f(house_width/2, 0, -house_depth/2);
        glVertex3f(house_width/2, wall_height, -house_depth/2);
        glVertex3f(house_width/2, wall_height, house_depth/2);
        glVertex3f(house_width/2, 0, house_depth/2);
    glEnd();
    
    // Porta central
    draw_colonial_door(0, 0, house_depth/2 + 0.01f, 1.2f, 2.8f);
    
    // Janelas da frente (2 de cada lado da porta)
    GLfloat window_space_between = 1.5f;
    GLfloat window_door_distance = 1.5f;
    draw_colonial_window(-2.5f - window_space_between - window_door_distance, 1.8f, house_depth/2 + 0.01f, 1.4f, 1.8f);
    draw_colonial_window(-1.0f - window_door_distance, 1.8f, house_depth/2 + 0.01f, 1.4f, 1.8f);
    draw_colonial_window(1.0f + window_door_distance, 1.8f, house_depth/2 + 0.01f, 1.4f, 1.8f);
    draw_colonial_window(2.5f + window_space_between + window_door_distance, 1.8f, house_depth/2 + 0.01f, 1.4f, 1.8f);

    // Janela lateral direita
    glPushMatrix();
        glTranslatef(house_width/2 + 0.01f, 1.8f, 0.0f);
        glRotatef(90.0f, 0, 1, 0);
        draw_colonial_window(0.0f, 0.0f, 0.0f, 1.2f, 1.5f);
    glPopMatrix();

    // Luminárias nas laterais da porta
    draw_colonial_lamp(-0.8f, wall_height/2.0f, house_depth/2 + 0.1f);
    draw_colonial_lamp(0.8f, wall_height/2.0f, house_depth/2 + 0.1f);

    // Telhado
    glPushMatrix();
        glRotatef(90.0f, 0, 1, 0);
        draw_colonial_roof(0, wall_height, 0, house_depth + 1.0f, house_width + 1.0f, roof_height);
    glPopMatrix();
    // Placa/plaqueta acima da porta
    glColor3f(0.3f, 0.3f, 0.3f);
    glPushMatrix();
        glTranslatef(0, 3.2f, house_depth/2 + 0.03f);
        glScalef(1.0f, 0.3f, 0.1f);
        glutSolidCube(1.0f);
    glPopMatrix();
    
    // Base/fundação da casa
    glColor3f(0.85f, 0.8f, 0.7f);
    glPushMatrix();
        glTranslatef(0, -0.1f, 0);
        glScalef(house_width + 0.5f, 0.2f, house_depth + 0.5f);
        glutSolidCube(1.0f);
    glPopMatrix();
    
    glPopMatrix();
}