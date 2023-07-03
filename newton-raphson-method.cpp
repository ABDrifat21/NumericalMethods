#include<bits/stdc++.h>

using namespace std;

// Define your function here
double funct(double x) {
    return pow(x, 3) + pow(x,2) - 1; 
}

// Define the derivative of your function here
double derivative(double x) {
    return (3 * pow(x, 2)) + (2*x); // Example derivative: f'(x) = 2x
}

double newtonRaphson(double x0, double epsilon, int maxIterations) {
    double x = x0;
    int iterations = 0;

    while (abs(funct(x)) > epsilon && iterations < maxIterations) {
        x = x - (funct(x) / derivative(x));
        iterations++;
    }

    return x;
}

int main() {
    double initialGuess = 1;
    double epsilon = 0.001;
    int maxIterations = 100;

    double root = newtonRaphson(initialGuess, epsilon, maxIterations);

    cout << "Approximate root: " << root << endl;

    return 0;
}
