#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool balanceada (char *sequencia) {
    char pilha[1010];
    int topo = 0;
    
    for (char *p = sequencia; *p != '\0'; ++p) {
        char ch = *p;
        
        if (ch == '{' || ch == '[' || ch == '(') {
            if (topo < 1010)
                pilha[topo++] = ch;
                
            else
                return false; // Garante que não haja extrapolação de leitura.
        }
        
        else if (ch == '}' || ch == ']' || ch == ')') {
            if (topo == 0)
                return false; // Garantia de que, não é balanceada, a string dada pelo usuário.
                
            char CHantecessor = pilha[topo - 1];
            
            if ((ch == '}' && CHantecessor == '{') || (ch == ']' && CHantecessor == '[') || (ch == ')' && CHantecessor == '('))
                topo--; // Processo de desempilhamento.
            
            else
                return false; // Caractere incompatível.
        }
        
        else
            return false;
    }
    
    return topo == 0;
}