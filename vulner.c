#include "header.h"
int i;
ACCOUNT* init(int *position)
{
    *position = 0;
    FILE* f = fopen("db.csv","r");
    if (f==NULL)
        return NULL;
    else
    {
        ACCOUNT t;
        while (fread(&t,sizeof(ACCOUNT),1,f))
        {
            accs[*position] = t;
            (*position)++;
        }
        fclose(f);
        if(*position==0)
            return NULL;
        else
            return accs;
    }
}

void reg_acc()
{
    printf("\nEnter username:");
    scanf("%s",accs[m].usrn);
    printf("Enter password: ");
    scanf("%s",accs[m].pwd);
    printf("Enter balance(only usd accepted): ");
    scanf("%d",&accs[m].bal);
    accs[m].ts = 0;
    accs[m].ap = 0;
    accs[m].k = 0;
    accs[m].wd = 0;
    accs[m].nf = 0;
    curr = &accs[m];

    FILE* f = fopen("db.csv","a");
    fwrite(&accs[m],sizeof(ACCOUNT),1,f);
    fclose(f);

    m++;
}


char user[20];

void login()
{
   
    char password[20];
    printf("\nEnter username: ");
    scanf("%s",user);
    printf("Enter password: ");
    scanf("%s",password);
    bool found = false;
    for(i=0;i<m;i++)
    {
        if(!strcmp(accs[i].usrn,user) && !strcmp(accs[i].pwd,password))
        {
            curr = &accs[i];
            found = true;
            break;
        }
    }
    if(!found)
    {
        printf("\nDetails are invalid.Try Again.\n");
        free(accs);
        main();
    }
    else
        printf("\nHello %s!What would you like to do?\n",user);
}

void activity()
{
    int c,s,tot,choice;
    char ch;
    
    while(true)
    {
        printf("1.Check account balance\n2.Buy Stocks\n3.Check my portfolio\n4.Exit\nEnter your choice: ");
        scanf("%d",&c);
        printf("\n");
        if (c==1)
            printf("%s Your current balance is $%d\n",user,curr->bal);
        else if (c==2)
        {
            printf("Here are your options:\n\n");
            printf("1. Tesla(TSLA) for $840\n");
            printf("2. Apple(AAPL) $134\n");
            printf("3. The Coca-Cola Company(KO) $50\n");
            printf("4. The Walt Disney Company(DIS) $171\n");
            printf("5. Netflix(NFLX) $539\n");
            printf("What would you like to buy(If you would like to buy apple type 2):");
            scanf("%d",&choice);
            printf("How many stocks do you want to buy? ");
            scanf("%d",&s);
            if(s<=0)
              {
                  printf("Invalid quantity\n");
                  break;
               }
            if(choice ==1)
               {
                  tot = s*840;
                  curr->ts =+s;
                  curr->bal-=tot;
               }
            else if(choice ==2)
               {
                   tot = s*134;
                   curr->ap =+s;
                   curr->bal-=tot;
               }
            else if(choice ==3)
               {
                    tot = s*50;
                    curr->k = +s;
                    curr->bal-=tot;
               }
            else if(choice ==4)
               {
                   tot = s*171;
                   curr->wd =+s;
                   curr->bal-=tot;
               }
            else if(choice ==5)
               {
                    tot = s*539;
                    curr->nf =+s;
                    curr->bal-=tot;
               }
            else
               {
                   printf("Invalid choice\n");
                }
             
            printf("Total cost: $%d\n",tot);
            printf("Your transaction is successful!\n");
            update();
        }
       else if(c==3)
            {
               printf("Here is your portfolio:\n");
               printf("Tesla(TSLA): %d\n",curr->ts);
               printf("Apple(AAPL): %d\n",curr->ap);
               printf("The Coca-Cola Company(KO): %d\n",curr->k);
               printf("The Walt Disney Company(DIS): %d\n",curr->wd);
               printf("Netflix(NFLX): %d\n",curr->nf);
            } 
        else if (c==4)
        {
            free(accs);
            printf("Thank you %s!\n",user);
            exit(0);
        }
        else
            printf("Try again.\n");
        printf("\n");
    }
}

void update()
{
    FILE* f = fopen("db.csv","w");
    for(i=0;i<m;i++)
        fwrite(&accs[i],sizeof(ACCOUNT),1,f);
    fclose(f);
}
