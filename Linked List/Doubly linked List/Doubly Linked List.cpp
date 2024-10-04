//
//  Doubly Linked List.cpp
//  Doubly Linked List
//
//  Created by Ayub's mac✌🏾 on 03/10/2024.
//

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* previous;
};
class DoubleLinkedList{
private:
    Node* head;
public:
    DoubleLinkedList(){
        head = NULL;
    }
    
    void insertNodeAtTheBegining(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        newNode->previous = NULL;
        
        head = newNode;
    }
    
    void insertNodeAtTheEnd(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        newNode->previous = NULL;
        
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* current= head;
            while(current->next!=NULL){
                current = current->next;
                
            }
            
            current->next = newNode;
            newNode->previous = current;
        }
    }
    
    void insertNodeAtTheMiddle(int value, int position){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        newNode->previous = NULL;
        
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* temp = head;
            for(int i =0; i<position-1 && temp!=nullptr; i++){
                temp = temp->next;
            }
            if(temp == nullptr){
                cout<<"The position is out of index!!!";
            }
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->previous = temp;
        }
    }
    
    void display(){
        if(head == NULL){
            cout<<"The List is empty!!!";
        }else{
            Node* temp = head;
            while(temp!=NULL){
                cout<<" <- "<<temp->data<<" -> ";
                temp = temp -> next;
            }
        }
    }
    
};
int main(){
    DoubleLinkedList list;
    list.insertNodeAtTheBegining(30);
    list.insertNodeAtTheBegining(40);
    list.insertNodeAtTheBegining(50);
    list.insertNodeAtTheBegining(60);
    list.insertNodeAtTheBegining(70);
    list.insertNodeAtTheEnd(90);
    list.insertNodeAtTheMiddle(300, 3);
    list.display();
    cout<<endl;
    return 0;
}
