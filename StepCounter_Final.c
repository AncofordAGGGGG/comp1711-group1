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
                break;
            case 'D':
            case 'd':
                findMaxStepsPeriod(fitnessData, numRecords);
                break;
            case 'E':
            case 'e':
                calculateAverageSteps(fitnessData, numRecords);
                break;
            case 'F':
            case 'f':
                findLongestOver500Period(fitnessData, numRecords);
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
   int minIndex = 0;

    for (int i = 1; i < recordCount; ++i) {
        if (records[i].steps < records[minIndex].steps) {
            minIndex = i;
        }
    }

    printf("Minimum steps: %d\n", records[minIndex].steps);
    printf("Date and time for minimum steps: %s %s\n", records[minIndex].date, records[minIndex].time);
}

void findMaxStepsPeriod(struct FitnessRecord *records, int recordCount) {
    int maxIndex = 0;

    for (int i = 1; i < recordCount; ++i) {
        if (records[i].steps > records[maxIndex].steps) {
            maxIndex = i;
        }
    }

    printf("Maximum steps: %d\n", records[maxIndex].steps);
    printf("Date and time for maximum steps: %s %s\n", records[maxIndex].date, records[maxIndex].time);
}
void calculateAverageSteps(struct FitnessRecord *records, int recordCount) {
    int totalSteps = 0;
    for (int i = 0; i < recordCount; ++i) {
        totalSteps += records[i].steps;
    }

    if (recordCount > 0) {
        float averageSteps = (float)totalSteps / recordCount;
        printf("Average steps: %.2f\n", averageSteps);
    } else {
        printf("No records to calculate average.\n");
    }
}
void findLongestOver500Period(struct FitnessRecord *records, int recordCount) {
    int currentStreak = 0;
    int longestStreak = 0;

    for (int i = 0; i < recordCount - 1; ++i) {
        if (records[i].steps > 500) {
            currentStreak++;
            if (currentStreak > longestStreak) {
                longestStreak = currentStreak;
            }
        } else {
            currentStreak = 0;
        }
    }

    if (longestStreak > 0) {
        printf("Longest continuous period with steps over 500: %d\n", longestStreak);
    } else {
        printf("No continuous period with steps over 500.\n");
    }
}