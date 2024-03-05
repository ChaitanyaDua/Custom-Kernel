#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <libgen.h>
#include <dirent.h>
#include <errno.h>
int main(int argc,char* argv[])
{
    if(strcmp(argv[0],"./mkdir.o")==0)
    {
        char *yelo=argv[1];
        /*int len=0;
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
        tok[len]=NULL;*/
        //./mkdir.o mkdir -p(or -v) 
        //char *comp;
        //comp=(char *)malloc(2*sizeof(char));
        //comp[0]=argv[1][0];
        //comp[1]=argv[1][1];
        if(strcmp(argv[2],"-p")!=0 && strcmp(argv[2],"-v")!=0)
        {
            char *thiscwd;
            char *buffer=NULL;
            size_t size=0;
            thiscwd=getcwd(buffer,size);
            /*int flag=0;
            for(int i=0;argv[1][i]!='\0';i++)
            {
                if(argv[1][i]=='/')
                {
                    printf("mkdir: cannot create directory '%s': No such file or directory",argv[1]);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                int check;
                char *finaldir;
                finaldir=(char *)malloc(256*sizeof(char));
                char *newdirectory=argv[1];int d=0;
                for(int i=0;i<strlen(argv[1])-1;i++)
                {
                    finaldir[d++]=newdirectory[i];
                }
                check=mkdir(finaldir,0777);
            }*/
            char *list[256];int indct=0;
            for(int i=2;argv[i]!=NULL;i++)
            {
                char *newst;int indct2=0;
                newst=(char *)malloc(256*sizeof(char));
                newst=argv[i];
                /*for(int j=i;j<strlen(argv[i]);j++)
                {
                    if(argv[1][j]==' ')
                    {
                        break;
                    }
                    else
                    {
                        newst[indct2++]=argv[1][i++];
                    }
                }*/
                list[indct++]=newst;
            }
            for(int i=0;i<indct;i++)
            {
                int flag=0;
                for(int j=0;j<strlen(list[i]);j++)
                {
                    if(list[i][j]=='/')
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    int flag2=0;int ind;
                    for(int k=strlen(list[i])-1;k>=0;k--)
                    {
                        if(list[i][k]=='/')
                        {
                            ind=k;
                            break;
                        }
                    }
                    for(int k=0;k<ind;k++)
                    {
                        char *newf;
                        newf=(char *)malloc(256*sizeof(char));int y=0;int l=k;
                        for(int p=l;list[i][p]!='/';p++)
                        {
                            newf[y++]=list[i][p];
                            k++;
                        }
                        int check=chdir(newf);
                        if(check!=0)
                        {
                            flag2=1;
                            break;
                        }
                    }
                    if(flag2==1)
                    {
                        printf("mkdir: cannot create directory '%s': No such file or directory\n",list[i]);
                        chdir(thiscwd);
                    }
                    else
                    {
                        int h;
                        char *final;
                        final=(char *)malloc(256*sizeof(char *));int u=0;
                        for(int t=ind+1;t<strlen(list[i]);t++)
                        final[u++]=list[i][t];
                        int ch=chdir(final);
                        if(ch==0)
                        {
                            printf("mkdir: cannot create directory '%s': File exists\n",list[i]);
                            chdir(thiscwd);
                        }
                        else
                        {
                            h=mkdir(final,0777);
                            chdir(thiscwd);
                        }
                    }
                }
                else
                {
                    //int gu=chdir(thiscwd);
                    int gt=chdir(list[i]);
                    if(gt==0)
                    {
                        printf("mkdir: cannot create directory '%s': File exists\n",list[i]);
                    }
                    else
                    {
                        int gy;
                        gy=mkdir(list[i],0777);
                    }
                }
            }
        }
        else
        if(strcmp(argv[2],"-p")==0)
        {
            //har *args[2]={" ","hi hi hi/hi"};
            char *newstr;
            newstr=(char*)malloc(256*sizeof(char));int ind=0;int ct=0;
            for(int i=0;i<strlen(argv[3]);i++)
            {
                ct++;
            }
            for(int i=0;i<ct;i++)
            {
                newstr[ind++]=argv[3][i];
            }
            char * listoffolders[256];int ind2=0;char *folderthis;int ind3=0;
            folderthis=(char *)malloc(256*sizeof(char));
            for(int i=0;i<ind;i++)
            {
                if(newstr[i]=='/')
                {
                    char *newfolder;
                    newfolder=(char *)malloc(256*sizeof(char));
                    listoffolders[ind2++]=folderthis;
                    folderthis=newfolder;
                    ind3=0;
                }
                else
                {
                    folderthis[ind3++]=newstr[i];
                }
            }
            listoffolders[ind2++]=folderthis;
            //for(int i=0;i<ind2;i++)
            //{
            //    printf("%s\n",listoffolders[i]);
            //}
            //int indcap;
            /*for(int i=0;i<ind2;i++)
            {
                DIR* dir=opendir(listoffolders[i]);
                if(ENOENT==errno)
                {
                    indcap=i;
                    break;
                }
                else
                {
                    int check;
                    char *newdirectory=listoffolders[i];
                    check=mkdir(newdirectory,0777);
                }
            }
            for(int i=indcap;i<ind2-1;i++)
            {
                chdir(listoffolders[i]);
                int check;
                char *newdirectory=listoffolders[i+1];
                check=mkdir(newdirectory,0777);
            }*/
            for(int i=0;i<ind2;i++)
            {
                if(i!=ind2-1)
                {
                    int check;
                    char *newdirectory=listoffolders[i];int flag=0;int ind=-1;
                    for(int i=0;i<strlen(newdirectory);i++)
                    {
                        if(newdirectory[i]==' ')
                        {
                            ind=i;
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1)
                    {
                        if(ind==(strlen(newdirectory)-1))
                        {
                            char *again;int loagain=0;
                            again=(char*)malloc(256*sizeof(char));
                            for(int i=0;i<strlen(newdirectory)-1;i++)
                            again[loagain++]=newdirectory[i];
                            check=mkdir(again,0777);
                            //chdir(newdirectory);
                            printf("mkdir: cannot create directory '/%s': Permission denied",listoffolders[i+1]);
                            break;
                        }
                        else
                        {
                            char *again;int loagain=0;
                            again=(char*)malloc(256*sizeof(char));
                            for(int i=0;i<ind;i++)
                            {
                                again[loagain++]=newdirectory[i];
                            }
                            check=mkdir(again,0777);
                            break;
                        }
                    }
                    check=mkdir(newdirectory,0777);
                    chdir(newdirectory);
                }
                else
                if(i==ind2-1)
                {
                    int check;
                    char *newdirectory=listoffolders[i];
                    char *newfindir;
                    newfindir=(char *)malloc(256*sizeof(char));int g=0;
                    for(int i=0;i<strlen(newdirectory);i++)
                    {
                        if(newdirectory[i]==' ')
                        break;
                        else
                        newfindir[g++]=newdirectory[i];
                    }
                    if(g>0)
                    {
                        check=mkdir(newfindir,0777);
                        //chdir(newdirectory);
                    }
                }
            }
            if(argv[4][0]=='/')
            {
                char *printerrror;
                printerrror=(char *)malloc(256*sizeof(char *));int ct=0;int ind=0;
                for(int i=1;argv[4][i]!='/';i++)
                ct++;
                for(int i=1;i<ct;i++)
                printerrror[ind++]=argv[4][i];
                printf("mkdir: cannot create directory '/%s': Permission denied\n",printerrror);
            }
        }
        else
        if(strcmp(argv[2],"-v")==0)
        {
            //har *args[2]={" ","hi hi hi/hi"};
            char *newstr;
            newstr=(char*)malloc(256*sizeof(char));int ind=0;
            for(int i=0;argv[3][i]!='\0';i++)
            {
                newstr[ind++]=argv[3][i];
            }
            char * listoffolders[256];int ind2=0;char *folderthis;int ind3=0;
            folderthis=(char *)malloc(256*sizeof(char));
            for(int i=0;i<strlen(newstr);i++)
            {
                if(newstr[i]=='/')
                {
                    char *newfolder;
                    newfolder=(char *)malloc(256*sizeof(char));
                    listoffolders[ind2++]=folderthis;
                    folderthis=newfolder;
                    ind3=0;
                }
                else
                {
                    folderthis[ind3++]=newstr[i];
                }
            }
            listoffolders[ind2++]=folderthis;
            int indcap;
            /*for(int i=0;i<ind2;i++)
            {
                DIR* dir=opendir(listoffolders[i]);
                if(ENOENT==errno)
                {
                    indcap=i;
                    break;
                }
                else
                {
                    int check;
                    char *newdirectory=listoffolders[i];
                    check=mkdir(newdirectory,0777);
                }
            }
            for(int i=indcap;i<ind2-1;i++)
            {
                chdir(listoffolders[i]);
                int check;
                char *newdirectory=listoffolders[i+1];
                check=mkdir(newdirectory,0777);
            }*/
            int flag=0;
            for(int i=0;i<ind2-1;i++)
            {
                /*DIR* dir=opendir(listoffolders[i]);
                if(ENOENT==errno)
                {
                    printf("%s",listoffolders[i]);
                    flag=1;
                    break;
                }*/
                int check=chdir(listoffolders[i]);
                if(check!=0)
                {
                    printf("%s",listoffolders[i]);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(int i=0;i<ind2-1;i++)
                {
                    char *newdirectory2=listoffolders[i];
                    chdir(newdirectory2);
                }
                int check;int check2;
                char *newdirectory=listoffolders[ind2-1];
                char *newfindir;
                newfindir=(char *)malloc(256*sizeof(char));int g=0;
                for(int i=0;i<strlen(newdirectory);i++)
                {
                    newfindir[g++]=newdirectory[i];
                }
                check2=chdir(newfindir);
                if(check2==0)
                {
                    printf("mkdir: cannot create directory '");
                    for(int i=0;i<ind2-1;i++)
                    {
                        printf("%s/",listoffolders[i]);
                    }
                    printf("%s': File exists\n",listoffolders[ind2-1]);
                }
                else
                {
                    check=mkdir(newfindir,0777);
                    printf("mkdir: created directory ");
                    for(int i=0;i<ind2-1;i++)
                    {
                        printf("%s/",listoffolders[i]);
                    }
                    printf("%s\n",listoffolders[ind2-1]);
                //chdir(newdirectory);
                }
            }
            else
            {
                printf("mkdir: cannot create directory '");
                for(int i=0;i<ind2-1;i++)
                    {
                        printf("%s/",listoffolders[i]);
                    }
                printf("%s'",listoffolders[ind2-1]);
                printf(": No such file or directory exists\n");
            }
        }
    }
    else
    {
        char *yelo=argv[1];
        /*int len=0;
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
        tok[len]=NULL;*/
        char *comp;
        comp=(char *)malloc(2*sizeof(char));
        comp[0]=argv[1][0];
        comp[1]=argv[1][1];
        if(strcmp(comp,"-p")!=0 && strcmp(comp,"-v")!=0)
        {
            char *thiscwd;
            char *buffer=NULL;
            size_t size=0;
            thiscwd=getcwd(buffer,size);
            /*int flag=0;
            for(int i=0;argv[1][i]!='\0';i++)
            {
                if(argv[1][i]=='/')
                {
                    printf("mkdir: cannot create directory '%s': No such file or directory",argv[1]);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                int check;
                char *finaldir;
                finaldir=(char *)malloc(256*sizeof(char));
                char *newdirectory=argv[1];int d=0;
                for(int i=0;i<strlen(argv[1])-1;i++)
                {
                    finaldir[d++]=newdirectory[i];
                }
                check=mkdir(finaldir,0777);
            }*/
            char *list[256];int indct=0;
            for(int i=0;i<strlen(argv[1])-1;i++)
            {
                /*for(int i=0;i<indct;i++)
            {
                int flag=0;
                for(int j=0;j<strlen(list[i]);j++)
                {
                    if(list[i][j]=='/')
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    int flag2=0;int ind;
                    for(int k=strlen(list[i])-1;k>=0;k--)
                    {
                        if(list[i][k]=='/')
                        {
                            ind=k;
                            break;
                        }
                    }
                    for(int k=0;k<ind;k++)
                    {
                        char *newf;
                        newf=(char *)malloc(256*sizeof(char));int y=0;int l=k;
                        for(int p=l;list[i][p]!='/';p++)
                        {
                            newf[y++]=list[i][p];
                            k++;
                        }
                        k++;
                        int check=chdir(newf);
                        if(check!=0)
                        {
                            flag2=1;
                            break;
                        }
                    }
                    if(flag2==1)
                    printf("mkdir: cannot create directory '%s': No such file or directory\n",list[i]);
                    else
                    {
                        int h;
                        char *final;
                        final=(char *)malloc(256*sizeof(char *));int u=0;
                        for(int t=ind+1;t<strlen(list[i]);t++)
                        final[u++]=list[i][t];
                        h=mkdir(final,0777);
                    }
                }
                else
                {
                    int gt=chdir(list[i]);
                    if(gt==0)
                    {
                        printf("mkdir: cannot create directory '%s': File exists\n",list[i]);
                    }
                    else
                    {
                        int gy;
                        gy=mkdir(list[i],0777);
                    }
                }*/
                char *newst;int indct2=0;
                newst=(char *)malloc(256*sizeof(char));
                for(int j=i;j<strlen(argv[1])-1;j++)
                {
                    if(argv[1][j]==' ')
                    {
                        break;
                    }
                    else
                    {
                        newst[indct2++]=argv[1][i++];
                    }
                }
                list[indct++]=newst;
            }
            /*for(int i=0;i<indct;i++)
            {
                int flag=0;
                for(int j=0;j<strlen(list[i]);j++)
                {
                    if(list[i][j]=='/')
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    printf("mkdir: cannot create directory '%s': No such file or directory\n",list[i]);
                }
                else
                {
                    int gt=chdir(list[i]);
                    if(gt==0)
                    {
                        printf("mkdir: cannot create directory '%s': File exists\n",list[i]);
                    }
                    else
                    {
                        int gy;
                        gy=mkdir(list[i],0777);
                    }
                }
            }*/
            for(int i=0;i<indct;i++)
            {
                int flag=0;
                for(int j=0;j<strlen(list[i]);j++)
                {
                    if(list[i][j]=='/')
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    int flag2=0;int ind;
                    for(int k=strlen(list[i])-1;k>=0;k--)
                    {
                        if(list[i][k]=='/')
                        {
                            ind=k;
                            break;
                        }
                    }
                    for(int k=0;k<ind;k++)
                    {
                        char *newf;
                        newf=(char *)malloc(256*sizeof(char));int y=0;int l=k;
                        for(int p=l;list[i][p]!='/';p++)
                        {
                            newf[y++]=list[i][p];
                            k++;
                        }
                        int check=chdir(newf);
                        if(check!=0)
                        {
                            flag2=1;
                            break;
                        }
                    }
                    if(flag2==1)
                    {
                        printf("mkdir: cannot create directory '%s': No such file or directory\n",list[i]);
                        chdir(thiscwd);
                    }
                    else
                    {
                        int h;
                        char *final;
                        final=(char *)malloc(256*sizeof(char *));int u=0;
                        for(int t=ind+1;t<strlen(list[i]);t++)
                        final[u++]=list[i][t];
                        int ch=chdir(final);
                        if(ch==0)
                        {
                            printf("mkdir: cannot create directory '%s': File exists\n",list[i]);
                            chdir(thiscwd);
                        }
                        else
                        {
                            h=mkdir(final,0777);
                            chdir(thiscwd);
                        }
                    }
                }
                else
                {
                    //int gu=chdir(thiscwd);
                    int gt=chdir(list[i]);
                    if(gt==0)
                    {
                        printf("mkdir: cannot create directory '%s': File exists\n",list[i]);
                    }
                    else
                    {
                        int gy;
                        gy=mkdir(list[i],0777);
                    }
                }
            }
        }
        else
        if(strcmp(comp,"-p")==0)
        {
            //har *args[2]={" ","hi hi hi/hi"};
            char *newstr;
            newstr=(char*)malloc(256*sizeof(char));int ind=0;
            for(int i=3;argv[1][i]!='\0';i++)
            {
                newstr[ind++]=argv[1][i];
            }
            char * listoffolders[256];int ind2=0;char *folderthis;int ind3=0;
            folderthis=(char *)malloc(256*sizeof(char));
            for(int i=0;i<strlen(newstr);i++)
            {
                if(newstr[i]=='/')
                {
                    char *newfolder;
                    newfolder=(char *)malloc(256*sizeof(char));
                    listoffolders[ind2++]=folderthis;
                    folderthis=newfolder;
                    ind3=0;
                }
                else
                {
                    folderthis[ind3++]=newstr[i];
                }
            }
            listoffolders[ind2++]=folderthis;
            //for(int i=0;i<ind2;i++)
            //{
            //    printf("%s\n",listoffolders[i]);
            //}
            int indcap;
            /*for(int i=0;i<ind2;i++)
            {
                DIR* dir=opendir(listoffolders[i]);
                if(ENOENT==errno)
                {
                    indcap=i;
                    break;
                }
                else
                {
                    int check;
                    char *newdirectory=listoffolders[i];
                    check=mkdir(newdirectory,0777);
                }
            }
            for(int i=indcap;i<ind2-1;i++)
            {
                chdir(listoffolders[i]);
                int check;
                char *newdirectory=listoffolders[i+1];
                check=mkdir(newdirectory,0777);
            }*/
            for(int i=0;i<ind2;i++)
            {
                if(i!=ind2-1)
                {
                    int check;
                    char *newdirectory=listoffolders[i];int flag=0;int ind=-1;
                    for(int i=0;i<strlen(newdirectory);i++)
                    {
                        if(newdirectory[i]==' ')
                        {
                            ind=i;
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1)
                    {
                        if(ind==(strlen(newdirectory)-1))
                        {
                            char *again;int loagain=0;
                            again=(char*)malloc(256*sizeof(char));
                            for(int i=0;i<strlen(newdirectory)-1;i++)
                            again[loagain++]=newdirectory[i];
                            check=mkdir(again,0777);
                            //chdir(newdirectory);
                            printf("mkdir: cannot create directory '/%s': Permission denied\n",listoffolders[i+1]);
                            break;
                        }
                        else
                        {
                            char *again;int loagain=0;
                            again=(char*)malloc(256*sizeof(char));
                            for(int i=0;i<ind;i++)
                            {
                                again[loagain++]=newdirectory[i];
                            }
                            check=mkdir(again,0777);
                            break;
                        }
                    }
                    check=mkdir(newdirectory,0777);
                    chdir(newdirectory);
                }
                else
                if(i==ind2-1)
                {
                    int check;
                    char *newdirectory=listoffolders[i];
                    char *newfindir;
                    newfindir=(char *)malloc(256*sizeof(char));int g=0;
                    for(int i=0;newdirectory[i]!=' ';i++)
                    {
                        newfindir[g++]=newdirectory[i];
                    }
                    if(g>0)
                    {
                        check=mkdir(newfindir,0777);
                        //chdir(newdirectory);
                    }
                }
            }
        }
        else
        if(strcmp(comp,"-v")==0)
        {
            //har *args[2]={" ","hi hi hi/hi"};
            char *newstr;
            newstr=(char*)malloc(256*sizeof(char));int ind=0;
            for(int i=3;argv[1][i]!='\0';i++)
            {
                newstr[ind++]=argv[1][i];
            }
            char * listoffolders[256];int ind2=0;char *folderthis;int ind3=0;
            folderthis=(char *)malloc(256*sizeof(char));
            for(int i=0;i<strlen(newstr);i++)
            {
                if(newstr[i]=='/')
                {
                    char *newfolder;
                    newfolder=(char *)malloc(256*sizeof(char));
                    listoffolders[ind2++]=folderthis;
                    folderthis=newfolder;
                    ind3=0;
                }
                else
                {
                    folderthis[ind3++]=newstr[i];
                }
            }
            listoffolders[ind2++]=folderthis;
            int indcap;
            /*for(int i=0;i<ind2;i++)
            {
                DIR* dir=opendir(listoffolders[i]);
                if(ENOENT==errno)
                {
                    indcap=i;
                    break;
                }
                else
                {
                    int check;
                    char *newdirectory=listoffolders[i];
                    check=mkdir(newdirectory,0777);
                }
            }
            for(int i=indcap;i<ind2-1;i++)
            {
                chdir(listoffolders[i]);
                int check;
                char *newdirectory=listoffolders[i+1];
                check=mkdir(newdirectory,0777);
            }*/
            int flag=0;
            for(int i=0;i<ind2-1;i++)
            {
                /*DIR* dir=opendir(listoffolders[i]);
                if(ENOENT==errno)
                {
                    printf("%s",listoffolders[i]);
                    flag=1;
                    break;
                }*/
                int check=chdir(listoffolders[i]);
                if(check!=0)
                {
                    printf("%s",listoffolders[i]);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(int i=0;i<ind2-1;i++)
                {
                    char *newdirectory2=listoffolders[i];
                    chdir(newdirectory2);
                }
                int check;int check2;
                char *newdirectory=listoffolders[ind2-1];
                char *newfindir;
                newfindir=(char *)malloc(256*sizeof(char));int g=0;
                for(int i=0;i<strlen(newdirectory)-1;i++)
                {
                    newfindir[g++]=newdirectory[i];
                }
                check2=chdir(newfindir);
                if(check2==0)
                {
                    printf("mkdir: cannot create directory '");
                    for(int i=0;i<ind2-1;i++)
                    {
                        printf("%s/",listoffolders[i]);
                    }
                    printf("%s': File exists\n",listoffolders[ind2-1]);
                }
                else
                {
                    check=mkdir(newfindir,0777);
                    printf("mkdir: created directory ");
                    for(int i=0;i<ind2-1;i++)
                    {
                        printf("%s/",listoffolders[i]);
                    }
                    printf("%s\n",listoffolders[ind2-1]);
                //chdir(newdirectory);
                }
            }
            else
            {
                printf("mkdir: cannot create directory '");
                for(int i=0;i<ind2-1;i++)
                    {
                        printf("%s/",listoffolders[i]);
                    }
                printf("%s'",listoffolders[ind2-1]);
                printf(": No such file or directory exists\n");
            }
        }
    }
}
