
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>


void rain(int);

int round(float x)
{
	int r;
	r=x+0.5;
	return r;
}

class pix1
{
public:
	 void drawpt(int x,int y,int color)
	 {
		putpixel(x,y,color);
	 }
};

class line1:public pix1
{
public:
	void drawline(int xa,int ya,int xb,int yb,int color)
	{

		float dx,dy,x,y;
		float xinc,yinc,step;

		dx = xb-xa;
		dy = yb-ya;
		drawpt(xa,ya,color);
		if(abs(dx) >= abs(dy))
		{
			step=abs(dx);
		}
		else
		{
			step=abs(dy);
		}

		 xinc = dx/step;
		 yinc = dy/step;
		 x = xa;
		 y = ya;


		 for(int i=0;i<step;i++)
		 {
			x = x+xinc;
			y = y+yinc;
			drawpt(round(x),round(y),color);
		 }
	}
};

class Pix
{
protected:
	int xc,yc,r;
public:

	void drawpoint(int x, int y,int xc,int yc)
	{
		putpixel((xc+x),(yc+y),10);
		putpixel((xc+x),(yc-y),10);
		putpixel((xc-x),(yc-y),10);
		putpixel((xc-x),(yc+y),10);
		putpixel((xc+y),(yc+x),10);
		putpixel((xc+y),(yc-x),10);
		putpixel((xc-y),(yc-x),10);
		putpixel((xc-y),(yc+x),10);

	}
};

class BRES_CIRCLE: public Pix
{
public:

	  void draw(int xc,int yc)
	  {
	int pk;

	r=30;

	pk = 3 - 2 * r;

	int x = 0;
	int y = r;

	drawpoint(x,y,xc,yc);
	while(x <= y)
	{
		if(pk < 0)
		{
			pk = pk + 4 * x + 6;
			x = x + 1;
		}
		else
		{
			pk = pk + 4*x - 4*y + 10;
			x = x + 1;
			y = y - 1;
		}
		drawpoint(x,y,xc,yc);
	}
	  }


};
void ffill(int x, int y,int old,int fill)
{
		int current;
		current = getpixel(x,y);
		if(current == old)
		{
			putpixel(x,y,fill);
			ffill(x+1,y,old,fill);
			ffill(x-1,y,old,fill);
			ffill(x,y+1,old,fill);
			ffill(x,y-1,old,fill);

		}
}


void drawTrees()
{
	BRES_CIRCLE circle;
	line1 line;
	int j=200;
	for(int i=50;i<640;i=i+100)
	{
	circle.draw(i,j);
	ffill(i-1,j-1,0,2);
	line.drawline(i-10,j,i+10,j,15);
	line.drawline(i-10,j,i-10,j+100,15);
	line.drawline(i+10,j,i+10,j+100,15);
	line.drawline(i-10,j+100,i+10,j+100,15);
	ffill(i,j+50,0,6);
	ffill(i,j,15,2);

	}
	j=100;
	for(i=100;i<640;i=i+100)
	{
	circle.draw(i,j);
	ffill(i-1,j-1,0,2);
	line.drawline(i-10,j,i+10,j,15);
	line.drawline(i-10,j,i-10,j+100,15);
	line.drawline(i+10,j,i+10,j+100,15);
	line.drawline(i-10,j+100,i+10,j+100,15);
	ffill(i,j+50,0,6);
	ffill(i,j,15,2);

	}
	settextstyle(3,0,4);
	outtextxy(50,350,"Once there was a jungle full of trees...");

	delay(2000);

	rain(25);
	outtextxy(50,400,"And it rained heavily...");
}

void drawLessTrees()
{
	BRES_CIRCLE circle;
	line1 line;

	int j=200;
	for(int i=50;i<240;i=i+100)
	{
	circle.draw(i,j);
	ffill(i-1,j-1,0,2);
	line.drawline(i-10,j,i+10,j,15);
	line.drawline(i-10,j,i-10,j+100,15);
	line.drawline(i+10,j,i+10,j+100,15);
	line.drawline(i-10,j+100,i+10,j+100,15);
	ffill(i,j+50,0,6);
	ffill(i,j,15,2);

	}
	j=100;
	for(i=100;i<240;i=i+100)
	{
	circle.draw(i,j);
	ffill(i-1,j-1,0,2);
	line.drawline(i-10,j,i+10,j,15);
	line.drawline(i-10,j,i-10,j+100,15);
	line.drawline(i+10,j,i+10,j+100,15);
	line.drawline(i-10,j+100,i+10,j+100,15);
	ffill(i,j+50,0,6);
	ffill(i,j,15,2);

	}
	settextstyle(3,0,4);
	outtextxy(20,350,"Then there came concrete jungle...");
	outtextxy(50,400,"\t and the rain reduced.....");
}

void drawBuildings()
{
	line1 line;


	//first building
	for(int i = 250;i<640;i=i+280)
	{
		line.drawline(i,100,i+100,100,15);
		line.drawline(i,100,i,300,15);
		line.drawline(i+100,100,i+100,300,15);
		line.drawline(i,300,i+100,300,15);

		int y = 120;
		while(y < 300)
		{
			line.drawline(i+20,y,i+40,y,15);
			line.drawline(i+20,y,i+20,y+20,15);
			line.drawline(i+20,y+20,i+40,y+20,15);
			line.drawline(i+40,y,i+40,y+20,15);

			line.drawline(i+60,y,i+80,y,15);
			line.drawline(i+60,y,i+60,y+20,15);
			line.drawline(i+60,y+20,i+80,y+20,15);
			line.drawline(i+80,y,i+80,y+20,15);

			y = y + 60;
	   }
	  setfillstyle(SOLID_FILL,5);
	  floodfill(i+1,101,15);
	  //setcolor(15);
	}

	i=400;
	//middle building
	line.drawline(i,200,i+100,200,15);
	line.drawline(i,200,i,300,15);
	line.drawline(i+100,200,i+100,300,15);
	line.drawline(i,300,i+100,300,15);

		int y = 220;
			line.drawline(i+20,y,i+40,y,15);
			line.drawline(i+20,y,i+20,y+20,15);
			line.drawline(i+20,y+20,i+40,y+20,15);
			line.drawline(i+40,y,i+40,y+20,15);

			line.drawline(i+60,y,i+80,y,15);
			line.drawline(i+60,y,i+60,y+20,15);
			line.drawline(i+60,y+20,i+80,y+20,15);
			line.drawline(i+80,y,i+80,y+20,15);


			y = y + 50;

			line.drawline(i+40,y,i+60,y,15);
			line.drawline(i+40,y,i+40,300,15);
			line.drawline(i+40,300,i+60,300,15);
			line.drawline(i+60,y,i+60,300,15);

			setfillstyle(SOLID_FILL,14);
			floodfill(i+1,221,15);
		delay(2000);
		rain(50);


}


void drawMoreBuildings()
{
	line1 line;

	//first building
	for(int i = 20;i<640;i=i+300)
	{
		line.drawline(i,100,i+100,100,15);
		line.drawline(i,100,i,300,15);
		line.drawline(i+100,100,i+100,300,15);
		line.drawline(i,300,i+100,300,15);

		int y = 120;
		while(y < 300)
		{
			line.drawline(i+20,y,i+40,y,15);
			line.drawline(i+20,y,i+20,y+20,15);
			line.drawline(i+20,y+20,i+40,y+20,15);
			line.drawline(i+40,y,i+40,y+20,15);

			line.drawline(i+60,y,i+80,y,15);
			line.drawline(i+60,y,i+60,y+20,15);
			line.drawline(i+60,y+20,i+80,y+20,15);
			line.drawline(i+80,y,i+80,y+20,15);

			y = y + 60;
	   }
	   int color=2;
	  setfillstyle(SOLID_FILL,color);
	  floodfill(i+1,101,15);
	  color++;
	  //setcolor(15);
	}

	i=170;
	//middle building
	for(;i<640;i=i+300)
	{
	line.drawline(i,200,i+100,200,15);
	line.drawline(i,200,i,300,15);
	line.drawline(i+100,200,i+100,300,15);
	line.drawline(i,300,i+100,300,15);

		int y = 220;

			line.drawline(i+20,y,i+40,y,15);
			line.drawline(i+20,y,i+20,y+20,15);
			line.drawline(i+20,y+20,i+40,y+20,15);
			line.drawline(i+40,y,i+40,y+20,15);

			line.drawline(i+60,y,i+80,y,15);
			line.drawline(i+60,y,i+60,y+20,15);
			line.drawline(i+60,y+20,i+80,y+20,15);
			line.drawline(i+80,y,i+80,y+20,15);


			y = y + 50;

			line.drawline(i+40,y,i+60,y,15);
			line.drawline(i+40,y,i+40,300,15);
			line.drawline(i+40,300,i+60,300,15);
			line.drawline(i+60,y,i+60,300,15);

		 int color= 5;

			setfillstyle(SOLID_FILL,color);
			floodfill(i+1,221,15);
			color++;
	}

	settextstyle(3,0,4);
	outtextxy(30,350,"In future the only greenary left");
	outtextxy(50,400,"will be the color of buildings...");

	delay(2000);
	rain(90);
}

void putText()
{
	settextstyle(3,0,4);
	outtextxy(100,100,"Let me tell you");
	outtextxy(100,200," \t a story today.....");
}

void putEndText()
{
	settextstyle(3,0,4);
	outtextxy(100,100,"Do you want this to happen??");
	outtextxy(100,200," Time to ACT and THINK..");
	settextstyle(3,0,4);
	outtextxy(100,300,"GROW TREES , SAVE WATER");
	outtextxy(150,350,"     SAVE LIFE");
}

void rain(int gap)
{
	line1 line;
	for(int g=0;g<400;g++)
	{
		for(int k=0;k<100;k++)
		{
			line.drawline(5+k*gap,0+g*gap,0+k*gap,8+g*gap,1);
		}
	}
}

void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

	putText();
	delay(5000);

	cleardevice();
	drawTrees();
	delay(5000);

	cleardevice();
	drawLessTrees();
	drawBuildings();
	delay(5000);

	cleardevice();
	drawMoreBuildings();
	delay(5000);

	cleardevice();
	putEndText();

	getch();
	closegraph();
}
