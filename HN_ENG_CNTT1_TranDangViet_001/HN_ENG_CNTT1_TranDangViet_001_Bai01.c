#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char title[50];
    int priority;
    char deadline[50];
} Task;

typedef struct SingleNode {
    Task task;
    struct singleNode *next;
} SingleNode;

typedef struct DoubleNode {
    Task task;
    struct DoubleNode *next;
    struct DoubleNode *prev;
} DoubleNode;
SingleNode *finishNode = NULL;

SingleNode *createSingleNode(Task task) {
    SingleNode *node = (SingleNode *)malloc(sizeof (SingleNode));
    node->task = task;
    node->next = NULL;
    return node;
}

SingleNode *insertSingleNodeAtEnd(SingleNode *head, Task task){
    SingleNode *newNode = createSingleNode(task);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    SingleNode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void displaySingleList(SingleNode *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    SingleNode *temp = head;
    while (temp != NULL) {
        printf("Task ID: %d\n", temp->task.id);
        printf("Title: %s\n", temp->task.title);
        printf("Priority: %d\n", temp->task.priority);
        printf("Deadline: %s\n", temp->task.deadline);
        temp = temp->next;
    }
}

SingleNode *deleteSingleNodeById(SingleNode *head, int id) {
    SingleNode *temp = head;
    SingleNode *prev = NULL;
    while (temp != NULL && temp->task.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim that task co id la %d", id);
        return head;
    }
    if (temp == head) {
        head = head -> next;
        finishNode = temp;
        free(temp);
        return head;
    }
    prev -> next = temp -> next;
    finishNode = temp;
    free(temp);
    return head;
}

void updateTaskById(SingleNode *head, int id) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    SingleNode *temp = head;
    while (temp != NULL && temp->task.id != id) {
        temp = temp -> next;
    }
    if (temp == NULL) {
        printf("Khong tim thay task co id la %d", id);
        return;
    }
    printf("Task ID: %d\n", temp->task.id);
    printf("Old title: %s\n", temp->task.title);
    printf("Old priority: %d\n", temp->task.priority);
    printf("Old deadline: %s\n", temp->task.deadline);
    printf("Nhap vao title moi: ");
    gets(temp->task.title);
    printf("Nhap vao priority moi: ");
    scanf("%d", &temp->task.priority);
    printf("Nhap vao deadline moi: ");
    gets(temp->task.deadline);
}

void searchTaskByTitle(SingleNode *head, char *findStr) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    SingleNode *temp = head;
    while (temp != NULL) {
        if (strstr(temp->task.title, findStr) == 0) {
            printf("Task ID: %d\n", temp->task.id);
            printf("Title: %s\n", temp->task.title);
            printf("Priority: %d\n", temp->task.priority);
            printf("Deadline: %s\n", temp->task.deadline);
        }
    }
}
int main() {
    int choice;
    SingleNode *singleHead = NULL;
    DoubleNode *doubleHead = NULL;
    do {
        printf("------------TASK MANAGER-----------\n");
        printf("1.Them nhiem vu\n");
        printf("2.Hien thi danh sach nhiem vu\n");
        printf("3.Xoa nhiem vu\n");
        printf("4.cap nhat thong tin nhiem vu\n");
        printf("5.Danh dau nhiem vu hoan thanh\n");
        printf("6.Sap xep nhiem vu\n");
        printf("7.Tim kiem nhiem vu\n");
        printf("8.Thoat chuong trinh\n");
        printf("Moi nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            Task newTask;
            printf("Nhap id: ");
            scanf("%d", &newTask.id);
            fflush(stdin);
            printf("Nhap title: ");
            gets(newTask.title);
            fflush(stdin);
            printf("Nhap priority: ");
            scanf("%d", &newTask.priority);
            fflush(stdin);
            printf("Nhap deadline: ");
            gets(newTask.deadline);
            singleHead = insertSingleNodeAtEnd(singleHead, newTask);
            break;
        case 2:
            displaySingleList(singleHead);
            break;
        case 3:
            int deleteId;
            printf("Nhap id can xoa: ");
            scanf("%d", &deleteId);
            singleHead = deleteSingleNodeById(singleHead, deleteId);
            break;
        case 4:
            int updateId;
            printf("Nhap id can sua: ");
            scanf("%d", &updateId);
            updateTaskById(singleHead, updateId);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            char findStr[100];
            printf("Nhap task muon tim: ");
            gets(findStr);
            searchTaskByTitle(singleHead, findStr);
            break;
        case 8:
            printf("Thoat chuong trinh\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);

    return 0;
}
