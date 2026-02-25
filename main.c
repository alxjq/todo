#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 100

typedef struct {
    char description[TASK_LENGTH];
    int completed; // 0 = not completed, 1 = completed
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter task description: ");
    getchar(); // clear input buffer
    fgets(tasks[taskCount].description, TASK_LENGTH, stdin);
    tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = 0; // remove newline
    tasks[taskCount].completed = 0;
    taskCount++;
    printf("Task added!\n");
}

void listTasks() {
    if (taskCount == 0) {
        printf("No tasks found!\n");
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%c] %s\n", i + 1, tasks[i].completed ? 'X' : ' ', tasks[i].description);
    }
}

void deleteTask() {
    int index;
    printf("Enter the task number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > taskCount) {
        printf("Invalid task number!\n");
        return;
    }
    for (int i = index - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    printf("Task deleted!\n");
}

void completeTask() {
    int index;
    printf("Enter the task number to mark as completed: ");
    scanf("%d", &index);
    if (index < 1 || index > taskCount) {
        printf("Invalid task number!\n");
        return;
    }
    tasks[index - 1].completed = 1;
    printf("Task marked as completed!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n-- TO-DO List --\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Complete Task\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(); break;
            case 2: listTasks(); break;
            case 3: deleteTask(); break;
            case 4: completeTask(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
