#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-3;

// Functions
double f1(double x3) { return (12 - x3) / 4.0; }
double f2(double x4) { return (19 - 2 * x4) / 3.0; }
double f3(double x1, double x4) { return (27 - x1 - x4) / 5.0; }
double f4(double x2, double x3) { return (30 - 2*x2 - x3) / 4.0; }

int main() {
    double x[4] = {0,0,0,0};
    double x0, x1, x2, x3;
    double e[4], E;
    int i = 1;

    do {
        x0 = f1(x[2]);
        x1 = f2(x[3]);
        x2 = f3(x0, x[3]);
        x3 = f4(x1, x2);

        cout << i << ": " << x0 << " " << x1 << " " << x2 << " " << x3 << endl;

        e[0] = fabs(x[0] - x0);
        e[1] = fabs(x[1] - x1);
        e[2] = fabs(x[2] - x2);
        e[3] = fabs(x[3] - x3);
        E = sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2] + e[3]*e[3]);

        x[0] = x0; x[1] = x1; x[2] = x2; x[3] = x3;
        i++;
    } while(E > EPS);

    cout <<"x[1] = "<< x0 << endl <<"x[2] = "<< x1 << endl <<"x[3] = "<< x2 << endl <<"x[4] = "<< x3 << endl;
    return 0;
}
