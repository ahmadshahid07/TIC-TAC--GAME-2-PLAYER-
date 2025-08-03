#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

void displayBoard() {
    system("cls");
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++)
            cout << board[i][j] << (j < 2 ? " | " : "");
        cout << "\n" << (i < 2 ? "---|---|---\n" : "");
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++)
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2]) return true;
    for (int i = 0; i < 3; i++)
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i]) return true;
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]) return true;
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0]) return true;
    return false;
}

int main() {
    int move, player = 1;
    char mark;

    do {
        displayBoard();
        player = (player % 2) ? 1 : 2;
        cout << "\nPlayer " << player << ", enter your move (1-9): ";
        cin >> move;
        mark = (player == 1) ? 'X' : 'O';

        int row = (move - 1) / 3, col = (move - 1) % 3;
        if (move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = mark;
        } else {
            cout << "Invalid move!\n";
            player--;
        }

        if (checkWin()) {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }

        player++;
    } while (player <= 9);

    return 0;
}
