#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int x[6],y=6,temp=0;
	
	for (int i = 0; i < 6; i++)
	{
		cin >> x[i];
		
	}
	for (int i = 0; i <= 5; i++)
	for (int j = 0; j<5; j++)
	{
		
		if (x[j] == 0) {
			temp = x[j];
			x[j] = x[j+1];
			x[j+1] = temp;
		}
	}
	cout << endl << "\n";
	for (int i = 0; i < 6; i++)
	{
		cout << x[i];
	}
	_getch();
}