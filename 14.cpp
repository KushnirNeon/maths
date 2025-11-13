#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

double f(double x) { return 2*pow(x,7)+3*pow(x,6)+4*pow(x,5)+3; }

double quadraticSpline(double x) {
    if(x>=0 && x<=2) return 3+144*pow(x,2);
    else if(x>2 && x<=4) return 46851-46848*x+11856*pow(x,2);
    else return 0;
}

int main() {
    double step=0.1;
    vector<double> x_values;
    for(double x=0;x<=4;x+=step) x_values.push_back(x);

    double maxDeviationQuadratic=0;
    for(double x : x_values) {
        double fx=f(x);
        double quadraticVal=quadraticSpline(x);
        maxDeviationQuadratic=max(maxDeviationQuadratic, abs(fx-quadraticVal));
    }
    cout << maxDeviationQuadratic;
    return 0;
}
