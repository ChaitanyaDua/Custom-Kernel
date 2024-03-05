#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <libgen.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
int main(int agrc,char *argv[])
{
    if(strcmp(argv[0],"./rm.o")==0)
    {
        if(strcmp(argv[2],"-i")!=0 && strcmp(argv[2],"-v")!=0)
        {
            int checkrem=0;
            DIR *dir=opendir(".");
            struct stat st;
            struct dirent *dirr;
            dirr=readdir(dir);
            while(dir!=NULL)
            {
                if(strcmp(dirr->d_name,argv[2])==0)
                {
                    stat(dirr->d_name,&st);
                    if(!(S_ISREG(st.st_mode)))
                    {
                        printf("Cannot delete the directory\n");
                    }
                    int r=remove(dirr->d_name);
                    if(r!=0){
                        printf("Could not delete file\n");
                    }
                }
                
                dirr=readdir(dir);
            }
        }
        if(strcmp(argv[2],"-i")==0)
        {
            int checkrem=0;
            DIR *dir=opendir(".");
            struct stat st;
            struct dirent *dirr;
            dirr=readdir(dir);
            while(dir!=NULL)
            {
                if(strcmp(dirr->d_name,argv[3])==0)
                {
                    stat(dirr->d_name,&st);
                    if(!(S_ISREG(st.st_mode)))
                    {
                        printf("Cannot delete the directory\n");
                    }
                    char inp;
                    printf("Do you want to remove the file: %s?[Y/n] ",argv[3]);
                    scanf("%c",&inp);
                    if(inp=='Y' || inp=='y')
                    {
                        int r=remove(dirr->d_name);
                        if(r==0)
                        {
                            checkrem=1;
                            break;
                        }
                    }
                }
                
                dirr=readdir(dir);
            }
            if(checkrem==0)
            {
                printf("Could not delete directory");
            }
        }
        else
        if(strcmp(argv[2],"-v")==0)
        {
            int checkrem=0;
            DIR *dir=opendir(".");
            struct stat st;
            struct dirent *dirr;
            dirr=readdir(dir);
            while(dir!=NULL)
            {
                if(strcmp(dirr->d_name,argv[3])==0)
                {
                    stat(dirr->d_name,&st);
                    if(!(S_ISREG(st.st_mode)))
                    {
                        printf("Cannot delete the directory\n");
                    }
                    int r=remove(dirr->d_name);
                    if(r==0)
                    {
                        printf("Directory deleted successfully");
                        checkrem=1;
                        break;
                    }
                }
                
                dirr=readdir(dir);
            }
            if(checkrem==0)
            {
                printf("Could not delete directory");
            }
        }
    }
    else
    {
        int len=0;
        int cap=16;
        char **tok=malloc(16*sizeof(char *));
        char *delim=" \t\r\n";
        char *token=strtok(argv[1],delim);
        while(token!=NULL)
        {
            tok[len]=token;
            len++;
            if(len>=cap)
            {
                cap=(int)(cap*1.5);
                tok=realloc(tok,cap*sizeof(char*));
            }
            token=strtok(NULL,delim);
        }
        tok[len]=NULL;
        if(strcmp(tok[0],"-i")!=0 && strcmp(tok[0],"-v")!=0)
        {
            int checkrem=0;
            DIR *dir=opendir(".");
            struct stat st;
            struct dirent *dirr;
            dirr=readdir(dir);
            while(dir!=NULL)
            {
                if(strcmp(dirr->d_name,tok[0])==0)
                {
                    stat(dirr->d_name,&st);
                    if(!(S_ISREG(st.st_mode)))
                    {
                        printf("Cannot delete the directory\n");
                    }
                    int r=remove(dirr->d_name);
                    if(r!=0){
                        printf("Could not delete file\n");
                    }
                }
                
                dirr=readdir(dir);
            }
        }
        if(strcmp(tok[0],"-i")==0)
        {
            int checkrem=0;
            DIR *dir=opendir(".");
            struct stat st;
            struct dirent *dirr;
            dirr=readdir(dir);
            while(dir!=NULL)
            {
                if(strcmp(dirr->d_name,tok[1])==0)
                {
                    stat(dirr->d_name,&st);
                    if(!(S_ISREG(st.st_mode)))
                    {
                        printf("Cannot delete the directory\n");
                    }
                    char inp;
                    printf("Do you want to remove the file: %s?[Y/n] ",tok[1]);
                    scanf("%c",&inp);
                    if(inp=='Y' || inp=='y')
                    {
                        int r=remove(dirr->d_name);
                        if(r==0)
                        {
                            checkrem=1;
                            break;
                        }
                    }
                }
                
                dirr=readdir(dir);
            }
            if(checkrem==0)
            {
                printf("Could not delete directory");
            }
        }
        else
        if(strcmp(tok[0],"-v")==0)
        {
            int checkrem=0;
            DIR *dir=opendir(".");
            struct stat st;
            struct dirent *dirr;
            dirr=readdir(dir);
            while(dir!=NULL)
            {
                if(strcmp(dirr->d_name,tok[1])==0)
                {
                    stat(dirr->d_name,&st);
                    if(!(S_ISREG(st.st_mode)))
                    {
                        printf("Cannot delete the directory\n");
                    }
                    int r=remove(dirr->d_name);
                    if(r==0)
                    {
                        printf("Directory deleted successfully");
                        checkrem=1;
                        break;
                    }
                }
                
                dirr=readdir(dir);
            }
            if(checkrem==0)
            {
                printf("Could not delete directory");
            }
        }
    }
}
