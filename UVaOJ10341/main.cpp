#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double p, q, r, s, t, u;

double f(double x) {
    double temp;
    temp = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
    return temp;
}
int main() {
    while (scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) != EOF) {
        double high = 1.0, low = 0.0, mid;
        for (int i = 0; i < 100; i ++) {
            mid = (high + low) / 2;
            if (f(mid) > 0) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (fabs(f(mid) - 0.0) < 1e-8) {
            printf("%.4lf\n", mid);
        } else {
            printf("No solution\n");
        }
    }
    return 0;
}
