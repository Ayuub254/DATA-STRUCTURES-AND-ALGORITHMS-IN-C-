#  QUICKSORT ALGORITHM
Before diving deep into how the quick sort algorithm works, we first need to have a good understanding of how partitioning works. 

The main aim of the partitioning process in the QuickSort algorithm is to rearrange the elements of the array around a chosen pivot element in such a way that:

    1. Elements smaller than or equal to the pivot are placed to the left of the pivot.
    2. Elements larger than the pivot are placed to the right of the pivot.
    
After the partitioning is complete:

    1. The pivot element is in its correct sorted position in the array.
    2. The subarray to the left of the pivot contains elements that are less than or equal to the pivot.
    3. The subarray to the right of the pivot contains elements that are greater than the pivot.
**HOW PARTITIONING WORKS

    1. Choose a pivot: The partitioning process typically begins by choosing a pivot element, which could be the first element, last element, or even a random element.
    2. Rearrange elements: The process then rearranges the array such that all elements less than or equal to the pivot are on one side (left) and all elements greater than the pivot are on the other side (right).
    3. Recursive sorting: After the partitioning is done, QuickSort recursively sorts the left and right subarrays, but the pivot is already sorted and does not need to be moved.
    
The follwoing is the code for the partitioning part of the quicksort algorithm.

    int Partition(int Arr[], int low, int high){
        int pivot = Arr[low];
        int i = low + 1;
        int j = high;
        
        while(i <= j){
            while(i <= j && A[i] <= pivot){
                i++;
            }
            while(i <= j && A[j] > pivot){
                j++;
            }
            
            if(i < j){
                swap(Arr[i], Arr[j]);
            }
        }
        swap(Arr[low], Arr[j]);
        return j;
    }

**EXPLANATION

    1. The Partition function takes three parameters that are
            1. The array to be sorted
            2. The beging of the array(low)
            3. The end of the array(high)
        The above parameteres will help us in traversing the array in finding the suitable positions for the pivot.
        
    2. The second part of the function helps us in assigning the pivot and the i and j varriables that are to be placed on either ends of the array. The i is placed 1 step after the low variable hence (int i = low + 1), while the j is placed at the end of the array and since high is at the end of th array, therefore (int j = high).
    
    3. We traveres the list only on one condition which is, aslong as i is less than j. therefore( while(i < j)).
    4. When traversing the list, there are certain conditions that need to be met before incrementing and decrementing i and j respectively.
        1. i can only be incremented by 1 aslong as:
            a. i is less than or equal to j(i <= j). 
                           OR
            b. The element at position i is less than or equal to the pivot.(A[i]<=pivot)
            
        2. j can only be decremented by 1 aslong as:
            a. i is less than or equal to j
                           OR
            b. The element at position j is greater than the pivot. (A[j] > pivot).
            
        Only when the above two conditions are met can we incrementand decrement the values i and j respectively.
        
    5. After every step (either incremnting i or decrementing j), we check to see if i is still less than j.(i<j). if so, it means we have found an element on the left side that is greater than the pivot and an element of the right side that is smaller or equal to the pivot, therefore we swap them. (swap(Arr[i], Arr[j])).
    
    6. In the end, when incrementing and decrementing has stopped, this means that we have found the correct position to place our pivot and therefore, we swap the pivot with the element at position j. (swap(Arr[low] , Arr[j])) and return the true position of j fo further recursive sorting.(return j).
    
Now that we have a clear aunderstanding of partitioning works, we can take a look at the Quick sort algorithm.

    void QuickSort(int Arr[], int low, int high){
        if(low < high){
            int pivotPosition = Partition(Arr, low, high);
            
            QuickSort(Arr, low, j-1);
            QuickSort(Arr, j+1, high);
        }
    }
    
** EXPLANATION

    1.  check whether there is more than one element to sort in the current portion of the array.(if(low < high)).
            a. If low is greater than or equal to high, it means the array (or sub-array) has only one element or is empty, so there is nothing to sort, and the recursion stops.
            b. For example, if low == high, you have one element, which is already sorted.

    2. The Partition function is called to divide the array into two parts based on a pivot element. (int pivotPosition = Partition(Arr, low, high));
        a. The pivot element is usually chosen as the first element of the array (in this case, Arr[low]).
        b. The Partition function rearranges the array so that:
            i. Elements smaller than or equal to the pivot go to the left side of the pivot.
            ii. Elements larger than the pivot go to the right side of the pivot.
        c. The Partition function returns the index of where the pivot element is now placed in the array (let's call this pivotPosition).
        
    3. After partitioning, the pivot element is in its correct position.
        a. The elements to the left of the pivot need to be sorted. So, the QuickSort function is called recursively on the left sub-array, from index low to pivotPosition - 1
        b. This step continues dividing the left sub-array into smaller sub-arrays until the base case (low >= high) is reached, meaning the sub-array has one or no elements and is already sorted.
    
    4. Similarly, the elements to the right of the pivot need to be sorted. So, the QuickSort function is called recursively on the right sub-array, from index pivotPosition + 1 to high.
        a. This step also continues dividing the right sub-array into smaller sub-arrays, repeating the partitioning process, until the base case is met and everything is sorted.
        
**ALGORITHM ANALYSIS

    1. BEST CASE: O(n log n)
    2. AVERAGE CASE: O(n log n)
    3. WORST CASE: O(n²)
    4. STABLE: No, QuickSort is not stable. Stability means that if two elements have the same value, their relative order remains the same in the sorted array. However, QuickSort may not guarantee this because of how elements are swapped during partitioning.
    5. TIME COMPLEXITY: 
        a. BEST CASE: O(n log n)
        b. AVERAGE CASE: O(n log n)
        C. WORST CASE: O(n²)
    6. SPACE COMPLEXITY: 
        a. BEST CASE: O(log n)
        b. WORST CASE: O(n)
    7. WHEN TO USE: 
        1. When average performance is more important, and you want a sorting algorithm with a relatively efficient O(n log n) time complexity.
        2. When in-place sorting (minimal extra space) is required.
        3. QuickSort works well for arrays or lists where performance matters for the average case, such as in many general-purpose applications.
        
    8. WHEN NOT TO USE:
        1. Avoid using QuickSort when the input array is already sorted (or nearly sorted) because it results in the worst-case O(n²) performance.
        2. Avoid using it when stability is essential (like when sorting objects that should maintain their relative order based on a non-sorting key).
        3. If memory consumption is a concern, especially in worst-case recursive depth scenarios, you might consider other algorithms like MergeSort (O(n) space) or an iterative version of QuickSort.
    
        
        
