#include <stdio.h>
#include <string.h>

int read_combo_as_int() {
    char s[5];
    for (int i = 0; i < 4; ++i) {
        if (scanf("%1s", &s[i]) != 1) return -1; 
    }
    return (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
}

int bfs(int start, int target, unsigned char forbidden[]) {
    if (forbidden[start] || forbidden[target]) return -1;
    if (start == target) return 0;

    int q[10000], head = 0, tail = 0;
    int dist[10000];
    for (int i = 0; i < 10000; ++i) dist[i] = -1;

    q[tail++] = start;
    dist[start] = 0;

    while (head < tail) {
        int cur = q[head++];
        int dcur = dist[cur];

        int digs[4] = {
            (cur / 1000) % 10,
            (cur / 100) % 10,
            (cur / 10) % 10,
            cur % 10
        };

        for (int i = 0; i < 4; ++i) {
            int orig = digs[i];
            for (int k = 0; k < 2; ++k) {
                int nd = (k == 0) ? (orig + 1) % 10 : (orig + 9) % 10;
                int place = (i == 0) ? 1000 : (i == 1) ? 100 : (i == 2) ? 10 : 1;
                int nxt = cur - orig * place + nd * place;

                if (dist[nxt] == -1 && !forbidden[nxt]) {
                    if (nxt == target) return dcur + 1;
                    dist[nxt] = dcur + 1;
                    q[tail++] = nxt;
                }
            }
        }
    }
    return -1;
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    for (int tc = 0; tc < T; ++tc) {
        int start = read_combo_as_int();
        int target = read_combo_as_int();

        int m;
        if (scanf("%d", &m) != 1) m = 0;

        unsigned char forbidden[10000] = {0};

        for (int i = 0; i < m; ++i) {
            int f = read_combo_as_int();
            if (f >= 0 && f < 10000) forbidden[f] = 1;
        }

        printf("%d\n", bfs(start, target, forbidden));
    }
    return 0;
}