#include <iostream>
using namespace std;

int main()
{
	char choice = 'Y';
	while (choice == 'Y' || choice == 'y')
	{
		system("cls"); //to clear screen at each attempt
		//Initialize Columns and Rows and Total Sum
		int rows, columns, sum = 0;
		//Enter Values
		cout << "Enter the Number of Rows: " << endl;
		cin >> rows;
		//check for Error
		while (rows < 1)
		{
			cout << "Invalid Input!!!" << endl;
			cout << "Enter the Number of Rows: " << endl;
			cin >> rows;
		}
		//Enter Value
		cout << "Enter the Number of Columns: " << endl;
		cin >> columns;
		//Check for Error
		while (columns < 1)
		{
			cout << "Invalid Input!!!" << endl;
			cout << "Enter the Number of Columns: " << endl;
			cin >> columns;
		}
		//Allocation memory for Input Array
		int** ptr2 = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			ptr2[i] = new int[columns];
		}
		//Enter Value into Input Array
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << "Enter Value into Array [" << i << "][" << j << "]: ";
				cin >> ptr2[i][j];

			}
		}
		//calculate the sum of all numbers larger than 0
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (ptr2[i][j] > 0)
				{
					sum += ptr2[i][j];
				}
			}
		}
		cout << endl << "----------------------------------------------------------" << endl << endl;
		//Print the Input Array
		cout << "The Created array is: " << endl << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << ptr2[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "----------------------------------------------------------" << endl << endl;
		cout << "Final Condensed array is: " << endl << endl;
		bool check1 = false;
		int num_arr = 0; //total rows with any positive integers
		//Caluculate Total Rows with positive Integers
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (ptr2[i][j] > 0)
				{
					check1 = true;
				}
				if (j == columns - 1 && check1 == true)
				{
					num_arr++;
					check1 = false;
				}
			}
		}
		int** ptr3 = new int* [num_arr];
		bool* ptr4 = new bool[rows]; //stores, if the row has any positive elements
		int* ptr5 = new int[rows]; //stores, how many positive elements, each row has
		//initialise ptr4 with false
		for (int i = 0; i < rows; i++)
		{
			ptr4[i] = false;
		}
		//initialise ptr5 with 0
		for (int i = 0; i < rows; i++)
		{
			ptr5[i] = 0;
		}
		//calculate the number of positive elements in each row
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (ptr2[i][j] > 0)
				{
					ptr5[i]++;
				}
			}
		}
		//check if the row has any positive elements
		for (int i = 0; i < rows; i++)
		{
			if (ptr5[i] > 0)
			{
				ptr4[i] = true;
			}
		}
		//allocate memory for the final array, if any row doesnt have any positive element skip it
		int k = 0;
		for (int i = 0; i < rows; i++)
		{
			if (ptr4[i] == true)
			{
				ptr3[k] = new int[ptr5[i]];
				k++;
			}
		}
		//copy the positive elements into the final array
		k = 0;
		for (int i = 0; i < rows; i++)
		{
			if (ptr4[i] == true)
			{
				int l = 0;
				for (int j = 0; j < columns; j++)
				{
					if (ptr2[i][j] > 0)
					{
						ptr3[k][l] = ptr2[i][j];
						l++;
					}
				}
				k++;
			}
		}
		//print the final array
		for (int i = 0; i < num_arr; i++)
		{
			for (int j = 0; j < ptr5[i]; j++)
			{
				cout << ptr3[i][j] << "\t";
			}
			cout << endl;
		}
		//delete all arrays ||----------------------------------------------------------------------------------------------||
		//delete ptr2
		for (int i = 0; i < rows; i++)
		{
			delete[] ptr2[i];
		}
		delete[] ptr2;
		//delete ptr3
		for (int i = 0; i < num_arr; i++)
		{
			delete[] ptr3[i];
		}
		delete[] ptr3;
		//delete ptr4
		delete[] ptr4;
		//delete ptr5
		delete[] ptr5;
		cout << endl;
		cout << "----------------------------------------------------------" << endl << endl;
		cout << "Total Sum is: " << sum << endl << endl;
		cout << "----------------------------------------------------------" << endl << endl;
		cout << "Do you want to continue? (Y/N): ";
		cin >> choice;
		while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
		{
			cout << "Invalid Input! Please Enter Again: ";
			cin >> choice;
		}
		if (choice == 'N' || choice == 'n')
		{
			exit(0);
		}
	}
	return 0;
}

//||------------------------------------------Junk Code Removed as The Program was being implimented------------------------||
/*
num_arr = 0;
	check1 = true;
	int skip = 0;
	int l = 0;
	//Allocation Memory for Final Array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (ptr2[i][j] > 0)
			{
				num_arr++;
			}
			if (j == columns - 1)
			{
				l = 0;
				ptr3[i - skip] = new int[num_arr];
				for (int k = 0; k < columns; k++)
				{
					if (ptr2[i][k] > 0)
					{
						ptr3[i - skip][l] = ptr2[i][k];
						l++;
					}
				}
				l = 0;
			}
			if (j == columns - 1)
			{
				num_arr = 0;
			}
			if (j == columns - 1 && check1 == false)
			{
				check1 = true;
				skip++;
			}
		}
	}
*/

//||-----------------------------------The End-----------------------------------------------------------||
