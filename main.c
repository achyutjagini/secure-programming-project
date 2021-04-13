#include "header.h"
int main()
{
    accs = (ACCOUNT*)malloc(sizeof(ACCOUNT)*10000);
    curr = NULL;
    init(&m);
    flag = false;
    if (m!=0)
        flag = true;
    printf("1.Create a new account\n2.Login\n3.Exit\nEnter your choice:");
    int c;
    scanf("%d",&c);
    if(c==1)
    {
        reg_acc();
        printf("\nYou have registered successfully!\n\n");
        activity();
    }
    else if (c==2 && flag)
    {
        login();
        activity();
    }
    else if (c==3)
    {
        printf("Thank you!\n");
        exit(0);
    }
    else
    {
        printf("Invalid choice. Try Again!\n");
        free(accs);
        main();
    }
}