#include <stdio.h>
#define MAX 100
int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int choice, value;
    printf("\nQueue Operations Menu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                if (rear == MAX - 1) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    printf("Enter a value to enqueue: ");
                    scanf("%d", &value);
                    if (front == -1) {
                        front = 0;
                    }
                    rear++;
                    queue[rear] = value;
                    printf("Enqueued: %d\n", value);
                }
                break;

            case 2: 
                if (front == -1 || front > rear) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    value = queue[front];
                    front++;
                    if (front > rear) {
                        front = rear = -1; 
                    }
                    printf("Dequeued value: %d\n", value);
                }
                break;

            case 3: 
                if (front == -1 || front > rear) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue elements: ");
                    for (int i = front; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;

            case 4: 
                printf("Exited\n");
                return 0;
        }
    }
    return 0;
}
