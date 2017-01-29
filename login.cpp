#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

class login
{
int i,i1,j1,xtra;
char ch1,p1[20],u1[20],pd1[20]="oops",user[20]="project";
public:

login()
{
 do{
for(il=20;il<=62;il++)
	{
		 gotoxy(il,8);
		 printf("%c",196);
		 delay(10);

	}
	for(jl=9;jl<=18;jl++)
	{
		 gotoxy(62,jl);
		 printf("%c",179);
		 delay(10);

	}
	for(il=62;il>=20;il--)
	{
		 gotoxy(il,19);
		 printf("%c",196);
		 delay(10);

	}
	for(jl=18;jl>=9;jl--)
	{
		 gotoxy(20,jl);
		 printf("%c",179);
		 delay(10);

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

      if(strcmp(pdl,pl)!=0||strcmp(user,u1)!=0)
      {
	gotoxy(25,15);
	xtra=1;
	printf("\033[31m USER NAME OR PASSWORD INCORRECT...\033[0m");
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


gotoxy(5,5);
printf("\n\t\t        Process the System files......");

for(i=1;i<=80;i++)
{
delay(100);
gotoxy(5,23);
printf(" Completed... %f %",i*1.25);
gotoxy(i,9);
textbackground(WHITE);
textcolor(WHITE);
cprintf("\n\n ",65);
}



};


int main()
{
login log;
return 0;
}