#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<bios.h>
#include<dos.h>                                                                                                                                                                                                                                     //                      //                      //                      //
int posx[77]={0,102,127,152,177,202,227,265,265,265,265,265,265,315,365,365,365,365,365,365,402,427,452,477,502,527,527,527,502,477,452,427,402,365,365,365,365,365,365,315,265,265,265,265,265,265,227,202,177,152,127,102,102,127,152,177,202,227,327,315,315,315,315,315,327,502,477,452,427,402,327,315,315,315,315,315,327};
int posy[77]={0,195,195,195,195,195,195,157,132,107,82,57,32,32,32,57,82,107,132,157,195,195,195,195,195,195,245,295,295,295,295,295,295,332,357,382,407,432,457,457,457,432,407,382,357,332,295,295,295,295,295,295,245,245,245,245,245,245,245,57,82,107,132,157,245,245,245,245,245,245,245,432,407,382,357,332,245};
int initposx[8]={130,205,130,205,425,500,425,500};                                                                                                                                                                                           //                    //                      //                      //
int initposy[8]={60,60,135,135,355,355,430,430};
int t=-1;
int cmsg;
char *msg,*tmsg;
void callput();
void clear();
void pmsg()
{       settextstyle(0,0,3);
	if(cmsg==1)
		setcolor(RED);
	else if(cmsg==2)
		setcolor(GREEN);
	else if(cmsg==3)
		setcolor(BLUE);
	else if(cmsg==4)
		setcolor(YELLOW);
	int i=0;
	tmsg=msg;
	while(*tmsg!='\0')
	{	outtextxy(600,(i*30)+10,tmsg++);
		i++;
	}
	settextstyle(0,0,0);
	setcolor(5);
}
int throwd()
{       setfillstyle(SOLID_FILL,5);
	int cd[]={0,1,89,1,89,600,0,600};
	while(1)
	{       setcolor(WHITE);
		int x=25+random(41);
		int y=185+random(206);
		int p[]={x-25,y,x,y-15,x+25,y,x,y+15};
		fillpoly(4,p);
		line(x-25,y,x-25,y+25);
		line(x,y+15,x,y+40);
		line(x+25,y,x+25,y+25);
		line(x-25,y+25,x,y+40);
		line(x,y+40,x+25,y+25);
		char n[1],nl[1],nr[1];
		int tn=x%8;
		if(tn+1==1)
		{	*n='1';
			*nl='2';
			*nr='4';
		}
		else if(tn+1==2)
		{	*n='2';
			*nl='3';
			*nr='6';
		}
		else if(tn+1==3)
		{	*n='3';
			*nl='1';
			*nr='5';
		}
		else if(tn+1==4)
		{	*n='4';
			*nl='2';
			*nr='6';
		}
		else if(tn+1==5)
		{	*n='5';
			*nl='1';
			*nr='4';
		}
		else if(tn+1>=6)
		{	*n='6';
			*nl='3';
			*nr='5';
		}
		*(n+1)='\0';
		*(nl+1)='\0';
		*(nr+1)='\0';
		outtextxy(x,y,n);
		outtextxy(x-13,y+20,nl);
		outtextxy(x+13,y+20,nr);
		if(bioskey(1))
		{	if(bioskey(0)==7181)
			{       delay(200);
				setcolor(5);
				return tn;
			}
		}
		delay(100);
		setfillstyle(SOLID_FILL,0);
		setcolor(0);
		fillpoly(4,cd);
	}
}
void draw()
{	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL,WHITE);
	int poly[]={90,20,540,20,540,470,90,470};
	fillpoly(4,poly);
	setfillstyle(SOLID_FILL,RED);
	int poly1[]={90,20,240,20,240,170,90,170};
	fillpoly(4,poly1);
	setfillstyle(SOLID_FILL,GREEN);
	int poly2[]={390,20,540,20,540,170,390,170};
	fillpoly(4,poly2);
	setfillstyle(SOLID_FILL,BLUE);
	int poly3[]={90,320,90,470,240,470,240,320};
	fillpoly(4,poly3);
	setfillstyle(SOLID_FILL,YELLOW);
	int poly4[]={390,320,540,320,540,470,390,470};
	fillpoly(4,poly4);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(315,245,20,20);
	setcolor(WHITE);
	outtextxy(300,243,"HOME");
	setcolor(BLACK);
	line(290,45,290,170);
	line(340,45,340,170);
	line(115,220,240,220);
	line(115,270,240,270);
	line(390,220,515,220);
	line(390,270,515,270);
	line(290,320,290,445);
	line(340,320,340,445);
	setfillstyle(SOLID_FILL,YELLOW);
	fillellipse(130,60,25,25);
	fillellipse(205,60,25,25);
	fillellipse(130,135,25,25);
	fillellipse(205,135,25,25);
	setfillstyle(SOLID_FILL,BLUE);
	fillellipse(425,60,25,25);
	fillellipse(500,60,25,25);
	fillellipse(425,135,25,25);
	fillellipse(500,135,25,25);
	setfillstyle(SOLID_FILL,RED);
	fillellipse(130,355,25,25);
	fillellipse(205,355,25,25);
	fillellipse(130,430,25,25);
	fillellipse(205,430,25,25);
	setfillstyle(SOLID_FILL,GREEN);
	fillellipse(425,355,25,25);
	fillellipse(500,355,25,25);
	fillellipse(425,430,25,25);
	fillellipse(500,430,25,25);
	setfillstyle(SOLID_FILL,GREEN);
	int polyg[]={290,45,340,45,340,170,290,170};
	fillpoly(4,polyg);
	int gs[]={465,170,490,170,490,220,465,220};
	fillpoly(4,gs);
	setfillstyle(SOLID_FILL,BLUE);
	int polyb[]={290,320,340,320,340,445,290,445};
	fillpoly(4,polyb);
	int bs[8]={140,270,165,270,165,320,140,320};
	fillpoly(4,bs);
	setfillstyle(SOLID_FILL,RED);
	int polyr[]={115,220,240,220,240,270,115,270};
	fillpoly(4,polyr);
	int rs[8]={240,70,290,70,290,95,240,95};
	fillpoly(4,rs);
	setfillstyle(SOLID_FILL,YELLOW);
	int polyy[]={390,220,515,220,515,270,390,270};
	fillpoly(4,polyy);
	int ys[]={340,395,390,395,390,420,340,420};
	fillpoly(4,ys);
	rectangle(240,170,390,320);
	line(240,170,390,320);
	line(390,170,240,320);
	line(290,20,290,170);
	line(340,20,340,170);
	line(290,345,290,470);
	line(340,345,340,470);
	line(90,220,240,220);
	line(90,270,240,270);
	line(390,220,540,220);
	line(390,270,540,270);
	setfillstyle(SOLID_FILL,0);
	setcolor(0);
	int bsi[8]={152,280,160,295,152,310,145,295};
	fillpoly(4,bsi);
	int gsi[]={477,180,485,195,477,210,470,195};
	fillpoly(4,gsi);
	int rsi[]={265,75,280,82,265,90,250,82};
	fillpoly(4,rsi);
	int ysi[]={365,400,380,407,365,415,350,407};
	fillpoly(4,ysi);
	settextstyle(0,1,0);
	setcolor(YELLOW);
	line(340,395,390,420);
	line(390,395,340,420);
	outtextxy(515,270,"START");
	int i=0;
	setcolor(0);
	for(i=45;i<=445;i=i+25)
	{       if(i==170)
			i=345;
		line(240,i,390,i);
	}
	for(i=115;i<=515;i=i+25)
	{       if(i==240)
			i=415;
		line(i,170,i,320);
	}
	setcolor(RED);
	line(240,70,290,95);
	line(290,70,240,95);
	outtextxy(125,170,"START");
	settextstyle(0,0,0);
	setcolor(BLUE);
	line(140,270,165,320);
	line(165,270,140,320);
	outtextxy(245,435,"START");
	setcolor(GREEN);
	line(465,170,490,220);
	line(490,170,465,220);
	outtextxy(348,48,"START");
	setcolor(0);
	rectangle(90,20,240,170);
	rectangle(390,20,540,170);
	rectangle(90,320,240,470);
	rectangle(390,320,540,470);
	setfillstyle(SOLID_FILL,5);
	setcolor(5);
}
void dice()
{       char n[1];
	int poly[]={30,430,70,430,70,470,30,470};
	setfillstyle(SOLID_FILL,5);
	fillpoly(4,poly);
	setcolor(0);
	if(t+1==1)
	 *n='1';
	else if(t+1==2)
	 *n='2';
	else if(t+1==3)
	 *n='3';
	else if(t+1==4)
	 *n='4';
	else if(t+1==5)
	 *n='5';
	else
	 *n='6';
	*(n+1)='\0';
	if(t>=0)
		outtextxy(48,447,n);
	else
		outtextxy(36,447,"LUDO");
	setcolor(5);
	*n=NULL;
}
class ludo
{       public:
		int nr[4];       //no.of rounds
		int init[4];     //strating or not 1-starting 0-not starting
		int d[4];        //direction 1-e 2-n 3-w 4-s
		int kill;           //killed or not 1-yes killed 0-not killed any
		int key;         //to select among 1 2 3 4
		int c;           //color r-1 g-2 b-3 y-4
		int nv;          //no. of values got
		int *v;          //values
		int bv[4];       //box values 1-52 for direction
		int h[4];        //home? 1-home 0-not home
		int sumv;        //sum of values
		int nomove[4];   //can't move  1-nomove 0-canmove
		int u[4];         //used? 1-used 0-not used
		int kc[4];	//kc increases for every dice point.key count
		ludo(int);
		int sum();
		void readv();
		int search(int);
		void yougot();
		void remove(int);
		int cantmove();
		void setmove();
		void initnomove();
		void move();
		void killr();        //checks killing chance for red
		void killg();
		void killb();
		void killy();
};
ludo r(1),g(2),b(3),y(4);
ludo::ludo(int col)
{    int gd=DETECT;
     initgraph(&gd,0,"");
     c=col;
     for(int i=0;i<4;i++)
     {  if(c==1)
	d[i]=4;
	else if(c==2)
	d[i]=1;
	else if(c==3)
	d[i]=3;
	else
	d[i]=2;
	kc[i]=0;
	nr[i]=0;
	init[i]=1;
	u[i]=0;
	bv[i]=0;
	h[i]=0;
	nomove[i]=0;
     }
     kill=0;
     key=1;
     nv=0;
     v=NULL;
     sumv=0;
}
int ludo::sum()
{       sumv=0;
	for(int i=0;i<nv;i++)
		sumv+=v[i];
	return sumv;
}
void ludo::readv()
{       if(c==1)
		msg="Turn for red";
	else if(c==2)
		msg="Turn for green";
	else if(c==3)
		msg="Turn for blue";
	else
		msg="Turn for yellow";
	clear();
	t=throwd();
	dice();
	while(t+1>=6||t+1==4)
	{       if(t+1==4)
			v[nv]=4;
		else
			v[nv]=6;
		nv++;
		yougot();
		outtextxy(1,1,"Press enter to roll the dice again.");
		getch();
		clear();
		t=throwd();
		clear();
	}
	v[nv]=t+1;
	nv++;
	setcolor(5);

   clear();
   yougot();
	setfillstyle(SOLID_FILL,5);
	setcolor(5);
}
int ludo::search(int k)
{       for(int i=0;i<nv;i++)
	{       if(v[i]==k)
			return 1;
	}
	return 0;
}
void ludo::yougot()
{	clear();
	if(nv>0)
	{      outtextxy(1,10,"You got:");
	       gotoxy(1,2);
	       for(int j=0;j<nv;j++)
			printf("\n%d ",v[j]);
	}
}
void ludo::remove(int k)
{       for(int i=0;i<nv;i++)
	{       if(v[i]==k)
		{       for(int j=i;j<nv-1;j++)
				v[j]=v[j+1];
			nv--;
			break;
		}
	}
}
int ludo::cantmove()
{       int c=0;
	for(int i=0;i<4;i++)
		if(nomove[i]==1)
			c++;
	if(c==4)
		return 1;
	else
		return 0;
}
void ludo::setmove()
{       for(int i=0;i<4;i++)
		nomove[i]=0;
}
void ludo::initnomove()
{       for(int i=0;i<=3;i++)
	{	if(init[i]==1)
		{	if(search(6))
				nomove[i]=0;
			else
				nomove[i]=1;
		}
		else if(h[i]==1)
			nomove[i]=1;
		else if(sum()>(58-kc[i]))
			nomove[i]=1;
		else if(h[i]==0)
			nomove[i]=0;
	}
}
void ludo::move()
{    printf("\nEnter which key to move:");
     key=getch()-48;
     if(key>=1&&key<=4)
     {  if(init[key-1]==1)
	{   if(search(6))
	    {	if(c==1)
		{	d[key-1]=3;
			bv[key-1]=2;
			kc[key-1]=2;
			r.killr();
		}
		else if(c==2)
		{	d[key-1]=4;
			bv[key-1]=15;
			kc[key-1]=2;
			g.killg();
		}
		else if(c==3)
		{	d[key-1]=2;
			bv[key-1]=41;
			kc[key-1]=2;
			b.killb();
		}
		else
		{	d[key-1]=1;
			bv[key-1]=28;
			kc[key-1]=2;
			y.killy();
		}
		init[key-1]=0;
		remove(6);
		yougot();
	    }
	    else
	    {	printf("You don't have dice point 6 to move your key.\n");
		nomove[key-1]=1;
	    }
	}
	else
	{       int k;
		printf("Enter any dice point you got:");
		k=getch()-48;
		while(1)
		{  if(search(k))
		   {    if(c==1&&kill==1)
			{       if(bv[key-1]<=52&&bv[key-1]+k>52&&bv[key-1]+k<=58)
				{       if(bv[key-1]+k==58)
						h[key-1]=1;
					bv[key-1]+=k;
					kc[key-1]+=k;
					remove(k);
					d[key-1]=3;
				}
				else if(bv[key-1]>=53)
				{	if(bv[key-1]+k<=58)
					{       if(bv[key-1]+k==58)
							h[key-1]=1;
						bv[key-1]+=k;
						kc[key-1]+=k;
						remove(k);
						d[key-1]=3;
					}
					else
					{	printf("Can't move this key.");
						nomove[key-1]=1;
					}
				}
				else if(bv[key-1]+k>52)
				{	bv[key-1]=bv[key-1]+k-52;
					if(kc[key-1]+k>52)
						kc[key-1]=kc[key-1]+k-52;
					else
						kc[key-1]+=k;
					remove(k);
				}
				else
				{	bv[key-1]+=k;
					if(kc[key-1]+k>52)
						kc[key-1]=kc[key-1]+k-52;
					else
						kc[key-1]+=k;
					remove(k);
				}
			}
			else if(c==2&&kill==1)
			{       if(bv[key-1]<=13&&bv[key-1]+k>13&&bv[key-1]+k<=19)
				{       if(bv[key-1]+k==19)
						h[key-1]=1;
					bv[key-1]+=(k+45);
					kc[key-1]+=k;
					remove(k);
					d[key-1]=4;
				}
				else if(bv[key-1]>=59)
				{	if(bv[key-1]+k<=64)
					{       if(bv[key-1]+k==64)
							h[key-1]=1;
						bv[key-1]+=k;
						kc[key-1]+=k;
						remove(k);
						d[key-1]=4;
					}
					else
					{	printf("Can't move this key.");
						nomove[key-1]=1;
					}
				}
				else if(bv[key-1]+k>52)
				{	bv[key-1]=bv[key-1]+k-52;
					if(kc[key-1]+k>52)
						kc[key-1]=kc[key-1]+k-52;
					else
						kc[key-1]+=k;
					remove(k);
				}
				else
				{	bv[key-1]+=k;
					if(kc[key-1]+k>52)
						kc[key-1]=kc[key-1]+k-52;
					else
						kc[key-1]+=k;
					remove(k);
				}
			}
			else if(c==3&&kill==1)
			{       if(bv[key-1]<=39&&bv[key-1]+k>39&&bv[key-1]+k<=45)
				{       if(bv[key-1]+k==45)
						h[key-1]=1;
					bv[key-1]+=(k+31);
					kc[key-1]+=k;
					remove(k);
					d[key-1]=2;
				}
				else if(bv[key-1]>=71)
				{	if(bv[key-1]+k<=76)
					{       if(bv[key-1]+k==76)
							h[key-1]=1;
						bv[key-1]+=k;
						kc[key-1]+=k;
						remove(k);
						d[key-1]=2;
					}
					else
					{	printf("Can't move this key.");
						nomove[key-1]=1;
					}
				}
				else if(bv[key-1]+k>52)
				{	bv[key-1]=bv[key-1]+k-52;
					if(kc[key-1]+k>52)
						kc[key-1]=kc[key-1]+k-52;
					else
						kc[key-1]+=k;
					remove(k);
				}
				else
				{	bv[key-1]+=k;
					if(kc[key-1]+k>52)
						kc[key-1]=kc[key-1]+k-52;
					else
						kc[key-1]+=k;
					remove(k);
				}
			}
			else if(c==4&&kill==1)
			{	if(bv[key-1]<=26&&bv[key-1]+k>26&&bv[key-1]+k<=32)
				{       if(bv[key-1]+k==32)
						h[key-1]=1;
					bv[key-1]+=(k+38);
					kc[key-1]+=k;
					remove(k);
					d[key-1]=1;
				}
				else if(bv[key-1]>=65)
				{	if(bv[key-1]+k<=70)
					{       if(bv[key-1]+k==70)
							h[key-1]=1;
						bv[key-1]+=k;
						kc[key-1]+=k;
						remove(k);
						d[key-1]=1;
					}
					else
					{	printf("Can't move this key.");
						nomove[key-1]=1;
					}
				}
				else if(bv[key-1]+k>52)
				{	bv[key-1]=bv[key-1]+k-52;
					if(kc[key-1]+k>52)
						kc[key-1]=kc[key-1]+k-52;
					else
						kc[key-1]+=k;
					remove(k);
				}
				else
				{	bv[key-1]+=k;
					if(kc[key-1]+k>52)
						kc[key-1]=kc[key-1]+k-52;
					else
						kc[key-1]+=k;
					remove(k);
				}
			}
			else if(bv[key-1]+k>52)
			{	bv[key-1]=bv[key-1]+k-52;
				if(kc[key-1]+k>52)
					kc[key-1]=kc[key-1]+k-52;
				else
					kc[key-1]+=k;
				remove(k);
			}
			else
			{	bv[key-1]+=k;
				if(kc[key-1]+k>52)
					kc[key-1]=kc[key-1]+k-52;
				else
					kc[key-1]+=k;
				remove(k);
			}
			if((bv[key-1]>=1&&bv[key-1]<=6)||(bv[key-1]>=12&&bv[key-1]<=13)||(bv[key-1]>=20&&bv[key-1]<=24))
				d[key-1]=3;
			else if((bv[key-1]>=27&&bv[key-1]<=32)||(bv[key-1]>=38&&bv[key-1]<=39)||(bv[key-1]>=46&&bv[key-1]<=50))
				d[key-1]=1;
			else if((bv[key-1]>=7&&bv[key-1]<=11)||(bv[key-1]>=40&&bv[key-1]<=45)||(bv[key-1]>=51&&bv[key-1]<=52))
				d[key-1]=2;
			else if((bv[key-1]>=14&&bv[key-1]<=19)||(bv[key-1]>=25&&bv[key-1]<=26)||(bv[key-1]>=33&&bv[key-1]<=37))
				d[key-1]=4;
			if(c==1)
			   r.killr();
			else if(c==2)
			   g.killg();
			else if(c==3)
			   b.killb();
			else
			   y.killy();
			clear();
			yougot();
			break;
		   }
		   else
		   {	printf("You don't have that point.\nEnter right point you have:");
			k=getch()-48;
		   }
		}
	}
     }
     else
       printf("You Entered wrong key.\n");
}
void ludo::killr()
{       int chsafe=bv[key-1]!=49&&bv[key-1]!=10&&bv[key-1]!=23&&bv[key-1]!=36;
	for(int i=0;i<4;i++)
	{   if(chsafe==1&&bv[key-1]==g.bv[i])
	    {   r.kill=1;
		g.bv[i]=0;
		g.kc[i]=0;
		g.init[i]=1;
		g.d[i]=1;
		r.yougot();
		outtextxy(1,1,"Press enter to roll the dice");
		getch();
		r.readv();
	    }
	    else if(chsafe==1&&bv[key-1]==b.bv[i])
	    {   r.kill=1;
		b.bv[i]=0;
		b.kc[i]=0;
		b.init[i]=1;
		b.d[i]=3;
		r.yougot();
		outtextxy(1,1,"Press enter to roll the dice");
		getch();
		r.readv();
	    }
	    else if(chsafe==1&&bv[key-1]==y.bv[i])
	    {   r.kill=1;
		y.bv[i]=0;
		y.kc[i]=0;
		y.init[i]=1;
		y.d[i]=2;
		r.yougot();
		outtextxy(1,1,"Press enter to roll the dice");
		getch();
		r.readv();
	    }
	}
}
void ludo::killg()
{       int chsafe=bv[key-1]!=49&&bv[key-1]!=10&&bv[key-1]!=23&&bv[key-1]!=36;
	for(int i=0;i<4;i++)
	{   if(chsafe==1&&bv[key-1]==r.bv[i])
	    {   g.kill=1;
		r.bv[i]=0;
		r.kc[i]=0;
		r.init[i]=1;
		r.d[i]=4;
		g.yougot();
		outtextxy(1,1,"Press enter to roll the dice");
		getch();
		g.readv();
	    }
	    else if(chsafe==1&&bv[key-1]==b.bv[i])
	    {   g.kill=1;
		b.bv[i]=0;
		b.kc[i]=0;
		b.init[i]=1;
		b.d[i]=3;
		g.yougot();
		outtextxy(1,1,"Press enter to roll the dice");
		getch();
		g.readv();
	    }
	    else if(chsafe==1&&bv[key-1]==y.bv[i])
	    {   g.kill=1;
		y.bv[i]=0;
		y.kc[i]=0;
		y.init[i]=1;
		y.d[i]=2;
		g.yougot();
		outtextxy(1,1,"Press enter to roll the dice");
		getch();
		g.readv();
	    }
	}
}
void ludo::killb()
{       int chsafe=bv[key-1]!=49&&bv[key-1]!=10&&bv[key-1]!=23&&bv[key-1]!=36;
	for(int i=0;i<4;i++)
	{   if(chsafe==1&&bv[key-1]==g.bv[i])
	    {   b.kill=1;
		g.bv[i]=0;
		g.kc[i]=0;
		g.init[i]=1;
		g.d[i]=1;
		b.yougot();
		outtextxy(1,1,"Press enter to roll the dice");
		getch();
		b.readv();
	    }
	    else if(chsafe==1&&bv[key-1]==r.bv[i])
	    {   b.kill=1;
		r.bv[i]=0;
		r.kc[i]=0;
		r.init[i]=1;
		r.d[i]=4;
		b.yougot();
		outtextxy(1,1,"Press enter to roll the dice");
		getch();
		b.readv();
	    }
	    else if(chsafe==1&&bv[key-1]==y.bv[i])
	    {   b.kill=1;
		y.bv[i]=0;
		y.kc[i]=0;
		y.init[i]=1;
		y.d[i]=2;
		b.yougot();
		outtextxy(1,1,"Press enter to roll the dice");
		getch();
		b.readv();
	    }
	}
}
void ludo::killy()
{       int chsafe=bv[key-1]!=49&&bv[key-1]!=10&&bv[key-1]!=23&&bv[key-1]!=36;
	for(int i=0;i<4;i++)
	 {   if(chsafe==1&&bv[key-1]==g.bv[i])
	     {   y.kill=1;
		 g.bv[i]=0;
		 g.kc[i]=0;
		 g.init[i]=1;
		 g.d[i]=1;
		 y.yougot();
		 outtextxy(1,1,"Press enter to roll the dice");
		 getch();
		 y.readv();
	     }
	     else if(chsafe==1&&bv[key-1]==b.bv[i])
	     {   y.kill=1;
		 b.bv[i]=0;
		 b.kc[i]=0;
		 b.init[i]=1;
		 b.d[i]=3;
		 y.yougot();
		 outtextxy(1,1,"Press enter to roll the dice");
		 getch();
		 y.readv();
	     }
	     else if(chsafe==1&&bv[key-1]==r.bv[i])
	     {   y.kill=1;
		 r.bv[i]=0;
		 r.kc[i]=0;
		 r.init[i]=1;
		 r.d[i]=4;
		 y.yougot();
		 outtextxy(1,1,"Press enter to roll the dice");
		 getch();
		 y.readv();
	     }
	 }
}
void put(int bv,int d,int c,int id)
{
	int x=posx[bv],y=posy[bv],i;
	if(c==1)
	{       if(bv==0)
		{	for(i=0;i<4;i++)
			{	if(i==id)
				{       x=initposx[i];
					y=initposy[i];
				}
			}
		}
		setfillstyle(SOLID_FILL,RED);
	}
	else if(c==2)
	{       if(bv==0)
		{	for(i=4;i<8;i++)
			{	if(i==id+4)
				{       x=initposx[i];
					y=initposy[i-4];
				}
			}
		}
		setfillstyle(SOLID_FILL,GREEN);
	}
	else if(c==3)
	{       if(bv==0)
		{	for(i=0;i<4;i++)
			{	if(i==id)
				{       x=initposx[i];
					y=initposy[i+4];
				}
			}
		}
		setfillstyle(SOLID_FILL,BLUE);
	}
	else
	{       if(bv==0)
		{	for(i=4;i<8;i++)
			{	if(i==id+4)
				{       x=initposx[i];
					y=initposy[i];
				}
			}
		}
		setfillstyle(SOLID_FILL,YELLOW);
	}
	setcolor(0);
	char ind[1];
	if(id==0)
		*ind='1';
	else if(id==1)
		*ind='2';
	else if(id==2)
		*ind='3';
	else
		*ind='4';
	*(ind+1)='\0';
	switch(d)
	{	case 1:	int poly1[8]={x-10,y,x+5,y-10,x,y,x+5,y+10};//1
			fillpoly(4,poly1);
			outtextxy(x+10,y,ind);
			break;
		case 2:	int poly2[8]={x-10,y+5,x,y-10,x+10,y+5,x,y};//2
			fillpoly(4,poly2);
			outtextxy(x,y+10,ind);
			break;
		case 3:	int poly3[8]={x-5,y-10,x+10,y,x-5,y+10,x,y};//3
			fillpoly(4,poly3);
			outtextxy(x-10,y,ind);
			break;
		case 4:	int poly4[8]={x-10,y-5,x,y,x+10,y-5,x,y+10};//4
			fillpoly(4,poly4);
			outtextxy(x,y-10,ind);
	}
	setfillstyle(SOLID_FILL,5);
	setcolor(5);
}
void callput()
{       for(int i=0;i<4;i++)
		put(r.bv[i],r.d[i],r.c,i);
	for(i=0;i<4;i++)
		put(g.bv[i],g.d[i],g.c,i);
	for(i=0;i<4;i++)
		put(b.bv[i],b.d[i],b.c,i);
	for(i=0;i<4;i++)
		put(y.bv[i],y.d[i],y.c,i);
}
int checkhome()
{       if(r.h[0]==1&&r.h[1]==1&&r.h[2]==1&&r.h[3]==1)
		return 1;
	else if(g.h[0]==1&&g.h[1]==1&&g.h[2]==1&&g.h[3]==1)
		return 2;
	else if(b.h[0]==1&&b.h[1]==1&&b.h[2]==1&&b.h[3]==1)
		return 3;
	else if(y.h[0]==1&&y.h[1]==1&&y.h[2]==1&&y.h[3]==1)
		return 4;
	return 0;
}
void rturn()
{       cmsg=1;
	msg="Turn for red";
	clear();
	outtextxy(1,1,"Press enter to roll the dice");
	getch();
	r.readv();
	while(r.nv>0)
	{       r.initnomove();
		if(r.bv[0]==0&&r.bv[1]==0&&r.bv[2]==0&&r.bv[3]==0&&!(r.search(6)))
		{	printf("\nBetter Luck next time.");
			break;
		}
		else if(r.cantmove())
		{	printf("Can't move any keys.");
			break;
		}
		else
			r.move();
		r.setmove();
	}
}
void gturn()
{       cmsg=2;
	msg="Turn for green";
	clear();
	outtextxy(1,1,"Press enter to roll the dice");
	getch();
	g.readv();
	while(g.nv>0)
	{       g.initnomove();
		if(g.bv[0]==0&&g.bv[1]==0&&g.bv[2]==0&&g.bv[3]==0&&!(g.search(6)))
		{	printf("\nBetter Luck next time.");
			break;
		}
		else if(g.cantmove())
		{	printf("Can't move any keys.");
			break;
		}
		else
			g.move();
		g.setmove();
	}
}
void bturn()
{       cmsg=3;
	msg="Turn for blue";
	clear();
	outtextxy(1,1,"Press enter to roll the dice");
	getch();
	b.readv();
	while(b.nv>0)
	{       b.initnomove();
		if(b.bv[0]==0&&b.bv[1]==0&&b.bv[2]==0&&b.bv[3]==0&&!(b.search(6)))
		{	printf("\nBetter Luck next time.");
			break;
		}
		else if(b.cantmove())
		{	printf("Can't move any keys.");
			break;
		}
		else
			b.move();
		b.setmove();
	}
}
void yturn()
{       cmsg=4;
	msg="Turn for yellow";
	clear();
	outtextxy(1,1,"Press enter to roll the dice");
	getch();
	y.readv();
	while(y.nv>0)
	{       y.initnomove();
		if(y.bv[0]==0&&y.bv[1]==0&&y.bv[2]==0&&y.bv[3]==0&&!(y.search(6)))
		{	printf("\nBetter Luck next time.");
			break;
		}
		else if(y.cantmove())
		{	printf("Can't move any keys.");
			break;
		}
		else
			y.move();
		y.setmove();
	}
}
void clear()
{       cleardevice();
	draw();
	callput();
	dice();
	pmsg();
	setcolor(5);
}
int stop()
{       printf("\nPress Esc to exit or 'p' to pause or Enter to continue:");
	int sp=bioskey(0);
	if(sp==283)
		return 1;
	else if(sp==6512)
		return 2;
	else
		return 0;
}
void scp()
{       int sp=stop();
	if(sp==1)
		exit(0);
	else if(sp==2)
		while(1)
		{	outtextxy(1,1,"Game is paused to play press 'p'.");
			if(getch()=='p')
				break;
		}
}
void main()
{       setbkcolor(9);
	setcolor(5);
	settextstyle(4,0,9);
	int i;
	delay(500);
	for(i=0;i<=180;i+=20)
	{
		outtextxy(i,180,"L");
		delay(50);
		cleardevice();
	}
	outtextxy(180,180,"L");
	for(i=0;i<=180;i+=20)
	{       outtextxy(180,180,"L");
		outtextxy(240,i,"U");
		delay(50);
		cleardevice();
	}
	outtextxy(180,180,"L");
	outtextxy(240,180,"U");
	for(i=480;i>=180;i-=40)
	{       outtextxy(180,180,"L");
		outtextxy(240,180,"U");
		outtextxy(305,i,"D");
		delay(50);
		cleardevice();
	}
	outtextxy(180,180,"L");
	outtextxy(240,180,"U");
	outtextxy(305,180,"D");
	for(i=640;i>=370;i-=40)
	{       outtextxy(180,180,"L");
		outtextxy(240,180,"U");
		outtextxy(305,180,"D");
		outtextxy(i,180,"O");
		delay(50);
		cleardevice();
	}
	outtextxy(180,180,"L");
	outtextxy(240,180,"U");
	outtextxy(305,180,"D");
	outtextxy(370,180,"O");
	delay(500);
	settextstyle(0,0,0);
	setcolor(12);
	int menu;
	setbkcolor(0);
	while(1)
	{       cleardevice();
		gotoxy(1,1);
		printf("*******MENU*******\n1.ABOUT\n2.INSTRUCTIONS\n3.PLAYERS\n4.DEVELOPERS\n5.START\n6.EXIT\nEnter Your choice:[ ]\b\b");
		menu=getch()-48;
		if(menu==6)
			exit(0);
		if(menu==5)
			break;
		if(menu>5||menu<1)
		{	printf("Enter right choice.");
			delay(500);
		}
		else
		{       cleardevice();
			gotoxy(1,1);
			switch(menu)
			{
				case 1: printf("\t\t\t\tABOUT\n\nThere can be 2 or 4 players.\nFor 2 players opposite colors should be selected.\nEach key can go to start position only when you have a dice point 6.\nNow the keys can go for a round where it should kill other player toy inorder   to reach its Home.\nIf a round is completed without killing other player toy atleast once should go for another round.\nIf one get a dice point 6 or 4 or kills other player toy will get another chanceto roll the dice.\nA player will win the game if all his/her keys reach their Home first.\n\nPress Enter to skip this menu.");
					getch();
					break;
				case 2: printf("\t\t\t\tINSTRUCTIONS\n\nPress Enter to roll the dice.\nPress Enter to stop rolling the dice.\nEnter which key out of 1/2/3/4 to move.\nEnter the dice point [you got] to be moved.\nKill other player toy to reach the Home.\n\nPress Enter to skip This Menu.");
					getch();
					break;
				case 3: printf("\t\t\t\tPLAYERS\n\nThere can be 2 or 4 players.\nFor 2 players opposite colors should be selected.\nLike Red and Yellow or Green and Blue.\n\nPress Enter to skip this menu.");
					getch();
					break;
				case 4: printf("\t\t\t\tDEVELOPERS\n\nCSE\nII year\n\nN.Anusha\nB.smitha\nN.deepika\nK.pavaniswarupa\nM.sunithasowjanya\n\nPress Enter to skip this menu.");
					getch();
					break;
			}
		}
	}
	cleardevice();
	setfillstyle(SOLID_FILL,RED);
	setbkcolor(BLACK);
	setcolor(5);
	int chhome,rp=0,gp=0,bp=0,yp=0,np,pc,selected=0;
	gotoxy(1,1);
	printf("Number of players:\n1.Two players.\n2.Four players.\n0.To quit.");
	while(1)
	{
		printf("\nEnter your choice:");
		np=getch()-48;
		switch(np)
		{       case 0: return;
			case 1: printf("\nEnter 1 to select Red and Yellow other to select Green and Blue:");
				pc=getch()-48;
				if(pc==1)
					rp=yp=1;
				else
					gp=bp=1;
				selected=1;
				break;
			case 2: rp=gp=bp=yp=1;
				selected=1;
				break;
			default: printf("\nEnter right number of players.");
		}
		if(selected)
			break;
	}
	clear();
	chhome=checkhome();
	while(chhome==0)
	{       if(rp)
		{
		     rturn();
		     scp();
		}
		if(checkhome())
			break;
		if(gp)
		{       clear();
			gturn();
			scp();
		}
		if(checkhome())
			break;
		if(yp)
		{       clear();
			yturn();
			scp();
		}
		if(checkhome())
			break;
		if(bp)
		{       clear();
			bturn();
			if(stop())
			      exit(0);
		}
		clear();
		r.v=g.v=b.v=y.v=NULL;
		r.nv=g.nv=b.nv=y.nv=0;
		chhome=checkhome();
	}
	if(chhome==1)
		printf("Red player won the game.");
	else if(chhome==2)
		printf("Green player won the game.");
	else if(chhome==3)
		printf("Blue player won the game.");
	else if(chhome==4)
		printf("Yellow player won the game.");
	getch();
}