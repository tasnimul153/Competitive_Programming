#include <iostream>
// endl makes program runs slower as it inserts a new line 
// but also flushes the stream each time  
#define endl "\n"; 

using namespace std;

/**In this functon we will compare left half and right half of the
 * sub arrays and merge them. For that firstly, we will calculate 
 * size of the left and right sub arrays and then we will create two 
 * temporary arrays and copy each element of the original array
 * into those two temporary arrays who are acting as left and right 
 * halves. Lastly, we will set iterative variables of both halves of
 * the arrays and also for the original array so that we can start 
 * the compare and replace operation. In terms of divide and conquer
 * this the part when we conquer our result. */
void merge(int arr[], int left, int middle, int right) {
    // Calculating the size of both halves, If we have three elements in 
    // the left side and two elements in the right side then 
    // leftSub_size = (4/2) - 0 + 1 
    //              = 2 - 0 + 1
    //              = 3 
    int const leftSub_size = middle - left + 1;
    // rightSub_size = 4 - ((4/2)) 
    //               = 4 - 2 
    //               = 2
    int const rightSub_size = right - middle;
    // Declare left sub-array based on the calculated size
    int * leftSubArr = new int[leftSub_size];
    // Declare right sub-array based on the calculated size 
    int * rightSubArr = new int[rightSub_size];

    // Copy elements to left sub-array
    for(int i = 0; i < leftSub_size; i++)
        leftSubArr[i] = arr[left + i];
    // Copy elements to right sub-array 
    for(int i = 0; i < rightSub_size; i++) 
        rightSubArr[i] = arr[middle + i + 1];

    // Define iterative variables for left, right, and original array 
    int leftSub_it = 0, rightSub_it = 0, mergedArr_it = left;

    // Run the loop until we reach to the end of left or right sub-array
    // Here, the compare and merge operation is occuring 
    while(leftSub_it < leftSub_size && rightSub_it < rightSub_size) {
        // if element from the left sub-array is equal or smaller than 
        // the element from the right sub-array then replace the original
        // array element with the left sub-array element 
        if(leftSubArr[leftSub_it] <= rightSubArr[rightSub_it]) {
            // Replace the original array element with left sub-array
            arr[mergedArr_it] = leftSubArr[leftSub_it];
            leftSub_it++;
        // if element from the left sub-array is larger than 
        // the element from the right sub-array then replace the original
        // array element with the right sub-array element 
        } else {
            // Replace the original array element with right sub-array
            arr[mergedArr_it] = rightSubArr[rightSub_it];
            rightSub_it++;
        }
        mergedArr_it++;
    }

    // if there is no element exist to replace in the right sub-array 
    // then replace the uniterated elements of the original array with 
    // the elements of left sub-array
    while(leftSub_it < leftSub_size) {
        arr[mergedArr_it] = leftSubArr[leftSub_it];
        leftSub_it++;
        mergedArr_it++;
    }

    // if there is no element exist to replace in the left sub-array 
    // then replace the uniterated elements of the original array with 
    // the elements of right sub-array
    while(rightSub_it < rightSub_size) {
        arr[mergedArr_it] = rightSubArr[rightSub_it];
        rightSub_it++;
        mergedArr_it++;
    }

    // Lastly, delete those temporary arrays
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
    // right sub arrays. For example, when we have one value in the right array
    // and that value's index is 7 that means we are passing 
    // ([4], 6 + 1, 7) means (middle + 1) >= (right) or (6+1) >= (7)
    // So we will stop the recursion and return.
    if(left >= right)
        return;
    // Calculating the middle. E.g: If we have 5 elements in the array
    // from index 0...4 then middle = (0 + 4) / 2 = 2 so, middle = 2
    int middle = (left + right) / 2;
    
    // Our intention is to divide the array into two halves logically 
    // for that we first calculate the middle index and left halve 
    // of the array would be from [left = 0...middle] and right halve would
    // be from [middle + 1...right = array_size-1]
    // So, passing the left half of the array from 0...middle
    mergeSort(arr, left, middle); 
    // passing the right half of the array from middle + 1...array_size
    mergeSort(arr, middle + 1, right);
    // After getting out of recursive operation we are going to 
    // compare and merge both left and right sub arrays
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