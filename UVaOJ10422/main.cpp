#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

struct Node {
    int x, y, step;
    char map[5][5];
}p, q;
int bx, by;
int dx[] = {-1, 1, -2, 2, -1, 1, -2, 2};
int dy[] = {-2, -2, -1, -1, 2, 2, 1, 1};
char goal[5][5] = { '1','1','1','1','1',
                    '0','1','1','1','1',
                    '0','0',' ','1','1',
                    '0','0','0','0','1',
                    '0','0','0','0','0'};
struct cmp {
    bool operator() (Node a, Node b) const {
        return memcmp(a.map, b.map, 25) < 0;
    }
};
set<Node, cmp> vis;
queue<Node> Q;
void init_lookup_table() {
    while (!Q.empty()) {Q.pop();}
    vis.clear();
}
int try_to_insert(Node s) {
    if (vis.count(s)) return 0;
    vis.insert(s);
    return 1;
}
int check(int r, int c) {
    if (r >= 0 && r < 5 && c >= 0 && c < 5) {
        return 1;
    } else {
        return 0;
    }
}
void bfs(Node &p) {
    init_lookup_table();
    if (memcmp(p.map, goal, sizeof(goal)) == 0) {
        printf("Solvable in 0 move(s).\n");
        return;
    }
    Q.push(p);
    while (! Q.empty()) {
        p = Q.front();
        Q.pop();
        if (p.step >= 11) {
            printf("Unsolvable in less than 11 move(s).\n");
            return;
        }
        if (memcmp(p.map, goal, sizeof(p.map)) == 0) {
            printf("Solvable in %d move(s).\n", p.step);
            return;
        }
        for (int i = 0; i < 8; i ++) {
            q = p;
            q.x += dx[i];
            q.y += dy[i];
            q.step ++;
            if (! check(q.x, q.y)) {continue;}
            char tmp = q.map[p.x][p.y];
            q.map[p.x][p.y] = q.map[q.x][q.y];
            q.map[q.x][q.y] = tmp;
            if (try_to_insert(q)) {
                Q.push(q);
            }
        }
    }
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    getchar();
    while (T --) {
        for (int i = 0; i < 5; i ++) {
            for (int j = 0; j < 5; j ++) {
                scanf("%c", &p.map[i][j]);
                if (p.map[i][j] == ' ') {
                    bx = i;
                    by = j;
                }
            }
            getchar();
        }
        p.x = bx;
        p.y = by;
        p.step = 0;
        bfs(p);
    }
    return 0;
}
