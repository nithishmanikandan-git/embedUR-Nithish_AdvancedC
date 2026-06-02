#include <stdio.h>
#include <string.h>

#define DAYS 7
#define MAX_TASKS 3
#define TASK_LENGTH 100

struct Day {
    char dayName[20];
    char tasks[MAX_TASKS][TASK_LENGTH];
    int taskCount;
};

int main() {
    struct Day week[DAYS] = {
        {"Monday", {}, 0},
        {"Tuesday", {}, 0},
        {"Wednesday", {}, 0},
        {"Thursday", {}, 0},
        {"Friday", {}, 0},
        {"Saturday", {}, 0},
        {"Sunday", {}, 0}
    };

    int choice, numTasks;
    char continueInput;

    do {
        printf("\nSelect a day to add tasks:\n");
        for (int i = 0; i < DAYS; i++) {
            printf("%d. %s\n", i + 1, week[i].dayName);
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 7) {
            printf("Invalid day choice.\n");
            continue;
        }

        printf("Enter number of tasks for %s (maximum 3): ", week[choice - 1].dayName);
        scanf("%d", &numTasks);
        getchar();

        if (numTasks < 1 || numTasks > MAX_TASKS) {
            printf("Invalid number of tasks.\n");
            continue;
        }

        week[choice - 1].taskCount = numTasks;

        for (int i = 0; i < numTasks; i++) {
            printf("Enter task %d: ", i + 1);
            fgets(week[choice - 1].tasks[i], TASK_LENGTH, stdin);

            week[choice - 1].tasks[i][strcspn(week[choice - 1].tasks[i], "\n")] = '\0';
        }

        printf("Do you want to add tasks for another day? (y/n): ");
        scanf(" %c", &continueInput);

    } while (continueInput == 'y' || continueInput == 'Y');

    printf("\nWeekly Calendar Tasks:\n");

    for (int i = 0; i < DAYS; i++) {
        printf("\n%s:\n", week[i].dayName);

        if (week[i].taskCount == 0) {
            printf("No tasks assigned.\n");
        } else {
            for (int j = 0; j < week[i].taskCount; j++) {
                printf("%d. %s\n", j + 1, week[i].tasks[j]);
            }
        }
    }

    return 0;
}
