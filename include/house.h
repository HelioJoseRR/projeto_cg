#ifndef HOUSE_H
#define HOUSE_H

#include <GL/glut.h>

/**
 * @brief Desenha a Casa Museu do Marechal Deodoro
 * @param x Posição X da casa
 * @param y Posição Y da casa (base)
 * @param z Posição Z da casa
 * @param scale Escala da casa (1.0 = tamanho original)
 */
void draw_casa_museu(float x, float y, float z, float scale);

/**
 * @brief Desenha uma janela colonial com grades decorativas
 * @param x, y, z Posição da janela
 * @param width Largura da janela
 * @param height Altura da janela
 */
void draw_colonial_window(float x, float y, float z, float width, float height);

/**
 * @brief Desenha uma porta colonial
 * @param x, y, z Posição da porta
 * @param width Largura da porta
 * @param height Altura da porta
 */
void draw_colonial_door(float x, float y, float z, float width, float height);

/**
 * @brief Desenha o telhado colonial
 * @param x, y, z Posição base do telhado
 * @param width Largura do telhado
 * @param depth Profundidade do telhado
 * @param height Altura do telhado
 */
void draw_colonial_roof(float x, float y, float z, float width, float depth, float height);

/**
 * @brief Desenha uma luminária colonial
 * @param x, y, z Posição da luminária
 */
void draw_colonial_lamp(float x, float y, float z);

#endif // HOUSE_H