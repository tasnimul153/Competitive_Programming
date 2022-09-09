#include <iostream>

using namespace std;

void reverseArr(int arr[]) {

}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    reverseArr(arr);
    for(int i : arr) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
