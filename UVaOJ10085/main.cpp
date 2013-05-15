#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 1000000;
char input[30];
int state[9], goal[9] = {1, 2, 3, 8, 0, 4, 7, 6, 5};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char path_dir[5] = "UDLR";
int st[MAXN][9];
int father[MAXN], path[MAXN], ans;
const int MAXHASHSIZE = 1000003;
int head[MAXHASHSIZE], next[MAXN];
void init_lookup_table() {
    memset(head, 0, sizeof(head));
}
typedef int State[9];
int hash(State &s) {
    int v = 0;
    for (int i = 0; i < 9; i ++) {
        v = v * 10 + s[i];
    }
    return v % MAXHASHSIZE;
}
int try_to_insert(int s) {
    int h = hash(st[s]);
    int u = head[h];
    while (u) {
        if (memcmp(st[u], st[s], sizeof(st[s])) == 0) return 0;
        u = next[u];
    }
    next[s] = head[h];
    head[h] = s;
    return 1;
}
void bfs() {
    init_lookup_table();
    father[0] = path[0] = -1;
    int front = 0, rear = 1;
    memcpy(st[0], state, sizeof(state));
    try_to_insert(0);
    while (front < rear) {
        int *s = st[front];
        int j;
        for (j = 0; j < 9; j ++) {
            if (! s[j]) {
                break;
            }
        }
        int x = j / 3, y = j % 3;
        for (int i = 0; i < 4; i ++) {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            int pos = dx * 3 + dy;
            if (dx >= 0 && dx < 3 && dy >= 0 && dy < 3) {
                int *newState = st[rear];
                memcpy(newState, s, sizeof(int) * 9);
                newState[j] = s[pos];
                newState[pos] = 0;
                if (try_to_insert(rear)) {
                    father[rear] = front;
                    path[rear] = i;
                    rear ++;
                }
            }
        }
        front ++;
    }
    ans = rear - 1;
}
void print_path(int cur) {
    if (cur != 0) {
        print_path(father[cur]);
        printf("%c", path_dir[path[cur]]);
    }
}
int main()
{
    int T, cas = 1;
    scanf("%d", &T);
    while (T --) {
        for (int i = 0; i < 9; i ++) {
            scanf("%d", &state[i]);
        }
        bfs();
        printf("Puzzle #%d\n", cas ++);
        for (int i = 0; i < 3; i ++) {
            printf("%d %d %d\n", st[ans][i * 3], st[ans][i * 3 + 1], st[ans][i * 3 + 2]);
        }
        print_path(ans);
        printf("\n\n");
    }
    return 0;
}
