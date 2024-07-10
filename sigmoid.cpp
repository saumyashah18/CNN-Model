#include <iostream>
#include <cmath>
using namespace std;

//Function to compute the sigmoid function for the value...

double sigmoid (double x){
    return 1/(1+ exp(-x));
}

int main(){
    double input;

     cout << "Enter the number you wanna input ---> ";
     cin >> input;

     double output = sigmoid(input);
     cout << " Your output sigmoid " << input << " ---> "<< output <<  endl;

     return 0;
}