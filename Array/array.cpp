// Insertion and Deletion in Array

#include <iostream>
using namespace std;
const int n = 10;   //Size of array

// Function Prototypes
void printArray(int arr[]);   //To print array
int currentSize(int arr[]);     //To count the current size
bool isOverflow(int arr[]);     //To check overflow condition
bool isUndeflow(int arr[]);     //To check underflow condition
void insertData(int arr[], int data, int index);  //To insert data at any index
void removeData(int arr[], int index);  //To delete data from any index

int main()
{
    int arr[n] = {1, 2, 3, 4, 5};
    printArray(arr);
    insertData(arr, 10, 0);
    printArray(arr);
    removeData(arr, 2);
    printArray(arr);
    
    

    return 0;
}
//Functon Definations
int currentSize(int arr[]){
    int i = 0;
    while (arr[i] != 0) {
        i++;
    }
    return i;
}
void printArray(int arr[]){
    int size = currentSize(arr);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool isOverflow(int arr[]){
    if(currentSize(arr) == n){
        return true;
    }
    else {
        return false;
    }
}
bool isUndeflow(int arr[]){
    if(currentSize(arr) == 0){
        return true;
    }
    else {
        return false;
    }
}
void insertData(int arr[], int data, int index){
    if(isOverflow(arr)){
        cout << "OVERFLOW" << endl;
        return;
    }
    if(index == currentSize(arr)){
        arr[index] = data;
    }
    else if (index < currentSize(arr)) {
        for(int i = currentSize(arr)-1; i >= index; i--){
            arr[i+1] = arr[i];
        }
        arr[index] = data;
    }
    else {
        cout << "INDEX EXCEEDED" << endl;
    }
}
void removeData(int arr[], int index){
    if(isUndeflow(arr)){
        cout << "UNDERFLOW" << endl;
        return;
    }
    if(index == currentSize(arr)){
        arr[index] = 0;
    }
    else if (index < currentSize(arr)) {
        for(int i = index+1; i < currentSize(arr); i++){
            arr[i-1] = arr[i];
        }
        arr[currentSize(arr)-1] = 0;
    }
    else {
        cout << "INDEX EXCEEDED" << endl;
    }
}
