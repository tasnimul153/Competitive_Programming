#include <iostream>
#define endl '\n'

using namespace std;

void reverseArr(int arr[]) {
    int sz = sizeof(arr[0])/sizeof(arr);
    for (int i = 0; i < sz-1; i++) {
        
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    reverseArr(arr);
    for(int i : arr) 
        cout << i << " ";
    cout << endl;
    return 0;
}
