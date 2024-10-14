//
//  main.cpp
//  BubbleSort
//
//  Created by Ayub's mac✌🏾 on 14/10/2024.
//

#include <iostream>
using namespace std;
class Array{
public:
    void displayArray(int myArray[], int n){
        for(int i =0; i< n; i++){
            cout<<myArray[i]<<" , ";
        }
        cout<<endl;
    }
    
    void bubbleSort(int myArray[], int n){
        bool isSwapped;
        for(int i=0; i<n-1; i++){
            isSwapped = false;
            for(int j=0; j<n-1-i; j++){
                if(myArray[j] > myArray[j+1]){
                    swap(myArray[j], myArray[j+1]);
                    isSwapped = true;
                }
            }
            
            if(isSwapped == false){
                cout<<"Array is already sorted!!!\n";
                break;
            }
        }
    }
    
};
int main(int argc, const char * argv[]) {
    Array array;
    int myArray[] = {2,3,5,7,8};
    int n = sizeof(myArray) / sizeof(myArray[0]);
    
    cout<<"Original Array: ";
    array.displayArray(myArray, n);
    cout<<endl;
    
    
    array.bubbleSort(myArray, n);
    cout<<"Sorted Array: ";
    array.displayArray(myArray, n);
    cout<<endl;
    
    return 0;
    
    
}
