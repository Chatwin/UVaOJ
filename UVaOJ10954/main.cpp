#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

struct Node {
    int x;
    bool operator < (const Node &a) const {
        return x > a.x;
    }
}num;
int n, sum, tmp;
priority_queue<Node> pq;
int main() {
    while (scanf("%d", &n)) {
        if (n == 0) break;
        sum = 0;
        while (! pq.empty()) pq.pop();
        for (int i = 0; i < n; i ++) {
            scanf("%d", &num.x);
            pq.push(num);
        }
        while (! pq.empty()) {
            Node num1, num2;
            num1 = pq.top();
            pq.pop();
            num2 = pq.top();
            pq.pop();
            tmp = num1.x + num2.x;
            sum += tmp;
            num.x = tmp;
            if (! pq.empty()) pq.push(num);
        }
        printf("%d\n", sum);
    }
    return 0;
}
