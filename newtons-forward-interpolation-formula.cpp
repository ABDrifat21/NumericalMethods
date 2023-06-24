#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> xValues = {3, 5, 7, 9};   // new x values
    vector<double> fValues = {180, 150, 120, 90};   // new corresponding f(x) values

    double x = 4;  // the value of x for which we want to find f(x)

    int n = xValues.size();
    double h = xValues[1] - xValues[0];  // Assuming equal spacing, so h is constant.

    double result = fValues[0];
    double term = (x - xValues[0]) / h;

    for (int i = 1; i < n; i++) {
        double termMultiplier = term;
        for (int j = 1; j <= i; j++) {
            termMultiplier *= (term - j) / (j + 1);
        }
        result += termMultiplier * fValues[i];
    }

    cout << "Interpolated value at x = " << x << " is: " << result << endl;

    return 0;
}
