#include<iostream>
#include<conio.h>
using namespace std;
//Omar Abu_Sanad
int main()
{
	int x[10]={6,7,8,6,8,7,6,3,3,3},h,y[10],counter=0;
	for(int i=0; i<10; i++)
	cout<<x[i];
	cout<<endl;
	
	for(int i=0; i<10; i++)
	{
		
		for(int j=i+1; j<10; j++)
		if(x[i]==x[j]){
			for(int a=j+1; a<11; a++)
			if(x[j]==x[a]){
				
			
		y[counter++]=x[i];
		break;
		}
		}
	
	}
	cout<<"The numbers are repeated more than once are : ";
	for(int i=0; i<counter; i++)
	cout<<y[i]<<"  ";
	_getch();
}