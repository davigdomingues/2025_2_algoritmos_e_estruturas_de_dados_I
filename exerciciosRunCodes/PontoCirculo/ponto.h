#ifndef PONTO_H
    #define PONTO_H
	#include <stdbool.h>
	
    typedef struct ponto PONTO;
    
    PONTO *ponto_criar(float x, float y);
    void ponto_apagar(PONTO *p);
    bool ponto_set(PONTO *p, float x, float y);
    
    // Novas operações:
    float ponto_get_x(const PONTO *p);
    float ponto_get_y(const PONTO *p);
    /* Justificativa: servem como "getters" para facilitar o cálculo da distância
    envolvido na circunferência. */
#endif