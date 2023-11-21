#include <stdio.h>
#include <cstdlib>
#include <string.h>


void interface(int a[3][3]);
void input1(int a[3][3], int n);
void input2(int a[3][3], int n);
void refill(int a[3][3], int n);
int check(int a[3][3],int d,char name1[50],char name2[50]);


main()
{
	int d=9,k, n, a[3][3],d2,d1=d,count;								// d = la so o co the nhap giu lieu	
	char c,name1[50],name2[50];									// d1 = xac dinh so o nhap tu PLAYER 1
	interface(a);											// d2 = xac dinh so o nhap tu PLAYER 2
	printf("\n\n\nEnter Player 1: ");								// d1 va d2 se tra ve gia tri cho d
	scanf("%s",name1);										// truong hop d=0 ma chua co WINNER thi = DRAW
	printf("\n\nEnter Player 2: ");
	scanf("%s",name2);
	system("cls");
	do 
	{
		do
		{
			do										// nhan gia tri 1 tu ban phim
			{
			system("cls");
			refill(a,n);
			printf("\n\n\n%s: ",name1);
			printf("\n\n\n\n\nEnter position to check = ");
			count=scanf("%d%c",&n,&c);
			fflush(stdin);
			} while ((count!=2) || c!='\n');						
			if (a[(n-1)/3][(n-1)%3]==0)							// (n-1) / 3  = vi tri dong
			{										// (n-1) % 3  = vi tri cot
				system("cls");								// n la vi tri nhap tu ban phim
				input1(a,n);
				d1--;
			} else
				{									// nhap sai
					system("cls");							// --> xoa man hinh va dien lai giao dien goc
					refill(a,n);
				}	
		} while (d1==d);
	
		d=d1;
		d2=d1;
		check(a,d,name1,name2);
		
		do
		{
			do										// nhan gia tri 2 tu ban phim			
			{
			system("cls");
			refill(a,n);
			printf("\n\n\n%s: ",name2);
			printf("\n\n\n\n\nEnter position to check = ");
			count=scanf("%d%c",&n,&c);
			fflush(stdin);
			} while ((count!=2) || c!='\n');
			if (a[(n-1)/3][(n-1)%3]==0)	
			{
				system("cls");
				input2(a,n);
				d2--;
			} else
				{
					system("cls");
					refill(a,n);
				}	
		} while (d2==d);
			
		d=d2;						
		d1=d2;
		check(a,d,name1,name2);
			
	} while (d>0); 
}


void interface(int a[3][3])										// giao dien ban dau 
{
	for(int i=0;i<=2;i++)
	{
		printf("\n\n\n\t\t");
		for(int j=0;j<=2;j++)
		{
			a[i][j]=0;
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}


void input1(int a[3][3], int n)										// dien gia tri 1 vao vi tri minh chon
{
	a[(n-1)/3][(n-1)%3]=1;
	for(int i=0;i<=2;i++)
	{
		printf("\n\n\n\t\t");
		for(int j=0;j<=2;j++)
		printf("%d\t",a[i][j]);
		printf("\n");
	}
	
}


void input2(int a[3][3], int n)										// dien gia tri 2 vao vi tri minh chon
{
	a[(n-1)/3][(n-1)%3]=2;
	for(int i=0;i<=2;i++)
	{
		printf("\n\n\n\t\t");
		for(int j=0;j<=2;j++)
		printf("%d\t",a[i][j]);
		printf("\n");
	}
}


void refill(int a[3][3], int n)										// dien lai cac o khi minh chon vi tri
{													// su dung trong viec minh nhap sai format
	for(int i=0;i<=2;i++)										// hoac nhap vao vi tri da bi danh dau
	{
		printf("\n\n\n\t\t");
		for(int j=0;j<=2;j++)
		printf("%d\t",a[i][j]);
		printf("\n");
	}	
}


int check(int a[3][3],int d,char name1[50],char name2[50]) 						// kiem tra va xuat ra ket qua = WINNER//      
{ 
	int k=0;
	for (int j=0;j<=2;j++)										// kiem tra cac cot
		if (a[0][j]!=0)
			if(a[0][j]==a[1][j] && a[0][j]==a[2][j]) k=a[0][j];					
			
	for (int i=0;i<=2;i++)										// kiem tra cac hang
		if(a[i][0]==a[i][1] && a[i][0]==a[i][2] && a[i][0]!=0) k=a[i][0];
		
	if ((a[0][0]==a[1][1] && a[0][0]==a[2][2] && a[0][0]!=0)) k=a[1][1];				// kiem tra duong cheo 
	if ((a[0][2]==a[1][1] && a[0][2]==a[2][0] && a[0][2]!=0)) k=a[0][2];
	
	
	
	
	
	if (k==1) 											// k=1 tuong ung voi PLAYER 1
	{
		printf("\n\n\n\n\n\n\t%s is WINNER !!\n\n\n\n\n\n",name1);
		exit(0);
	}
	
	if (k==2) 											// k=2 tuong ung voi PLAYER 2
	{
		printf("\n\n\n\n\n\n\t%s is WINNER !!\n\n\n\n\n\n",name2);
		exit(0);
	}
	
	if (k==0 && d==0) 										// k=0 tuong ung voi DRAW
	{
		printf("\n\n\n\n\n\n\tDRAWWWW !!!\n\n\n\n\n\n");
		exit(0);
	}
}
