#include "bule.h"
#include <GL/glut.h>
#include <GL/glu.h>

void desenhaBuleBranco(float x, float y, float z, float escala) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(escala, escala * 0.7f, escala); // corpo mais "chato"
    glColor3f(1.0f, 1.0f, 1.0f); // branco
    // Corpo do bule (esfera achatada)
    glutSolidSphere(1.0f, 32, 32);
    // Tampa do bule (disco + cilindro achatado, mais largo)
    glPushMatrix();
        glTranslatef(0.0f, 1.0f, 0.0f);
        glRotatef(-90, 1, 0, 0);
        GLUquadric* quad = gluNewQuadric();
        gluDisk(quad, 0.0f, 0.7f, 32, 1); // disco mais largo
        // Tampa 3D achatada e larga
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.03f);
            glScalef(1.2f, 1.2f, 0.5f); // achatada e mais larga
            gluCylinder(quad, 0.6f, 0.6f, 0.07f, 32, 1);
        glPopMatrix();
        gluDeleteQuadric(quad);
    glPopMatrix();
    // Alça do bule (torus)
    glPushMatrix();
        glTranslatef(1.0f, 0.3f, 0.0f);
        glRotatef(90, 0, 0, 1);
        glutSolidTorus(0.08, 0.35, 16, 32);
    glPopMatrix();
    glPopMatrix();
}
