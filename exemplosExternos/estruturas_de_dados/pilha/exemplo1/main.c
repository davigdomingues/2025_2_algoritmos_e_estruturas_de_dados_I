#include <stdio.h>
#include <string.h>
#include "pilha.h"

// Exercício 1: Empilhar e Desempilhar
void exercicio1() {
    Pilha p;
    int valor;
    inicializar(&p);

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    printf("Desempilhando valores:\n");
    while (!estaVazia(&p)) {
        desempilhar(&p, &valor);
        printf("%d\n", valor);
    }
}

// Exercício 2: Verificar se está vazia ou cheia
void exercicio2() {
    Pilha p;
    int num;
    inicializar(&p);

    printf("Digite números (-1 para parar):\n");
    while (!estaCheia(&p)) {
        scanf("%d", &num);
        if (num == -1) break;
        empilhar(&p, num);
    }

    if (estaCheia(&p))
        printf("A pilha está cheia.\n");
    else
        printf("A pilha não está cheia.\n");
}

// Exercício 3: Inverter sequência
void exercicio3() {
    Pilha p;
    int num;
    inicializar(&p);

    printf("Digite 5 números:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &num);
        empilhar(&p, num);
    }

    printf("Números invertidos:\n");
    while (!estaVazia(&p)) {
        desempilhar(&p, &num);
        printf("%d ", num);
    }
    printf("\n");
}

// Exercício 4: Decimal para Binário
void exercicio4() {
    Pilha p;
    int num, resto;
    inicializar(&p);

    printf("Digite um número decimal: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("Binário: 0\n");
        return;
    }

    while (num > 0) {
        resto = num % 2;
        empilhar(&p, resto);
        num /= 2;
    }

    printf("Binário: ");
    while (!estaVazia(&p)) {
        desempilhar(&p, &resto);
        printf("%d", resto);
    }
    printf("\n");
}

// Exercício 5: Palíndromo
void exercicio5() {
    char palavra[100];
    Pilha p;
    int i, ok = 1, valor;
    inicializar(&p);

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    for (i = 0; palavra[i] != '\0'; i++) {
        empilhar(&p, palavra[i]);
    }

    for (i = 0; palavra[i] != '\0'; i++) {
        desempilhar(&p, &valor);
        if (valor != palavra[i]) {
            ok = 0;
            break;
        }
    }

    if (ok)
        printf("É palíndromo!\n");
    else
        printf("Não é palíndromo.\n");
}

// Exercício 6: Reverter frase
void exercicio6() {
    char frase[200];
    Pilha p;
    int i, ch;
    inicializar(&p);

    getchar(); // limpar buffer
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    for (i = 0; frase[i] != '\0'; i++) {
        empilhar(&p, frase[i]);
    }

    printf("Frase invertida:\n");
    while (!estaVazia(&p)) {
        desempilhar(&p, &ch);
        printf("%c", ch);
    }
}

// Exercício 7: Parênteses balanceados
void exercicio7() {
    char expr[200];
    Pilha p;
    int i, ch, ok = 1;
    inicializar(&p);

    printf("Digite uma expressão: ");
    scanf("%s", expr);

    for (i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(')
            empilhar(&p, '(');
        else if (expr[i] == ')') {
            if (!desempilhar(&p, &ch)) {
                ok = 0;
                break;
            }
        }
    }

    if (!estaVazia(&p)) ok = 0;

    if (ok) printf("Parênteses balanceados!\n");
    else printf("Parênteses não balanceados!\n");
}

// Exercício 8: Desfazer/Refazer
void exercicio8() {
    Pilha feitos, desfeitos;
    int valor, opcao;
    inicializar(&feitos);
    inicializar(&desfeitos);

    do {
        printf("\n1 - Fazer ação\n2 - Desfazer\n3 - Refazer\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o valor da ação: ");
            scanf("%d", &valor);
            empilhar(&feitos, valor);
        }
        else if (opcao == 2) {
            if (desempilhar(&feitos, &valor)) {
                empilhar(&desfeitos, valor);
                printf("Ação %d desfeita.\n", valor);
            } else {
                printf("Nada para desfazer.\n");
            }
        }
        else if (opcao == 3) {
            if (desempilhar(&desfeitos, &valor)) {
                empilhar(&feitos, valor);
                printf("Ação %d refeita.\n", valor);
            } else {
                printf("Nada para refazer.\n");
            }
        }
    } while (opcao != 0);
}

// Exercício 9: Ordenar pilha
void exercicio9() {
    Pilha p, aux;
    int n, valor, tmp;
    inicializar(&p);
    inicializar(&aux);

    printf("Quantos números deseja empilhar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        empilhar(&p, valor);
    }

    while (!estaVazia(&p)) {
        desempilhar(&p, &tmp);
        while (!estaVazia(&aux) && topo(&aux, &valor) && valor > tmp) {
            desempilhar(&aux, &valor);
            empilhar(&p, valor);
        }
        empilhar(&aux, tmp);
    }

    printf("Pilha ordenada (topo para base):\n");
    while (!estaVazia(&aux)) {
        desempilhar(&aux, &valor);
        printf("%d ", valor);
    }
    printf("\n");
}

// Exercício 10: Avaliar pós-fixada
void exercicio10() {
    char expr[200];
    Pilha p;
    int i, a, b, res;
    inicializar(&p);

    printf("Digite expressão pós-fixada: ");
    scanf("%s", expr);

    for (i = 0; expr[i] != '\0'; i++) {
        if (expr[i] >= '0' && expr[i] <= '9') {
            empilhar(&p, expr[i] - '0');
        } else {
            desempilhar(&p, &b);
            desempilhar(&p, &a);
            switch (expr[i]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            empilhar(&p, res);
        }
    }

    desempilhar(&p, &res);
    printf("Resultado: %d\n", res);
}

// Exercício 12: Simetria de vetor
void exercicio12() {
    Pilha p;
    int n, valor, vetor[100], simetrico = 1;
    inicializar(&p);

    printf("Quantos números? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        empilhar(&p, vetor[i]);
    }

    for (int i = 0; i < n; i++) {
        desempilhar(&p, &valor);
        if (valor != vetor[i]) {
            simetrico = 0;
            break;
        }
    }

    if (simetrico) printf("O vetor é simétrico!\n");
    else printf("O vetor não é simétrico.\n");
}

int main() {
    int opcao;

    do {
        printf("\n===== MENU PILHA =====\n");
        printf("1 - Empilhar e Desempilhar\n");
        printf("2 - Verificar Cheia/Vazia\n");
        printf("3 - Inverter Sequência\n");
        printf("4 - Decimal para Binário\n");
        printf("5 - Palíndromo\n");
        printf("6 - Reverter Frase\n");
        printf("7 - Parênteses Balanceados\n");
        printf("8 - Desfazer/Refazer\n");
        printf("9 - Ordenar Pilha\n");
        printf("10 - Avaliar Pós-fixada\n");
        printf("12 - Simetria de Vetor\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: exercicio1(); break;
            case 2: exercicio2(); break;
            case 3: exercicio3(); break;
            case 4: exercicio4(); break;
            case 5: exercicio5(); break;
            case 6: exercicio6(); break;
            case 7: exercicio7(); break;
            case 8: exercicio8(); break;
            case 9: exercicio9(); break;
            case 10: exercicio10(); break;
            case 12: exercicio12(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}