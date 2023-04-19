#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   char username[50], password[50], check_user[50], check_pass[50];
   int option, found = 0;

   printf("Welcome to the Login Module\n");
   printf("---------------------------\n");

   do {
      printf("\nPlease select an option:\n");
      printf("1. Login\n");
      printf("2. Create New User\n");
      printf("3. Exit\n");

      scanf("%d", &option);

      switch(option) {
         case 1:
            found = 0;
            printf("\nPlease enter your username: ");
            scanf("%s", username);
            printf("Please enter your password: ");
            scanf("%s", password);

            fp = fopen("users.txt", "r");

            while(fscanf(fp, "%s %s", check_user, check_pass) != EOF) {
               if(strcmp(username, check_user) == 0 && strcmp(password, check_pass) == 0) {
                  found = 1;
                  break;
               }
            }

            if(found) {
               printf("\nLogin successful!\n");
               
            }
            else {
               printf("\nInvalid username or password!\n");
            }

            fclose(fp);
            break;

         case 2:
            printf("\nPlease enter a username: ");
            scanf("%s", username);
            printf("Please enter a password: ");
            scanf("%s", password);

            fp = fopen("users.txt", "a");

            fprintf(fp, "%s %s\n", username, password);

            fclose(fp);

            printf("\nUser created successfully!\n");
            break;

         case 3:
            printf("\nExiting...\n");
            break;

         default:
            printf("\nInvalid option!\n");
            break;
      }
   } while(option != 3);

   return 0;
}
