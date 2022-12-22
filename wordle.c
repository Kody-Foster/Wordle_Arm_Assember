#include <stdio.h>
#include <time.h>       // time()
#include <stdlib.h>     // seed()
#include <string.h>     // strcmp()
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

int wordCount(char *fileName);
int getRandom(int min, int max);
void getWord(char *fileName, int wordIndex, char *word);
int validWord(char *fileName, char *word);
void getColorCodes(char *answer, char *buff, int *codeArray);

int main() {
    char buff[6];
    char answer[6];
    int validFlag = FALSE;

    char board[6][6];
    int colors[6][5];
    int guessCounter = 0;

    int count = wordCount("5Letter.txt");


    srand((unsigned)time(0));
    int record = getRandom(0, count);
    getWord("5Letter.txt", record, answer);

    for (int i = 0; i < 6; i++ ){
        for (int j = 0; j < 5; j++){
            board[i][j] = '-';
        }
    }

    for (int i = 0; i < 6; i++ ){
        for (int j = 0; j < 5; j++){
            colors[i][j] = -1;
        }
    }

    while (guessCounter < 6 && strcmp(answer, buff) != 0) {
        printf("Answer: %s\n", answer);
        printf("Enter Guess: ");

        scanf("%s", buff);
        validFlag = validWord("5Letter.txt", buff);

        if (validFlag){
            printf("\033c");  // clear console
            strcpy(board[guessCounter], buff);


            int tmpColors[5] = {-1, -1, -1, -1, -1};
            getColorCodes(answer, buff, tmpColors);

            for (int i = 0; i < 5; i++){
                colors[guessCounter][i] = tmpColors[i];
            }
            
            guessCounter++;

            for (int i = 0; i < 6; i++ ){
                for (int j = 0; j < 5; j++){

                    if( colors[i][j] == 1){
                        printf("%s%c", "\033[1;43m", board[i][j]);  // yellow background
                    }
                    else if (colors[i][j] == 2){
                        printf("%s%c", "\033[1;42m", board[i][j]);  // green background
                    }
                    else{
                        printf("%s%c", "\033[0m", board[i][j]);  // default
                    }

                }
                printf("%s\n", "\033[0m");  // default
            }
        }else{
            printf("Not a valid Word\n");
        }

    }

    if(strcmp(answer, buff) == 0){
        printf("** You WIN! **\n");
    }else{
        printf("** You ran out of guesses **\n");
    }

    return 0;
}

