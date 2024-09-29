#LINKED LISTS

Linked lists are of 3 types:
1. Singly linked lists.
2. Doubly linked lists.
3. Circularly linked lists.

##SINGLY LINKED LISTS

This is a linear collection of data items.
Each item of the list has two fields
Each item in the list is refered to as a node.
The two fields stored in the nodes are:
1. The data itself
2. The address to the next node

*OPERATIONS ON SINGLY LINKED LIST:
1. Insertion of a node.
    a. insertion at the beginning
    b. insertion at any given point
    c. insertion at the end 
2. Deletion of a node.
3. Traversing the list.


*STRUCTURE OF A NODE

There are two ways in making a node:

1. struct node {
        int data;
        struct node* link;
    }

2. class node{
    public:
        int data;
        node* link;
    }
    
#INSERTIONS IN THE LINKED LIST

##CASE 1: Insert at the begining:

*When inserting a node at the begining, we follow the steps bellow:
    1. Create a newNode.
        1a. Assign the data pointer of the newNode to the value
        1b. Make the newNode's pointer point to the head.
    2. Make the pointer of the new Node point to the head.
    3. Make the newNode the head of the list.
    
**Bellow is an implementation of the function of insertion at the start of the list.

void insertNodeAtTheBegining(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    
    head = newNode;
}

##CASE 2: Insert Node in the middle:

When inserting a node in the middle of the list, we follow the steps bellow:
    1. Create a newNode:
        1a. Assign the data value of the newNode to the value you wish to insert
        1b. Assign the pointer of the newNode as NULL.
    2. Check if the list is empty:
        2a. If the list is empty, assign the newNode as the head
        2b. If not, create a temporary node to help you traverse the list.
        2c. Traverse the list for as the long as the following conditions are met:
            2c.1. Travesre the list aslong as you haven't reached the position previous to the one desired.
            2c.2. The data value of te Temporary node is not the same as the value you wish to insert.
        2d. Check if you have reached the end of the list:
            2d.1. if you are ate the end of the list, print out a message that notifies the user.
            2d.1. else, assign the pointer value of the new node to the pointer value of the temp node and then assign the temp node pointer to the new node as shown bellow.
                    newNode->next = tempNode->next;
                    tempNode->next = newNode;
            

void insertNodeAtTheMiddle(int value, int position){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->NULL;
    
    if(head==NULL){
        head = newNode;
    }
    else{
        Node* Temp = head;
        for(int i = 0; i < position-1 && temp != nullptr; i++ ){
            Temp = Temp->next;
        }
        else{
            newNode->next = Temp->next;
            Temp->next = newNode;
        }
    }
}

##CASE 3: Insert Node at the End:

When insering a node at the end of a list, we follow the steps bellow:
1. Create a new Node instance.
    1a. Set the data value of the new Node to the value you wish to insert.
    1b. set the new node pointer to NULL.
2. check if the list is empty:
    2a. if the list is empty, make the new node the head node
    2b. if not, create a cureent node that you will use to traverse the list.
    2c. traverse the list for as long as you aren't at the end.
    2d. insert the new node at the end of the list.
    
    
void insertNodeAtTheEnd(int value){
    Node* newNode= new Node;
    newNode->data = value;
    newNode->next = NULL;
    
    if(head==NULL){
        head = newNode;
    }
    else{
        Node* current = head;
        while(current!=NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}


## DELETION OF A NODE IN A LINKED LIST

when deleting a node in the list it is important that we follow the steps bellow:
1. Create two pointers:
    1a. current pointer: help us keep track of which node we are at. (it is initially assigned to the head node)
    1b. previuos pointer: helps us keep track of the node previous of the current node. (it is initially signed as a nullptr)
2. Check if the list is empty:
    2a. if the list is empty, let the user kn ow and end the program.
    2b. if not, traverse the list for aslong as the following two conditions are met:
        2b.1. As long as we aren't in the end of the list
        2b.2. As long as we haven't found the value we are looking for.
    2c. When traversing the list, we set the previous node to the current node and move the current node one step ahead. i.e.
            previous = current;
            current = current->next;
    2d.  check if we the node is in the list
        2d.1. check if the list is not at the head of the list
            2d.2. if the value is not at the head of the list, assign the next pointer value of the previous node to the next pointer of the current node. i.e.
                    previous->next = current->next;
        2d.2. if the node is at the head of the list, move the current node by one step and delete the current node value.
    2e. if the node is not in the list, let the user know and end the program.
    
By following the above steps, you will be able to succesfully delete any node in a singly linked list.

void deleteNode(int value){
    Node* current = head;
    Node* previous = nullptr;
    
    if(head == NULL){
        cout<<"THE LIST IS EMPTY!!!\n";
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
            cout<<"The node has been succesfully deleted!!\n";
        }
        else{
            cout<<"The node with the value "<<value<<" is not in the list";
        }
        
    }
}


## SEARCHING A NODE IN A LINKED LIST

To search for a node in a linked list, one should follow the steps bellow
1. Check if the list is empty.
    1a. if the list is empty, let the user know and end the program.
    1b. if the list is not empty, create a temporary node that will be used to traverese the list and a bool too keep tack if the value is found or not.
    1c. initialize an index int to keep track of the indices of the values.
    
2. Traverse the list for aslong as the following two conditions are met:
    2a. aslong as we aren't at the end of the list
    2b. aslong as the value we are looking for is not equal to the value of the temporary node
    
    while(current!=nullptr && current->data != value)
    
    
3. check if we are at the end of the list
    3a. if so, print out a message to the user and end the program
    3b. if we are not at the end of the list and the value has been found, print out a message indicating so and its index 
    
The method is written down bellow.

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



