#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 50

struct Task {
    char description[MAX_LENGTH];
    int completed;
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask(char description[]) {
    if (taskCount < MAX_TASKS) {
        strcpy(tasks[taskCount].description, description);
        tasks[taskCount].completed = 0;
        taskCount++;
        printf("Task added successfully!\n");
    } else {
        printf("Sorry, the to-do list is full.\n");
    }
}

void markCompleted(int index) {
    if (index >= 0 && index < taskCount) {
        tasks[index].completed = 1;
        printf("Task marked as completed.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void displayTasks() {
    printf("To-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%c] %s\n", i+1, tasks[i].completed ? 'X' : ' ', tasks[i].description);
    }
}

int main() {
    int choice;
    char description[MAX_LENGTH];

    do {
        printf("\n1. Add Task\n2. Mark Task as Completed\n3. Display Tasks\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]", description);
                addTask(description);
                break;
            case 2:
                printf("Enter index of task to mark as completed: ");
                scanf("%d", &choice);
                markCompleted(choice - 1);
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
