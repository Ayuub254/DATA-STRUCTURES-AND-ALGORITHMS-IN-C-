#  2DIMENSIONAL ARRAYS (2D ARRAYS)

A Two dimensional array is basically an array within an array. i.e.
    int myArray[2][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
what the above array means is that, there is an array with 2 rows and 3 collumns. 
each row holds three fields of data.

**INITIALIZING A TWO DIMENSIONAL ARRAY IN C++

In c++, to create a dynamic 2D array, we usually use double pointers. The following is an indepth explanation.

In the code bellow:
    1. we have initialzed the rows and the collumns for the 2D array.
    2. created an instance of the 2d array using a two pointer varriable
    3. We then assigned the no of rows the array is supposed to have and for each row we have assigned the desired collumns.
    
    


    Using namespace std;
    class Array{
        public:
        int rows;
        int cols;
        
        int** myArray;
        
        void insert(){
            cout<<"Enter prefered length of rows: ";
            cin>>rows;
            cout<<"Enter prefered length of collumns: ";
            cin>>cols;
            
            myArray = new int*[rows]; // initialize an array with the length of rows.
            for(int i=0 i<rows; i++){ // for each row create a collumn.
                myArray[i] = new int[cols];
            }
        }
    };
   

