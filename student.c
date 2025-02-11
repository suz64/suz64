#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "student.txt"

// Structure to store student information
typedef struct {
    int roll_no;
    char name[50];
    int age;
    char address[100];
} Student;

// Function to save student records to a file
void saveToFile(Student students[], int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%d,%s\n", 
            students[i].roll_no, 
            students[i].name, 
            students[i].age, 
            students[i].address);
    }
    fclose(file);
    printf("Data saved successfully!\n");
}

// Function to load student records from a file
int loadFromFile(Student students[]) {
    FILE *file = fopen(FILE_NAME, "r");
    int count = 0;
    if (file == NULL) {
        printf("No existing records found.\n");
        return 0;
    }
    fscanf(file, "%d\n", &count);
    for (int i = 0; i < count; i++) {
        fscanf(file, "%d,%[^,],%d,%[^\n]\n", 
            &students[i].roll_no, 
            students[i].name, 
            &students[i].age, 
            students[i].address);
    }
    fclose(file);
    return count;
}

// Function to search student by roll number
void searchByRollNo(Student students[], int count, int roll_no) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll_no) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\nName: %s\nAge: %d\nAddress: %s\n", 
                   students[i].roll_no, students[i].name, students[i].age, students[i].address);
            return;
        }
    }
    printf("\nStudent with Roll No %d not found.\n", roll_no);
}

// Function to search student by name
void searchByName(Student students[], int count, char name[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\nName: %s\nAge: %d\nAddress: %s\n", 
                   students[i].roll_no, students[i].name, students[i].age, students[i].address);
            return;
        }
    }
    printf("\nStudent with Name '%s' not found.\n", name);
}

int main() {
    Student students[MAX_STUDENTS];
    int count = loadFromFile(students);
    int choice, roll_no;
    char name[50];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Student Record\n");
        printf("2. Search by Roll No\n");
        printf("3. Search by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < MAX_STUDENTS) {
                    printf("\nEnter details for Student %d:\n", count + 1);
                    printf("Roll No: ");
                    scanf("%d", &students[count].roll_no);
                    printf("Name: ");
                    scanf(" %[^\n]s", students[count].name);
                    printf("Age: ");
                    scanf("%d", &students[count].age);
                    printf("Address: ");
                    scanf(" %[^\n]s", students[count].address);
                    count++;
                    saveToFile(students, count);
                } else {
                    printf("Student storage is full!\n");
                }
                break;
            case 2:
                printf("Enter Roll No to search: ");
                scanf("%d", &roll_no);
                searchByRollNo(students, count, roll_no);
                break;
            case 3:
                printf("Enter Name to search: ");
                scanf(" %s", name);
                searchByName(students, count, name);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
