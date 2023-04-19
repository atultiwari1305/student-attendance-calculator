#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fptr;

    char loginuserType[20],c;
    char newuser[100];
    int bufferlength=100;
    int existence=0;
    char line[bufferlength];
    int value;
    

    //----------------LOGIN MODULE----------------//
    
    printf("NEW USER or EXISTING USER: ");
    scanf("%s",loginuserType);
    value=strcmp(loginuserType,"EXISTING");
    if(value==0)
    {
        printf("The word to search: \n");
        scanf("%s",newuser);
        fptr=fopen("details.txt","r");
        while(fgets(line, bufferlength, fptr))
        {
            char *ptr = strstr(line, newuser);
            if(ptr!=NULL)
            {
                existence=1;
                break;
            }
        }
        fclose(fptr);
        if(existence==1)
        {
            printf("Yes");
        }
        else
        {
            printf("No");
        }
    }
    else if(value!=0)
    {
        fptr=fopen("details.txt","a");
        printf("Enter the line of text, press ^z to stop: ");
        while((c=getchar())!=EOF)
        {
            putc(c,fptr);
        }
        fclose(fptr);
    }
    return 0;
}






/////
