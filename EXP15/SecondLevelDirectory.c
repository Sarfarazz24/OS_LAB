#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_USERS 10
#define MAX_FILES 10
struct Directory {
    char uname[10];
    char fname[MAX_FILES][10];
    int fcnt; // File count
};
struct Directory dir[MAX_USERS];
int user_count = 0;
void create_user_directory(char uname[]) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(uname, dir[i].uname) == 0) {
            printf("User directory '%s' already exists.\n", uname);
            return;
        }
    }
    strcpy(dir[user_count].uname, uname);
    dir[user_count].fcnt = 0;
    user_count++;
    printf("User directory '%s' created successfully.\n", uname);
}
void create_file(char uname[], char fname[]) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(uname, dir[i].uname) == 0) {
            if (dir[i].fcnt < MAX_FILES) {
                strcpy(dir[i].fname[dir[i].fcnt], fname);
                dir[i].fcnt++;
                printf("File '%s' created in user directory '%s'.\n", fname, uname);
            } else {
                printf("User '%s' directory is full, cannot add more files.\n", uname);
            }
            return;
        }
    }
    printf("User directory '%s' not found.\n", uname);
}
void delete_file(char uname[], char fname[]) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(uname, dir[i].uname) == 0) {
            for (int j = 0; j < dir[i].fcnt; j++) {
                if (strcmp(fname, dir[i].fname[j]) == 0) {
                    printf("File '%s' deleted from user directory '%s'.\n", fname, uname);
                    strcpy(dir[i].fname[j], dir[i].fname[dir[i].fcnt - 1]);
                    dir[i].fcnt--;
                    return;
                }
            }
            printf("File '%s' not found in user directory '%s'.\n", fname, uname);
            return;
        }
    }
    printf("User directory '%s' not found.\n", uname);
}
void search_file(char uname[], char fname[]) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(uname, dir[i].uname) == 0) {
            for (int j = 0; j < dir[i].fcnt; j++) {
                if (strcmp(fname, dir[i].fname[j]) == 0) {
                    printf("File '%s' found in user directory '%s'.\n", fname, uname);
                    return;
                }
            }
            printf("File '%s' not found in user directory '%s'.\n", fname, uname);
            return;
        }
    }
    printf("User directory '%s' not found.\n", uname);
}
void display_files(char uname[]) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(uname, dir[i].uname) == 0) {
            if (dir[i].fcnt == 0) {
                printf("User directory '%s' is empty.\n", uname);
            } else {
                printf("Files in user directory '%s':\n", uname);
                for (int j = 0; j < dir[i].fcnt; j++) {
                    printf("\t%s\n", dir[i].fname[j]);
                }
            }
            return;
        }
    }
    printf("User directory '%s' not found.\n", uname);
}
int main() {
    int choice;
    char uname[10], fname[10];
    while (1) {
        printf("\n\nTwo-Level Directory System\n");
        printf("1. Create User Directory\n");
        printf("2. Create File\n");
        printf("3. Delete File\n");
        printf("4. Search File\n");
        printf("5. Display Files\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the name of the user directory: ");
                scanf("%s", uname);
                create_user_directory(uname);
                break;
            case 2:
                printf("Enter the name of the user directory: ");
                scanf("%s", uname);
                printf("Enter the name of the file: ");
                scanf("%s", fname);
                create_file(uname, fname);
                break;
            case 3:
                printf("Enter the name of the user directory: ");
                scanf("%s", uname);
                printf("Enter the name of the file to delete: ");
                scanf("%s", fname);
                delete_file(uname, fname);
                break;
            case 4:
                printf("Enter the name of the user directory: ");
                scanf("%s", uname);
                printf("Enter the name of the file to search: ");
                scanf("%s", fname);
                search_file(uname, fname);
                break;
            case 5:
                printf("Enter the name of the user directory: ");
                scanf("%s", uname);
                display_files(uname);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
