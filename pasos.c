#include "pasos.h"

#include <stdio.h>

size_t pasos_proposicion_equivalente(const char *expresion, Paso *buffer, size_t capacidad) {
    static const char *PLANTILLA[] = {
        "1) Identificar conectores principales de la expresion.",
        "2) Aplicar equivalencias logicas (De Morgan, doble negacion, etc.).",
        "3) Simplificar terminos repetidos o tautologicos.",
        "4) Verificar equivalencia con una tabla de verdad parcial."
    };
    size_t total = sizeof(PLANTILLA) / sizeof(PLANTILLA[0]);
    size_t i;

    (void)expresion;
    if (buffer == NULL || capacidad == 0) {
        return total;
    }

    for (i = 0; i < total && i < capacidad; ++i) {
        buffer[i].texto = PLANTILLA[i];
    }
    return total;
}

size_t pasos_induccion_basica(const char *enunciado, Paso *buffer, size_t capacidad) {
    static const char *PLANTILLA[] = {
        "1) Probar el caso base n=1 (o el inicial indicado).",
        "2) Suponer verdadera la proposicion para n=k.",
        "3) Demostrar el caso n=k+1 usando la hipotesis inductiva.",
        "4) Concluir por induccion que vale para todo n natural."
    };
    size_t total = sizeof(PLANTILLA) / sizeof(PLANTILLA[0]);
    size_t i;

    (void)enunciado;
    if (buffer == NULL || capacidad == 0) {
        return total;
    }

    for (i = 0; i < total && i < capacidad; ++i) {
        buffer[i].texto = PLANTILLA[i];
    }
    return total;
}

size_t pasos_contradiccion(const char *proposicion, Paso *buffer, size_t capacidad) {
    static const char *PLANTILLA[] = {
        "1) Asumir que la proposicion es falsa (negar la tesis).",
        "2) Derivar logicamente consecuencias de esta suposicion.",
        "3) Llegar a una contradiccion con hechos conocidos o hipotesis.",
        "4) Concluir que la proposicion original debe ser verdadera."
    };
    size_t total = sizeof(PLANTILLA) / sizeof(PLANTILLA[0]);
    size_t i;

    (void)proposicion;
    if (buffer == NULL || capacidad == 0) {
        return total;
    }

    for (i = 0; i < total && i < capacidad; ++i) {
        buffer[i].texto = PLANTILLA[i];
    }
    return total;
}

size_t pasos_demostracion_directa(const char *proposicion, Paso *buffer, size_t capacidad) {
    static const char *PLANTILLA[] = {
        "1) Identificar las hipotesis dadas (P).",
        "2) Establecer definiciones y teoremas relevantes.",
        "3) Aplicar razonamientos logicos paso a paso desde P.",
        "4) Llegar a la conclusion requerida (Q), probando P->Q."
    };
    size_t total = sizeof(PLANTILLA) / sizeof(PLANTILLA[0]);
    size_t i;

    (void)proposicion;
    if (buffer == NULL || capacidad == 0) {
        return total;
    }

    for (i = 0; i < total && i < capacidad; ++i) {
        buffer[i].texto = PLANTILLA[i];
    }
    return total;
}

size_t pasos_analisis_casos(const char *proposicion, Paso *buffer, size_t capacidad) {
    static const char *PLANTILLA[] = {
        "1) Identificar todos los casos posibles que cubren la situacion.",
        "2) Verificar que los casos son mutuamente excluyentes y exhaustivos.",
        "3) Demostrar la proposicion para cada caso por separado.",
        "4) Concluir que la proposicion es verdadera en todos los casos."
    };
    size_t total = sizeof(PLANTILLA) / sizeof(PLANTILLA[0]);
    size_t i;

    (void)proposicion;
    if (buffer == NULL || capacidad == 0) {
        return total;
    }

    for (i = 0; i < total && i < capacidad; ++i) {
        buffer[i].texto = PLANTILLA[i];
    }
    return total;
}

size_t pasos_obtener_por_tema(int tema_id, Paso *buffer, size_t capacidad) {
    switch (tema_id) {
        case 1: /* Logica proposicional */
            return pasos_proposicion_equivalente(NULL, buffer, capacidad);
        case 2: /* Predicados */
            return pasos_demostracion_directa(NULL, buffer, capacidad);
        case 3: /* Induccion matematica */
            return pasos_induccion_basica(NULL, buffer, capacidad);
        case 4: /* Sucesiones y sumatorias */
            return pasos_induccion_basica(NULL, buffer, capacidad);
        case 5: /* Teoria de numeros */
            return pasos_contradiccion(NULL, buffer, capacidad);
        case 6: /* Residuo chino */
            return pasos_demostracion_directa(NULL, buffer, capacidad);
        case 7: /* Combinatoria */
            return pasos_analisis_casos(NULL, buffer, capacidad);
        case 8: /* Teoria de grafos */
            return pasos_analisis_casos(NULL, buffer, capacidad);
        case 9: /* Algebra booleana */
            return pasos_proposicion_equivalente(NULL, buffer, capacidad);
        case 10: /* Recursion */
            return pasos_induccion_basica(NULL, buffer, capacidad);
        case 11: /* Analisis de complejidad */
            return pasos_demostracion_directa(NULL, buffer, capacidad);
        case 12: /* Funciones de crecimiento */
            return pasos_demostracion_directa(NULL, buffer, capacidad);
        default:
            return 0;
    }
}

void pasos_imprimir(const Paso *pasos, size_t total) {
    size_t i;
    if (pasos == NULL) {
        return;
    }
    for (i = 0; i < total; ++i) {
        if (pasos[i].texto != NULL) {
            printf("%s\n", pasos[i].texto);
        }
    }
}
