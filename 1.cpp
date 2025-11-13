#include <iostream>
#include <cmath>
using namespace std;

double func(double x) {
    return pow(x, 3) - 7 * pow(x, 2) + 7 * x + 15;
}

double deriv(double x) {
    return 3 * pow(x, 2) - 14 * x + 7;
}

int main() {
    double a = 4.5, b = 5.5;
    double eps = 0.001;
    double x = a;

    cout << "Enter the precision, or enter 0 to use the default value" << endl;
    double prec;
    cin >> prec;
    if (prec) {
        eps = prec;
    }

    cout << "Iteration #1 " << x << " " << func(x) << endl;

    for (int i = 0; abs(func(x)) > eps; i++) {
        x = x - (func(x) / deriv(x));
        cout << "Iteration #" << i + 2 << " " << x << " " << func(x) << endl;
    }
    return 0;
}
