#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student
{
    char enrollno[9];
    char name[20];
    char mobile[10];
    char projectname[50];
    char faculty[30];
    char marks_mid[2];
    char marks_end[2];
    char marks_guide[2];   
    struct Student *next;
};

struct Student *first = NULL, *last = NULL, *ptr;

void insertStudent(int n)
{
    int i;
    first = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter name of student : ");
    scanf("%s", first->name);
    printf("Enter enrollment number of the student : ");
    scanf("%s", first->enrollno);
    printf("Enter mobile number of the student : ");
    scanf("%s", first->mobile);
    printf("Enter project name of the student : ");
    scanf("%s", first->projectname);
    printf("Enter name of faculty assigned to the student : ");
    scanf("%s", first->faculty);
    printf("Enter mid-presentation of the student : ");
    scanf("%s", first->marks_mid);
    printf("Enter end-presenation of the student : ");
    scanf("%s", first->marks_end);
    printf("Enter marks of guide given to the student : ");
    scanf("%s", first->marks_guide);
    first->next = NULL;
    last = first;
    for(i=1; i<n; i++)
    {
        ptr = (struct Student*)malloc(sizeof(struct Student));
        printf("\n");
        printf("Enter name of the student : ");
        scanf("%s", ptr->name);
        printf("\n");
        printf("Enter enrollment number of the student :");
        scanf("%s", ptr->enrollno);
        printf("\n");
        printf("Enter mobile number of the student : ");
        scanf("%s", ptr->mobile);
        printf("\n");
        printf("Enter project name of the student : ");
        scanf("%s", ptr->projectname);
        printf("\n");
        printf("Enter name of faculty assigned to the student : ");
        scanf("%s", ptr->faculty);
        printf("\n");
        printf("Enter mid-presentation of the student : ");
        scanf("%s", ptr->marks_mid);
        printf("\n");
        printf("Enter end-presenation of the student : ");
        scanf("%s", ptr->marks_end);
        printf("\n");
        printf("Enter marks of guide given to the student : ");
        scanf("%s", ptr->marks_guide);
        printf("\n");
        ptr->next = NULL;
        last->next = ptr;
        last = ptr;
    }
}

void displayInfo()
{
    struct Student *ptr1;
    ptr1 = first;
    while(ptr1 != NULL)
    {
        printf("Name : %s", ptr1->name);
        printf("\n");
        printf("Enrollment number : %s", ptr1->enrollno);
        printf("\n");
        printf("Mobile number : %s", ptr1->mobile);
        printf("\n");
        printf("Project name : %s", ptr1->projectname);
        printf("\n");
        printf("Faculty name : %s", ptr1->faculty);
        printf("\n");
        printf("Mid-presentation marks : %s", ptr1->marks_mid);
        printf("\n");
        printf("End-presentation marks : %s", ptr1->marks_end);
        printf("\n");
        printf("Guide marks : %s", ptr1->marks_guide);
        printf("\n");
        ptr1 = ptr1->next;
    }
}

void updateProject()
{
    char r[10];
    int flag = 0;
    printf("\n");
    printf("Enter the enrollment number to change/update : \n");
    scanf("%s", &r);
    struct Student *ptr2;
    ptr2 = first;
    while (ptr2 != NULL)
    {
        if (strcmp(r, ptr2->enrollno) == 0)
        {
            printf("\n");
            printf("\nThe enrollment number of %s has been found.", ptr2->name);
            flag = 1;
            printf("\nProject name : %s", ptr2->projectname);
            printf("\nFaculty name : %s", ptr2->faculty);
            printf("\n\n");
            printf("Project name : ");
            scanf("%s", ptr2->projectname);
            printf("Faculty name : %s");
            scanf("%s", ptr2->faculty);
            break;
        }
        ptr2 = ptr2->next;
    }
}

void updateMarks()
{
    char q[10];
        int flag = 0;
        printf("\n");
        printf("Enter the enrollment number to change/upate : \n");
        scanf("%s", &q);
        struct Student *ptr3;
        ptr3 = first;
        while (ptr3 != NULL)
        {
            if (strcmp(q, ptr3->enrollno) == 0)
            {
                printf("\n");
                printf("\nThe enrollment number of %s has been found.", ptr3->name);
                flag = 1;
                printf("\nMid-presentation marks : %s", ptr3->marks_mid);
                printf("\nEnd-presentation marks : %s", ptr3->marks_end);
                printf("\nGuide marks : %s", ptr3->marks_guide);
                printf("\n\nChange now\n\n");
                printf("Enter mid-presentation marks to be changed : ");
                scanf("%s", ptr3->marks_mid);
                printf("\nEnter end-presentation marks to be changed : ");
                scanf("%s", ptr3->marks_end);
                printf("\nEnter guide marks to be changed : ");
                scanf("%s", ptr3->marks_guide);
                break;
            }
            ptr3 = ptr3->next;
        }
}

void main()
{
    int n;
    printf("**//\\Main Menu**//\\");
    int choice;
    while(choice != 0)
    {
        printf("Main Menu\n");
        printf("1. Insert student data\n2. Update project info of given enrollment number\n3. Update marks of students individually\n4. Display students' information\n5. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice)
        {
            case 1:
            printf("Enter the size of database to store student data : \n");
            scanf("%d", &n);
            insertStudent(n);
            break;

            case 2:
            updateProject();
            break;

            case 3:
            updateMarks();
            break;

            case 4:
            displayInfo();
            break;

            case 5:
            exit(0);
            break;
        
            default:
            printf("Invalid choice!\n\n");
        }
    }
}