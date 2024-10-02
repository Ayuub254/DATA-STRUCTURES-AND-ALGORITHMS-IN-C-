//
//  TIC TAC TOE project.cpp
//  TIC TAC TOE PROJECT
//
//  Created by Ayub's mac✌🏾 on 02/10/2024.
//

#include <iostream>
using namespace std;
class game{
public:
    char board[3][3] = {
        {' ', ' ',' '},
        {' ', ' ',' '},
        {' ', ' ',' '}
    };
    
    string player1;
    string player2;
    char playerX =  'X';
    char playerO =  'O';
    char currentPlayer;
    int EMPTY = 0;
    int row =-1;
    int col=-1;
    char winner = ' ';
    char choice;
    char starter;
    int player1Wins = 0;
    int player2Wins = 0;
    
    void playerNames(){
        
        cout<<"WHICH PLAYER WOULD LIKE TO START FIRST? ('A' for player1 and 'B' for player2: ) ";
        cin>>starter;
        
        if(starter == 'A'){
            currentPlayer = playerX;
        }else if (starter == 'B'){
            currentPlayer = playerO;
        }else{
            cout<<"invalid choice!!!, try again!!";
        }
        
        
        
    }
    
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
};
int main(){
    game ticTacToe;
    cout<<"TIC TAC TOE GAME\n";
    
    
    cout<<"Player 1's Name: ";
    cin>>ticTacToe.player1;
    
    cout<<"Player 2's Name: ";
    cin>>ticTacToe.player2;
   
    ticTacToe.play();
    
    
    
    
    return 0;
}
