#  TIC TAC TOE EXPLANATION

Tic tac toe is a fun and easy game one can play with friends and thanks to me:)) you can now learn how to make your own version
of the game.(in the terminal :) )

The concepts one should grasp before attempting the project bellow are:
1. 2D ARRAYS IN C++
2. A good grasp of control statements
3. OOP in c++

The first step before actaully attempting this project is:
1. Break down the entire project into bits to make it easy:
    a.Displaying the board.
    b.Getting user's input
    c. Determining winners and Ties
    
**DISPLAYING THE BOARD IN THE CONSOLE

1. Before displaying the board we first initialize a 2D Array that will be used in storing and displaying the user's input

    char board[3][3] = {
        {' ', ' ',' '},
        {' ', ' ',' '},
        {' ', ' ',' '}
    };

2. The following method display an empty playing board in the console.

    void displayBoard(){
        
        cout<<"    |     |    "<<endl;
        cout<<" "<<board[0][0] << "  |  "<<board[0][1]<<"  |  "<<board[0][2]<<endl;
        cout<<"    |     |    "<<endl;
        cout<<"----+-----+----"<<endl;
        cout<<" "<<board[1][0] << "  |  "<<board[1][1]<<"  |  "<<board[1][2]<<endl;
        cout<<"    |     |    "<<endl;
        cout<<"----+-----+----"<<endl;
        cout<<" "<<board[2][0] << "  |  "<<board[2][1]<<"  |  "<<board[2][2]<<endl;
        cout<<"    |     |    "<<endl;
    }

**PLAYING LOGIC

1. The method bellow determines the game logic

    void play(){
        playerNames();
        for(int i=0; i<9; i++){
            displayBoard();
            
            if(winner != ' '){
                break;
            }
            if(currentPlayer == playerX){
                cout<<"Current player is: "<<player1<<endl;
            }else if (currentPlayer == playerO){
                cout<<"Current player is: "<<player2<<endl;
            }
            while(true){
                cout<<"Input values in range 0-2 for row and col: ";
                cin>>row>>col;
                if(row <0 || row >2 || col <0 || col >2){
                    cout<<"Invalid input, try again!!"<<endl;
                }
                else if(board[row][col] != ' '){
                    cout<<"Tile is full, try another tile!!"<<endl;
                }
                else{
                    break;
                }
                row = -1;
                col = -1;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            board[row][col] = currentPlayer;
            currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
            win();
        }
        if(winner!=' '){
            if(winner == 'X'){
                cout<<"Winner is: "<<player1 <<endl;
                player1Wins = player1Wins + 1;
            }else if(winner == 'O'){
                cout<<"Winner is: "<<player2 <<endl;
                player2Wins = player2Wins + 1;
            }
            
        }else{
            cout<<"TIE!!"<<endl;
        }
        
        cout<<"SCORE BOARD:  PLAYER 1  :  PLAYER 2\n";
        cout<<"The Game is: "<<player1Wins<<" : "<<player2Wins<<endl;
    }
    
To determine the winner the follwoing method is put into play:

    void win(){
        for(int r=0; r<3; r++){
            if(board[r][0]!=' ' && board[r][0]==board[r][1] && board[r][1]==board[r][2]){
                winner = board[r][0];
                break;
            }
        }
        
        for(int c=0; c<3; c++){
            if(board[0][c]!=' ' && board[0][c]==board[1][c] && board[1][c]==board[2][c]){
                winner = board[0][c];
                break;
            }
        }
        
        if(board[0][0]!=' ' && board[0][0]==board[1][1] && board[1][1]==board[2][2]){
            winner = board[0][0];
        }
        
        if(board[0][2]!=' ' && board[0][2]==board[1][1] && board[1][1]==board[2][0]){
            winner = board[0][0];
        }
        
        
        
    }





