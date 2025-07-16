#include <stdio.h>
#include <stdio.h>

int main() {
    int choice;
    do {
        printf("----------TEXT EDITOR---------\n");
        printf("1.INSERT x\n");
        printf("2.UNDO\n");
        printf("3.REDO\n");
        printf("4.HIEN THI\n");
        printf("5.THOAT\n");
        printf("Moi nhap lua chon:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            printf("Thoat\n");
            break;
            default:
            printf("Lua chon khong hop le\n");
        }
    } while (choice != 5);
    return 0;
}
