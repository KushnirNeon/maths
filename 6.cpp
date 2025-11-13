#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <algorithm>
using namespace std;

const double EPS = 1e-3;

int signum(double a) {
    if (a < 0) return -1;
    if (a == 0) return 0;
    return 1;
}

// Second norm of a matrix
double second_norm(Eigen::MatrixXd A) {
    Eigen::VectorXcd eigenvalues = (A.transpose() * A).eigenvalues();
    double eigenval[3] = { eigenvalues[0].real(), eigenvalues[1].real(), eigenvalues[2].real() };
    double maxeigenvalue = *max_element(eigenval, eigenval + 3);
    return sqrt(maxeigenvalue);
}

// Transpose of matrix
void matrixTranspose(double A[][3], double AT[][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            AT[i][j] = A[j][i];
}

// Multiply matrices
void matrixMultiplication(double a[][3], double b[][3], double c[][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

// Check if symmetric
bool matrixSymetric(double A[][3], double AT[][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (A[i][j] != AT[i][j])
                return false;
    return true;
}

// Condition number
double cond_number(double b[][3]) {
    Eigen::MatrixXd a(3, 3);
    a << b[0][0], b[0][1], b[0][2],
         b[1][0], b[1][1], b[1][2],
         b[2][0], b[2][1], b[2][2];
    return second_norm(a) * second_norm(a.inverse());
}

int main() {
    double a[3][3] = { {1, 2, 0}, {2, 2, 3}, {0, 3, 2} };
    double b[3] = {5, 15, 12};

    double aT[3][3];
    matrixTranspose(a, aT);

    if (!matrixSymetric(a, aT)) {
        cout << "Method is not appliable";
        return 0;
    }

    // Compute D and S
    double d11 = signum(a[0][0]);
    double s11 = sqrt(fabs(a[0][0]));
    double s12 = a[0][1] / d11 / s11;
    double s13 = a[0][2] / d11 / s11;

    double d22 = signum(a[1][1] - s12 * s12 * d11);
    double s22 = sqrt(fabs(a[1][1] - s12 * s12 * d11));
    double s23 = (a[1][2] - s12 * d11 * s13) / (d22 * s22);

    double d33 = signum(a[2][2] - s13 * s13 * d11 - s23 * s23 * d22);
    double s33 = sqrt(fabs(a[2][2] - s13 * s13 * d11 - s23 * s23 * d22));

    double S[3][3] = { { s11, s12, s13 }, { 0, s22, s23 }, { 0, 0, s33 } };
    double D[3][3] = { {d11, 0, 0}, {0, d22, 0}, {0, 0, d33} };

    double ST[3][3], STD[3][3];
    matrixTranspose(S, ST);
    matrixMultiplication(ST, D, STD);

    // Gaussian backward substitution
    double y1 = b[0] / STD[0][0];
    double y2 = (b[1] - STD[1][0] * y1) / STD[1][1];
    double y3 = (b[2] - STD[2][0] * y1 - STD[2][1] * y2) / STD[2][2];

    double x3 = y3 / S[2][2];
    double x2 = (y2 - S[1][2] * x3) / S[1][1];
    double x1 = (y1 - S[0][1] * x2 - S[0][2] * x3) / S[0][0];

    cout <<"Roots: "<< endl <<"x[1] = "<< x1 << endl <<"x[2] = "<< x2 << endl <<"x[3] = "<< x3 << endl;

    double det = d11 * s11 * s11 * d22 * s22 * s22 * d33 * s33 * s33;
    cout <<"Determinant: "<< det << endl;
    cout <<"Condition number: "<< cond_number(a) << endl;
    return 0;
}
