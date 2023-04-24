#include<iostream>
#include<string>
using namespace std;
int main()
{
	string Sentence;
	cout << "Enter a sentence: ";
	getline(cin, Sentence);
	int temp;
	//remove apostrophe and the s that comes after it
	for (int i = 0; i < Sentence.length(); i++)
	{
		if (Sentence[i] == 39)
		{
			temp = i;
			//manually remove it using for loop
			for (int j = i; j < Sentence.length(); j++)
			{
				Sentence[j] = Sentence[j + 1];
			}
			//remove the s after apostrophe
			if (Sentence[temp] == 's')
			{
				for (int k = temp; k < Sentence.length(); k++)
				{
					Sentence[k] = Sentence[k + 1];
				}
			}
		}
	}
	//if two words have a dot between them with no space, replace dot with space
	for (int i = 0; i < Sentence.length(); i++)
	{
		if (Sentence[i] == '.' && Sentence[i + 1] >= 97 && Sentence[i + 1] <= 122)
		{
			Sentence[i] = ' ';
		}
	}
	//if two words have a comma between them with no space, replace dot with space
	for (int i = 0; i < Sentence.length(); i++)
	{
		if (Sentence[i] == ',' && Sentence[i + 1] >= 97 && Sentence[i + 1] <= 122)
		{
			Sentence[i] = ' ';
		}
	}
	//if two words have a exclamation mark between them with no space, replace dot with space
	for (int i = 0; i < Sentence.length(); i++)
	{
		if (Sentence[i] == '!' && Sentence[i + 1] >= 97 && Sentence[i + 1] <= 122)
		{
			Sentence[i] = ' ';
		}
	}
	//now remove other punctuations
	for (int i = 0; i < Sentence.length(); i++)
	{
		if (Sentence[i] == ',' || Sentence[i] == '.' || Sentence[i] == '!' || Sentence[i] == '?')
		{
			for (int j = i; j < Sentence.length(); j++)
			{
				Sentence[j] = Sentence[j + 1];
			}
		}
	}
	//now remove extra spaces
	for (int i = 0; i < Sentence.length(); i++)
	{
		if (Sentence[i] == ' ' && Sentence[i + 1] == ' ')
		{
			for (int j = i; j < Sentence.length(); j++)
			{
				Sentence[j] = Sentence[j + 1];
			}
		}
	}
	//remove space at the start of sentence
	if (Sentence[0] == ' ')
	{
		for (int i = 0; i < Sentence.length(); i++)
		{
			Sentence[i] = Sentence[i + 1];
		}
	}
	//remove space at the end of sentence
	if (Sentence[Sentence.length() - 1] == ' ')
	{
		for (int i = Sentence.length() - 1; i < Sentence.length(); i++)
		{
			Sentence[i] = Sentence[i + 1];
		}
	}
	//now convert all letters to lower case
	for (int i = 0; i < Sentence.length(); i++)
	{
		if (Sentence[i] >= 65 && Sentence[i] <= 90)
		{
			Sentence[i] = Sentence[i] + 32;
		}
	}
	//now count the number of words
	int count = 0;
	for (int i = 0; i < Sentence.length(); i++)
	{
		if (Sentence[i] == ' ')
		{
			count++;
		}
	}
	//now store the words in an array
	string* words = new string[count + 1];
	int j = 0;
	for (int i = 0; i < Sentence.length(); i++)
	{
		if (Sentence[i] != ' ')
		{
			words[j] = words[j] + Sentence[i];
		}
		else
		{
			j++;
		}
	}
	//now count the frequency of each word
	int* frequency = new int[count + 1];
	for (int i = 0; i < count + 1; i++)
	{
		frequency[i] = 0;
	}
	for (int i = 0; i < count + 1; i++)
	{
		for (int j = 0; j < count + 1; j++)
		{
			if (words[i] == words[j])
			{
				frequency[i]++;
			}
		}
	}
	//now print the frequency of each word
	for (int i = 0; i < count + 1; i++)
	{
		cout << words[i] << " = " << frequency[i] << endl;
	}
	//search specific word
	string search;
	cout << "Enter word to find its frequency: ";
	cin >> search;	
	//convert to lowercase
	for (int i = 0; i < search.length(); i++)
	{
		if (search[i] >= 65 && search[i] <= 90)
		{
			search[i] = search[i] + 32;
		}
	}
	for (int i = 0; i < count + 1; i++)
	{
		if (words[i] == search)
		{
			cout << search << " = " << frequency[i] << endl;
		}
	}
	//delete arrays
	delete[]words;
	delete[]frequency;
	return 0;	
}
