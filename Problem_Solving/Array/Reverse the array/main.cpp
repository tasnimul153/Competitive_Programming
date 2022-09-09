#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

void printArray(int arr[], int sz) {
    int i = 0;
    cout << "\n[";
    while(i < sz-1) {
       cout << arr[i] << ", "; i++; 
    }
    cout << arr[i] << "]";
}

void printVector(vector <int> vect) {
    vector<int>::iterator it;
    cout << "\n[";
    for (it = vect.begin(); it+1 != vect.end(); it++)
        cout << *it << ", ";
    cout << *it << "]";
}

// Method 1: Swap elements 
void reverse_arr(int arr[], int arr_size) {
    int i = 0, j = arr_size-1;
    while(i < j) {
        swap(arr[i], arr[j]);
        i++; j--;
    }
}

/* ***********************************************************************************
Practice problem: https://practice.geeksforgeeks.org/problems/reverse-a-string/1
You are given a string s. You need to reverse the string.
Input: s = Geeks 
Output: skeeG

// Solutions: 
string reverseWord(string str){
  reverse(str.begin(), str.end());
  return str;
}

string reverseWord(string str){
  int i = 0, j = str.size() - 1;
  while(i < j) {
      char x = str[i];
      str[i] = str[j];
      str[j] = x; 
      i++; j--;
  }
  return str;
}

*/
int main() {
    ios_base::sync_with_stdio(false); 
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector <int> vect = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr)/sizeof(arr[0]);

    reverse_arr(arr, len);
    // Method 2: Using vector STL
    reverse(vect.begin(), vect.end());

    printArray(arr, len);
    printVector(vect);
    return 0;
}
