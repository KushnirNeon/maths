#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <Eigen/Dense>
using namespace std;

const double ACCURACY = 1e-4;
const int MAX_ITER = 1000;

vector<double> simpleIterationMethod(const Eigen::MatrixXd& A, const Eigen::VectorXd& b) {
    int n = A.rows();
    vector<double> x(n, 0.0), x_new(n, 0.0), diff(n, 0.0);
    for (int k = 0; k < MAX_ITER; k++) {
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++)
                if (i != j) sum += A(i, j) * x[j];
            x_new[i] = (b[i] - sum) / A(i,i);
        }
        for (int i = 0; i < n; i++) diff[i] = x_new[i] - x[i];
        if (sqrt(inner_product(diff.begin(), diff.end(), diff.begin(), 0.0)) < ACCURACY) break;
        x = x_new;
    }
    return x;
}

double second_norm(const Eigen::MatrixXd& A) {
    Eigen::VectorXcd eigenvalues = (A.transpose()*A).eigenvalues();
    return sqrt(eigenvalues.real().maxCoeff());
}

double conditionNumber(const Eigen::MatrixXd& A, const Eigen::MatrixXd& A_inv) {
    return second_norm(A) * second_norm(A_inv);
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

    Eigen::MatrixXd A_inv = A.inverse();
    cout << "Inverse matrix:\n" << A_inv << endl << endl;

    vector<double> solution = simpleIterationMethod(A,b);
    cout << "Roots:\n";
    for(auto val: solution) cout << val << endl;

    double cond_num = conditionNumber(A, A_inv);
    cout << "Condition number: " << cond_num << endl;
    return 0;
}
