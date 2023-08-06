#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int x[6];
	cout << "-----------------------------------------------------\n";
	cout << "                       IN PUT                     \n";
	cout << "-----------------------------------------------------\n";
	for (int i = 0; i < 6; i++)
	{
		cout << "Enter number  " << i + 1 << " : ";
		cin >> x[i];
	}
	int temp=0;
	cout << "\n-----------------------------------------------------\n";
	cout << "                       checking                     \n";
	cout << "-----------------------------------------------------\n";
	for (int i = 0; i < 6; i++)
	{
		for (int j = i; j < 6; j++)
		{
			if (x[i] > x[j]) {
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
				
			}
					
		}

	}
	for (int i = 0; i < 6; i++)
	cout << x[i]<< endl;
	
		 


	_getch();
}
