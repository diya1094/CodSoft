#include <cstdlib> 
#include <iostream> 
#include <time.h> 

using namespace std; 

int n;

void game(){
    const int N = 20; 
    int num = rand() % N + 1; 
    cout << "Guess a number between 1-20: ";
    while(true){ 
        cin >> n; 
        if(n > 20 || n < 1){
            cout << "Invalid Input. Guess a number between 1-20: " ;
            continue;
        }
        if(num == n){
            cout << "Number found" << endl;
            break;
        }
        else if(num<n){
            cout << "Too High" << endl;
        }
        else{
            cout << "Too Low" << endl;
        }
        cout << "Guess again: ";
    }
}

int main(){ 
    char playAgain;
    cout << "----WELCOME TO NUMBER GUESSING GAME----" << endl;

    srand(time(0));

    do{

        game();
        cout << "Do you want to play again (Y/N): ";
        cin >> playAgain;

    }while(playAgain == 'y' || playAgain == 'Y');

	return 0; 
}