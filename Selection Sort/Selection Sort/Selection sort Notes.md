#  SELECTION SORT ALGORITHIM

Selection sort is an in-place comparison sorting algorithm that keeps track of the minimum value during each iteration and at the
end of each iteration we swap variables.

consider the examople bellow:
    int myArr[] = {9, 1, 8, 7, 5, 3, 6, 2, 4};
    
    When sorting the above array of numbers we use the help of two varriables that will help us store the minimum value and a temporary value
    
    PASS 1:
        9, 1, 8, 7, 5, 3, 6, 2, 4
        
        Min value: 9, 1
        Temp value: 9
        Swap: 9 with 1
        Result: 1, 9, 8, 7, 5, 3, 6, 2, 4
        
    PASS 2:
        *
        1, 9, 8, 7, 5, 3, 6, 2, 4
        
        Min value: 9, 8, 7, 5, 3, 6, 2
        Temp value: 9
        Swap: 9 with 2
        Result: 1, 2, 8, 7, 5, 3, 6, 9, 4
        
    PASS 3:
        *  *
        1, 2, 8, 7, 5, 3, 6, 9, 4
        
        Min value: 8, 7, 5, 3
        Temp value: 8
        Swap: 8 with 3
        Result: 1, 2, 3, 7, 5, 8, 6, 9, 4
        
    PASS 4:
        *  *  *
        1, 2, 3, 7, 5, 8, 6, 9, 4
        
        Min value: 7, 5, 4
        Temp value: 7
        Swap: 7 with 4
        Result: 1, 2, 3, 4, 5, 8, 6, 9, 7
        
    PASS 5:
        *  *  *  *
        1, 2, 3, 4, 5, 8, 6, 9, 7
        
        Min value: 5
        Temp value: 5
        Swap: no swap
        Result: 1, 2, 3, 4, 5, 8, 6, 9, 7
        
    PASS 6:
        *  *  *  *  *
        1, 2, 3, 4, 5, 8, 6, 9, 7
        
        Min value: 8, 6
        Temp value: 8
        Swap: 8 with 6
        Result: 1, 2, 3, 4, 5, 6, 8, 9, 7
        
    PASS 7:
        *  *  *  *  *  *  
        1, 2, 3, 4, 5, 6, 8, 9, 7
        
        Min value: 8,7
        Temp value: 8
        Swap: 8 with 7
        Result: 1, 2, 3, 4, 5, 6, 7, 9, 8
        
    PASS 8:
        *  *  *  *  *  *  *
        1, 2, 3, 4, 5, 6, 7, 9, 8
        
        Min value: 9, 8
        Temp value: 9
        Swap: 9 with 8
        Result: 1, 2, 3, 4, 5, 6, 7, 8, 9
        
        RESULT = 1, 2, 3, 4, 5, 6, 7, 8, 9
        
From the above we can conclude that it took n-1 iterations to sort out the entire array. where n is the number of elements present in the array.


The code for the above algorithm is eplained bellow:

    void SelectionSort(int myArr[], int n){
        int minIndex;
        int temp;
        
        for(int i=0; i<n-1; i++){
            minIndex = i;
            for(int j = i+1; j<n; j++){
                if(myArr[minIndex] > myArr[j]){
                    minIndex = j;
                }
            }
            
            temp = myArr[i];
            myArr[i] = myArr[minIndex];
            myArray[minIndex] = temp;
        }
    }
    
** EXPLANATION
    
    1. The two variables help us keep track of the minimum number and a temporary number that are to be used in swapping.
        int minIndex; -> store the minimum number
        int temp; -> store a temporary number
        
    2. The first for loop is the one that deteremines the number of iterations that re to be done (PASSES 1-8) and after every pass we set the minIndex to I
    3. The second for loop is the one that assists in comparing the two numbers and determining the minimum number between the two.
    
    4. After the nested loops we swap the numbers. i.e:
        temp = myArr[i]; -> Assign the first value to the temp varriable
        myArr[i] = myArr[minIndex]; -> Assign the smallest value to the position formaly held by the bigger value.
        myArr[minIndex] = temp; -> Assign the temp value to the position formaly held by the smallest value.
        

** SELECTION SORT ALGORITHM ANALYSIS:

    1. Best Case --------> O(n^2)
    2. Average Case -----> O(n^2)
    3. Worst Case -------> O(n^2)
    4. Space complexity--> O(1)
    5. Stable -----------> No
    6. When to use ------> Small datasets, few swaps needed, memory constraints.
    7. when not to use --> Large datasets, when stability matters, when a faster solution is required.
    
NB: When we say an alogrithm is stable, we mean that it preserves the relative order of equal elements in the sorted output. This means that if two elements have the same value in the input array, they will appear in the same order in the output as they did in the input. 
    Example: If you have an array of objects with both name and age attributes and you're sorting by age, a stable sort ensures that objects with the same age maintain the same order they had in the original list.
    
    Original Array:  [(Alice, 25), (Bob, 25), (Charlie, 22)]
    Sorted Array (by age):  [(Charlie, 22), (Alice, 25), (Bob, 25)]  // Relative order of Alice and Bob is preserved.
    
    On the other hand, when we say an algorithim is unstable, we mean that it does not guarantee the relative order of equal elements. After sorting, equal elements might appear in a different order than they did in the input.
    Example: For the same input:
    
    Original Array:  [(Alice, 25), (Bob, 25), (Charlie, 22)]
    Sorted Array (by age, with unstable sort):  [(Charlie, 22), (Bob, 25), (Alice, 25)]  // Relative order of Alice and Bob is not preserved.
    

QN: Why stability matters? :
    1. Preserving metadata: Stability is important when elements carry additional information (like names in the example above), and you want to maintain their original order when sorting by other attributes (e.g., age).
    2. Multi-level sorting: If you're performing multi-level sorting, where you first sort by one key (say, age), and then sort by another key (say, name), a stable sort ensures that the first sort does not disrupt the results of the second sort.
    

**STABLE AND UNSTABLE ALGORITHMS

1. STABLE ALGORITHMS:
    a. Bubble sort
    b. Merge sort
    c. Insertion sort
    
2. UNSTABLE ALGORITHMS: 
    a. Selection sort
    b. Quick sort
    c. Heap sort
    
In short, stability is about whether equal elements retain their original relative order after sorting.



    
        

        
        
        
        
        
        
        

