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

**INSERTING ITEMS INTO A 2D ARRAY

when inserting into a 2D array, we follow the steps bellow:
1. create a for loop that will help iterate over the rows of the array.
2. create an inner for loop that will help in itterating over the collumns in each row, and insert a value in the respective i,j position in the array.

void insert(){
    for(int i =0; i < rows; i++){
        for(int j=0; j<cols; j++){
            cout<<"Enter element at index["<<i<<"]["<<j<<"]: ";
            cin>>myArray[i][j];
        }
    }
}
**DISPLAYING THE ITEMS IN A 2D ARRAY.

when displaying all the items in a 2d array, we iterarate over the two respective loops and print out the value at each position.
   
   void display(){
        for(int i = 0; i<rows; i++){
            for(int j = 0; j< cols; j++){
                cout<<myArray[i][j]<<" , ";
            }
        }
    }

**SEARCHING ITEMS IN A 2D ARRAY

when searching for an item in a 2D array, we use a bool that will help us know if we have found the desired value or not.
if the value has been found the bool is set to true and a message with the index of the value is printed out to the user.
if the bool is still set at false after iterating over the entire array, then that means that the item is absent and a message is 
printed out to the user letting them know.

void search(int value){
    bool isFound = false;
    for(int i =0; i<rows; i++){
        for(int j =0; j<cols; j++){
            if(myArray[i][j] == value){
                isFound = true;
                cout<<"The item has been found at index: ["<<i<<"]["<<j"]";
            }
            
        }
    }
    if(isFound == false){
        cout<<"The item is not in the array!!";
    }
}
