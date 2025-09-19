#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "circulo.h"

int main() {
    float pontoX, pontoY, centroX, centroY, raio;

    scanf("%f %f", &pontoX, &pontoY);
    scanf("%f %f %f", &centroX, &centroY, &raio);

    PONTO *ponto = ponto_criar(pontoX, pontoY);
    PONTO *centro = ponto_criar(centroX, centroY);
    CIRCULO *circulo = circulo_criar(centro, raio);

    if (!ponto || !centro || !circulo) {
        printf("Erro ao criar as estruturas\n");

        ponto_apagar(ponto);
        ponto_apagar(centro);
        circulo_apagar(circulo);

        return 1;
    }

    float dist = circulo_distancia(circulo, ponto);

    if (dist < 0) {
        printf("Erro ao calcular a distância\n");

        circulo_apagar(circulo);
        ponto_apagar(ponto);

        return 1;
    }

    if (dist < circulo_raio(circulo))
        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
    
    else if (dist > circulo_raio(circulo))
        printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);

    else
        printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);

    circulo_apagar(circulo);
    ponto_apagar(ponto);

    return 0;
}