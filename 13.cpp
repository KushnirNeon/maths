#include <iostream>
#include <vector>
using namespace std;

void calculateCoefficients(vector<double>& x, vector<double>& y, vector<vector<double>>& f) {
    int n = x.size();
    for(int i=0;i<n;i++) f[i][0]=y[i];
    for(int i=1;i<n;i++)
        for(int j=0;j<n-i;j++)
            f[j][i] = (f[j+1][i-1]-f[j][i-1])/(x[i+j]-x[j]);
}

void printNewtonPolynomial(vector<double>& x, vector<vector<double>>& f) {
    int n = x.size();
    cout << "P(x) = " << f[0][0];
    for(int i=1;i<n;i++){
        if(f[0][i]!=0){
            cout << " + " << f[0][i];
            for(int j=0;j<i;j++) cout << " * (x - " << x[j] << ")";
        }
    }
    cout << endl;
}

int main() {
    vector<double> x={0,1,2,3,4};
    vector<double> y={3,12,579,7536,49155};
    int n = x.size();
    vector<vector<double>> f(n, vector<double>(n));
    calculateCoefficients(x,y,f);
    printNewtonPolynomial(x,f);
    return 0;
}
