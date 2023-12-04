#include <iostream>
#include <windows.h>
#include <limits>
#include <cstdlib>
#include <time.h>

using namespace std;

void displayBoard(string board[9], int round, int maxRound) {
    cout << "======================================" << endl;
    cout << "            TicTacToe Games           " << endl;
    cout << "======================================" << endl;
    cout << "Dibuat oleh Mastay\nSocial Media :\nIG : https://instagram.com/nniceone._\nGithub : https://github.com/MastayY\n" << endl;
    cout << "KETERANGAN :\nPlayer : 'X'\nComputer : 'O'" << endl;
    cout << "\n============== [ " << round << "/" << maxRound << " ] ==============\n" << endl;

    cout << "\t       |     |     " << endl;
    cout << "\t    " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
    cout << "\t  _____|_____|_____" << endl;
    cout << "\t       |     |     " << endl;
    cout << "\t    " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
    cout << "\t  _____|_____|_____" << endl;
    cout << "\t       |     |     " << endl;
    cout << "\t    " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
    cout << "\t       |     |     " << endl << endl;

    cout << "======================================\n" << endl;
}

int evaluate(string board[9]) {
    for (int row = 0; row < 3; row++) {
        if (board[row * 3] == board[row * 3 + 1] && board[row * 3 + 1] == board[row * 3 + 2]) {
            if (board[row * 3] == "O") {
                return 10;  
            } else if (board[row * 3] == "X") {
                return -10;  
            }
        }
    }

    for (int col = 0; col < 3; col++) {
        if (board[col] == board[col + 3] && board[col + 3] == board[col + 6]) {
            if (board[col] == "O") {
                return 10;  
            } else if (board[col] == "X") {
                return -10;  
            }
        }
    }

    if (board[0] == board[4] && board[4] == board[8]) {
        if (board[0] == "O") {
            return 10;  
        } else if (board[0] == "X") {
            return -10;  
        }
    }

    if (board[2] == board[4] && board[4] == board[6]) {
        if (board[2] == "O") {
            return 10;  
        } else if (board[2] == "X") {
            return -10;  
        }
    }

    return 0;
}

bool isMovesLeft(string board[9]) 
{ 
    for (int i = 0; i < 9; i++) 
        if (board[i] == " ") {
            return true; 
        } 
    return false; 
} 

int minimax(string board[9], int depth, bool isMaximizing) {
    int score = evaluate(board);
    if (score == 10) {
        return score;
    }
    if (score == -10) {
        return score;
    }
    if (depth == 0) { 
        return 0;
    }

    if (isMovesLeft(board) == false) {
        return 0;
    }

    if (isMaximizing) {
        int bestScore = -1000;

        for (int i = 0; i < 9; i++) {
            if (board[i] == " ") {
                board[i] = "O";
                int currentScore = minimax(board, depth + 1, !isMaximizing);
                board[i] = " ";  

                bestScore = max(bestScore, currentScore);
            }
        }

        return bestScore;
    } else {
        int bestScore = 1000;

        for (int i = 0; i < 9; i++) {
            if (board[i] == " ") {
                board[i] = "X";
                int currentScore = minimax(board, depth + 1, !isMaximizing);
                board[i] = " ";  

                bestScore = min(bestScore, currentScore);
            }
        }

        return bestScore;
    }
}

int findBestMove(string board[9], int depth) {
    int bestVal = -1000;
    int bestMove = -1;

    for (int i = 0; i < 9; i++) {
        if (board[i] == " ") {
            board[i] = "O";
            int moveVal = minimax(board, depth, false);
            board[i] = " ";  // undo move

            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }

    return bestMove;
}

// Scoring sistem
int getDynamicScore(string board[9], int movesMade, int emptySpaces) {
    int winMultiplier = 8;
    int drawMultiplier = 5;
    int moveMultiplier = 2;

    if (evaluate(board) == 10) {
        return winMultiplier * (10 - (movesMade * 2));
    } else if (evaluate(board) == 0) {
        return drawMultiplier * (10 - (movesMade * 2));
    } else {
        return moveMultiplier * emptySpaces * 2;
    }
}

int main() {
    string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ",  " "};
    // int leaderboard[50];
    int turn = 1;
    int move = 0;
    int score = 0;
    int playerPoint = 0;
    int computerPoint = 0;
    int round = 1;
    int MAX_ROUND = 2;
    int difficulty;

    cout << "\n\n1. Easy\n2. Impossible\nPilih Tingkat Kesulitan : ";
    cin >> difficulty;

    system("cls");

    while(true) {
        int choice;

        if(evaluate(board) == -10) {
            displayBoard(board, round, MAX_ROUND);
            cout << "Player Menang\n" << endl;

            if (round <= MAX_ROUND) {
                for (int i = 0; i < 9; i++) {
                    board[i] = " ";
                }
                move = 0;
                turn = 1;
                playerPoint += 1;
                round += 1;
            }

            score += 15;

            Sleep(1500);
            system("cls");
            
        } else if(evaluate(board) == 10) {
            displayBoard(board, round, MAX_ROUND);
            cout << "Computer Menang\n" << endl;
            
            if (round <= MAX_ROUND) {
                for (int i = 0; i < 9; i++) {
                    board[i] = " ";
                }
                move = 0;
                turn = 1;
                computerPoint += 1;
                round += 1;
            }

            score += 5;

            Sleep(1500);
            system("cls");

        } else if(evaluate(board) == 0 && !isMovesLeft(board)) {
            displayBoard(board, round, MAX_ROUND);
            cout << "Seimbang\n" << endl;
            
            if (round <= MAX_ROUND) {
                for (int i = 0; i < 9; i++) {
                    board[i] = " ";
                }
                move = 0;
                turn = 1;
                round += 1;
            }

            score += 1;

            Sleep(1500);
            system("cls");
        }

        if(round > MAX_ROUND) {
            system("cls");
            break;
        }

        cout << "\n\nSCORE : " << score << endl << endl;
        displayBoard(board, round, MAX_ROUND);

        if(turn == 1) {
            cout << "Masukkan nomor index papan : ";
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
                        if (evaluate(board) == 10) {
                            score += getDynamicScore(board, move, 9 - move);
                        } else if (evaluate(board) == 0) {
                            score += getDynamicScore(board, move, 9 - move);
                        } else {
                            score += getDynamicScore(board, move, 9 - move);
                        }
                    } else {
                        cout << "\n[ERROR] Pilihan sudah diisi\n" << endl;
                    }

                    break;

                default:
                    cout << "\n[ERROR] Pilih papan dari 1-9\n" << endl;
                    break;
            }
        } else {
            if(difficulty == 1) {
                int bestMove = findBestMove(board, 0);
                board[bestMove] = "O";
            } else {
                int bestMove = findBestMove(board, 7);
                board[bestMove] = "O";
            }

            turn = 1;
            cout << "Komputer sedang berpikir......\n";
        }

        Sleep(1200);
        system("cls");

    }

    cout << "\n========== [ HASIL ] ==========" << endl;
    cout << "\nSCORE\t\t: " << score << endl;
    cout << "\n-------------------------------";
    cout << "\n       Ronde dimenangkan       ";
    cout << "\n-------------------------------" << endl;
    cout << "\nPlayer\t\t: " << playerPoint << "\nComputer\t: " << computerPoint << endl;
    cout << "\n===============================";
}
