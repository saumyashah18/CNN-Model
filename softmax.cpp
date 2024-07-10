#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Function to calculate softmax functionn.....

vector<double> softmax(const vector<double>& input){
       vector<double> result(input.size());
       double max_Elem = *max_element(input.begin(), input.end());
       double sum = 0.0;

       //compute the sum of exponents

       for (double val : input){
         sum = sum + exp(val - max_Elem);
       }

       //computee the softmax valuesss...

       for(size_t i = 0;i < input.size(); ++i){
        result[i] = exp(input[i] - max_Elem) / sum;
        }

        return result;
}

int main(){
    int n;

    cout<< " Enter the number of elementss you want ---> ";
    cin>>n;

    vector<double> input(n);

    cout<<"Enter your elements you want your softmax function to work on --> ";
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
     // Compute the softmax values...

    vector<double> result = softmax(input); 

    // Display the softmax values..

    cout << "Softmax values: ";
    for (double val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

