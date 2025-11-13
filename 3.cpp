#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return (x - 1) * (x - 1) - 0.5 * exp(x);
}

double chord(double x_prev, double x_i, double e) {
    double x_next = 0;
    double tmp;
    do {
        tmp = x_next;
        x_next = x_i - f(x_i) * (x_prev - x_i) / (f(x_prev) - f(x_i));
        x_prev = x_i;
        x_i = tmp;
    } while (fabs(x_next - x_i) > e);
    return x_next;
}

int main() {
    double x0 = 0;
    double x1 = 1;
    double e = 0.000001;
    double x = chord(x0, x1, e);
    cout << x;
    return 0;
}
