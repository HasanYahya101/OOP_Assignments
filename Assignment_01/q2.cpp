#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int rows = 0;
	int columns = 0;
	//open Input.txt and check for total rows and columns, each Yes and each no sideways in a column and downwards is a row
	ifstream input("Input.txt");
	string line;
	while (getline(input, line))
	{
		rows++;
	}
	input.close();
	//check the total number of yes and no
	ifstream input2("Input.txt");
	string word;
	while (input2 >> word)
	{
		columns++;
	}
	int total_elements = columns;
	columns = columns / rows;
	input2.close();
	//create a 2D array of strings
	string** array = new string * [rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new string[columns];
	}
	//fill the 2D array with the values from the file
	ifstream input3("Input.txt");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			input3 >> array[i][j];
		}
	}
	input3.close();
	//print the 2D array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-------------------------------------------------------------------" << endl;
	//create a 2D array of int to store the compressed array
	int** compressed_array = new int * [rows];
	for (int i = 0; i < rows; i++)
	{
		compressed_array[i] = new int[2];
	}
	//initialise with 0
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			compressed_array[i][j] = 0;
		}
	}
	//count the number of yes in each row and store it in the first column of the compressed array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (array[i][j] == "Yes")
			{
				compressed_array[i][0]++;
			}
		}
	}
	//fill the second column of the compressed array with no
	for (int i = 0; i < rows; i++)
	{
		compressed_array[i][1] = columns - compressed_array[i][0];
	}
	//print the compressed array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << compressed_array[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-------------------------------------------------------------------" << endl;
	//create a 2D array of strings to store the decompressed array
	string** decompressed_array = new string * [rows];
	for (int i = 0; i < rows; i++)
	{
		decompressed_array[i] = new string[columns];
	}
	//initialise with no
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			decompressed_array[i][j] = "No";
		}
	}
	//create a new array that stores the atual locations of Yes
	int** yes_locations = new int * [rows];
	for (int i = 0; i < rows; i++)
	{
		yes_locations[i] = new int[compressed_array[i][0]];
	}
	//initialise with 0
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < compressed_array[i][0]; j++)
		{
			yes_locations[i][j] = 0;
		}
	}
	//fill the yes_locations array with the actual locations of yes
	int count = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (array[i][j] == "Yes")
			{
				yes_locations[i][count] = j;
				count++;
			}
		}
		count = 0;
	}
	/*//print the yes_locations array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < compressed_array[i][0]; j++)
		{
			cout << yes_locations[i][j] << "\t";
		}
		cout << endl;
	}*/
	//fill the decompressed array with yes in actual locations
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < compressed_array[i][0]; j++)
		{
			decompressed_array[i][yes_locations[i][j]] = "Yes";
		}
	}
	//print the decompressed array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << decompressed_array[i][j] << "\t";
		}
		cout << endl;
	}	
	//calculate total yes
	int total_yes = 0;
	for (int i = 0; i < rows; i++)
	{
		total_yes += compressed_array[i][0];
	}
	//calculate total elements
	total_elements = rows * columns;
	cout << "-------------------------------------------------------------------" << endl;
	//print the total yes
	cout << "Total Yes's in array: " << total_yes << endl;
	//print the number of rows and columns
	cout << "Rows: " << rows << endl;
	cout << "Columns: " << columns << endl;
	//print the total No
	cout << "Total No's in array: " << total_elements - total_yes << endl;
	cout << "-------------------------------------------------------------------" << endl;
	//delete the arrays
	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	for (int i = 0; i < rows; i++)
	{
		delete[] compressed_array[i];
	}
	delete[] compressed_array;
	for (int i = 0; i < rows; i++)
	{
		delete[] decompressed_array[i];
	}
	delete[] decompressed_array;
	for (int i = 0; i < rows; i++)
	{
		delete[] yes_locations[i];
	}
	delete[] yes_locations;
	return 0;
}