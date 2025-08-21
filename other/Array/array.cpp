#include<iostream>
using namespace std;


int main(){
    int arr[10];
    memset(arr, 0, sizeof(arr)); // Initialize all elements to 0
    // cout << "Array initialized with zeros." << endl;
    // cout << "First element: " << arr[0] << endl; // Output the
    // cout << "Last element: " << arr[9] << endl; // Output the last element
    arr[0] = 100;
    arr[1] = 200;
    arr[2] = 300;
    arr[3] = 1000;
    // 100 200 300 1000 0 0 0 0 0 0
    for(int i = 4; i > 2;i--){
        arr[i] = arr[i - 1];
    }
    arr[2] = 500; // Modify the third element
    cout << "Array after modification: ";
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " "; // Output the modified array
    }
    cout << endl;
    // cout << "Last element after modification: " << arr[9] << endl; // Output the modified last element
    // cout << "Size of the array: " << sizeof(arr) / sizeof(arr[0]) << endl; // Output the size of the array
    return 0;
}