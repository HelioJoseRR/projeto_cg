#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/floor.h"
#include "../include/casa.h"
#include "../include/escada.h"
#include "../include/moveis.h"

#define FLOOR_SIZE 1000.0f
#define PI 3.14159265359

// Variáveis de posição e câmera
float camera_x = 0.0f;
float camera_y = 1.7f;
float camera_z = 1.0f;

float camera_yaw = 0.0f;   // Rotação horizontal (esquerda/direita)
float camera_pitch = 0.0f; // Rotação vertical (cima/baixo)

float move_speed = 0.5f;   // Velocidade de movimento
float mouse_sensitivity = 2.0f; // Sensibilidade do mouse/setas

void display();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void special_keyboard(int key, int x, int y);
void init();
void update_camera();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Casa Museu - Marechal Deodoro");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special_keyboard);

    glutMainLoop();
    return 0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    update_camera();

    // Desenhar o chão
    glPushMatrix();
        draw_floor(FLOOR_SIZE);
    glPopMatrix();

    // Desenhar a Casa Museu completa
    glPushMatrix();
        draw_casa_museu();
    glPopMatrix();
    
    // Desenhar a escada em U
    glPushMatrix();
        draw_escada_completa();
    glPopMatrix();
    
    // Desenhar móveis e objetos do museu
    glPushMatrix();
        draw_moveis_museu();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)width / (double)height, 0.1, 2000.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    float yaw_rad = camera_yaw * PI / 180.0f;
    
    switch(key) {
        case 27: // ESC
            exit(0);
            break;
        case 'w':
        case 'W':
            // Move para frente
            camera_x += sin(yaw_rad) * move_speed;
            camera_z -= cos(yaw_rad) * move_speed;
            break;
        case 's':
        case 'S':
            // Move para trás
            camera_x -= sin(yaw_rad) * move_speed;
            camera_z += cos(yaw_rad) * move_speed;
            break;
        case 'a':
        case 'A':
            // Move para esquerda (strafe)
            camera_x -= cos(yaw_rad) * move_speed;
            camera_z -= sin(yaw_rad) * move_speed;
            break;
        case 'd':
        case 'D':
            // Move para direita (strafe)
            camera_x += cos(yaw_rad) * move_speed;
            camera_z += sin(yaw_rad) * move_speed;
            break;
        case 'q':
        case 'Q':
            // Move câmera para cima
            camera_y += move_speed;
            break;
        case 'e':
        case 'E':
            // Move câmera para baixo
            camera_y -= move_speed;
            // Evita que a câmera vá abaixo do chão
            if(camera_y < 0.5f) camera_y = 0.5f;
            break;
        default:
            break;
    }
    
    glutPostRedisplay();
}

void special_keyboard(int key, int x, int y)
{
    switch(key) {
        case GLUT_KEY_LEFT:
            camera_yaw -= mouse_sensitivity;
            break;
        case GLUT_KEY_RIGHT:
            camera_yaw += mouse_sensitivity;
            break;
        case GLUT_KEY_UP:
            camera_pitch += mouse_sensitivity;
            if(camera_pitch > 89.0f) camera_pitch = 89.0f; // Limite superior
            break;
        case GLUT_KEY_DOWN:
            camera_pitch -= mouse_sensitivity;
            if(camera_pitch < -89.0f) camera_pitch = -89.0f; // Limite inferior
            break;
    }
    
    glutPostRedisplay();
}

void update_camera()
{
    float yaw_rad = camera_yaw * PI / 180.0f;
    float pitch_rad = camera_pitch * PI / 180.0f;
    
    // Calcular a direção da câmera baseada nos ângulos
    float look_x = camera_x + sin(yaw_rad) * cos(pitch_rad);
    float look_y = camera_y + sin(pitch_rad);
    float look_z = camera_z - cos(yaw_rad) * cos(pitch_rad);
    
    gluLookAt(camera_x, camera_y, camera_z,  // Posição da câmera
              look_x, look_y, look_z,        // Ponto para onde olha
              0.0, 1.0, 0.0);                // Vetor "up"
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
}
