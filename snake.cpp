#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x,y;
int fruitx,fruity;
int tailx[100],taily[100];
int score,nTail;
enum eDirection 
{
	STOP = 0, LEFT, RIGHT, UP, DOWN	
};
eDirection dir;


void setUp()
{
	gameOver = false;
	dir = STOP;	
	x=width/2;
	y=height/2;
	fruitx = rand() % width;
	fruity = rand() % height;
	score=0;
}
void draw()
{
	system("cls");
	int i,j,k;
	
	for(i=0;i<width+2;i++)
	cout<<"#";
	cout<<endl;
	
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			if(j==0)
			cout<<"#";
			if(i == y && j == x)
			cout<<"O"; 
			else if(i == fruity && j == fruitx)
			cout<<"*";
			else
			{
				bool print = false;
				for(k=0;k<nTail;k++)
				{
					if(tailx[k] == j && taily[k] == i)
					{
						cout<<"o";
						print = true;
					}
				}
				if(!print)
				cout<<" ";
			}
			
			if(j==width-1)
			cout<<"#";
		}
		cout<<endl;
	}
	
	for(i=0;i<width+2;i++)
	cout<<"#";
	cout<<endl;
	cout<<"score = "<<score<<endl;
}
void input()
{
	if(_kbhit())
	{
	   switch(_getch())
	   {
	   	  case 'a':
	   	  	dir = LEFT;
	   	  	break;
	   	  case 'd':
			dir = RIGHT;
			break;
		  case 's':
		  	dir = DOWN;
		  	break;
		  case 'w':
		  	dir = UP;
			break;
		  case 'x':
		  gameOver=true;
		  break;		 	
	   }
	}
}
void logic()
{
	int prevx = tailx[0];
	int prevy = taily[0];
	int i,prev2x,prev2y;
	tailx[0] = x;
	taily[0] = y;
	for(i=1;i<nTail;i++)
	{
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y; 
	}
	switch(dir)
	{
		case LEFT:
		  x--;
		  break;
		case RIGHT:
			x++;
		  break;
		case UP:
			y--;
		  break;
		case DOWN:
			y++;
		  break;
		default:
		  break;  	
	}
	if(x>width || x<0 || y>height-1 || y<0)
	gameOver = true;	
	/*
	if(x>=width)
	x=0;
	else if(x<0)
	x=width-1;
	
	if(y>=height)
	y=0;
	else if(y<0)
	y=height-1;
	*/
	for(i=0;i<nTail;i++)
	   if(tailx[i] == x && taily[i] == y)
	      gameOver = true;
	
	if(x==fruitx&&y==fruity)
	{
		nTail++;
		score++;
		fruitx = rand() % width;
		fruity = rand() % height;   
	}
	
}
int main()
{
	setUp();
	while(!gameOver)
	{
		draw();
		input();
		logic();
		Sleep(30);
	}
	return 0;
}
