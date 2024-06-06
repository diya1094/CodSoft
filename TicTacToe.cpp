#include <iostream>
#include <array>
using namespace std;

// declaration
const int s = 3;
char grid[3][3] = {{'0','1','2'},{'3','4','5'},{'6','7','8'}};
char space[s][s] = { {' ',' ', ' '}, { ' ', ' ', ' '},{ ' ', ' ',' '}};
string n1,n2;
char ch;
int num;

//printing game board
void board(char grid[s][s]){
    // board grid
    cout << "    |      |    " << endl;
    cout << "  " << grid[0][0] << " |  " << grid[0][1] << "   |  " << grid [0][2]<<endl;
    cout << "    |      |    " << endl;
    cout << "--------------------" << endl;
    cout << "    |      |    " << endl;
    cout << "  " << grid[1][0] << " |  " << grid[1][1] << "   |  " << grid [1][2]<<endl;
    cout << "    |      |    " << endl;
    cout << "--------------------" << endl;
    cout << "    |      |    " << endl;
    cout << "  " << grid[2][0] << " |  " << grid[2][1] << "   |  " << grid [2][2]<<endl;
    cout << "    |      |    " << endl << endl;
}

//game function 
void game(){
    int r,c;
    //locating input place
    switch (num) {
        case 0: 
            r = 0; 
            c = 0; 
            break;
        case 1: 
            r = 0; 
            c = 1; 
            break;
        case 2: 
            r = 0; 
            c = 2; 
            break;
        case 3: 
            r = 1; 
            c = 0; 
            break;
        case 4: 
            r = 1; 
            c = 1;
            break;
        case 5: 
            r = 1; 
            c = 2; 
            break;
        case 6: 
            r = 2; 
            c = 0;
            break;
        case 7: 
            r = 2; 
            c = 1;
            break;
        case 8: 
            r = 2; 
            c = 2; 
            break;
        default:
            cout << "Invalid place" << endl; 
            return;
    }

    if (space[r][c] == ' '){
        space[r][c] = ch;
        ch = (ch == 'X') ? '0' : 'X';
    } else {
        cout << "Place is already assigned." << endl;
    }
}

bool checkWin(char space[s][s]){
    for (int i=0; i<3; i++){
        // check horizontial and vertical win
        if((space[i][0] == space[i][1] && space[i][0] == space[i][2] && space[i][0] != ' ') || (space[0][i] == space[1][i] && space[0][i] == space[2][i] && space[0][i]!= ' ')){
            return true;
        }
    }

    // checks left and right diagonal win
    if ((space[0][0] == space[1][1] && space[0][0] == space[2][2] && space[0][0] != ' ') || (space[0][2] == space[1][1] && space[0][2] == space[2][0] && space[0][2] != ' ')){
        return true;
    }

    return false;
}

bool checkTie(char space[s][s]){
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++){
            if (space[i][k] == ' '){ 
                return false;
            }
        }
    }
    return true;
}

int main(){ 
    bool end = false;
    cout << endl <<  "WELCOME TO TIC TAC TOE GAME" << endl;

    //enter player name
    cout << "Enter name of player 1: ";
    getline(cin, n1);
    cout << "Enter name of player 2: ";
    getline(cin, n2);

    cout << "Player 1 has been assigned X and Player 2 has been assigned 0" << endl;

    ch = 'X';

    board(grid);

    while(!end){
        board(space);
        if(ch == 'X'){
            cout << endl << n1 << "'s turn. Enter number(0-8): ";
            cin >> num;
        }
        else{
            cout << endl <<  n2<< "'s turn. Enter number(0-8): ";
            cin >> num;
        }

        game();

        if (checkWin(space)) {
            board(space);
            cout << ((ch == 'X') ? n2 : n1) << " wins!" << endl;
            end = true;
        } 
        else if (checkTie(space)) {
            board(space);
            cout << "It's a tie!" << endl;
            end = true;
        }
    }
    return 0;
}