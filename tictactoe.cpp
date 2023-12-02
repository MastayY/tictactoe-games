#include <iostream>
#include <windows.h>
#include <limits>
#include <cstdlib>
#include <time.h>

using namespace std;

void displayBoard(const string board[9]) {
    cout << "=====================================" << endl;
    cout << "           TicTacToe Games           " << endl;
    cout << "=====================================" << endl;
    cout << "Dibuat oleh Mastay\nSocial Media :\nIG : https://instagram.com/nniceone._\nGithub : https://github.com/MastayY\n" << endl;
    cout << "KETERANGAN :\nPlayer : 'X'\nComputer : 'O'" << endl;
    cout << "=====================================\n" << endl;

    cout << "\t     |     |     " << endl;
    cout << "\t  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
    cout << "\t     |     |     " << endl << endl;

    cout << "\n=====================================" << endl;
}

int evaluate(string board[9]) {
    for (int row = 0; row < 3; row++) {
        if (board[row * 3] == board[row * 3 + 1] && board[row * 3 + 1] == board[row * 3 + 2]) {
            if (board[row * 3] == "O") {
                return 10;  // Computer wins
            } else if (board[row * 3] == "X") {
                return -10;  // Player wins
            }
        }
    }

    for (int col = 0; col < 3; col++) {
        if (board[col] == board[col + 3] && board[col + 3] == board[col + 6]) {
            if (board[col] == "O") {
                return 10;  // Computer wins
            } else if (board[col] == "X") {
                return -10;  // Player wins
            }
        }
    }

    if (board[0] == board[4] && board[4] == board[8]) {
        if (board[0] == "O") {
            return 10;  // Computer wins
        } else if (board[0] == "X") {
            return -10;  // Player wins
        }
    }

    if (board[2] == board[4] && board[4] == board[6]) {
        if (board[2] == "O") {
            return 10;  // Computer wins
        } else if (board[2] == "X") {
            return -10;  // Player wins
        }
    }

    return 0;
}

int minimax(string board[9], int depth, bool isMaximizing) {
    int score = evaluate(board);
    if (score == 10) {
        return score - depth;
    }
    if (score == -10) {
        return score + depth;
    }
    if (depth == 9) {
        return 0;
    }

    if (isMaximizing) {
        int bestScore = numeric_limits<int>::min();

        for (int i = 0; i < 9; i++) {
            if (board[i] == " ") {
                board[i] = "O";
                int currentScore = minimax(board, depth + 1, false);
                board[i] = " ";  

                bestScore = max(bestScore, currentScore);
            }
        }

        return bestScore;
    } else {
        int bestScore = numeric_limits<int>::max();

        for (int i = 0; i < 9; i++) {
            if (board[i] == " ") {
                board[i] = "X";
                int currentScore = minimax(board, depth + 1, true);
                board[i] = " ";  

                bestScore = min(bestScore, currentScore);
            }
        }

        return bestScore;
    }
}

int findBestMove(string board[9]) {
    int bestVal = numeric_limits<int>::min();
    int bestMove = -1;

    for (int i = 0; i < 9; i++) {
        if (board[i] == " ") {
            board[i] = "O";
            int moveVal = minimax(board, 5, false);
            board[i] = " ";  // Undo the move

            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }

    return bestMove;
}

int main() {
    string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ",  " "};
    // int leaderboard[50];
    int turn = 1;
    char again;
    int move = 0;

    while(true) {
        int choice;

        system("cls");

        if(evaluate(board) == -10) {
            displayBoard(board);
            cout << "\nPlayer 1 Menang\n" << endl;

            cout << "Main lagi? ";
            cin >> again;

            if (again == 'y' || again == 'Y') {
                for (int i = 0; i < 9; i++) {
                    board[i] = " ";
                }
                move = 0;
                turn = 1;
                
            } else {
                break;
            }
            
        } else if(evaluate(board) == 10) {
            displayBoard(board);
            cout << "\nComputer Menang\n" << endl;
            
            break;
        } else if(evaluate(board) == 0 && move > 7) {
            displayBoard(board);
            cout << "\nDRAW!!\n" << endl;
            
            break;
        }

        displayBoard(board);

        if(turn == 1) {
            cout << "Player " << turn << " masukkan nomor index papan : ";
            cin >> choice;
            switch(choice) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                    if(board[choice - 1] != "X" && board[choice - 1] != "O") {
                        board[choice - 1] = "X";
                        turn = 2;
                        move += 1;
                    } else {
                        cout << "\n[ERROR] Pilihan sudah diisi\n" << endl;
                    }

                    break;

                default:
                    cout << "\n[ERROR] Pilih papan dari 1-9\n" << endl;
                    break;
            }
        } else {
            if (move <= 1) {
                srand((unsigned) time(NULL));
                int index = rand() % 9;

                while (board[index] != " ") {
                    index = rand() % 9;
                }

                turn = 1;

                board[index] = "O";
            } else {
                int bestMove = findBestMove(board);
                board[bestMove] = "O";
                turn = 1;
                cout << "Komputer sedang berpikir......";
                Sleep(3000);
            }
        }

    }
}
