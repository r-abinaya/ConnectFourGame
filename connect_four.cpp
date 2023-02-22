#include <iostream>

using namespace std;

const int HEIGHT = 6;
const int WIDTH = 7;
int column_choice;

//The 'O' starts first
char player_char = 'O';
char board[WIDTH][HEIGHT];

void create_board();
void print_board();
void put_piece(int);
bool check_win();
bool check_vert();
bool check_hor();
bool check_diag();
bool is_full();


int main() {
    cout << "******************************************" << endl;
    cout << "---------WELCOME TO CONNECT FOUR----------" << endl;
    cout << "******************************************" << endl;
    cout << "Press Enter to continue..." << endl;
    cin.get();
    create_board();
    cout << endl;
    //REPLACE false WITH check_win()
    while(1) {

        cin >> column_choice;
        put_piece(column_choice-1);

        if (check_win()) {
            break;
        }

        if (is_full()) {
            cout << "The Game Tied. Neither Players Win" << endl;
            return 0;
        }

        cout << player_char << "'s turn" << endl;
    }

    if (player_char == 'X') {
        player_char = 'O';
    }
    else {
        player_char = 'X';
    }

    cout << "Player " << player_char << " Wins the Game!";

    return 0;
}


//Puts in the piece into the board if the move is valid
//Also shows the current state of the board
void put_piece(int column) {
    for (int i = 0; i < HEIGHT; ++i) {
        if (board[column][i] == ' ') {
            board[column][i] = player_char;
            if (player_char == 'O') {
                player_char = 'X';
            }
            else if (player_char == 'X') {
                player_char = 'O';
            }
            print_board();
            return;
        }
    }
    cout << "INVALID MOVE" << endl;
}


//Creates a new empty space-filled board
void create_board() {
    cout << "-----------------------------" << endl;
    for (int j = HEIGHT-1; j >= 0; --j) {
        for (int i = 0; i < WIDTH; ++i) {
            board[i][j] = ' ';
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "-----------------------------" << endl;
    }
    cout << "  1   2   3   4   5   6   7" << endl;
    cout << "O starts the game" << endl;
}


//Shows the current state of the board
//requires: board must be made with create_board()
void print_board() {
    cout << "-----------------------------" << endl;
    for (int j = HEIGHT-1; j >= 0; --j) {
        for (int i = 0; i < WIDTH; ++i) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "-----------------------------" << endl;
    }
    cout << "  1   2   3   4   5   6   7" << endl;
}


//Checks the board for any wins
bool check_win() {
    return check_vert() || check_hor() || check_diag();
}


bool check_vert() {
    int x_counter = 0;
    int o_counter = 0;
    for (int j = 0; j < WIDTH; ++j) {
        for (int i = 0; i < HEIGHT; ++i) {
            if (board[i][j] == 'X') {
                x_counter++;
                o_counter = 0;
            }
            if (board[i][j] == 'O') {
                o_counter++;
                x_counter = 0;
            }
            if (board[i][j] == ' ') {
                o_counter = 0;
                x_counter = 0;
            }
            if (x_counter >= 4) {
                return true;
            }
            else if (o_counter >= 4) {
                return true;
            }
        }
        o_counter = 0;
        x_counter = 0;
    }
    return false;
}

bool check_hor() {
    int x_counter = 0;
    int o_counter = 0;
    for (int j = 0; j < HEIGHT; ++j) {
        for (int i = 0; i < WIDTH; ++i) {
            if (board[j][i] == 'X') {
                x_counter++;
                o_counter = 0;
            }
            if (board[j][i] == 'O') {
                o_counter++;
                x_counter = 0;
            }
            if (board[j][i] == ' ') {
                o_counter = 0;
                x_counter = 0;
            }

            if (x_counter >= 4) {
                return true;
            }
            else if (o_counter >= 4) {
                return true;
            }
        }
        o_counter = 0;
        x_counter = 0;
    }
    return false;
}

bool check_diag() {
    for (int i = 0; i < WIDTH - 3; ++i) {
        for (int j = 0; j < HEIGHT - 3; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] &&
                    board[i][j] == board[i + 2][j + 2] &&
                    board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }
    for (int i = 0; i < WIDTH - 3; ++i) {
        for (int j = 3; j < HEIGHT; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j - 1] &&
                    board[i][j] == board[i + 2][j - 2] &&
                    board[i][j] == board[i + 3][j - 3]) {
                return true;
            }
        }
    }
    return false;
}


//Checks if the board is full
bool is_full() {
    for (int j = HEIGHT-1; j >= 0; --j) {
        for (int i = 0; i < WIDTH; ++i) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
