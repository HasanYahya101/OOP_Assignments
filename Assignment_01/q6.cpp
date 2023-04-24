#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
	char str[100];
	int len;

public:
	MyString() //initialise it to null string
	{
		str[0] = '\0';
		len = 0;
	}

	void getStr()
	{
		cout << "Enter a string: ";
		cin.getline(str, 100);
	}

	void findLen()
	{
		int i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		len = i;
		cout << "Length of the string is: " << len << endl;
	}

	void concat(MyString s1, MyString s2)
	{
		int i = 0, j = 0;
		while (s1.str[i] != '\0')
		{
			str[i] = s1.str[i];
			i++;
		}
		while (s2.str[j] != '\0')
		{
			str[i] = s2.str[j];
			i++;
			j++;
		}
		str[i] = '\0';
		cout << "Concatenated string is: " << str << endl;
	}

	void subStr(int pos, int n)
	{
		char sub[100];
		int i = 0;
		while (i < n)
		{
			sub[i] = str[pos + i];
			i++;
		}
		sub[i] = '\0';
		cout << "Substring is: " << sub << endl;
	}

	void search(char word[])
	{
		int i = 0, j = 0, flag = 0;
		while (str[i] != '\0')
		{
			if (str[i] == word[j])
			{
				while (str[i] == word[j])
				{
					i++;
					j++;
				}
				if (word[j] == '\0')
				{
					flag = 1;
					break;
				}
				else
				{
					j = 0;
				}
			}
			i++;
		}
		if (flag == 1)
		{
			cout << "Word found" << endl;
			//at what index
			cout << "Index is: " << i - j << endl;
		}
		else
		{
			cout << "Word not found" << endl;
		}
	}

	void reverse()
	{
		char rev[100];
		int i = 0, j = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		i--;
		while (i >= 0)
		{
			rev[j] = str[i];
			i--;
			j++;
		}
		rev[j] = '\0';
		cout << "Reversed string is: " << rev << endl;
	}
};

int main()
{
	//create a menu driven program to perform the above operations
	MyString s1, s2, s3;
	int choice, pos, n;
	char word[100];
	do
	{
		cout << "1. Find length of string" << endl;
		cout << "2. Concatenate two strings" << endl;
		cout << "3. Make a sub-string" << endl;
		cout << "4. Search a word in a string" << endl;
		cout << "5. Reverse the string" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		if (choice == 1)
		{
			s1.getStr();
			s1.findLen();
			
		}
		else if (choice == 2)
		{
			s1.getStr();
			s2.getStr();
			s3.concat(s1, s2);
			break;
		}
		else if (choice == 3) 
		{
			s1.getStr();
			cout << "Enter the position and length of substring: ";
			cin >> pos >> n;
			s1.subStr(pos, n);
			break;
		}
		else if (choice == 4) 
		{
			s1.getStr();
			cout << "Enter the word to be searched: ";
			cin >> word;
			s1.search(word);
			break;
		}
			
		else if (choice == 5) 
		{
			s1.getStr();
			s1.reverse();
			break;
		}
		else if (choice == 6)
		{
			exit(0);
		}
		else
		{
			cout << "Invalid choice" << endl;
		}

	} while (choice != 6);
	return 0;
}

