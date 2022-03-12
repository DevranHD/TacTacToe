#include <stdio.h>
#include <stdlib.h>

void field(const char* Array) {
    printf("\t\t\t[ %c ] [ %c ] [ %c ]\n\t\t\t[ %c ] [ %c ] [ %c ]\n\t\t\t[ %c ] [ %c ] [ %c ]\n",
        Array[0], Array[1], Array[2], Array[3], Array[4], Array[5], Array[6], Array[7], Array[8]
    );
}

int hasGameEnded(const char* GameFields) {

    //Horizontal
    if ((GameFields[0] == 'x' && GameFields[1] == 'x' && GameFields[2] == 'x') ||
        (GameFields[3] == 'x' && GameFields[4] == 'x' && GameFields[5] == 'x') ||
        (GameFields[6] == 'x' && GameFields[7] == 'x' && GameFields[8] == 'x') ||
        //Vertikal
        (GameFields[0] == 'x' && GameFields[3] == 'x' && GameFields[6] == 'x') ||
        (GameFields[1] == 'x' && GameFields[4] == 'x' && GameFields[7] == 'x') ||
        (GameFields[2] == 'x' && GameFields[5] == 'x' && GameFields[8] == 'x') ||
        //Diagonal
        (GameFields[0] == 'x' && GameFields[4] == 'x' && GameFields[8] == 'x') ||
        (GameFields[2] == 'x' && GameFields[4] == 'x' && GameFields[6] == 'x'))
        return 1;
    else if ((GameFields[0] == 'o' && GameFields[1] == 'o' && GameFields[2] == 'o') ||
        (GameFields[3] == 'o' && GameFields[4] == 'o' && GameFields[5] == 'o') ||
        (GameFields[6] == 'o' && GameFields[7] == 'o' && GameFields[8] == 'o') ||
        //Vertikal                                                                 
        (GameFields[0] == 'o' && GameFields[3] == 'o' && GameFields[6] == 'o') ||
        (GameFields[1] == 'o' && GameFields[4] == 'o' && GameFields[7] == 'o') ||
        (GameFields[2] == 'o' && GameFields[5] == 'o' && GameFields[8] == 'o') ||
        //Diagonal                                                                 
        (GameFields[0] == 'o' && GameFields[4] == 'o' && GameFields[8] == 'o') ||
        (GameFields[2] == 'o' && GameFields[4] == 'o' && GameFields[6] == 'o'))
        return 2;

    for (int i = 0; i < 9; i++) {
        if (GameFields[i] != 'x' && GameFields[i] != 'o')
            return 0;
    }

    //unentschieden
    return 3;
}

void game() {
    char fields[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int choise;
    field(fields);
    bool Spieler = true;    //true = spieler1, false = spieler2

    do {
        printf("%s ist dran.\nGeben Sie eine Zahl zwischen 1-9 ein", Spieler ? "Spieler1" : "Spieler2");
        scanf_s("%i", &choise);
        Spieler = !Spieler;    //Umkehren
    } while (!(hasGameEnded(fields)));    //false wird zu true


//    if (fields[choise - 1] == 'x' || fields[choise - 1] == 'o')
//        printf("Geben Sie eine gültige Zahl ein.");
}

void menu() {
    printf("**************Tic Tac Toe**************\n\t1)Spiel Starten\n\t2)Programm beenden\n");
    int choice;
    printf("Geben Sie eine Zahl fuer Ihre Auswahl ein.\n");
    while (true) {
        scanf_s("%i", &choice);

        if (choice == 1) {
            game();
            break;
        }
        else if (choice == 2) {
            break;
        }
        else {
            printf("Geben Sie eine Zahl zwischen 1 und 2 ein.\n");
        }
    }

}

int main() {
    menu();
}