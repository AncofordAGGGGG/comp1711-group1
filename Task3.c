#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_LINE_LENGTH 100

typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    if (sscanf(record, "%10[^,],%5[^,],%d", date, time, steps) != 3) {
        // Failed to parse all three values
        printf("Error: Invalid record format: %s\n", record);
        exit(1);
    }
}

int readRecords(const char *filename, FitnessData **records, int *recordCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    *recordCount = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        (*recordCount)++;
    }

    *records = (FitnessData *)malloc(*recordCount * sizeof(FitnessData));

    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < *recordCount; i++) {
        fgets(line, sizeof(line), file);
        tokeniseRecord(line, ',', (*records)[i].date, (*records)[i].time, &(*records)[i].steps);
    }

    fclose(file);
    return 0;
}

int compareRecords(const void *a, const void *b) {
    return ((FitnessData *)b)->steps - ((FitnessData *)a)->steps;
}

int writeRecords(const char *filename, FitnessData *records, int recordCount) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file %s for writing\n", filename);
        return 1;
    }

    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%s\t%s\t%d\n", records[i].date, records[i].time, records[i].steps);
    }

    fclose(file);
    return 0;
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FitnessData *records;
    int recordCount;
    if (readRecords(filename, &records, &recordCount) != 0) {
        return 1;
    }

    qsort(records, recordCount, sizeof(FitnessData), compareRecords);

    char outputFilename[MAX_FILENAME_LENGTH];
    sprintf(outputFilename, "%s.csv.tsv", strtok(filename, ".")); // Append .tsv to the original filename
    if (writeRecords(outputFilename, records, recordCount) != 0) {
        free(records);
        return 1;
    }

    printf("Sorted data written to %s\n", outputFilename);

    free(records);
    return 0;
}