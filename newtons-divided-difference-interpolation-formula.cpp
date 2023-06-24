#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> xValues = {0, 2, 3, 6};   // x values
    vector<double> fValues = {648, 704, 724, 792};   // corresponding f(x) values

    double x = 4.5;  // the value of x for which we want to find f(x)

    int n = xValues.size();
    vector<double> dividedDifferences = fValues;

    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            dividedDifferences[j] = (dividedDifferences[j] - dividedDifferences[j - 1]) / (xValues[j] - xValues[j - i]);
        }
    }

    double result = dividedDifferences[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        result = dividedDifferences[i] + (x - xValues[i]) * result;
    }

    cout << "Interpolated value at x = " << x << " is: " << result << endl;

    return 0;
}
