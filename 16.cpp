#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double f(double x) { return 2*pow(x,7)+3*pow(x,6)+4*pow(x,5)+3; }

int main() {
    double start=0.0, end=4.0, step=0.5;
    vector<double> x, y;
    for(double i=start;i<=end;i+=step) { x.push_back(i); y.push_back(f(i)); }

    for(size_t i=0;i<x.size()-1;i++){
        double slope=(y[i+1]-y[i])/(x[i+1]-x[i]);
        cout << "S" << i << "(x) = " << y[i] << " + " << slope << " * (x - " << x[i] << ")" << endl;
    }
    return 0;
}
