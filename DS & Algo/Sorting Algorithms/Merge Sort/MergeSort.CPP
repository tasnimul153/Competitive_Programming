#include <iostream> 
#define endl "\n";

using namespace std;

void merge(int arr[], int left, int middle, int right) {
    
    int const leftSub_size = middle - left + 1;
    int const rightSub_size = right - middle;
    
    int * leftSubArr = new int[leftSub_size];
    int * rightSubArr = new int[rightSub_size];

    for(int i = 0; i < leftSub_size; i++)
        leftSubArr[i] = arr[left + i];
    for(int i = 0; i < rightSub_size; i++) 
        rightSubArr[i] = arr[middle + i + 1];

    int leftSub_it = 0, rightSub_it = 0, mergedArr_it = left;

    while(leftSub_it < leftSub_size && rightSub_it < rightSub_size) {
        if(leftSubArr[leftSub_it] <= rightSubArr[rightSub_it]) {
            arr[mergedArr_it] = leftSubArr[leftSub_it];
            leftSub_it++;
        } else {
            arr[mergedArr_it] = rightSubArr[rightSub_it];
            rightSub_it++;
        }
        mergedArr_it++;
    }

    while(leftSub_it < leftSub_size) {
        arr[mergedArr_it] = leftSubArr[leftSub_it];
        leftSub_it++;
        mergedArr_it++;
    }

    while(rightSub_it < rightSub_size) {
        arr[mergedArr_it] = rightSubArr[rightSub_it];
        rightSub_it++;
        mergedArr_it++;
    }

    delete leftSubArr, rightSubArr;
}

/** mergeSort function is a recursive function. In this function
 * we pass the array, the left index, and the right index. After 
 * calling this fucntion for the first time this function will call 
 * itself and recursive operation will occur. This function will 
 * divide the array into two parts (left sub array and right sub array).
 * The recursion will be executed until the arrays are in atomic value 
 * means left sub array and right sub array both has one element each. 
 * Then after that merge function will be called in order to compare
 * and merge the divided array. */
void mergeSort(int arr[], int left, int right) {
    // Stop the recursion when we have atomic values in both left and 
    // right sub array. 
    if(left >= right)
        return;
    
    int middle = (left + right) / 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);

    merge(arr, left, middle, right);
}

// This function is just to print the array 
// in a nice format + so that we don't have 
// to write the print array code everytime
void printArr(int arr[], int arrSize) {
    cout << "[";
    // No element in array means we don't have to print anything
    if(arrSize != 0) { 
        // Print each element till the second last
        // or else there will be comma (", ") printed after that
        for(int i = 0; i < arrSize-1; i++)
            cout << arr[i] << ", ";
        // Lastly print the last element of the array or only element
        cout << arr[arrSize-1];
    }
    cout << "]\n";
}

int main() {
    // Stop the synchronization between C and C++ to make the program faster
    ios_base::sync_with_stdio(false);
    // Our initial Array 
    int arr[] = {10, 9, 6, 7, 2, 5, 4, 3, 2, 1, 8};
    // Get the size of the array 
    // sizeof(arr) returns (length of array) * (total byte of arr[0] means size of int)
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    // print the initial array 
    cout << "Initial Array: ";
    printArr(arr, arrSize);
    // Sort the array and print it 
    cout << "Sorted Array: ";
    mergeSort(arr, 0, arrSize-1); // pass the array, left index, and right index
    printArr(arr, arrSize); // Pass the array and its size to print the array 
    return 0;
}