#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

/* ###########Create a simple calculator###########*/

//function declarations
//int answer(int x, int y, char operand);

//functions
int answer(int x, int y, char *operand) {

    //local variables
    int answer;
    const char multiply[] = "*";
    const char add[] = "+";
    const char divide[] = "\\";
    const char minus[] = "-";

    mvprintw(4, 2, "Operand %c", *operand);

    int comp = strcmp(operand, multiply);
    mvprintw(5, 2, "strcmp: %d", comp);


    if (comp == 0) {
        answer = x * y;
        mvprintw(6, 2, "Answer = %d", answer);
    } else {
        mvprintw (8, 2, "Operand did not match");
    }
    return answer;
}

int main() {
    int inputNo1, inputNo2, inputOp, result;
    char inputStr1[10], inputStr2[10], inputStrOp[10], inputAgain[10];

    initscr(); // Initialize ncurses
    cbreak(); // Disable line buffering

    printw("###### C-alculator ######\n");
    printw("#                       #\n");
    printw("#                       #\n");
    printw("#                       #\n");
    printw("#                       #\n");
    printw("#                       #\n");
    printw("#                       #\n");
    printw("#########################\n");


    mvprintw(1, 2, "Enter a number: ");
    getstr(inputStr1); // Get input as a string
    inputNo1 = atoi(inputStr1); // Convert string to integer

    mvprintw(2, 2, "Enter an operand: ");
    getstr(inputStrOp); // Get input as a string

    mvprintw(3, 2, "Enter a number: ");
    getstr(inputStr2); // Get input as a string
    inputNo2 = atoi(inputStr2); // Convert string to integer

    answer(inputNo1, inputNo2, inputStrOp);

   // mvprintw(5, 2, "Calculate again? y/n");
    //getstr(inputAgain); // Get input as a string
    getch();

    endwin(); // Terminate ncurses

    return 0;
}