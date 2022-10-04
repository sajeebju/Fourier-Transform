#include<iostream>
#include<vector>
#include<complex>
#include<iomanip>

using namespace std;

vector<complex<double>> dft(vector<complex<double>>X){
 
 int N = X.size();
 int K = N;
 complex<double> intSum;

 vector<complex<double>> output;
 output.reserve(K);

 for(int k = 0; k < K; k++){
    intSum = complex<double>(0, 0);
    for(int n = 0; n < N; n++){
        double realPart = cos(((2*M_PI) / N) * k * n);
        double imagPart = sin(((2*M_PI) / N) * k * n);
        complex<double> w (realPart, -imagPart);
        intSum += X[n] * w;
    }
    output.push_back(intSum);
 }

}

int main(){

    int N = 1000;
    vector<complex<double>> signal;
    signal.reserve(N);

    double sigK = 3.0;
    double sigPhase = 0.0;

    for(int x = 0; x < N; ++x){
        auto currentSample = complex<double>(cos((2*M_PI / static_cast<double>(N)) * sigK * static_cast<double>(x) + sigPhase), 0.0);
       signal.push_back(currentSample);
    }

    vector<complex<double>> Fx = dft(signal);

    cout << "First 6 samples of the output......." << endl;
    cout << "\n" << "k\t" << setw(12) << "Real\t" << setw(12) << "Imag" << endl;

    for(int i = 0; i < 6; i++){

        cout << i << "\t" << setw(12) << Fx[i].real() / static_cast<double>(N) << "\t" <<
        setw(12) << Fx[i].imag() / static_cast<double>(N) << endl;
    }
return 0;
}