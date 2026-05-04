#ifndef PASOS_H
#define PASOS_H

#include <stddef.h>

typedef struct {
    const char *texto;
} Paso;

size_t pasos_proposicion_equivalente(const char *expresion, Paso *buffer, size_t capacidad);
size_t pasos_induccion_basica(const char *enunciado, Paso *buffer, size_t capacidad);
size_t pasos_contradiccion(const char *proposicion, Paso *buffer, size_t capacidad);
size_t pasos_demostracion_directa(const char *proposicion, Paso *buffer, size_t capacidad);
size_t pasos_analisis_casos(const char *proposicion, Paso *buffer, size_t capacidad);
size_t pasos_obtener_por_tema(int tema_id, Paso *buffer, size_t capacidad);
void pasos_imprimir(const Paso *pasos, size_t total);

#endif
