//
//  main.cpp
//  Linked List
//
//  Created by Ayub's mac✌🏾 on 25/09/2024.
//

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }
    
    void insertNodeAtTheBegining(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        
        head = newNode;
    }
    
    void insertNodeAtTheMiddle(int value, int position){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* temp = head;
            for(int i = 0; i < position-1 && temp != nullptr; i++){
                temp = temp->next;
            }
            if(temp == nullptr){
                cout<<"The position is out of index!!!\n";
            }
            else{
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
    
    void insertNodeAtTheEnd(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = newNode;
        }
    }
    
    void deleteNode(int value){
        Node* current = head;
        Node* previous = nullptr;
        
        if(head == NULL){
            cout<<"THE LIST IS EMPTY\n";
        }
        else{
            while(current!=nullptr && current->data!=value){
                previous = current;
                current = current->next;
            }
            
            if(current!=nullptr){
                if(previous!=nullptr){
                    previous->next = current->next;
                }
                else{
                    head = current->next;
                }
                delete current;
                cout<<"The node with the value "<<value<<" has been deleted succesfully\n";
            }
            else{
                cout<<"The node with value "<<value<<" is not in the list\n";
            }
        }
    }
    
    void searchNode(int value){
        if(head == NULL){
            cout<<"The list is empty!!!\n";
        }
        else{
            Node* current = head;
            int index = 0;
            bool isFound = false;
            
            while(current!= nullptr && current->data!=value){
                current = current->next;
                index = index + 1;
            }
            if(current != nullptr && current->data == value){
                isFound = true;
                cout<<"The node has been found at index "<<index<<endl;
                
            }
            else{
                cout<<"The node is not in the list!!!!\n";
            }
        }
    }
    
    void display() {
        if (head == NULL) {
            cout << "The List is empty!!!!\n";
        } else {
            Node* current = head;
            while (current != NULL) {
                cout << current->data;
                if (current->next != NULL) {
                    cout << " -> ";
                }
                current = current->next;
            }
            cout << endl;
        }
    }

    
    
};
int main(int argc, const char * argv[]) {
    LinkedList list;
    cout<<"BASIC IMPLEMENTATION OF SINGLY LINKED LIST\n";
    int num;
    int pos;
    int choice;
    char choice1;
    
    cout<<"How many Numbers would you like to input into the list? ";
    cin>>choice;
    
    cout<<"Where in the list would you like to add the numbers?('B' for Begining, 'M' for middle, 'E' at the end): ";
    cin>>choice1;
    
    for(int i = 0; i<choice; i++){
        cout<<"Enter number ("<<i<<"): ";
        cin>>num;
        if(choice1 == 'B'){
            list.insertNodeAtTheBegining(num);
        }
        else if (choice1 == 'M'){
            cout<<"Enter index position: ";
            cin>>pos;
            list.insertNodeAtTheMiddle(num,pos);
        }
        else if(choice1 == 'E'){
            list.insertNodeAtTheEnd(num);
        }
    }
    
    list.display();
    cout<<endl;
    
    char deletenode;
    int deleteValue;
    cout<<"Would you like to delete a node? ('Y' for yes and 'N' for no) ";
    cin>>deletenode;
    
    if(deletenode == 'Y'){
        cout<<"What value would you like to delete: ";
        cin>>deleteValue;
        list.deleteNode(deleteValue);
        
    }
    else if(deletenode == 'N'){
        cout<<"No node has been deleted in the list!!!\n";
    }
    
    list.display();
    cout<<endl;
    
    char searchANode;
    cout<<"Would you like to search a node in the list? ('Y' for yes and 'N' for no): ";
    cin>>searchANode;
    
    if(searchANode == 'Y'){
        int nodeVlaue;
        cout<<"What value would you like to search for: ";
        cin>>nodeVlaue;
        list.searchNode(nodeVlaue);
    }
    else if (searchANode == 'N'){
        return 0;
    }
    
    
  
    //return 0;
}
