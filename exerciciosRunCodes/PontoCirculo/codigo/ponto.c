#include "ponto.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ponto {
    float x;
    float y;
};

PONTO *ponto_criar(float x, float y) {
    PONTO *p = malloc(sizeof(PONTO));
    
    if (p) {
        p->x = x;
        p->y = y;
    }
    
    return p;
}

void ponto_apagar(PONTO *p) {
    if (p)
        free(p);
}

bool ponto_set(PONTO *p, float x, float y) {
    if (!p)
        return false;
        
    p->x = x;
    p->y = y;

    return true;    
}

float ponto_get_x(const PONTO *p) {
    return p ? p->x : 0;
}
    
    
float ponto_get_y(const PONTO *p) {
    return p ? p->y : 0;
}