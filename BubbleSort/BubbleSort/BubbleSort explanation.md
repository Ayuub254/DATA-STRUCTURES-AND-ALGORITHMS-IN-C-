#  BUBBLE SORT ALGORITHM

When it comes to the bubble sort algorithm to best explain how it works we can use an unsorted array,

    int myArray[] = {8,5,7,3,2};
    
In the above array we can clearly notice that it has 5 elements aof which they are in an unsorted manner.Before actually attempting to 
write down the algorithm, lets try and sort it mannualy.

    8, 5, 7, 3, 2. -> ORIGINAL ARRAY.
    
    PASS #1: We compare the first two elements of the array (8 and 5), we can notice that 5 is smaller than 8 and it should come before 8, 
        therefore, we swap their positions. we do this with the other elements in the array untill we reach the end. By the end of the first pass,
        we notice that the largest element in the array is sorted. We repeat these steps untill all the items in the array are sorted.
        
        Results for PASS #1:
            Comparisons = 4;
            Max swaps = 4;
            Resulting array = 5, 7, 3, 2, 8.
            
        Results for PASS #2;
            Comparisons = 3;
            Max swaps = 3;
            Resulting array = 5, 3, 2, 7, 8.
            
        Results for PASS #3;
            Comparisons = 2;
            Max swaps = 2;
            Resulting array = 3, 2, 5, 7, 8.
            
        Results for PASS #4;
            Comparisons = 1;
            Max swaps = 1;
            Resulting array = 2, 3, 5, 7, 8.
            
            
From analyzing the above data we can comfortably conclude that for every array that has n number of elements, it will have:
    1. n-1 number of passes
    2. n-1 number of swaps
    
    
NOTE: 
    1. BEST CASE SCENARIO FOR BUBBLE SORT WILL BE O(n);
    2. WORST CASE SCENARIO FOR BUBBLE SORT WILL BE O(n^2);
    
    
    
Having the inforamtion bellow, lets analyze the function that will execute the above algorithm.

void bubbleSort(int Arr[], int n){
    bool isSwapped; // keep track if elements are swapped
    for(int i = 0; i < n-1; i++){ // executing the number of passes.
        isSwapped = false;
        for(int j = 0; j<n-1-i; j++){ // Conducting comparison and swaps
            if(Arr[j] > Arr[j+1]){
                swap(Arr[j], Arr[j+1]);
                isSwapped = true;
            }
        }
        if(isSwapped == false){
            cout<<"Array is already sorted!!";
            break;
        }
    }
}


in above algorithm, we used 'n-1-i' in the second for loop because after every pass the number of comaprisons reduce by 1.

**BUBBLE SORT ALGORITHM ANALYSIS:
    1. Best case    -> O(n)
    2. Average case -> O(n^2)
    3. Worst case   -> O(n^2)
    4. Space complexity -> O(1)
    5. Stable           -> YES
    6. When to use      -> small datasets, partialy sorted datasets.
    7. When not to use  -> large datasets, Random unsorted data.
     

            
