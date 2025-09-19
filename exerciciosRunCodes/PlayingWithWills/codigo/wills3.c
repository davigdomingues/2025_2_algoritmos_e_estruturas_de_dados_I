#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define N 10000   // total de estados possíveis

typedef struct {
    int v;
    int dist;
} Node;

typedef struct {
    Node heap[N+5];
    int size;
} MinHeap;

void swap(Node *a, Node *b) {
    Node t = *a; *a = *b; *b = t;
}

void heapify_up(MinHeap *h, int idx) {
    while (idx > 1 && h->heap[idx].dist < h->heap[idx/2].dist) {
        swap(&h->heap[idx], &h->heap[idx/2]);
        idx /= 2;
    }
}

void heapify_down(MinHeap *h, int idx) {
    int smallest = idx;
    int l = 2*idx, r = 2*idx+1;
    if (l <= h->size && h->heap[l].dist < h->heap[smallest].dist) smallest = l;
    if (r <= h->size && h->heap[r].dist < h->heap[smallest].dist) smallest = r;
    if (smallest != idx) {
        swap(&h->heap[idx], &h->heap[smallest]);
        heapify_down(h, smallest);
    }
}

void push(MinHeap *h, int v, int dist) {
    h->heap[++h->size].v = v;
    h->heap[h->size].dist = dist;
    heapify_up(h, h->size);
}

Node pop(MinHeap *h) {
    Node top = h->heap[1];
    h->heap[1] = h->heap[h->size--];
    heapify_down(h, 1);
    return top;
}

int empty(MinHeap *h) {
    return h->size == 0;
}

int read_combo_as_int() {
    char s[5];
    for (int i = 0; i < 4; i++) {
        if (scanf("%1s", &s[i]) != 1) return -1;
    }
    return (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
}

int dijkstra(int start, int target, unsigned char forbidden[]) {
    if (forbidden[start] || forbidden[target]) return -1;

    int dist[N];
    for (int i = 0; i < N; i++) dist[i] = INT_MAX;
    dist[start] = 0;

    MinHeap h = { .size = 0 };
    push(&h, start, 0);

    while (!empty(&h)) {
        Node cur = pop(&h);
        int u = cur.v;
        int dcur = cur.dist;

        if (u == target) return dcur;
        if (dcur > dist[u]) continue; // já temos melhor

        // pega dígitos
        int digs[4] = {
            (u / 1000) % 10,
            (u / 100) % 10,
            (u / 10) % 10,
            u % 10
        };

        // tenta girar cada dígito
        for (int i = 0; i < 4; i++) {
            int orig = digs[i];
            for (int k = 0; k < 2; k++) {
                int nd = (k == 0) ? (orig + 1) % 10 : (orig + 9) % 10;
                int place = (i == 0) ? 1000 : (i == 1) ? 100 : (i == 2) ? 10 : 1;
                int nxt = u - orig * place + nd * place;

                if (!forbidden[nxt] && dist[nxt] > dcur + 1) {
                    dist[nxt] = dcur + 1;
                    push(&h, nxt, dist[nxt]);
                }
            }
        }
    }

    return -1; // impossível
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int start = read_combo_as_int();
        int target = read_combo_as_int();

        int m;
        scanf("%d", &m);

        unsigned char forbidden[N] = {0};
        for (int i = 0; i < m; i++) {
            int f = read_combo_as_int();
            if (f >= 0 && f < N) forbidden[f] = 1;
        }

        printf("%d\n", dijkstra(start, target, forbidden));
    }

    return 0;
}