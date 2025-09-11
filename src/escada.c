#include "../include/escada.h"
#include "../include/dimensoes.h"
#include "../include/makePolygon.h"
#include <GL/glut.h>
#include <math.h>

void draw_escada_completa()
{
    // Posicionar a escada no centro da casa, próxima à parede divisória
    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, -1.0f); // Centrada na casa museu
    
    // Desenhar os três componentes da escada em U
    draw_escada_trecho1();
    draw_patamar_intermediario();
    draw_escada_trecho2();
    draw_escada_base();
    
    glPopMatrix();
}

void draw_escada_trecho1()
{
    // Primeiro trecho: 8 degraus indo para frente (direção Z positiva)
    int degraus_trecho1 = 8;
    float profundidade_degrau = 0.25f; // Profundidade padrão de degrau
    float altura_degrau = 0.15f; // Altura padrão de degrau residencial
    float largura_escada = 1.2f; // Largura adequada para circulação
    
    for (int i = 0; i < degraus_trecho1; i++) {
        float x = 0.0f;
        float y = i * altura_degrau;
        float z = i * profundidade_degrau;
        
        draw_degrau(x, y, z, largura_escada, profundidade_degrau, 
                   altura_degrau, 0.0f);
    }
}

void draw_patamar_intermediario()
{
    Color3D cor_patamar = {0.6f, 0.5f, 0.4f}; // Cor de madeira natural
    
    float altura_patamar = PATAMAR_ALTURA; // Altura após 8 degraus (1.2f)
    float largura_patamar = PATAMAR_LARGURA; // Mesma largura da escada
    float profundidade_patamar = PATAMAR_PROFUNDIDADE; // Espaço suficiente para virar
    
    // Posição do patamar: conecta o final do trecho1 com o início do trecho2
    float x_centro = 0.0f;
    float z_centro = 8 * 0.25f; // Final do trecho1 (2.0f)

    // Desenhar as laterais do patamar
    float espessura_patamar = 0.1f;
    
    glPushMatrix();
        glTranslatef(largura_patamar/2.0f, 0.0f, 0.0f);
        // Desenhar o piso do patamar
        Vertex3D piso_patamar[4] = {
            {x_centro - largura_patamar, altura_patamar, z_centro},
            {x_centro + largura_patamar, altura_patamar, z_centro},
            {x_centro + largura_patamar, altura_patamar, z_centro + profundidade_patamar},
            {x_centro - largura_patamar, altura_patamar, z_centro + profundidade_patamar}
        };
        makePolygon(piso_patamar, 4, cor_patamar);



        // Lateral esquerda
        Vertex3D lateral_esq[4] = {
            {x_centro - largura_patamar, altura_patamar - espessura_patamar, z_centro},
            {x_centro - largura_patamar, altura_patamar, z_centro},
            {x_centro - largura_patamar, altura_patamar, z_centro + profundidade_patamar},
            {x_centro - largura_patamar, altura_patamar - espessura_patamar, z_centro + profundidade_patamar}
        };
        makePolygon(lateral_esq, 4, cor_patamar);

        // Lateral direita
        Vertex3D lateral_dir[4] = {
            {x_centro + largura_patamar, altura_patamar - espessura_patamar, z_centro},
            {x_centro + largura_patamar, altura_patamar, z_centro},
            {x_centro + largura_patamar, altura_patamar, z_centro + profundidade_patamar},
            {x_centro + largura_patamar, altura_patamar - espessura_patamar, z_centro + profundidade_patamar}
        };
        makePolygon(lateral_dir, 4, cor_patamar);

        // Face frontal do patamar (onde termina o trecho1)
        Vertex3D frontal[4] = {
            {x_centro - largura_patamar, altura_patamar - espessura_patamar, z_centro},
            {x_centro + largura_patamar, altura_patamar - espessura_patamar, z_centro},
            {x_centro + largura_patamar, altura_patamar, z_centro},
            {x_centro - largura_patamar, altura_patamar, z_centro}
        };
        makePolygon(frontal, 4, cor_patamar);

        // Face traseira do patamar (onde começa o trecho2)
        Vertex3D traseira[4] = {
            {x_centro - largura_patamar, altura_patamar - espessura_patamar, z_centro + profundidade_patamar},
            {x_centro + largura_patamar, altura_patamar - espessura_patamar, z_centro + profundidade_patamar},
            {x_centro + largura_patamar, altura_patamar, z_centro + profundidade_patamar},
            {x_centro - largura_patamar, altura_patamar, z_centro + profundidade_patamar}
        };
        makePolygon(traseira, 4, cor_patamar);
    glPopMatrix();
}

void draw_escada_trecho2()
{
    // Segundo trecho: 8 degraus voltando (direção Z negativa)
    // Posicionado ao lado do primeiro trecho, criando formato em U
    int degraus_trecho2 = 8;
    float profundidade_degrau = 0.25f; // Mesma profundidade do trecho1
    float altura_degrau = 0.15f;
    float largura_escada = 1.2f;
    float altura_inicial = 8 * 0.13f; // Altura do patamar (1.2f)
    
    // Posição inicial do trecho2: ao lado do trecho1, após o patamar
    float x_offset = 1.5f; // Deslocamento para criar o formato em U
    float z_inicial = 9 * 0.25f; // Final do patamar (3.0f)
    
    for (int i = 0; i < degraus_trecho2; i++) {
        float x = x_offset; // Posicionado ao lado do primeiro trecho
        float y = altura_inicial + (i + 1) * altura_degrau;
        float z = z_inicial - (i + 1) * profundidade_degrau;
        
        draw_degrau(x, y, z, largura_escada, profundidade_degrau, 
                   altura_degrau, 180.0f); // Rotacionado 180° para voltar
    }
}

void draw_degrau(float x, float y, float z, float largura, 
                float profundidade, float altura, float rotacao)
{
    Color3D cor_degrau = {0.5f, 0.4f, 0.3f}; // Cor de madeira mais escura
    
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(rotacao, 0.0f, 1.0f, 0.0f);
    
    // Superfície superior do degrau (onde se pisa)
    Vertex3D superficie[4] = {
        {-largura/2.0f, altura, 0.0f},
        {largura/2.0f, altura, 0.0f},
        {largura/2.0f, altura, profundidade},
        {-largura/2.0f, altura, profundidade}
    };
    makePolygon(superficie, 4, cor_degrau);
    
    // Face frontal do degrau (espelho)
    Vertex3D frontal[4] = {
        {-largura/2.0f, 0.0f, 0.0f},
        {largura/2.0f, 0.0f, 0.0f},
        {largura/2.0f, altura, 0.0f},
        {-largura/2.0f, altura, 0.0f}
    };
    makePolygon(frontal, 4, cor_degrau);
    
    // Laterais do degrau
    Vertex3D lateral_esq[4] = {
        {-largura/2.0f, 0.0f, 0.0f},
        {-largura/2.0f, altura, 0.0f},
        {-largura/2.0f, altura, profundidade},
        {-largura/2.0f, 0.0f, profundidade}
    };
    makePolygon(lateral_esq, 4, cor_degrau);
    
    Vertex3D lateral_dir[4] = {
        {largura/2.0f, 0.0f, 0.0f},
        {largura/2.0f, altura, 0.0f},
        {largura/2.0f, altura, profundidade},
        {largura/2.0f, 0.0f, profundidade}
    };
    makePolygon(lateral_dir, 4, cor_degrau);
    
    // Face traseira do degrau
    Vertex3D traseira[4] = {
        {-largura/2.0f, 0.0f, profundidade},
        {largura/2.0f, 0.0f, profundidade},
        {largura/2.0f, altura, profundidade},
        {-largura/2.0f, altura, profundidade}
    };
    makePolygon(traseira, 4, cor_degrau);
    
    glPopMatrix();
}

void draw_escada_base()
{
    // Cor metálica (aço/ferro)
    Color3D cor_metal = {0.3f, 0.3f, 0.35f}; // Cinza metálico
    
    // Dimensões das bases
    float largura_base = 0.2f;  // Largura da base metálica
    float profundidade_base = 0.2f; // Profundidade da base
    float altura_base = 8 * 0.15f - 0.1f; // Altura até o patamar (1.2f)
    
    // Posições das bases (uma em cada extremidade do patamar)
    float altura_patamar = altura_base;
    float largura_patamar = 1.4f;
    float profundidade_patamar = 1.5f;
    float z_centro_patamar = 8 * 0.25f; // Posição Z do patamar (2.0f)
    
    // Base 1: Lado esquerdo do patamar
    glPushMatrix();
        float x1 = -largura_patamar + largura_base/2.0f; // Posição na extremidade esquerda
        float z1 = z_centro_patamar + profundidade_patamar - profundidade_base/2.0f; // Final do patamar

        glTranslatef(x1 + 1.5f/2.0f, 0.0f, z1);

        // Face superior da base
        Vertex3D topo1[4] = {
            {-largura_base/2.0f, altura_base, -profundidade_base/2.0f},
            {largura_base/2.0f, altura_base, -profundidade_base/2.0f},
            {largura_base/2.0f, altura_base, profundidade_base/2.0f},
            {-largura_base/2.0f, altura_base, profundidade_base/2.0f}
        };
        makePolygon(topo1, 4, cor_metal);
        
        // Face inferior da base (no chão)
        Vertex3D base1[4] = {
            {-largura_base/2.0f, 0.0f, -profundidade_base/2.0f},
            {largura_base/2.0f, 0.0f, -profundidade_base/2.0f},
            {largura_base/2.0f, 0.0f, profundidade_base/2.0f},
            {-largura_base/2.0f, 0.0f, profundidade_base/2.0f}
        };
        makePolygon(base1, 4, cor_metal);
        
        // Faces laterais da base 1
        // Face frontal
        Vertex3D frontal1[4] = {
            {-largura_base/2.0f, 0.0f, -profundidade_base/2.0f},
            {largura_base/2.0f, 0.0f, -profundidade_base/2.0f},
            {largura_base/2.0f, altura_base, -profundidade_base/2.0f},
            {-largura_base/2.0f, altura_base, -profundidade_base/2.0f}
        };
        makePolygon(frontal1, 4, cor_metal);
        
        // Face traseira
        Vertex3D traseira1[4] = {
            {-largura_base/2.0f, 0.0f, profundidade_base/2.0f},
            {largura_base/2.0f, 0.0f, profundidade_base/2.0f},
            {largura_base/2.0f, altura_base, profundidade_base/2.0f},
            {-largura_base/2.0f, altura_base, profundidade_base/2.0f}
        };
        makePolygon(traseira1, 4, cor_metal);
        
        // Face esquerda
        Vertex3D esquerda1[4] = {
            {-largura_base/2.0f, 0.0f, -profundidade_base/2.0f},
            {-largura_base/2.0f, altura_base, -profundidade_base/2.0f},
            {-largura_base/2.0f, altura_base, profundidade_base/2.0f},
            {-largura_base/2.0f, 0.0f, profundidade_base/2.0f}
        };
        makePolygon(esquerda1, 4, cor_metal);
        
        // Face direita
        Vertex3D direita1[4] = {
            {largura_base/2.0f, 0.0f, -profundidade_base/2.0f},
            {largura_base/2.0f, altura_base, -profundidade_base/2.0f},
            {largura_base/2.0f, altura_base, profundidade_base/2.0f},
            {largura_base/2.0f, 0.0f, profundidade_base/2.0f}
        };
        makePolygon(direita1, 4, cor_metal);
    glPopMatrix();
    
    // Base 2: Lado direito do patamar
    glPushMatrix();
        float x2 = largura_patamar - largura_base/2.0f; // Posição na extremidade direita
        float z2 = z_centro_patamar + profundidade_patamar - profundidade_base/2.0f; // Final do patamar

        glTranslatef(x2 + 1.4f/2.0f, 0.0f, z2);

        // Face superior da base
        Vertex3D topo2[4] = {
            {-largura_base/2.0f, altura_base, -profundidade_base/2.0f},
            {largura_base/2.0f, altura_base, -profundidade_base/2.0f},
            {largura_base/2.0f, altura_base, profundidade_base/2.0f},
            {-largura_base/2.0f, altura_base, profundidade_base/2.0f}
        };
        makePolygon(topo2, 4, cor_metal);
        
        // Face inferior da base (no chão)
        Vertex3D base2[4] = {
            {-largura_base/2.0f, 0.0f, -profundidade_base/2.0f},
            {largura_base/2.0f, 0.0f, -profundidade_base/2.0f},
            {largura_base/2.0f, 0.0f, profundidade_base/2.0f},
            {-largura_base/2.0f, 0.0f, profundidade_base/2.0f}
        };
        makePolygon(base2, 4, cor_metal);
        
        // Faces laterais da base 2
        // Face frontal
        Vertex3D frontal2[4] = {
            {-largura_base/2.0f, 0.0f, -profundidade_base/2.0f},
            {largura_base/2.0f, 0.0f, -profundidade_base/2.0f},
            {largura_base/2.0f, altura_base, -profundidade_base/2.0f},
            {-largura_base/2.0f, altura_base, -profundidade_base/2.0f}
        };
        makePolygon(frontal2, 4, cor_metal);
        
        // Face traseira
        Vertex3D traseira2[4] = {
            {-largura_base/2.0f, 0.0f, profundidade_base/2.0f},
            {largura_base/2.0f, 0.0f, profundidade_base/2.0f},
            {largura_base/2.0f, altura_base, profundidade_base/2.0f},
            {-largura_base/2.0f, altura_base, profundidade_base/2.0f}
        };
        makePolygon(traseira2, 4, cor_metal);
        
        // Face esquerda
        Vertex3D esquerda2[4] = {
            {-largura_base/2.0f, 0.0f, -profundidade_base/2.0f},
            {-largura_base/2.0f, altura_base, -profundidade_base/2.0f},
            {-largura_base/2.0f, altura_base, profundidade_base/2.0f},
            {-largura_base/2.0f, 0.0f, profundidade_base/2.0f}
        };
        makePolygon(esquerda2, 4, cor_metal);
        
        // Face direita
        Vertex3D direita2[4] = {
            {largura_base/2.0f, 0.0f, -profundidade_base/2.0f},
            {largura_base/2.0f, altura_base, -profundidade_base/2.0f},
            {largura_base/2.0f, altura_base, profundidade_base/2.0f},
            {largura_base/2.0f, 0.0f, profundidade_base/2.0f}
        };
        makePolygon(direita2, 4, cor_metal);
    glPopMatrix();
}