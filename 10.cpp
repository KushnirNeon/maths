#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

pair<int,int> findMaxOffDiagonal(const vector<vector<double>>& A) {
    int n = A.size(); double maxVal=0.0;
    pair<int,int> indices={0,0};
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(fabs(A[i][j])>maxVal){ maxVal=fabs(A[i][j]); indices={i,j}; }
    return indices;
}

void jacobiRotation(vector<vector<double>>& A) {
    int n = A.size();
    while(true){
        auto [p,q] = findMaxOffDiagonal(A);
        double apq = A[p][q], app = A[p][p], aqq = A[q][q];
        double theta = 0.5 * atan2(2*apq, aqq-app);
        double cosTheta = cos(theta), sinTheta = sin(theta);

        for(int i=0;i<n;i++){
            double aip=A[i][p], aiq=A[i][q];
            A[i][p] = cosTheta*aip - sinTheta*aiq;
            A[p][i] = A[i][p];
            A[i][q] = sinTheta*aip + cosTheta*aiq;
            A[q][i] = A[i][q];
        }

        A[p][p] = app*cosTheta*cosTheta - 2*apq*sinTheta*cosTheta + aqq*sinTheta*sinTheta;
        A[q][q] = app*sinTheta*sinTheta + 2*apq*sinTheta*cosTheta + aqq*cosTheta*cosTheta;
        A[p][q] = A[q][p] = 0.0;

        if(fabs(apq)<1e-6) break;
    }
}

void findEigenvalues(vector<vector<double>>& A, vector<double>& eigenvalues) {
    jacobiRotation(A);
    for(int i=0;i<A.size();i++) eigenvalues.push_back(A[i][i]);
}

int main() {
    vector<vector<double>> A={{4,1,0,1},{1,3,2,0},{0,2,4,0},{1,0,0,2}};
    vector<double> eigenvalues;
    findEigenvalues(A,eigenvalues);
    for(int i=0;i<eigenvalues.size();i++)
        cout<<"Eigenvalue #"<<i+1<<": "<<eigenvalues[i]<<endl;
    return 0;
}
