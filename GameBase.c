#include<stdio.h>
#include <time.h>
#include <windows.h>
//code by ram170
//Thanks for checking out
//int size;
//int seq[100];
//int t;
//int r,c;
//int move=0;
void rand_seq(int i,int seq[100])
{
	int j;
	srand(time(0));
	for(j=0;j<i;j++)
	{
		int x;
		x=rand();
		seq[j]=x%4;
	}
}
void random(int arr3[100][100],int size,int seq[100],int r,int c)
{
	int i;
	//printf("%d%d",*r,*c);
	for(i=0;i<100;i++)
	{
		if(seq[i]==0)
		{
			swapleft(arr3,size,r,c);
		}
		else if(seq[i]==1)
		{
			swapright(arr3,size,r,c);
		}
		else if(seq[i]==2)
		{
			swapup(arr3,size,r,c);
		}
		else
		{
			swapdown(arr3,size,r,c);
		}
	}
	printf("DOne");
}
int swapleft(int arr[100][100],int size,int *r,int *c)
{
	int t;
//	printf("%d%d",*r,*c);
	if(*c-1>=0)
	{
	   t=arr[*r][*c];
	   arr[*r][*c]=arr[*r][*c-1];
	   arr[*r][*c-1]=t;
	   *c=*c-1;
	   return 0;
	}
	else return 1;
}
int swapright(int arr[100][100],int size,int *r,int *c)
{
	int t;
	if(*c+1<size)
	{
	   t=arr[*r][*c];
	   arr[*r][*c]=arr[*r][*c+1];
	   arr[*r][*c+1]=t;
	   *c=*c+1;
	   return 0;
	}
	else return 1;
}
int swapup(int arr[100][100],int size,int *r,int *c)
{
	int t;
	if(*r-1>=0)
	{
	   t=arr[*r][*c];
	   arr[*r][*c]=arr[*r-1][*c];
	   arr[*r-1][*c]=t;
	   *r=*r-1;
	   return 0;
	}
	else return 1;
}
int swapdown(int arr[100][100],int size,int *r,int *c)
{
	int t;
	if(*r+1<size)
	{
	   t=arr[*r][*c];
	   arr[*r][*c]=arr[*r+1][*c];
	   arr[*r+1][*c]=t;
	   *r=*r+1;
	   return 0;
	}
	else return 1;
}
void line(int r,int c,int size)
{
	int i,count;
	count=(4*size)+1;
	for(i=0;i<count;i++)
	{
		if(r==0 && c==0)
		{
			printf("%c",218);
			c+=1;
		}
		else if(r==0 && c==count-1)
		{
			printf("%c",191);
		}
		else if(r==size-1 && c==0)
		{
			printf("%c",192);
			c+=1;
		}
		else if(r==size-1 && c==count-1)
		{
			printf("%c",217);
		}
		else
		{
			printf("-");
			c+=1;
		}
	}
	printf("\n");
}


void display(int arr[100][100],int size,int move)
{
	system("CLS");
	printf("Thanks for trying out the PUZZLE GAME.\n\n");
	int i,j;
	line(0,0,size);
	for(i=0;i<size;i++)
	{
		printf("|");
		for(j=0;j<size;j++)
		{
		   if(arr[i][j]==size*size)
		   {
			   printf("   |");
		   }
		   else
		   {
		       printf("%3d|",arr[i][j]);
		   }
	    }
	    printf("\n");
	    line(i,0,size);
    }
    printf("Move number: %d",move);
    printf("\n\n");
}
int check(int arr[100][100],int size)
{
	int i,j,f=1,count=1;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(arr[i][j]==count)
			{
				count++;
			}
			else
			{
				f=0;
			}
		}
	}
	return f;
}
int main()
{
	int i,j,count=1,res,beep=0,size,r,c,move=0;
	int ch,seq[100];
	scanf("%d",&size);
	r=c=size-1;
	int arr2[100][100];
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			arr2[i][j]=count;
			count+=1;
		}
	}
	//printf("Ok");
	rand_seq(100,seq);
	random(arr2,size,seq,&r,&c);
	display(arr2,size,move);
	while(1)
	{
		ch=getch();
		switch(ch)
	    {
	    	case 72:
	    			beep=swapup(arr2,size,&r,&c);
	    			move++;
	    			display(arr2,size,move);
					break;
			case 80:
			    	beep=swapdown(arr2,size,&r,&c);
			    	move++;
			    	display(arr2,size,move);
			    	break;
			case 75:
			    	beep=swapleft(arr2,size,&r,&c);
			    	move++;
			    	display(arr2,size,move);
			    	break;
			case 77:
			    	beep=swapright(arr2,size,&r,&c);
			    	move++;
			    	display(arr2,size,move);
			    	break;
	    }
	    if(beep)
	    {
	    	printf("\a");
	    	beep=0;
		}
	    if(check(arr2,size))
	    {
	    	MessageBeep(MB_OK);
	    	printf("Congrats. You've won.\n");
	    	break;
		}
	}
}
