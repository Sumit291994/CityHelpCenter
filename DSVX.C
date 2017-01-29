#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>

  union REGS in,out;

       void callmouse()
       {
	      in.x.ax=1;
	      int86(51,&in,&out);

       }
	void mouseposi(int *xpos,int *ypos,int *click)
       {
	      in.x.ax=3;
	      int86(51,&in,&out);
	      *click=out.x.bx;
	      *xpos=out.x.cx;
	      *ypos=out.x.dx;
	}
 int mousehide()
       {
	      in.x.ax=2;
	      int86(51,&in,&out);
	      return 1;
       }
void bkcolor()
{
setbkcolor(1);
}
void load()
{
int a,b,i;
 setbkcolor(2);
   settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
   moveto(getmaxx()/2-50,getmaxy()/2);
   outtext("BRICK BREAKER");
   moveto(getmaxx()/2-50,getmaxy()/2+30);
   outtext("LOADING");
   moveto(getmaxx()/2-50,getmaxy()/2+60);
   a=getmaxx()/2-50;
   b=getmaxy()/2+60;
   for(i=0;i<10;i++)
   {
   rectangle(a,b,a+20,b+5);
   floodfill(a+1,b+1,getmaxcolor());
   delay(200);
   a=a+23;
   }
   cleardevice();


 }

void rect(int r,int p)
{
int a1=10,a2=10,a3=60,a4=60;
while(r<a1&&r>a3&&p!=a4)
{
rectangle(a1,a2,a3,a4);
floodfill(a1+1,a2+2,getmaxcolor());
}
}

struct place
{
       char *name;
       struct place *next;
       struct list * down;
       };
struct list
{
       char *name, *add;
       int num;
       struct list *down;
       };

void addplace (struct place**, char*);
void addlist (struct place**, char*, int, char*);
void addlist (struct place**head, char*n, int x, char*a)
{
     struct place*t=*head;
     struct list *temp, *t1;
     temp=(struct list*)malloc(sizeof(struct list));
     temp->name=n;
     temp->num=x;
     temp->add=a;
     temp->down=NULL;
     while(t->next!=NULL)
     t=t->next;
     if(t->down==NULL)
     t->down=temp;
     else
     {
	 t1=t->down;
	 while(t1->down!=NULL)
			      t1=t1->down;
	 t1->down=temp;
	 }
     }
void displayplace (struct place**);
void displayplace (struct place**head)
{
     struct place *t=*head;
     struct list *t1;
     int i=1;
     while(t!=NULL)
     {
		   printf(" \033[33m %d.->%s\n\n\n \033[0m", i++, t->name);
		   t=t->next;
		   }
     }
void addplace (struct place** head, char* n)
{
     struct place *temp, *t=*head;
     temp=(struct place*)malloc(sizeof(struct place));
     temp->name=n;
     temp->next=NULL;
     temp->down=NULL;
     if(*head==NULL)
     *head=temp;
	else
     {
	 while(t->next!=NULL)
	 {
		       t=t->next;
		       }
	 t->next=temp;
	 }
     }

void tictactoe()
{

int x,cl,yt,tt,r;
    int nn=2;
    int t1,t2,t3,t4,t5,t6,t7,t8,t9;
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
   errorcode = graphresult();

   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }


setcolor(65);
settextstyle(7,0,6);
outtextxy(250,350,"TIC TAC TOE");
delay(1000);
for(r=0;r<=390;r=r+5){
setfillstyle(SOLID_FILL,4);
fillellipse(70,0,r,r);
}

    printf("\n\n\n\n\n\n\n\t\t\t\t\n\n\t\t\t\t\n\n\n\t\t\t\t");
    setcolor(30);
    settextstyle(4,0,5);
    outtextxy(50,10,"WELCOME");
    setcolor(35);
    settextstyle(5,0,1);
    outtextxy(15,103,"1. PLAY THE GAME ");
    outtextxy(15,135,"2. EXIT ");
    outtextxy(15,182," ENTER YOUR CHOICE=  ");

    scanf("%d",&tt);
    switch(tt)
 {   case 1:
  {
  cleardevice();

    do
	     {
		    callmouse();
		    mouseposi(&x,&yt,&cl);

   setcolor(98);
   settextstyle(7,0,5);
   outtextxy(300,100,"THE GAME ");
   settextstyle(6,0,2);
   outtextxy(300,200," press any key to exit");
   line(80,80, 80,260);
   line(140,80,140,260);
   line(20,140,200,140);
   line(20,200,200,200);
   if(cl==1)
   {
  if(x>20&&x<80&&yt<140&&yt>80)
   {

   if(nn%2==0)
   {
    line(20,80,80,140);
    line(20,140,80,80);
    t1=3;
    }
    else
    {
    circle(50,100,30);
    t1=2;
    }
    }
    else if(x>80&&x<140&&yt<140&&yt>80)
   {
   if(nn%2==0)
   {
    line(80,80,140,140);
    line(80,140,140,80);
    t2=3;
    }
    else
    {
    circle(110,110,30);
    t2=2;
    }
    }
  else if(x>140&&x<200&&yt<140&&yt>80)
   {
   if(nn%2==0)
   {
    line(140,80,200,140);
    line(140,140,200,80);
    t3=3;
    }
    else
    {t3=2;
    circle(170,110,30);
    }
    }
   else if(x>20&&x<80&&yt<200&&yt>140)
   {
   if(nn%2==0)
   {
    line(20,140,80,200);
    line(20,200,80,140);
    t4=3;
    }
    else
    {
    circle(50,170,30);
    t4=2;
    }
    }
   else if(x>80&&x<140&&yt<200&&yt>140)
   {
   if(nn%2==0)
   {    t5=3;
    line(80,140,140,200);
    line(80,200,140,140);
    }
    else
    {
    circle(110,170,30);
    t5=2;
    }
    }
   else if(x>140&&x<200&&yt<200&&yt>140)
   {
   if(nn%2==0)
   {         t6=3;
    line(140,140,200,200);
    line(200,140,140,200);
    }
    else
    { t6=2;
    circle(170,170,30);
    }
    }
   else if(x>20&&x<80&&yt<260&&yt>200)
   {
   if(nn%2==0)
   {     t7=3;
    line(20,200,80,260);
    line(80,200,20,260);
    }
    else
    {
    circle(50,230,30);
    t7=2;
    }
    }
   else if(x>80&&x<140&&yt<260&&yt>200)
   {
   if(nn%2==0)
   {  t8=3;
    line(80,200,140,260);
    line(80,260,140,200);
    }
    else
    {
    circle(110,230,30);
    t8=2;
    }
    }
   else if(x>140&&x<200&&yt<260&&yt>200)
   {
   if(nn%2==0)
   { t9=3;
    line(140,200,200,260);
    line(140,260,200,200);
    }
    else
    {t9=2;
    circle(170,230,30);
    }
    }
	 if((t1==t2&&t2==t3&&t1==3)||(t1==3&&t1==t4&&t4==t7)||(t3==3&&t3==t6&&t6==t9)||(t8==t7&&t7==t9&&t8==3)||(t1==3&&t1==t5&&t5==t9)||(t3==t5&&t5==t7&&t3==3)||(t2==t5&&t5==t8&&t2==3)||(t4==3&&t4==t5&&t4==t6))
	 {
     for(r=0;r<=220;r=r+5){
setfillstyle(SOLID_FILL,17);
fillellipse(200,550,r,r); }
     setcolor(95);
     settextstyle(7,0,3);
     outtextxy(150,400,"player 1 wins");
     delay(8000);
   // exit(0);
    }
    else if((t1==2&&t1==t2&&t2==t3)||(t1==2&&t1==t4&&t4==t7)||(t3==2&&t3==t6&&t6==t9)||(t8==2&&t8==t7&&t7==t9)||(t1==t5&&t5==t9&&t9==2)||(t3==2&&t3==t5&&t5==t7)||(t2==2&&t2==t5&&t5==t8)||(t4==2&&t4==t5&&t4==t6))
    {
    for(r=0;r<=220;r=r+5){
setfillstyle(SOLID_FILL,10);
fillellipse(200,550,r,r);}
     setcolor(97);
     settextstyle(7,0,3);
    outtextxy(150,400,"player 2 wins");
     delay(2000);
  //  exit(0);
    }
     if(t1==2||t1==3)
    {if(t2==2||t2==3)
    {if(t3==2||t3==3)
    {if(t4==2||t4==3)
    {if(t5==2||t5==3)
    {if(t6==2||t6==3)
    {if(t7==2||t7==3)
    {if(t8==2||t8==3)
    {if(t9==2||t9==3)
    {
      for(r=0;r<=220;r=r+5){
setfillstyle(SOLID_FILL,10);
fillellipse(200,550,r,r);}
     setcolor(97);
     settextstyle(7,0,3);
    outtextxy(150,400,"game draw");
     delay(2000);
   // exit(0);
    }}}}}}}}}
    nn++;
    }
   delay(150);
   }
   while(!kbhit());
   getch();
   closegraph();
 //  return 0;
}
 case 2:cleardevice();
  break;
 //exit(0);
   }
}


int main()
{
  struct place *head=NULL, *temp;
  struct list *temp2, *t2, *t3, *pret2;
  int choice, choiceA, choiceB, choiceC, ng, num,t, i, y=1, sg, cg=0, j;
  int c,d,e,f;
	int il;
	double jl;
	char ul[20];
	char pl[20];
	char chl;
	char pdl[20]="computer";
   int m=0;
   int g=0;
   int h=100;
   int sp1=1;
   int sp2=1;
   int s=0,xtra;
   int a1=290,a2=50,a3=360,a4=75;
   int a5,game;
   int n=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0,n10=0,n11=0,n12=0,n13=0,l;
  char pswrd[10], password[10]={'D', 'S', 'V'}, pass[10], st[25], ad[100];
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "C:\\TurboC3\\bgi");
//  clrscr();
  addplace(&head, "Hospitals");
  addlist(&head, "City Hospital", 76904573, "G-11, Mall road, Central square, New Delhi");
  addlist(&head, "Heart Care Hospital", 29691542, "Plot No. 10, Panth Nagar, New Delhi");
  addlist(&head, "Fortis Hospital", 47322840, "A-22, Sector - 62, Noida, UP(NCR)");
  addlist(&head, "Sanjivini Hospital", 10239727, "Alam Bagh, Opposite ITO, New Delhi");
  addlist(&head, "Army Hospital", 43892227, "Arjun Vihar, Delhi Cantonment, New Delhi");
  addplace(&head, "Malls");
  addlist(&head, "Shipra Mall", 11226053, "Shipra Suncity, Indirapuram, NCR(ghzbd)");
  addlist(&head, "The Great India Place Mall", 10856369, "Sector - 18, Noida, NCR(UP)");
  addlist(&head, "Ambiance Mall", 98542283, "Iffco Chowk, Gurgaon, NCR(Haryana)");
  addlist(&head, "Cross river Mall", 98543925, "J-54, Karkarduma, New Delhi");
  addlist(&head, "Metropolitian Mall", 57438216, "66-U, Dhaula Kuan, New Delhi");
  addplace(&head, "Historical monuments");
  addlist(&head, "Red Fort", 54374029, "Ring road, Opposite Chandi Chowk, Old Delhi");
  addlist(&head, "India Gate", 13533286, "Rajpath, Central Delhi, New Delhi");
  addlist(&head, "Qutub Minar", 622040126, "Inner Ring Road, Vijay ghat, New Delhi");
  addlist(&head, "Lotus Temple",86282111, "B1-305, National Highway 4, New Delhi");
  addlist(&head, "Jantar Mantar", 49206022, "City Center, Opposite Supreme Court, New Delhi");
  addplace(&head, "Gaming Zone");


 delay(1000);
 do{
for(il=20;il<=62;il++)
	{
		 gotoxy(il,8);
		 printf("%c",196);
		 delay(50);

	}
	for(jl=9;jl<=18;jl++)
	{
		 gotoxy(62,jl);
		 printf("%c",179);
		 delay(50);

	}
	for(il=62;il>=20;il--)
	{
		 gotoxy(il,19);
		 printf("%c",196);
		 delay(50);

	}
	for(jl=18;jl>=9;jl--)
	{
		 gotoxy(20,jl);
		 printf("%c",179);
		 delay(50);

	}
	settextstyle(GOTHIC_FONT, HORIZ_DIR,3);
	outtextxy(250,90,"LOGIN");

	gotoxy(25,11);
	printf("\033[33mUsername:\033[0m ");
     //	settextstyle(TRIPLEX_FONT , HORIZ_DIR,1);
      //	 outtextxy(25,11,"Username:");
	gets(ul);
	gotoxy(25,13);
	printf("\033[33mPassowrd:\033[0m ");
    //	settextstyle(TRIPLEX_FONT , HORIZ_DIR,1);
     //	 outtextxy(25,15,"Passowrd:");
	il=0;
	while(1)
	{

		chl=getch();

		if(chl!=13)
		{
			pl[il]=chl;
			printf("*");
		}
		else
		{
		pl[il]='\0';
		break;
		}
		il++;
	}

      if(strcmp(pdl,pl)!=0)
      {
	gotoxy(25,15);
	xtra=1;
	printf("\033[31m PASSWORD INCORRECT...\033[0m");
	delay(1000);
	cleardevice();
      }
      else
      {
	gotoxy(25,15);
	printf("\033[32m PASSWORD CORRECT...\033[0m");
	xtra=0;
	delay(1000);
	cleardevice();
	
       }
}
while(xtra);
	       settextstyle(TRIPLEX_FONT , HORIZ_DIR,4);
		 outtextxy(100,30,"WELCOME TO CITY HELP CENTER");
		 delay(1000);
  do{
  printf(" \n\n\n\n\n\n");
  printf("\033[33m1.ADMIN  \n\n");
  delay(500);
  printf("2.GUEST  \n\n");
  delay(500);
  printf("3.EXIT   \033[0m \n\n");
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
  delay(1000);
  printf("enter ur choice=  ");
  scanf("%d", &choice);
  printf("\n\n");
  switch(choice)
  {
   case 1:
		     printf("\n\nEnter ur password=  ");
			scanf("%s",pswrd);
			t= strcmp(password,pswrd);
			if(t==0)
			{
				do
				{
				     //	settextstyle(TRIPLEX_FONT , HORIZ_DIR,5);
				      //	outtextxy(100,430,"ADMIN");
					delay(1000);
					printf("\n\n\033[33mADMIN\033[0m>>\n");
					printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
					printf("\033[33m1.ADD A INFRASTRUCTURE     \n\n");
					printf("2.CHANGE PASSWORD  \n\n");
					printf("3.DELETE A INFRASTRUCTURE        \n\n");
					printf("4.SIGN OUT    \033[0m  \n\n");
		    printf("enter ur choice=  ");
					scanf("%d",&choiceA);
					printf("\n\n");
					switch(choiceA)
					{
		     case 1:
			    displayplace(&head);
			    printf("\nEnter the category to which addition has to be made\n\n");
			    scanf("%d", &ng);
			    printf("\n\nEnter the name of the place\n\n");
			    fflush(stdin);
			    scanf("%[^\n]s", st);
			    printf("\n\nEnter the Contact number\n\n");
			    scanf("%d", &num);
			    printf("\n\nEnter the Address....\n\n");
			    fflush(stdin);
			    scanf("%[^\n]s", ad);
			    temp=head;
			    for(i=1; i<ng; i++)
			    temp=temp->next;
			    temp2=(struct list*)malloc(sizeof(struct list));
			    temp2->name=(char*)malloc(strlen(st)+1);
			    temp2->add=(char*)malloc(strlen(ad)+1);
			    strcpy(temp2->name, st);
			    temp2->num=num;
			    strcpy(temp2->add, ad);
			    temp2->down=NULL;
			    t2=temp->down;
			    while(t2->down!=NULL)
			      t2=t2->down;
			      t2->down=temp2;
			    printf("\n\n\033[32mInfrastructure added succesfully.....\033[0m\n\n");
			    break;
		     case 2:

			    printf("\n\n\033[33mADMIN>>CHANGE PASSWORD\033[0m>>\n");
							printf("\033[33mCHANGING DETAILS--\033[0m\n");
							printf("New password-  ");
							scanf("%s",pass);
							printf("current password-  ");
							scanf("%s",pswrd);
							sg= strcmp(password,pswrd);
							if(sg==0)
							{
								strcpy(password,pass);
								printf("\n\n\033[32mpassword sucessfully changed....\033[0m\n");
							}
							else
							{
								printf("\n\n");
								printf("\033[31mIncorrect current password\033[0m \n");
								printf("\n");
							}
							break;
					case 3:
			    displayplace(&head);
			    printf("\n\nEnter category from which deletions is to be done\n\n");
			    scanf("%d", &ng);
			    temp=head;
			    for(i=1; i<ng; i++)
			    temp=temp->next;
			    t2=temp->down;
			    y=1;
			     while(t2!=NULL)
			     {
					    printf("\n\033[33m%d.->%s\033[0m\n\n", y++, t2->name);
					    t2=t2->down;
					    }
			    printf("Enter the infrastructure to be deleted");
			    scanf("%d", &ng);
			    t2=temp->down;
			    for(i=1; i<ng; i++)
			    {
				  pret2=t2;
				  t2=t2->down;
				     }
			    pret2->down=t2->down;
			    free(t2);
			    printf("\n\n\033[32mInfrastructure deleted successfully......\033[0m\n\n");
			    break;
		    case 4:
			    printf("\n\n");
							printf("\033[32mYou are signed out....\033[0m\n");
							printf("\n");
							break;
			default:
							printf("\n\n");
							printf("\033[31mInvalid choice\033[0m");
							printf("\n");
							break;
				   }
		}while(choiceA!=4);
		}
		else
		{
		    printf("\n");
				printf("\033[31mPASSWORD INCORRECT\033[0m\n");
				printf("\n");
		    }
		    break;
    case 2:
	 do
	 {
	       //	settextstyle(TRIPLEX_FONT , HORIZ_DIR,5);
			//	outtextxy(100,430,"GUEST");
	    printf("\033[33m1.VIEW GUIDE\n\n");
	    printf("2.SEARCH A DESTINATION\n\n");
	    printf("3.GO BACK\033[0m\n\n");
	    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
	    printf("Enter ur choice  ");
	    scanf("%d", &choiceB);
	    printf("\n\n");
	    switch(choiceB)
	    {
			case 1:
			     printf("\n\033[33m----------CATEGORIES-------\033[0m\n^^^^^^^^^^^^^^^^^^^^^^^\n\n");
			     displayplace(&head);
			     printf("Enter ur choice  ");
			     scanf("%d", &choiceC);
			    if(choiceC!=4)
			   {
			     temp=head;
			     for(i=1; i<choiceC; i++)
			     {
				 temp=temp->next;
				 if(temp==NULL)
				 {
				 cg=1;
				 break;
				 }
			      }
			     if(cg==1)
			     {
			     cg=0;
			     printf("\n\n\033[31mInvalid Choice\033[0m\n\n\n\n");
			     break;
			     }
			     cg=0;
			     t2=temp->down;
			     y=1;
			     while(t2!=NULL)
			     {
					    printf("\n\033[33m%d.->%s\033[0m\n\n", y++, t2->name);
					    t2=t2->down;
					    }
			     printf("\n\n\033[33m1. DETAILS \n");
			     printf("2. GO BACK\033[0m\n\n");
			     scanf("%d", &ng);
			     printf("\n\n");
			     if(ng==1)
			     {
			     printf("\n\nEnter Choice for Details\n\n");
			     scanf("%d", &j);
			     t2=temp->down;
			     for(i=1; i<j; i++)
				  {
				  t2=t2->down;
				  if(t2==NULL)
				     {
				       cg=1;
				       break;
				     }
				  }
			     if(cg==1)
			     {
			     cg=0;
			     printf("\n\n\033[31mInvalid Choice\033[0m\n\n\n\n");
			     break;
			     }
			     cg=0;
			     printf("\n\n\033[33mContact Number: %d\n\nAddress : %s\033[0m\n\n\n\n", t2->num, t2->add);
			     break;
			     }
			     else if(ng==2)
			     {
			     break;
			     }
			     else
			     {
			     printf("\n\n\033[31mInvalid Choice\033[0m\n\n\n");
			     break;
			   }
			}
		       else
			{
			   printf("1. Brick Bracker\n2. Tic Tac Toe\n");
			printf("which game u want to play- ");
			scanf("%d",&game);
			if(game==1)
			{

			 load();
			bkcolor();
settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
   circle(getmaxx()/2,getmaxy()/2+15,100);
   circle(getmaxx()/2,getmaxy()/2+15,130);
   floodfill(getmaxx()/2,getmaxy()/2-100,getmaxcolor());
   circle(getmaxx()/2,getmaxy()/2+15,200);
   circle(getmaxx()/2,getmaxy()/2+15,230);
   floodfill(getmaxx()/2,getmaxy()/2-200,getmaxcolor());
   moveto(getmaxx()/2-50,getmaxy()/2);
   outtext("1.START GAME");
   moveto(getmaxx()/2-50,getmaxy()/2+10);
   outtext("2.INSTRUCTIONS");
   moveto(getmaxx()/2-50,getmaxy()/2+20);
   outtext("3.EXIT");
   scanf("%d",&c);
   callmouse();
  if(c==1)
  { clock_t start, end;
   cleardevice();
   do
	     {
		    mouseposi(&d,&e,&f);
		    gotoxy(10,9);
		   /*printf("\n\tMouse Position is: %d,%d",d,e);
		    printf("\n\tClick: %d",f);
		    printf("\n\tPress any key to hide the mouse");*/


		     rectangle(d,getmaxy()-50,d+70,getmaxy()-40);

		     floodfill(d+1,getmaxy()-49,getmaxcolor());
		     if(f==1)
		     {
		     m=1;
		     }
		       if(m==0)
		       {
		       g=d+35;
		       h=getmaxy()-59;

		       }
		       circle(g,h,8);
		       mousehide();
   floodfill(g,h,getmaxcolor());
   if(g>=d&&g<d+70&&h+8==getmaxy()-50)
   {
   sp2=sp2*(-1);
   sound(1000);
   delay(50);
   nosound();
   }
   else if(g==getmaxx()||g<0)
   {
   sp1=sp1*(-1);
   }
   else if(h<0)
   {
   sp2=sp2*(-1);
   }
   else if(h==getmaxy())
   {
   sp2=sp2*(-1);
   for(l=3;l>=1;l--)
   {
   printf("%d",l);
   printf("...");
   delay(200);
   }
   printf("GAME OVER");
   printf("\n\nPRESS ANY KEY\n\n");
   printf("\n\n\n\n\n\n\n\n\n\n\n");
   break;
   }
   if(m==1)
   {
   g=g+sp1;
   h=h+sp2;
   }
   delay(4);
   if(g%5==0)
   cleardevice();

   if(g>=a1&&g<=a3&&h-8==a4)
   {
   ++n;
   if(n<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1&&g<=a3&&h+8==a2)
   {
   ++n;
   if(n<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n<1)
   {
   rectangle(a1,a2,a3,a4);
   floodfill(a1+1,a2+1,getmaxcolor());
    floodfill(a1+1,a2+1,getmaxcolor());
   }
    if(g>=a1&&g<=a3&&h-8==a4+50)
   {
   ++n2;
   if(n2<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1&&g<=a3&&h+8==a2+50)
   {
   ++n2;
   if(n2<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n2<1)
   {
   rectangle(a1,a2+50,a3,a4+50);
   floodfill(a1+1,a2+51,getmaxcolor());
     floodfill(a1+1,a2+51,getmaxcolor());
   }
    if(g>=a1&&g<=a3&&h-8==a4+100)
   {
   ++n3;
   if(n3<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1&&g<=a3&&h+8==a2+100)
   {
   ++n3;
   if(n3<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n3<1)
   {
   rectangle(a1,a2+100,a3,a4+100);
   floodfill(a1+1,a2+101,getmaxcolor());
   floodfill(a1+1,a2+101,getmaxcolor());
   }
    if(g>=a1&&g<=a3&&h-8==a4+150)
   {
   ++n4;
   if(n4<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1&&g<=a3&&h+8==a2+150)
   {
   ++n4;
   if(n4<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n4<1)
   {
   rectangle(a1,a2+150,a3,a4+150);
   floodfill(a1+1,a2+151,getmaxcolor());
     floodfill(a1+1,a2+151,getmaxcolor());
   }
    if(g>=a1&&g<=a3&&h-8==a4+200)
   {
   ++n5;
   if(n5<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1&&g<=a3&&h+8==a2+200)
   {
   ++n5;
   if(n5<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n5<1)
   {
   rectangle(a1,a2+200,a3,a4+200);
   floodfill(a1+1,a2+201,getmaxcolor());
   floodfill(a1+1,a2+201,getmaxcolor());
   }
    if(g>=a1+90&&g<=a3+90&&h-8==a4+50)
   {
   ++n6;
   if(n6<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1+90&&g<=a3+90&&h+8==a2+50)
   {
   ++n6;
   if(n6<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n6<1)
   {
   rectangle(a1+90,a2+50,a3+90,a4+50);
   floodfill(a1+91,a2+51,getmaxcolor());
     floodfill(a1+91,a2+51,getmaxcolor());
   }
    if(g>=a1+90&&g<=a3+90&&h-8==a4+100)
   {
   ++n7;
   if(n7<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1+90&&g<=a3+90&&h+8==a2+100)
   {
   ++n7;
   if(n7<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n7<1)
   {
   rectangle(a1+90,a2+100,a3+90,a4+100);
   floodfill(a1+91,a2+101,getmaxcolor());
     floodfill(a1+91,a2+101,getmaxcolor());
   }
    if(g>=a1+90&&g<=a3+90&&h-8==a4+150)
   {
   ++n8;
   if(n8<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1+90&&g<=a3+90&&h+8==a2+150)
   {
   ++n8;
   if(n8<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n8<1)
   {
   rectangle(a1+90,a2+150,a3+90,a4+150);
   floodfill(a1+91,a2+151,getmaxcolor());
     floodfill(a1+91,a2+151,getmaxcolor());
   }
     if(g>=a1-90&&g<=a3-90&&h-8==a4+50)
   {
   ++n9;
   if(n9<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1-90&&g<=a3-90&&h+8==a2+50)
   {
   ++n9;
   if(n9<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n9<1)
   {
   rectangle(a1-90,a2+50,a3-90,a4+50);
   floodfill(a1-89,a2+51,getmaxcolor());
     floodfill(a1-89,a2+51,getmaxcolor());
   }
    if(g>=a1-90&&g<=a3-90&&h-8==a4+100)
   {
   ++n10;
   if(n10<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1-90&&g<=a3-90&&h+8==a2+100)
   {
   ++n10;
   if(n10<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n10<1)
   {
   rectangle(a1-90,a2+100,a3-90,a4+100);
   floodfill(a1-89,a2+101,getmaxcolor());
     floodfill(a1-89,a2+101,getmaxcolor());

   }
    if(g>=a1-90&&g<=a3-90&&h-8==a4+150)
   {
   ++n11;
   if(n11<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1-90&&g<=a3-90&&h+8==a2+150)
   {
   ++n11;
   if(n11<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n11<1)
   {
   rectangle(a1-90,a2+150,a3-90,a4+150);
   floodfill(a1-89,a2+151,getmaxcolor());
     floodfill(a1-89,a2+151,getmaxcolor());

   }
    if(g>=a1-180&&g<=a3-180&&h-8==a4+100)
   {
   ++n12;
   if(n12<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1-180&&g<=a3-180&&h+8==a2+100)
   {
   ++n12;
   if(n12<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n12<1)
   {
   rectangle(a1-180,a2+100,a3-180,a4+100);
   floodfill(a1-179,a2+101,getmaxcolor());
     floodfill(a1-179,a2+101,getmaxcolor());
   }
    if(g>=a1+180&&g<=a3+180&&h-8==a4+100)
   {
   ++n13;
   if(n13<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }
   else if(g>=a1+180&&g<=a3+180&&h+8==a2+100)
   {
   ++n13;
   if(n13<=1)
   {
   sp2=sp2*(-1);
   s++;
   }
   }

   if(n13<1)
   {
   rectangle(a1+180,a2+100,a3+180,a4+100);
   floodfill(a1+181,a2+101,getmaxcolor());
     floodfill(a1+181,a2+101,getmaxcolor());
   }
    gotoxy(70,1);
    printf("points:%d",s);
    if(n>0&&n2>0&&n3>0&&n4>0&&n5>0&&n6>0&&n7>0&&n8>0&&n9>0&&n10>0&&n11>0&&n12>0&&n13>0)
    {

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
    outtextxy(getmaxx()/2-70,getmaxy()/2,"player wins");
    delay(1000);
    break;
    }
   /* start = clock();

   printf("The time was: %f\n", (start) / CLK_TCK); */
   }
while(!kbhit());
cleardevice();
	     getch();
	     }


}
else
{
tictactoe();
cleardevice();
}
			}
			break;
			case 2:
			     displayplace(&head);
			     printf("\n\nEnter the category in whiich u want to search\n\n");
			     scanf("%d", &ng);
			     temp=head;
			     for(i=1; i<ng; i++)
			     temp=temp->next;
			     printf("\n\nEnter the Destination u want to search\n\n");
			     fflush(stdin);
			     scanf("%[^\n]s", st);
			     t2=temp->down;
			     i=1;
			     while(i!=0&&t2!=NULL)
			     {
					i=strcmp(t2->name, st);
					if(i!=0)
					t2=t2->down;
					}
			     if(i==0)
			     {
				     printf("\n\n\n\033[32mDestination located...\033[0m\n\n");
				     printf("\033[33mName : %s\n\nContact number : %d\n\nAddress : %s\033[0m\n\n\n\n", t2->name, t2->num, t2->add);
				     }
			     else
			     {
				 printf("\033[31mSearch term could not be located\033[0m\n\n\n\n");
				 }
			     break;
			case 3:
			     break;
			default:
			     printf("\n\n\n\033[31mInvalid choice\033[0m\n\n");
	     break;
	      }
	      }while(choiceB!=3);
	      break;
    case 3:
	 {
	 delay(500);
	 cleardevice();
	 settextstyle(TRIPLEX_FONT , HORIZ_DIR,1);
	 outtextxy(100,30,"MADE BY- ");
	 settextstyle(TRIPLEX_FONT , HORIZ_DIR,1);
	 outtextxy(120,80,"  VRISHTI GAHLAUT");
	 delay(500);
	 settextstyle(TRIPLEX_FONT , HORIZ_DIR,2);
	 outtextxy(120,130,"    DHRUV SINGH");
	 delay(500);
	 settextstyle(TRIPLEX_FONT , HORIZ_DIR,3);
	 outtextxy(120,180,"      SUMIT BANSAL");
	 delay(500);
	 settextstyle(TRIPLEX_FONT , HORIZ_DIR,4);
	 outtextxy(140,230,"      HAMZA KHAN");
	 delay(2000);
	 exit(1);
	 break;
	 }
    default:
	     printf("\n\n");
	     printf("\033[31mInvalid choice\033[0m");
		 printf("\n");
	     break;
    }
}while(choice!=3);
  getch();
 closegraph();
  return 0;
}

