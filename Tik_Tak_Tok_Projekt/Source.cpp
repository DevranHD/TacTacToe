#include <stdio.h>
#include <stdlib.h>


void Menu();
system("CLS");
printf("\t\t\tTic-Tac-Toe\n\t\t\tWer möchte beginnen?\n\t\t\t1)Player 1 (x)\n\t\t\t2)Player 2 (o)");

void field(const char* Array) {
    printf("\t\t\t[ %c ] [ %c ] [ %c ]\n\t\t\t[ %c ] [ %c ] [ %c ]\n\t\t\t[ %c ] [ %c ] [ %c ]\n",
        Array[0], Array[1], Array[2], Array[3], Array[4], Array[5], Array[6], Array[7], Array[8]);
}

int main() {
    
    Menu();
    
    char fields[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    field(fields);
}