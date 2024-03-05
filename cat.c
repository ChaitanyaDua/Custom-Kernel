#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <libgen.h>
int main(int argc,char* argv[])
{
    if(strcmp(argv[0],"./cat.o")==0)
    {
        if(strcmp(argv[2],"-n")!=0 && strcmp(argv[2],"-E")!=0)
        {
            for(int i=2;argv[i]!=NULL;i++)
            {
                FILE *pointer;
                char character;
                pointer=fopen(argv[i],"r");
                if(pointer==NULL)
                {
                    printf("cat: %s: No such file or directory\n",argv[i]);
                }
                else
                {
                    character=fgetc(pointer);
                    while(character!=EOF)
                    {
                        printf("%c",character);
                        character=fgetc(pointer);
                    }
                }
                fclose(pointer);
            }
        }
        else
        if(strcmp(argv[2],"-n")==0)
        {
            int count=1;
            for(int i=3;argv[i]!=NULL;i++)
            {
                FILE *pointer;
                pointer=fopen(argv[i],"r");
                if(pointer==NULL)
                {
                    printf("cat: %s: No such file or directory\n",argv[i]);
                }
                else
                {
                    char character;char charnext;
                    character=fgetc(pointer);int flag=0;
                    charnext=fgetc(pointer);
                    printf("%d ",count++);
                    while(character!=EOF)
                    {
                        /*if(flag==0)
                        {
                            printf("%d) ",count++);
                            printf("%c",character);
                            flag=3;
                        }
                        else
                        if(flag==3)
                        {
                            printf("%c",character);
                        }
                        else
                        if(flag==1)
                        {
                            printf("%c",character);
                            flag=0;
                        }
                        else
                        if(flag==2)
                        {
                            printf("%c",character);
                            flag=0;
                        }
                        character=fgetc(pointer);
                        if(character==EOF && flag!=0)
                        {
                            printf(character);
                            break;
                        }
                        if(character==EOF && flag==0)
                        {
                            printf(character);
                            break;
                        }
                        if(character=='\n')
                        flag=1;*/
                        
                        if(character=='\n' && charnext!=EOF)
                        {
                            printf("\n");
                            printf("%d ",count++);
                            character=charnext;
                            charnext=fgetc(pointer);
                        }
                        else
                        {
                            if(character!=EOF)
                            printf("%c",character);
                            character=charnext;
                            charnext=fgetc(pointer);
                            if(charnext==EOF)
                            {
                                if(character!=EOF)
                                printf("%c",character);
                                character=EOF;  
                            }
                        }
                    }
                }
                fclose(pointer);
            }
        }
        else
        if(strcmp(argv[2],"-E")==0)
        {
            int count=0;
            for(int i=1;argv[i]!=NULL;i++)
            {
                count++;
            }
            for(int i=3;argv[i]!=NULL;i++)
            {
                FILE *pointer;
                char character;
                pointer=fopen(argv[i],"r");
                if(pointer==NULL)
                {
                    printf("cat: %s: No such file or directory\n",argv[i]);
                }
                else
                {
                    character=fgetc(pointer);int flag=0;
                    while(character!=EOF)
                    {
                        if(flag==0)
                        {
                            printf("%c",character);
                        }
                        else
                        if(flag==1)
                        {
                            printf("$");
                            printf("%c",character);
                            flag=0;
                        }
                        character=fgetc(pointer);
                        if(character=='\n')
                        flag=1;
                    }
                }
                fclose(pointer);
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
    if(strcmp(tok[0],"-n")!=0 && strcmp(tok[0],"-E")!=0)
    {
        for(int i=0;tok[i]!=NULL;i++)
        {
            FILE *pointer;
            char character;
            pointer=fopen(tok[i],"r");
            if(pointer==NULL)
            {
                printf("cat: %s: No such file or directory\n",tok[i]);
            }
            else
            {
                character=fgetc(pointer);
                while(character!=EOF)
                {
                    printf("%c",character);
                    character=fgetc(pointer);
                }
            }
            fclose(pointer);
        }
    }
    else
    if(strcmp(tok[0],"-n")==0)
    {
        int count=1;
        for(int i=1;tok[i]!=NULL;i++)
        {
            FILE *pointer;
            pointer=fopen(tok[i],"r");
            if(pointer==NULL)
            {
                printf("cat: %s: No such file or directory\n",tok[i]);
            }
            else
            {
                char character;char charnext;
                character=fgetc(pointer);int flag=0;
                charnext=fgetc(pointer);
                printf("%d ",count++);
                while(character!=EOF)
                {
                    /*if(flag==0)
                    {
                        printf("%d) ",count++);
                        printf("%c",character);
                        flag=3;
                    }
                    else
                    if(flag==3)
                    {
                        printf("%c",character);
                    }
                    else
                    if(flag==1)
                    {
                        printf("%c",character);
                        flag=0;
                    }
                    else
                    if(flag==2)
                    {
                        printf("%c",character);
                        flag=0;
                    }
                    character=fgetc(pointer);
                    if(character==EOF && flag!=0)
                    {
                        printf(character);
                        break;
                    }
                    if(character==EOF && flag==0)
                    {
                        printf(character);
                        break;
                    }
                    if(character=='\n')
                    flag=1;*/
                    
                    if(character=='\n' && charnext!=EOF)
                    {
                        printf("\n");
                        printf("%d ",count++);
                        character=charnext;
                        charnext=fgetc(pointer);
                    }
                    else
                    {
                        if(character!=EOF)
                        printf("%c",character);
                        character=charnext;
                        charnext=fgetc(pointer);
                        if(charnext==EOF)
                        {
                            if(character!=EOF)
                            printf("%c",character);
                            character=EOF;  
                        }
                    }
                }
            }
            fclose(pointer);
        }
    }
    else
    if(strcmp(tok[0],"-E")==0)
    {
        int count=0;
        for(int i=1;tok[i]!=NULL;i++)
        {
            count++;
        }
        for(int i=1;tok[i]!=NULL;i++)
        {
            FILE *pointer;
            char character;
            pointer=fopen(tok[i],"r");
            if(pointer==NULL)
            {
                printf("cat: %s: No such file or directory\n",tok[i]);
            }
            else
            {
                character=fgetc(pointer);int flag=0;
                while(character!=EOF)
                {
                    if(flag==0)
                    {
                        printf("%c",character);
                    }
                    else
                    if(flag==1)
                    {
                        printf("$");
                        printf("%c",character);
                        flag=0;
                    }
                    character=fgetc(pointer);
                    if(character=='\n')
                    flag=1;
                }
            }
            fclose(pointer);
        }
    }
            
    }
}
