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
	int check = 0;
	cout << "\n-----------------------------------------------------\n";
	cout << "                       checking                     \n";
	cout << "-----------------------------------------------------\n";
	for (int i = 0; i < 3; i++)
	{
		if (x[5 - i] == x[i])
			check++;

	}
	
	if (check == 3)
		cout << "THe element is the same read from front or back \n";
	else
		cout << "THe element is not the same read from front or back \n";


	_getch();
}
