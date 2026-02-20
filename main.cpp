#include <iostream>
#include <vector>
#include <cmath>
#include <random>
using namespace std;

int BOARD_SIZE = 5;

vector<vector<char> > makeBoard(){
    vector<vector<char> > board;

    for (int i = 0; i < BOARD_SIZE; i++){
        vector<char> row;
        if (i == 0 || i == BOARD_SIZE-1){
            for (int j = 0; j < BOARD_SIZE; j++){
                row.push_back('#');
            }
            board.push_back(row);
        }
        else{
            row.push_back('#');
            for (int j = 0; j < BOARD_SIZE-2; j++){
                row.push_back('*');
            }
            row.push_back('#');
            board.push_back(row);
        }
    }
    return board;
}

void printBoard(vector<vector<char> > board){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}

// void robotMovement(vector<vector<char> > board, char move, int x_pos, y_pos){
// }

int main(){
    srand(time(0));

    int x_pos = 1;
    int y_pos = 1;
    char move;

    vector<vector<char> >board = makeBoard();
    board[x_pos][y_pos] = 'R';
    board[1][BOARD_SIZE-2] = 'D';
    board[rand()% (BOARD_SIZE-3) + 2][rand()% (BOARD_SIZE-2) + 1] = 'P';

    printBoard(board);
    do{
        cout << "How would you like to move the robot use WASD" << endl;
        cout << "If you would like to exit type (E)" << endl;
        cout << "Your response: ";
        cin >> move;
        move = toupper(move);
        bool validMove = false;

        int new_x = x_pos;
        int new_y = y_pos;

        if (move == 'E'){
            cout << "Thank you for playing";
            break;
        }
        
        else if(move == 'W'){
            new_y = y_pos-1;
            validMove = true;
        }

        else if(move == 'A'){
            new_x = x_pos-1;
            validMove = true;
        }

        else if(move == 'S'){
            new_y = y_pos+1;
            validMove = true;
        }
        
        else if(move == 'D'){
            new_x = x_pos+1;
            validMove = true;
        }

        else{
            cout << "Invalid move, try again!" << endl;
        }

        if(validMove){
            if(board[new_y][new_x] != '#'){

                if(board[new_y][new_x] == 'P'){
                    
                }
                board[y_pos][x_pos] = '*';
                y_pos = new_y;
                x_pos = new_x;
                board[y_pos][x_pos] = 'R';
                printBoard(board);
            }

            else{
                cout << "Invalid move, try again!" << endl;
            }
        }

        /*
        - make it not possible for 'R' to pass 'D' until it has 'P' which means that it 'R' should be '@'
        - We should make it once that 'R' touches 'P' it turns into '@' and also a print message saying that successfully collected package
        - We should make it that when the 'R' reaches 'D' we print out a message for successful delivery*/

        

    } while(move != 'E');




}