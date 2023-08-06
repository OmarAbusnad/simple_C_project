#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int x[8];
	cout << "-----------------------------------------------------\n";
	cout << "                    frist array                     \n";
	cout << "-----------------------------------------------------\n";
	for (int i = 0; i < 8; i++)
	{
		cout << "Enter number  " << i + 1 << " : ";
		cin >> x[i];
	}
	int x2[4];
	cout << "-----------------------------------------------------\n";
	cout << "                     second array                     \n";
	cout << "-----------------------------------------------------\n";
	for (int i = 0; i < 4; i++)
	{
		cout << "Enter number  " << i + 1 << " : ";
		cin >> x2[i];
	}

	int counter = 0;
	cout << "\n-----------------------------------------------------\n";
	cout << "                  second largest number                     \n";
	cout << "-----------------------------------------------------\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (x2[i] == x[j]) {
				
				counter++;
				break;
			}
			
		}
	
	}
	
	cout << counter << endl;
	if (counter >=4)
	cout <<"THe second array is the subset of frist array "<< endl;
	else
		cout << "THe second array is not the subset of frist array " << endl;




	_getch();
}
