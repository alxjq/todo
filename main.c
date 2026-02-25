#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 100

typedef struct {
	char description[TASK_LENGTH];
	int completed; // 0 = tamamlanmadi, 1 = tamamlandi
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Görev listesi dolu!\n");
        return;
    }
    printf("Görev açıklamasını girin: ");
    char temp[10];
    fgets(temp, sizeof(temp), stdin);
    fgets(tasks[taskCount].description, TASK_LENGTH, stdin);
    tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = 0; // \n temizle
    tasks[taskCount].completed = 0;
    taskCount++;
    printf("Görev eklendi!\n");
}

void listTasks() {
	if (taskCount == 0) {
		printf("Gorev yok!\n");
		return;
	}
	for (int i = 0; i < taskCount; i++) {
		printf("%d. [%c] %s\n", i + 1, tasks[i].completed ? 'X' : ' ', tasks[i].description);
	}
}

void deleteTask() {
	int index;
	printf("Silmek istediginiz gorev numarasini girin: ");
	scanf("%d", &index);
	if (index < 1 || index > taskCount) {
		printf("Gecersiz gorev numarasi!\n");
		return;
	}
	for (int i = index - 1; i < taskCount - 1; i++) {
	    tasks[i] = tasks[i + 1];
	}
	taskCount--;
	printf("Gorev silindi!\n");
}

void completeTask() {
	int index;
	printf("Tamamlamak istediginiz gorev numarasini girin!: ");
	scanf("%d", &index);
	if (index < 1 || index > taskCount) {
		printf("Gecersiz gorev numarasi!\n");
		return;
	}
	tasks[index - 1].completed = 1;
	printf("Gorev tamamlandi olarak isaretlendi!\n");
}

int main() {
	int choice;
	while (1) {
		printf("\n-- TO-DO Listesi --\n");
		printf("1.Gorev Ekle\n");
		printf("2.Gorevleri listele\n");
		printf("3.Gorev Sil\n");
		printf("4.Gorev Tamamla\n");
		printf("5.Cikis\n");
		printf("Seciminiz: ");
		scanf("%d", &choice);
	

	switch (choice) {
		case 1: addTask(); break;
		case 2: listTasks(); break;
		case 3: deleteTask(); break;
		case 4: completeTask(); break;
		case 5: exit(0);
		default: printf("Gecersiz Secim!\n");
		}
	}
	return 0;
}
