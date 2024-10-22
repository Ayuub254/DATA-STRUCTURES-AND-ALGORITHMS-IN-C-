//
//  main.cpp
//  Quick Sort
//
//  Created by Ayub's mac✌🏾 on 22/10/2024.
//

#include <iostream>
using namespace std;
class QUICKSORT{
public:
    void display(int Arr[], int sizeOfArray){
        for(int i =0; i<sizeOfArray; i++){
            cout<<Arr[i]<<" , ";
        }
        cout<<endl;
    }
    
    int Partition(int Arr[], int low, int high){
        int pivot = Arr[low];
        int i = low + 1;
        int j = high;
        
        while(i <= j){
            while(i <= j && Arr[i] <= pivot){
                i++;
            }
            while(i <= j && Arr[j] > pivot){
                j--;
            }
            if(i < j){
                swap(Arr[i], Arr[j]);
            }
        }
        swap(Arr[low], Arr[j]);
        return j; // returns the pivot position.
    }
    
    void QuickSort(int Arr[], int low, int high){
        if(low < high){
            int pivotPosition = Partition(Arr, low, high);
            
            QuickSort(Arr, low, pivotPosition-1);
            QuickSort(Arr, pivotPosition+1, high);
            
        }
    }
};
int main(int argc, const char * argv[]) {
    QUICKSORT sort;
    int Arr[] = {10, 16, 8, 12, 15, 6, 3, 9, 5, 7};
    int sizeOfArray = sizeof(Arr) / sizeof(Arr[0]);
    
    cout<<"ORIGINAL ARRAY: ";
    sort.display(Arr, sizeOfArray);
    
    sort.QuickSort(Arr, 0, sizeOfArray-1);
    cout<<"SORTED ARRAY: ";
    sort.display(Arr, sizeOfArray);
    return 0;
}
