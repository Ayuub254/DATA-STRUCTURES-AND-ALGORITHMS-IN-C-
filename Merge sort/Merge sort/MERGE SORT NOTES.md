#  MERGE SORT ALGORITHIM
To understand how the merge sort algorithim works, we first need to understand how merging works. 
Lets use the array bellow as an example:

    int myArr[] = {9, 3, 7, 5, 6, 4, 8, 2};

Merging uses a divide and conqure type of approach when it comes to solving this problem. It divides the large array into halves that are managable and solves each sub-array at a time. Before dividing the array into halves, we first need to determine the mid point of the array.
This will be done through the help of two pointers:
    1. Low -> a pointer that points to the begining of the array.
    2. High -> a pointer that points to the end of the array.
    
    using the array bellow, the pointers will point at the head and the tail of the array:
    
        INDEX: 0  1  2  3  4  5  6  7
               9  3  7  5  6  4  8  2
               ^                    ^
              Low                  High
       
       To determine the mid point we use the formula: 
          Mid = Low + (High + Low)/2.
          Mid = 0 + (7 + 0)/2.
          Mid = (7)/2
          Mid = 3.5
          
          Therefore: The mid will point at index 3
                            Index:    0  1  2  3
          SubArray 1: Low -> Mid    : 9  3  7  5
                                      ^        ^
                                     Low      Mid   
          
          
                            Index:    4  5  6  7
          SubArray 2: Mid+1 -> High : 6  4  8  2
                                      ^        ^
                                    Mid+1     High
          
          
Now that the Array has been subdivided into two, we can start sorting by continous subdivision of each array and then merge the results 

        SUBARRAY 1: (0 - 3) -> 9, 3, 7, 5
        SUBARRAY 2: (4 - 7) -> 6, 4, 8, 2
        
                        9  3   7  5          6  4   8  2
                        \  /   \  /          \  /   \  /
                        3  9   5  7          4  6   2  8         -> PASS 1.
                          \      /             \     /
                        3  5  7  9            2  4  6  8         -> PASS 2.
                             \                    /
                              \                  /
                              2   3  4  5  6  7  8  9            -> PASS 3.
                              
From the results above we can see, that it took three passes to solve an array of 8 elements, therefore we can conclude that:
    For an array of n elemets, the time complexity will be O(nlogn).
    
    TIME COMPLEXITY: O(nlogn).
    
Now lets take a look at how the code would look like:

To effectively perfom merging, we follow the steps bellow: 
    1. Determine the lengths of the two subarrays.
    2. Create two new arrays to store the data of the subarrays
    3. Fill the two new subarrays with their relevant data.
    4. Compare the data of the two subarrays and copy them in a sorted format to the old array.
    5. Fill in any remaining elements of both subarrays into the original array.
    
        Void merge(int Arr[], int low, int mid, int high){
            int N1 = (mid - low+1);
            int N2 = (high - mid);
            
            int L[N1];
            int R[N2];
            
            for(int i=0; i<N1; i++){
                L[i] = Arr[low + i];
            }
            for(int j=0; j<N2; j++){
                R[j] = Arr[mid+1 + j];
            }
            
            int i = 0;
            int j = 0;
            int k = low;
            
            while(i < N1 && j < N2){
                if(L[i] < R[j]){
                    Arr[k] = L[i];
                    i++;
                } else {
                    Arr[k] = R[j];
                    j++;
                }
                k++;
            }
            
            while(i < N1){
                Arr[k] = L[i];
                i++;
                k++;
            }
            while(j < N2){
                Arr[k] = R[j];
                j++;
                k++;
            }
        }


Now that we understand how merging works, it is easier to comprehend how the merge sort algorithm works. Merge sort is recursive in nature.

        Void mergeSort(int Arr[], int low, int high){
            if(low < high){
                int mid = low + (high - low)/2;
                
                mergeSort(Arr, low, mid);
                mergeSort(Arr, mid+1, high);
                
                merge(Arr, low, mid, high);
            }
        }

**EXPLANATION:

    1. The if-statement in the merge sort algorithm checks if there is more than one elemnt in the array and if thats the case, then the condition will be true.
    2. it then proceedes to perform merge sort of the two subarrays and then at the end merges the two arrays.
    
    
** ALGORITHM ANALYSIS:

    1. BEST CASE : O(n log n)
    2. WORST CASE: O(n log n)
    3. AVERAGE CASE: O(n log n)
    4. STABLE : Yes, meaning it maintains the relative order of equal elements in the input array.
    5. TIME COMPLEXITY: O(n log n)
    6. SPACE COMPLEXITY: O(n)
    7. WHEN TO USE: 
            1. When you need a stable, comparison-based sorting algorithm.
            2. When the input data is too large to be efficiently handled by quicksort due to its O(n^2) worst-case time complexity.
            3. Suitable for sorting linked lists, as it doesn’t require random access to elements (no additional memory overhead for splitting).
    8. WHEN NOT TO USE: 
            1. When memory usage is a concern. Merge Sort requires O(n) extra space, which might not be suitable for systems with limited memory.
            2. In cases where the data can fit into memory, and faster in-place sorting algorithms like quicksort or heapsort (which have O(n log n) time complexity but use O(1) additional space) might be more appropriate.

