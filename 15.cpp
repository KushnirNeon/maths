#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct SplineSegment { double a,b,c; };

double f(double x) { return 2*pow(x,7)+3*pow(x,6)+4*pow(x,5)+3; }
double f_derivative(double x) { return 14*pow(x,6)+18*pow(x,5)+20*pow(x,4); }

int main() {
    vector<double> x={0,2,4};
    vector<double> y={f(x[0]),f(x[1]),f(x[2])};

    vector<SplineSegment> splines(2);

    splines[0].a=y[0];
    splines[1].a=y[1];

    double f_prime_0=f_derivative(x[0]);
    splines[0].b=f_prime_0;
    splines[0].c=(y[1]-splines[0].a-splines[0].b*(x[1]-x[0]))/pow(x[1]-x[0],2);

    splines[1].b=splines[0].b+2*splines[0].c*(x[1]-x[0]);
    splines[1].c=(y[2]-splines[1].a-splines[1].b*(x[2]-x[1]))/pow(x[2]-x[1],2);

    for(int i=0;i<splines.size();i++)
        cout << "Сплайн " << i << ": a=" << splines[i].a << ", b=" << splines[i].b << ", c=" << splines[i].c << endl;
    return 0;
}
