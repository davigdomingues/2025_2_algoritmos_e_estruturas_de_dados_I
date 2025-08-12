#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circulo.h"
#include "ponto.h"


// Definição da constante Pi como M_PI (padrão C)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct circulo {
    PONTO *centro;
    float raio;
};

CIRCULO *circulo_criar(PONTO *centro, float raio) {
    if (!centro || raio < 0)
        return NULL;
        
    CIRCULO *c = malloc(sizeof(CIRCULO));
    
    if (c) {
        c->centro = centro;
        c->raio = raio;
    }
    
    return c;
}

void circulo_apagar (CIRCULO *circ) {
    if (circ) {
        ponto_apagar(circ->centro);
        free(circ);
    }
}

float circulo_area (CIRCULO *circ) {
    if (!circ)
        return 0;
        
    return M_PI*pow(circ->raio,2);
}

float circulo_distancia(CIRCULO *c, PONTO *p) {
    if (!p || !c || !c->centro)
        return -1;

    return sqrt(pow(ponto_get_x(p) - ponto_get_x(c->centro),2) + pow(ponto_get_y(p) - ponto_get_y(c->centro),2));
}

float circulo_raio(const CIRCULO *circ) {
    return circ ? circ->raio : -1;
}