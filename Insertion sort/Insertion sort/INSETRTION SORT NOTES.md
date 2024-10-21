#  INSERTION SORT

When it comes to insertion sort, sorting is done in a manner that at first two items are comapred and then as the number of passes increases, so does the comparion items increase by 1. Take the example bellow:

    int myArr[] = {6,8,12,2,18,20,10};
     
    when sorting the above array, we do so by the help of two varriables:
    1. One to store as temporary value (int temp)
    2. The other to store the previous position (int j)
    
    EXAMPLE:
    index:    0  1  2   3  4   5   6
    items:    6  8  12  2  18  20  10
    
    PASS 1: 
    position of i = index 1.
    position of j = index 0.
    result: 6  8  12  2  18  20  10
    
    index:    0  1  2   3  4   5   6
    items:    6  8  12  2  18  20  10
    
    PASS 2:
    position of i = index 2.
    position of j = index 1.
    result: 6  8  12  2  18  20  10
    
    index:    0  1  2   3  4   5   6
    items:    6  8  12  2  18  20  10
    
    PASS 3:
    position of i = index 3.
    position of j = index 2.
    comparing: 6 , 8, 12, 2
    result: 2  6  8  12  18  20  10
    
    index:    0  1  2   3  4   5   6
    items:    2  6  8  12  18  20  10
    
    PASS 4:
    position of i = index 4.
    position of j = index 3.
    result: 2  6  8  12  18  20  10
    
    
    index:    0  1  2   3  4   5   6
    items:    2  6  8  12  18  20  10
    
    PASS 5:
    position of i = index 5.
    position of j = index 4.
    result:  2  6  8  12  18  20  10
    
    
    index:    0  1  2   3  4   5   6
    items:    2  6  8  12  18  20  10
    
    PASS 6:
    position of i = index 6.
    position of j = index 5.
    result: 2  6  8  10  12  18  20
    
    
The code for the above algorithm is as follwos:

    void insertion sort(int myArr[], int sizeOfArray){
        int j;
        int temp;
        
        for(int i = 1; i<sizeOfArray; i++){
            j = i - 1;
            temp = myArr[i];
            
            while(myArr[j] > temp && j > -1){
                myArr[j+1] = myArr[j];
                j--;
            }
            myArr[j+1] = temp;
        }
        
    }
    
**EXPLANATION:

1. The algorithm takes two parameters:
    1. The array to be sorted 
    2. The size of the array.
    
2. The initialized varriables j and temp help us store the previous position to i and the number at position i respectivley.

3. The for loop helps in determining the number of passes and since we start comparing from index 1, hence we assign i to 1.
4. After every pass, we assign j to the previous position i and temp to store the value at position i.

5. For aslong as the number at position j is greater than the number at position i(myArr[j] > temp) and index j is greater than -1 meaning that we arent at the end, the comparisons continue and so do the swaps. we assign the item at i(j+1) to the item at j (myArr[j + 1] = myArr[j]) and we decrease j by 1(j--)

6. we assing the item at i(myArr[j + 1]) to temp (myArr[j+1] = temp).


**ALGORITHM ANALYSIS

    1. BEST CASE: O(n)
    2. WORST CASE: O(n^2)
    3. AVERAGE CASE: O(n^2)
    4. STABLE: yes
    5. SPACE COMPLEXITY: O(1)
    6. WHEN TO USE: small datasets, nearly sorted arrays, partially sorting data.
    7. WHEN NOT TO USE: large datasets, Already optimized altenatives(For large, unsorted arrays, more advanced algorithms like merge sort or quick sort are generally better choices since they have lower average and worst-case time complexities (O(n log n))).



