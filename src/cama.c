#include "../include/cama.h"
#include "../include/dimensoes.h"
#include "../include/makePolygon.h"
#include <GL/glut.h>
#include <math.h>

void draw_camas_museu()
{
    // Não desenha nenhuma cama aqui
}

void draw_cama_colonial(float x, float y, float z, float comprimento, float largura, float altura, float rotacao)
{
    Color3D cor_madeira = {0.4f, 0.25f, 0.15f}; // Marrom escuro da madeira
    Color3D cor_madeira_clara = {0.5f, 0.35f, 0.2f}; // Marrom mais claro
    Color3D cor_colchao = {0.9f, 0.9f, 0.85f}; // Bege claro do colchão
    Color3D cor_renda = {1.0f, 1.0f, 0.95f}; // Branco da renda
    
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(rotacao, 0.0f, 1.0f, 0.0f);
    
    // === BASE DA CAMA ===
    float espessura_base = 0.08f;
    
    // Tampo da base (onde fica o colchão)
    Vertex3D base_superior[4] = {
        {-comprimento/2.0f, altura - espessura_base, -largura/2.0f},
        {comprimento/2.0f, altura - espessura_base, -largura/2.0f},
        {comprimento/2.0f, altura - espessura_base, largura/2.0f},
        {-comprimento/2.0f, altura - espessura_base, largura/2.0f}
    };
    makePolygon(base_superior, 4, cor_madeira);
    
    // Lateral esquerda da base
    Vertex3D base_esquerda[4] = {
        {-comprimento/2.0f, altura - espessura_base, -largura/2.0f},
        {-comprimento/2.0f, altura - espessura_base, largura/2.0f},
        {-comprimento/2.0f, altura - espessura_base*2, largura/2.0f},
        {-comprimento/2.0f, altura - espessura_base*2, -largura/2.0f}
    };
    makePolygon(base_esquerda, 4, cor_madeira);
    
    // Lateral direita da base
    Vertex3D base_direita[4] = {
        {comprimento/2.0f, altura - espessura_base, -largura/2.0f},
        {comprimento/2.0f, altura - espessura_base*2, -largura/2.0f},
        {comprimento/2.0f, altura - espessura_base*2, largura/2.0f},
        {comprimento/2.0f, altura - espessura_base, largura/2.0f}
    };
    makePolygon(base_direita, 4, cor_madeira);
    
    // === CABECEIRA (inspirada nas imagens) ===
    float altura_cabeceira = altura + 0.8f;
    float espessura_cabeceira = 0.06f;
    
    // Painel principal da cabeceira (na extremidade do comprimento, parte da cabeça)
    Vertex3D cabeceira_painel[4] = {
        {-comprimento/2.0f, altura - espessura_base, largura/2.0f},
        {-comprimento/2.0f, altura - espessura_base, -largura/2.0f},
        {-comprimento/2.0f, altura_cabeceira, -largura/2.0f},
        {-comprimento/2.0f, altura_cabeceira, largura/2.0f}
    };
    makePolygon(cabeceira_painel, 4, cor_madeira);

    // Parte decorativa superior da cabeceira (arredondada)
    Vertex3D cabeceira_topo[4] = {
        {-comprimento/2.0f, altura_cabeceira, largura/2.0f},
        {-comprimento/2.0f, altura_cabeceira, -largura/2.0f},
        {-comprimento/2.0f, altura_cabeceira + 0.15f, -largura/2.0f},
        {-comprimento/2.0f, altura_cabeceira + 0.15f, largura/2.0f}
    };
    makePolygon(cabeceira_topo, 4, cor_madeira_clara);
    
    // === PÉS DA CAMA ===
    float raio_pe = 0.03f;
    float altura_pe = altura - espessura_base;
    
    glColor3f(cor_madeira.r, cor_madeira.g, cor_madeira.b);
    
    // Pé 1 (canto esquerdo traseiro)
    glPushMatrix();
    glTranslatef(-comprimento/2.0f + 0.1f, altura_pe/2.0f, largura/2.0f - 0.1f);
    glScalef(raio_pe*2, altura_pe, raio_pe*2);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    // Pé 2 (canto direito traseiro)
    glPushMatrix();
    glTranslatef(comprimento/2.0f - 0.1f, altura_pe/2.0f, largura/2.0f - 0.1f);
    glScalef(raio_pe*2, altura_pe, raio_pe*2);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    // Pé 3 (canto esquerdo dianteiro)
    glPushMatrix();
    glTranslatef(-comprimento/2.0f + 0.1f, altura_pe/2.0f, -largura/2.0f + 0.1f);
    glScalef(raio_pe*2, altura_pe, raio_pe*2);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    // Pé 4 (canto direito dianteiro)
    glPushMatrix();
    glTranslatef(comprimento/2.0f - 0.1f, altura_pe/2.0f, -largura/2.0f + 0.1f);
    glScalef(raio_pe*2, altura_pe, raio_pe*2);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    // === COLCHÃO ===
    // Proporções realistas para pessoa magra e de estatura normal
    float colchao_comprimento = comprimento * 0.85f; // 85% do comprimento da cama
    float colchao_largura = largura * 0.45f;         // 45% da largura da cama
    float altura_colchao = 0.08f;                    // Menor altura para parecer mais fino

    // Superfície do colchão
    Vertex3D colchao_topo[4] = {
        {-colchao_comprimento/2.0f, altura - espessura_base + altura_colchao, -colchao_largura/2.0f},
        {colchao_comprimento/2.0f, altura - espessura_base + altura_colchao, -colchao_largura/2.0f},
        {colchao_comprimento/2.0f, altura - espessura_base + altura_colchao, colchao_largura/2.0f},
        {-colchao_comprimento/2.0f, altura - espessura_base + altura_colchao, colchao_largura/2.0f}
    };
    makePolygon(colchao_topo, 4, cor_colchao);

    // Laterais do colchão
    Vertex3D colchao_lateral1[4] = {
        {-colchao_comprimento/2.0f, altura - espessura_base, -colchao_largura/2.0f},
        {colchao_comprimento/2.0f, altura - espessura_base, -colchao_largura/2.0f},
        {colchao_comprimento/2.0f, altura - espessura_base + altura_colchao, -colchao_largura/2.0f},
        {-colchao_comprimento/2.0f, altura - espessura_base + altura_colchao, -colchao_largura/2.0f}
    };
    makePolygon(colchao_lateral1, 4, cor_colchao);

    Vertex3D colchao_lateral2[4] = {
        {-colchao_comprimento/2.0f, altura - espessura_base, colchao_largura/2.0f},
        {-colchao_comprimento/2.0f, altura - espessura_base + altura_colchao, colchao_largura/2.0f},
        {colchao_comprimento/2.0f, altura - espessura_base + altura_colchao, colchao_largura/2.0f},
        {colchao_comprimento/2.0f, altura - espessura_base, colchao_largura/2.0f}
    };
    makePolygon(colchao_lateral2, 4, cor_colchao);
    
    // === RENDA/TOALHA (como nas imagens) ===
    draw_toalha_renda(comprimento, largura, altura - espessura_base + altura_colchao + 0.01f);
    
    
    glPopMatrix();
}

void draw_toalha_renda(float comprimento, float largura, float altura_base)
{
    Color3D cor_renda = {1.0f, 1.0f, 0.95f}; // Branco cremoso
    
    // Toalha principal cobrindo parte do colchão
    Vertex3D toalha_principal[4] = {
        {-comprimento/2.0f + 0.2f, altura_base, -largura/2.0f + 0.15f},
        {comprimento/2.0f - 0.2f, altura_base, -largura/2.0f + 0.15f},
        {comprimento/2.0f - 0.2f, altura_base, largura/2.0f - 0.15f},
        {-comprimento/2.0f + 0.2f, altura_base, largura/2.0f - 0.15f}
    };
    makePolygon(toalha_principal, 4, cor_renda);
    
    // Barrado de renda (padrão geométrico)
    glColor3f(cor_renda.r, cor_renda.g, cor_renda.b);
    glLineWidth(2.0f);
    
    // Desenhar padrão de losangos na borda da toalha
    int num_losangos = 8;
    float step = (comprimento - 0.4f) / num_losangos;
    
    for(int i = 0; i < num_losangos; i++) {
        float x_centro = -comprimento/2.0f + 0.2f + i * step + step/2;
        float y_renda = altura_base + 0.001f;
        
        // Losango superior
        glBegin(GL_LINE_LOOP);
        glVertex3f(x_centro, y_renda, largura/2.0f - 0.15f);
        glVertex3f(x_centro + 0.04f, y_renda, largura/2.0f - 0.19f);
        glVertex3f(x_centro, y_renda, largura/2.0f - 0.23f);
        glVertex3f(x_centro - 0.04f, y_renda, largura/2.0f - 0.19f);
        glEnd();
        
        // Losango inferior
        glBegin(GL_LINE_LOOP);
        glVertex3f(x_centro, y_renda, -largura/2.0f + 0.15f);
        glVertex3f(x_centro + 0.04f, y_renda, -largura/2.0f + 0.19f);
        glVertex3f(x_centro, y_renda, -largura/2.0f + 0.23f);
        glVertex3f(x_centro - 0.04f, y_renda, -largura/2.0f + 0.19f);
        glEnd();
    }
    
    glLineWidth(1.0f);
}

void draw_detalhes_cabeceira_colonial(float comprimento, float altura_cabeceira, float z_pos)
{
    Color3D cor_detalhe = {0.3f, 0.2f, 0.1f}; // Marrom mais escuro para detalhes
    
    glColor3f(cor_detalhe.r, cor_detalhe.g, cor_detalhe.b);
    glLineWidth(3.0f);
    
    // Moldura retangular central
    float moldura_width = comprimento * 0.6f;
    float moldura_height = altura_cabeceira * 0.6f;
    float moldura_y_base = altura_cabeceira * 0.2f;
    
    glBegin(GL_LINE_LOOP);
    glVertex3f(-moldura_width/2.0f, moldura_y_base, z_pos);
    glVertex3f(moldura_width/2.0f, moldura_y_base, z_pos);
    glVertex3f(moldura_width/2.0f, moldura_y_base + moldura_height, z_pos);
    glVertex3f(-moldura_width/2.0f, moldura_y_base + moldura_height, z_pos);
    glEnd();
    
    // Divisão central vertical
    glBegin(GL_LINES);
    glVertex3f(0.0f, moldura_y_base, z_pos);
    glVertex3f(0.0f, moldura_y_base + moldura_height, z_pos);
    glEnd();
    
    // Divisões horizontais
    glBegin(GL_LINES);
    glVertex3f(-moldura_width/2.0f, moldura_y_base + moldura_height/3.0f, z_pos);
    glVertex3f(moldura_width/2.0f, moldura_y_base + moldura_height/3.0f, z_pos);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-moldura_width/2.0f, moldura_y_base + 2*moldura_height/3.0f, z_pos);
    glVertex3f(moldura_width/2.0f, moldura_y_base + 2*moldura_height/3.0f, z_pos);
    glEnd();
    
    // Detalhes decorativos nos cantos (pequenos losangos)
    float detalhe_size = 0.03f;
    
    // Canto superior esquerdo
    glBegin(GL_LINE_LOOP);
    glVertex3f(-moldura_width/2.0f + detalhe_size, moldura_y_base + moldura_height - detalhe_size/2, z_pos);
    glVertex3f(-moldura_width/2.0f + detalhe_size*2, moldura_y_base + moldura_height, z_pos);
    glVertex3f(-moldura_width/2.0f + detalhe_size, moldura_y_base + moldura_height + detalhe_size/2, z_pos);
    glVertex3f(-moldura_width/2.0f, moldura_y_base + moldura_height, z_pos);
    glEnd();
    
    // Canto superior direito
    glBegin(GL_LINE_LOOP);
    glVertex3f(moldura_width/2.0f - detalhe_size, moldura_y_base + moldura_height - detalhe_size/2, z_pos);
    glVertex3f(moldura_width/2.0f, moldura_y_base + moldura_height, z_pos);
    glVertex3f(moldura_width/2.0f - detalhe_size, moldura_y_base + moldura_height + detalhe_size/2, z_pos);
    glVertex3f(moldura_width/2.0f - detalhe_size*2, moldura_y_base + moldura_height, z_pos);
    glEnd();

    
    glLineWidth(1.0f);
}