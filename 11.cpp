#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<double> F(double x, double y) {
    return { sin(x-0.6)-y-1.6, 3*x-cos(y)-0.9 };
}

vector<vector<double>> jacobi(double x, double y) {
    return { {cos(x-0.6), -1}, {3, sin(y)} };
}

vector<vector<double>> inverseJacobi(const vector<vector<double>>& J) {
    double detJ = J[0][0]*J[1][1] - J[0][1]*J[1][0];
    return { { J[1][1]/detJ, -J[0][1]/detJ }, { -J[1][0]/detJ, J[0][0]/detJ } };
}

void modifiedNewton(double x0, double y0, double precision=1e-6) {
    double x=x0, y=y0, x_prev, y_prev;
    int iter=0;
    while(true) {
        x_prev=x; y_prev=y;
        vector<vector<double>> J = jacobi(x,y);
        vector<vector<double>> J_inv = inverseJacobi(J);
        vector<double> F_val = F(x,y);
        double dx = -(J_inv[0][0]*F_val[0] + J_inv[0][1]*F_val[1]);
        double dy = -(J_inv[1][0]*F_val[0] + J_inv[1][1]*F_val[1]);
        x += dx; y += dy;
        iter++;
        cout << "Ітерація " << iter << ": x = " << x << ", y = " << y << endl;
        if (sqrt((x-x_prev)*(x-x_prev) + (y-y_prev)*(y-y_prev)) < precision) break;
    }
    cout << "Розв'язок знайдено: x = " << x << ", y = " << y << endl;
}

int main() {
    double x0=0.0, y0=0.5;
    modifiedNewton(x0,y0);
    return 0;
}
