#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
struct acc
{
    char usrn[20],pwd[20];
    int bal,stock,ts,ap,k,wd,nf;
};
typedef struct acc ACCOUNT;
int main();
ACCOUNT* init(int*);
void disp_acc(ACCOUNT*);
void disp(ACCOUNT*);
void login();
void reg_acc();
void activity();
void update();
int m;
bool flag;
ACCOUNT* accs;
ACCOUNT* curr;