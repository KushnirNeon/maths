#include <iostream>
#include <cmath>
#include <Eigen/Dense>
using namespace std;

const double EPS = 1e-3;

int main() {
    Eigen::Matrix4d a;
    a << 7, 2, 3, 0,
         0, 3, 2, 6,
         2, 5, 1, 0,
         0, 1, 4, 2;

    double tau = 0.1;
    Eigen::Vector4d b { 20, 36, 15, 22 };
    Eigen::Vector4d x { 0, 0, 0, 0 };
    Eigen::Vector4d x_new = x;
    int i = 0;

    do {
        x_new = x - tau * (a * x - b);
        if ((x_new - x).norm() < EPS) break;
        x = x_new;
        i++;
    } while (true);

    cout <<"x[1] = "<< x[0] << endl;
    cout <<"x[2] = "<< x[1] << endl;
    cout <<"x[3] = "<< x[2] << endl;
    cout <<"x[4] = "<< x[3] << endl;
    return 0;
}
