#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
char name[20];
char colour[20];
char modele[20];
char price[10];
int hp;
struct node * link;
};
struct use
{
char fn[15];
char ln[15];
char ad[100];
char ph[15];
char em[35];
struct use * list;
};
struct nb
{
char f[15];
char l[15];
char a[100];
char p[15];
char e[35];
char n[15];
struct nb * lst;
};
struct node * first=NULL;
struct use * start=NULL;
struct nb * head=NULL;
void add();
void dis();
void ser();
void sell();
void buy();
void binfo();
void sinfo();
void disp();
int ch;
void main()
{int n,m=1,a,c;
int feed=0,k=0;
char na,nam[10],pa[15]="pass",pwd[15];
clrscr();
while(m)
{
printf("\t\t\t**************************************\t\t\n");
printf("\t\t\t    --||WELCOME TO SELECTMYCAR||--\t\t\n");
printf("\t\t\t**************************************\t\t\n");
printf("\n\n\n*\tPress 1 for onwer\n*\tPress 2 for user\n");
scanf("%d",&ch);
if(ch==1)
{
printf("\nEnter the password\n");
while(1)
{
 na=getch();
 if(na==13)
 {
 pwd[k]=NULL;
 break;
 }
 else if (na==8)
 {
 printf("\b \b");
 k--;
 }
 else
 {
 pwd[k]=na;
 printf("*");
 k++;
 }
}
if(strcmp(pa,pwd))
{
printf("\n\t!!!!Incorrect password!!!!\n");
k=0;
}
else
{
printf("\n____________________\n1.To add\n2.To display cars\n3.To display buyer\n4.Display seller\n5.Feedback\n___________________\n");
scanf("%d",&c);
switch(c)
{
case 1:
add();
break;
case 2:
disp();
dis();
break;
case 3:
binfo();
break;
case 4:
sinfo();
case 5:
if(feed==0)
{
printf("\n No feedbacks\n");
}
else
{
printf("\n%s\t%d\n",nam,feed);
}
break;
default:
printf("***********\nWorng input\n***********\n");
}
}
}
else if(ch==2)
{
printf("\n_________________________________\n1.For display the cars avalible\n2.To sell a car\n3.Buy a car\n4.Feedback\n__________________________________\n");
scanf("%d",&a);
switch(a)
{
case 1:
disp();
dis();
if(ch==2)
{
printf("\n\n\t=====================\n\tWant to buy a car\n");
printf("\tPress 1 for YES\n\tPress 0 to exit\n\t===================== \n");
scanf("%d",&n);
if(n==1)
{
buy();
}
}
break;
case 2:
add();
printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-\nEnter your detail\n");
sell();
break;
case 3:
buy();
break;
case 4:
printf("\nGive your feedback\n");
printf("5 for very setisfied\n4 for somewhat setisfied\n3 for Neither satis fied nor dissatisfied\n2 for Somewhat dissatisfied\n1 for very dissatisfied\n");
scanf("%d",&feed);
printf("Enter your name");
scanf("%s",&nam);
printf("THANKS FOR THE FEEDBACK\n ");
break;
default:
printf("\n************\nWorng input\n************\n");
}
}
else
{
printf("*************");
printf("\nWrong input\n");
printf("*************\n");
}
printf("\n\t\t\t***************************\n");
printf("\t\t\tWant to return to menu\n\t\t\tpress 1 for yes\n\t\t\t0 for exit\n");
printf("\t\t\t***************************\n");
scanf("%d",&m);
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
}

void add()
{
struct node *p,*t;
p=( struct node *)malloc(sizeof(struct node));
printf("\nEnter the car name\n");
scanf("%s",&(p->name));
printf("\nEnter the model\n");
scanf("%s",&(p->modele));
printf("\nEnter the colour\n");
scanf("%s",&(p->colour));
printf("\nEnter the price\n");
scanf("%s",&(p->price));
printf("\nEnter the horse power\n");
scanf("%d",&(p->hp));
p->link=NULL;
if(first==NULL)
{first=p;
}
else
{
t=first;
while(t->link!=NULL)
{t=t->link;
}
t->link=p;
}
}

void dis()
{
struct node * temp=first;
if(first!=NULL)
{
while(temp!=NULL)
{
printf("%s        %s        %s      %s          %d\n",temp->name,temp->modele,temp->colour,temp->price,temp->hp);
temp=temp->link;
}
}

}
void sell()
{
int n,a=1;
char p1[12];
struct use *p,*t;
p=( struct use *)malloc(sizeof(struct use));
printf("\nEnter your first name\n");
scanf("%s",&(p->fn));
printf("\nEnter your last name\n");
scanf("%s",&(p->ln));
printf("\nEnter phone.no\n");
scanf("%s",&(p->ph));
while(a)
{
n=strlen(p->ph);
if(n<10)
{
printf("Wrong phone number\n");
printf("Enter again\n");
scanf("%s",&p1);
strcpy(p->ph,p1);
}
else if(n==10)
{
a=0;
}
else
{
printf("Wrong phone number\n");
printf("Enter again\n");
scanf("%s",&p1);
strcpy(p->ph,p1);
}
}
printf("\nEnter your address\n(use underscore insted of space)\n");
scanf("%s",&(p->ad));
printf("\nEnter your email\n");
scanf("%s",&(p->em));
p->list=NULL;
if(start==NULL)
{start=p;
}
else
{
t=start;
while(t->list!=NULL)
{t=t->list;
}

t->list=p;
}
}

void sinfo()
{
struct use * temp;
temp=start;
if(start!=NULL)
{
while(temp!=NULL)
{
printf("\n____________________\n");
printf("%s\t%s\t%s\t%s\t%s\n",temp->fn,temp->ln,temp->ph,temp->em,temp->ad);
temp=temp->list;
}
}
else
printf("_____________________\nNO seller avalible\n_____________________\n");
}

void binfo()
{
struct nb * tmp;
tmp=head;
if(head!=NULL)
{
while(tmp!=NULL)
{
printf("\n__________________\n");
printf("%s\t%s\t%s\t%s\t%s\t%s\n",tmp->f,tmp->l,tmp->p,tmp->e,tmp->n,tmp->a);
tmp=tmp->lst;
}
}
else
printf("___________________\nNO buyer avalible\n___________________");
}

void buy()
{
int n,a=1;
char p1[12];
struct nb *pe,*te;
pe=( struct nb *)malloc(sizeof(struct nb));
printf("\nEnter your first name\n");
scanf("%s",&(pe->f));
printf("\nEnter your last name\n");
scanf("%s",&(pe->l));
printf("\nEnter phone.no\n");
scanf("%s",&(pe->p));
while(a)
{
n=strlen(pe->p);
if(n<10)
{
printf("Wrong phone number\n");
printf("Enter again\n");
scanf("%s",&p1);
strcpy(pe->p,p1);
}
else if(n==10)
{
a=0;
}
else
{
printf("Wrong phone number\n");
printf("Enter again\n");
scanf("%s",&p1);
strcpy(pe->p,p1);
}
}
printf("\nEnter your address\n(use underscore insted of space)\n");
scanf("%s",&(pe->a));
printf("\nEnter your email\n");
scanf("%s",&(pe->e));
printf("\nEnter the name of the car which u want to buy\n");
scanf("%s",&(pe->n));
printf("\n");
printf("\t\t*********************************************************\n");
printf("\t\tWe will contact you shortly...Thank you for your perchace\n");
printf("\t\t*********************************************************\n");
pe->lst=NULL;
if(head==NULL)
{head=pe;
}
else
{
te=head;
while(te->lst!=NULL)
{
te=te->lst;
}

te->lst=pe;
}
 }
void disp()
{
printf("NAME      MODEL     COLOUR     PRICE       HORSE POWER\n");
printf("BMW       M5        BLACK      12.2lakh    700\n");
printf("NISSAN    GTR       BLUE       22.2lakh    1300\n");
printf("AUDI      R8        RED        17.8lakh    900\n");
printf("BENTLEY   GT        SILVER     14.2lakh    450\n");
printf("FERRARI   488       RED        20.0lakh    700\n");
}

