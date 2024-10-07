//
//  main.cpp
//  Two pointers
//
//  Created by Ayub's mac✌🏾 on 07/10/2024.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    
    void insertNodeAtTheBegining(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
         
        head = newNode;
    }
    
    bool TortoiseAndHare(){
        if(head == NULL || head->next == NULL){
            cout<<"No cycles are possible!!";
            return false;
        }
        Node* Tortoise = head;
        Node* Hare = head;
        
        while(Hare!=NULL && Hare->next!=NULL){
            Tortoise = Tortoise->next;
            Hare = Hare->next->next;
            
            if(Tortoise == Hare){
                cout<<"Cycle Detected!!\n";
                return true;
            }
        }
        cout<<"No Cycle Detected!!!\n";
        return false;
    }
    
    void display(){
        if(head == NULL){
            cout<<"The list is empty!!\n";
        }else{
            Node* current = head;
            while(current!=NULL){
                cout<<current->data<<" -> ";
                current = current->next;
            }
        }
    }
};
int main(int argc, const char * argv[]) {
    LinkedList list;
    list.insertNodeAtTheBegining(30);
    list.insertNodeAtTheBegining(40);
    list.insertNodeAtTheBegining(50);
    list.insertNodeAtTheBegining(60);
    list.insertNodeAtTheBegining(70);
    list.insertNodeAtTheBegining(80);
    list.display();
    cout<<endl;
    
    list.TortoiseAndHare();
    
    Node* tempNode = list.head->next->next->next->next;
    Node* tail = list.head;
    
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = tempNode;
    
    list.TortoiseAndHare();
    cout<<endl;
    
    return 0;
}
