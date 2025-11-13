#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) { return x + y; }

int main() {
    double x0=0, y0=1, X=1, h=0.1;
    while (x0 < X) {
        double k1 = h*f(x0, y0);
        double k2 = h*f(x0+h/2, y0+k1/2);
        double k3 = h*f(x0+h/2, y0+k2/2);
        double k4 = h*f(x0+h, y0+k3);
        y0 += (k1+2*k2+2*k3+k4)/6;
        x0 += h;
        cout <<"x="<< x0 <<" y="<< y0 << endl;
    }
    return 0;
}
