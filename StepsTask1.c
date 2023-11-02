#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

    
    void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) {
    char *inputCopy=strdup(input);
    char *token=strtok(inputCopy, delimiter);
    if (token !=NULL) {
        strcpy(date, token);
    }

    token=strtok(NULL, delimiter);
    if (token !=NULL){
        strcpy(time, token);
    }

    token=strtok(NULL, delimiter);
    if (token !=NULL) {
        strcpy(steps, token);
    }

    free(inputCopy);
    }


int main() {
    FILE *file=fopen("FitnessData_2023.csv", "r");
    if (file==NULL){
    perror("Cannot open");
    return 1;
    }

    FITNESS_DATA fitnessData[716];
    int records=0;
    char line[716];

    while(fgets(line, sizeof(line), file)) {
        if (records>716) {
            printf("records too many.\n");
            break;
        }
    
    char date[11];
    char time[6];
    char steps[10];

    tokeniseRecord(line, ",", date, time, steps);

    strcpy(fitnessData[records].date, date);
    strcpy(fitnessData[records].time, time);
    fitnessData[records].steps=atoi(steps);

    records++;
    }

    fclose(file);

    printf("Number of records in file: %d\n", records);

    for (int i=0; i<3; i++) {
        printf("%s/%s/%d\n", fitnessData[i].date, fitnessData[i].time, fitnessData[i]. steps);
    }
    return 0;
}

//https://www.bilibili.com/video/BV1uM4y1V7m1/?spm_id_from=333.1007.top_right_bar_window_history.content.click
//https://www.bilibili.com/video/BV1F54y1r7ww/?spm_id_from=333.1007.top_right_bar_window_history.content.click
//https://www.bilibili.com/video/BV1os411h77o/?spm_id_from=333.1007.top_right_bar_window_default_collection.content.click
//https://simple.wikipedia.org/wiki/C_(programming_language)#:~:text=The%20C%20programming%20language%20is%20a%20computer%20programming,their%20programs%20as%20a%20series%20of%20step-by-step%20instructions.