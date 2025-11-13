#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) { return 2*pow(x,7)+3*pow(x,6)+4*pow(x,5)+3; }

vector<double> compute_weights(const vector<double>& nodes) {
    int n=nodes.size();
    vector<double> weights(n,0.0);
    for(int i=0;i<n;i++){
        double weight=0.0;
        for(double x=0; x<=4.0; x+=0.001){
            double a=1.0;
            for(int j=0;j<n;j++) if(i!=j) a*=(x-nodes[j])/(nodes[i]-nodes[j]);
            weight+=a*0.001;
        }
        weights[i]=weight;
    }
    return weights;
}

double compute_approx_integral(const vector<double>& nodes, const vector<double>& weights){
    double integral=0.0;
    for(int i=0;i<nodes.size();i++) integral+=weights[i]*f(nodes[i]);
    return integral;
}

int main() {
    vector<double> nodes={0,1,2,3,4};
    vector<double> weights = compute_weights(nodes);

    cout << "Квадратурна формула:\n";
    for(int i=0;i<nodes.size();i++){
        if(i>0) cout<<" + ";
        cout << fixed << setprecision(4) << weights[i] << " * f(" << nodes[i] << ")";
    }
    cout << endl;

    double approx_integral = compute_approx_integral(nodes,weights);
    cout << "Наближене значення інтеграла: " << approx_integral << endl;
    return 0;
}
