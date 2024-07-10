#include <iostream>
using namespace std;

// Function to calculate ReLU for a single value.....

double ReLU(double x) {
    return x > 0 ? x : 0;
}

int main() {
    double input;

    cout << "Enter a number ----> ";
    cin >> input;

    // Calculate the ReLU of the input
    double output = ReLU(input);

    // Print the result
    cout << "ReLU" << input << " ---> "<< output << endl;

    return 0;
}