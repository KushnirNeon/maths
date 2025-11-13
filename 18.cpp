#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) { return 2*pow(x,7)+3*pow(x,6)+4*pow(x,5)+3; }

double trapezoidal_rule(double a,double b,int n){
    double h=(b-a)/n, sum=f(a)+f(b);
    for(int i=1;i<n;i++) sum+=2*f(a+i*h);
    return (h/2)*sum;
}

double simpson_rule(double a,double b,int n){
    if(n%2!=0){ cout<<"n має бути парним для формули Сімпсона. Збільшуємо n на 1.\n"; n++; }
    double h=(b-a)/n, sum=f(a)+f(b);
    for(int i=1;i<n;i++){
        double x=a+i*h;
        sum+= (i%2==0? 2*f(x) : 4*f(x));
    }
    return (h/3)*sum;
}

int main(){
    double a=0.0,b=4.0;
    int n=10;
    double trapezoidal_result = trapezoidal_rule(a,b,n);
    cout<<"Наближене значення інтеграла за формулою трапецій: "<<fixed<<setprecision(6)<<trapezoidal_result<<endl;
    double simpson_result = simpson_rule(a,b,n);
    cout<<"Наближене значення інтеграла за формулою Сімпсона: "<<fixed<<setprecision(6)<<simpson_result<<endl;
    return 0;
}
