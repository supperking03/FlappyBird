#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int check(int L1, int T1, int R1, int B1, int L2, int T2, int R2, int B2)
{
	
	float check_w, check_h;
	if (L2 > L1){
		check_w = R1 - L1;
	}
	else{
		check_w = R2 - L2;
	}
	if (T2 > T1){
		check_h = B1 - T1;
	}
	else{
		check_h = B2 - T2;
	}
	if ((abs(L2 - L1) < check_w) && (abs(T2 - T1) < check_h))
	{
		return 1;
	}
	return 0;
}
void drawcolum(int x,int y)
{ 
	bar(x, 0, x + 20, y);
	bar(x, y+ 150, x + 20, 500);
}
void drawbrid(int x, int y)
{
	rectangle(x - 60, y - 25, x - 20, y + 25);
	circle(x-10, y, 10);
	circle(x -7, y - 3, 3);
	line(x-2 , y - 3, x-2 , y + 5);
	line(x-2 , y - 3, x + 6, y + 5);
	line(x-2 , y + 5, x + 6, y + 5);

	line(x-30,y-10,x-30,y+10);
	line(x - 30, y - 10, x - 50, y + 10);
	line(x - 30, y + 10, x - 50, y + 10);

}
int main()
{

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	int diem = 0;
	char a[5] = { 0 };
	int cl = 600;
	int y = 50;
	



	int cl2 = 900;
	int y2 = 150;
	srand(time(NULL));
	
	for (int i = 0; i <= 100000; i+=5)
	{
		
		outtextxy(25, 25, "SCORE:");
		outtextxy(80, 25, a);
		if (cl == 140)
		{
			diem++;
			sprintf_s(a, "%d", diem);
		}
		if (cl2 == 140)
		{
			diem++;
			sprintf_s(a, "%d", diem);
		}
		if (cl == 0)
		{
			y = rand() % 300 + 50;
			cl = 600;
		}
		
		if (cl2 == 0)
		{
			y2 = rand() % 300 + 50;
			cl2 = 600;
		}
		drawcolum(cl,y);
		drawcolum(cl2, y2);
		cl2 -= 5;
		cl-=5;
		drawbrid(200, i);
		if (kbhit())
		{
			char c = getch();
			if (c == 'w')
			{
				i-=60;
			}

		}
		if ((check(cl, 0, cl + 20, y, 200 - 60, i - 25, 200 - 20, i + 25) == 1) || (check(cl, y + 150, cl + 20, 500, 200 - 60, i - 25, 200 - 20, i + 25) == 1) || (check(cl2, 0, cl2 + 20, y2, 200 - 60, i - 25, 200 - 20, i + 25) == 1) || (check(cl2, y2 + 150, cl2 + 20, 500, 200 - 60, i - 25, 200 - 20, i + 25) == 1))
		{
			break;
		}
		Sleep(20);
		cleardevice();
	}
	for (int i = 0; i <= 1000; i+=2)
	{
		setcolor(YELLOW);
		outtextxy(230, 500 - i, "FLAPPY BIRD CONSOLE WIN32");
		setcolor(GREEN);
		outtextxy(210, 550 - i, "----> MADE BY MiKiNo - UIT K10 <----");
		if (i == 300)
		{
			Sleep(5000);
			break;
		}
		Sleep(20);
		cleardevice();
	}
	closegraph(-2);
	system("pause");
	return 0;
}