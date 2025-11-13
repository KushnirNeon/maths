#include <iostream>
#include <vector>
#include <cmath>
#include <Eigen/Dense>
using namespace std;

const double EPS = 1e-4;
const int MAX_ITER = 1000;

vector<double> jacobiMethod(const Eigen::MatrixXd &A, const Eigen::VectorXd &b) {
    int n = A.rows();
    vector<double> x(n, 0.0), x_new(n, 0.0);
    for (int k = 0; k < MAX_ITER; k++) {
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++)
                if (i != j) sum += A(i,j) * x[j];
            x_new[i] = (b[i] - sum) / A(i,i);
        }
        double error = 0.0;
        for (int i = 0; i < n; i++) error += (x_new[i] - x[i]) * (x_new[i] - x[i]);
        if (sqrt(error) < EPS) break;
        x = x_new;
    }
    return x_new;
}

int main() {
    Eigen::MatrixXd A(5,5);
    A << 5.43,1.12,0.95,1.32,0.83,
         1.12,6.03,2.12,0.57,0.91,
         0.95,2.12,6.38,1.29,1.57,
         1.32,0.57,1.29,4.32,1.25,
         0.83,0.91,1.57,1.25,5.46;
    Eigen::VectorXd b(5);
    b << 8.29,3.21,2.18,6.25,7.05;

    vector<double> solution = jacobiMethod(A,b);
    cout << "Roots:\n";
    for(auto val: solution) cout << val << endl;
    return 0;
}
