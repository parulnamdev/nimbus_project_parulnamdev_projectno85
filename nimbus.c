#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Faculty {
    char name[50];
    char dept[50];
    int available;  // 1 = available, 0 = not available
};

struct Schedule {
    char slotName[50];
    char facultyAssigned[50];
};

int checkAvailability(struct Faculty *f) {
    return f->available;
}

// Rotate faculty index: 0,1,2,... then again 0,1,2....
int getNextFaculty(int current, int total) {
    return (current + 1) % total;
}

void saveToFile(struct Schedule *sch, int slots) {
    FILE *fp = fopen("invigilation_schedule.txt", "w");
    if (!fp) {
        printf("Error creating file!\n");
        return;
    }

    for (int i = 0; i < slots; i++) {
        fprintf(fp, "%s -> %s\n", sch[i].slotName, sch[i].facultyAssigned);
    }

    fclose(fp);
    printf("\nSchedule saved to file: invigilation_schedule.txt\n");
}

int main() {
    int n;
    printf("Enter number of faculty: ");
    scanf("%d", &n);

    struct Faculty *faculty = (struct Faculty *)malloc(n * sizeof(struct Faculty));

    printf("\nEnter faculty details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nFaculty %d\n", i + 1);
        printf("Name: ");
        scanf("%s", faculty[i].name);
        printf("Department: ");
        scanf("%s", faculty[i].dept);
        printf("Available (1=Yes, 0=No): ");
        scanf("%d", &faculty[i].available);
    }

    int slots;
    printf("\nEnter number of exam slots: ");
    scanf("%d", &slots);

    struct Schedule *schedule = (struct Schedule *)malloc(slots * sizeof(struct Schedule));

    printf("\nEnter Slot Names:\n");
    for (int i = 0; i < slots; i++) {
        printf("Slot %d: ", i + 1);
        scanf("%s", schedule[i].slotName);
    }

    int currentFaculty = 0;

    printf("\n--- ALLOCATING INVIGILATORS ---\n");
    for (int i = 0; i < slots; i++) {
        int assigned = 0;
        int attempts = 0;

        while (!assigned && attempts < n) {
            if (checkAvailability(&faculty[currentFaculty])) {
                strcpy(schedule[i].facultyAssigned, faculty[currentFaculty].name);
                assigned = 1;
            }
            currentFaculty = getNextFaculty(currentFaculty, n);
            attempts++;
        }

        if (!assigned) {
            strcpy(schedule[i].facultyAssigned, "No Faculty Available");
        }
    }

    printf("\n--- FINAL SCHEDULE ---\n");
    for (int i = 0; i < slots; i++) {
        printf("%s -> %s\n", schedule[i].slotName, schedule[i].facultyAssigned);
    }

    saveToFile(schedule, slots);

    free(faculty);
    free(schedule);

    return 0;
}

