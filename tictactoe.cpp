#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ",  " "};

    int win = -1;
    int turn = 1;

    while(win == -1) {
        int choice;

        cout << "=====================================" << endl;
        cout << "           TicTacToe Games           " << endl;
        cout << "=====================================" << endl;
        cout << "Dibuat oleh Mastay\nSocial Media :\nIG : https://instagram.com/nniceone._\nGithub : https://github.com/MastayY\n" << endl;
        cout << "KETERANGAN :\nPlayer 1 : 'X'\nPlayer 2 : 'O'" << endl;
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

        if((board[0] == "X" && board[0] == board[1] && board[1] == board[2]) || ( board[3] == "X" &&board[3] == board[4] && board[4] == board[5]) || (board[6] == "X" && board[6] == board[7] && board[7] == board[8]) || (board[0] == "X" && board[0] == board[3] && board[3] == board[6]) || (board[1] == "X" && board[1] == board[4] && board[4] == board[7]) || (board[2] == "X" && board[2] == board[5] && board[5] == board[8]) || (board[0] == "X" && board[0] == board[4] && board[4] == board[8]) || (board[2] == "X" && board[2] == board[4] && board[4] == board[6])) {
            cout << "\nPlayer 1 Menang\n" << endl;
            break;
        } else if((board[0] == "O" && board[0] == board[1] && board[1] == board[2]) || ( board[3] == "O" &&board[3] == board[4] && board[4] == board[5]) || (board[6] == "O" && board[6] == board[7] && board[7] == board[8]) || (board[0] == "O" && board[0] == board[3] && board[3] == board[6]) || (board[1] == "O" && board[1] == board[4] && board[4] == board[7]) || (board[2] == "O" && board[2] == board[5] && board[5] == board[8]) || (board[0] == "O" && board[0] == board[4] && board[4] == board[8]) || (board[2] == "O" && board[2] == board[4] && board[4] == board[6])) {
            cout << "\nPlayer 2 Menang\n" << endl;
            break;
        }

        cout << "Player " << turn << " masukkan nomor index papan : ";
        cin >> choice;

        if(turn == 1) {
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
                        system("cls");
                    } else {
                        system("cls");
                        cout << "\n[ERROR] Pilihan sudah diisi\n" << endl;
                    }

                    break;

                default:
                    cout << "\n[ERROR] Pilih papan dari 1-9\n" << endl;
                    break;
            }
        } else {
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
                        board[choice - 1] = "O";
                        turn = 1;
                        system("cls");
                    } else {
                        system("cls");
                        cout << "\n[ERROR] Pilihan sudah diisi\n" << endl;
                    }

                    break;

                default:
                    cout << "\n[ERROR] Pilih papan dari 1-9\n" << endl;
                    break;
            }
        }


    }
}
