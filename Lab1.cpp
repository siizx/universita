#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double factorial(int n) { 
    double fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double taylorSeries(double x, int N) {
    double sum = 0;
    for(int n = 0; n <= N; n++) {
        sum += pow(x, n) / factorial(n);
    }
    return sum;
}

double machineEpsilon(bool singlePrecision) { // singlePrecision = true -> single precision, singlePrecision = false -> double precision
    if(singlePrecision) {
        float eps = 1.0f;                     // 1.0f = 1.0 in single precision
        while ((float)(1.0 + (eps / 2.0)) != 1.0) {  
            eps /= 2.0; 
        }
        return eps;
    } else {
        double eps = 1.0;
        while ((double)(1.0 + (eps / 2.0)) != 1.0) {  //
            eps /= 2.0;
        }
        return eps;
    }
}

int main() {
    int d0 = 5;
    int d1 = 8;
    const int MAX_INDEX = 6;
    double A[MAX_INDEX];

    double b = (d1+1)*(pow(10,20));

    double c = -b;

    for (int i = 0; i<=MAX_INDEX; ++i)
    {
        A[i] = (d0+1) * (pow(10,i));
        cout << A[i] << endl;

        cout << "Ripetizione n." << i << ":\n";

        cout << "Prima Espressione (a+b)+c : ("<< A[i] << "+" << b << "+" << c << ") "<< (A[i]+b)+c << endl;

        cout << "Seconda Espressione a+(b+c) : " << A[i]+(b+c) << endl;

    }

    double x_values[] = {0.5, 30, -0.5, -30};
    int N_values[] = {3, 10, 50, 100, 150};

    for(double x : x_values) {
        for(int N : N_values) {
            double approx = taylorSeries(x, N);
            double actual = exp(x);
            double absoluteError = abs(approx - actual);
            double relativeError = absoluteError / actual;

            cout << "x: " << x << ", N: " << N << ", Approx: " << approx << ", Actual: " << actual;
            cout << ", Absolute Error: " << absoluteError << ", Relative Error: " << relativeError << endl;
        }
    }

    cout << "Machine epsilon (single precision): " << machineEpsilon(true) << endl;
    cout << "Machine epsilon (double precision): " << machineEpsilon(false) << endl;

    return 0;
}