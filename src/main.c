#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/floor.h"
#include "../include/house.h"
#include "../include/escada.h"
#include "../include/moveis.h"
#include "../include/cama.h"
#include "../include/bule.h"

#define FLOOR_SIZE 1000.0f
#define PI 3.14159265359

// Variáveis de posição e câmera
float camera_x = 0.0f;
float camera_y = 1.7f;
float camera_z = 5.0f;

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
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Casa Museu - Marechal Deodoro com Camas Coloniais");
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
        draw_casa_museu(0.0f, 0.0f, 0.0f, CASA_SCALE);
    glPopMatrix();
    
    // Desenhar a escada em U
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, -CASA_PROFUNDIDADE/5);
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        draw_escada_completa();
    glPopMatrix();
    
    // Desenhar móveis e objetos do museu
    glPushMatrix();
        draw_moveis_museu();
    glPopMatrix();


    // Desenhar as camas coloniais
    glPushMatrix();
        draw_camas_museu();
    glPopMatrix();

    // Desenhar bule branco embaixo da cama (ajuste posição conforme necessário)
    glPushMatrix();
        desenhaBuleBranco(0.0f, 0.05f, CASA_PROFUNDIDADE/2 - 2.0f, 0.3f);
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
        case 'r':
        case 'R':
            // Reset da câmera para posição inicial
            camera_x = 0.0f;
            camera_y = 1.7f;
            camera_z = 5.0f;
            camera_yaw = 0.0f;
            camera_pitch = 0.0f;
            break;
        case 'f':
        case 'F':
            // Posição especial para ver as camas no primeiro andar
            camera_x = -1.0f;
            camera_y = ESCADA_ALTURA_TOTAL + 1.0f;
            camera_z = -2.0f;
            camera_yaw = 45.0f;
            camera_pitch = -15.0f;
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
    
    // Habilitar iluminação básica para melhor visualização das camas
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    // Configurar luz ambiente
    GLfloat light_ambient[] = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat light_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat light_position[] = {0.0f, 10.0f, 0.0f, 1.0f};
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    // Permitir que as cores sejam definidas mesmo com iluminação
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    
    printf("=== CONTROLES DA CASA MUSEU ===\n");
    printf("WASD: Mover pela casa\n");
    printf("Q/E: Subir/Descer\n");
    printf("Setas: Olhar ao redor\n");
    printf("R: Reset da câmera\n");
    printf("F: Ver camas do primeiro andar\n");
    printf("ESC: Sair\n");
    printf("===============================\n");
}