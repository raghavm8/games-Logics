#include<iostream>
using namespace std;
char back[30][60];
void setboundary()
{
	int i;
	for(i=0;i<60;i++)
	{
		back[i][20] = '*';
		back[i][40] = '*';
		back[10][i] = '*';
		back[20][i] = '*';
	}
}
void print()
{
	int i,j;
	system("cls");
	for(i=0;i<30;i++)
	{
		for(j=0;j<60;j++)
		{
			cout<<back[i][j];
		}
		cout<<"\n";
    }
}
	 void setInput(int position, char x)
	 {
	 	if(position == 1)
			back[25][10] = x;
		if(position == 2)
			back[25][30] = x;
		if(position == 3)
			back[25][50] = x;
		if(position == 4)
			back[15][10] = x;
		if(position == 5)
			back[15][30] = x;
		if(position == 6)
			back[15][50] = x;
		if(position == 7)
			back[5][10] = x;
		if(position == 8)
			back[5][30] = x;
		if(position == 9)
			back[5][50] = x;
	 }
	bool check(char a)
	{
		if(back[25][10] == a)
		{
			if(back[25][10] == back[25][30] && back[25][10] == back[25][50])
			return true;
			if(back[25][10] == back[15][10] && back[25][10] == back[5][10])
			return true;
			if(back[25][10] == back[15][30] && back[25][10] == back[5][50])
			return true;
		}
		if(back[25][30] == a)
		{
			if(back[25][30] == back[25][10] && back[25][30] == back[25][50])
			return true;
			if(back[25][30] == back[15][30] && back[25][30] == back[5][30])
			return true;
		}
		if(back[25][50] == a)
		{
			if(back[25][50] == back[25][30] && back[25][50] == back[25][10])
			return true;
			if(back[25][50] == back[15][30] && back[25][50] == back[5][10])
			return true;
			if(back[25][50] == back[15][50] && back[25][50] == back[5][50])
			return true;
		}
		 if(back[15][10] == a)
		 {
		 	if(back[15][10] == back[15][30] && back[15][10] == back[15][50])
		 	return true;
		 	if(back[15][10] == back[25][10] && back[15][10] == back[5][10])
		 	return true;
		 }
		  if(back[15][30] == a)
		 {
		 	if(back[15][30] == back[15][10] && back[15][30] == back[15][50])
		 	return true;
		 	if(back[15][30] == back[25][30] && back[15][30] == back[5][30])
		 	return true;
		 }
		 if(back[15][50] == a)
		 {
		 	if(back[15][50] == back[25][30] && back[15][50] == back[5][50])
		 	return true;
		 	if(back[15][50] == back[15][30] && back[15][50] == back[15][10])
		 	return true;
		 }
	}
int main()
{
	setboundary();
	print();
	int i=0,position;
	cout<<"enter the number to choose a location for you character";
	cout<<"\n Player 1 has to play with X ";
	cout<<"\n Player 2 has to play with 0 ";
	
while(i<9)
{
	   if(i%2==0)
	   {
	       cout<<"player 1 turn\nenter position for player 1\n";
	       cin>>position;
	   }
	   else
	   {
	       cout<<"player 2 turn\nenter position for player 2\n";
	       cin>>position;
	   }


	   if(i%2==0)
	   {
	   	setInput(position,'X');
		print();
		if(check('X'))  {
		cout<<"player one is winner";
		break;
	  }
	   }
	   else
	   {
	   	setInput(position,'0');
	   	print();
	   	if(check('0')){
	   	cout<<"player 2 is winner";
	break;
	}
	   }
	i++;
	cout<<"                   Game Ends";
			}
}
