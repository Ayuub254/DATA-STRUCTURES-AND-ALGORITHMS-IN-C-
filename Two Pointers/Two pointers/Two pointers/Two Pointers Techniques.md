#  TWO POINTERS TECHNIQUES
- It is an algorithmic technique that is used to ssolve problems involving arrays or linked lists in efficient manner

- It involves using two pointers to traverse a sorted array or linked list simultaneously.

- There are two varriations of the two pointers tecchniques:

1. TORTOISE AND HARE:
    - Two pointers (slow and fast) both at the start of the data structure
    - The fast pointer moves twice as fast as the slow pointer.
    - This technique is mostly used in finding cycles in a Linked List.
    
    *Implementation of the Tortoise and Hare Technique:
    
    bool TortoiseAndHare (){
        if(head == NULL || head->next == NULL){
            cout<<"No cycles possible";
            return false;
        }
        Node* Tortoise = head;
        Node* Hare = head;
        
        while(Hare != NULL && Hare->next != NULL){
            Tortoise = Tortoise->next;
            Hare = Hare->next->next;
            
            if(Tortoise == Hare){
                cout<<"Cycles Detected!!"
                return true;
            }
        }
        cout<<"No cycles Detected!!"
        return false;
    }
    
    

