#include <stdio.h>
struct Student {
    char name[50];
    int age;
};

int main() {
    struct Student student1;

    printf("Enter student's name: ");
    scanf("%s", student1.name); 

    printf("Enter student's age: ");
    scanf("%d", &student1.age);  

    printf("\nStudent Information:\n");
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);

    return 0;
}
