#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    // papan permainan
    string row_1[3] = {" ", " ", " "};
    string row_2[3] = {" ", " ", " "};
    string row_3[3] = {" ", " ", " "};

    bool win = false;
    char turn = '1';

    // logic

    while(!win) {
        int p1RowChoice;
        int p1ColumnChoice;
        int p2RowChoice;
        int p2ColumnChoice;

        cout << "=====================================" << endl;
        cout << "            TicTacToe Game           " << endl;
        cout << "=====================================" << endl;
        cout << "Dibuat oleh Mastay\n\nSocial Media\nGithub : https://github.com/MastayY\nIG : https://instagram.com/nniceone._" << endl;
        cout << "\nKeterangan :\nBaris : Mendatar\nKolom : Menurun\nPlayer 1 : 'X'\nPlayer 2 : 'O'" << endl;
        cout << "=====================================\n" << endl;


        cout << "\t\t" << row_1[0] << "|" << row_1[1] << "|" << row_1[2] << endl;
        cout << "\t\t" << "-" << " - " << "-" << endl;
        cout << "\t\t" << row_2[0] << "|" << row_2[1] << "|" << row_2[2] << endl;
        cout << "\t\t" << "-" << " - " << "-" << endl;
        cout << "\t\t" << row_3[0] << "|" << row_3[1] << "|" << row_3[2] << endl;

        cout << "\n=====================================" << endl;

        if((row_1[0] == "x" && row_1[1] == "x" && row_1[2] == "x") || (row_2[0] == "x" && row_2[1] == "x" && row_2[2] == "x") || (row_3[0] == "x" && row_3[1] == "x" && row_3[2] == "x") || (row_1[0] == "x" && row_2[0] == "x" && row_3[0] == "x") ||(row_1[1] == "x" && row_2[1] == "x" && row_3[1] == "x") || (row_1[2] == "x" && row_2[2] == "x" && row_3[2] == "x") || (row_1[0] == "x" && row_2[1] == "x" && row_3[2] == "x") || (row_3[0] == "x" && row_2[1] == "x" && row_1[2] == "x")) {
            cout << "\nPlayer 1 Menang\n" << endl;
            win = true;
            break;
        } else if((row_1[0] == "o" && row_1[1] == "o" && row_1[2] == "o") || (row_2[0] == "o" && row_2[1] == "o" && row_2[2] == "o") || (row_3[0] == "o" && row_3[1] == "o" && row_3[2] == "o") || (row_1[0] == "o" && row_2[0] == "o" && row_3[0] == "o") ||(row_1[1] == "o" && row_2[1] == "o" && row_3[1] == "o") || (row_1[2] == "o" && row_2[2] == "o" && row_3[2] == "o") || (row_1[0] == "o" && row_2[1] == "o" && row_3[2] == "o") || (row_3[0] == "o" && row_2[1] == "o" && row_1[2] == "o")) {
            cout << "\nPlayer 2 Menang\n" << endl;
            win = true;
            break;
        }

        cout << "\nGiliran : Player " << turn << endl;

        if(turn == '1') {
            cout << "\nBaris Pilihan anda ? ";
            cin >> p1RowChoice;

            if(p1RowChoice - 1 > 2) {
                system("cls");
                cout << "\n[ERROR] Baris tidak ada. Baris yang ada : 1, 2, 3\n" << endl;
            } else if(p1RowChoice == 1 && (row_1[0] == " " || row_1[1] == " " || row_1[2] == " ")){
                cout << "\nKolom Pilihan anda ? ";
                cin >> p1ColumnChoice;

                if(p1ColumnChoice - 1 > 2) {
                    system("cls");
                    cout << "\n[ERROR] Kolom tidak ada. Kolom yang ada : 1, 2, 3\n" << endl;
                } else {
                    if(row_1[p1ColumnChoice - 1] != " ") {
                        system("cls");
                        cout << "[ERROR] Kolom sudah terisi\n" << endl;
                    } else {
                        row_1[p1ColumnChoice - 1] = 'x';
                        turn = '2';
                        system("cls");
                    }
                }
            } else if(p1RowChoice == 2 && (row_2[0] == " " || row_2[1] == " " || row_2[2] == " ")){
                cout << "\nKolom Pilihan anda ? ";
                cin >> p1ColumnChoice;

                if(p1ColumnChoice - 1 > 2) {
                    system("cls");
                    cout << "\n[ERROR] Kolom tidak ada. Kolom yang ada : 1, 2, 3\n" << endl;
                } else {
                    if(row_2[p1ColumnChoice - 1] != " ") {
                        system("cls");
                        cout << "[ERROR] Kolom sudah terisi\n" << endl;
                    } else {
                        row_2[p1ColumnChoice - 1] = 'x';
                        turn = '2';
                        system("cls");
                    }
                }
            } else if(p1RowChoice == 3 && (row_3[0] == " " || row_3[1] == " " || row_3[2] == " ")){
                cout << "\nKolom Pilihan anda ? ";
                cin >> p1ColumnChoice;

                if(p1ColumnChoice - 1 > 2) {
                    system("cls");
                    cout << "\n[ERROR] Kolom tidak ada. Kolom yang ada : 1, 2, 3\n" << endl;
                } else {
                    if(row_3[p1ColumnChoice - 1] != " ") {
                        system("cls");
                        cout << "[ERROR] Kolom sudah terisi\n" << endl;
                    } else {
                        row_3[p1ColumnChoice - 1] = 'x';
                        turn = '2';
                        system("cls");
                    }
                }
            } else {
                system("cls");
                cout << "Baris sudah terisi semua\n" << endl;
            }

        } else {
            cout << "\nBaris Pilihan anda ? ";
            cin >> p2RowChoice;

            if(p2RowChoice - 1 > 2) {
                system("cls");
                cout << "\n[ERROR] Baris tidak ada. Baris yang ada : 1, 2, 3\n" << endl;
            } else if(p2RowChoice == 1 && (row_1[0] == " " || row_1[1] == " " || row_1[2] == " ")){
                cout << "\nKolom Pilihan anda ? ";
                cin >> p2ColumnChoice;

                if(p2ColumnChoice - 1 > 2) {
                    system("cls");
                    cout << "\n[ERROR] Kolom tidak ada. Kolom yang ada : 1, 2, 3\n" << endl;
                } else {
                    if(row_1[p2ColumnChoice - 1] != " ") {
                        system("cls");
                        cout << "[ERROR] Kolom sudah terisi\n" << endl;
                    } else {
                        row_1[p2ColumnChoice - 1] = 'o';
                        turn = '1';
                        system("cls");
                    }
                }
            } else if(p2RowChoice == 2 && (row_2[0] == " " || row_2[1] == " " || row_2[2] == " ")){
                cout << "\nKolom Pilihan anda ? ";
                cin >> p2ColumnChoice;

                if(p2ColumnChoice - 1 > 2) {
                    system("cls");
                    cout << "\n[ERROR] Kolom tidak ada. Kolom yang ada : 1, 2, 3\n" << endl;
                } else {
                    if(row_2[p2ColumnChoice - 1] != " ") {
                        system("cls");
                        cout << "[ERROR] Kolom sudah terisi\n" << endl;
                    } else {
                        row_2[p2ColumnChoice - 1] = 'o';
                        turn = '1';
                        system("cls");
                    }
                }
            } else if(p2RowChoice == 3 && (row_3[0] == " " || row_3[1] == " " || row_3[2] == " ")){
                cout << "\nKolom Pilihan anda ? ";
                cin >> p2ColumnChoice;

                if(p2ColumnChoice - 1 > 2) {
                    system("cls");
                    cout << "\n[ERROR] Kolom tidak ada. Kolom yang ada : 1, 2, 3\n" << endl;
                } else {
                    if(row_3[p2ColumnChoice - 1] != " ") {
                        system("cls");
                        cout << "[ERROR] Kolom sudah terisi\n" << endl;
                    } else {
                        row_3[p2ColumnChoice - 1] = 'o';
                        turn = '1';
                        system("cls");
                    }
                }
            } else {
                system("cls");
                cout << "Baris sudah terisi semua\n" << endl;
            }
        }
    }
}
