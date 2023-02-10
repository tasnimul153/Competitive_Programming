#include <iostream> 
#include <vector> 
#define endl "\n";

using namespace std;

// To return two values from a function we use struct 
struct Pair {
    int min;
    int max; 
}; 

// Using linear search 
Pair getMinMax(vector<int> vect) {
    Pair minmax;

    // Initialize and if there is only one element 
    minmax.min = vect[0];
    minmax.max = vect[0];

    for(vector<int>::iterator it = vect.begin(); it != vect.end(); it++) {
        minmax.min = (*it < minmax.min) ? *it : minmax.min; 
        minmax.max = (*it > minmax.max) ? *it : minmax.max; 
    }

    return minmax; 
}

int main() {
    vector <int> vect = {1, 5, 6, 1, 3, -5, 8, 10, -125, 5}; 

    struct Pair minmax = getMinMax(vect);
    cout << "Minimum: " << minmax.min << "\nMaximum: " << minmax.max << endl;

    return 0;
}