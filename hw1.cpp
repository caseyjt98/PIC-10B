//
//  main.cpp
//  10B.hw1
//
//  Created by Casey Taylor on 9/28/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

//  I, CASEY TAYLOR, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
//  I did not copy code from anyone, student or otherwise.


#include <iostream>
#include <string>
#include <vector>
using namespace std;


//PLAYER CLASS
class Player {
public:
    //constructor
    Player(string n); // n is name
    //declare public functions
    void addWin();
    string const getName();
    int const getWinCount();
private:
    // member variables
    string name;
    int winCount;
    vector<string> board;
    
};
//define constructor
Player::Player(string n){
    name = n;
    winCount=0; //initialize win count to 0
}

/*This function allows for the retrieval of an inputted player name
 @returns string name, representing the name of the player
 */
string const Player::getName(){
    return name;
}

/*This function keeps track of # of rounds won by adding to a player's win count
 @param N/A
 @returns void
 */
void Player::addWin(){
    winCount++;
}

/*This function allows for the retrieval of a player's win count
 @param N/A
 @returns int winCount, representing the number of wins each player has
 */
int const Player::getWinCount(){
    return winCount;
}


//BOARD CLASS
class Board {
public:
    Board();
    string gameStatus();
    void displayBoard();
    void clear();
    void addMarker(string rowCol, string marker);
private:
    vector<string> spaces;
    
};

Board::Board(){
    //loop creates 9 empty spaces within spaces vector
    for(int i=0; i < 9; i++){
    spaces.push_back(" ");
    }
   
}
/*This function prints out the empty board
 @param N/A
 @returns void
 */
void Board::displayBoard() {
    cout << "\n   1" << "  2" << "  3";
    cout << "\n 1 " << spaces[0] << " | " << spaces[1] << " | " << spaces[2];
    cout << "\n" << "  ---------";
    cout << "\n 2 " << spaces[3] << " | " << spaces[4] << " | " << spaces[5];
    cout << "\n" << "  ---------";
    cout << "\n 3 " << spaces[6] << " | " << spaces[7] << " | " << spaces[8];
    cout << endl << endl;
    return ;
}

/*This function clears the board by emptying each space in the vector
 @param N/A
 @returns void
 */
void Board::clear(){
    //loop through vector 0-8 and clear each space by inputting an empty space ' '
    for(int i=0; i < 9; i++){
        spaces[i] = " ";
    }
}

/*This function adds player marker to correct space on the board based on inputted rowCol
 @param string rowCol; represents the player's inputted row and column aka where they would like to place their marker
 @param string marker represents 'x' or 'o' markers
 @returns void
 */
void Board::addMarker(string rowCol, string marker){
    int row;
    int column;
    int index;
    row = stoi(rowCol.substr(0,1)); //extract row & convert string to int
    column = stoi(rowCol.substr(2,1)); //extract column & convert string to int
    
    //algorithm to determine index based on inputted row/ column
    index = (row-1)*3 + (column-1);
    
    //if spot is already taken, alert player
    if (spaces[index] != " "){
        cout << "Error. This space is taken. Proceed to next player's turn." << endl << endl;
        
    }
        else{ //if spot is open, add player marker
            spaces[index] = marker;
        }
}

/*This function checks the status of the game, indicating if it should continue to the next player's turn
 @param N/A
 @returns string status represents the possible game outcomes (continue game, x wins, o wins, or draw)
 */
string Board::gameStatus(){
    //default status is continue game
    string status = "continue";
    
    //outline all possible winning combinations
    string rowOne = spaces[0] + spaces[1] + spaces[2];
    string rowTwo = spaces[3] + spaces[4] + spaces[5];
    string rowThree = spaces[6] + spaces[7] + spaces[8];
    string colOne = spaces[0] + spaces[3] + spaces[6];
    string colTwo = spaces[1] + spaces[4] + spaces[7];
    string colThree = spaces[2] + spaces[5] + spaces[8];
    string diagOne = spaces[0] + spaces[4] + spaces[8];
    string diagTwo = spaces[2] + spaces[4] + spaces[6];
    
    //check all possible x combinations
    if ((rowOne == "xxx") ||
        (rowTwo == "xxx") ||
        (rowThree == "xxx") ||
        (colOne == "xxx") ||
        (colTwo == "xxx") ||
        (colThree == "xxx") ||
        (diagOne == "xxx") ||
        (diagTwo == "xxx")) {
        
        //if one of these combinations exists, x has won
        status = "x wins";
        
    }
    
    //check all possible o combinations
    
    if ((rowOne == "ooo") ||
        (rowTwo == "ooo") ||
        (rowThree == "ooo") ||
        (colOne == "ooo") ||
        (colTwo == "ooo") ||
        (colThree == "ooo") ||
        (diagOne == "ooo") ||
        (diagTwo == "ooo")) {
        
        //if one of these combination exists, o has won
        status = "o wins";
    }

    
    //check for draw
    int i = 0; //initialize index to 0
    while((spaces[i] != " ") && (i < 9)){ //check for full board
        i++;
    }
    if(i == 9){ //if while loop executes to completion, board is full
        status = "draw"; //full board indicates a draw
    }
    
    return status;
    
}


int main() {

    string playerName;
    string sNumberOfRounds; //string for inputted number of rounds
    int numberOfRounds = 0;
    string rowCol;
    
    //welcome!
    cout << "This is a Tic Tac Toe game!" << endl;
    
    //get player one name and create object within player class
    cout << "Pleast enter the name of player 1: ";
    getline (cin, playerName);
    Player playerOne(playerName);
    
    
    //get player two name and create object within player class
    cout << endl << "Thanks. Please enter the name of player 2: ";
    getline (cin, playerName);
    Player playerTwo(playerName);
    
    
    //prompt for preferred number of rounds
    cout << "How many rounds would you like to play?" << endl;
    getline(cin, sNumberOfRounds);
    cout << "Let the game begin!" << endl;
    
    //convert string to integer
    numberOfRounds = stoi(sNumberOfRounds);
    
    //repeat process of individual round depending on requested number of rounds
    for(int i=1; i <= numberOfRounds; i++){
        
        //create board object & display board
        Board board;
        board.displayBoard();
        
        //repeat player turns until round is completed
        while(board.gameStatus() == "continue"){
            
            //player one's turn, assume x plays first
            cout << "It is " << playerOne.getName() << "'s turn." << endl;
            cout << "Where would you like to play? Enter your row position and column position: row col: ";
            getline(cin,rowCol);
            
            
            //add player one's marker to board
            board.addMarker(rowCol, "x");
            board.displayBoard();
            
            
            //check game status
            //if status is continue, continue with next player's turn
            if (board.gameStatus() == "continue"){
            
                //player two's turn
                cout << "It is " << playerTwo.getName() << "'s turn." << endl;
                cout << "Where would you like to play? Enter your row position and column position: row col: ";
                getline(cin,rowCol);

                //add player two's marker to board
                board.addMarker(rowCol, "o");
                board.displayBoard();
                
        
            }
        }
        
        
        //refer to game status and check who won the round
        if(board.gameStatus() == "x wins"){
            //add win to player object
            playerOne.addWin();
            cout << playerOne.getName() << " won the round!" << endl;
        }
        else if(board.gameStatus() == "o wins"){
            //add win to player object
            playerTwo.addWin();
            cout << playerTwo.getName() << " won the round!" << endl;
        }
        //if no one won, the game is a draw.
        else{
            cout << "Draw." << endl;
        }
        
        //print each player's current scores
        cout << "Presently, " << playerOne.getName() << " has " << playerOne.getWinCount() << " points and " << playerTwo.getName() << " has " << playerTwo.getWinCount() << " points." << endl;
    }
    
    // if player one has won more rounds
    if(playerOne.getWinCount() > playerTwo.getWinCount()){
        //player one wins
        cout << playerOne.getName() << " wins!" << endl;
    }
    //if player two has won more rounds
    else if(playerTwo.getWinCount() > playerOne.getWinCount()){
        //player two wins
        cout << playerTwo.getName() << " wins!" << endl;
    }
    //otherwise, it's a draw
    else{
        cout << "It's a draw!" << endl;
    }

    
return 0;
}




