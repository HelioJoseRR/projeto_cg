#include "../include/floor.h"
#include <GL/glut.h>

void draw_floor(float size)
{
    float half_size = size / 2.0f;

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);

    glColor3f(0.8f, 0.8f, 0.8f); // Cor cinza
    glBegin(GL_QUADS);
        glVertex3f(-half_size, 0.0f, -half_size);
        glVertex3f(half_size, 0.0f, -half_size);
        glVertex3f(half_size, 0.0f, half_size);
        glVertex3f(-half_size, 0.0f, half_size);
    glEnd();

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glPopMatrix();
}
