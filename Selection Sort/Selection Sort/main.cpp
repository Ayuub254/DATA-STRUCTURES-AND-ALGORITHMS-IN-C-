//
//  main.cpp
//  Selection Sort
//
//  Created by Ayub's mac✌🏾 on 15/10/2024.
//

#include <iostream>
using namespace std;

class Sorting{
public:
    void display(int myArr[], int n){
        for(int i =0; i<n; i++){
            cout<<myArr[i]<<" , ";
        }
        cout<<endl;
    }
    
    void selectionSort(int myArr[], int n){
        int minValueIndex;
        int tempValue;
        
        for(int i =0; i< n-1; i++){
            minValueIndex = i;
            for(int j = i+1;j<n; j++){
                if(myArr[minValueIndex] > myArr[j]){
                    minValueIndex = j;
                }
            }
            if (minValueIndex != i){
                tempValue = myArr[i];
                myArr[i] = myArr[minValueIndex];
                myArr[minValueIndex] = tempValue;
            }
        }
    }
};
int main(int argc, const char * argv[]) {
    Sorting sort;
    
    int myArr[] = {8, 7, 9, 2, 3, 1, 5, 4, 6};
    int n = sizeof(myArr) / sizeof(myArr[0]);
    
    cout<<"ORIGINAL ARRAY: ";
    sort.display(myArr, n);
    cout<<endl;
    
    
    cout<<"SORTED ARRAY: ";
    sort.selectionSort(myArr, n);
    sort.display(myArr, n);
    cout<<endl;
    
    
    
    return 0;
}
