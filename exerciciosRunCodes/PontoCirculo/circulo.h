#ifndef CIRCULO_H
    #define CIRCULO_H
    #include "ponto.h"

    typedef struct circulo CIRCULO;
    
    CIRCULO *circulo_criar(PONTO *p, float raio);
    void circulo_apagar (CIRCULO *circ);
    float circulo_area (CIRCULO *circ);

    //Novas operações:
    float circulo_distancia(CIRCULO *c, PONTO *p);
    float circulo_raio(const CIRCULO *circ);

    /* Justificativa: facilitará a determinação dos casos lógicos da referenciação analítica do
    ponto, em relação à circunferência no espaço R^2. Além disso, permitirá calcular a distância
    entre o ponto e a circunferência de forma mais intuitiva para o usuário. */
#endif