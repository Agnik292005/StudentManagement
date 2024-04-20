#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  char firstname[40];
  char lastname[40];
  float gpa;
  int rollno;
  char course[10];
};

static int len = 0;

void add(struct student *s) {
  static int ind = 0;
  int n;
  printf("Number of records to add : ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter the first name : ");
    scanf("%s", (s + ind + i)->firstname);
    printf("Enter the last name : ");
    scanf("%s", (s + ind + i)->lastname);
    printf("Enter the GPA : ");
    scanf("%f", &(s + ind + i)->gpa);
    printf("Enter the roll no : ");
    scanf("%d", &(s + ind + i)->rollno);
    printf("Enter the course : ");
    scanf("%s", (s + ind + i)->course);
    printf("Record added successfully\n");
    len++;
  }
  ind += n;
}

void findbyfname(struct student *s) {
  bool flag = false;
  if (len == 0) {
    printf("No records found\n");
  } else {
    char *fname;
    fname = (char *)malloc(40 * (sizeof(char)));
    printf("Enter the first name to search : ");
    scanf("%s", fname);
    printf("First name\t\t\tLast name\t\t\tGPA\t\t\tRoll no \t\t\tCourse\n");
    for (int i = 0; i < len; i++) {
      if (strcmp((s + i)->firstname, fname) == 0) {
        printf("%s\t\t\t\t%s\t\t\t\t%.2f\t\t\t%d\t\t\t\t%s\n",
               (s + i)->firstname, (s + i)->lastname, (s + i)->gpa,
               (s + i)->rollno, (s + i)->course);
        flag = true;
      }
    }
    if (!flag) {
      printf("No such student name exists.\n");
    }
    free(fname);
  }
}

void findbyrollno(struct student *s) {
  bool flag = false;
  if (len == 0) {
    printf("No records found\n");
  } else {
    int roll;
    printf("Enter the roll no to search : ");
    scanf("%d", &roll);
    for (int i = 0; i < len; i++) {
      if ((s + i)->rollno == roll) {
        printf(
            "First name\t\t\tLast name\t\t\tGPA\t\t\tRoll no \t\t\tCourse\n");
        printf("%s\t\t\t\t%s\t\t\t\t%.2f\t\t\t%d\t\t\t\t%s\n",
               (s + i)->firstname, (s + i)->lastname, (s + i)->gpa,
               (s + i)->rollno, (s + i)->course);
        flag = true;
      }
    }
    if (!flag) {
      printf(
          "No such roll number exists. Enter a valid/existing roll number.\n");
    }
  }
}

void findbycourse(struct student *s) {
  bool flag = false;
  int index;
  if (len == 0) {
    printf("No records found\n");
  } else {
    char *course;
    course = (char *)malloc(10 * (sizeof(char)));
    printf("Enter the course to search : ");
    scanf("%s", course);
    printf("First name\t\t\tLast name\t\t\tGPA\t\t\tRoll no \t\t\tCourse\n");
    for (int i = 0; i < len; i++) {
      if (strcmp((s + i)->course, course) == 0) {
        flag = true;
        index = i;
        printf("%s\t\t\t\t%s\t\t\t\t%.2f\t\t\t%d\t\t\t\t%s\n",
               (s + index)->firstname, (s + index)->lastname, (s + index)->gpa,
               (s + index)->rollno, (s + index)->course);
      }
    }
    if (!flag) {
      printf("Enter valid course\n");
    }
    free(course);
  }
}

void deletebyroll(struct student *s) {
  int a;
  bool flag = false;
  if (len == 0) {
    printf("No records found.\n");
  } else {
    printf("Enter roll number to be deleted:");
    scanf("%d", &a);
    for (int i = 0; i < len; i++) {
      if (a == (s + i)->rollno) {
        for (int j = i; j < len; j++) {
          strcpy((s + j)->firstname, (s + j + 1)->firstname);
          strcpy((s + j)->lastname, (s + j + 1)->lastname);
          (s + j)->rollno = (s + j + 1)->rollno;
          strcpy((s + j)->course, (s + j + 1)->course);
          (s + j)->gpa = (s + j + 1)->gpa;
        }
        len--;
        flag = true;
      }
    }
    if (!flag) {
      printf(
          "No such roll number exists currently. Enter a valid roll number.\n");
    } else {
      printf("Student with chosen roll number is successfully removed.\n");
    }
  }
}

void updatebyroll(struct student *s) {
  int a;
  bool flag = false;
  if (len == 0) {
    printf("No records found\n");
  } else {
    printf("Enter the roll number of the student want to update details of:");
    scanf("%d", &a);
    for (int i = 0; i < len; i++) {
      if (a == (s + i)->rollno) {
        int z = 0;
        while (z != 6) {
          printf("CHOOSE ONE OF THE OPTIONS TO UPDATE:\n");
          printf("1.First name\n");
          printf("2.Last name\n");
          printf("3.GPA\n");
          printf("4.Roll number\n");
          printf("5.Course(Major code)\n");
          printf("6.Finish updation.\n\n");
          printf("Enter your choice:");
          scanf("%d", &z);
          switch (z) {
          case 1:
            printf("Enter new first name:");
            scanf("%s", (s + i)->firstname);
            break;
          case 2:
            printf("Enter new last name:");
            scanf("%s", (s + i)->lastname);
            break;
          case 3:
            printf("Enter new gpa:");
            scanf("%f", &(s + i)->gpa);
            break;
          case 4:
            printf("Enter new roll number:");
            scanf("%d", &(s + i)->rollno);
            break;
          case 5:
            printf("Enter new course(major code):");
            scanf("%s", (s + i)->course);
            break;
          case 6:
            printf("Updation successfully finished.\n");
            break;
          default:
            printf(
                "Invalid choice number. Please enter a valid choice number.\n");
          }
        }
        flag = true;
      }
    }
    if (!flag) {
      printf("No such roll number found. Enter a valid or existing roll "
             "number.\n");
    }
  }
}

void total() { printf("Total number of students currently are:%d\n", len); }

void exitprogram() {
  printf("--------Program exited successfully! Thank you.------------\n");
}

void printnewline(){
    printf("\n\n");
}

int main() {
  struct student *stud[60];
  int choice;
  while (choice != 8) {
    printf("----------------------MENU-----------------------\n");
    printf("1.Add student details.\n");
    printf("2.Search and find student details by first name.\n");
    printf("3.Search and find student details by roll number.\n");
    printf("4.Search and find student details by course id.\n");
    printf("5.Delete student details by roll number.\n");
    printf("6.Update student details by roll number.\n");
    printf("7.Display total number of students.\n");
    printf("8.Exit the program.\n\n\n");
    printf("Enter your choice number based on above menu:");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      add(stud);
      printnewline();
      break;
    case 2:
      findbyfname(stud);
      printnewline();
      break;
    case 3:
      findbyrollno(stud);
      printnewline();
      break;
    case 4:
      findbycourse(stud);
      printnewline();
      break;
    case 5:
      deletebyroll(stud);
      printnewline();
      break;
    case 6:
      updatebyroll(stud);
      printnewline();
      break;
    case 7:
      total();
      printnewline();
      break;
    case 8:
      exitprogram();
      break;
    default:
      printf("Invalid choice number. Please enter a valid choice number.\n");
    }
  }
  return 0;
}
