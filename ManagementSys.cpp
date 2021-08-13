#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Users User;
typedef struct Student Student;
typedef struct Teacher Teacher;

//Global Variables

int studentLength;
int teachersLength;

//Structures

 struct Student
 {
     char name[20], cgpa[20],email[50];
     char password[50]; int id;

     Student(){
            ;
        }

 };

 struct Teacher
 {
    char designation[20],name[20],email[50],password[50];
     Teacher(){
            ;
        }
 };
 struct Users
    {
        char name[50],email[50],password[50];

        Student student1[5];

        Teacher teacher1[5];

        Users(){
            ;
        }

    };

//All Functions

void selectUser(User User1,User User2);
void showStudents(User user);
void showTeachers(User user);
void editStudent(User user,int id);
bool checkUserStudent(User user1, User user2, int iteration);
bool checkUserTeacher(User user1, User user2, int iteration);
void displayStudentInfo(User user1,User user2,int iteration);

//Selecting User and Options Afterwards

void selectUser(User User1,User User2){
     int userID,iteration1, iteration2;
     bool isLoggedIn;
mainMenu:
     printf("\nAre You a Student or Teacher:\n 1.Teacher \n 2.Student \nEnter Choice: ");
     scanf("%d",&userID);
     switch (userID)
     {
     case 1:
         printf("\nEmail:");
         scanf("%s",&User2.email);
         printf("\nPassword:");
         scanf("%s",&User2.password);

         for (int i = 0; i < teachersLength; i++)
         {
              iteration1= i;
              isLoggedIn = checkUserTeacher(User1,User2, iteration1 );
         }
             if (isLoggedIn){
             printf("\nLogin Successful !\n");
             int options;
teacherMenu:
             printf("\nPlease Choose Option:\n 1.See All Students \n 2.See All Teachers \n 3.Edit Student \n 4.LogOut \n 5.Exit\n");
             scanf("%d",&options);
                 switch (options)
                 {
                 case 1:
                     showStudents(User1);
                     goto teacherMenu;
                     break;
                 case 2:
                      showTeachers(User1);
                      goto teacherMenu;
                      break;
                 case 3:
                        printf("Enter Student ID: ");
                        int id;
                        scanf("%d",&id);
                         printf("\nEnter New Name:");
                         scanf("%s",&User1.student1[id-1].name);
                        showStudents(User1);
                        goto teacherMenu;
                       break;
                 case 4:
                        isLoggedIn = false;
                        goto mainMenu;

                       break;
                 case 5:
                       exit(0);
                       break;
                 default:
                     printf("Invalid Input");
                     break;
                 }

         }
         else
            printf("Login Unsuccessful");

         break;
     case 2:
         printf("You are a Student\n");
         printf("\nEmail:");
         scanf("%s",&User2.email);
         printf("\nPassword:");
         scanf("%s",&User2.password);
         
          for (int i = 0; i < studentLength; i++)
         {
              iteration2 = i;

              isLoggedIn = checkUserStudent(User1,User2, iteration2 );
         }
         if (isLoggedIn){
            printf("\nLogin Successful !\n");
             if (isLoggedIn)
             {  int options;
studentMenu:
             printf("\nPlease Choose Option:\n 1.See Student Info \n 2.LogOut \n 3.Exit\n");
             scanf("%d",&options);
                 switch (options)
                 {
                 case 1:
                     displayStudentInfo(User1,User2,iteration2);
                     goto studentMenu;
                     break;
                 case 2:
                     goto mainMenu;
                     isLoggedIn =false;
                      break;
                 case 3:
                       exit(0);
                       break;
                 default:
                     printf("Invalid Input");
                     break;
                 }
             }
         }
         else {
                 printf("Login Unsuccessful");
             }
        break;
     default:
        printf("Invalid Input");
         break;
     }
 }


 void displayStudentInfo(User user1,User user2,int iteration){
     int temp = iteration;
   for (int i = temp; i < studentLength; i++)
        {
            printf("Student ID: %d\n", temp+1);
            printf("Student Name: %s\n",user1.student1[temp].name);
            printf("Student Email: %s\n",user1.student1[temp].email);
            printf("Student CGPA: %s\n",user1.student1[temp].cgpa);
        }

 }

 void showTeachers(User user){
        for (int i = 0; i < teachersLength; i++)
        {
            printf("Teacher Name: %s\n",user.teacher1->name);
            printf("Teacher Email: %s\n",user.teacher1->email);
            printf("Teacher Designation: %s\n",user.teacher1->designation);
        }
    }
bool checkUserTeacher(User u1, User u2, int iteration)
{
    int checkEmail;
    int checkPassword;
    checkEmail= strcmp(u1.teacher1[iteration].email, u2.email);
    checkPassword=strcmp(u1.teacher1[iteration].password, u2.password);
    if(checkEmail == 0 && checkPassword == 0 )
    {
        return 1;
    }
    else
        return 0;
}
bool checkUserStudent(User u1, User u2, int iteration)
{
    int checkEmail;
    int checkPassword;
    checkEmail= strcmp(u1.student1[iteration].email, u2.email);
    checkPassword=strcmp(u1.student1[iteration].password, u2.password);
    if(checkEmail == 0 && checkPassword == 0 )
    {
        return 1;
    }
    else
        return 0;
}
void showStudents(User user){
        for (int i = 0; i < studentLength; i++)
        {   printf("Student ID: %d\n", i+1);
            printf("Student Name: %s\n",user.student1[i].name);
            printf("Student Email: %s\n",user.student1[i].email);
            printf("Student CGPA: %s\n",user.student1[i].cgpa);
        }
    }
int main() {
   User user1,user2;
    printf("How Many Students: ");
    scanf("%d",&studentLength);
    printf("How Many Teachers: ");
    scanf("%d",&teachersLength);
    for ( int i = 0; i < studentLength; i++)
    {   printf("Enter Student Information:\n");
        printf("Name:");
        fflush(stdin);
        scanf("%s",&user1.student1[i].name);
        fflush(stdin);
        printf("\nEmail:");
        scanf("%s",&user1.student1[i].email);
        printf("\nPassword:");
        scanf("%s",&user1.student1[i].password);
        printf("\nCGPA:");
        scanf("%s",&user1.student1[i].cgpa);
    }
    for ( int i = 0; i < teachersLength; i++)
    {   printf("Enter Teacher Information:\n");
        printf("Name:");
        scanf("%s",&user1.teacher1[i].name);
        fflush(stdin);
        printf("\nEmail:");
        scanf("%s",&user1.teacher1[i].email);
        printf("\nPassword:");
        scanf("%s",&user1.teacher1[i].password);
        printf("\nDesignation:");
        scanf("%s",&user1.teacher1[i].designation);
    }
    selectUser(user1,user2);
    return 0;
}
