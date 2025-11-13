#include <iostream>
#include <cmath>
#include <Eigen/Dense>
using namespace std;

const double EPS = 1e-3;

int main() {
    Eigen::Matrix4d a;
    a << 4, 0, 1, 0,
         0, 3, 0, 2,
         1, 0, 5, 1,
         0, 2, 1, 4;

    double tau = 0.1;
    Eigen::Vector4d b { 12, 19, 27, 30 };
    Eigen::Vector4d x { 0, 0, 0, 0 };
    Eigen::Vector4d x_new = x;
    int i = 0;

    do {
        x_new = x - tau * (a * x - b);
        if ((x_new - x).norm() < EPS) break;
        x = x_new;
        i++;
    } while (true);

    cout << "x[1] = " << x[0] << endl;
    cout << "x[2] = " << x[1] << endl;
    cout << "x[3] = " << x[2] << endl;
    cout << "x[4] = " << x[3] << endl;
    return 0;
}
