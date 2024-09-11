#include <stdio.h>
#include <stdlib.h>

struct sllnode {
    int value;
    struct sllnode *next;
};

struct sllnode *sllstart = NULL;

struct sllnode *sllcreate() {
    struct sllnode *temp = (struct sllnode *)malloc(sizeof(struct sllnode));
    temp->next = NULL;
    return temp;
}

void slldisplay_list() {
    struct sllnode *temp = sllstart;

    if (sllstart == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
}

void sllinsert_start(int value) {
    struct sllnode *newNode = sllcreate();
    newNode->value = value;
    newNode->next = sllstart;
    sllstart = newNode;
    slldisplay_list();
}

void sllinsert_end(int value) {
    struct sllnode *newNode = sllcreate();
    newNode->value = value;
    newNode->next = NULL;

    if (sllstart == NULL) {
        sllstart = newNode;
    } else {
        struct sllnode *temp = sllstart;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    slldisplay_list();
}

int slldelete_start() {
    if (sllstart == NULL) {
        printf("List is empty\n");
        return -1;
    }

    struct sllnode *temp = sllstart;
    int value = sllstart->value;
    sllstart = sllstart->next;
    temp->next = NULL;
    free(temp);
    return value;
}

int slldelete_end() {
    if (sllstart == NULL) {
        printf("List is empty\n");
        return -1;
    }

    struct sllnode *temp = sllstart;
    struct sllnode *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    int value = temp->value;
    prev->next = NULL;
    free(temp);
    return value;
}

void sllinsert_position(int value, int pos) {
    struct sllnode *newNode = sllcreate();
    newNode->value = value;

    if (pos == 1) {
        sllinsert_start(value);
    } else {
        struct sllnode *temp = sllstart;
        int i;

        for (i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

    }

    slldisplay_list();
}

int slldelete_position(int pos) {
    if (sllstart == NULL) {
        printf("List is empty\n");
        return -1;
    }

    if (pos == 1) {
        int deletedValue = sllstart->value;
        sllstart = sllstart->next;
        return deletedValue;
    }

    struct sllnode *temp = sllstart;
    struct sllnode *prev = NULL;
    int i;

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d does not exist\n", pos);
        return -1;
    }

    int deletedValue = temp->value;
    prev->next = temp->next;
    temp->next = NULL;
    free(temp);
    return deletedValue;
}
#include <stdio.h>
#include <stdlib.h>


int main() {
    int choice, value, pos;
    printf("\nMenu:\n");
        printf("1. Insert at start\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at start\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
    do {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                sllinsert_start(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                sllinsert_end(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                sllinsert_position(value, pos);
                break;
            case 4:
                printf("Deleted value: %d\n", slldelete_start());
                break;
            case 5:
                printf("Deleted value: %d\n", slldelete_end());
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Deleted value: %d\n", slldelete_position(pos));
                break;
            case 7:
                slldisplay_list();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}