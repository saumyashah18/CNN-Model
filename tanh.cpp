#include <iostream>
#include <cmath>
using namespace std;

// function to create tanh function to work on values...

double tanh (double x){
    return (exp(x) - exp(-x))/(exp(x) + exp(-x));
}

int main(){

    double input;

    cout<< "Enter your value ---> ";
    cin >> input;

    double output = tanh(input);
    cout << " Your outputt of the "<< input << " --->> " << output << endl;

    return 0; 
}
