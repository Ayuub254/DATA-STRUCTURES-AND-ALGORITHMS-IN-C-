//
//  main.cpp
//  Insertion sort
//
//  Created by Ayub's mac✌🏾 on 16/10/2024.
//

#include <iostream>
using namespace std;
class Array{
public:
    void display(int myArr[], int sizeOfArray){
        for(int i = 0; i<sizeOfArray; i++){
            cout<<myArr[i]<<" , ";
        }
        cout<<endl;
    }
    
    void insertionSort(int myArr[], int sizeOfArray){
        int positionJ;
        int tempItem;
        
        for(int i = 1; i<sizeOfArray; i++){ // deals with passes
            positionJ = i - 1;
            tempItem = myArr[i];
            
            while(myArr[positionJ]>tempItem && positionJ >-1){
                myArr[positionJ+1] = myArr[positionJ];
                positionJ--;
            }
            myArr[positionJ + 1] = tempItem;
        }
    }
};
int main(int argc, const char * argv[]) {
    Array array;
    int myArr[] = {6,8,12,2,18,20,10};
    int sizeOfArray = sizeof(myArr) / sizeof(myArr[0]);
    
    cout<<"ORIGINAL ARRAY: ";
    array.display(myArr, sizeOfArray);
    cout<<endl;
    
    array.insertionSort(myArr, sizeOfArray);
    cout<<"SORTED ARRAY: ";
    array.display(myArr, sizeOfArray);
    cout<<endl;
    
    return 0;
}
