#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

#define MAX_FILENAME_LENGTH 100
#define MAX_RECORDS 100

struct FitnessRecord {
    char date[20];
    char time[20];
    int steps;
};

void displayMenu();
void displayDateTimeRecords(struct FitnessRecord *records, int recordCount);
void importFromFile(struct FitnessRecord *data, int *records, const char *filename);
void displayTotalRecords(struct FitnessRecord *records, int recordCount);
void findMinStepsPeriod(struct FitnessRecord *records, int recordCount);
void findMaxStepsPeriod(struct FitnessRecord *records, int recordCount);
void calculateAverageSteps(struct FitnessRecord *records, int recordCount);
void findLongestOver500Period(struct FitnessRecord *records, int recordCount);
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) {
    
    char *inputCopy = strdup(input);
    
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    
    free(inputCopy);

                    }

int main() {
    struct FitnessRecord fitnessData[MAX_RECORDS];
    int numRecords = 0;
    char filename[MAX_FILENAME_LENGTH];
    char choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
            case 'a':
                printf("Enter the filename: ");
                scanf("%s", filename);
                importFromFile(fitnessData, &numRecords, filename);
                break;
            case 'B':
            case 'b':
                displayTotalRecords(fitnessData, numRecords);
                break;
            case 'C':
            case 'c':
                findMinStepsPeriod(fitnessData, numRecords);
                displayDateTimeRecords(fitnessData, numRecords);
                break;
            case 'D':
            case 'd':
                findMaxStepsPeriod(fitnessData, numRecords);
                displayDateTimeRecords(fitnessData, numRecords);
                break;
            case 'E':
            case 'e':
                calculateAverageSteps(fitnessData, numRecords);
                break;
            case 'F':
            case 'f':
                findLongestOver500Period(fitnessData, numRecords);
                displayDateTimeRecords(fitnessData, numRecords);
                break;
            case 'Q':
            case 'q':
                printf("Thank you ^_^ Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    }while (choice != 'Q' && choice != 'q');

    free(fitnessData);

    return 0;
}

void displayMenu() {
    printf("Menu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
}

importFromFile(struct FitnessRecord *data, int *records, const char *filename) {
FILE *file;
    
    char date[20], time[20];
    int steps;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file: %s\n", filename);
        return 1;
    }

    while (fscanf(file, "%s %s %d", date, time, &steps) == 3 && *records < MAX_RECORDS) {
        strcpy(data[*records].date, date);
        strcpy(data[*records].time, time);
        data[*records].steps = steps;
        (*records)++;
    }

    fclose(file);

printf("File successfully loaded.");
}


void displayTotalRecords(struct FitnessRecord *records, int recordCount) {
    printf("Total number of records: %d\n", recordCount);
}

void findMinStepsPeriod(struct FitnessRecord *records, int recordCount) {
    void displayDateTimeRecords(struct FitnessRecord *records, int recordCount) {
        for (int i = 0; i < 11; ++i) {
            printf("%d\n", fitnessData[i]. steps);
        }
    }

}
void findMaxStepsPeriod(struct FitnessRecord *records, int recordCount) {
    void displayDateTimeRecords(struct FitnessRecord *records, int recordCount) {
        for (int i = 0; i > 1099; ++i) {
            printf("%d\n", fitnessData[i]. steps);
        }
    }
}
void calculateAverageSteps(struct FitnessRecord *records, int recordCount) {
    printf("Average steps: %d\n", recordCount);
}
void findLongestOver500Period(struct FitnessRecord *records, int recordCount) {
    void displayDateTimeRecords(struct FitnessRecord *records, int recordCount) {
        for (int i = 0; i < 1101; i > 599++i) {
            printf("%d\n", fitnessData[i]. steps);
        }
    }
}