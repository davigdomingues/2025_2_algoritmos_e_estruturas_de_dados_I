#include <stdio.h>
#include <stdlib.h>

#define MAXQ 10000   // capacidade da fila = todos os estados possíveis

// Estrutura da fila
typedef struct {
    int data[MAXQ];
    int front; // indica o que será retirado
    int rear; // indica o que será adicionado
} Fila;

void inicializa(Fila *f) {
    f->front = 0;
    f->rear = 0;
}

int vazia(Fila *f) {
    return f->front == f->rear;
}

int cheia(Fila *f) {
    return (f->rear + 1) % MAXQ == f->front;
}

void enqueue(Fila *f, int x) { // função de "enfileiramento"
    if (cheia(f)) return; // aqui não deve encher porque MAXQ >= 10000
    f->data[f->rear] = x;
    f->rear = (f->rear + 1) % MAXQ;
}

int dequeue(Fila *f) { // função de "desenfileiramento"
    if (vazia(f)) return -1;
    int x = f->data[f->front];
    f->front = (f->front + 1) % MAXQ;
    return x;
}

// Lê uma combinação de 4 dígitos como inteiro (0000..9999)
int read_combo_as_int() {
    char s[5];
    for (int i = 0; i < 4; ++i) {
        if (scanf("%1s", &s[i]) != 1) return -1;
    }
    return (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
}

// BFS para encontrar menor número de passos de start até target
int bfs(int start, int target, unsigned char forbidden[]) {
    if (forbidden[start] || forbidden[target]) return -1;
    if (start == target) return 0;

    int dist[10000];
    for (int i = 0; i < 10000; i++) dist[i] = -1;

    Fila fila;
    inicializa(&fila);

    enqueue(&fila, start);
    dist[start] = 0;

    while (!vazia(&fila)) {
        int cur = dequeue(&fila);
        int dcur = dist[cur];

        // separa os 4 dígitos
        int digs[4] = {
            (cur / 1000) % 10,
            (cur / 100) % 10,
            (cur / 10) % 10,
            cur % 10
        };

        // para cada dígito, tenta girar +1 ou -1
        for (int i = 0; i < 4; i++) {
            int orig = digs[i];
            for (int k = 0; k < 2; k++) {
                int nd = (k == 0) ? (orig + 1) % 10 : (orig + 9) % 10;
                int place = (i == 0) ? 1000 : (i == 1) ? 100 : (i == 2) ? 10 : 1;
                int nxt = cur - orig * place + nd * place;

                if (dist[nxt] == -1 && !forbidden[nxt]) {
                    if (nxt == target) return dcur + 1;
                    dist[nxt] = dcur + 1;
                    enqueue(&fila, nxt);
                }
            }
        }
    }

    return -1; // impossível chegar
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int start = read_combo_as_int();
        int target = read_combo_as_int();

        int m;
        scanf("%d", &m);

        unsigned char forbidden[10000] = {0};
        for (int i = 0; i < m; i++) {
            int f = read_combo_as_int();
            if (f >= 0 && f < 10000) forbidden[f] = 1;
        }

        printf("%d\n", bfs(start, target, forbidden));
    }

    return 0;
}