#include <iostream> 
#define endl "\n";

using namespace std;

void bubbleSort(int arr[], int sz) {
    for(int i = 0; i < sz-1; i++) {
        for(int j = 0; j < sz-i-1; j++) {
            if(arr[j] >= arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printArr(int arr[], int sz) {
    cout << "[";
    if(sz != 0) {
        for(int i = 0; i < sz-1; i++) {
            cout << arr[i] << ", ";
        }
        cout << arr[sz-1];
    }
    cout << "]";
}

int main() {
    ios_base::sync_with_stdio(false);
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int arraySize = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, arraySize);
    printArr(arr, arraySize);
    return 0;
}