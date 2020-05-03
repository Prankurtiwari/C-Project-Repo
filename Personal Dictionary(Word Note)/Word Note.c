#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct WORD
{
    char term[50];
    char meaning[1000];
} DIC;

FILE *fp,*ft;
char query[50],temppname[50];
int i,ch,found,flag;

int main()
{   int choice,count;
    thing:
    system("cls");
    printf("\t\t\t\t\t\t=======MAIN  MENU============\n");
    printf("\t\t\t\t\t\t 1.Enter the Word\n");
    printf("\t\t\t\t\t\t 2.Search the word\n");
    printf("\t\t\t\t\t\t 3.Display the list of Words\n");
    printf("\t\t\t\t\t\t 4.Delete the Word\n");
    printf("\t\t\t\t\t\t 0.Exit\n");
    printf("\t\t\t\t\t\t============================\n");
    printf("\t\t ENTER YOUR CHOICE:");
    scanf("%d",&choice);
    switch(choice)
    {
        system("cls");

        case 0:
            printf("\t\t\t\t\t\tARE YOU SURE?\n\n\n");
            break;

        case 1:
                system("cls");

                for(;;)
                {
                    found=0;
                    fp=fopen("thesaurus.dll","r");
                    fflush(stdin);
                    printf("NOTE:To exit enter blank space in the term input\n");
                    printf("Enter the term\n");
                    scanf("%[^\n]s",DIC.term);
                    fflush(stdin);
                    if(stricmp(DIC.term,"")==0 || stricmp(DIC.term," ")==0)
                    break;
                    strcpy(temppname,DIC.term);
                    system("cls");
                    while(fread(&DIC,sizeof(DIC),1,fp)==1)
                    {
                        if(stricmp(DIC.term,temppname)==0)
                        {
                            printf("TERM ALREADY THERE \n");
                            printf("\n..::TERM\t: %s\n..::MEANING\t: %s\n.\n",DIC.term,DIC.meaning);
                            found++;
                        }
                    }
                    fclose(fp);

                    if(found==0)
                    {
                        fp=fopen("thesaurus.dll","a");
                        fflush(stdin);
                        strcpy(DIC.term,temppname);
                        printf("Enter the meaning of %s\n",DIC.term);
                        scanf("%[^\n]s",DIC.meaning);
                        fwrite(&DIC,sizeof(DIC),1,fp);
                        fclose(fp);
                    }
                    else
                        printf("\nElement Already present ABOVE IS THE MEANING OF IT\n");
                    break;
                }

                break;

        case 3:
                 system("cls");
                 printf("\n==============\nLIST OF WORDS\n==============\n\n");
                 for(i=97; i<=122; i=i+1)
                    {
                        fp=fopen("thesaurus.dll","r");
                        fflush(stdin);
                        flag=0;
                        while(fread(&DIC,sizeof(DIC),1,fp)==1)
                            {
                                if(DIC.term[0]==i || DIC.term[0]==i-32)
                                {
                                    printf("TERM\t: %s\nMEANING\t: %s\n\n",DIC.term,DIC.meaning);
                                    flag++;
                                }
                            }

                                if(flag!=0)
                                {
                                    printf("=========================================================== [%c][%d]\n\n",i-32,flag);
                                }
                                fclose(fp);
                    }
                break;

        case 2:
                system("cls");
                do
                    {
                        printf("\n\n\t..::TERM SEARCH\n\t===========================\n\t..::TERM to search: ");
                        fflush(stdin);
                        scanf("%[^\n]s",query);
                        fp=fopen("thesaurus.dll","r");
                        system("cls");
                        printf("\n\n..::Search result for '%s' \n===================================================\n",query);
                        while(fread(&DIC,sizeof(DIC),1,fp)==1)
                            {
                                if(stricmp(DIC.term,query)==0)
                                    printf("\n..::TERM\t: %s\n..::MEANING\t: %s\n.\n",DIC.term,DIC.meaning);
                            }
                            fclose(fp);
                            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
                            scanf("%d",&ch);

        }while(ch==1);
        break;
        case 4:
                system("cls");
                fflush(stdin);
                printf("\n\n\t..::DELETE A WORD\n\t==========================\n\t..::Enter the Word:");
                scanf("%[^\n]",&temppname);
                fp=fopen("thesaurus.dll","r");
                ft=fopen("temp.dat","w");
                while(fread(&DIC,sizeof(DIC),1,fp)!=0)
                {
                    if (stricmp(temppname,DIC.term)!=0)
                    fwrite(&DIC,sizeof(DIC),1,ft);
                }
                    fclose(fp);
                    fclose(ft);
                remove( "thesaurus.dll" );
                rename("temp.dat" , "thesaurus.dll");
                break;
        default:
        printf("Invalid choice");
        break;
    }
    printf("\t\t\t\t\t\t=======END  MENU============\n");
    printf("\t\t\t\t\t\t 1.RETURN BACK TO MAIN MENU\n");
    printf("\t\t\t\t\t\t 0.EXIT\n");
    printf("\t\t\t\t\t\t============================\n");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1:
                fflush(stdin);
                goto thing;
        case 0:
                break;
        default:
                printf("Invalid choice");
                goto thing;
                break;
    }
return 0;
}
