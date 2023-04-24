#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

void createMaze(char** maze)
{
	int i, j, k, l;
	srand(time(NULL));
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			maze[i][j] = '.';
		}
	}
	for (i = 1; i < 8; i += 2)
	{
		for (j = 1; j < 8; j += 2)
		{
			maze[i][j] = '#';
		}
	}
	l = 0;
	while (l < 3)
	{
		i = rand() % 9;
		j = rand() % 9;
		if (maze[i][j] == '#')
		{
			maze[i][j] = '.';
			l++;
		}
	}
	k = 0;
	while (k < 3)
	{
		i = rand() % 9;
		j = rand() % 9;
		if (maze[i][j] == '.')
		{
			maze[i][j] = '#';
			k++;
		}
	}
	maze[0][0] = 'P'; //at start
	maze[8][8] = 'E'; //at end
}

void printMaze(char** maze)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	cout << "------------------------------------" << endl;
	cout << "Welcome to Maze Game!" << endl;
	cout << "------------------------------------" << endl;
	cout << "The Maze Created is about 8 x 8!" << endl;
	cout << "------------------------------------" << endl;
	int i, j, k, moves, flag, flag1;
	char** maze, ch;  //array created using memory allocation
	maze = new char* [9];
	for (i = 0; i < 9; i++)
	{
		maze[i] = new char[9];
	}
	createMaze(maze);
	printMaze(maze);
	moves = 0;
	flag = 0;
	flag1 = 0;
	while (flag != 1)
	{
		k = 0;
		cout << "Enter the direction you want to go (u, d, l, r): ";
		cin >> ch;
		if (ch == 'u')
		{
			for (i = 0; i < 9; i++)
			{
				for (j = 0; j < 9; j++)
				{
					if (maze[i][j] == 'P')
					{
						if (maze[i - 1][j] == '.')
						{
							maze[i][j] = '.';
							maze[i - 1][j] = 'P';
							moves++;
							k = 1;
							break;
						}
						else if (maze[i - 1][j] == 'E')
						{
							maze[i][j] = '.';
							maze[i - 1][j] = 'P';
							flag1 = 1;
							k = 1;
							break;
						}
					}
				}
				if (k == 1)
				{
					break;
				}
			}
		}
		else if (ch == 'd')
		{
			for (i = 0; i < 9; i++)
			{
				for (j = 0; j < 9; j++)
				{
					if (maze[i][j] == 'P')
					{
						if (maze[i + 1][j] == '.')
						{
							maze[i][j] = '.';
							maze[i + 1][j] = 'P';
							moves++;
							k = 1;
							break;
						}
						else if (maze[i + 1][j] == 'E')
						{
							maze[i][j] = '.';
							maze[i + 1][j] = 'P';
							flag1 = 1;
							k = 1;
							break;
						}
					}
				}
				if (k == 1)
				{
					break;
				}
			}
		}
		else if (ch == 'l')
		{
			for (i = 0; i < 9; i++)
			{
				for (j = 0; j < 9; j++)
				{
					if (maze[i][j] == 'P')
					{
						if (maze[i][j - 1] == '.')
						{
							maze[i][j] = '.';
							maze[i][j - 1] = 'P';
							moves++;
							k = 1;
							break;
						}
						else if (maze[i][j - 1] == 'E')
						{
							maze[i][j] = '.';
							maze[i][j - 1] = 'P';
							flag1 = 1;
							k = 1;
							break;
						}
					}
				}
				if (k == 1)
				{
					break;
				}
			}
		}
		else if (ch == 'r')
		{
			for (i = 0; i < 9; i++)
			{
				for (j = 0; j < 9; j++)
				{
					if (maze[i][j] == 'P')
					{
						if (maze[i][j + 1] == '.')
						{
							maze[i][j] = '.';
							maze[i][j + 1] = 'P';
							moves++;
							k = 1;
							break;
						}
						else if (maze[i][j + 1] == 'E')
						{
							maze[i][j] = '.';
							maze[i][j + 1] = 'P';
							flag1 = 1;
							k = 1;
							break;
						}
					}
				}
				if (k == 1)
				{
					break;
				}
			}
		}
		else
		{
			cout << "Enter a valid direction" << endl;
		}
		system("cls");
		printMaze(maze);
		if (flag1 == 1)
		{
			break;
		}
	}
	if (flag1 == 1)
	{
		cout << "You won the game in " << moves << " moves" << endl;
	}
	else
	{
		cout << "You lost the game" << endl;
	}
	for (i = 0; i < 9; i++)
	{
		delete[] maze[i];
	}
	delete[] maze;
	system("pause");
	return 0;
}