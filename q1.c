#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 9
#define X 1
#define O -1

static int board[3][3];
static char input[11];

int getInput(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Please provide exactly one argument representing the computer's moves.\n");
        return 1;
    }

    strncpy(input, argv[1], sizeof(input) - 1);
    input[sizeof(input) - 1] = '\0';

    size_t len = strlen(input);
    int digit_count[10] = {0}; // Array to count occurrences of each digit

    // Check length of input
    if (len != LENGTH) {
        printf("Error: The number must have exactly 9 digits.\n");
        return 1;
    }

    // Check digits and count occurrences
    for (int i = 0; i < LENGTH; i++) {
        if (input[i] < '1' || input[i] > '9') {
            printf("Error: Digits must be between 1 and 9.\n");
            return 1;
        }

        int digit = input[i] - '0';
        digit_count[digit]++;

        // Check for duplicate digits
        if (digit_count[digit] > 1) {
            printf("Error: Each digit must appear only once.\n");
            return 1;
        }
    }

    printf("Valid input: %s\n", input);
    return 0;
}

void reset() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
}

int computerTurn() {
    for (int i = 0; i < LENGTH; i++) {
        if (input[i] == '1' && board[0][0] == 0) {
            board[0][0] = X;
            printf("Square number 1 (0,0) chosen\n");
            return 0;
        }
        if (input[i] == '2' && board[0][1] == 0) {
            board[0][1] = X;
            printf("Square number 2 (0,1) chosen\n");
            return 0;
        }
        if (input[i] == '3' && board[0][2] == 0) {
            board[0][2] = X;
            printf("Square number 3 (0,3) chosen\n");
            return 0;
        }
        if (input[i] == '4' && board[1][0] == 0) {
            board[1][0] = X;
            printf("Square number 4 (1,0) chosen\n");
            return 0;
        }
        if (input[i] == '5' && board[1][1] == 0) {
            board[1][1] = X;
            printf("Square number 5 (1,1) chosen\n");
            return 0;
        }
        if (input[i] == '6' && board[1][2] == 0) {
            board[1][2] = X;
            printf("Square number 6 (1,2) chosen\n");
            return 0;
        }
        if (input[i] == '7' && board[2][0] == 0) {
            board[2][0] = X;
            printf("Square number 7 (2,0) chosen\n");
            return 0;
        }
        if (input[i] == '8' && board[2][1] == 0) {
            board[2][1] = X;
            printf("Square number 8 (2,1) chosen\n");
            return 0;
        }
        if (input[i] == '9' && board[2][2] == 0) {
            board[2][2] = X;
            printf("Square number 9 (2,2) chosen\n");
            return 0;
        }
    }
    printf("Computer did not make a turn\n");
    return 1;
}

int checkComputerWin() {
    if ((board[0][0] == X && board[0][1] == X && board[0][2] == X) ||
        (board[1][0] == X && board[1][1] == X && board[1][2] == X) ||
        (board[2][0] == X && board[2][1] == X && board[2][2] == X) ||
        (board[0][0] == X && board[1][0] == X && board[2][0] == X) ||
        (board[0][1] == X && board[1][1] == X && board[2][1] == X) ||
        (board[0][2] == X && board[1][2] == X && board[2][2] == X) ||
        (board[0][0] == X && board[1][1] == X && board[2][2] == X) ||
        (board[2][0] == X && board[1][1] == X && board[0][2] == X)) {
        return 0;
    }
    return 1;
}

int checkPlayerWin() {
    if ((board[0][0] == O && board[0][1] == O && board[0][2] == O) ||
        (board[1][0] == O && board[1][1] == O && board[1][2] == O) ||
        (board[2][0] == O && board[2][1] == O && board[2][2] == O) ||
        (board[0][0] == O && board[1][0] == O && board[2][0] == O) ||
        (board[0][1] == O && board[1][1] == O && board[2][1] == O) ||
        (board[0][2] == O && board[1][2] == O && board[2][2] == O) ||
        (board[0][0] == O && board[1][1] == O && board[2][2] == O) ||
        (board[2][0] == O && board[1][1] == O && board[0][2] == O)) {
        return 0;
    }
    return 1;
}

int playerTurn() {
    int get = 0;

    while (true) {
        printf("Enter a number between 1-9: ");
        scanf("%d", &get);
        while (get < 1 || get > 9) {
            printf("Invalid choice! Number needs to be between 1-9: ");
            scanf("%d", &get);
        }

        if (get == 1 && board[0][0] == 0) {
            board[0][0] = O;
            printf("Square number 1 (0,0) chosen\n");
            return 0;
        }
        if (get == 2 && board[0][1] == 0) {
            board[0][1] = O;
            printf("Square number 2 (0,1) chosen\n");
            return 0;
        }
        if (get == 3 && board[0][2] == 0) {
            board[0][2] = O;
            printf("Square number 3 (0,3) chosen\n");
            return 0;
        }
        if (get == 4 && board[1][0] == 0) {
            board[1][0] = O;
            printf("Square number 4 (1,0) chosen\n");
            return 0;
        }
        if (get == 5 && board[1][1] == 0) {
            board[1][1] = O;
            printf("Square number 5 (1,1) chosen\n");
            return 0;
        }
        if (get == 6 && board[1][2] == 0) {
            board[1][2] = O;
            printf("Square number 6 (1,2) chosen\n");
            return 0;
        }
        if (get == 7 && board[2][0] == 0) {
            board[2][0] = O;
            printf("Square number 7 (2,0) chosen\n");
            return 0;
        }
        if (get == 8 && board[2][1] == 0) {
            board[2][1] = O;
            printf("Square number 8 (2,1) chosen\n");
            return 0;
        }
        if (get == 9 && board[2][2] == 0) {
            board[2][2] = O;
            printf("Square number 9 (2,2) chosen\n");
            return 0;
        }
        printf("Can't choose %d because it's already taken\n", get);
    }
    return 1;
}

void printBoard() {
    printf("///////////////////////////////////\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == X) {
                printf("X ");
            } else if (board[i][j] == O) {
                printf("O ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    reset();

    if (getInput(argc, argv) == 1) {
        return 1;
    }

    int turn = 0;
    while (true) {
        printf("Computer turn\n");
        computerTurn();
        turn++;
        printBoard();
        if (checkComputerWin() == 0) {
            printf("Computer wins!\n");
            return 0;
        }
        if (turn == 9) {
            printf("DRAW\n");
            return 0;
        }
        printf("Player turn\n");
        playerTurn();
        turn++;
        printBoard();
        if (checkPlayerWin() == 0) {
            printf("Player wins!\n");
            return 0;
        }
    }
    return 1;
}
