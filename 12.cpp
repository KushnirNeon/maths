#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double f(double x) {
    return 2*pow(x,7) + 3*pow(x,6) + 4*pow(x,5) + 3;
}

double newtonPolynomial(double x) {
    return 3 - 3936*x + 7648*pow(x,2) - 4638*pow(x,3) + 935*pow(x,4);
}

int main() {
    double step = 0.1;
    vector<double> x_values;
    for(double x=0; x<=4; x+=step) x_values.push_back(x);

    double maxDeviationNewton=0;
    for(double x : x_values) {
        double fx = f(x);
        double newtonVal = newtonPolynomial(x);
        maxDeviationNewton = max(maxDeviationNewton, abs(fx-newtonVal));
    }
    cout << maxDeviationNewton;
    return 0;
}
