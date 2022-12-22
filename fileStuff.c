#include <stdio.h>
#include <string.h>  // strcmp()
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

int wordCount(char *fileName) {
    FILE *fp;
    char buff[6];
    int i = 0;

    fp = fopen(fileName, "r");

    while (!feof(fp)) {
        fscanf(fp, "%s", buff);
        i += 1;
    }
    fclose(fp);

    return (i);
}

void getWord(char *fileName, int wordIndex, char *word) {
    FILE *fp;
    int i = 0;

    fp = fopen(fileName, "r");

    while ((!feof(fp)) && (i < wordIndex)) {
        fscanf(fp, "%s", word);
        i += 1;
    }
    fclose(fp);

    return;
}

int validWord(char *fileName, char *word) {
    FILE *fp;
    char buff[6];
    int i = 0;
    int foundFlag = FALSE;

    fp = fopen(fileName, "r");

    while (!feof(fp)) {
        fscanf(fp, "%s", buff);
        i += 1;
        if (strcmp(word, buff) == 0) {
            foundFlag = TRUE;
            break;
        }
    }
    fclose(fp);

    return (foundFlag);
}

// void colorCodes(char *answer, char *buff, int *codeArray) {
//     // get greens
//     bool answerFlags[5] = {false, false, false, false, false};

//     for (int i = 0; i < 5; i++){
//         if (buff[i] == answer[i]){
//             codeArray[i] = 2;
//             answerFlags[i] = true;
//         }
//     }
//     // get yellows
//     for (int i = 0; i < 5; i++){
//         if (codeArray[i] == -1){ // no match yet
//             for (int j = 0; j < 5; j++){
//                 if (buff[i] == answer[j] && !answerFlags[j]){
//                     // a match in another position
//                     codeArray[i] = 1;
//                     answerFlags[j] = true;
//                     break; // ends j loop for avoid checkin same letter
//                 }
//             }
//         }
//     }

//     return;
// }
