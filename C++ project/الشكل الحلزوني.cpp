#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int x[4][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	
	for(int i=0; i<4; i++)
	{
	  for(int j=0; j<5; j++)
	  cout<<x[i][j]<<" ";
	  cout<<endl;
	}

	
	cout<<"\n----------------------\n";
	
	
	
	for (int i = 0; i < 5; i++)
		cout << x[0][i];
	for (int i = 1; i < 4; i++)
		cout << x[i][4];
	for (int i = 3; i >= 0; i--)
		cout << x[3][i];
	for (int i = 2; i >= 0; i--)
		cout << x[i][0];
	for (int i = 1; i < 4; i++)
		cout << x[1][i];
	for (int i = 3; i > 0; i--)
		cout << x[2][i];

	_getch();
}