//
//  2D Arrays.cpp
//  2D Arrays
//
//  Created by Ayub's mac✌🏾 on 30/09/2024.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class twoDArray{
public:
    int rows;
    int cols;
    int** myTwoDArray;
    
    void insert(){
        cout<<"Enter number of rows: ";
        cin>>rows;
        cout<<"Enter number of cols: ";
        cin>>cols;
        
        myTwoDArray = new int*[rows];
        for(int i =0; i<rows; i++){
            myTwoDArray[i] = new int[cols];
        }
        cout<<"Enter the values of the array: \n";
        for(int i =0; i<rows;i++){
            for(int j =0; j<cols; j++){
                cout<<"Enter element ["<<i<<"]["<<j<<"]: ";
                cin>>myTwoDArray[i][j];
            }
        }
    }

    void display(){
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cout<<myTwoDArray[i][j]<<" , ";
            }
        }
    }
    
    void search(int value){
        bool isFound = false;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(myTwoDArray[i][j] == value){
                    isFound = true;
                    cout<<"The number is at index: ["<<i<<"]["<<j<<"] \n";
                }
            }
        }
    }
};
int main(){
    cout<<"IMLPEMETATION OF A 2D ARRAY!!\n";
    twoDArray array;
    array.insert();
    cout<<endl;
    cout<<"All Items in the array: ";
    array.display();
    
    char search;
    cout<<"\nWould you like to search for an item in the array? ('Y' for yes and 'N' for no): ";
    cin>>search;
    
    if(search == 'Y'){
        int val;
        cout<<"\nWhat value would you like to search for: ";
        cin>>val;
        array.search(val);
        
    }
    else if(search == 'N'){
        return 0;
    }
        
    //return 0;
}
