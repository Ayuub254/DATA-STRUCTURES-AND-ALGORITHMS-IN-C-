//
//  Circular Linked List.cpp
//  Circular Linked List
//
//  Created by Ayub's mac✌🏾 on 04/10/2024.
//

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class CircularLinkedList{
private:
    Node* head;
public:
    
    CircularLinkedList(){
        head = NULL;
    }
    
    void insertNodeAtTheBegining(int value){
        Node* newNode = new Node;
        newNode->data = value;
        
        if(head == NULL){
            newNode->next = newNode;
            head = newNode;
        }else{
            Node* current = head;
            while(current->next != head){
                current = current->next;
            }
            
            current->next = newNode;
            
            newNode->next = head;
            
            head = newNode;
        }
    }
    
    void display(){
        if(head==NULL){
            cout<<"THE CIRCULAR LIST IS EMPTY!!!\n";
        }else{
            Node* temp = head;
            do{
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }while(temp!=head);
            cout<<" Back at the head of the list: "<<head->data<<"\n";
        }
    }
};
int main(){
    CircularLinkedList list;
    list.insertNodeAtTheBegining(30);
    list.insertNodeAtTheBegining(40);
    list.insertNodeAtTheBegining(50);
    list.insertNodeAtTheBegining(60);
    list.insertNodeAtTheBegining(70);
    list.display();
    return 0;
}
