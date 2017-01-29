#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<graphics.h>
#include<conio.h>

void loading()
{
 int a,b,i,c,d;
 setbkcolor(9);
   settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
   moveto(getmaxx()/2-50,getmaxy()/2+30);
   outtext("LOADING");

   a=getmaxx()/2-70;
   b=getmaxy()/2+60;
   for(i=0;i<7;i++)
   {
     setfillstyle(SOLID_FILL,getmaxcolor());
     bar(a,b,a+15,b+8);
 //  circle(a+40,b-60,2);
   delay(200);
   a=a+23;
   }

}
void path()
{
int i;
for(i=0;i<getmaxx();i++)
{
     rectangle(i,150,i+10,151);
     i=i+11;
}
}

void action1(int x,int y)
{
cleardevice();
circle(x,y,10);
line(x,y+10,x,y+30);
line(x,y+30,x-10,y+50);
line(x,y+30,x+10,y+50);
line(x,y+20,x-10,y+25);
line(x,y+20,x+10,y+25);
}

void action2(int x,int y)
{
cleardevice();
circle(x,y,10);
line(x,y+10,x,y+30);
line(x,y+30,x-2,y+50);
line(x,y+30,x+5,y+50);
line(x,y+20,x+5,y+15);
line(x,y+20,x+5,y+25);
}

void action3(int x,int y)
{
cleardevice();
circle(x,y,10);
line(x,y+10,x,y+30);
line(x,y+30,x+2,y+50);
line(x,y+30,x-5,y+50);
line(x,y+20,x-10,y+15);
line(x,y+20,x+10,y+25);
}
void action4(int x,int y)
{
cleardevice();
circle(x,y,10);
line(x,y+10,x,y+30);
line(x,y+30,x-10,y+50);
line(x,y+30,x+10,y+50);
line(x,y+20,x-10,y+25);
line(x,y+20,x+10,y+25);
}
void obstacle(int x,int y)
{
     setfillstyle(SOLID_FILL,1);
     bar(495,150,505,120);
//rectangle(495,150,505,120);
if((x>=500&&x<=510))
{
printf("GAME OVER\n");
path();
delay(1000);
exit(0);
}
}


int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\tURBOC3\\bgi");

int k,x=50,y=100,i=0;
char c;
loading();
cleardevice();
setbkcolor(2);
path();
obstacle(x+i,y);

do{
c=getch();
action1(x+i,y);
obstacle(x+i,y);
path();
delay(125);
if(c=='d')
{
action2(x+i+5,y);
obstacle(x+i+10,y);
path();
i=i+20;
}
else if(c=='a')
{
action3(x+i-5,y);
obstacle(x+i-5,y);
path();
i=i-20;
}
else if(c=='w')
{
i=i+30;
action1(x+i,y-55);

delay(100);
i=i+20;
action1(x+i,y);
obstacle(x+i,y);
path();
}

delay(125);

}while(c!='q');


getch();
return 0;
}