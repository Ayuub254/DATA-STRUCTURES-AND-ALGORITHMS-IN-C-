//
//  main.cpp
//  Merge sort
//
//  Created by Ayub's mac✌🏾 on 21/10/2024.
//

#include <iostream>
using namespace std;
class MERGESORTALGORITHIM{
public:
    void merge(int Arr[], int low, int mid, int high){
        int sizeOfLeftArray = mid - low + 1;
        int sizeOfRightArray = high - mid;
        
        int Left[sizeOfLeftArray];
        int Right[sizeOfRightArray];
        
        for(int i = 0; i<sizeOfLeftArray; i++){
            Left[i] = Arr[low + i];
        }
        for(int j = 0; j<sizeOfRightArray; j++){
            Right[j] = Arr[mid + 1 + j];
        }
        
        int i = 0;
        int j = 0;
        int k = low;
        
        while(i < sizeOfLeftArray && j < sizeOfRightArray){
            if(Left[i]<Right[j]){
                Arr[k] = Left[i];
                i++;
            }else{
                Arr[k] = Right[j];
                j++;
            }
            k++;
        }
        
        while(i < sizeOfLeftArray){
            Arr[k] = Left[i];
            i++;
            k++;
        }
        while(j < sizeOfRightArray){
            Arr[k] = Right[j];
            j++;
            k++;
        }
    }
    
    void display(int Arr[], int sizeOfArray){
        for(int i =0; i< sizeOfArray; i++){
            cout<<Arr[i]<<" , ";
        }
        cout<<endl;
    }
    
    void mergeSort(int Arr[], int low, int high){
        if(low<high){
            int mid = low + (high - low)/2;
            
            mergeSort(Arr, low, mid);
            mergeSort(Arr, mid+1, high);
            
            merge(Arr, low, mid, high);
        }
    }
    
};
int main(int argc, const char * argv[]) {
    MERGESORTALGORITHIM sort;
    int Arr[] = {9,3,7,5,6,4,8,2};
    int sizeOfArray = sizeof(Arr) / sizeof(Arr[0]);
    
    cout<<"ORIGINAL UNSORTED ARRAY: ";
    sort.display(Arr, sizeOfArray);
    
    sort.mergeSort(Arr, 0, sizeOfArray-1);
    cout<<"ARRAY AFTER MERGE SORT: ";
    sort.display(Arr, sizeOfArray);
    return 0;
}
