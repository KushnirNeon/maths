#include <iostream>
#include <cmath>
using namespace std;

double func(double x) {
    return pow(x, 3) - 5 * pow(x, 2) - 4 * x + 20;
}

double root(double x) {
    return pow((5 * pow(x, 2) + 4 * x - 20), 1./3.);
}

int main() {
    double xn1, xn = 4.75;
    double eps = 0.001;

    cout << "Enter the precision, or enter 0 to use the default value" << endl;
    double prec;
    cin >> prec;
    if (prec) {
        eps = prec;
    }

    int i = 1;
    while (1) {
        xn1 = root(xn);
        if (abs(xn1 - xn) < eps) {
            break;
        }
        xn = xn1;
        cout << i << " iteration " << xn1 << " " << func(xn1) << endl;
        i++;
    }
    return 0;
}
