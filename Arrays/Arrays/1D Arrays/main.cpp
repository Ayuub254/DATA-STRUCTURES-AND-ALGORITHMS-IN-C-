//
//  main.cpp
//  Arrays
//
//  Created by Ayub's mac✌🏾 on 24/09/2024.
//

#include <iostream>
using namespace std;

class Numbers{
public:
    int myArray[4];
    
    void insert(){ // method for insertion in the array. 
        for(int i=0; i<4; i++){
            cout<<"Enter Number("<<i<<"): ";
            cin>>myArray[i];
        }
    }
    
    void display(){ // method for displaying the items in the array.
        for(int i =0; i<4; i++){
            cout<<myArray[i]<<" ";
        }
    }
    
    void search(){ // method for searching for an item in the array
        int searchNumber;
        bool found = false; //helps in keeping track of if the number has been found or not.
        cout<<"Enter the number you wish to search for: ";
        cin>>searchNumber;
        
        for(int i =0; i< 4; i++){
            if(searchNumber == myArray[i]){
                cout<<"The number is found at index: "<<i<<"\n";
                found = true; // number has been found.
            }
        }
        if(!found){ //number has not been found.
            cout<<"The number is not in the Array!!!!!\n";
            
        }
        
    }
};

int main(int argc, const char * argv[]) {
    Numbers num;
    
    cout<<"BASIC ARRAY IMPLEMENTATION\n";
    num.insert();
    cout<<"The numbers in the array are: ";
    num.display();
    
    string option;
    cout<<"\nWould you like to search for a number in the array?(yes or no) ";
    cin>>option;
    
    if(option =="yes"){
        num.search();
    }
    else{
        return 0;
    }
    
}
