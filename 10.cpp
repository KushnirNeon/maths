#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-6;
const int MAX_ITER = 100;

double f1(double x, double y) { return x*x + y*y - 4; }
double f2(double x, double y) { return x*y - 1; }

int main() {
    double x = 2.0, y = 0.5, dx, dy;
    for (int i = 0; i < MAX_ITER; i++) {
        double J[2][2] = { {2*x, 2*y}, {y, x} };
        double F[2] = { -f1(x,y), -f2(x,y) };
        double det = J[0][0]*J[1][1]-J[0][1]*J[1][0];
        dx = (F[0]*J[1][1]-F[1]*J[0][1])/det;
        dy = (J[0][0]*F[1]-J[1][0]*F[0])/det;
        x += dx; y += dy;
        if (fabs(dx)+fabs(dy) < EPS) break;
    }
    cout <<"Roots: x="<< x <<" y="<< y << endl;
    return 0;
}
