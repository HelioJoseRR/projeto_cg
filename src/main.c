#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "../include/floor.h"
#include "../include/house.h"
#include "../include/escada.h"
#include "../include/moveis.h"

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

// Variáveis do botão
bool button_state = false;  // Variável global que será alterada
int button_x = 20;          // Posição X do botão na tela
int button_y = 20;          // Posição Y do botão na tela
int button_width = 120;     // Largura do botão
int button_height = 30;     // Altura do botão

void display();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void special_keyboard(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void init();
void update_camera();
void draw_button();
void draw_text(float x, float y, const char* text);
bool is_point_in_button(int x, int y);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Casa Museu - Marechal Deodoro");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special_keyboard);
    glutMouseFunc(mouse);

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
        draw_casa_museu(0.0f, 0.0f, 0.0f, CASA_SCALE, button_state);
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

    // Desenhar o botão na interface
    draw_button();

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

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Verificar se o clique foi dentro do botão
        if (is_point_in_button(x, y)) {
            // Alterar o estado da variável
            button_state = !button_state;
            
            // Debug: imprimir o estado atual
            printf("Botão clicado! Novo estado: %s\n", button_state ? "true" : "false");
            
            glutPostRedisplay();
        }
    }
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

void draw_button()
{
    // Salvar o estado atual das matrizes
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    
    // Configurar projeção ortogonal para UI 2D
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glOrtho(0, viewport[2], viewport[3], 0, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    // Desabilitar teste de profundidade para UI
    glDisable(GL_DEPTH_TEST);
    
    // Desenhar o fundo do botão (vermelho)
    if (button_state) {
        glColor3f(0.0f, 1.0f, 0.0f); // Vermelho mais escuro quando ativado
    } else {
        glColor3f(1.0f, 0.3f, 0.3f);  // Vermelho normal
    }
    
    glBegin(GL_QUADS);
        glVertex2f(button_x, button_y);
        glVertex2f(button_x + button_width, button_y);
        glVertex2f(button_x + button_width, button_y + button_height);
        glVertex2f(button_x, button_y + button_height);
    glEnd();
    
    // Desenhar borda do botão
    glColor3f(0.0f, 0.0f, 0.0f);  // Preto
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(button_x, button_y);
        glVertex2f(button_x + button_width, button_y);
        glVertex2f(button_x + button_width, button_y + button_height);
        glVertex2f(button_x, button_y + button_height);
    glEnd();
    
    // Desenhar o texto do botão
    glColor3f(1.0f, 1.0f, 1.0f);  // Branco
    draw_text(button_x + 15, button_y + 20, "Clique aqui");
    
    // Restaurar configurações anteriores
    glEnable(GL_DEPTH_TEST);
    
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void draw_text(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *text);
        text++;
    }
}

bool is_point_in_button(int x, int y)
{
    return (x >= button_x && x <= button_x + button_width &&
            y >= button_y && y <= button_y + button_height);
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Inicializar estado do botão
    printf("Estado inicial do botão: %s\n", button_state ? "true" : "false");
}